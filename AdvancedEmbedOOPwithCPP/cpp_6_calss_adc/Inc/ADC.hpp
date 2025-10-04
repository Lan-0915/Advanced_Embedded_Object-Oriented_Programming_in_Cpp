#ifndef ADC_HPP
#define ADC_HPP

#include "stm32f4xx.h"


class ADC_MODULE {
private:
	ADC_TypeDef * adc;
	GPIO_TypeDef * gpioPort;
	uint8_t pin;

public:
	// 构造函数
	ADC_MODULE(ADC_TypeDef * adc, GPIO_TypeDef * gpioPort, uint8_t pin);

	// 初始化
	void init();

	// 启动转换函数
	void startConversion();

	// 读取功能函数
	uint32_t read();
};



#endif
