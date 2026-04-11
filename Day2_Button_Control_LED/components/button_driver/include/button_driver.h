#ifndef BUTTON_DRIVER_H
#define BUTTON_DRIVER_H

#include <driver/gpio.h>
#include <stdbool.h>


void button_init(gpio_num_t pin);

bool button_was_pressed(gpio_num_t pin);

#endif // BUTTON_DRIVER_H