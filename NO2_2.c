#include "stm32f10x.h"
int main(void)
{
    RCC->APB2ENR |= 1 << 3;//使能外设GPIOB寄存器，只使能GPIOB（32位寄存器）
   /*可以配置为00输入，01输出模式 10MHZ 10输出模式 2MHZ  11输出模式 50Mhz*/
    GPIOB->CRL &= ~(0x0f << 5 * 4);
    /*输入模式下可以配置为模拟输入、上拉下拉输入、保留*/
    /*输出模式下 推挽、开漏、复用推挽、复用开漏*/
    GPIOB->CRL |= 3 << 5 * 4;
    /*GPIOB5输出低电平*/
    GPIOB->CRL &= ~(1 << 5);
    while (1)
    {

    }
}