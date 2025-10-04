#ifndef ADXL345_HPP
#define ADXL345_HPP

#include "SPI.hpp"
#include <cstdint>



/**
 * ADXL345 类
 * 包含了 ADXL345 传感器的操作功能
 * */
class ADXL345 {
private:
	SPI& spi;
	uint8_t deviceAddress;
	int16_t accel_x, accel_y, accel_z;

	void writeRegister(uint8_t reg, uint8_t value);
	void readRegister(uint8_t reg, uint8_t * data, uint8_t size);

public:
	// 构造函数, 用于初始化 ADXL345 传感器
	// spi 参数为 SPI 类型, deviceAddress 参数为设备地址
	ADXL345(SPI& spi, uint8_t deviceAddress = 0x53);

	// 初始化 ADXL345 传感器
	void init();

	// 读取原始加速度计数据并更新内部变量
	void updateAcceleration();

	// 获取 x 轴的原始加速度值
	int16_t getAccelX();

	// 获取 y 轴的原始加速度值
	int16_t getAccelY();

	// 获取 z 轴的原始加速度值
	int16_t getAccelZ();

	// 获取 x 轴的原始加速度 g 单位下的值
	float getAccelXG();

	// 获取 y 轴的原始加速度 g 单位下的值
	float getAccelYG();

	// 获取 z 轴的原始加速度 g 单位下的值
	float getAccelZG();
};



#endif
