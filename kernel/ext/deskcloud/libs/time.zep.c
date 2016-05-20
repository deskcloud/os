
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/time.h"
#include "kernel/memory.h"


ZEPHIR_INIT_CLASS(Deskcloud_Libs_Time) {

	ZEPHIR_REGISTER_CLASS(Deskcloud\\Libs, Time, deskcloud, libs_time, deskcloud_libs_time_method_entry, 0);

	return SUCCESS;

}

PHP_METHOD(Deskcloud_Libs_Time, now) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *timezone = NULL, *time = NULL, _0, *_1 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &timezone);

	if (!timezone) {
		ZEPHIR_INIT_VAR(timezone);
		ZVAL_STRING(timezone, "Asia/Jakarta", 1);
	}


	ZEPHIR_CALL_FUNCTION(NULL, "date_default_timezone_set", NULL, 11, timezone);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(time);
	zephir_time(time);
	ZEPHIR_SINIT_VAR(_0);
	ZVAL_STRING(&_0, "h:i A", 0);
	ZEPHIR_CALL_FUNCTION(&_1, "date", NULL, 5, &_0, time);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(time, _1);
	RETURN_CCTOR(time);

}

