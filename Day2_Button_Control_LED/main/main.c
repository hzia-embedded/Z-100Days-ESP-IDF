#include <stdio.h>
#include "button_driver.h"
#include "led_driver.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

void app_main(void)
{
  button_init(CONFIG_BUTTON_GPIO);
  led_init(CONFIG_LED_GPIO);

  while (1) {
    if (button_was_pressed(CONFIG_BUTTON_GPIO)) {
      led_control_toggle(CONFIG_LED_GPIO);
    }
    vTaskDelay(pdMS_TO_TICKS(10));
  }
}
