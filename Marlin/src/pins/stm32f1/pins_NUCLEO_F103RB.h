/**
 * Marlin 3D Printer Firmware
 * Copyright (c) 2020 MarlinFirmware [https://github.com/MarlinFirmware/Marlin]
 *
 * Based on Sprinter and grbl.
 * Copyright (c) 2011 Camiel Gubbels / Erik van der Zalm
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 *
 */
#pragma once

#if NOT_TARGET(STM32F1, STM32F1xx)
  #error "Oops! Select an STM32F1/4 board in 'Tools > Board.'"
#endif

/**
 * Anthony Brown test for Nucleo F103RB
 */

#define BOARD_INFO_NAME      "Nucleo F103RB"
#define DEFAULT_MACHINE_NAME BOARD_INFO_NAME

// Enable I2C_EEPROM for testing
//#define I2C_EEPROM

// Ignore temp readings during development.
//#define BOGUS_TEMPERATURE_GRACE_PERIOD    2000

//
// Limit Switches
//
#define X_MAX_PIN                          PC8
#define Y_MAX_PIN                          PA12
#define Z_MAX_PIN                          PB2
#define Z_MIN_PIN                          PB1 //bed probe

//
// Z Probe (when not Z_MIN_PIN)
//
  
//#define Z_MIN_PROBE_PIN                    PB1

//
// Steppers
//
#define X_STEP_PIN                          PA6
#define X_DIR_PIN                           PA8
#define X_ENABLE_PIN                        PC2

#define Y_STEP_PIN                          PB5
#define Y_DIR_PIN                           PB4
#define Y_ENABLE_PIN                        PC2

#define Z_STEP_PIN                          PC6
#define Z_DIR_PIN                           PB3
#define Z_ENABLE_PIN                        PC2

#define E0_STEP_PIN                         PC4 //wasted pin
#define E0_DIR_PIN                          PB10 //wasted pin
#define E0_ENABLE_PIN                       PA10 //wasted pin

/*#define E1_STEP_PIN                         PE9
#define E1_DIR_PIN                          PE8
#define E1_ENABLE_PIN                       PC2

#define E2_STEP_PIN                         PE11
#define E2_DIR_PIN                          PE10
#define E2_ENABLE_PIN                       PC2*/

// Microstepping pins
#define X_MS1_PIN                           PC0
#define X_MS2_PIN                           PC1
#define X_MS3_PIN                           PC3
#define Y_MS1_PIN                           PC0
#define Y_MS2_PIN                           PC1
#define Y_MS3_PIN                           PC3
#define Z_MS1_PIN                           PC0
#define Z_MS2_PIN                           PC1
#define Z_MS3_PIN                           PC3

//
// Misc. Functions
//
//#define SDSS                                PA15
#define LED_PIN                             PA5

//
// Heaters / Fans
//
//#define HEATER_0_PIN                        PD12  // EXTRUDER 1
//#define HEATER_1_PIN                      PD13

//#define HEATER_BED_PIN                      PB9   // BED
//#define HEATER_BED2_PIN                   -1    // BED2
//#define HEATER_BED3_PIN                   -1    // BED3

//#ifndef FAN_PIN
//  #define FAN_PIN                           PD14
//#endif
//#define FAN1_PIN                            PD13

#define FAN_SOFT_PWM

//
// Temperature Sensors
//
//#define TEMP_BED_PIN                        PA0
#define TEMP_0_PIN                          PB7
//#define TEMP_1_PIN                          PA2
//#define TEMP_2_PIN                          PA3

// spindle control
#if HAS_CUTTER
  #define SPINDLE_LASER_PWM_PIN             PC7
  #define SPINDLE_LASER_ENA_PIN             PB6 //wasted pin
  //#define SPINDLE_LASER_DIR_PIN             PB7
#endif

//
// LCD Pins
//
#if HAS_WIRED_LCD

  #if ENABLED(REPRAPWORLD_GRAPHICAL_LCD)
    #define LCD_PINS_RS                       49  // CS chip select /SS chip slave select
    #define LCD_PINS_ENABLE                   51  // SID (MOSI)
    #define LCD_PINS_D4                       52  // SCK (CLK) clock
  #elif BOTH(NEWPANEL, PANEL_ONE)
    #define LCD_PINS_RS                     PB8
    #define LCD_PINS_ENABLE                 PD2
    #define LCD_PINS_D4                     PB12
    #define LCD_PINS_D5                     PB13
    #define LCD_PINS_D6                     PB14
    #define LCD_PINS_D7                     PB15
  #else
    #define LCD_PINS_RS                     PB8
    #define LCD_PINS_ENABLE                 PD2
    #define LCD_PINS_D4                     PB12
    #define LCD_PINS_D5                     PB13
    #define LCD_PINS_D6                     PB14
    #define LCD_PINS_D7                     PB15
    #if DISABLED(NEWPANEL)
      #define BEEPER_PIN                      33
      // Buttons attached to a shift register
      // Not wired yet
      //#define SHIFT_CLK                     38
      //#define SHIFT_LD                      42
      //#define SHIFT_OUT                     40
      //#define SHIFT_EN                      17
    #endif
  #endif

  #if NEED_TOUCH_PINS

    #define TOUCH_CS_PIN                    PB12  // SPI2_NSS
    #define TOUCH_SCK_PIN                   PB13
    #define TOUCH_MOSI_PIN                  PB14
    #define TOUCH_MISO_PIN                  PB15
    #define TOUCH_INT_PIN                   PC6   // (PenIRQ coming from ADS7843)

  #elif ENABLED(NEWPANEL)

    #if ENABLED(REPRAP_DISCOUNT_SMART_CONTROLLER)

      #define BEEPER_PIN                      37

      #define BTN_EN1                         31
      #define BTN_EN2                         33
      #define BTN_ENC                         35

      #define SD_DETECT_PIN                   49
      #define KILL_PIN                        41

      #if ENABLED(BQ_LCD_SMART_CONTROLLER)
        #define LCD_BACKLIGHT_PIN             39
      #endif

    #elif ENABLED(REPRAPWORLD_GRAPHICAL_LCD)

      #define BTN_EN1                         64
      #define BTN_EN2                         59
      #define BTN_ENC                         63
      #define SD_DETECT_PIN                   42

    #elif ENABLED(LCD_I2C_PANELOLU2)

      #define BTN_EN1                         47
      #define BTN_EN2                         43
      #define BTN_ENC                         32
      #define LCD_SDSS                        53
      #define SD_DETECT_PIN                 -1
      #define KILL_PIN                        41

    #elif ENABLED(LCD_I2C_VIKI)

      #define BTN_EN1                         22  // https://files.panucatt.com/datasheets/viki_wiring_diagram.pdf explains 40/42.
      #define BTN_EN2                          7  // 22/7 are unused on RAMPS_14. 22 is unused and 7 the SERVO0_PIN on RAMPS_13.

      #define BTN_ENC                       -1
      #define LCD_SDSS                        53
      #define SD_DETECT_PIN                   49

    #elif ANY(VIKI2, miniVIKI)

      #define BEEPER_PIN                      33

      // Pins for DOGM SPI LCD Support
      #define DOGLCD_A0                       44
      #define DOGLCD_CS                       45
      #define LCD_SCREEN_ROT_180

      #define BTN_EN1                         22
      #define BTN_EN2                          7
      #define BTN_ENC                         39

      #define SDSS                            53
      #define SD_DETECT_PIN                 -1    // Pin 49 for display sd interface, 72 for easy adapter board

      #define KILL_PIN                        31

      #define STAT_LED_RED_PIN                32
      #define STAT_LED_BLUE_PIN               35

    #elif ENABLED(ELB_FULL_GRAPHIC_CONTROLLER)

      #define BTN_EN1                         35
      #define BTN_EN2                         37
      #define BTN_ENC                         31
      #define SD_DETECT_PIN                   49
      #define LCD_SDSS                        53
      #define KILL_PIN                        41
      #define BEEPER_PIN                      23
      #define DOGLCD_CS                       29
      #define DOGLCD_A0                       27
      #define LCD_BACKLIGHT_PIN               33

    #elif ENABLED(MINIPANEL)

      #define BEEPER_PIN                      42
      // Pins for DOGM SPI LCD Support
      #define DOGLCD_A0                       44
      #define DOGLCD_CS                       66
      #define LCD_BACKLIGHT_PIN               65  // backlight LED on A11/D65
      #define SDSS                            53

      #define KILL_PIN                        64
      // GLCD features
      // Uncomment screen orientation
      //#define LCD_SCREEN_ROT_90
      //#define LCD_SCREEN_ROT_180
      //#define LCD_SCREEN_ROT_270
      // The encoder and click button
      #define BTN_EN1                         40
      #define BTN_EN2                         63
      #define BTN_ENC                         59
      // not connected to a pin
      #define SD_DETECT_PIN                   49

    #else

      // Beeper on AUX-4
      #define BEEPER_PIN                      33

      // Buttons directly attached to AUX-2
      #if ENABLED(REPRAPWORLD_KEYPAD)
        #define BTN_EN1                       64
        #define BTN_EN2                       59
        #define BTN_ENC                       63
        #define SHIFT_OUT                     40
        #define SHIFT_CLK                     44
        #define SHIFT_LD                      42
      #elif ENABLED(PANEL_ONE)
        #define BTN_EN1                       59  // AUX2 PIN 3
        #define BTN_EN2                       63  // AUX2 PIN 4
        #define BTN_ENC                       49  // AUX3 PIN 7
      #else
        #define BTN_EN1                       37
        #define BTN_EN2                       35
        #define BTN_ENC                       31
      #endif

      #if ENABLED(G3D_PANEL)
        #define SD_DETECT_PIN                 49
        #define KILL_PIN                      41
      #else
        //#define SD_DETECT_PIN             -1    // Ramps doesn't use this
      #endif

    #endif
  #endif // NEWPANEL

#endif // HAS_WIRED_LCD
