/* Copyright 2017 Ryan Mitchell (@newtmitch)
 *           2021 James Young for QMK (@noroadsleft)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H
#include <stdio.h>


enum layers {
  _BASE,
  _RAISE,
};


//#include "custom_keycodes.h"


// Custom shortened key names
#define 	RCTL_ENT		RCTL_T(KC_ENT)				// tap = enter				hold = right control
#define 	RSFT_PENT		RSFT_T(KC_PENT)				// tap = numberpad enter	hold = right shift
#define		RAISE_SPC		LT(_RAISE, KC_SPC)			// tap = space				hold = momentary RAISE layer
#define		RAISE_P0		LT(_RAISE, KC_P0)			// tap = numberpad 0		hold = momentary RAISE layer
#define		TOG_NK			MAGIC_TOGGLE_NKRO			// toggles full NKRO


// Custom keycodes - behavious defined below in process_record_user
enum custom_keycodes {
	COM_COM = SAFE_RANGE,								// tap = , (KC_COMM)			shift + tap = , (unshifted KC_COMM)
	L_PRN,												// tap = ( (shifted KC_9)		shift + tap = < (shifted KC_COMM)
	R_PRN,												// tap = ) (shifted KC_0)		shift + tap = > (shifted KC_DOT)
};


// State variables
uint8_t mod_state;


bool process_record_user(uint16_t keycode, keyrecord_t *record) {

mod_state = get_mods();

    switch (keycode) {
        case COM_COM: {
		// tap = , (KC_COMM)			shift + tap = , (unshifted KC_COMM)
			static bool shifted_COM_COM = false;
			if (record->event.pressed) {
				if (mod_state & MOD_MASK_SHIFT) {
					shifted_COM_COM = true;
					del_mods(MOD_MASK_SHIFT);
					register_code(KC_COMM);
					set_mods(mod_state);
				} else {
					register_code(KC_COMM);
				}
            } else {
				if (shifted_COM_COM) {
					shifted_COM_COM = false;
					unregister_code(KC_COMM);
				} else {
					unregister_code(KC_COMM);
				}
			}
		}
		break;

        case L_PRN: {
		// tap = ( (shifted KC_9)		shift + tap = < (shifted KC_COMM)
			static bool shifted_L_PRN_ABK = false;
			if (record->event.pressed) {
				if (mod_state & MOD_MASK_SHIFT) {
					shifted_L_PRN_ABK = true;
					register_code(KC_COMM);
				} else {
					register_mods(MOD_BIT(KC_LSFT));
					register_code(KC_9);
				}
            } else {
				if (shifted_L_PRN_ABK) {
					shifted_L_PRN_ABK = false;
					unregister_code(KC_COMM);
				} else {
					unregister_code(KC_9);
					unregister_mods(MOD_BIT(KC_LSFT));
				}
			}
		}
        return false;
        break;

        case R_PRN: {
		// tap = ) (shifted KC_0)		shift + tap = > (shifted KC_DOT)
			static bool shifted_R_PRN_ABK = false;
			if (record->event.pressed) {
				if (mod_state & MOD_MASK_SHIFT) {
					shifted_R_PRN_ABK = true;
					register_code(KC_DOT);
				} else {
					register_mods(MOD_BIT(KC_LSFT));
					register_code(KC_0);
				}
            } else {
				if (shifted_R_PRN_ABK) {
					shifted_R_PRN_ABK = false;
					unregister_code(KC_DOT);
				} else {
					unregister_code(KC_0);
					unregister_mods(MOD_BIT(KC_LSFT));
				}
			}
		}
        return false;
        break;


    }
    return true;
};



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_BASE] = LAYOUT_all(
//  ┌────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬─────────────────┐		┌────────┬────────┬────────┬────────┐
      KC_ESC ,   KC_1 ,   KC_2 ,   KC_3 ,   KC_4 ,   KC_5 ,   KC_6 ,   KC_7 ,   KC_8 ,   KC_9 ,   KC_0 , KC_MINS, KC_EQL ,         KC_BSPC ,		   KC_NO , KC_PMNS, KC_PPLS, KC_PAST,
//  ├────────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬─────────────┤		├────────┼────────┼────────┼────────┤
      KC_TAB     ,   KC_Q ,   KC_W ,   KC_E ,   KC_R ,   KC_T ,   KC_Y ,   KC_U ,   KC_I ,   KC_O ,   KC_P , KC_LBRC, KC_RBRC,     KC_BSLS ,		   KC_P7 ,  KC_P8 ,  KC_P9 , KC_PSLS,
//  ├────────────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─────────────┤		├────────┼────────┼────────┼────────┤
      KC_LCTL      ,   KC_A ,   KC_S ,   KC_D ,   KC_F ,   KC_G ,   KC_H ,   KC_J ,   KC_K ,   KC_L , KC_SCLN, KC_QUOT,           RCTL_ENT ,		   KC_P4 ,  KC_P5 ,  KC_P6 , COM_COM,
//  ├──────────────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴────────────────────┤		├────────┼────────┼────────┼────────┤
      KC_LSFT          ,   KC_Z ,   KC_X ,   KC_C ,   KC_V ,   KC_B ,   KC_N ,   KC_M , KC_COMM, KC_DOT , KC_SLSH,                 KC_RSFT ,		   KC_P1 ,  KC_P2 ,  KC_P3 ,
//  └─────────┬────────┴┬───────┴──┬─────┴────────┴────────┴────────┴────────┴────────┴────────┴────────┴───┬────┴─────┬─────────┬─────────┘		├────────┴────────┼────────┤        │
                KC_LALT ,  KC_LGUI ,                             RAISE_SPC                                  ,  KC_RGUI , KC_RALT ,					         RAISE_P0 , KC_PDOT,RSFT_PENT
//            └─────────┴──────────┴────────────────────────────────────────────────────────────────────────┴──────────┴─────────┘					└─────────────────┴────────┴────────┘
    ),


    [_RAISE] = LAYOUT_all(
//  ┌────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬─────────────────┐		┌────────┬────────┬────────┬────────┐
      KC_GRV ,  KC_F1 ,  KC_F2 ,  KC_F3 ,  KC_F4 ,  KC_F5 ,  KC_F6 ,  KC_F7 ,  KC_F8 ,  KC_F9 , KC_F10 , KC_F11 , KC_F12 ,          KC_DEL ,		   KC_NO , KC_PMNS, KC_LEFT, KC_RGHT,
//  ├────────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬─────────────┤		├────────┼────────┼────────┼────────┤
      KC_TAB     , KC_HOME,  KC_UP , KC_END , KC_PGUP, XXXXXXX, XXXXXXX, XXXXXXX, KC_PSCR, KC_SCRL, KC_PAUS, XXXXXXX, XXXXXXX,      KC_INS ,		   KC_P7 ,  KC_P8 ,  KC_P9 ,   KC_UP,
//  ├────────────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─────────────┤		├────────┼────────┼────────┼────────┤
      _______      , KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,            _______ ,		   KC_P4 ,  KC_P5 ,  KC_P6 , KC_DOWN,
//  ├──────────────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴────────────────────┤		├────────┼────────┼────────┼────────┤
      _______          , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, TOG_NK , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                 _______ ,		   KC_P1 ,  KC_P2 ,  KC_P3 ,
//  └─────────┬────────┴┬───────┴──┬─────┴────────┴────────┴────────┴────────┴────────┴────────┴────────┴───┬────┴─────┬─────────┬─────────┘		├────────┴────────┼────────┤        │
                _______ ,  _______ ,                               _______                                  ,  _______ , _______ ,					          _______ ,  KC_P0 ,RSFT_PENT
//            └─────────┴──────────┴────────────────────────────────────────────────────────────────────────┴──────────┴─────────┘					└─────────────────┴────────┴────────┘
    ),


};
