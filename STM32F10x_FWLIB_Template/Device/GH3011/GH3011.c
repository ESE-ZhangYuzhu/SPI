/*
 * @Author: Zhang Yuzhu
 * @Date: 2021-08-05 15:28:10
 * @LastEditors: Zhang Yuzhu
 * @LastEditTime: 2021-08-07 18:38:56
 * @FilePath: \STM32F10x_FWLIB_Template\Device\GH3011\GH3011.c
 * @Description: 
 */
#include "GH3011.h"

u8 GH3011_Init(void)
{
    // u8 TestArr[3] = {0xC0};
    // SPI_CS_Control(0);
    // SPI_WriteData(TestArr, 1);
    // SPI_CS_Control(1);
    // SysTick_Delay_us(5);
    // SysTick_Delay_ms(1);

    // SPI_CS_Control(0);
    // TestArr[0] = 0xF0;
    // TestArr[1] = 0x00;
    // TestArr[2] = 0x28;
    // SPI_WriteData(TestArr, 3);
    // SysTick_Delay_us(15);
    // SPI_CS_Control(1);
    // SysTick_Delay_us(5);

    // TestArr[0] = 0xF1;
    // SPI_CS_Control(0);
    // SPI_WriteData(TestArr, 1);

    // u8 ReadTestArr[10] = {0};
    // SPI_ReadData(ReadTestArr, 10);
    // SPI_CS_Control(1);
    // SysTick_Delay_us(5);

    u8 GH3011_Init_Flag;
    HBD_SetDelayUsCallback(SysTick_Delay_us);
    GH3011_Init_Flag = HBD_SetSpiRW(SPI_WriteData, SPI_ReadData, SPI_CS_Control);
    GH3011_Init_Flag = HBD_CommunicationInterfaceConfirm();
    return GH3011_Init_Flag;
}
