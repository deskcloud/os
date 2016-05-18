
extern zend_class_entry *deskcloud_libs_file_ce;

ZEPHIR_INIT_CLASS(Deskcloud_Libs_File);

PHP_METHOD(Deskcloud_Libs_File, create);
PHP_METHOD(Deskcloud_Libs_File, read);
PHP_METHOD(Deskcloud_Libs_File, extension);
PHP_METHOD(Deskcloud_Libs_File, time);
PHP_METHOD(Deskcloud_Libs_File, copy);
PHP_METHOD(Deskcloud_Libs_File, rename);
PHP_METHOD(Deskcloud_Libs_File, delete);
PHP_METHOD(Deskcloud_Libs_File, size);

ZEND_BEGIN_ARG_INFO_EX(arginfo_deskcloud_libs_file_create, 0, 0, 2)
	ZEND_ARG_INFO(0, location)
	ZEND_ARG_INFO(0, content)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_deskcloud_libs_file_read, 0, 0, 1)
	ZEND_ARG_INFO(0, location)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_deskcloud_libs_file_extension, 0, 0, 1)
	ZEND_ARG_INFO(0, location)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_deskcloud_libs_file_time, 0, 0, 2)
	ZEND_ARG_INFO(0, format)
	ZEND_ARG_INFO(0, location)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_deskcloud_libs_file_copy, 0, 0, 2)
	ZEND_ARG_INFO(0, location)
	ZEND_ARG_INFO(0, newlocation)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_deskcloud_libs_file_rename, 0, 0, 2)
	ZEND_ARG_INFO(0, location)
	ZEND_ARG_INFO(0, newname)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_deskcloud_libs_file_delete, 0, 0, 1)
	ZEND_ARG_INFO(0, location)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_deskcloud_libs_file_size, 0, 0, 1)
	ZEND_ARG_INFO(0, location)
	ZEND_ARG_INFO(0, format)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(deskcloud_libs_file_method_entry) {
	PHP_ME(Deskcloud_Libs_File, create, arginfo_deskcloud_libs_file_create, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Deskcloud_Libs_File, read, arginfo_deskcloud_libs_file_read, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Deskcloud_Libs_File, extension, arginfo_deskcloud_libs_file_extension, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Deskcloud_Libs_File, time, arginfo_deskcloud_libs_file_time, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Deskcloud_Libs_File, copy, arginfo_deskcloud_libs_file_copy, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Deskcloud_Libs_File, rename, arginfo_deskcloud_libs_file_rename, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Deskcloud_Libs_File, delete, arginfo_deskcloud_libs_file_delete, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Deskcloud_Libs_File, size, arginfo_deskcloud_libs_file_size, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
