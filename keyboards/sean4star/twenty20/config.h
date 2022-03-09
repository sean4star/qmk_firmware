/*
Copyright 2012 Jun Wako <wakojun@gmail.com>

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

#ifndef CONFIG_H
#define CONFIG_H

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0xFEED
#define PRODUCT_ID      0x6060
#define DEVICE_VER      0x0001
#define MANUFACTURER    R.S.F.
#define PRODUCT         twenty20
#define DESCRIPTION     Keyboard

//#define MOUSEKEY_INTERVAL 16
//#define MOUSEKEY_DELAY 0
//#define MOUSEKEY_TIME_TO_MAX 60
//#define MOUSEKEY_MAX_SPEED 7
//#define MOUSEKEY_WHEEL_DELAY 0

/* key matrix size */
#define MATRIX_ROWS 10
#define MATRIX_COLS 8

/* key matrix pins */
#define MATRIX_ROW_PINS { F0, F1, F4, F5, F6, B1, B7, D0, D1, B3 }
#define MATRIX_COL_PINS { F7, B6, B5, B4, B2, D3, D2, B0 }
#define UNUSED_PINS

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW

/* number of backlight levels */
//#define BACKLIGHT_PIN D4
//#ifdef BACKLIGHT_PIN
#define BACKLIGHT_LEVELS 0
//#endif

/* Set 0 if debouncing isn't needed */
#define DEBOUNCING_DELAY 5

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE

/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

/* key combination for command */
#define IS_COMMAND() ( \
    keyboard_report->mods == (MOD_BIT(KC_LCTL) | MOD_BIT(KC_RCTL)) \
)

/* prevent stuck modifiers */
#define PREVENT_STUCK_MODIFIERS

/* tap timing */
#define TAPPING_TERM 200

#ifdef RGB_DI_PIN
#define RGBLIGHT_ANIMATIONS
#define RGBLED_NUM 0
#define RGBLIGHT_HUE_STEP 8
#define RGBLIGHT_SAT_STEP 8
#define RGBLIGHT_VAL_STEP 8
#endif

#endif
