# Set project.
BUILD_PATH = build
STM32F4_PATH = ../../lib/stm32f4
BIN = 002_stm32f4

# Set toolchain.
CROSS = arm-none-eabi-
CC = $(CROSS)gcc
OBJCOPY = $(CROSS)objcopy

# Set compilation flags.
CFLAGS  = -march=armv7e-m -mcpu=cortex-m4
CFLAGS += -mthumb -O0 -g
CFLAGS += -nostdlib
CFLAGS += -I $(STM32F4_PATH)/CMSIS -I $(STM32F4_PATH)/drivers
CFLAGS += -DUSE_STDPERIPH_DRIVER
LDFLAGS = -T stm32f4discovery.ld

# Add sources.
SOURCES_STM32F4 = $(STM32F4_PATH)/CMSIS/system_stm32f4xx.c \
                  $(STM32F4_PATH)/CMSIS/startup_stm32f40_41xxx.s \
                  $(STM32F4_PATH)/drivers/stm32f4xx_gpio.c \
		          $(STM32F4_PATH)/drivers/stm32f4xx_rcc.c \
				  $(STM32F4_PATH)/drivers/stm32f4xx_usart.c
SOURCES = main.c console.c

$(BIN): $(SOURCES)
	mkdir -p $(BUILD_PATH)
	$(CC) $(CFLAGS) $(LDFLAGS) $(SOURCES) $(SOURCES_STM32F4) -o $(BUILD_PATH)/$(BIN).elf
	$(OBJCOPY) -O binary $(BUILD_PATH)/$(BIN).elf $(BUILD_PATH)/$(BIN).img

clean:
	rm -rf $(BUILD_PATH)
