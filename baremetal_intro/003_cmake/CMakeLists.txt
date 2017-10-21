cmake_minimum_required(VERSION 3.7)

# Set project.
set(PROJECT_NAME 003_stm32f4)
project(${PROJECT_NAME} C ASM)

# Set toolchain.
set(CROSS arm-none-eabi-)
set(CMAKE_C_COMPILER ${CROSS}gcc)
set(CMAKE_ASM_COMPILER ${CROSS}as)
set(CMAKE_RANLIB ${CROSS}ranlib)

# Set compilation flags.
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -march=armv7e-m -mcpu=cortex-m4")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -mthumb")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -nostdlib")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c11")
set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -O0")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -T ${CMAKE_SOURCE_DIR}/stm32f4discovery.ld")
set(CMAKE_EXECUTABLE_SUFFIX ".elf")

if (APPLE)
    # On macOS -search_paths_first linker flag breaks the build.
    string(REPLACE "-Wl,-search_paths_first" "" CMAKE_C_LINK_FLAGS ${CMAKE_C_LINK_FLAGS})
endif()

# Add sources.
set(SOURCES
    main.c
    console.c
)

# Add drivers.
set(STM32F4_PATH ${CMAKE_SOURCE_DIR}/../../lib/stm32f4)
add_subdirectory(${STM32F4_PATH} ${CMAKE_BINARY_DIR}/stm32f4)
include_directories(${STM32F4_PATH}/drivers)
include_directories(${STM32F4_PATH}/CMSIS)

# Define executable.
add_executable(${PROJECT_NAME} ${SOURCES})
target_link_libraries(${PROJECT_NAME} stm32f4)

add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD COMMAND
    ${CROSS}objcopy -O binary ${PROJECT_NAME}.elf ${PROJECT_NAME}.img
)
