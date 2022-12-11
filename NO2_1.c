/*
GPIO使用步骤
1.打开GPIO的硬件时钟
2.配置GPIO输入/输出模式
3.操作GPIO端口寄存器
*/
#define u32 unsigned int 
//#define RCC_APB2ENR *(volatile unsigned int *)(0x40021018)//GPIOA ~G挂载在APB2上，需要使能RCC_APB2时钟
//#define GPIOB_CRL   *(volatile unsigned int *)(0x40010C00)//GPIOB地址
//#define GPIOB_ODR   *(volatile unsigned int *)(0x40010C0C)//GPIOB5地址

typedef struct
{
    volatile u32 CR;//0x40021000 基地址
    volatile u32 CFGR;//0x40021004 地址自动偏移+4 以此类推
    volatile u32 CIR;//0x40021008
    volatile u32 APB2RSTR;//0x4002100C
    volatile u32 APB1RSTR;//0x40021010
    volatile u32 AHBENR;//0x40021014
    volatile u32 APB2ENR;//0x40021018
    volatile u32 APB1ENR;//0x4002101C
    volatile u32 BDCR;//0x40021020
    volatile u32 CSR;//0x40021024
}RCC_Typedef; 

typedef struct
{
    volatile u32 CRL;//0x40010C00 GPIOB基地址
    volatile u32 CRH;//0x40010C04
    volatile u32 IDR;//0x40010C08
    volatile u32 ODR;//0x40010C0C
    volatile u32 BSRR;//0x40010C10
    volatile u32 BRR;//0x40010C14
    volatile u32 LCKR;//0x40010C18
}GPIO_Typedef;

#define RCC       ((RCC_Typedef *)(0x40021000))//RCC时钟的结构体指针
#define GPIOB     ((GPIO_Typedef *)(0x40010C00))//GPIOB的结构体指针
#define GPIOA     ((GPIO_Typedef *)(0x40010800))//GPIOA的结构体指针

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