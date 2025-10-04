#include "FPU.hpp"

void FPU_CP::enable(void) {
	// 启用浮点单元（Enable CP10 and CP11）
	SCB->CPACR |= (1<<20);
	SCB->CPACR |= (1<<21);
	SCB->CPACR |= (1<<22);
	SCB->CPACR |= (1<<23);
}
