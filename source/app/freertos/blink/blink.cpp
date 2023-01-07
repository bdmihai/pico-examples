#include <stdint.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "picortos.h"
#include "task.h"

static void vTaskLED(void *pvParameters)
{
    (void)pvParameters;
    const uint32_t LED_PIN = 25;

    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);

    for (;;) {
        gpio_put(LED_PIN, 1);
        vTaskDelay(100 / portTICK_PERIOD_MS);

        gpio_put(LED_PIN, 0);
        vTaskDelay(100 / portTICK_PERIOD_MS);
    }
}

int main(void)
{
    stdio_init_all();

    /* create the tasks specific to this application. */
    xTaskCreate(vTaskLED, "vTaskLED", configMINIMAL_STACK_SIZE, NULL, 1, NULL);

    /* start the scheduler. */
    vTaskStartScheduler();

    /* should never get here ... */
    return 0;
}
