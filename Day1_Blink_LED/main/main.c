#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "led_driver.h"
#include "sdkconfig.h"
#include <stdio.h>

void app_main() {
  led_init(CONFIG_BLINK_GPIO);
  while (1) {
    led_control_toggle(CONFIG_BLINK_GPIO);
    vTaskDelay(pdMS_TO_TICKS(5000));
  }
}
