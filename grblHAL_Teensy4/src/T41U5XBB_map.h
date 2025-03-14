/*
  T41U5XBB_map.h - driver code for IMXRT1062 processor (on Teensy 4.1 board)

  Part of grblHAL

  Board by Phil Barrett: https://github.com/phil-barrett/grblHAL-teensy-4.x

  Copyright (c) 2020-2023 Terje Io

  Grbl is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  Grbl is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with Grbl.  If not, see <http://www.gnu.org/licenses/>.
*/

#if N_ABC_MOTORS > 2
#error "Axis configuration is not supported!"
#endif

#if SPINDLE_SYNC_ENABLE
#error "Spindle sync is not supported for T41U5XBB!"
#endif

#define BOARD_NAME "T41U5XBB"
#define BOARD_URL "https://github.com/phil-barrett/grbl-teensy-4"
#define HAS_IOPORTS

#define X_STEP_PIN          (2u)
#define X_DIRECTION_PIN     (3u)
#define X_ENABLE_PIN        (10u)
#define X_LIMIT_PIN         (20u)

#define Y_STEP_PIN          (4u)
#define Y_DIRECTION_PIN     (5u)
#define Y_ENABLE_PIN        (40u)
#define Y_LIMIT_PIN         (21u)

#define Z_STEP_PIN          (6u)
#define Z_DIRECTION_PIN     (7u)
#define Z_ENABLE_PIN        (39u)
#define Z_LIMIT_PIN         (22u)

// Define ganged axis or A axis step pulse and step direction output pins.
#if N_ABC_MOTORS > 0
#define M3_AVAILABLE
#define M3_STEP_PIN         (8u)
#define M3_DIRECTION_PIN    (9u)
#define M3_LIMIT_PIN        (23u)
#define M3_ENABLE_PIN       (38u)
#endif

// Define ganged axis or B axis step pulse and step direction output pins.
#if N_ABC_MOTORS == 2
#define M4_AVAILABLE
#define M4_STEP_PIN         (26u)
#define M4_DIRECTION_PIN    (27u)
#define M4_LIMIT_PIN        (28u)
#define M4_ENABLE_PIN       (37u)
#endif

#if MPG_MODE == 1 && !defined(M4_LIMIT_PIN)
#define MPG_MODE_PIN        (28u)
#endif

// Define spindle enable and spindle direction output pins.
#if DRIVER_SPINDLE_ENABLE
#define SPINDLE_ENABLE_PIN      (12u)
#define SPINDLE_DIRECTION_PIN   (11u)
#define SPINDLE_PWM_PIN         (13u) // NOTE: only pin 12 or pin 13 can be assigned!
#endif

// Define flood and mist coolant enable output pins.
#define COOLANT_FLOOD_PIN   (19u)
#define COOLANT_MIST_PIN    (18u)

// Define user-control CONTROLs (cycle start, reset, feed hold, door) input pins.
#define RESET_PIN           (14u)
#define FEED_HOLD_PIN       (16u)
#define CYCLE_START_PIN     (17u)
#if SAFETY_DOOR_ENABLE
#define SAFETY_DOOR_PIN     (29u)
#endif

// Define probe switch input pin.
#define PROBE_PIN           (15u)

#if QEI_ENABLE
#define QEI_A_PIN           (30u) // ST1
#define QEI_B_PIN           (34u) // ST2
#define QEI_SELECT_PIN      (35u) // ST3
#endif

// Define auxillary input pins
#define AUXINPUT0_PIN       (36u) // ST0
#if !QEI_ENABLE
#define AUXINPUT1_PIN       (30u) // ST1
#define AUXINPUT2_PIN       (34u) // ST2
#define AUXINPUT3_PIN       (35u) // ST3
#endif

#define AUXOUTPUT0_PIN      (31u) // AUX0
#define AUXOUTPUT1_PIN      (32u) // AUX1
#define AUXOUTPUT2_PIN      (33u) // AUX2
#if !DRIVER_SPINDLE_ENABLE
#define AUXOUTPUT3_PIN      (12u) // AUX3
#define AUXOUTPUT4_PIN      (11u) // AUX4
#endif

#if I2C_STROBE_ENABLE
#define I2C_STROBE_PIN   (41u) // I2C ST
#endif

#if I2C_ENABLE
#define I2C_PORT    4
#define I2C_SCL4    (24u) // Not referenced, for info only
#define I2C_SDA4    (25u) // Not referenced, for info only
#endif
