#include "main.h"

void clk_enable(void)
{
    CCM_CCGR0 = 0xffffffff;
    CCM_CCGR1 = 0xffffffff;
    CCM_CCGR2 = 0xffffffff;
    CCM_CCGR3 = 0xffffffff;
    CCM_CCGR4 = 0xffffffff;
    CCM_CCGR5 = 0xffffffff;
    CCM_CCGR6 = 0xffffffff;
}

void led_init(void)
{
    SW_MUX_GPIO1_IO03 = 0x5;

    SW_PAD_GPIO1_IO03 = 0X10b0;

    GPIO1_GDIR = 0X00000008;

    GPIO1_DR = 0X0;
}

void led_on(void)
{
    GPIO1_DR &= ~(1<<3);
}

void led_off(void)
{
    GPIO1_DR |= (1<<3);
}

void delay_short(volatile unsigned int n)
{
    while (n--)
    {
        /* code */
    }
}

void delay(volatile unsigned int n)
{
    while (n--)
    {
        delay_short(0x7ff);
    }
}

int main(void)
{
    clk_enable();
    led_init();

    while (1)
    {
       led_off();
       delay(500);

       led_on();
       delay(500);
    }

    return 0;
}