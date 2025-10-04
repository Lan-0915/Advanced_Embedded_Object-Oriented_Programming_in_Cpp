#include "stm32f4xx.h"


class GPIO {
private:
	GPIO_TypeDef * port;
	uint8_t pin;

public:
	// 构造函数
	GPIO(GPIO_TypeDef * gpioPort, uint8_t gpioPin, bool isOutput = true): port(gpioPort), pin(gpioPin) {

		// 启用 GPIO 的时钟访问
		if (gpioPort == GPIOA) RCC->AHB1ENR |= (1U<<0);
		if (gpioPort == GPIOC) RCC->AHB1ENR |= (1U<<2);
		// ......

		// 配置引脚
		if (isOutput) {
			gpioPort->MODER |= (1 << (2 * gpioPin));
			gpioPort->MODER &= ~(1 << (2 * gpioPin + 1));
		} else {
			gpioPort->MODER &= ~(3 << (2 * gpioPin));
		}
	}


	// 切换引脚状态
	void toggle() {
		port->ODR ^= (1U << pin);
	}

	// 将引脚设置为低电平
	void setLow() {
		port->ODR &= ~(1U << pin);
	}

	// 将引脚设置为高电平
	void setHigh() {
		port->ODR |= (1U << pin);
	}

	// 读取引脚状态
	bool read() {
		return (port->IDR & (1U << pin));
	}
};
