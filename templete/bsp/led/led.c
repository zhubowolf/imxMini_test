#include "led.h"

void led_init(void)
{
    IOMUXC_SetPinMux(IOMUXC_GPIO1_IO03_GPIO1_IO03, 0);
    IOMUXC_SetPinConfig(IOMUXC_GPIO1_IO03_GPIO1_IO03, 0x10b0);
    GPIO1->GDIR |= (1 << 3);
    GPIO1->DR &= ~(1 << 3);
}

void led_switch(int led, int status)
{
    switch (led)
    {
    case LED0:
        if(status == ON)
        {
            GPIO1->DR &= ~(1<<3);
        }
        else if (status == OFF)
        {
            GPIO1->DR |= (1<<3);
        }
        break;
    }
}