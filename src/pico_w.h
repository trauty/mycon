/*
 * Copyright (c) 2022 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

// -----------------------------------------------------
// NOTE: THIS HEADER IS ALSO INCLUDED BY ASSEMBLER SO
//       SHOULD ONLY CONSIST OF PREPROCESSOR DIRECTIVES
// -----------------------------------------------------

// This header may be included by other board headers as "boards/pico.h"

#ifndef _BOARDS_PICO_W_H
#define _BOARDS_PICO_W_H

// For board detection
#define RASPBERRYPI_PICO_W

// --- UART ---
#ifndef PICO_DEFAULT_UART
#define PICO_DEFAULT_UART 0
#endif
#ifndef PICO_DEFAULT_UART_TX_PIN
#define PICO_DEFAULT_UART_TX_PIN 0
#endif
#ifndef PICO_DEFAULT_UART_RX_PIN
#define PICO_DEFAULT_UART_RX_PIN 1
#endif

// --- LED ---
// no PICO_DEFAULT_LED_PIN - LED is on Wireless chip
// no PICO_DEFAULT_WS2812_PIN

// --- I2C ---
#ifndef PICO_DEFAULT_I2C
#define PICO_DEFAULT_I2C 0
#endif
#ifndef PICO_DEFAULT_I2C_SDA_PIN
#define PICO_DEFAULT_I2C_SDA_PIN 4
#endif
#ifndef PICO_DEFAULT_I2C_SCL_PIN
#define PICO_DEFAULT_I2C_SCL_PIN 5
#endif

// --- SPI ---
#ifndef PICO_DEFAULT_SPI
#define PICO_DEFAULT_SPI 0
#endif
#ifndef PICO_DEFAULT_SPI_SCK_PIN
#define PICO_DEFAULT_SPI_SCK_PIN 18
#endif
#ifndef PICO_DEFAULT_SPI_TX_PIN
#define PICO_DEFAULT_SPI_TX_PIN 19
#endif
#ifndef PICO_DEFAULT_SPI_RX_PIN
#define PICO_DEFAULT_SPI_RX_PIN 16
#endif
#ifndef PICO_DEFAULT_SPI_CSN_PIN
#define PICO_DEFAULT_SPI_CSN_PIN 17
#endif

// --- FLASH ---

#define PICO_BOOT_STAGE2_CHOOSE_W25Q080 1

#ifndef PICO_FLASH_SPI_CLKDIV
#define PICO_FLASH_SPI_CLKDIV 2
#endif

#ifndef PICO_FLASH_SIZE_BYTES
#define PICO_FLASH_SIZE_BYTES (2 * 1024 * 1024)
#endif

// note the SMSP mode pin is on WL_GPIO1
// #define PICO_SMPS_MODE_PIN

#ifndef PICO_RP2040_B0_SUPPORTED
#define PICO_RP2040_B0_SUPPORTED 0
#endif

#ifndef PICO_RP2040_B1_SUPPORTED
#define PICO_RP2040_B1_SUPPORTED 0
#endif

#ifndef CYW43_PIN_WL_HOST_WAKE
#define CYW43_PIN_WL_HOST_WAKE 24
#endif

#ifndef CYW43_PIN_WL_REG_ON
#define CYW43_PIN_WL_REG_ON 23
#endif

#ifndef CYW43_WL_GPIO_COUNT
#define CYW43_WL_GPIO_COUNT 3
#endif

#ifndef CYW43_WL_GPIO_LED_PIN
#define CYW43_WL_GPIO_LED_PIN 0
#endif

// If CYW43_WL_GPIO_VBUS_PIN is defined then a CYW43 GPIO has to be used to read VBUS.
// This can be passed to cyw43_arch_gpio_get to determine if the device is battery powered.
// PICO_VBUS_PIN and CYW43_WL_GPIO_VBUS_PIN should not both be defined.
#ifndef CYW43_WL_GPIO_VBUS_PIN
#define CYW43_WL_GPIO_VBUS_PIN 2
#endif

// If CYW43_USES_VSYS_PIN is defined then CYW43 uses the VSYS GPIO (defined by PICO_VSYS_PIN) for other purposes.
// If this is the case, to use the VSYS GPIO it's necessary to ensure CYW43 is not using it.
// This can be achieved by wrapping the use of the VSYS GPIO in cyw43_thread_enter / cyw43_thread_exit.
#ifndef CYW43_USES_VSYS_PIN
#define CYW43_USES_VSYS_PIN 1
#endif

// The GPIO Pin used to monitor VSYS. Typically you would use this with ADC.
// There is an example in adc/read_vsys in pico-examples.
#ifndef PICO_VSYS_PIN
#define PICO_VSYS_PIN 29
#endif

#define TFT_CS_PIN 1
#define TFT_SCK_PIN 2
#define TFT_MOSI_PIN 3
#define TFT_RS_PIN 6
#define TFT_RST_PIN 7

/* SPI device that corresponds with those pins: */
#define TFT_SPI_DEV spi0

/* Maximum speed to use: */
#define TFT_BAUDRATE (64 * 1000 * 1000)

/* Swap axes, or perhaps flip them: */
#define TFT_SWAP_XY 1
#define TFT_FLIP_X 1
#define TFT_FLIP_Y 0

#endif
