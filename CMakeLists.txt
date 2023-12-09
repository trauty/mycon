cmake_minimum_required(VERSION 3.13)

# initialize the SDK based on PICO_SDK_PATH
# note: this must happen before project()
set(PICO_SDK_PATH ${CMAKE_SOURCE_DIR}/pico-sdk)
set(PICO_BOARD pico_w)
set(PICO_BOARD_HEADER_DIRS ${CMAKE_SOURCE_DIR}/src)
include(pico_sdk_import.cmake)

project(mycon)

# initialize the Raspberry Pi Pico SDK
pico_sdk_init()

add_executable(mycon_exec
    src/main.c
    src/display/ili9225.c
    src/display/font.c
    src/display/tft.c
)

# Add pico_stdlib library which aggregates commonly used features
target_link_libraries(mycon_exec 
    pico_stdlib
    pico_util
    pico_divider
    hardware_spi
    hardware_timer
    hardware_dma
)

target_include_directories(mycon_exec PUBLIC
    ${CMAKE_SOURCE_DIR}/src
    ${CMAKE_SOURCE_DIR}/src/display
)

# create map/bin/hex/uf2 file in addition to ELF.
pico_add_extra_outputs(mycon_exec)