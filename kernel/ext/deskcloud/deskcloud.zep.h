
extern zend_class_entry *deskcloud_deskcloud_ce;

ZEPHIR_INIT_CLASS(Deskcloud_Deskcloud);

PHP_METHOD(Deskcloud_Deskcloud, version);

ZEND_BEGIN_ARG_INFO_EX(arginfo_deskcloud_deskcloud_version, 0, 0, 1)
	ZEND_ARG_INFO(0, location)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(deskcloud_deskcloud_method_entry) {
	PHP_ME(Deskcloud_Deskcloud, version, arginfo_deskcloud_deskcloud_version, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
