
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
#include "kernel/memory.h"


ZEPHIR_INIT_CLASS(Deskcloud_Deskcloud) {

	ZEPHIR_REGISTER_CLASS(Deskcloud, Deskcloud, deskcloud, deskcloud, deskcloud_deskcloud_method_entry, 0);

	return SUCCESS;

}

PHP_METHOD(Deskcloud_Deskcloud, version) {

	zval *location;

	zephir_fetch_params(0, 1, 0, &location);



	RETURN_STRING("Build 0.1", 1);

}

