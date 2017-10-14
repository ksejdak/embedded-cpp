# Set project.
BUILD_PATH = build
BIN        = 001_toolchain

# Set toolchain.
CC = gcc

# Set compilation flags.
CFLAGS += -O0 -g

# Add sources
SOURCES = main.c

$(BIN): $(SOURCES)
	mkdir -p $(BUILD_PATH)
	$(CC) $(CFLAGS) $(SOURCES) -o $(BUILD_PATH)/$(BIN).elf

clean:
	rm -f $(BUILD_PATH)/$(BIN).elf
	rmdir $(BUILD_PATH)