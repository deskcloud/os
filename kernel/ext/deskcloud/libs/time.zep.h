
extern zend_class_entry *deskcloud_libs_time_ce;

ZEPHIR_INIT_CLASS(Deskcloud_Libs_Time);

PHP_METHOD(Deskcloud_Libs_Time, now);

ZEND_BEGIN_ARG_INFO_EX(arginfo_deskcloud_libs_time_now, 0, 0, 0)
	ZEND_ARG_INFO(0, timezone)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(deskcloud_libs_time_method_entry) {
	PHP_ME(Deskcloud_Libs_Time, now, arginfo_deskcloud_libs_time_now, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
