set(SOURCES
    CMSIS/system_stm32f4xx.c
    CMSIS/startup_stm32f40_41xxx.s
    drivers/stm32f4xx_gpio.c
    drivers/stm32f4xx_rcc.c
    drivers/stm32f4xx_usart.c
)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -DUSE_STDPERIPH_DRIVER")

include_directories(CMSIS)
include_directories(drivers)
add_library(drivers ${SOURCES})
