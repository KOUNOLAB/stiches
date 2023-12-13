#include <drivers/gpio.h>
#include <kernel.h>
#include <stdbool.h>
#include <zephyr.h>

#define BUTTON_NODE DT_ALIAS(button)
static const struct gpio_dt_spec button =
        GPIO_DT_SPEC_GET_OR(BUTTON_NODE, gpios, {0});
static struct gpio_callback button_cb_data;

#define LED_NODE DT_ALIAS(led_red)
static const struct gpio_dt_spec led = GPIO_DT_SPEC_GET(LED_NODE, gpios);

void button_pressed(const struct device *dev,
                    struct gpio_callback *cb,
                    uint32_t pins) {
    gpio_pin_toggle_dt(&led);
}

int main(void) {
    int ret;

    ret = gpio_pin_configure_dt(&button, GPIO_INPUT);
    if (ret != 0) {
        return 0;
    }

    ret = gpio_pin_interrupt_configure_dt(&button, GPIO_INT_EDGE_TO_ACTIVE);
    if (ret != 0) {
        return 0;
    }

    gpio_init_callback(&button_cb_data, button_pressed, BIT(button.pin));
    gpio_add_callback(button.port, &button_cb_data);

    ret = gpio_pin_configure_dt(&led, GPIO_OUTPUT_ACTIVE);
    if (ret < 0) {
        return 0;
    }

    while (1) {
        // int val = gpio_pin_get_dt(&button);
        //
        // if (val >= 0) {
        //     gpio_pin_set_dt(&led, val);
        // }
    }

    return 0;
}
