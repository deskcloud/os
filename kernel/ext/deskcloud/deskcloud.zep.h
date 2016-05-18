
extern zend_class_entry *deskcloud_deskcloud_ce;

ZEPHIR_INIT_CLASS(Deskcloud_Deskcloud);

PHP_METHOD(Deskcloud_Deskcloud, version);

ZEPHIR_INIT_FUNCS(deskcloud_deskcloud_method_entry) {
	PHP_ME(Deskcloud_Deskcloud, version, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
