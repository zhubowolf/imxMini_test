#include "delay.h"

void delay_short(volatile unsigned int n)
{
    while (n--)
    {
    }
}

void delay(volatile unsigned int n)
{
    while (n--)
    {
        delay_short(0x7ff);
    }
}