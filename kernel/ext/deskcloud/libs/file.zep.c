
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
#include "kernel/array.h"
#include "kernel/fcall.h"
#include "kernel/concat.h"
#include "kernel/memory.h"
#include "kernel/file.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/operators.h"
#include "kernel/math.h"


ZEPHIR_INIT_CLASS(Deskcloud_Libs_File) {

	ZEPHIR_REGISTER_CLASS(Deskcloud\\Libs, File, deskcloud, libs_file, deskcloud_libs_file_method_entry, 0);

	return SUCCESS;

}

PHP_METHOD(Deskcloud_Libs_File, create) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *location_param = NULL, *content_param = NULL, *_GET, *file = NULL, *dir = NULL, *_0, *_1, _2;
	zval *location = NULL, *content = NULL;

	ZEPHIR_MM_GROW();
	zephir_get_global(&_GET, SS("_GET") TSRMLS_CC);
	zephir_fetch_params(1, 2, 0, &location_param, &content_param);

	if (unlikely(Z_TYPE_P(location_param) != IS_STRING && Z_TYPE_P(location_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'location' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(location_param) == IS_STRING)) {
		zephir_get_strval(location, location_param);
	} else {
		ZEPHIR_INIT_VAR(location);
		ZVAL_EMPTY_STRING(location);
	}
	if (unlikely(Z_TYPE_P(content_param) != IS_STRING && Z_TYPE_P(content_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'content' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(content_param) == IS_STRING)) {
		zephir_get_strval(content, content_param);
	} else {
		ZEPHIR_INIT_VAR(content);
		ZVAL_EMPTY_STRING(content);
	}


	zephir_array_fetch_string(&_0, _GET, SL("_url"), PH_NOISY | PH_READONLY, "deskcloud/libs/file.zep", 7 TSRMLS_CC);
	ZEPHIR_CALL_FUNCTION(&dir, "dirname", NULL, 1, _0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_1);
	ZEPHIR_CONCAT_VSV(_1, dir, "/", location);
	ZEPHIR_SINIT_VAR(_2);
	ZVAL_STRING(&_2, "w", 0);
	ZEPHIR_CALL_FUNCTION(&file, "fopen", NULL, 2, _1, &_2);
	zephir_check_call_status();
	zephir_fwrite(NULL, file, content TSRMLS_CC);
	zephir_fclose(file TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Deskcloud_Libs_File, read) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *location_param = NULL, *_GET, *dir = NULL, *_0, *_1;
	zval *location = NULL;

	ZEPHIR_MM_GROW();
	zephir_get_global(&_GET, SS("_GET") TSRMLS_CC);
	zephir_fetch_params(1, 1, 0, &location_param);

	if (unlikely(Z_TYPE_P(location_param) != IS_STRING && Z_TYPE_P(location_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'location' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(location_param) == IS_STRING)) {
		zephir_get_strval(location, location_param);
	} else {
		ZEPHIR_INIT_VAR(location);
		ZVAL_EMPTY_STRING(location);
	}


	zephir_array_fetch_string(&_0, _GET, SL("_url"), PH_NOISY | PH_READONLY, "deskcloud/libs/file.zep", 15 TSRMLS_CC);
	ZEPHIR_CALL_FUNCTION(&dir, "dirname", NULL, 1, _0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_1);
	ZEPHIR_CONCAT_VSV(_1, dir, "/", location);
	ZEPHIR_RETURN_CALL_FUNCTION("file_get_contents", NULL, 3, _1, ZEPHIR_GLOBAL(global_true));
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Deskcloud_Libs_File, extension) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *location_param = NULL, *_GET, *dir = NULL, *_0, *_1, _2;
	zval *location = NULL;

	ZEPHIR_MM_GROW();
	zephir_get_global(&_GET, SS("_GET") TSRMLS_CC);
	zephir_fetch_params(1, 1, 0, &location_param);

	if (unlikely(Z_TYPE_P(location_param) != IS_STRING && Z_TYPE_P(location_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'location' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(location_param) == IS_STRING)) {
		zephir_get_strval(location, location_param);
	} else {
		ZEPHIR_INIT_VAR(location);
		ZVAL_EMPTY_STRING(location);
	}


	zephir_array_fetch_string(&_0, _GET, SL("_url"), PH_NOISY | PH_READONLY, "deskcloud/libs/file.zep", 21 TSRMLS_CC);
	ZEPHIR_CALL_FUNCTION(&dir, "dirname", NULL, 1, _0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_1);
	ZEPHIR_CONCAT_VSV(_1, dir, "/", location);
	ZEPHIR_SINIT_VAR(_2);
	ZVAL_LONG(&_2, 4);
	ZEPHIR_RETURN_CALL_FUNCTION("pathinfo", NULL, 4, _1, &_2);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Deskcloud_Libs_File, time) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *format_param = NULL, *location_param = NULL, *_GET, *dir = NULL, *_0, *_1, *_2;
	zval *format = NULL, *location = NULL;

	ZEPHIR_MM_GROW();
	zephir_get_global(&_GET, SS("_GET") TSRMLS_CC);
	zephir_fetch_params(1, 2, 0, &format_param, &location_param);

	if (unlikely(Z_TYPE_P(format_param) != IS_STRING && Z_TYPE_P(format_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'format' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(format_param) == IS_STRING)) {
		zephir_get_strval(format, format_param);
	} else {
		ZEPHIR_INIT_VAR(format);
		ZVAL_EMPTY_STRING(format);
	}
	if (unlikely(Z_TYPE_P(location_param) != IS_STRING && Z_TYPE_P(location_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'location' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(location_param) == IS_STRING)) {
		zephir_get_strval(location, location_param);
	} else {
		ZEPHIR_INIT_VAR(location);
		ZVAL_EMPTY_STRING(location);
	}


	zephir_array_fetch_string(&_0, _GET, SL("_url"), PH_NOISY | PH_READONLY, "deskcloud/libs/file.zep", 27 TSRMLS_CC);
	ZEPHIR_CALL_FUNCTION(&dir, "dirname", NULL, 1, _0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_1);
	ZEPHIR_INIT_VAR(_2);
	ZEPHIR_CONCAT_VSV(_2, dir, "/", location);
	zephir_filemtime(_1, _2 TSRMLS_CC);
	ZEPHIR_RETURN_CALL_FUNCTION("date", NULL, 5, format, _1);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Deskcloud_Libs_File, copy) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *location_param = NULL, *newlocation_param = NULL, *_GET, *dir = NULL, *_0, *_1, *_2, *_3 = NULL;
	zval *location = NULL, *newlocation = NULL;

	ZEPHIR_MM_GROW();
	zephir_get_global(&_GET, SS("_GET") TSRMLS_CC);
	zephir_fetch_params(1, 2, 0, &location_param, &newlocation_param);

	if (unlikely(Z_TYPE_P(location_param) != IS_STRING && Z_TYPE_P(location_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'location' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(location_param) == IS_STRING)) {
		zephir_get_strval(location, location_param);
	} else {
		ZEPHIR_INIT_VAR(location);
		ZVAL_EMPTY_STRING(location);
	}
	if (unlikely(Z_TYPE_P(newlocation_param) != IS_STRING && Z_TYPE_P(newlocation_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'newlocation' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(newlocation_param) == IS_STRING)) {
		zephir_get_strval(newlocation, newlocation_param);
	} else {
		ZEPHIR_INIT_VAR(newlocation);
		ZVAL_EMPTY_STRING(newlocation);
	}


	zephir_array_fetch_string(&_0, _GET, SL("_url"), PH_NOISY | PH_READONLY, "deskcloud/libs/file.zep", 33 TSRMLS_CC);
	ZEPHIR_CALL_FUNCTION(&dir, "dirname", NULL, 1, _0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_1);
	ZEPHIR_CONCAT_VSV(_1, dir, "/", location);
	ZEPHIR_INIT_VAR(_2);
	ZEPHIR_CONCAT_VSV(_2, dir, "/", newlocation);
	ZEPHIR_CALL_FUNCTION(&_3, "copy", NULL, 6, _1, _2);
	zephir_check_call_status();
	if (!zephir_is_true(_3)) {
		php_printf("%s", "failed to copy...\n");
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Deskcloud_Libs_File, rename) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *location_param = NULL, *newname_param = NULL, *_GET, *dir = NULL, *_0, *_1, *_2, *_3 = NULL;
	zval *location = NULL, *newname = NULL;

	ZEPHIR_MM_GROW();
	zephir_get_global(&_GET, SS("_GET") TSRMLS_CC);
	zephir_fetch_params(1, 2, 0, &location_param, &newname_param);

	if (unlikely(Z_TYPE_P(location_param) != IS_STRING && Z_TYPE_P(location_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'location' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(location_param) == IS_STRING)) {
		zephir_get_strval(location, location_param);
	} else {
		ZEPHIR_INIT_VAR(location);
		ZVAL_EMPTY_STRING(location);
	}
	if (unlikely(Z_TYPE_P(newname_param) != IS_STRING && Z_TYPE_P(newname_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'newname' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(newname_param) == IS_STRING)) {
		zephir_get_strval(newname, newname_param);
	} else {
		ZEPHIR_INIT_VAR(newname);
		ZVAL_EMPTY_STRING(newname);
	}


	zephir_array_fetch_string(&_0, _GET, SL("_url"), PH_NOISY | PH_READONLY, "deskcloud/libs/file.zep", 41 TSRMLS_CC);
	ZEPHIR_CALL_FUNCTION(&dir, "dirname", NULL, 1, _0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_1);
	ZEPHIR_CONCAT_VSV(_1, dir, "/", location);
	ZEPHIR_INIT_VAR(_2);
	ZEPHIR_CONCAT_VSV(_2, dir, "/", newname);
	ZEPHIR_CALL_FUNCTION(&_3, "rename", NULL, 7, _1, _2);
	zephir_check_call_status();
	if (!zephir_is_true(_3)) {
		php_printf("%s", "failed to rename...\n");
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Deskcloud_Libs_File, delete) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *location_param = NULL, *_GET, *dir = NULL, *_0, *_1, *_2 = NULL;
	zval *location = NULL;

	ZEPHIR_MM_GROW();
	zephir_get_global(&_GET, SS("_GET") TSRMLS_CC);
	zephir_fetch_params(1, 1, 0, &location_param);

	if (unlikely(Z_TYPE_P(location_param) != IS_STRING && Z_TYPE_P(location_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'location' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(location_param) == IS_STRING)) {
		zephir_get_strval(location, location_param);
	} else {
		ZEPHIR_INIT_VAR(location);
		ZVAL_EMPTY_STRING(location);
	}


	zephir_array_fetch_string(&_0, _GET, SL("_url"), PH_NOISY | PH_READONLY, "deskcloud/libs/file.zep", 49 TSRMLS_CC);
	ZEPHIR_CALL_FUNCTION(&dir, "dirname", NULL, 1, _0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_1);
	ZEPHIR_CONCAT_VSV(_1, dir, "/", location);
	ZEPHIR_CALL_FUNCTION(&_2, "unlink", NULL, 8, _1);
	zephir_check_call_status();
	if (!zephir_is_true(_2)) {
		php_printf("%s", "failed to delete...\n");
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Deskcloud_Libs_File, size) {

	zval *type$$3 = NULL;
	zephir_fcall_cache_entry *_3 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *location_param = NULL, *format = NULL, *_GET, *size = NULL, *base = NULL, *dir = NULL, *_0, *_1$$3 = NULL, *_2$$3, _4$$3, *_5$$4, *_6$$4, _7$$4, _8$$4, _9$$4, *_10$$4, *_11$$6;
	zval *location = NULL;

	ZEPHIR_MM_GROW();
	zephir_get_global(&_GET, SS("_GET") TSRMLS_CC);
	zephir_fetch_params(1, 1, 1, &location_param, &format);

	if (unlikely(Z_TYPE_P(location_param) != IS_STRING && Z_TYPE_P(location_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'location' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(location_param) == IS_STRING)) {
		zephir_get_strval(location, location_param);
	} else {
		ZEPHIR_INIT_VAR(location);
		ZVAL_EMPTY_STRING(location);
	}
	if (!format) {
		format = ZEPHIR_GLOBAL(global_false);
	}


	zephir_array_fetch_string(&_0, _GET, SL("_url"), PH_NOISY | PH_READONLY, "deskcloud/libs/file.zep", 57 TSRMLS_CC);
	ZEPHIR_CALL_FUNCTION(&dir, "dirname", NULL, 1, _0);
	zephir_check_call_status();
	if (ZEPHIR_IS_TRUE(format)) {
		ZEPHIR_INIT_VAR(type$$3);
		zephir_create_array(type$$3, 5, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_1$$3);
		ZVAL_STRING(_1$$3, " bytes", 1);
		zephir_array_fast_append(type$$3, _1$$3);
		ZEPHIR_INIT_NVAR(_1$$3);
		ZVAL_STRING(_1$$3, " KB", 1);
		zephir_array_fast_append(type$$3, _1$$3);
		ZEPHIR_INIT_NVAR(_1$$3);
		ZVAL_STRING(_1$$3, " MB", 1);
		zephir_array_fast_append(type$$3, _1$$3);
		ZEPHIR_INIT_NVAR(_1$$3);
		ZVAL_STRING(_1$$3, " GB", 1);
		zephir_array_fast_append(type$$3, _1$$3);
		ZEPHIR_INIT_NVAR(_1$$3);
		ZVAL_STRING(_1$$3, " TB", 1);
		zephir_array_fast_append(type$$3, _1$$3);
		ZEPHIR_INIT_VAR(_2$$3);
		ZEPHIR_CONCAT_VSV(_2$$3, dir, "/", location);
		ZEPHIR_CALL_FUNCTION(&size, "filesize", &_3, 9, _2$$3);
		zephir_check_call_status();
		ZEPHIR_SINIT_VAR(_4$$3);
		ZVAL_LONG(&_4$$3, 1024);
		ZEPHIR_CALL_FUNCTION(&base, "log", NULL, 10, size, &_4$$3);
		zephir_check_call_status();
		if (ZEPHIR_GT_LONG(base, 0)) {
			ZEPHIR_INIT_VAR(_5$$4);
			ZEPHIR_INIT_VAR(_6$$4);
			ZEPHIR_SINIT_VAR(_7$$4);
			ZVAL_LONG(&_7$$4, 1024);
			ZEPHIR_SINIT_VAR(_8$$4);
			ZVAL_DOUBLE(&_8$$4, (zephir_get_numberval(base) - zephir_floor(base TSRMLS_CC)));
			zephir_pow_function(_6$$4, &_7$$4, &_8$$4);
			ZEPHIR_SINIT_VAR(_9$$4);
			ZVAL_LONG(&_9$$4, 2);
			zephir_round(_5$$4, _6$$4, &_9$$4, NULL TSRMLS_CC);
			zephir_array_fetch(&_10$$4, type$$3, base, PH_NOISY | PH_READONLY, "deskcloud/libs/file.zep", 64 TSRMLS_CC);
			ZEPHIR_CONCAT_VV(return_value, _5$$4, _10$$4);
			RETURN_MM();
		} else {
			RETURN_MM_STRING("0 bytes", 1);
		}
	} else {
		ZEPHIR_INIT_VAR(_11$$6);
		ZEPHIR_CONCAT_VSV(_11$$6, dir, "/", location);
		ZEPHIR_RETURN_CALL_FUNCTION("filesize", &_3, 9, _11$$6);
		zephir_check_call_status();
		RETURN_MM();
	}

}

