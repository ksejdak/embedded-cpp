////////////////////////////////////////////////////////////////////////////////////////////////
///
/// @file
/// @author     Kuba Sejdak
/// @date       11.03.2017
///
/// @copyright  This file is a part of embedded-cpp.com project.
///
////////////////////////////////////////////////////////////////////////////////////////////////

#include "stm32f4xx_gpio.h"
#include "stm32f4xx_rcc.h"

#define LED_RED     GPIO_Pin_14
#define LED_BLUE    GPIO_Pin_15

int main(int argc, char *argv[])
{
    // Enable peripheral clock for GPIOD.
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);

    // Configure pins for red anb blue LEDs to output pushpull mode.
    GPIO_InitTypeDef GPIO_InitStructure;
    GPIO_InitStructure.GPIO_Pin = LED_RED | LED_BLUE;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
    GPIO_Init(GPIOD, &GPIO_InitStructure);

    while (1) {
        GPIOD->BSRRL = LED_RED | LED_BLUE;
        GPIOD->BSRRH = LED_RED | LED_BLUE;
    }

    return 0;
}
