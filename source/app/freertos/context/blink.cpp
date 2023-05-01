#include <stdint.h>
#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "picortos.h"
#include "task.h"


static void vTaskLED(void *pvParameters)
{
    (void)pvParameters;

    gpio_init(PICO_DEFAULT_LED_PIN);
    gpio_set_dir(PICO_DEFAULT_LED_PIN, GPIO_OUT);

    for (;;) {
        
            TickType_t xLastWakeTime;

            xLastWakeTime = xTaskGetTickCount();

            gpio_put(PICO_DEFAULT_LED_PIN, 1);
            vTaskDelayUntil(&xLastWakeTime, 250 / portTICK_PERIOD_MS);

            gpio_put(PICO_DEFAULT_LED_PIN, 0);
            vTaskDelayUntil(&xLastWakeTime, 250 / portTICK_PERIOD_MS);
    }
}

static void vTaskPI1(void *pvParameters)
{
    (void)pvParameters;

    for (;;) {
        int r[2800 + 1];
        int i, k;
        int b, d;
        int c = 0;

        printf("vTaskPI1: core %d\n", get_core_num());

        for (i = 0; i < 2800; i++) {
            r[i] = 2000;
        }

        for (k = 2800; k > 0; k -= 14) {
            d = 0;

            i = k;
            for (;;) {
                d += r[i] * 10000;
                b = 2 * i - 1;

                r[i] = d % b;
                d /= b;
                i--;
                if (i == 0) break;
                d *= i;
            }
            c = d % 10000;
        }
        
        vTaskDelay(5000 / portTICK_PERIOD_MS);
    }
}

static void vTaskPI2(void *pvParameters)
{
    (void)pvParameters;

    for (;;) {
        int r[2800 + 1];
        int i, k;
        int b, d;
        int c = 0;

        printf("vTaskPI2: core %d\n", get_core_num());

        for (i = 0; i < 2800; i++) {
            r[i] = 2000;
        }

        for (k = 2800; k > 0; k -= 14) {
            d = 0;

            i = k;
            for (;;) {
                d += r[i] * 10000;
                b = 2 * i - 1;

                r[i] = d % b;
                d /= b;
                i--;
                if (i == 0) break;
                d *= i;
            }
            c = d % 10000;
        }
        vTaskDelay(500 / portTICK_PERIOD_MS);
    }
}

int main(void)
{
    stdio_init_all();

    /* create the tasks specific to this application. */
    xTaskCreateAffinitySet(vTaskLED,  "vTaskLED",  configMINIMAL_STACK_SIZE,  NULL, 1, 0x01, NULL);
    xTaskCreateAffinitySet(vTaskPI1,  "vTaskPI1",   3000,                     NULL, 1, 0x03, NULL);
    xTaskCreateAffinitySet(vTaskPI2,  "vTaskPI2",   3000,                     NULL, 2, 0x03, NULL);

    /* start the scheduler. */
    vTaskStartScheduler();

    /* should never get here ... */
    return 0;
}
