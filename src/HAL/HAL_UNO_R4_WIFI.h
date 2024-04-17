// Platform setup ------------------------------------------------------------------------------------
#pragma once

// This is for fast processors with hardware FP
#define HAL_FAST_PROCESSOR

// Base rate for critical task timing (0.0095s = 0.14", 0.2 sec/day)
#define HAL_FRACTIONAL_SEC 105.2631579F

// Analog read and write
#ifndef ANALOG_READ_RANGE
  #define ANALOG_READ_RANGE 1023
#endif
#ifndef ANALOG_WRITE_RANGE
  #define ANALOG_WRITE_RANGE 255
#endif
#ifndef ANALOG_WRITE_PWM_BITS
  #define ANALOG_WRITE_PWM_BITS 8
#endif

// Lower limit (fastest) step rate in uS for this platform (in SQW mode) and width of step pulse
#ifndef HAL_MAXRATE_LOWER_LIMIT
  #define HAL_MAXRATE_LOWER_LIMIT 60
#endif
#ifndef HAL_PULSE_WIDTH
  #define HAL_PULSE_WIDTH 10000  // in ns, estimated
#endif

// New symbol for the default I2C port -------------------------------------------------------------
#include <Wire.h>
#define HAL_Wire Wire
#define HAL_WIRE_CLOCK 100000

// Non-volatile storage ----------------------------------------------------------------------------
#if NV_DRIVER == NV_DEFAULT
  #define E2END 4095
  #include "../lib/nv/NV_EEPROM.h"
  #define HAL_NV_INIT() nv.init(2048, true, 0, false)
#endif

//--------------------------------------------------------------------------------------------------
// General purpose initialize for HAL
#define HAL_INIT() { ; }

//--------------------------------------------------------------------------------------------------
// Internal MCU temperature (in degrees C)
#define HAL_TEMP() ( NAN )

// stand-in for delayNanoseconds()
#define delayNanoseconds(ns) delayMicroseconds(ceilf(ns/1000.0F))
