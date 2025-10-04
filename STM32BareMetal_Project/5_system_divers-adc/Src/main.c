#include <stdio.h>
#include "stm32f4xx.h"
#include "fpu.h"
#include "uart.h"
#include "timebase.h"
#include "bsp.h"
#include "adc.h"

/**
 * Module:
 * FPU			// FPUF浮点单元模块
 * UART			// UART驱动, 在串行终端产生结果
 * TIMEBASE		// 时间基准, 制造延迟
 * GPIO (BSP)	// GPIO模块, 打开LED, 来测试输出
 * ADC
 * */



#define GPIOAEN		(10<<0)
#define PINS		(10<<5)
#define LED_PIN		PINS

bool btn_state;
uint32_t sensor_calue;

int main() {

	// Enable FPU
	fpu_enable();

	// 初始化调试 UART
	debug_uart_init();

	// 初始化时间基准函数
	timebase_init();

	// 初始化 LED
	led_init();

	// 初始化按钮
	button_init();

	// 初始化 ADC
	pal_adc_init();

	// 开始转换
	start_conversion();


	while (1) {
		led_on();
		btn_state = get_btn_state();

		sensor_calue = adc_read();
	}
}

