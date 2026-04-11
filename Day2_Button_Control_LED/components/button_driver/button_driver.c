#include "button_driver.h"
#include "esp_log.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

static const char *TAG = "BUTTON_DRIVER";

/**
 * @brief Khởi tạo và cấu hình button
 * @param pin Số hiệu chân GPIO cần được cấu hình.
 */
void button_init(gpio_num_t pin) {
  ESP_LOGI(TAG, "Configuring GPIO %d as input", pin);
  gpio_reset_pin(pin);

  gpio_config_t io_cfg = {
      .pin_bit_mask = (1ULL << pin),
      .mode = GPIO_MODE_INPUT,
      .pull_up_en = true,
      .pull_down_en = false,
      .intr_type = GPIO_INTR_DISABLE,
  };
  gpio_config(&io_cfg);
}

/**
 * @brief Kiểm tra trạng thái nút nhấn (có Debounce)
 * @return true nếu nút đang được nhấn
 */
bool button_was_pressed(gpio_num_t pin) {
    static uint32_t last_time = 0;
    static bool last_state = 1;
    static bool stable_state = 1;

    bool reading = gpio_get_level(pin);
    uint32_t now = xTaskGetTickCount();

    if (reading != last_state) {
        last_time = now;
        last_state = reading;
    }

    if ((now - last_time) > pdMS_TO_TICKS(20)) {
        if (stable_state != reading) {
            stable_state = reading;

            // chỉ trả về true khi vừa nhấn (HIGH → LOW)
            if (stable_state == 0) {
                return true;
            }
        }
    }

    return false;
}