#include "adc.h"
#include "stm32f4xx.h"

#define GPIOAEN			(1U<<0)
#define ADC1EN			(1U<<8)
#define ADC_CH1			(1U<<0)
#define AD_SEQ_LEN_1	0X00
#define CR2_ADCON		(1U<<0)
#define CR2_CONT		(1U<<1)
#define CR2_SWSTART		(1U<<30)
#define SR_EOC			(1U<<1)


void pal_adc_init(void) {
	/**
	 * 配置 ADC GPIO 引脚
	 */
	// 1. 启用 GPIOA 的时钟访问
	RCC->AHB1ENR |= GPIOAEN;

	// 2. 将 PA1 模式设置为模拟模式
	GPIOA->MODER |=(1U<<2);
	GPIOA->MODER |=(1U<<3);


	/**
	 * 配置 ADC 模块
	 */
	// 1. 启用 ADC 模块的时钟访问
	RCC->APB2ENR |= ADC1EN;

	// 2. 设置转换序列开始
	ADC1->SQR3 = ADC_CH1;

	// 3. 设置转换序列长度
	ADC1->SQR1 = AD_SEQ_LEN_1;

	// 4. 启用 ADC 模块
	ADC1->CR2 |= CR2_ADCON;
}


void start_conversion(void) {
	// 启用连续转换
	ADC1->CR2 |= CR2_CONT;

	// 开始 AD 转换
	ADC1->CR2 |= CR2_SWSTART;
}


uint32_t adc_read(void) {
	// 等待转换完成
	while (!(ADC1->SR & SR_EOC)) {}

	// 读取转换后的值
	return (ADC1->DR);
}




