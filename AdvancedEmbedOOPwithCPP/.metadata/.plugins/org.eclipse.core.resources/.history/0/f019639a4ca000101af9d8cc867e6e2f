#include "GPIO.hpp"


int main() {
	// 将 PA5 设置为输出引脚
	GPIO led(GPIOA, 5, true);

	// 将 PC13 设置为输入引脚
	GPIO button(GPIOC, 13, false);

	while (1) {
		if (!button.read()) {
			led.toggle();
		}
	}
}
