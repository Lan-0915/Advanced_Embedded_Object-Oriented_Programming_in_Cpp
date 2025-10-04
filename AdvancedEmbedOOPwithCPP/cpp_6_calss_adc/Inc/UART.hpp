#ifndef UART_HPP
#define UART_HPP

#include "stm32f4xx.h"


class UART {
private:
	USART_TypeDef * uart;
	uint32_t baudrate;

	void setBuadRate(uint32_t periph_clk) {
		uart->BRR = ((periph_clk + (baudrate / 2U)) / baudrate);
	}

public:
	// 构造函数
	UART(USART_TypeDef * uart, uint32_t baudrate): uart(uart), baudrate(baudrate) {
		/**
		 * GPIO 引脚的配置
		 * */
		// 1. 启用对 GPIOA 的时钟访问
		RCC->AHB1ENR |= (1U<<0);

		// 2. 将 PA2 模式设置为替代功能模式
		GPIOA->MODER &= ~(1U<<4);
		GPIOA->MODER |= (1U<<5);

		// 3. 设置替代功能类型 AF07 (UART2_TX)
		GPIOA->AFR[0] |= (1U<<8);
		GPIOA->AFR[0] |= (1U<<9);
		GPIOA->AFR[0] |= (1U<<10);
		GPIOA->AFR[0] &= ~(1U<<11);


		/**
		 * UART 的配置
		 * */
		// 1. 启用对 UART2 的时钟访问
		RCC->APB1ENR |= (1U<<17);

		// 2. 配置 UART 的波特率
		setBuadRate(16000000);

		// 3. 配置传输方向
		USART2->CR1 = (1U<<3);

		// 4. 启用 UART 模块
		USART2->CR1 |= (1U<<13);
	}


	// 发送单个字符
	void send(char ch) {
		// 传输数据前，确保数据寄存器是空的
		while (!(USART2->SR & (1U<<7))) {}

		// 写入数据寄存器
		USART2->DR = (ch & 0xFF);
	}

	// 发送字符串
	void sendString(const char * str) {
		while (*str) {
			send(*str++);
		}
	}

	// 发送整数
	void sendInterger(int num) {
		char buffer[12];	// 用于存储整数字符串的缓冲区（最多10位数字 + 符号 + 结束符）
		int i= 0;
		bool isNegative = false;

		// 处理负数
		if (num < 0) {
			isNegative = true;
			num -= num;
		}

		// int 转 string (倒序)
		do {
			buffer[i++] = (num % 10) + '0';
			num /= 10;
		} while (num > 10);

		// 加负数的符号
		if (isNegative) {
			buffer[i++] = '-';
		}

		buffer[i] = '\0';	// 加入结束符

		// 将倒序变为正序
		for (int j = 0; j < i / 2; j++) {
			char temp = buffer[j];
			buffer[j] = buffer[i - 1 - j];
			buffer[i - 1 - j] = temp;
		}

		// 发送
		sendString(buffer);
	}
};



#endif
