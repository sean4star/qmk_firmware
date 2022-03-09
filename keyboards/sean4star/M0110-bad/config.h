/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#include "config_common.h"


/* USB Device descriptor parameter */
#define VENDOR_ID    0x0001
#define PRODUCT_ID   0x0001
#define DEVICE_VER   0x0001
#define MANUFACTURER sean4star
#define PRODUCT      Apple M0110 Keyboard


/* key matrix size */
// Rows are doubled-up
#define MATRIX_ROWS  5
#define MATRIX_COLS  14

#define MATRIX_ROW_PINS 		{ B0, B1, B2, B3, B7 }
#define MATRIX_COL_PINS 		{ F0, F1, F4, F5, F6, F7, B6, B5, B4, D7, D4, D5, C7, C6 }
//#define MATRIX_ROW_PINS_RIGHT 	{ B0, B1, B2, B3, B7 }
//#define MATRIX_COL_PINS_RIGHT 	{ F0, F1, F4, F5, F6, F7, B6, B5, B4, D7, D4, D5, C7, C6 }

#define DIODE_DIRECTION COL2ROW


#define BOOTMAGIC_LITE_ROW 				0
#define BOOTMAGIC_LITE_COLUMN 			0
//#define BOOTMAGIC_LITE_ROW_RIGHT 		0
//#define BOOTMAGIC_LITE_COLUMN_RIGHT 	0


/* define if matrix has ghost */
//#define MATRIX_HAS_GHOST

/* Set 0 if debouncing isn't needed */
#define DEBOUNCE 5

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
//#define LOCKING_SUPPORT_ENABLE
/* Locking resynchronize hack */
//#define LOCKING_RESYNC_ENABLE

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
// #define NO_DEBUG

/* disable print */
// #define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT
//#define NO_ACTION_MACRO
//#define NO_ACTION_FUNCTION

#undef TAPPING_FORCE_HOLD
#define TAPPING_TERM 200

#define USE_SERIAL

#define SOFT_SERIAL_PIN D2

#define NO_ACTION_MACRO
#define NO_ACTION_FUNCTION


#define SPLIT_HAND_MATRIX_GRID D0, F1				// the first pin is the output pin and the second pin is the input pin
//#define SPLIT_HAND_MATRIX_GRID_LOW_IS_RIGHT		// when a diode is connected to an intersection, it is judged to be left. If you add the following definition, it will be judged to be right

/*	Note that adding a diode at a previously unused intersection will effectively tell the firmware that there is a key held down at that point. You can
	instruct qmk to ignore that intersection by defining MATRIX_MASKED and then defining a matrix_row_t matrix_mask[MATRIX_ROWS] array in
	your keyboard config. Each bit of a single value (starting form the least-significant bit) is used to tell qmk whether or not to pay attention to key
	presses at that intersection.
	
	While MATRIX_MASKED isn’t necessary to use SPLIT_HAND_MATRIX_GRID successfully, without it you may experience issues trying to suspend your
	computer with your keyboard attached as the matrix will always report at least one key-press.
*/





