#pragma once

#include "config.h"

// Tested with display model ER-TFT035-6 from BuyDisplay.com:
// https://www.buydisplay.com/serial-spi-3-5-inch-tft-lcd-module-in-320x480-optl-touchscreen-ili9488
// Using long dupont wires to connect to a Pi Zero, the clock divider was tested down to a value of 12.

// Data specific to the ILI948X controllers
#define DISPLAY_SET_CURSOR_X 0x2A
#define DISPLAY_SET_CURSOR_Y 0x2B
#define DISPLAY_WRITE_PIXELS 0x2C

#define DISPLAY_NATIVE_WIDTH  480
#define DISPLAY_NATIVE_HEIGHT 640
#define DISPLAY_ACTUAL_HEIGHT 320
#define DOUBLE_HEIGHT

// I believe this reduces the effective screen size
#define DISPLAY_NATIVE_COVERED_LEFT_SIDE 00
#define DISPLAY_NATIVE_COVERED_TOP_SIDE 0

// 18 bits/pixel R6G6B6 format (padded to 3 bytes per pixel), and no 16-bits R5G6B5 mode.
//#define DISPLAY_COLOR_FORMAT_R5X2G5X2B5X2
#define DISPLAY_COLOR_FORMAT_R6X2G6X2B6X2
// ILI948X does not behave well if one sends partial commands, but must finish each command or the command does not apply
#define MUST_SEND_FULL_CURSOR_WINDOW

void InitILI9488(void);
#define InitSPIDisplay InitILI9488
