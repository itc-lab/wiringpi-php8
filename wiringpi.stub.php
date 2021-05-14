<?php

/** @generate-function-entries */

function wiringpi_test1(): void {}

function wiringpi_test2(string $str = ""): string {}

class WiringPi
{
	public static function setmode(long $mode): long {}
	public static function setup(long $pinno, long $pinmode, long $pud = 0 ): void {}
	public static function input(long $pinno ): long {}
	public static function output(long $pinno, long $value ): void {}
	public static function wiringPiVersion(): mixed {}
	public static function wiringPiSetup(): long {}
	public static function wiringPiSetupSys(): long {}
	public static function wiringPiSetupGpio(): long {}
	public static function wiringPiSetupPhys(): long {}
	public static function pinModeAlt(long $pin, long $mode): void {}
	public static function pinMode(long $pin, long $mode): void {}
	public static function pullUpDnControl(long $pin, long $pud): void {}
	public static function digitalRead(long $pin): long {}
	public static function digitalWrite(long $pin, long $value): void {}
	public static function digitalRead8(long $pin): long {}
	public static function digitalWrite8(long $pin, long $value): void {}
	public static function pwmWrite(long $pin, long $value): void {}
	public static function analogRead(long $pin): long {}
	public static function analogWrite(long $pin, long $value): void {}
	public static function piGpioLayout(): long {}
	public static function piBoardId(): mixed {}
	public static function wpiPinToGpio(long $wpiPin): long {}
	public static function physPinToGpio(long $physPin): long {}
	public static function setPadDrive(long $group, long $value): void {}
	public static function getAlt(long $pin): long {}
	public static function pwmToneWrite(long $pin, long $freq): void {}
	public static function pwmSetMode(long $mode): void {}
	public static function pwmSetRange(long $range): void {}
	public static function pwmSetClock(long $divisor): void {}
	public static function gpioClockSet(long $pin, long $freq): void {}
	public static function digitalReadByte(): long {}
	public static function digitalReadByte2(): long {}
	public static function digitalWriteByte(long $value): void {}
	public static function digitalWriteByte2(long $value): void {}
	public static function softPwmCreate(long $pin, long $value, long $range): long {}
	public static function softPwmWrite(long $pin, long $value): void {}
	public static function softPwmStop(long $pin): void {}
	public static function pcf8574Setup(long $pinBase, long $i2cAddress): long {}
	public static function pcf8591Setup(long $pinBase, long $i2cAddress): long {}
	public static function softServoWrite(long $pin, long $value): void {}
	public static function softServoSetup(long $p0, long $p1, long $p2, long $p3, long $p4, long $p5, long $p6, long $p7): long {}
	public static function softToneCreate(long $pin): long {}
	public static function softToneStop(long $pin): void {}
	public static function softToneWrite(long $pin, long $freq): void {}
	public static function wiringPiI2CRead(long $fd): long {}
	public static function wiringPiI2CReadReg8(long $fd, long $reg): long {}
	public static function wiringPiI2CReadReg16(long $fd, long $reg): long {}
	public static function wiringPiI2CWrite(long $fd, long $data): long {}
	public static function wiringPiI2CWriteReg8(long $fd, long $reg, long $data): long {}
	public static function wiringPiI2CWriteReg16(long $fd, long $reg, long $data): long {}
	public static function wiringPiI2CSetupInterface(long $device, long $devId): long {}
	public static function wiringPiI2CSetup(long $device): long {}
	public static function I2CReadBlock(long $fd, long $reg, long $length): mixed {}
	public static function I2CWriteBlock(long $fd, long $reg, mixed $value, long $length=0): long {}
	public static function getConstants(): mixed {}
}
