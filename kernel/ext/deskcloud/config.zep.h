
extern zend_class_entry *deskcloud_config_ce;

ZEPHIR_INIT_CLASS(Deskcloud_Config);

PHP_METHOD(Deskcloud_Config, config);

ZEND_BEGIN_ARG_INFO_EX(arginfo_deskcloud_config_config, 0, 0, 3)
	ZEND_ARG_INFO(0, location)
	ZEND_ARG_INFO(0, section)
	ZEND_ARG_INFO(0, config)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(deskcloud_config_method_entry) {
	PHP_ME(Deskcloud_Config, config, arginfo_deskcloud_config_config, ZEND_ACC_PRIVATE|ZEND_ACC_STATIC)
	PHP_FE_END
};
