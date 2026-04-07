#include "led_driver.h"
#include "esp_log.h"

static const char *TAG = "LED_DRIVER";

/**
 * @brief Khởi tạo và cấu hình phần cứng cho một chân GPIO cụ thể để điều khiển
 * LED.
 * @param pin Số hiệu chân GPIO cần được cấu hình.
 */
void led_init(gpio_num_t pin) {
  ESP_LOGI(TAG, "Configuring GPIO %d as output", pin);
  gpio_reset_pin(pin);

  gpio_config_t io_cfg = {
      .pin_bit_mask = (1ULL << pin),
      .mode = GPIO_MODE_INPUT_OUTPUT,
  };
  gpio_config(&io_cfg);
}

/**
 * @brief Bật/tắt LED thông qua việc thay đổi mức điện áp trên chân GPIO.
 * @param pin Số hiệu chân GPIO cần được điều khiển.
 */
void led_control_toggle(gpio_num_t pin) {
  int current_level = gpio_get_level(pin);
  ESP_LOGI(TAG, "Turning the LED %s!", current_level == 1 ? "ON" : "OFF");
  gpio_set_level(pin, !current_level);
}