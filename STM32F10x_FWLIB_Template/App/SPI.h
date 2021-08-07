/*
 * @Author: Zhang Yuzhu
 * @Date: 2021-08-05 14:25:35
 * @LastEditors: Zhang Yuzhu
 * @LastEditTime: 2021-08-06 16:32:28
 * @FilePath: \STM32F10x_FWLIB_Template\App\SPI.h
 * @Description: 
 */
#ifndef __SPI_H
#define __SPI_H

#include "stm32f10x.h"
#include "GPIO_Bit_Band.h"
#include "SysTick.h"

void SPI_CS_Control(u8 CS_Level);
u8 SPI_WriteData(u8 WriteBytesArr[], u16 WriteLen);
u8 SPI_ReadData(u8 ReadBytesArr[], u16 MaxReadLen);

#endif // !__SPI_H
