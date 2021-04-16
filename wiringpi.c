/* WiringPi extension for PHP */

#ifdef HAVE_CONFIG_H
# include "config.h"
#endif

#include "php.h"
#include "ext/standard/info.h"
#include "php_wiringpi.h"
#include "wiringpi_arginfo.h"

/* For compatibility with older PHP versions */
#ifndef ZEND_PARSE_PARAMETERS_NONE
#define ZEND_PARSE_PARAMETERS_NONE() \
	ZEND_PARSE_PARAMETERS_START(0, 0) \
	ZEND_PARSE_PARAMETERS_END()
#endif

static zend_class_entry *wiringpi_class_entry;

#define	WIRINGPI_CLASS_NAME		"WiringPi"

#define	NAMEandVALUE(val)	{ #val, val }
static const struct {
	const char* name;
	long value;
} constants[] = {

// wiringPi modes
	NAMEandVALUE( WPI_MODE_PINS ),
	NAMEandVALUE( WPI_MODE_GPIO ),
	NAMEandVALUE( WPI_MODE_GPIO_SYS ),
	NAMEandVALUE( WPI_MODE_PHYS ),
	NAMEandVALUE( WPI_MODE_PIFACE ),
	NAMEandVALUE( WPI_MODE_UNINITIALISED ),

// Pin modes
	NAMEandVALUE( INPUT ),
	NAMEandVALUE( OUTPUT ),
	NAMEandVALUE( PWM_OUTPUT ),
	NAMEandVALUE( GPIO_CLOCK ),
	NAMEandVALUE( SOFT_PWM_OUTPUT ),
	NAMEandVALUE( SOFT_TONE_OUTPUT ),
	NAMEandVALUE( PWM_TONE_OUTPUT ),

	NAMEandVALUE( LOW ),
	NAMEandVALUE( HIGH ),

// Pull up/down/none
	NAMEandVALUE( PUD_OFF ),
	NAMEandVALUE( PUD_DOWN ),
	NAMEandVALUE( PUD_UP ),

// PWM
	NAMEandVALUE( PWM_MODE_MS ),
	NAMEandVALUE( PWM_MODE_BAL ),

// Interrupt levels
	NAMEandVALUE( INT_EDGE_SETUP ),
	NAMEandVALUE( INT_EDGE_FALLING ),
	NAMEandVALUE( INT_EDGE_RISING ),
	NAMEandVALUE( INT_EDGE_BOTH ),

// Pi model types and version numbers
//	Intended for the GPIO program Use at your own risk.
	NAMEandVALUE( PI_MODEL_A ),
	NAMEandVALUE( PI_MODEL_B ),
	NAMEandVALUE( PI_MODEL_AP ),
	NAMEandVALUE( PI_MODEL_BP ),
	NAMEandVALUE( PI_MODEL_2 ),
	NAMEandVALUE( PI_ALPHA ),
	NAMEandVALUE( PI_MODEL_CM ),
	NAMEandVALUE( PI_MODEL_07 ),
	NAMEandVALUE( PI_MODEL_3B ),
	NAMEandVALUE( PI_MODEL_ZERO ),
	NAMEandVALUE( PI_MODEL_CM3 ),
	NAMEandVALUE( PI_MODEL_ZERO_W ),
	NAMEandVALUE( PI_MODEL_3BP ),
	NAMEandVALUE( PI_MODEL_3AP ),
	NAMEandVALUE( PI_MODEL_CM3P ),
	NAMEandVALUE( PI_MODEL_4B ),

	NAMEandVALUE( PI_VERSION_1 ),
	NAMEandVALUE( PI_VERSION_1_1 ),
	NAMEandVALUE( PI_VERSION_1_2 ),
	NAMEandVALUE( PI_VERSION_2 ),

	NAMEandVALUE( PI_MAKER_SONY ),
	NAMEandVALUE( PI_MAKER_EGOMAN ),
	NAMEandVALUE( PI_MAKER_EMBEST ),
	NAMEandVALUE( PI_MAKER_UNKNOWN ),

	NAMEandVALUE( LSBFIRST ),
	NAMEandVALUE( MSBFIRST ),

	{ NULL }
};

/* {{{ void wiringpi_test1()
 */
PHP_FUNCTION(wiringpi_test1)
{
	ZEND_PARSE_PARAMETERS_NONE();

	php_printf("The extension %s is loaded and working!\r\n", "WiringPi");
}
/* }}} */

/* {{{ string wiringpi_test2( [ string $var ] )
 */
PHP_FUNCTION(wiringpi_test2)
{
	char *var = "World";
	size_t var_len = sizeof("World") - 1;
	zend_string *retval;

	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_STRING(var, var_len)
	ZEND_PARSE_PARAMETERS_END();

	retval = strpprintf(0, "Hello %s", var);

	RETURN_STR(retval);
}
/* }}}*/

PHP_METHOD( WiringPi, setmode )
{
	zend_long pinmode;

	ZEND_PARSE_PARAMETERS_START( 1, 1 )
		Z_PARAM_LONG( pinmode )
	ZEND_PARSE_PARAMETERS_END();

	int result = -1;
	if ( pinmode == WPI_MODE_PINS )
	  result = wiringPiSetup();
	else if ( pinmode == WPI_MODE_GPIO )
	  result = wiringPiSetupGpio();
	else if ( pinmode == WPI_MODE_GPIO_SYS )
	  result = wiringPiSetupSys();
	else if ( pinmode == WPI_MODE_PHYS )
	  result = wiringPiSetupPhys();
	else if ( pinmode == WPI_MODE_PIFACE )
	  result = wiringPiSetupPiFace();

	RETURN_LONG( result );
}


PHP_METHOD( WiringPi, setup )
{
	zend_long pinno, pinmode, pud = PUD_OFF;

	ZEND_PARSE_PARAMETERS_START( 2, 3 )
		Z_PARAM_LONG( pinno )
		Z_PARAM_LONG( pinmode )
		Z_PARAM_OPTIONAL
		Z_PARAM_LONG( pud )
	ZEND_PARSE_PARAMETERS_END();

	pinMode( pinno, pinmode );
	pullUpDnControl( pinno, pud );

	RETURN_NULL();
}


PHP_METHOD( WiringPi, input )
{
	zend_long pinno;

	ZEND_PARSE_PARAMETERS_START( 1, 1 )
		Z_PARAM_LONG( pinno )
	ZEND_PARSE_PARAMETERS_END();

	int result = digitalRead( pinno );

	RETURN_LONG( result );
}


PHP_METHOD( WiringPi, output )
{
	zend_long pinno, value;

	ZEND_PARSE_PARAMETERS_START( 2, 2 )
		Z_PARAM_LONG( pinno )
		Z_PARAM_LONG( value )
	ZEND_PARSE_PARAMETERS_END();

	digitalWrite( pinno, value );

	RETURN_NULL();
}


PHP_METHOD( WiringPi, wiringPiVersion )
{
	int major, minor;
	ZEND_PARSE_PARAMETERS_NONE();
	wiringPiVersion	( &major, &minor );
	array_init( return_value );
	add_assoc_long( return_value, "major", major );
	add_assoc_long( return_value, "minor", minor );
}


PHP_METHOD( WiringPi, wiringPiSetup )
{
	ZEND_PARSE_PARAMETERS_NONE();
	RETURN_LONG( wiringPiSetup() );
}


PHP_METHOD( WiringPi, wiringPiSetupSys )
{
	ZEND_PARSE_PARAMETERS_NONE();
	RETURN_LONG( wiringPiSetupSys() );
}


PHP_METHOD( WiringPi, wiringPiSetupGpio )
{
	ZEND_PARSE_PARAMETERS_NONE();
	RETURN_LONG( wiringPiSetupGpio() );
}


PHP_METHOD( WiringPi, wiringPiSetupPhys )
{
	ZEND_PARSE_PARAMETERS_NONE();
	RETURN_LONG( wiringPiSetupPhys() );
}


PHP_METHOD( WiringPi, pinModeAlt )
{
	zend_long pin, mode;

	ZEND_PARSE_PARAMETERS_START( 2, 2 )
		Z_PARAM_LONG( pin )
		Z_PARAM_LONG( mode )
	ZEND_PARSE_PARAMETERS_END();
	pinModeAlt( pin, mode );
}


PHP_METHOD( WiringPi, pinMode )
{
	zend_long pin, mode;
	ZEND_PARSE_PARAMETERS_START( 2, 2 )
		Z_PARAM_LONG( pin )
		Z_PARAM_LONG( mode )
	ZEND_PARSE_PARAMETERS_END();
	pinMode( pin, mode);
}


PHP_METHOD( WiringPi, pullUpDnControl )
{
	zend_long pin, pud;
	ZEND_PARSE_PARAMETERS_START( 2, 2 )
		Z_PARAM_LONG( pin )
		Z_PARAM_LONG( pud )
	ZEND_PARSE_PARAMETERS_END();
	pullUpDnControl( pin, pud);
}


PHP_METHOD( WiringPi, digitalRead )
{
	zend_long pin;
	ZEND_PARSE_PARAMETERS_START( 1, 1 )
		Z_PARAM_LONG( pin )
	ZEND_PARSE_PARAMETERS_END();
	RETURN_LONG( digitalRead( pin) );
}


PHP_METHOD( WiringPi, digitalWrite )
{
	zend_long pin, value;
	ZEND_PARSE_PARAMETERS_START( 2, 2 )
		Z_PARAM_LONG( pin )
		Z_PARAM_LONG( value )
	ZEND_PARSE_PARAMETERS_END();
	digitalWrite( pin, value);
}


PHP_METHOD( WiringPi, digitalRead8 )
{
	zend_long pin;
	ZEND_PARSE_PARAMETERS_START( 1, 1 )
		Z_PARAM_LONG( pin )
	ZEND_PARSE_PARAMETERS_END();
	RETURN_LONG( digitalRead8( pin ) );
}

PHP_METHOD( WiringPi, digitalWrite8 )
{
	zend_long pin, value;
	ZEND_PARSE_PARAMETERS_START( 2, 2 )
		Z_PARAM_LONG( pin )
		Z_PARAM_LONG( value )
	ZEND_PARSE_PARAMETERS_END();
	digitalWrite8( pin, value);
}


PHP_METHOD( WiringPi, pwmWrite )
{
	zend_long pin, value;
	ZEND_PARSE_PARAMETERS_START( 2, 2 )
		Z_PARAM_LONG( pin )
		Z_PARAM_LONG( value )
	ZEND_PARSE_PARAMETERS_END();
	pwmWrite( pin, value );
}


PHP_METHOD( WiringPi, analogRead )
{
	zend_long pin;
	ZEND_PARSE_PARAMETERS_START( 1, 1 )
		Z_PARAM_LONG( pin )
	ZEND_PARSE_PARAMETERS_END();
	RETURN_LONG(  analogRead( pin ) );
}


PHP_METHOD( WiringPi, analogWrite )
{
	zend_long pin, value;
	ZEND_PARSE_PARAMETERS_START( 2, 2 )
		Z_PARAM_LONG( pin )
		Z_PARAM_LONG( value )
	ZEND_PARSE_PARAMETERS_END();
	analogWrite( pin, value);
}


PHP_METHOD( WiringPi, piGpioLayout )
{
	RETURN_LONG( piGpioLayout() );
}


PHP_METHOD( WiringPi, piBoardId )
{
	int model, rev, mem, maker, overVolted;
	piBoardId( &model, &rev, &mem, &maker, &overVolted );
	array_init( return_value );
	add_assoc_long( return_value, "model", model );
	add_assoc_long( return_value, "rev", rev );
	add_assoc_long( return_value, "mem", mem );
	add_assoc_long( return_value, "maker", maker );
	add_assoc_long( return_value, "overVolted", overVolted );
}


PHP_METHOD( WiringPi, wpiPinToGpio )
{
	zend_long wpiPin;
	ZEND_PARSE_PARAMETERS_START( 1, 1 )
		Z_PARAM_LONG( wpiPin )
	ZEND_PARSE_PARAMETERS_END();
	RETURN_LONG( wpiPinToGpio( wpiPin ) );
}


PHP_METHOD( WiringPi, physPinToGpio )
{
	zend_long physPin;
	ZEND_PARSE_PARAMETERS_START( 1, 1 )
		Z_PARAM_LONG( physPin )
	ZEND_PARSE_PARAMETERS_END();
	RETURN_LONG( physPinToGpio( physPin ) );
}


PHP_METHOD( WiringPi, setPadDrive )
{
	zend_long group, value;
	ZEND_PARSE_PARAMETERS_START( 2, 2 )
		Z_PARAM_LONG( group )
		Z_PARAM_LONG( value )
	ZEND_PARSE_PARAMETERS_END();
	setPadDrive( group, value );
}


PHP_METHOD( WiringPi, getAlt )
{
	zend_long pin;
	ZEND_PARSE_PARAMETERS_START( 1, 1 )
		Z_PARAM_LONG( pin )
	ZEND_PARSE_PARAMETERS_END();
	RETURN_LONG( getAlt( pin ) );
}


PHP_METHOD( WiringPi, pwmToneWrite )
{
	zend_long pin, freq;
	ZEND_PARSE_PARAMETERS_START( 2, 2 )
		Z_PARAM_LONG( pin )
		Z_PARAM_LONG( freq )
	ZEND_PARSE_PARAMETERS_END();
	pwmToneWrite( pin, freq );
}


PHP_METHOD( WiringPi, pwmSetMode )
{
	zend_long mode;
	ZEND_PARSE_PARAMETERS_START( 1, 1 )
		Z_PARAM_LONG( mode )
	ZEND_PARSE_PARAMETERS_END();
	pwmSetMode( mode );
}


PHP_METHOD( WiringPi, pwmSetRange )
{
	zend_long range;
	ZEND_PARSE_PARAMETERS_START( 1, 1 )
		Z_PARAM_LONG( range )
	ZEND_PARSE_PARAMETERS_END();
	pwmSetRange( range );
}


PHP_METHOD( WiringPi, pwmSetClock )
{
	zend_long divisor;
	ZEND_PARSE_PARAMETERS_START( 1, 1 )
		Z_PARAM_LONG( divisor )
	ZEND_PARSE_PARAMETERS_END();
	pwmSetClock( divisor );
}


PHP_METHOD( WiringPi, gpioClockSet )
{
	zend_long pin, freq;
	ZEND_PARSE_PARAMETERS_START( 2, 2 )
		Z_PARAM_LONG( pin )
		Z_PARAM_LONG( freq )
	ZEND_PARSE_PARAMETERS_END();
	gpioClockSet( pin, freq);
}


PHP_METHOD( WiringPi, digitalReadByte )
{
	ZEND_PARSE_PARAMETERS_NONE();
	RETURN_LONG( digitalReadByte() );
}


PHP_METHOD( WiringPi, digitalReadByte2 )
{
	ZEND_PARSE_PARAMETERS_NONE();
	RETURN_LONG( digitalReadByte2() );
}


PHP_METHOD( WiringPi, digitalWriteByte )
{
	zend_long value;
	ZEND_PARSE_PARAMETERS_START( 1, 1 )
		Z_PARAM_LONG( value )
	ZEND_PARSE_PARAMETERS_END();
	digitalWriteByte( value );
}


PHP_METHOD( WiringPi, digitalWriteByte2 )
{
	zend_long value;
	ZEND_PARSE_PARAMETERS_START( 1, 1 )
		Z_PARAM_LONG( value )
	ZEND_PARSE_PARAMETERS_END();
	digitalWriteByte2( value );
}


PHP_METHOD( WiringPi, softPwmCreate )
{
	zend_long pin, value, range;

	ZEND_PARSE_PARAMETERS_START( 3, 3 )
		Z_PARAM_LONG( pin )
		Z_PARAM_LONG( value )
		Z_PARAM_LONG( range )
	ZEND_PARSE_PARAMETERS_END();

	//ZVAL_LONG(return_value, softPwmCreate( pin, value, range) );
	RETURN_LONG( softPwmCreate( pin, value, range) );
}


PHP_METHOD( WiringPi, softPwmWrite )
{
	zend_long pin, value;

	ZEND_PARSE_PARAMETERS_START( 2, 2 )
		Z_PARAM_LONG( pin )
		Z_PARAM_LONG( value )
	ZEND_PARSE_PARAMETERS_END();
	softPwmWrite( pin, value);
	RETURN_NULL();
}


PHP_METHOD( WiringPi, softPwmStop )
{
	zend_long pin;

	ZEND_PARSE_PARAMETERS_START( 1, 1 )
		Z_PARAM_LONG( pin )
	ZEND_PARSE_PARAMETERS_END();
	softPwmStop( pin );
	RETURN_NULL();
}


PHP_METHOD( WiringPi, pcf8574Setup )
{
	zend_long pinBase, i2cAddress;

	ZEND_PARSE_PARAMETERS_START( 2, 2 )
		Z_PARAM_LONG( pinBase )
		Z_PARAM_LONG( i2cAddress )
	ZEND_PARSE_PARAMETERS_END();
	RETURN_LONG( pcf8574Setup( pinBase, i2cAddress ) );
}


PHP_METHOD( WiringPi, pcf8591Setup )
{
	zend_long pinBase, i2cAddress;

	ZEND_PARSE_PARAMETERS_START( 2, 2 )
		Z_PARAM_LONG( pinBase )
		Z_PARAM_LONG( i2cAddress )
	ZEND_PARSE_PARAMETERS_END();
	RETURN_LONG( pcf8591Setup( pinBase, i2cAddress ) );
}


PHP_METHOD( WiringPi, softServoWrite )
{
	zend_long pin, value;
	ZEND_PARSE_PARAMETERS_START( 2, 2 )
		Z_PARAM_LONG( pin )
		Z_PARAM_LONG( value )
	ZEND_PARSE_PARAMETERS_END();

	softServoWrite( pin, value);
	RETURN_NULL();
}


PHP_METHOD( WiringPi, softServoSetup )
{
	zend_long p0, p1, p2, p3, p4, p5, p6, p7;
	ZEND_PARSE_PARAMETERS_START( 7, 7 )
		Z_PARAM_LONG( p0 )
		Z_PARAM_LONG( p1 )
		Z_PARAM_LONG( p2 )
		Z_PARAM_LONG( p3 )
		Z_PARAM_LONG( p4 )
		Z_PARAM_LONG( p5 )
		Z_PARAM_LONG( p6 )
		Z_PARAM_LONG( p7 )
	ZEND_PARSE_PARAMETERS_END();
	RETURN_LONG( softServoSetup( p0, p1, p2, p3, p4, p5, p6, p7 ) );
}


PHP_METHOD( WiringPi, softToneCreate )
{
	zend_long pin;
	ZEND_PARSE_PARAMETERS_START( 1, 1 )
		Z_PARAM_LONG( pin )
	ZEND_PARSE_PARAMETERS_END();
	RETURN_LONG( softToneCreate( pin ) );
}


PHP_METHOD( WiringPi, softToneStop )
{
	zend_long pin;
	ZEND_PARSE_PARAMETERS_START( 1, 1 )
		Z_PARAM_LONG( pin )
	ZEND_PARSE_PARAMETERS_END();
	softToneStop( pin );
	RETURN_NULL();
}


PHP_METHOD( WiringPi, softToneWrite )
{
	zend_long pin, freq;
	ZEND_PARSE_PARAMETERS_START( 2, 2 )
		Z_PARAM_LONG( pin )
		Z_PARAM_LONG( freq )
	ZEND_PARSE_PARAMETERS_END();
	softToneWrite( pin, freq );
	RETURN_NULL();
}


PHP_METHOD( WiringPi, wiringPiI2CRead )
{
	zend_long fd;
	ZEND_PARSE_PARAMETERS_START( 1, 1 )
		Z_PARAM_LONG( fd )
	ZEND_PARSE_PARAMETERS_END();
	RETURN_LONG( wiringPiI2CRead( fd ) );
}


PHP_METHOD( WiringPi, wiringPiI2CReadReg8 )
{
	zend_long fd, reg;
	ZEND_PARSE_PARAMETERS_START( 2, 2 )
		Z_PARAM_LONG( fd )
		Z_PARAM_LONG( reg )
	ZEND_PARSE_PARAMETERS_END();
	RETURN_LONG( wiringPiI2CReadReg8( fd, reg ) );
}


PHP_METHOD( WiringPi, wiringPiI2CReadReg16 )
{
	zend_long fd, reg;
	ZEND_PARSE_PARAMETERS_START( 2, 2 )
		Z_PARAM_LONG( fd )
		Z_PARAM_LONG( reg )
	ZEND_PARSE_PARAMETERS_END();
	RETURN_LONG( wiringPiI2CReadReg16( fd, reg ) );
}


PHP_METHOD( WiringPi, wiringPiI2CWrite )
{
	zend_long fd, data;
	ZEND_PARSE_PARAMETERS_START( 2, 2 )
		Z_PARAM_LONG( fd )
		Z_PARAM_LONG( data )
	ZEND_PARSE_PARAMETERS_END();
	RETURN_LONG( wiringPiI2CWrite( fd, data ) );
}


PHP_METHOD( WiringPi, wiringPiI2CWriteReg8 )
{
	zend_long fd, reg, data;
	ZEND_PARSE_PARAMETERS_START( 3, 3 )
		Z_PARAM_LONG( fd )
		Z_PARAM_LONG( reg )
		Z_PARAM_LONG( data )
	ZEND_PARSE_PARAMETERS_END();
	RETURN_LONG( wiringPiI2CWriteReg8( fd, reg, data ) );
}


PHP_METHOD( WiringPi, wiringPiI2CWriteReg16 ) {
	zend_long fd, reg, data;
	ZEND_PARSE_PARAMETERS_START( 3, 3 )
		Z_PARAM_LONG( fd )
		Z_PARAM_LONG( reg )
		Z_PARAM_LONG( data )
	ZEND_PARSE_PARAMETERS_END();
	RETURN_LONG( wiringPiI2CWriteReg16 ( fd, reg, data ) );
}


PHP_METHOD( WiringPi, wiringPiI2CSetupInterface )
{
	zend_string* device;
	zend_long devId;
	ZEND_PARSE_PARAMETERS_START( 2, 2 )
		Z_PARAM_STR( device )
		Z_PARAM_LONG( devId )
	ZEND_PARSE_PARAMETERS_END();
	RETURN_LONG( wiringPiI2CSetupInterface( ZSTR_VAL(device ), devId ) );
}


PHP_METHOD( WiringPi, wiringPiI2CSetup ) {
	zend_long devId;
	ZEND_PARSE_PARAMETERS_START( 1, 1 )
		Z_PARAM_LONG( devId )
	ZEND_PARSE_PARAMETERS_END();
	RETURN_LONG( wiringPiI2CSetup( devId ) );
}


PHP_METHOD( WiringPi, getConstants )
{
	int n;
	char name[120];

	array_init( return_value );
	for ( n = 0; constants[n].name; n ++ ) {
		sprintf( name, WIRINGPI_CLASS_NAME "::%s", constants[n].name );
		add_assoc_long( return_value, name, constants[n].value );
	}
}


/* {{{ PHP_RINIT_FUNCTION
 */
PHP_RINIT_FUNCTION(WiringPi)
{
#if defined(ZTS) && defined(COMPILE_DL_WIRINGPI)
	ZEND_TSRMLS_CACHE_UPDATE();
#endif

	return SUCCESS;
}
/* }}} */

/* {{{ REGISTER_WIRINGPI_CLASS_CONST_LONG */
#define REGISTER_WIRINGPI_CLASS_CONST_LONG(const_name, value) \
		zend_declare_class_constant_long( wiringpi_class_entry, const_name, strlen(const_name), (zend_long)value );
/* }}} */

/* {{{ PHP_MINIT_FUNCTION */
static PHP_MINIT_FUNCTION(WiringPi)
{
	zend_class_entry ce;
	INIT_CLASS_ENTRY( ce, WIRINGPI_CLASS_NAME, class_WiringPi_methods);
	wiringpi_class_entry = zend_register_internal_class(&ce);
	int n;

//	zend_declare_property_string( wiringpi_class_entry, "hello", sizeof("hello") - 1, "hello, WiringPi!", ZEND_ACC_PUBLIC);

	for ( n = 0; constants[n].name; n ++ ) {
		REGISTER_WIRINGPI_CLASS_CONST_LONG( constants[n].name, constants[n].value );
	}
	return SUCCESS;
}

/* {{{ PHP_MINFO_FUNCTION
 */
PHP_MINFO_FUNCTION(WiringPi)
{
	php_info_print_table_start();
	php_info_print_table_header(2, "Variable", "Value");
	php_info_print_table_row(2, WIRINGPI_CLASS_NAME " support", "enabled");
	php_info_print_table_row(2, WIRINGPI_CLASS_NAME " Version", PHP_WIRINGPI_VERSION);
	php_info_print_table_end();
}
/* }}} */

/* {{{ wiringpi_module_entry
 */
zend_module_entry wiringpi_module_entry = {
	STANDARD_MODULE_HEADER,
	WIRINGPI_CLASS_NAME,			/* Extension name */
	ext_functions,					/* zend_function_entry */
	PHP_MINIT(WiringPi),			/* PHP_MINIT - Module initialization */
	NULL,							/* PHP_MSHUTDOWN - Module shutdown */
	PHP_RINIT(WiringPi),			/* PHP_RINIT - Request initialization */
	NULL,							/* PHP_RSHUTDOWN - Request shutdown */
	PHP_MINFO(WiringPi),			/* PHP_MINFO - Module info */
	PHP_WIRINGPI_VERSION,			/* Version */
	STANDARD_MODULE_PROPERTIES
};
/* }}} */

#ifdef COMPILE_DL_WIRINGPI
# ifdef ZTS
ZEND_TSRMLS_CACHE_DEFINE()
# endif
ZEND_GET_MODULE(wiringpi)
#endif

