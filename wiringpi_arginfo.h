/* This is a generated file, edit the .stub.php file instead.
 * Stub hash: 1be3d4b6a695381c5f26461e74e98ef93d0c008b */

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_wiringpi_test1, 0, 0, IS_VOID, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_wiringpi_test2, 0, 0, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, str, IS_STRING, 0, "\"\"")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_WiringPi_setmode, 0, 1, long, 0)
	ZEND_ARG_OBJ_INFO(0, mode, long, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_WiringPi_setup, 0, 2, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, pinno, long, 0)
	ZEND_ARG_OBJ_INFO(0, pinmode, long, 0)
	ZEND_ARG_OBJ_INFO_WITH_DEFAULT_VALUE(0, pud, long, 0, "0")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_WiringPi_input, 0, 1, long, 0)
	ZEND_ARG_OBJ_INFO(0, pinno, long, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_WiringPi_output, 0, 2, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, pinno, long, 0)
	ZEND_ARG_OBJ_INFO(0, value, long, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_WiringPi_wiringPiVersion, 0, 0, IS_MIXED, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_WiringPi_wiringPiSetup, 0, 0, long, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_WiringPi_wiringPiSetupSys arginfo_class_WiringPi_wiringPiSetup

#define arginfo_class_WiringPi_wiringPiSetupGpio arginfo_class_WiringPi_wiringPiSetup

#define arginfo_class_WiringPi_wiringPiSetupPhys arginfo_class_WiringPi_wiringPiSetup

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_WiringPi_pinModeAlt, 0, 2, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, pin, long, 0)
	ZEND_ARG_OBJ_INFO(0, mode, long, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_WiringPi_pinMode arginfo_class_WiringPi_pinModeAlt

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_WiringPi_pullUpDnControl, 0, 2, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, pin, long, 0)
	ZEND_ARG_OBJ_INFO(0, pud, long, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_WiringPi_digitalRead, 0, 1, long, 0)
	ZEND_ARG_OBJ_INFO(0, pin, long, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_WiringPi_digitalWrite, 0, 2, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, pin, long, 0)
	ZEND_ARG_OBJ_INFO(0, value, long, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_WiringPi_digitalRead8 arginfo_class_WiringPi_digitalRead

#define arginfo_class_WiringPi_digitalWrite8 arginfo_class_WiringPi_digitalWrite

#define arginfo_class_WiringPi_pwmWrite arginfo_class_WiringPi_digitalWrite

#define arginfo_class_WiringPi_analogRead arginfo_class_WiringPi_digitalRead

#define arginfo_class_WiringPi_analogWrite arginfo_class_WiringPi_digitalWrite

#define arginfo_class_WiringPi_piGpioLayout arginfo_class_WiringPi_wiringPiSetup

#define arginfo_class_WiringPi_piBoardId arginfo_class_WiringPi_wiringPiVersion

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_WiringPi_wpiPinToGpio, 0, 1, long, 0)
	ZEND_ARG_OBJ_INFO(0, wpiPin, long, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_WiringPi_physPinToGpio, 0, 1, long, 0)
	ZEND_ARG_OBJ_INFO(0, physPin, long, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_WiringPi_setPadDrive, 0, 2, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, group, long, 0)
	ZEND_ARG_OBJ_INFO(0, value, long, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_WiringPi_getAlt arginfo_class_WiringPi_digitalRead

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_WiringPi_pwmToneWrite, 0, 2, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, pin, long, 0)
	ZEND_ARG_OBJ_INFO(0, freq, long, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_WiringPi_pwmSetMode, 0, 1, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, mode, long, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_WiringPi_pwmSetRange, 0, 1, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, range, long, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_WiringPi_pwmSetClock, 0, 1, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, divisor, long, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_WiringPi_gpioClockSet arginfo_class_WiringPi_pwmToneWrite

#define arginfo_class_WiringPi_digitalReadByte arginfo_class_WiringPi_wiringPiSetup

#define arginfo_class_WiringPi_digitalReadByte2 arginfo_class_WiringPi_wiringPiSetup

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_WiringPi_digitalWriteByte, 0, 1, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, value, long, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_WiringPi_digitalWriteByte2 arginfo_class_WiringPi_digitalWriteByte

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_WiringPi_softPwmCreate, 0, 3, long, 0)
	ZEND_ARG_OBJ_INFO(0, pin, long, 0)
	ZEND_ARG_OBJ_INFO(0, value, long, 0)
	ZEND_ARG_OBJ_INFO(0, range, long, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_WiringPi_softPwmWrite arginfo_class_WiringPi_digitalWrite

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_WiringPi_softPwmStop, 0, 1, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, pin, long, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_WiringPi_pcf8574Setup, 0, 2, long, 0)
	ZEND_ARG_OBJ_INFO(0, pinBase, long, 0)
	ZEND_ARG_OBJ_INFO(0, i2cAddress, long, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_WiringPi_pcf8591Setup arginfo_class_WiringPi_pcf8574Setup

#define arginfo_class_WiringPi_softServoWrite arginfo_class_WiringPi_digitalWrite

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_WiringPi_softServoSetup, 0, 8, long, 0)
	ZEND_ARG_OBJ_INFO(0, p0, long, 0)
	ZEND_ARG_OBJ_INFO(0, p1, long, 0)
	ZEND_ARG_OBJ_INFO(0, p2, long, 0)
	ZEND_ARG_OBJ_INFO(0, p3, long, 0)
	ZEND_ARG_OBJ_INFO(0, p4, long, 0)
	ZEND_ARG_OBJ_INFO(0, p5, long, 0)
	ZEND_ARG_OBJ_INFO(0, p6, long, 0)
	ZEND_ARG_OBJ_INFO(0, p7, long, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_WiringPi_softToneCreate arginfo_class_WiringPi_digitalRead

#define arginfo_class_WiringPi_softToneStop arginfo_class_WiringPi_softPwmStop

#define arginfo_class_WiringPi_softToneWrite arginfo_class_WiringPi_pwmToneWrite

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_WiringPi_wiringPiI2CRead, 0, 1, long, 0)
	ZEND_ARG_OBJ_INFO(0, fd, long, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_WiringPi_wiringPiI2CReadReg8, 0, 2, long, 0)
	ZEND_ARG_OBJ_INFO(0, fd, long, 0)
	ZEND_ARG_OBJ_INFO(0, reg, long, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_WiringPi_wiringPiI2CReadReg16 arginfo_class_WiringPi_wiringPiI2CReadReg8

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_WiringPi_wiringPiI2CWrite, 0, 2, long, 0)
	ZEND_ARG_OBJ_INFO(0, fd, long, 0)
	ZEND_ARG_OBJ_INFO(0, data, long, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_WiringPi_wiringPiI2CWriteReg8, 0, 3, long, 0)
	ZEND_ARG_OBJ_INFO(0, fd, long, 0)
	ZEND_ARG_OBJ_INFO(0, reg, long, 0)
	ZEND_ARG_OBJ_INFO(0, data, long, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_WiringPi_wiringPiI2CWriteReg16 arginfo_class_WiringPi_wiringPiI2CWriteReg8

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_WiringPi_wiringPiI2CSetupInterface, 0, 2, long, 0)
	ZEND_ARG_OBJ_INFO(0, device, long, 0)
	ZEND_ARG_OBJ_INFO(0, devId, long, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_WiringPi_wiringPiI2CSetup, 0, 1, long, 0)
	ZEND_ARG_OBJ_INFO(0, device, long, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_WiringPi_I2CReadBlock, 0, 3, IS_MIXED, 0)
	ZEND_ARG_OBJ_INFO(0, fd, long, 0)
	ZEND_ARG_OBJ_INFO(0, reg, long, 0)
	ZEND_ARG_OBJ_INFO(0, length, long, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_WiringPi_I2CWriteBlock, 0, 3, long, 0)
	ZEND_ARG_OBJ_INFO(0, fd, long, 0)
	ZEND_ARG_OBJ_INFO(0, reg, long, 0)
	ZEND_ARG_TYPE_INFO(0, value, IS_MIXED, 0)
	ZEND_ARG_OBJ_INFO_WITH_DEFAULT_VALUE(0, length, long, 0, "0")
ZEND_END_ARG_INFO()

#define arginfo_class_WiringPi_getConstants arginfo_class_WiringPi_wiringPiVersion


ZEND_FUNCTION(wiringpi_test1);
ZEND_FUNCTION(wiringpi_test2);
ZEND_METHOD(WiringPi, setmode);
ZEND_METHOD(WiringPi, setup);
ZEND_METHOD(WiringPi, input);
ZEND_METHOD(WiringPi, output);
ZEND_METHOD(WiringPi, wiringPiVersion);
ZEND_METHOD(WiringPi, wiringPiSetup);
ZEND_METHOD(WiringPi, wiringPiSetupSys);
ZEND_METHOD(WiringPi, wiringPiSetupGpio);
ZEND_METHOD(WiringPi, wiringPiSetupPhys);
ZEND_METHOD(WiringPi, pinModeAlt);
ZEND_METHOD(WiringPi, pinMode);
ZEND_METHOD(WiringPi, pullUpDnControl);
ZEND_METHOD(WiringPi, digitalRead);
ZEND_METHOD(WiringPi, digitalWrite);
ZEND_METHOD(WiringPi, digitalRead8);
ZEND_METHOD(WiringPi, digitalWrite8);
ZEND_METHOD(WiringPi, pwmWrite);
ZEND_METHOD(WiringPi, analogRead);
ZEND_METHOD(WiringPi, analogWrite);
ZEND_METHOD(WiringPi, piGpioLayout);
ZEND_METHOD(WiringPi, piBoardId);
ZEND_METHOD(WiringPi, wpiPinToGpio);
ZEND_METHOD(WiringPi, physPinToGpio);
ZEND_METHOD(WiringPi, setPadDrive);
ZEND_METHOD(WiringPi, getAlt);
ZEND_METHOD(WiringPi, pwmToneWrite);
ZEND_METHOD(WiringPi, pwmSetMode);
ZEND_METHOD(WiringPi, pwmSetRange);
ZEND_METHOD(WiringPi, pwmSetClock);
ZEND_METHOD(WiringPi, gpioClockSet);
ZEND_METHOD(WiringPi, digitalReadByte);
ZEND_METHOD(WiringPi, digitalReadByte2);
ZEND_METHOD(WiringPi, digitalWriteByte);
ZEND_METHOD(WiringPi, digitalWriteByte2);
ZEND_METHOD(WiringPi, softPwmCreate);
ZEND_METHOD(WiringPi, softPwmWrite);
ZEND_METHOD(WiringPi, softPwmStop);
ZEND_METHOD(WiringPi, pcf8574Setup);
ZEND_METHOD(WiringPi, pcf8591Setup);
ZEND_METHOD(WiringPi, softServoWrite);
ZEND_METHOD(WiringPi, softServoSetup);
ZEND_METHOD(WiringPi, softToneCreate);
ZEND_METHOD(WiringPi, softToneStop);
ZEND_METHOD(WiringPi, softToneWrite);
ZEND_METHOD(WiringPi, wiringPiI2CRead);
ZEND_METHOD(WiringPi, wiringPiI2CReadReg8);
ZEND_METHOD(WiringPi, wiringPiI2CReadReg16);
ZEND_METHOD(WiringPi, wiringPiI2CWrite);
ZEND_METHOD(WiringPi, wiringPiI2CWriteReg8);
ZEND_METHOD(WiringPi, wiringPiI2CWriteReg16);
ZEND_METHOD(WiringPi, wiringPiI2CSetupInterface);
ZEND_METHOD(WiringPi, wiringPiI2CSetup);
ZEND_METHOD(WiringPi, I2CReadBlock);
ZEND_METHOD(WiringPi, I2CWriteBlock);
ZEND_METHOD(WiringPi, getConstants);


static const zend_function_entry ext_functions[] = {
	ZEND_FE(wiringpi_test1, arginfo_wiringpi_test1)
	ZEND_FE(wiringpi_test2, arginfo_wiringpi_test2)
	ZEND_FE_END
};


static const zend_function_entry class_WiringPi_methods[] = {
	ZEND_ME(WiringPi, setmode, arginfo_class_WiringPi_setmode, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(WiringPi, setup, arginfo_class_WiringPi_setup, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(WiringPi, input, arginfo_class_WiringPi_input, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(WiringPi, output, arginfo_class_WiringPi_output, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(WiringPi, wiringPiVersion, arginfo_class_WiringPi_wiringPiVersion, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(WiringPi, wiringPiSetup, arginfo_class_WiringPi_wiringPiSetup, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(WiringPi, wiringPiSetupSys, arginfo_class_WiringPi_wiringPiSetupSys, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(WiringPi, wiringPiSetupGpio, arginfo_class_WiringPi_wiringPiSetupGpio, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(WiringPi, wiringPiSetupPhys, arginfo_class_WiringPi_wiringPiSetupPhys, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(WiringPi, pinModeAlt, arginfo_class_WiringPi_pinModeAlt, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(WiringPi, pinMode, arginfo_class_WiringPi_pinMode, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(WiringPi, pullUpDnControl, arginfo_class_WiringPi_pullUpDnControl, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(WiringPi, digitalRead, arginfo_class_WiringPi_digitalRead, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(WiringPi, digitalWrite, arginfo_class_WiringPi_digitalWrite, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(WiringPi, digitalRead8, arginfo_class_WiringPi_digitalRead8, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(WiringPi, digitalWrite8, arginfo_class_WiringPi_digitalWrite8, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(WiringPi, pwmWrite, arginfo_class_WiringPi_pwmWrite, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(WiringPi, analogRead, arginfo_class_WiringPi_analogRead, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(WiringPi, analogWrite, arginfo_class_WiringPi_analogWrite, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(WiringPi, piGpioLayout, arginfo_class_WiringPi_piGpioLayout, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(WiringPi, piBoardId, arginfo_class_WiringPi_piBoardId, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(WiringPi, wpiPinToGpio, arginfo_class_WiringPi_wpiPinToGpio, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(WiringPi, physPinToGpio, arginfo_class_WiringPi_physPinToGpio, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(WiringPi, setPadDrive, arginfo_class_WiringPi_setPadDrive, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(WiringPi, getAlt, arginfo_class_WiringPi_getAlt, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(WiringPi, pwmToneWrite, arginfo_class_WiringPi_pwmToneWrite, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(WiringPi, pwmSetMode, arginfo_class_WiringPi_pwmSetMode, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(WiringPi, pwmSetRange, arginfo_class_WiringPi_pwmSetRange, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(WiringPi, pwmSetClock, arginfo_class_WiringPi_pwmSetClock, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(WiringPi, gpioClockSet, arginfo_class_WiringPi_gpioClockSet, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(WiringPi, digitalReadByte, arginfo_class_WiringPi_digitalReadByte, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(WiringPi, digitalReadByte2, arginfo_class_WiringPi_digitalReadByte2, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(WiringPi, digitalWriteByte, arginfo_class_WiringPi_digitalWriteByte, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(WiringPi, digitalWriteByte2, arginfo_class_WiringPi_digitalWriteByte2, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(WiringPi, softPwmCreate, arginfo_class_WiringPi_softPwmCreate, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(WiringPi, softPwmWrite, arginfo_class_WiringPi_softPwmWrite, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(WiringPi, softPwmStop, arginfo_class_WiringPi_softPwmStop, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(WiringPi, pcf8574Setup, arginfo_class_WiringPi_pcf8574Setup, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(WiringPi, pcf8591Setup, arginfo_class_WiringPi_pcf8591Setup, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(WiringPi, softServoWrite, arginfo_class_WiringPi_softServoWrite, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(WiringPi, softServoSetup, arginfo_class_WiringPi_softServoSetup, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(WiringPi, softToneCreate, arginfo_class_WiringPi_softToneCreate, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(WiringPi, softToneStop, arginfo_class_WiringPi_softToneStop, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(WiringPi, softToneWrite, arginfo_class_WiringPi_softToneWrite, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(WiringPi, wiringPiI2CRead, arginfo_class_WiringPi_wiringPiI2CRead, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(WiringPi, wiringPiI2CReadReg8, arginfo_class_WiringPi_wiringPiI2CReadReg8, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(WiringPi, wiringPiI2CReadReg16, arginfo_class_WiringPi_wiringPiI2CReadReg16, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(WiringPi, wiringPiI2CWrite, arginfo_class_WiringPi_wiringPiI2CWrite, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(WiringPi, wiringPiI2CWriteReg8, arginfo_class_WiringPi_wiringPiI2CWriteReg8, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(WiringPi, wiringPiI2CWriteReg16, arginfo_class_WiringPi_wiringPiI2CWriteReg16, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(WiringPi, wiringPiI2CSetupInterface, arginfo_class_WiringPi_wiringPiI2CSetupInterface, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(WiringPi, wiringPiI2CSetup, arginfo_class_WiringPi_wiringPiI2CSetup, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(WiringPi, I2CReadBlock, arginfo_class_WiringPi_I2CReadBlock, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(WiringPi, I2CWriteBlock, arginfo_class_WiringPi_I2CWriteBlock, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(WiringPi, getConstants, arginfo_class_WiringPi_getConstants, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_FE_END
};
