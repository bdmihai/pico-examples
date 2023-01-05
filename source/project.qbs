/*_____________________________________________________________________________
 │                                                                            |
 │ COPYRIGHT (C) 2022 Mihai Baneu                                             |
 │                                                                            |
 | Permission is hereby  granted,  free of charge,  to any person obtaining a |
 | copy of this software and associated documentation files (the "Software"), |
 | to deal in the Software without restriction,  including without limitation |
 | the rights to  use, copy, modify, merge, publish, distribute,  sublicense, |
 | and/or sell copies  of  the Software, and to permit  persons to  whom  the |
 | Software is furnished to do so, subject to the following conditions:       |
 |                                                                            |
 | The above  copyright notice  and this permission notice  shall be included |
 | in all copies or substantial portions of the Software.                     |
 |                                                                            |
 | THE SOFTWARE IS PROVIDED  "AS IS",  WITHOUT WARRANTY OF ANY KIND,  EXPRESS |
 | OR   IMPLIED,   INCLUDING   BUT   NOT   LIMITED   TO   THE  WARRANTIES  OF |
 | MERCHANTABILITY,  FITNESS FOR  A  PARTICULAR  PURPOSE AND NONINFRINGEMENT. |
 | IN NO  EVENT SHALL  THE AUTHORS  OR  COPYRIGHT  HOLDERS  BE LIABLE FOR ANY |
 | CLAIM, DAMAGES OR OTHER LIABILITY,  WHETHER IN AN ACTION OF CONTRACT, TORT |
 | OR OTHERWISE, ARISING FROM,  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR  |
 | THE USE OR OTHER DEALINGS IN THE SOFTWARE.                                 |
 |____________________________________________________________________________|
 |                                                                            |
 |  Author: Mihai Baneu                           Last modified: 16.Dec.2022  |
 |                                                                            |
 |___________________________________________________________________________*/
  
import qbs

Project {
    name: 'examples'
    minimumQbsVersion: '1.24'
    qbsSearchPaths: '../qbs'

    references: [
        //'app/blink/app.qbs',
        //'app/hello_world/serial/app.qbs',
        //'app/hello_world/usb/app.qbs',
        //'app/dma/hello_dma/app.qbs',
        //'app/dma/control_blocks/app.qbs',
        //'app/multicore/hello_multicore/app.qbs',
        //'app/multicore/multicore_fifo_irqs/app.qbs',
        //'app/multicore/multicore_runner/app.qbs',
        //'app/multicore/multicore_runner_queue/app.qbs',
        //'app/divider/app.qbs',
        //'app/uart/hello_uart/app.qbs',
        //'app/uart/uart_advanced/app.qbs',
        //'app/flash/program/app.qbs',
        //'app/flash/cache_perfctr/app.qbs',
        //'app/flash/ssi_dma/app.qbs',
        //'app/flash/xip_stream/app.qbs',
        //'app/watchdog/hello_watchdog/app.qbs',
        //'app/system/hello_double_tap/app.qbs',
        //'app/system/narrow_io_write/app.qbs',
        //'app/system/unique_board_id/app.qbs',
        //'app/reset/hello_reset/app.qbs',
        //'app/timer/hello_timer/app.qbs',
        //'app/timer/periodic_sampler/app.qbs',
        //'app/timer/timer_lowlevel/app.qbs',
        //'app/interp/hello_interp/app.qbs',
        //'app/clocks/detached_clk_peri/app.qbs',
        //'app/clocks/hello_48MHz/app.qbs',
        //'app/clocks/hello_gpout/app.qbs',
        //'app/clocks/hello_resus/app.qbs',
        //'app/picoboard/blinky/app.qbs',
        //'app/picoboard/button/app.qbs',
        //'app/rtc/hello_rtc/app.qbs',
        //'app/rtc/rtc_alarm/app.qbs',
        //'app/rtc/rtc_alarm_repeat/app.qbs',
        //'app/adc/hello_adc/app.qbs',
        //'app/usb/device/dev_lowlevel/app.qbs',
        //'app/usb/device/dev_hid_composite/app.qbs',
        //'app/gpio/button/app.qbs',
        'app/pwm/led_fade/app.qbs',
        //'app/pwm/hello_pwm/app.qbs',
        //'app/pwm/measure_duty_cycle/app.qbs',
        'boot/boot.qbs',
        'rp2040/rp2040.qbs',
        'tinyusb/tinyusb.qbs'
    ]

    SubProject {
        filePath: 'sdk/sdk.qbs'
        Properties {
            projectDefines: [
                //'PICO_TIME_DEFAULT_ALARM_POOL_DISABLED=1'
            ]
        }
    }
}


