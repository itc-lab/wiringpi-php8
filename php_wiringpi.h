/* wiringpi extension for PHP */

#ifndef PHP_WIRINGPI_H
# define PHP_WIRINGPI_H

extern zend_module_entry wiringpi_module_entry;
# define phpext_wiringpi_ptr &wiringpi_module_entry

# define PHP_WIRINGPI_VERSION "1.0.0"

# if defined(ZTS) && defined(COMPILE_DL_WIRINGPI)
ZEND_TSRMLS_CACHE_EXTERN()
# endif

#include <wiringPi.h>
#include <wiringPiI2C.h>
#include <wiringPiSPI.h>
#include <wiringSerial.h>
#include <wiringShift.h>
#include <softPwm.h>
#include <pcf8574.h>
#include <pcf8591.h>
#include <softServo.h>
#include <softTone.h>

/****
#include <drcSerial.h>
#include <ads1115.h>
#include <max31855.h>
#include <max5322.h>
#include <mcp23008.h>
#include <mcp23016.h>
#include <mcp23016reg.h>
#include <mcp23017.h>
#include <mcp23s08.h>
#include <mcp23s17.h>
#include <mcp23x0817.h>
#include <mcp23x08.h>
#include <mcp3002.h>
#include <mcp3004.h>
#include <mcp3422.h>
#include <mcp4802.h>
#include <sn3218.h>
#include <sr595.h>
#include <ds1302.h>
#include <gertboard.h>
#include <lcd128x64.h>
#include <lcd.h>
#include <maxdetect.h>
#include <piGlow.h>
#include <piNes.h>
#include <scrollPhat.h>
****/

#endif	/* PHP_WIRINGPI_H */

