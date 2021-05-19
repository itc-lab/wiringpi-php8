#!/usr/bin/env php
<?php
	class mh_z19 {
		protected $fd;
		protected $valid = false;
		public $CO2 = 0;
		public $TEMP = 0;
		public $STAT = 0;

		function  __construct( $device = "/dev/serial0" ) {
			$this->setup( $device );
		}

		function setup( $device ) {
			$this->fd = WiringPi::serialOpen( $device, 9600 );
			if ( $this->readCO2() ) {
				$this->valid = true;
			}
		}

		function ready() {
			return $this->valid;
		}

		function readCO2() {
			WiringPi::serialFlush( $this->fd );
			//$cmd = "\xff\x01\x86\x00\x00\x00\x00\x00\x79";
			$cmd = "\xff\x01\x86\x00\x00\x00\x00\x00";
			$cmd .= chr( $this->checksum( $cmd ) );
			$len = WiringPi::serialPuts( $this->fd, $cmd );
			$data = array();
			for ( $n = 0; $n < 9; $n ++ ) {
				////while ( !WiringPi::serialDataAvail( $this->fd ) ) usleep( 1000 );
				$ch = WiringPi::serialGetchar( $this->fd );
				if ( $ch < 0 ) {	//	timeout ?
					return false;
				}
				$data[] = $ch;
			}
			$this->CO2 = $data[2] << 8 | $data[3];
			$this->TEMP = $data[4] - 40;
			$this->STAT = $data[5];
			return true;
		}

		function calibration( $auto = true ) {
			$cmd = "\xff\x01\x79" . ( $auto ? "\xa0" : "\x00" ) . "\x00\x00\x00\x00";
			$cmd .= chr( $this->checksum( $cmd ) );
			$len = WiringPi::serialPuts( $this->fd, $cmd );
		}

		function checksum( $cmd ) {
			$sum = 0;
			for ( $n = 0; $n < strlen( $cmd ); $n ++ ) {
				$sum += ord( $cmd[$n] );
			}
			return ( ~ $sum ) & 0xff;
		}
	}

	$mh_z19 = new mh_z19();
	if ( !$mh_z19->ready() ) {
		exit;
	}

	$prev = time();
	while ( 1 ) {
		$tm = time();
		if ( $prev == $tm ) {
			usleep( 100000 );
			continue;
		}
		$prev = $tm;
		$mh_z19->readCO2();
		//echo "\n";
		echo strftime( "%Y/%m/%d %H:%M:%S ", $tm ) . sprintf( "CO2: %d, temp: %d, status: %02x\n", $mh_z19->CO2, $mh_z19->TEMP, $mh_z19->STAT );
	}
?>
