#include <stdint.h>
#include "pico/time.h"
#include "hardware/gpio.h"
#include "hardware/divider.h"
#include "pico/unique_id.h"
#include "pico/binary_info.h"

bi_decl(bi_program_name("Blink"));
bi_decl(bi_program_version_string("1.3.3"));
bi_decl(bi_program_build_date_string(__DATE__));

int main()
{
    const uint32_t LED_PIN = 25;

//    volatile int kk = __clzsi2(1);
//    volatile int ss = 55;
//    volatile int gg1 = __builtin_clz(1);
//    volatile int gg = hw_divider_u32_remainder(ss, kk);
//
//
//    volatile float a,b,c;
//
//    a = 55.5f;
//    b = 11.0f;
//
//    c = a / b;
//
//    volatile double a1,b1,c1;
//
//    a1 = 55.5;
//    b1 = 11.0;
//
//    c1 = a1 / b1;
//
//    volatile pico_unique_board_id_t id;
//    pico_get_unique_board_id(&id);

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
