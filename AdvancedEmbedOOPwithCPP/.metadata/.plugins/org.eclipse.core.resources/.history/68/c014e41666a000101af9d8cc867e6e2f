#include "ADC.hpp"


#define GPIOAEN			(1U<<0)
#define ADC1EN			(1U<<8)
#define ADC_CH1			(1U<<0)
#define AD_SEQ_LEN_1	0X00
#define CR2_ADCON		(1U<<0)
#define CR2_CONT		(1U<<1)
#define CR2_SWSTART		(1U<<30)
#define SR_EOC			(1U<<1)


// 构造函数
ADC_MODULE::ADC_MODULE(ADC_TypeDef * adc, GPIO_TypeDef * gpioPort, uint8_t pin)
: adc(adc), gpioPort(gpioPort), pin(pin) {}


// 初始化
void ADC_MODULE::init() {
	/**
	 * 配置 ADC GPIO 引脚
	 */
	// 1. 启用 GPIO (A / B / ......) 的时钟访问
	RCC->AHB1ENR |= GPIOAEN;
	// ......

	// 2. 将 pin 模式设置为模拟模式
	gpioPort->MODER |= (1U << (2 * pin));
	gpioPort->MODER |= (1U << (2 * pin + 1));


	/**
	 * 配置 ADC 模块
	 */
	// 1. 启用 ADC 模块的时钟访问
	RCC->APB2ENR |= ADC1EN;

	// 2. 设置转换序列开始
	adc->SQR3 = ADC_CH1;

	// 3. 设置转换序列长度
	adc->SQR1 = AD_SEQ_LEN_1;

	// 4. 启用 ADC 模块
	adc->CR2 |= CR2_ADCON;
}



// 启动转换函数
void ADC_MODULE::startConversion() {
	// 启用连续转换
	adc->CR2 |= CR2_CONT;

	// 开始 AD 转换
	adc->CR2 |= CR2_SWSTART;
}


// 读取功能函数
uint32_t ADC_MODULE::read() {
	// 等待转换完成
	while (!(adc->SR & SR_EOC)) {}

	// 读取转换后的值
	return (adc->DR);
}











