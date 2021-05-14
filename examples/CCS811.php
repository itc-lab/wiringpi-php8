#!/usr/bin/env php
<?php

	class ccs811 {
		const STATUS_REG			= 0x00;
		const MEAS_MODE_REG			= 0x01;
		const ALG_RESULT_DATA		= 0x02;
		const RAW_DATA				= 0x03;
		const ENV_DATA				= 0x05;
		const NTC_REG				= 0x06;
		const THRESHOLDS			= 0x10;
		const BASELINE				= 0x11;
		const HW_ID_REG				= 0x20;
		const HW_VER_REG			= 0x21;
		const APP_VER_REG			= 0x24;
		const ERROR_ID_REG			= 0xE0;
		const APP_START_REG			= 0xF4;
		const SW_RESET				= 0xFF;

		const CCS_811_ADDRESS		= 0x5A;
		const GPIO_WAKE				= 0x5;
		const DRIVE_MODE_IDLE		= 0x0;
		const DRIVE_MODE_1SEC		= 0x10;
		const DRIVE_MODE_10SEC		= 0x20;
		const DRIVE_MODE_60SEC		= 0x30;
		const INTERRUPT_DRIVEN		= 0x8;
		const THRESHOLDS_ENABLED	= 0x4;

		protected $fd;
		public $eCO2 = 0;
		public $TVOC = 0;
		public $ADC = 0;
		public $BASELINE = 0;


		function __construct(  $addr ) {
			$this->setup( $addr );
		}


		function setup( $addr ) {
			$this->fd = WiringPi::wiringPiI2CSetup( $addr );
			$hw_id = WiringPi::wiringPiI2CReadReg8( $this->fd, self::HW_ID_REG );
			$hw_ver = WiringPi::wiringPiI2CReadReg8( $this->fd, self::HW_VER_REG );
			echo sprintf( "HW_ID (HW_VER): %02X(%02X)\n", $hw_id, $hw_ver );
			$this->reset();
			usleep( 10000 );
			$this->start();
		}


		function start() {
			WiringPi::I2CWriteBlock( $this->fd, self::APP_START_REG, array(), 0 );
			WiringPi::wiringPiI2CWriteReg8( $this->fd, self::MEAS_MODE_REG, self::DRIVE_MODE_1SEC );
		}


		function reset() {
			$data = array( 0x11, 0xe5, 0x72, 0x8a );
			WiringPi::I2CWriteBlock( $this->fd, self::SW_RESET, $data, 4 );
		}


		function stop() {
			WiringPi::wiringPiI2CWriteReg8( $this->fd, self::MEAS_MODE_REG, self::DRIVE_MODE_IDLE );
		}


		function ready() {
			$stat = WiringPi::wiringPiI2CReadReg8( $this->fd, self::STATUS_REG );
			return ( $stat & 0x08 ) != 0;
		}


		function getbaseline() {
//			$this->BASELINE = WiringPi::wiringPiI2CReadReg16( $this->fd, self::BASELINE );
			$values = WiringPi::I2CReadBlock( $this->fd, self::BASELINE, 2 );
			$this->BASELINE = $values[0] | $values[1] << 8;
		}


		function setbaseline( $val ) {
//			WiringPi::wiringPiI2CWriteReg16( $this->fd, self::BASELINE, $val );
			$values = array( $val & 0xff, $val >> 8 );
			$rt = WiringPi::I2CWriteBlock( $this->fd, self::BASELINE, $values, 2 );
		}


		function readalg() {
			//$err = WiringPi::wiringPiI2CReadReg8( $this->fd, self::ERROR_ID_REG );
			//echo sprintf( "STATUS: %02X (%02X)\n", $stat, $err );
			$val = WiringPi::wiringPiI2CReadReg16( $this->fd, self::RAW_DATA );
			$this->ADC = ( $val & 0x03 ) << 8 | ( $val >> 8 );

			$values = WiringPi::I2CReadBlock( $this->fd, self::ALG_RESULT_DATA, 8 );
			$eCO2 = ( $values[0] & 0xff ) << 8 | ( $values[1] );
			if ( $eCO2 >= 400 && $eCO2 <= 8192 ) {
				$this->eCO2 = $eCO2;
				$this->TVOC = ( $values[2] & 0xff ) << 8 | ( $values[3] );
			}
		}


		function adjust( $temp = 25.0, $humid = 50.0 ) {
			$h = intVal( $humid * 512 );
			$t = intVal( ( $temp + 25 ) * 512 );
			$envData = array(
				( $h >> 8 ), ( $h & 0xFF ), ( $t >> 8 ), ( $t & 0xFF )
			);
			WiringPi::I2CWriteBlock( $this->fd, self::ENV_DATA, $envData, 4 );
		}
	}


	$baseline = "/var/log/css811log/baseline";
	@mkdir( dirname( $baseline ) );
	$ccs811 = new ccs811( 0x5a );
	$ccs811->readalg();
	$start = time();
	while ( true ) {
		$file = "/var/log/bme280log/current";
		if ( is_file( $file ) ) {
			$data = trim( file_get_contents( $file ) );
			$val = explode( "\t", $data );
			//	$val[0]: date
			//	$val[1]: time
			//	$val[2]: temp.
			//	$val[3]: humid.
			//	$val[4]: press.
			$ccs811->adjust( $val[2], $val[3] );
		}
		if ( isset( $start ) && ( time() - $start ) > 10 ) {
			if ( is_file( $baseline ) ) {
				$val = intval( file_get_contents( $baseline ), 16 );
				$ccs811->setbaseline( $val );
				//echo sprintf( "set BASELINE: %04x\n", $val );
			}
			unset( $start );
		}
		while( true ) {
			if ( $ccs811->ready() ) {
				break;
			}
			usleep( 10000 );
			continue;
		}
		echo strftime( "%Y/%m/%d %H:%M:%S  ", time() );
		$ccs811->readalg();
		$ccs811->getbaseline();
		echo sprintf( "eCO2: %4d ppm, TVOC: %4d bpm, RAW_DATA: %d, BASELINE: %04x\n", $ccs811->eCO2, $ccs811->TVOC, $ccs811->ADC, $ccs811->BASELINE );
//		$ccs811->stop();
//		$ccs811->adjust( 25, 40 );
	}
?>
