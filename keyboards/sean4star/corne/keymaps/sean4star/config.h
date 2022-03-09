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


/* Select hand configuration */
// #define MASTER_LEFT
#define MASTER_RIGHT
// #define EE_HANDS


/*
#ifdef RGB_MATRIX_ENABLE
#    define RGBLED_NUM       54 // Number of LEDs
#    define DRIVER_LED_TOTAL RGBLED_NUM
#    define RGB_MATRIX_SPLIT \
        { 27, 27 }
#    define SPLIT_TRANSPORT_MIRROR
#endif
*/


#ifdef RGB_MATRIX_ENABLE
#   define RGB_MATRIX_KEYPRESSES // reacts to keypresses
// #   define RGB_MATRIX_KEYRELEASES // reacts to keyreleases (instead of keypresses)
// #   define RGB_DISABLE_AFTER_TIMEOUT 0 // number of ticks to wait until disabling effects
#   define RGB_DISABLE_WHEN_USB_SUSPENDED // turn off effects when suspended
#   define RGB_MATRIX_FRAMEBUFFER_EFFECTS
// #   define RGB_MATRIX_LED_PROCESS_LIMIT (DRIVER_LED_TOTAL + 4) / 5 // limits the number of LEDs to process in an animation per task run (increases keyboard responsiveness)
// #   define RGB_MATRIX_LED_FLUSH_LIMIT 16 // limits in milliseconds how frequently an animation will update the LEDs. 16 (16ms) is equivalent to limiting to 60fps (increases keyboard responsiveness)
#    define RGB_MATRIX_MAXIMUM_BRIGHTNESS 120 // limits maximum brightness of LEDs to 150 out of 255. Higher may cause the controller to crash. 
//#    define RGB_MATRIX_HUE_STEP 8
//#    define RGB_MATRIX_SAT_STEP 8
//#    define RGB_MATRIX_VAL_STEP 8
//#    define RGB_MATRIX_SPD_STEP 10

#    define ENABLE_RGB_MATRIX_TYPING_HEATMAP
//#    define RGB_MATRIX_TYPING_HEATMAP_DECREASE_DELAY_MS 50

#    define ENABLE_RGB_MATRIX_MULTISPLASH

#endif



#undef TAPPING_FORCE_HOLD
#define TAPPING_TERM 200


// #define OLED_FONT_H "keyboards/crkbd/lib/glcdfont.c"

#define FORCE_NKRO

// Uncomment if you are using old style macros
// #undef NO_ACTION_MACRO
// #undef NO_ACTION_FUNCTION

// Space Saving
#undef LOCKING_SUPPORT_ENABLE
#undef LOCKING_RESYNC_ENABLE
#define NO_ACTION_ONESHOT
//#define NO_ACTION_LAYER			// if not using layers
//#define LAYER_STATE_8BIT			// if using 8 layers or less
#define LAYER_STATE_16BIT			// if using 16 layers or less


