
#ifdef HAVE_CONFIG_H
#include "../ext_config.h"
#endif

#include <php.h>
#include "../php_ext.h"
#include "../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/file.h"
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/memory.h"


ZEPHIR_INIT_CLASS(Deskcloud_Config) {

	ZEPHIR_REGISTER_CLASS(Deskcloud, Config, deskcloud, config, deskcloud_config_method_entry, 0);

	return SUCCESS;

}

PHP_METHOD(Deskcloud_Config, config) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *location, *section, *config, *setting = NULL, *_0$$3, *_1$$4, *_2$$4;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &location, &section, &config);



	if ((zephir_file_exists(location TSRMLS_CC) == SUCCESS)) {
		ZEPHIR_CALL_FUNCTION(&setting, "parse_ini_file", NULL, 1, location, ZEPHIR_GLOBAL(global_true));
		zephir_check_call_status();
		zephir_array_fetch(&_0$$3, setting, section, PH_READONLY, "deskcloud/config.zep", 10 TSRMLS_CC);
		if (zephir_array_isset(_0$$3, config)) {
			zephir_array_fetch(&_1$$4, setting, section, PH_NOISY | PH_READONLY, "deskcloud/config.zep", 11 TSRMLS_CC);
			zephir_array_fetch(&_2$$4, _1$$4, config, PH_NOISY | PH_READONLY, "deskcloud/config.zep", 11 TSRMLS_CC);
			RETURN_CTOR(_2$$4);
		} else {
			RETURN_MM_STRING("none", 1);
		}
	} else {
		RETURN_MM_STRING("none", 1);
	}

}

