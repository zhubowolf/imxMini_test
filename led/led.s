.global _start

_start:
ldr r0, =0X020C4068 /* CCGR0 */
ldr r1, =0XFFFFFFFF
str r1, [r0]

ldr r0, =0X020C406C /* CCGR1 */
str r1, [r0]

ldr r0, =0X020C4070 /* CCGR2 */
str r1, [r0]

ldr r0, =0X020C4074 /* CCGR3 */
str r1, [r0]

ldr r0, =0X020C4078 /* CCGR4 */
str r1, [r0]

ldr r0, =0X020C407c /* CCGR5 */
str r1, [r0]

ldr r0, =0X020C4080 /* CCGR6 */
str r1, [r0]

ldr r0, =0X020E0068 /* IOMUXC_SW_MUX_CTL_PAD_GPIO1_IO03 */
ldr r1, =0X5        /* ALT5:GPIO1 */
str r1, [r0]

ldr r0, =0X020E02F4 /* IOMUXC_SW_PAD_CTL_PAD_GPIO1_IO03 */
ldr r1, =0X10B0     /* HYS_0_Hysteresis_Disabled;
                        PUS_0_100K_Ohm_Pull_Down;
                        PUE_0_Keeper; 
                        PKE_1_Pull_Keeper_Enabled;
                        ODE_0_Open_Drain_Disabled;
                        SPEED_2_medium_100MHz;
                        DSE_6_R0_6;
                        SRE_0_Slow_Slew_Rate
                        */
str r1, [r0]

ldr r0, =0X0209C004 /* GPIO1_GDIR */
ldr r1, =0X00000008
str r1, [r0]

ldr r0, =0X0209C000 /* GPIO1_DR */
ldr r1, =0
str r1, [r0]

loop:
    b loop
