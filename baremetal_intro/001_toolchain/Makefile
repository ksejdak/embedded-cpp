# Set project.
BUILD_PATH = build
BIN        = 001_toolchain

# Set toolchain.
CC = gcc

# Add sources
SOURCES = main.c

$(BIN): $(SOURCES)
	mkdir -p $(BUILD_PATH)
	$(CC) $(SOURCES) -o $(BUILD_PATH)/$(BIN).elf

clean:
	rm -f $(BUILD_PATH)/$(BIN).elf
	rmdir $(BUILD_PATH)
