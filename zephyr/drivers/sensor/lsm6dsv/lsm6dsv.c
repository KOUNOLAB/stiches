#include "lsm6dsv.h"

#include <drivers/gpio.h>
#include <logging/log.h>

struct lsm6dsv_data {};

struct lsm6dsv_config {};

LOG_MODULE_REGISTER(lsm6dsv, CONFIG_SENSOR_LOG_LEVEL);

static void lsm6dsv_gpio_callback(const struct device *dev,
                                  struct gpio_callback *cb,
                                  uint32_t pins) {
    LOG_INF("GPIO callback");
}

static int lsm6dsv_cycle(const struct device *dev) {
    LOG_INF("Cycling");
    return 0;
}

static int lsm6dsv_init(const struct device *dev) {
    LOG_INF("Initializing");
    return 0;
}

static int lsm6dsv_sample_fetch(const struct device *dev,
                                enum sensor_channel channel) {
    LOG_INF("Fetching");
    return 0;
}

static int lsm6dsv_channel_get(const struct device *dev,
                               enum sensor_channel channel,
                               struct sensor_value *val) {
    LOG_INF("Getting channel");
    return 0;
}

static int lsm6dsv_attr_set(const struct device *dev,
                            enum sensor_channel chan,
                            enum sensor_attribute attr,
                            const struct sensor_value *val) {
    LOG_INF("Setting attribute");
    return 0;
}

static int lsm6dsv_attr_get(const struct device *dev,
                            enum sensor_channel chan,
                            enum sensor_attribute attr,
                            struct sensor_value *val) {
    LOG_INF("Getting attribute");
    return 0;
}

static int lsm6dsv_pm_action(const struct device *dev,
                             enum pm_device_action action) {
    LOG_INF("Power management action");
    return 0;
}

static const struct sensor_driver_api lsm6dsv_driver_api = {
        .sample_fetch = lsm6dsv_sample_fetch,
        .channel_get = lsm6dsv_channel_get,
        .attr_set = lsm6dsv_attr_set,
        .attr_get = lsm6dsv_attr_get,
};

#define LSM6DSV_INIT(index) \
    static struct lsm6dsv_data lsm6dsv_data_##index = {}; \
\
    static const struct lsm6dsv_config lsm6dsv_config_##index = {}; \
\
    PM_DEVICE_DT_INST_DEFINE(index, lsm6dsv_pm_action); \
\
    DEVICE_DT_INST_DEFINE(index, \
                          lsm6dsv_init, \
                          PM_DEVICE_DT_INST_GET(index), \
                          &lsm6dsv_data_##index, \
                          &lsm6dsv_config_##index, \
                          POST_KERNEL, \
                          CONFIG_SENSOR_INIT_PRIORITY, \
                          &lsm6dsv_driver_api);

DT_INST_FOREACH_STATUS_OKAY(LSM6DSV_INIT)
