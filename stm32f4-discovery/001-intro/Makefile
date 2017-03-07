# Setup binary name from current directory name.
CURRENT_PATH=$(abspath $(lastword $(MAKEFILE_LIST)))
BIN=$(notdir $(patsubst %/,%,$(dir $(CURRENT_PATH))))

# Setup toolchain.
CROSS=arm-none-eabi-

CC=$(CROSS)gcc
OBJCOPY=$(CROSS)objcopy
STRIP=$(CROSS)strip

# Setup compilation and linker flags.
CFLAGS=-mcpu=cortex-m4 -march=armv7e-m -mthumb -mfloat-abi=hard -nostdlib  -lc -lgcc -I CMSIS
LDFLAGS=-T ./stm32f4_discovery.ld

# Setup project files.
SOURCES=CMSIS/system_stm32f4xx.c \
        CMSIS/startup_stm32f40_41xxx.s \
		main.c

$(BIN): $(SOURCES)
	mkdir -p bin
	$(CC) $(CFLAGS) $(LDFLAGS) $(SOURCES) -o bin/$(BIN).elf
	$(OBJCOPY) -O binary bin/$(BIN).elf bin/$(BIN).img

clean:
	rm -f bin/$(BIN).elf bin/$(BIN).img
	rmdir bin