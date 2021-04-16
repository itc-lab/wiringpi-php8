#!/usr/bin/env php
<?php
	$PID_FILE = "/var/run/RGBLED.pid";

	$pid = pcntl_fork();
	if ($pid == -1) {
		die('fork できません');
	} else if ( $pid ) {
		// 親プロセスの場合
		//pcntl_wait($status);
		echo "pid: ${pid}\n";
		file_put_contents( $PID_FILE, $pid );
		exit;
	}
	$pwm = true;
	$pinr = 11;
	$ping = 12;
	$pinb = 13;
	pcntl_signal( SIGTERM, function( $signo, $siginfo ) {
		//print_r( $siginfo );
		WiringPi::setmode(WiringPi::WPI_MODE_PHYS);
		if ( $GLOBALS["pwm"] ) {
			WiringPi::softPwmStop( $GLOBALS["pinr"] );
			WiringPi::softPwmStop( $GLOBALS["ping"] );
			WiringPi::softPwmStop( $GLOBALS["pinb"] );
		} else {
			WiringPi::setup( $GLOBALS["pinr"], WiringPi::INPUT );
			WiringPi::setup( $GLOBALS["ping"], WiringPi::INPUT );
			WiringPi::setup( $GLOBALS["pinb"], WiringPi::INPUT );
		}
		unlink( $GLOBALS["PID_FILE"] );
		exit;
		} );
	//var_dump( $wiringpi );
	declare( ticks = 1 );
	echo "BoardId: ";
	print_r( WiringPi::piBoardId() );
	//print_r( WiringPi::wiringPiVersion() );
	//print_r( WiringPi::getConstants() );
	$rt = WiringPi::setmode(WiringPi::WPI_MODE_PHYS);
	//echo "setmode: ${rt}\n";
	if ( $pwm ) {
		WiringPi::softPwmCreate( $pinr,	0, 100);
		WiringPi::softPwmCreate( $ping,	0, 100);
		WiringPi::softPwmCreate( $pinb,	0, 100);
	} else {
		WiringPi::setup( $pinr, WiringPi::OUTPUT );
		WiringPi::setup( $ping, WiringPi::OUTPUT );
		WiringPi::setup( $pinb, WiringPi::OUTPUT );
	}
	$col = 7;

	while ( true ) {
		//echo "input: " . WiringPi::input( $pin ) . "\n";
		if ( $pwm ) {
			$r = random_int( 0, 99 );
			$g = random_int( 0, 99 );
			$b = random_int( 0, 99 );
			//printf( "r: %2d, g: %2d, b: %2d\n", $r, $g, $b );
			WiringPi::softPwmWrite( $pinr, $r );
			WiringPi::softPwmWrite( $ping, $g );
			WiringPi::softPwmWrite( $pinb, $b );
		} else {
			WiringPi::output( $pinr, $col & 1 ? WiringPi::HIGH : WiringPi::LOW );
			WiringPi::output( $ping, $col & 2 ? WiringPi::HIGH : WiringPi::LOW );
			WiringPi::output( $pinb, $col & 4 ? WiringPi::HIGH : WiringPi::LOW );
			$col = ( $col + 1 ) % 8;
		}
		usleep(200*1000);
	}
?>
