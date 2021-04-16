--TEST--
Check if wiringpi is loaded
--SKIPIF--
<?php
if (!extension_loaded('wiringpi')) {
	echo 'skip';
}
?>
--FILE--
<?php
echo 'The extension "wiringpi" is available';
?>
--EXPECT--
The extension "wiringpi" is available
