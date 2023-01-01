#include <stdint.h>
#include "pico/time.h"
#include "hardware/gpio.h"
#include "pico/binary_info.h"

bi_decl(bi_program_name("Blink"));
bi_decl(bi_program_version_string("1.3.3"));
bi_decl(bi_program_build_date_string(__DATE__));

int main()
{
    const uint32_t LED_PIN = 25;

    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);
    while (true) {
        gpio_put(LED_PIN, 1);
        sleep_ms(250);
        gpio_put(LED_PIN, 0);
        sleep_ms(250);
    }

    return 0;
}
