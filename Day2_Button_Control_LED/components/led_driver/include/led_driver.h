#ifndef LED_DRIVER_H
#define LED_DRIVER_H

#include <driver/gpio.h>

void led_init(gpio_num_t pin);
void led_control_toggle(gpio_num_t pin);

#endif // LED_DRIVER_H