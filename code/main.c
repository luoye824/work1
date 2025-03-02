/**
 * 本代码参考自江协科技的STM32入门教程
 * 教程链接：https://jiangxiekeji.com
#include "stm32f10x.h"  // STM32F10x系列芯片头文件
#include <Delay.h>       // 自定义延时函数头文件
#include <led.h>         // LED相关功能头文件

/*
 * @brief LED闪烁处理函数
 * @details 依次点亮GPIOA上的三个LED灯，并在每次切换前延迟500毫秒。
 */
void Led_Proc(void)
{
    GPIO_Write(GPIOA, ~0x0001);  // 点亮第一个LED（GPIOA的第0位控制LED）
    Delay_ms(500);               // 延时500毫秒
    GPIO_Write(GPIOA, ~0x0002);  // 点亮第二个LED（GPIOA的第1位控制LED）
    Delay_ms(500);               // 延时500毫秒
    GPIO_Write(GPIOA, ~0x0004);  // 点亮第三个LED（GPIOA的第2位控制LED）
    Delay_ms(500);               // 延时500毫秒
}

/*
 * @brief 主函数入口
 * @details 初始化LED模块，并进入主循环，持续调用Led_Proc函数。
 */
int main(void)
{
    LED_Init();  // 初始化LED模块（配置GPIO为输出模式）
    
    while(1)      
    {
        Led_Proc();  // 调用LED处理函数
    }
}





