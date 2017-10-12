cmake_minimum_required(VERSION 3.7)

# Set project.
set(PROJECT_NAME 002_stm32f4)
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
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c11")
set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -O0")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -T ${CMAKE_SOURCE_DIR}/stm32f4discovery.ld")
set(CMAKE_EXECUTABLE_SUFFIX ".elf")

if (APPLE)
    # On macOS -search_paths_first linker flag breaks the build.
    string(REPLACE "-Wl,-search_paths_first" "" CMAKE_C_LINK_FLAGS ${CMAKE_C_LINK_FLAGS})
endif()

# Set sources.
add_subdirectory(lib)
include_directories(lib/CMSIS)
include_directories(lib/drivers)

set(SOURCES
    main.c
    console.c
    syscalls.c
)

add_executable(${PROJECT_NAME} ${SOURCES})
target_link_libraries(${PROJECT_NAME} drivers)

add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD COMMAND
    ${CROSS}objcopy -O binary ${PROJECT_NAME}.elf ${PROJECT_NAME}.img
)
