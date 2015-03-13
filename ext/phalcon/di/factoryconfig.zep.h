
extern zend_class_entry *phalcon_di_factoryconfig_ce;

ZEPHIR_INIT_CLASS(Phalcon_Di_FactoryConfig);

PHP_METHOD(Phalcon_Di_FactoryConfig, __construct);
PHP_METHOD(Phalcon_Di_FactoryConfig, registerConfig);
PHP_METHOD(Phalcon_Di_FactoryConfig, registerLoads);
PHP_METHOD(Phalcon_Di_FactoryConfig, registerServices);
PHP_METHOD(Phalcon_Di_FactoryConfig, registerEvents);
PHP_METHOD(Phalcon_Di_FactoryConfig, get);
PHP_METHOD(Phalcon_Di_FactoryConfig, resolveArguments);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_di_factoryconfig___construct, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, globalConfig, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_di_factoryconfig_registerconfig, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, globalConfig, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_di_factoryconfig_registerloads, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, config, 0)
	ZEND_ARG_INFO(0, merge)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_di_factoryconfig_registerservices, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, config, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_di_factoryconfig_registerevents, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, config, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_di_factoryconfig_get, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, parameters)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_di_factoryconfig_resolvearguments, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, arguments, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_di_factoryconfig_method_entry) {
	PHP_ME(Phalcon_Di_FactoryConfig, __construct, arginfo_phalcon_di_factoryconfig___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Di_FactoryConfig, registerConfig, arginfo_phalcon_di_factoryconfig_registerconfig, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Di_FactoryConfig, registerLoads, arginfo_phalcon_di_factoryconfig_registerloads, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Di_FactoryConfig, registerServices, arginfo_phalcon_di_factoryconfig_registerservices, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Di_FactoryConfig, registerEvents, arginfo_phalcon_di_factoryconfig_registerevents, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Di_FactoryConfig, get, arginfo_phalcon_di_factoryconfig_get, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Di_FactoryConfig, resolveArguments, arginfo_phalcon_di_factoryconfig_resolvearguments, ZEND_ACC_PUBLIC)
  PHP_FE_END
};
