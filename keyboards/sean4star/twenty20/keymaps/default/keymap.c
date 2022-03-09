/*  Keymap for Space Oddity Keyboard
    Copyright (C) 2017  James Taylor

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

// cd /C/Users/forric/"Personal Files"/Programming/qmk-qmk_firmware-0.5.216-5-g13d2881/qmk-qmk_firmware-13d2881

#include "twenty20_matrix.h"


// Layer Names
enum twenty20_layers {
  // Alpha Layers
	QTY,  // Qwerty layer
	TK1,  // Tarmak Training 1
	TK2,  // Tarmak Training 2
	TK3,  // Tarmak Training 3
	TK4,  // Tarmak Training 4
	TK5,  // Colemak
	TAB,  // ALT+TAB layer
  // Tenkey/Navigation Layers
	BTK,  // base tenkey layer
	LTK,  // left tenkey layer
	RTK,  // right tenkey layer
	NPD,  // tenkey alt layer - ALT codes 
	DEL,  // extra delete key layer
  // Function/Media/Navigation Layers
	LFN,  // left function layer
	RFN,  // right function layer
};


#include "twenty20_tapdance.h"
#include "twenty20_macros.h"
#include "twenty20_leds.h"


// Planck keycodes needed for dynamic macros.
//enum planck_keycodes {
//  QWERTY = SAFE_RANGE,
//  DYNAMIC_MACRO_RANGE,
//};
//#include "dynamic_macro.h"


// Special Keys Short Names
#define ________  KC_TRNS
#define XXXXXXXX  KC_NO
#define LCTL_ESC  LCTL_T(KC_ESC)
#define LCTL_PRV  LCTL_T(KC_MPRV)
#define RCTL_ESC  RCTL_T(KC_ESC)
#define RCTL_SLS  RCTL_T(KC_PSLS)
#define RCTL_PAU  RCTL_T(KC_PAUS)
#define LALT_NXT  LALT_T(KC_MNXT)
#define RALT_PCM  RALT_T(KC_PCMM)
#define RALT_PSC  RALT_T(KC_PSCR)
#define LSPC_LTK  LT(LTK,KC_SPC)
#define RSPC_RTK  LT(RTK,KC_SPC)
#define RSPC_0    LT(RTK,KC_0)
#define RSPC_P0   LT(RTK,KC_P0)
#define DEL_LFN   LT(LFN,KC_DEL)
#define DEL_RFN   LT(RFN,KC_DEL)


// Toggle MOUSE_LAYER. Additional layers can be added for additional layouts or other special functions.
const uint16_t PROGMEM fn_actions[] = {
//  [2] = ACTION_LAYER_TOGGLE(MOUSE_LAYER),
};



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /*  Qwerty Layer (default)
     *                  {Alt+Tab}
     *              ,------------------------.                 ,------------------------.
     *              |   Q|   W|   E|   R|   T|                 |   Y|   U|   I|   O|BSPC|
     *              |------------------------|                 |------------------------|
     *              |   A|   S|   D|   F|   G|                 |   H|   J|   K|   L|   P|
     *              |------------------------|                 |------------------------|
     *        {LSFT}|   Z|   X|   C|   V|   B|                 |   N|   M|  '"|  ?!| ENT|{RSFT}
     *              |------------------------|                 |------------------------|
     *              | ESC|    |    | DEL| SPC|                 | SPC| DEL|  ,;|  .:| ESC|
     *              `------------------------'                 `------------------------'
     *              {LCTL|LGUI|LALT| LFN| LTK}                 { RTK| RFN|RALT| APP|RCTL}
     */

  [QTY] = LAYOUT (
	     KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,          KC_Y,     KC_U,     KC_I,     KC_O,  KC_BSPC, \
	     KC_A,     KC_S,     KC_D,     KC_F,     KC_G,          KC_H,     KC_J,     KC_K,     KC_L,     KC_P, \
       LSFT_Z,     KC_X,     KC_C,     KC_V,     KC_B,          KC_N,     KC_M,  KC_QUOT, Q_EX_MRK, RSFT_ENT, \
     LCTL_ESC, LGUI_HLD, LALT_TAB,  DEL_LFN, LSPC_LTK,      RSPC_RTK,  DEL_RFN, RALT_COM,  APP_DOT, RCTL_ESC) ,

	/* Colemak Training Levels
     *                  {Alt+Tab}
     *              ,------------------------.                 ,------------------------.
     *              |   Q|   W|   F|   P|   G|                 |   J|   L|   U|   Y|BSPC|
     *              |------------------------|                 |------------------------|
     *              |   A|   R|   S|   T|   D|                 |   H|   N|   E|   I|   O|
     *              |------------------------|                 |------------------------|
     *        {LSFT}|   Z|   X|   C|   V|   B|                 |   K|   M|  '"|  ?!| ENT|{RSFT}
     *              |------------------------|                 |------------------------|
     *              | ESC|    |    | DEL| SPC|                 | SPC| DEL|  ,;|  .:| ESC|
     *              `------------------------'                 `------------------------'
     *              {LCTL|LGUI|LALT| LFN| LTK}                 { RTK| RFN|RALT| APP|RCTL}
     */

  [TK1] = LAYOUT (  // Tarmak (E)		J -> E -> K -> N
	     KC_Q,     KC_W,     KC_J,     KC_R,     KC_T,          KC_Y,     KC_U,     KC_I,     KC_O,  KC_BSPC, \
	     KC_A,     KC_S,     KC_D,     KC_F,     KC_G,          KC_H,     KC_N,     KC_E,     KC_L,     KC_P, \
       LSFT_Z,     KC_X,     KC_C,     KC_V,     KC_B,          KC_K,     KC_M,  KC_QUOT, Q_EX_MRK, RSFT_ENT, \
     LCTL_ESC, LGUI_HLD, LALT_TAB,  DEL_LFN, LSPC_LTK,      RSPC_RTK,  DEL_RFN, RALT_COM,  APP_DOT, RCTL_ESC) ,

  [TK2] = LAYOUT (  // Tarmak (ET)		J -> G -> T -> F
	     KC_Q,     KC_W,     KC_F,     KC_R,     KC_G,          KC_Y,     KC_U,     KC_I,     KC_O,  KC_BSPC, \
	     KC_A,     KC_S,     KC_D,     KC_T,     KC_J,          KC_H,     KC_N,     KC_E,     KC_L,     KC_P, \
       LSFT_Z,     KC_X,     KC_C,     KC_V,     KC_B,          KC_K,     KC_M,  KC_QUOT, Q_EX_MRK, RSFT_ENT, \
     LCTL_ESC, LGUI_HLD, LALT_TAB,  DEL_LFN, LSPC_LTK,      RSPC_RTK,  DEL_RFN, RALT_COM,  APP_DOT, RCTL_ESC) ,

  [TK3] = LAYOUT (  // Tarmak (ETR)		J -> R -> S -> D
	     KC_Q,     KC_W,     KC_F,     KC_J,     KC_G,          KC_Y,     KC_U,     KC_I,     KC_O,  KC_BSPC, \
	     KC_A,     KC_R,     KC_S,     KC_T,     KC_D,          KC_H,     KC_N,     KC_E,     KC_L,     KC_P, \
       LSFT_Z,     KC_X,     KC_C,     KC_V,     KC_B,          KC_K,     KC_M,  KC_QUOT, Q_EX_MRK, RSFT_ENT, \
     LCTL_ESC, LGUI_HLD, LALT_TAB,  DEL_LFN, LSPC_LTK,      RSPC_RTK,  DEL_RFN, RALT_COM,  APP_DOT, RCTL_ESC) ,

  [TK4] = LAYOUT (  // Tarmak (ETRO)	J -> Y -> O -> P
	     KC_Q,     KC_W,     KC_F,     KC_P,     KC_G,          KC_J,     KC_U,     KC_I,     KC_Y,  KC_BSPC, \
	     KC_A,     KC_R,     KC_S,     KC_T,     KC_D,          KC_H,     KC_N,     KC_E,     KC_L,     KC_O, \
       LSFT_Z,     KC_X,     KC_C,     KC_V,     KC_B,          KC_K,     KC_M,  KC_QUOT, Q_EX_MRK, RSFT_ENT, \
     LCTL_ESC, LGUI_HLD, LALT_TAB,  DEL_LFN, LSPC_LTK,      RSPC_RTK,  DEL_RFN, RALT_COM,  APP_DOT, RCTL_ESC) ,

  [TK5] = LAYOUT (  // Tarmak (ETROI)	L -> U -> I			*** Full Colemak ***
	     KC_Q,     KC_W,     KC_F,     KC_P,     KC_G,          KC_J,     KC_L,     KC_U,     KC_Y,  KC_BSPC, \
	     KC_A,     KC_R,     KC_S,     KC_T,     KC_D,          KC_H,     KC_N,     KC_E,     KC_I,     KC_O, \
       LSFT_Z,     KC_X,     KC_C,     KC_V,     KC_B,          KC_K,     KC_M,  KC_QUOT, Q_EX_MRK, RSFT_ENT, \
     LCTL_ESC, LGUI_HLD, LALT_TAB,  DEL_LFN, LSPC_LTK,      RSPC_RTK,  DEL_RFN, RALT_COM,  APP_DOT, RCTL_ESC) ,


    /*  ALT+TAB Layer  */
  [TAB] = LAYOUT (
	 ________,   KC_TAB, ________, ________, ________,      ________, ________, ________, ________, ________, \
	 ________, ________, ________, ________, ________,      ________, ________, ________, ________, ________, \
     ________, ________, ________, ________, ________,      ________, ________, ________, ________, ________, \
     ________, ________, ________, ________, ________,      ________, ________, ________, ________, ________) ,


    /*  Tenkey Layers
     *              ,------------------------.                 ,------------------------.
     *              |BSPC| TAB|Home|PgUp| End|                 |  =+|  7&|  8*|  9(|   *|
     *              |------------------------|                 |------------------------|
     *              |  `~|Left|  Up|Rght|  [{|                 |  (<|  4$|  5%|  6^|  -_|
     *              |------------------------|                 |------------------------|
     *        {LSFT}| ENT|  \||Down|PgDn|  ]}|                 |  )>|  1!|  2@|  3#|   +|{RSFT}
     *              |------------------------|                 |------------------------|
     *              | ESC|NLCK|CAPS| INS| SPC|                 |   0| 000|  ,;|  .:|   /|
     *              `------------------------'                 `------------------------'
     *              {LCTL|LGUI|LALT|    |    }                 {    |Lay9|RALT| APP|RCTL}
     */

  [BTK] = LAYOUT (  // Hands-free Tenkey Layer (activate by tapping the LGUI key from an alpha layer)
      KC_BSPC,   KC_TAB,  KC_HOME,  KC_PGUP,   KC_END,      NLCK_EQL,    KC_P7,    KC_P8,    KC_P9,  KC_PAST, \
       KC_GRV,  KC_LEFT,    KC_UP,  KC_RGHT,  KC_LBRC,      LPRN_LAB,    KC_P4,    KC_P5,    KC_P6,  KC_PMNS, \
     LSFT_ENT,  KC_BSLS,  KC_DOWN,  KC_PGDN,  KC_RBRC,      RPRN_RAB,    KC_P1,    KC_P2,    KC_P3, RSFT_PLS, \
     LCTL_ESC, LGUI_HLD, LALT_CAP,   KC_INS, ________,       RSPC_P0, TRI_ZERO, RALT_PCM, APP_PDOT, RCTL_SLS) ,

  [LTK] = LAYOUT (
      KC_BSPC,   KC_TAB,  KC_HOME,  KC_PGUP,   KC_END,        KC_EQL,     KC_7,     KC_8,     KC_9,  KC_PAST, \
       KC_GRV,  KC_LEFT,    KC_UP,  KC_RGHT,  KC_LBRC,      LPRN_LAB,     KC_4,     KC_5,     KC_6,  KC_MINS, \
     LSFT_ENT,  KC_BSLS,  KC_DOWN,  KC_PGDN,  KC_RBRC,      RPRN_RAB,     KC_1,     KC_2,     KC_3, RSFT_PLS, \
     LCTL_ESC, LGUI_BTK, LALT_CAP,   KC_INS, ________,        RSPC_0, TRI_ZERO, RALT_COM,  APP_DOT, RCTL_SLS) ,

  [RTK] = LAYOUT (
      KC_BSPC,   KC_TAB,  KC_HOME,  KC_PGUP,   KC_END,        KC_EQL,     KC_7,     KC_8,     KC_9,  KC_PAST, \
       KC_GRV,  KC_LEFT,    KC_UP,  KC_RGHT,  KC_LBRC,      LPRN_LAB,     KC_4,     KC_5,     KC_6,  KC_MINS, \
     LSFT_ENT,  KC_BSLS,  KC_DOWN,  KC_PGDN,  KC_RBRC,      RPRN_RAB,     KC_1,     KC_2,     KC_3, RSFT_PLS, \
     LCTL_ESC, LGUI_BTK, LALT_CAP,   KC_INS, ________,      ________, ZERO_DEL, RALT_COM,  APP_DOT, RCTL_SLS) ,


    /*  Tenkey Alt Layer - for numpad keys (Alt codes)  */
  [NPD] = LAYOUT (
	 ________, ________, ________, ________, ________,      NLCK_EQL,    KC_P7,    KC_P8,    KC_P9, ________, \
	 ________, ________, ________, ________, ________,      ________,    KC_P4,    KC_P5,    KC_P6,  KC_PMNS, \
     ________, ________, ________, ________, ________,      ________,    KC_P1,    KC_P2,    KC_P3, ________, \
     ________, ________, ________, ________, ________,         KC_P0, ________, RALT_PCM, APP_PDOT, ________) ,


    /*  Extra Delete Key Layer  */
  [DEL] = LAYOUT (
	 ________, ________, ________, ________, ________,      ________, ________, ________, ________,   KC_DEL, \
	 ________, ________, ________, ________, ________,      ________, ________, ________, ________, ________, \
     ________, ________, ________, ________, ________,      ________, ________, ________, ________, ________, \
     ________, ________, ________, ________, ________,      ________, ________, ________, ________, ________) ,


    /* Function Layers
     *              ,------------------------.                 ,------------------------.
     *              | VUp|  F1|  F2|  F3|  F4|                 | End|PgUp|Home| TAB| DEL|
     *              |------------------------|                 |------------------------|
     *              | VDn|  F5|  F6|  F7|  F8|                 |    |Left|  Up|Rght|    |
     *              |------------------------|                 |------------------------|
     *        {LSFT}|MUTE|  F9| F10| F11| F12|                 |    |PgDn|Down|    | ENT|{RSFT}
     *              |------------------------|                 |------------------------|
     *              |PREV|PLAY|NEXT|XXXX| SPC|                 | SPC|    |PSCR|SLCK|PAUS|
     *              `------------------------'                 `------------------------'
     *              {LCTL|LGUI|LALT|    |    }                 {    |    |RALT|RGUI|RCTL}
     */

  [LFN] = LAYOUT (
	  KC_VOLU,    KC_F1,    KC_F2,    KC_F3,    KC_F4,       KC_HOME,  KC_PGUP,   KC_END,   KC_TAB,   KC_DEL, \
	  KC_VOLD,    KC_F5,    KC_F6,    KC_F7,    KC_F8,      XXXXXXXX,  KC_LEFT,    KC_UP,  KC_RGHT, XXXXXXXX, \
     LSFT_MUT,    KC_F9,   KC_F10,   KC_F11,   KC_F12,      XXXXXXXX,  KC_PGDN,  KC_DOWN, XXXXXXXX, RSFT_ENT, \
     LCTL_PRV, LGUI_PLY, LALT_NXT, ________,   KC_SPC,        KC_SPC, ________, RALT_PSC, APP_SLCK, RCTL_PAU) ,

  [RFN] = LAYOUT (
	  KC_VOLU,    KC_F1,    KC_F2,    KC_F3,    KC_F4,       KC_HOME,  KC_PGUP,   KC_END,   KC_TAB,   KC_DEL, \
	  KC_VOLD,    KC_F5,    KC_F6,    KC_F7,    KC_F8,      XXXXXXXX,  KC_LEFT,    KC_UP,  KC_RGHT, XXXXXXXX, \
     LSFT_MUT,    KC_F9,   KC_F10,   KC_F11,   KC_F12,      XXXXXXXX,  KC_PGDN,  KC_DOWN, XXXXXXXX, RSFT_ENT, \
     LCTL_PRV, LGUI_PLY, LALT_NXT, ________,   KC_SPC,        KC_SPC, ________, RALT_PSC, APP_SLCK, RCTL_PAU) ,
};


void matrix_init_user(void) {
}

void matrix_scan_user(void) {
}


