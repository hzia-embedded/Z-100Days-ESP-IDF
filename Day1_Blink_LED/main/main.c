#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "led_driver.h"

#define BLINK_GPIO GPIO_NUM_4

void app_main() {
  led_init(BLINK_GPIO);
  while (1) {
    led_control_toggle(BLINK_GPIO);
    vTaskDelay(pdMS_TO_TICKS(500));
  }
}
