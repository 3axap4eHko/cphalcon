
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
#include "kernel/memory.h"
#include "kernel/object.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/array.h"
#include "kernel/operators.h"
#include "kernel/hash.h"


/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2014 Phalcon Team (http://www.phalconphp.com)       |
 +------------------------------------------------------------------------+
 | This source file is subject to the New BSD License that is bundled     |
 | with this package in the file docs/LICENSE.txt.                        |
 |                                                                        |
 | If you did not receive a copy of the license and are unable to         |
 | obtain it through the world-wide-web, please send an email             |
 | to license@phalconphp.com so we can send you a copy immediately.       |
 +------------------------------------------------------------------------+
 | Authors: Andres Gutierrez <andres@phalconphp.com>                      |
 |          Eduar Carvajal <eduar@phalconphp.com>                         |
 +------------------------------------------------------------------------+
 */
/**
 * Phalcon\Di\FactoryConfig
 *
 * This is a variant of the standard Phalcon\Di. By default it automatically
 * registers all the services provided by the framework. Thanks to this, the developer does not need
 * to register each service individually providing a full stack framework
 */
ZEPHIR_INIT_CLASS(Phalcon_Di_FactoryConfig) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Di, FactoryConfig, phalcon, di_factoryconfig, phalcon_di_ce, phalcon_di_factoryconfig_method_entry, 0);

	/**
	 * Default service arguments
	 */
	zend_declare_property_null(phalcon_di_factoryconfig_ce, SL("serviceArguments"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

/**
 * Phalcon\Di\FactoryConfig constructor
 */
PHP_METHOD(Phalcon_Di_FactoryConfig, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_0 = NULL;
	zval *globalConfig_param = NULL, *eventsManager, *loader, *_1, *_2 = NULL;
	zval *globalConfig = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &globalConfig_param);

	globalConfig = globalConfig_param;



	ZEPHIR_CALL_PARENT(NULL, phalcon_di_factoryconfig_ce, this_ptr, "__construct", &_0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_1);
	object_init_ex(_1, phalcon_config_ce);
	ZEPHIR_CALL_METHOD(NULL, _1, "__construct", NULL, globalConfig);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_2);
	ZVAL_STRING(_2, "config", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setshared", NULL, _2, _1);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(loader);
	object_init_ex(loader, phalcon_loader_ce);
	ZEPHIR_CALL_METHOD(NULL, loader, "__construct", NULL);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, loader, "register", NULL);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "loader", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setshared", NULL, _2, loader);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_2);
	array_init(_2);
	zephir_update_property_this(this_ptr, SL("serviceArguments"), _2 TSRMLS_CC);
	ZEPHIR_INIT_VAR(eventsManager);
	object_init_ex(eventsManager, phalcon_events_manager_ce);
	if (zephir_has_constructor(eventsManager TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, eventsManager, "__construct", NULL);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "seteventsmanager", NULL, eventsManager);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, loader, "seteventsmanager", NULL, eventsManager);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "registerconfig", NULL, globalConfig);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Phalcon_Di_FactoryConfig, registerConfig) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *globalConfig_param = NULL, *config = NULL, *_0 = NULL, *_1 = NULL;
	zval *globalConfig = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &globalConfig_param);

	globalConfig = globalConfig_param;



	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "config", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getshared", NULL, _1);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_1);
	object_init_ex(_1, phalcon_config_ce);
	ZEPHIR_CALL_METHOD(NULL, _1, "__construct", NULL, globalConfig);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, _0, "merge", NULL, _1);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(config);
	if (zephir_array_isset_string_fetch(&config, globalConfig, SS("loader"), 0 TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "registerloads", NULL, config);
		zephir_check_call_status();
	}
	ZEPHIR_OBS_NVAR(config);
	if (zephir_array_isset_string_fetch(&config, globalConfig, SS("services"), 0 TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "registerservices", NULL, config);
		zephir_check_call_status();
	}
	ZEPHIR_OBS_NVAR(config);
	if (zephir_array_isset_string_fetch(&config, globalConfig, SS("events"), 0 TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "registerevents", NULL, config);
		zephir_check_call_status();
	}
	RETURN_THIS();

}

/**
 * Register autoload config
 *
 * @param array config
 * @return FactoryConfig
 */
PHP_METHOD(Phalcon_Di_FactoryConfig, registerLoads) {

	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool merge;
	zval *config_param = NULL, *merge_param = NULL, *loader = NULL, *options = NULL, *_0;
	zval *config = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &config_param, &merge_param);

	config = config_param;

	if (!merge_param) {
		merge = 0;
	} else {
		merge = zephir_get_boolval(merge_param);
	}


	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "loader", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&loader, this_ptr, "get", NULL, _0);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(options);
	if (zephir_array_isset_string_fetch(&options, config, SS("namespaces"), 0 TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, loader, "registernamespaces", NULL, options, (merge ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false)));
		zephir_check_call_status();
	}
	ZEPHIR_OBS_NVAR(options);
	if (zephir_array_isset_string_fetch(&options, config, SS("prefixes"), 0 TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, loader, "registerprefixes", NULL, options, (merge ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false)));
		zephir_check_call_status();
	}
	ZEPHIR_OBS_NVAR(options);
	if (zephir_array_isset_string_fetch(&options, config, SS("dirs"), 0 TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, loader, "registerdirs", NULL, options, (merge ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false)));
		zephir_check_call_status();
	}
	ZEPHIR_OBS_NVAR(options);
	if (zephir_array_isset_string_fetch(&options, config, SS("classes"), 0 TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, loader, "registerclasses", NULL, options, (merge ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false)));
		zephir_check_call_status();
	}
	RETURN_THIS();

}

/**
 * Register services
 *
 * @param array config
 * @return FactoryConfig
 */
PHP_METHOD(Phalcon_Di_FactoryConfig, registerServices) {

	zephir_fcall_cache_entry *_7 = NULL, *_11 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_6 = NULL, *_10 = NULL;
	HashTable *_1;
	HashPosition _0;
	zend_bool shared, _8;
	zval *config_param = NULL, *name = NULL, *options = NULL, *args = NULL, *className = NULL, **_2, *_3 = NULL, _4 = zval_used_for_init, *_5 = NULL, *_9 = NULL;
	zval *config = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &config_param);

	config = config_param;



	zephir_is_iterable(config, &_1, &_0, 0, 0, "phalcon/di/factoryconfig.zep", 136);
	for (
	  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zephir_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HMKEY(name, _1, _0);
		ZEPHIR_GET_HVALUE(options, _2);
		ZEPHIR_OBS_NVAR(args);
		if (zephir_array_isset_string_fetch(&args, options, SS("args"), 0 TSRMLS_CC)) {
			zephir_update_property_array(this_ptr, SL("serviceArguments"), name, args TSRMLS_CC);
		}
		ZEPHIR_OBS_NVAR(className);
		if (!(zephir_array_isset_string_fetch(&className, options, SS("class"), 0 TSRMLS_CC))) {
			ZEPHIR_INIT_NVAR(_3);
			object_init_ex(_3, phalcon_di_exception_ce);
			ZEPHIR_SINIT_NVAR(_4);
			ZVAL_STRING(&_4, "Argument 'class' for service '%s' not defined", 0);
			ZEPHIR_CALL_FUNCTION(&_5, "sprintf", &_6, &_4, name);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, _3, "__construct", &_7, _5);
			zephir_check_call_status();
			zephir_throw_exception_debug(_3, "phalcon/di/factoryconfig.zep", 130 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		_8 = zephir_array_isset_string(options, SS("shared"));
		if (_8) {
			ZEPHIR_OBS_NVAR(_9);
			zephir_array_fetch_string(&_9, options, SL("shared"), PH_NOISY, "phalcon/di/factoryconfig.zep", 132 TSRMLS_CC);
			_8 = zephir_is_true(_9);
		}
		shared = _8;
		ZEPHIR_INIT_NVAR(_3);
		object_init_ex(_3, phalcon_di_service_ce);
		ZEPHIR_CALL_METHOD(NULL, _3, "__construct", &_10, name, className, (shared ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false)));
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "setraw", &_11, name, _3);
		zephir_check_call_status();
	}
	RETURN_THIS();

}

/**
 * Register event listeners
 *
 * @param array config
 * @return FactoryConfig
 */
PHP_METHOD(Phalcon_Di_FactoryConfig, registerEvents) {

	zephir_fcall_cache_entry *_7 = NULL, *_8 = NULL, *_10 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_6 = NULL;
	HashTable *_1;
	HashPosition _0;
	zval *config_param = NULL, *name = NULL, *options = NULL, *handler = NULL, *priority = NULL, **_2, *_3 = NULL, _4 = zval_used_for_init, *_5 = NULL, *_9 = NULL;
	zval *config = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &config_param);

	config = config_param;



	zephir_is_iterable(config, &_1, &_0, 0, 0, "phalcon/di/factoryconfig.zep", 157);
	for (
	  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zephir_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HMKEY(name, _1, _0);
		ZEPHIR_GET_HVALUE(options, _2);
		ZEPHIR_OBS_NVAR(handler);
		if (!(zephir_array_isset_string_fetch(&handler, options, SS("handler"), 0 TSRMLS_CC))) {
			ZEPHIR_INIT_NVAR(_3);
			object_init_ex(_3, phalcon_di_exception_ce);
			ZEPHIR_SINIT_NVAR(_4);
			ZVAL_STRING(&_4, "Argument 'handler' for event '%s' not defined", 0);
			ZEPHIR_CALL_FUNCTION(&_5, "sprintf", &_6, &_4, name);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, _3, "__construct", &_7, _5);
			zephir_check_call_status();
			zephir_throw_exception_debug(_3, "phalcon/di/factoryconfig.zep", 149 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_OBS_NVAR(priority);
		if (!(zephir_array_isset_string_fetch(&priority, options, SS("priority"), 0 TSRMLS_CC))) {
			ZEPHIR_INIT_NVAR(priority);
			ZVAL_LONG(priority, 100);
		}
		ZEPHIR_CALL_METHOD(&_5, this_ptr, "geteventsmanager", &_8);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_9, this_ptr, "get", &_10, handler);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, _5, "attach", NULL, name, _9, priority);
		zephir_check_call_status();
	}
	RETURN_THIS();

}

/**
 * Resolves the service based on its configuration
 *
 * @param string name
 * @param array parameters
 * @return mixed
 */
PHP_METHOD(Phalcon_Di_FactoryConfig, get) {

	zephir_nts_static zephir_fcall_cache_entry *_4 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool _0;
	zval *name_param = NULL, *parameters = NULL, *_1, *_2, *_3 = NULL;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &name_param, &parameters);

	if (unlikely(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(name, name_param);
	} else {
		ZEPHIR_INIT_VAR(name);
		ZVAL_EMPTY_STRING(name);
	}
	if (!parameters) {
		ZEPHIR_CPY_WRT(parameters, ZEPHIR_GLOBAL(global_null));
	} else {
		ZEPHIR_SEPARATE_PARAM(parameters);
	}


	_0 = Z_TYPE_P(parameters) == IS_NULL;
	if (_0) {
		_1 = zephir_fetch_nproperty_this(this_ptr, SL("serviceArguments"), PH_NOISY_CC);
		_0 = zephir_array_isset(_1, name);
	}
	if (_0) {
		_2 = zephir_fetch_nproperty_this(this_ptr, SL("serviceArguments"), PH_NOISY_CC);
		ZEPHIR_OBS_NVAR(parameters);
		zephir_array_fetch(&parameters, _2, name, PH_NOISY, "phalcon/di/factoryconfig.zep", 170 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(&_3, this_ptr, "resolvearguments", NULL, parameters);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(parameters, _3);
	}
	ZEPHIR_RETURN_CALL_PARENT(phalcon_di_factoryconfig_ce, this_ptr, "get", &_4, name, parameters);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Resolves the service arguments with existing services
 *
 * @param array arguments
 * @return array
 */
PHP_METHOD(Phalcon_Di_FactoryConfig, resolveArguments) {

	zephir_fcall_cache_entry *_10 = NULL, *_13 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_6 = NULL;
	zend_bool _3, _7;
	HashTable *_1;
	HashPosition _0;
	zval *arguments_param = NULL, *key = NULL, *value = NULL, **_2, *_4 = NULL, *_5 = NULL, *_8 = NULL, *_9, *_11 = NULL, *_12;
	zval *arguments = NULL, *resolvedArguments, *matches;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &arguments_param);

	arguments = arguments_param;

	ZEPHIR_INIT_VAR(resolvedArguments);
	array_init(resolvedArguments);
	ZEPHIR_INIT_VAR(matches);
	array_init(matches);


	zephir_is_iterable(arguments, &_1, &_0, 0, 0, "phalcon/di/factoryconfig.zep", 193);
	for (
	  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zephir_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HMKEY(key, _1, _0);
		ZEPHIR_GET_HVALUE(value, _2);
		_3 = Z_TYPE_P(value) == IS_STRING;
		if (_3) {
			ZEPHIR_INIT_NVAR(_4);
			ZVAL_STRING(_4, "#^@(\\w+)$#", ZEPHIR_TEMP_PARAM_COPY);
			Z_SET_ISREF_P(matches);
			ZEPHIR_CALL_FUNCTION(&_5, "preg_match", &_6, _4, value, matches);
			zephir_check_temp_parameter(_4);
			Z_UNSET_ISREF_P(matches);
			zephir_check_call_status();
			_3 = zephir_is_true(_5);
		}
		_7 = _3;
		if (_7) {
			zephir_array_fetch_long(&_9, matches, 1, PH_NOISY | PH_READONLY, "phalcon/di/factoryconfig.zep", 186 TSRMLS_CC);
			ZEPHIR_CALL_METHOD(&_8, this_ptr, "has", &_10, _9);
			zephir_check_call_status();
			_7 = zephir_is_true(_8);
		}
		if (_7) {
			zephir_array_fetch_long(&_12, matches, 1, PH_NOISY | PH_READONLY, "phalcon/di/factoryconfig.zep", 187 TSRMLS_CC);
			ZEPHIR_CALL_METHOD(&_11, this_ptr, "get", &_13, _12);
			zephir_check_call_status();
			zephir_array_update_zval(&resolvedArguments, key, &_11, PH_COPY | PH_SEPARATE);
		} else {
			zephir_array_update_zval(&resolvedArguments, key, &value, PH_COPY | PH_SEPARATE);
		}
	}
	RETURN_CTOR(resolvedArguments);

}

