# Setup binary name from current directory name.
CURRENT_PATH = $(abspath $(lastword $(MAKEFILE_LIST)))
BIN = $(notdir $(patsubst %/,%,$(dir $(CURRENT_PATH))))

# Setup toolchain.
CROSS = arm-none-eabi-

CC = $(CROSS)gcc
OBJCOPY = $(CROSS)objcopy

# Setup compilation and linker flags.
CFLAGS  = -march=armv7e-m -mcpu=cortex-m4
CFLAGS += -mthumb
CFLAGS += -O0 -g
CFLAGS += -I ../lib/CMSIS -I ../lib/drivers
CFLAGS += -DUSE_STDPERIPH_DRIVER
LDFLAGS = -T ../stm32f4_discovery.ld

# Setup project files.
SOURCES_CMSIS   = ../lib/CMSIS/system_stm32f4xx.c \
                  ../lib/CMSIS/startup_stm32f40_41xxx.s
SOURCES_DRIVERS = ../lib/drivers/stm32f4xx_gpio.c \
		          ../lib/drivers/stm32f4xx_rcc.c \
				  ../lib/drivers/stm32f4xx_usart.c
SOURCES         = main.c syscalls.c console.c

$(BIN): $(SOURCES)
	mkdir -p bin
	$(CC) $(CFLAGS) $(LDFLAGS) $(SOURCES) $(SOURCES_CMSIS) $(SOURCES_DRIVERS) -o bin/$(BIN).elf
	$(OBJCOPY) -O binary bin/$(BIN).elf bin/$(BIN).img

clean:
	rm -f bin/$(BIN).elf bin/$(BIN).img
	rmdir bin