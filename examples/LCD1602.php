#!/usr/bin/env php
<?php
	define( "PID_FILE",	"/var/run/LCD1602.pid" );

	define( "pcf8574_address",	0x27 );		// default I2C address of Pcf8574

	define( "RS",		0 );
	define( "RW",		1 );
	define( "STRB",		2 );
	define( "LED",		3 );
	define( "D4",		4 );
	define( "D5",		5 );
	define( "D6",		6 );
	define( "D7",		7 );


	class lcd {
		const LCD_BLINK_CTRL	= 0x01;
		const LCD_CURSOR_CTRL	= 0x02;
		const LCD_DISPLAY_CTRL	= 0x04;

		const LCD_CLEAR			= 0x01;
		const LCD_HOME			= 0x02;
		const LCD_ENTRY			= 0x04;
		const LCD_CTRL			= 0x08;
		const LCD_CDSHIFT		= 0x10;
		const LCD_FUNC			= 0x20;
		const LCD_CGRAM			= 0x40;
		const LCD_DGRAM			= 0x80;

		const LCD_FUNC_F		= 0x04;
		const LCD_FUNC_N		= 0x08;
		const LCD_FUNC_DL		= 0x10;

		const LCD_CDSHIFT_RL	= 0x04;
		const LCD_ENTRY_ID		= 0x02;

		protected $rows;
		protected $cols;
		protected $bits = 0;
		protected $cx = 0;
		protected $cy = 0;
		protected $rowOff = array( 0x00, 0x40, 0x14, 0x54 );
		protected $lcdControl = 0;

		function lcd( $rows, $cols, $bits ) {
			$this->rows = $rows;
			$this->cols = $cols;
			$this->bits = $bits;

			for ( $i = 0; $i < 8; $i ++ ) {
				//WiringPi::pinMode( $i, WiringPi::OUTPUT );
				digitalWrite( $i, WiringPi::LOW );
			}
			digitalWrite( LED, WiringPi::HIGH );		// turn on LCD backlight
			digitalWrite( RW, WiringPi::LOW );		// allow writing to LCD

			digitalWrite( RS, WiringPi::LOW );
			//WiringPi::pinMode ( RS, WiringPi::OUTPUT );
			digitalWrite( RS, WiringPi::LOW );
			digitalWrite( STRB, WiringPi::LOW );
			//WiringPi::pinMode( STRB, WiringPi::OUTPUT );
			digitalWrite( STRB, WiringPi::LOW );
			for ( $i = 0; $i < $this->bits; $i ++ ) {
				$dataPin = D4 + $i;
				digitalWrite ( $dataPin + $i, WiringPi::LOW );
				//WiringPi::pinMode( $dataPin + $i, WiringPi::OUTPUT );
				digitalWrite( $dataPin + $i, WiringPi::LOW );
			}

			$func = self::LCD_FUNC | self::LCD_FUNC_DL ;		// Set 8-bit mode 3 times
			put4Command( $func >> 4);
			usleep (35000) ;
			put4Command( $func >> 4);
			usleep (35000) ;
			put4Command( $func >> 4);
			usleep (35000) ;
			$func = self::LCD_FUNC ;							// 4th set: 4-bit mode
			put4Command( $func >> 4);
			usleep (35000) ;
			$func |= self::LCD_FUNC_N ;
			putCommand ( $func );
			usleep (35000) ;

			$this->lcdDisplay( true );
			$this->lcdCursor( false );
			$this->lcdCursorBlink( false );
			$this->lcdClear();

			putCommand( self::LCD_ENTRY	| self::LCD_ENTRY_ID );
			putCommand( self::LCD_CDSHIFT | self::LCD_CDSHIFT_RL );
		}

		function lcdPosition( $x, $y ) {
			if ( ( $x > $this->cols ) || ( $x < 0 ) ) {
				return;
			}
			if ( ( $y > $this->rows ) || ( $y < 0 ) ) {
				return;
			}
			putCommand( $x + ( self::LCD_DGRAM | $this->rowOff[$y] ) );
			$this->cx = $x ;
			$this->cy = $y ;
		}

		function lcdPutchar( $data ) {
			digitalWrite( RS, 1 );
			sendDataCmd( $data );
			if ( ++ $this->cx >= $this->cols ) {
				$this->cx = 0 ;
				if ( ++ $this->cy >= $this->rows ) {
					$this->cy = 0 ;
				}
				putCommand( $this->cx + (self::LCD_DGRAM | $this->rowOff[$this->cy] ) );
			}
		}

		function lcdPuts( $string ) {
			for ( $n = 0; $n < strlen( $string ); $n ++ ) {
				$this->lcdPutchar( Ord( $string[$n] ) );
			}
		}

		function digitalWrite( $pin, $value) {
			static $old = 0;
			$bit  = 1 << ( $pin & 7 );
			if ( $value == WiringPi::LOW )
				$old &= ( ~ $bit );
			else
				$old |= $bit;
			WiringPi::wiringPiI2CWrite( $GLOBALS["I2Chandle"], $old );
		}

		function lcdDisplay( $state ) {
			if ( $state )
				$this->lcdControl |=  self::LCD_DISPLAY_CTRL;
			else
				$this->lcdControl &= ~self::LCD_DISPLAY_CTRL;

			putCommand( self::LCD_CTRL | $this->lcdControl );
		}

		function lcdCursor( $state ) {
			if ( $state )
				$this->lcdControl |=  self::LCD_CURSOR_CTRL;
			else
				$this->lcdControl &= ~self::LCD_CURSOR_CTRL;
			putCommand( self::LCD_CTRL | $this->lcdControl );
		}

		function lcdCursorBlink( $state ) {
			if ( $state )
				$this->lcdControl |=  self::LCD_BLINK_CTRL;
			else
				$this->lcdControl &= ~self::LCD_BLINK_CTRL;
			putCommand( self::LCD_CTRL | $this->lcdControl );
		}

		function lcdClear() {
			putCommand( self::LCD_CLEAR );
			putCommand( self::LCD_HOME );
			$this->cx = $this->cy = 0 ;
			usleep(5000);
		}
	};

	if ( $argc > 1 && !strcasecmp( $argv[1], "stop" ) ) {
		$pid = intval( file_get_contents( PID_FILE ) );
		posix_kill( $pid, SIGTERM );
		echo "stoped\n";
		exit;
	}
	if ( is_file( PID_FILE ) ) {
		echo "already running\n";
		exit;
	}
	$pid = pcntl_fork();
	if ($pid == -1) {
		die('fork できません');
	} else if ( $pid ) {
		// 親プロセスの場合
		//pcntl_wait($status);
		echo "pid: ${pid}\n";
		file_put_contents( PID_FILE, $pid );
		exit;
	}

	$I2Chandle = WiringPi::wiringPiI2CSetup( pcf8574_address );
	if ( $I2Chandle < 0 ) {
		echo "WiringPi::wiringPiI2CSetup Error\n";
	}

	pcntl_signal( SIGTERM, function( $signo, $siginfo ) {
		//print_r( $siginfo );
		////WiringPi::setmode(WiringPi::WPI_MODE_PINS);
		digitalWrite( LED, WiringPi::LOW );		// turn off LCD backlight
		$lcd = $GLOBALS["lcd"];
		$lcd->lcdClear();
		$lcd->lcdDisplay( false );
		unlink( PID_FILE );
		exit;
		} );
	//var_dump( $wiringpi );
	declare( ticks = 1 );
	echo "BoardId: ";
	print_r( WiringPi::piBoardId() );
	//print_r( WiringPi::wiringPiVersion() );
	//print_r( WiringPi::getConstants() );

	$rt = WiringPi::setmode(WiringPi::WPI_MODE_PINS);
	//echo "setmode: ${rt}\n";

	$bits = 4;
	$cols = 16;
	$rows = 2;

	$lcd = new lcd( $rows, $cols, $bits );
//	lcdhd = lcdInit(2,16,4,RS,EN,D4,D5,D6,D7,0,0,0,0);

	$prv = -1;
	$cx = $cy  =0;
	while ( true ) {
		$t = time();
		if ( $t == $prv ) {
			usleep(100*1000);
			continue;
		}
		$prv = $t;
		$lcd->lcdPosition( $cx, $cy );
		$fp = fopen( "/sys/class/thermal/thermal_zone0/temp", "r" );
		$temp = fgets( $fp, 15 );
		fclose( $fp );
		$temp = floatval( $temp ) / 1000;
		$lcd->lcdPuts( sprintf( "Temp: %.2f\xdfC", $temp ) );
		$lcd->lcdPosition( $cx, $cy + 1 );
		//$lcd->lcdPuts( strftime( "%x %X" ) );
		$lcd->lcdPuts( strftime( "Time: %X" ) );
/****
		if ( ++ $cx >= $cols ) {
			$cx = 0;
			if ( ++ $cy >= $rows ) {
				$cy = 0;
			}
		}
****/
	}

	function strobe() {
		digitalWrite( STRB, WiringPi::HIGH );
		usleep (50);
		digitalWrite( STRB, WiringPi::LOW );
		usleep (50);
	}

	function  sendDataCmd( $data ) {
		for ( $i = 0; $i < 4; $i++ ) {
			$d = ( $data & ( 0x10 << $i ) ) ? WiringPi::HIGH : WiringPi::LOW;
			digitalWrite( D4 + $i, $d, $i == 3 );
		}
		strobe() ;
		for ( $i = 0; $i < 4; $i++ ) {
			$d	=( $data & ( 0x01 << $i ) ) ? WiringPi::HIGH : WiringPi::LOW;
			digitalWrite( D4 + $i, $d, $i == 3 );
		}
		strobe() ;
	}

	function  putCommand( $command ) {
		digitalWrite( RS, WiringPi::LOW ) ;
		sendDataCmd( $command );
		usleep( 2000 ) ;
	}

	function put4Command( $command ) {
		digitalWrite( RS, WiringPi::LOW );
		for ( $i = 0; $i < 4; $i ++ ) {
			digitalWrite( D4 + $i, ( $command & ( 1 << $i ) ) ? WiringPi::HIGH : WiringPi::LOW, $i == 3 );
		}
		strobe();
	}

	function digitalWrite( $pin, $value, $i2cw = true ) {
		static $old = 0;
		$bit  = 1 << ( $pin & 7 );
		if ( $value == WiringPi::LOW ) {
			$old &= ( ~ $bit );
		} else {
			$old |= $bit;
		}
		if ( $i2cw ) {
			WiringPi::wiringPiI2CWrite( $GLOBALS["I2Chandle"], $old );
		}
	}
?>
