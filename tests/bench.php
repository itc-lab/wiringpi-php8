#!/usr/bin/env php
<?php
	$pin = 11;
	$wiringpi = new WiringPi();
	$wiringpi->setmode(WiringPi::WPI_MODE_PHYS);
	$wiringpi->setup( $pin, WiringPi::INPUT, WiringPi::PUD_OFF );

	$start = microtime( true );
	for ( $n = 0; $n < 100000; $n ++ ) {
		$wiringpi->input( $pin );
	}
	$end = microtime( true );
//	echo "start: ${start}, end: ${end}\n";
	echo ( $end - $start ) . "\n";
?>
