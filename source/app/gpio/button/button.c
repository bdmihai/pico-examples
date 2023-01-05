#include <stdio.h>
#include "pico/time.h"
#include "hardware/gpio.h"


int main() {
    gpio_init(PICO_DEFAULT_LED_PIN);
    gpio_set_dir(PICO_DEFAULT_LED_PIN, GPIO_OUT);
    gpio_init(PICO_DEFAULT_KEY_PIN);
    gpio_set_dir(PICO_DEFAULT_KEY_PIN, GPIO_IN);
    while (true) {
        gpio_put(PICO_DEFAULT_LED_PIN, gpio_get(PICO_DEFAULT_KEY_PIN));
        sleep_ms(10);
    }
}
