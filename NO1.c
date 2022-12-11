

/*(unsigned int *)(地址) 取地址赋值*/
/*RCC地址0x40021000 RCC_APB2ENR在RCC上偏移0x18*/
/*GPIOB地址0x40010C00 GPIOB_CRL在GPIOB上偏移0x00*/
/*GPIOB地址0x40010C00 GPIOB_ODR在GPIOB上偏移0x0C*/
#define RCC_APB2ENR *(volatile unsigned int *)(0x40021018)//GPIOA ~G挂载在APB2上，需要使能RCC_APB2时钟
#define GPIOB_CRL   *(volatile unsigned int *)(0x40010C00)//GPIOB地址
#define GPIOB_ODR   *(volatile unsigned int *)(0x40010C0C)//GPIOB5地址
//stm32f103c8t6程序需要启动的汇编代码startup_stm32f10x_md.s
//汇编代码startup_stm32f10x_md.s系统时钟初始化函数需要注释
int main(void)
{
    RCC_APB2ENR |= 1 << 3;//使能外设GPIOB寄存器，只使能GPIOB（32位寄存器）
   /*可以配置为00输入，01输出模式 10MHZ 10输出模式 2MHZ  11输出模式 50Mhz*/
    GPIOB_CRL &= ~(0x0f << 5 * 4);
    /*输入模式下可以配置为模拟输入、上拉下拉输入、保留*/
    /*输出模式下 推挽、开漏、复用推挽、复用开漏*/
    GPIOB_CRL |= 3 << 5 * 4;
    /*GPIOB5输出低电平*/
    GPIOB_ODR &= ~(1 << 5);
    while (1)
    {

    }
}

/*总结
1.(unsigned int *)(地址) 取地址赋值

2.从数据手册看RCC、RCC_APB2ENR、GPIOB等的地址

3.注意地址的偏移

4.程序编译需要汇编启动代码

5.或等于|=在不改变其他位的数据下，对某一位进行置1，
  上例RCC_APB2ENR第3位置1，以及GPIOB_CRL的20 21位置1  

6.与等于 &=在不改变其他位的数据下，对某一位进行置0,
  上例为清零GPIOB_CRL20 21 22 23位，以及GPIOB_ODR第5位置0
*/