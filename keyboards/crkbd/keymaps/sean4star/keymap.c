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

#include QMK_KEYBOARD_H
#include <stdio.h>


// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum layers {
  _QWERTY,
  _TARMAK1,
  _TARMAK2,
  _TARMAK3,
  _TARMAK4,
  _COLEMAK,
  _TAB,
  _NAVNUM,
  _R_NUM,
  _NUM_ON,
  _TENKEY,
  _FKEY,
  _LAYOUT,
};


#include "oled.h"
#include "custom_keycodes.h"


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {


/*					Character Layers
			┌─────────┬─────────┬─────────┬─────────┬─────────┬─────────┐            ┌─────────┬─────────┬─────────┬─────────┬─────────┬─────────┐
			│  Escape │       Q │       W │       E │       R │       T │            │       Y │       U │       I │       O │       P │ Backspc │
			├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤     	     ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
			│   Shift │       A │       S │       D │       F │       G │            │       H │       J │       K │       L │     ' " │   Enter │  {Shift}
			├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤     	     ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
 {Caps Lk}  │ Control │       Z │       X │       C │       V │       B │            │       N │       M │     , ; │     . : │     ? ! │ Control │
			└─────────┴─────────┴─────────┴───┬─────┴───┬─────┴───┬─────┴───┐    ┌───┴─────┬───┴─────┬───┴─────┬───┴─────────┴─────────┴─────────┘
											  │ 	Alt │         │   Space │    │   Space │         │     Alt │
											  └─────────┴─────────┴─────────┘    └─────────┴─────────┴─────────┘
											      {TAB}    {FKEY}   {NAVNUM}  	   {NAVNUM}   {FKEY}
*/
  
  [_QWERTY] = LAYOUT_split_3x6_3(
		   KC_ESC ,    KC_Q ,    KC_W ,    KC_E ,    KC_R ,    KC_T ,                 KC_Y ,    KC_U ,    KC_I ,    KC_O ,    KC_P , KC_BSPC ,
		  KC_LSFT ,    KC_A ,    KC_S ,    KC_D ,    KC_F ,    KC_G ,                 KC_H ,    KC_J ,    KC_K ,    KC_L , KC_QUOT , RSFT_ENT,
		 LCTL_CAPS,    KC_Z ,    KC_X ,    KC_C ,    KC_V ,    KC_B ,                 KC_N ,    KC_M ,COMM_SCLN, DOT_COLN,QUES_EXLM, KC_RCTL ,
										    LALT_TAB,  L_FKEY ,L_NUM_SPC,     R_NUM_SPC,  R_FKEY , KC_RALT 
  ),

/*					Colemak Training
			┌─────────┬─────────┬─────────┬─────────┬─────────┬─────────┐            ┌─────────┬─────────┬─────────┬─────────┬─────────┬─────────┐
			│  Escape │       Q │       W │   E→J→F │   R→J→P │     T→G │            │     Y→J │     U→L │     I→U │     O→Y │   P→' " │ Backspc │
			├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤     	     ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
			│   Shift │       A │     S→R │     D→S │     F→T │   G→J→D │            │       H │     J→N │     K→E │     L→I │   ' "→O │   Enter │  {Shift}
			├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤     	     ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
 {Caps Lk}  │ Control │       Z │       X │       C │       V │       B │            │     N→K │       M │     , ; │     . : │     ? ! │ Control │
			└─────────┴─────────┴─────────┴───┬─────┴───┬─────┴───┬─────┴───┐    ┌───┴─────┬───┴─────┬───┴─────┬───┴─────────┴─────────┴─────────┘
											  │ 	Alt │         │   Space │    │   Space │         │     Alt │
											  └─────────┴─────────┴─────────┘    └─────────┴─────────┴─────────┘
											      {TAB}    {FKEY}   {NAVNUM}  	   {NAVNUM}   {FKEY}
*/

  [_TARMAK1] = LAYOUT_split_3x6_3(  // Tarmak (E)			J -> E -> K -> N
		   KC_ESC ,    KC_Q ,    KC_W ,    KC_J ,    KC_R ,    KC_T ,                 KC_Y ,    KC_U ,    KC_I ,    KC_O ,    KC_P , KC_BSPC ,
		  KC_LSFT ,    KC_A ,    KC_S ,    KC_D ,    KC_F ,    KC_G ,                 KC_H ,    KC_N ,    KC_E ,    KC_L , KC_QUOT , RSFT_ENT,
		 LCTL_CAPS,    KC_Z ,    KC_X ,    KC_C ,    KC_V ,    KC_B ,                 KC_K ,    KC_M ,COMM_SCLN, DOT_COLN,QUES_EXLM, KC_RCTL ,
										    LALT_TAB,  L_FKEY ,L_NUM_SPC,     R_NUM_SPC,  R_FKEY , KC_RALT 
  ),

  [_TARMAK2] = LAYOUT_split_3x6_3(  // Tarmak (ET)			J -> G -> T -> F
		   KC_ESC ,    KC_Q ,    KC_W ,    KC_F ,    KC_R ,    KC_G ,                 KC_Y ,    KC_U ,    KC_I ,    KC_O ,    KC_P , KC_BSPC ,
		  KC_LSFT ,    KC_A ,    KC_S ,    KC_D ,    KC_T ,    KC_J ,                 KC_H ,    KC_N ,    KC_E ,    KC_L , KC_QUOT , RSFT_ENT,
		 LCTL_CAPS,    KC_Z ,    KC_X ,    KC_C ,    KC_V ,    KC_B ,                 KC_K ,    KC_M ,COMM_SCLN, DOT_COLN,QUES_EXLM, KC_RCTL ,
										    LALT_TAB,  L_FKEY ,L_NUM_SPC,     R_NUM_SPC,  R_FKEY , KC_RALT 
  ),

  [_TARMAK3] = LAYOUT_split_3x6_3(  // Tarmak (ETR)			J -> R -> S -> D
		   KC_ESC ,    KC_Q ,    KC_W ,    KC_J ,    KC_J ,    KC_T ,                 KC_Y ,    KC_U ,    KC_I ,    KC_O ,    KC_P , KC_BSPC ,
		  KC_LSFT ,    KC_A ,    KC_R ,    KC_S ,    KC_F ,    KC_D ,                 KC_H ,    KC_N ,    KC_E ,    KC_L , KC_QUOT , RSFT_ENT,
		 LCTL_CAPS,    KC_Z ,    KC_X ,    KC_C ,    KC_V ,    KC_B ,                 KC_K ,    KC_M ,COMM_SCLN, DOT_COLN,QUES_EXLM, KC_RCTL ,
										    LALT_TAB,  L_FKEY ,L_NUM_SPC,     R_NUM_SPC,  R_FKEY , KC_RALT 
  ),

  [_TARMAK4] = LAYOUT_split_3x6_3(  // Tarmak (ETRO)		J -> Y -> O -> ; -> P		 (QUOT is in the ; position for this layout)
		   KC_ESC ,    KC_Q ,    KC_W ,    KC_J ,    KC_P ,    KC_T ,                 KC_J ,    KC_U ,    KC_I ,    KC_Y , KC_QUOT , KC_BSPC ,
		  KC_LSFT ,    KC_A ,    KC_R ,    KC_S ,    KC_F ,    KC_D ,                 KC_H ,    KC_N ,    KC_E ,    KC_L ,    KC_O , RSFT_ENT,
		 LCTL_CAPS,    KC_Z ,    KC_X ,    KC_C ,    KC_V ,    KC_B ,                 KC_K ,    KC_M ,COMM_SCLN, DOT_COLN,QUES_EXLM, KC_RCTL ,
										    LALT_TAB,  L_FKEY ,L_NUM_SPC,     R_NUM_SPC,  R_FKEY , KC_RALT 
  ),

  [_COLEMAK] = LAYOUT_split_3x6_3(  // Tarmak (ETROI)		L -> U -> I			*** Full Colemak ***
		   KC_ESC ,    KC_Q ,    KC_W ,    KC_J ,    KC_P ,    KC_T ,                 KC_J ,    KC_L ,    KC_U ,    KC_Y , KC_QUOT , KC_BSPC ,
		  KC_LSFT ,    KC_A ,    KC_R ,    KC_S ,    KC_F ,    KC_D ,                 KC_H ,    KC_N ,    KC_E ,    KC_I ,    KC_O , RSFT_ENT,
		 LCTL_CAPS,    KC_Z ,    KC_X ,    KC_C ,    KC_V ,    KC_B ,                 KC_K ,    KC_M ,COMM_SCLN, DOT_COLN,QUES_EXLM, KC_RCTL ,
										    LALT_TAB,  L_FKEY ,L_NUM_SPC,     R_NUM_SPC,  R_FKEY , KC_RALT 
  ),



  [_TAB] = LAYOUT_split_3x6_3(
	// to allow easy access to Alt + Tab (Alt + Q can still be accessed using right alt)
		  _______ , _______ ,  KC_TAB , _______ , _______ , _______ ,              _______ , _______ , _______ , _______ , _______ , _______ ,
		  _______ , _______ , _______ , _______ , _______ , _______ ,              _______ , _______ , _______ , _______ , _______ , _______ ,
		  _______ , _______ , _______ , _______ , _______ , _______ ,              _______ , _______ , _______ , _______ , _______ , _______ ,
										    _______ , _______ , _______ ,      _______ , _______ , _______
  ),


/*					Navigation and Number Layers
																					  {TENKEY}
			┌─────────┬─────────┬─────────┬─────────┬─────────┬─────────┐            ┌─────────┬─────────┬─────────┬─────────┬─────────┬─────────┐
			│  Escape │     ` ~ │     Tab │    Home │   Pg Up │     End │            │  = NmLk │     7 & │     8 * │     9 ( │       - │ Backspc │
			├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤     	     ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
            │   Shift │     / _ │    Left │      Up │   Right │     [ { │            │     ( < │     4 $ │     5 % │     6 ^ │       + │   Enter │  {Shift}
			├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤            ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
 {Caps Lk}  │ Control │     \ | │         │    Down │ Pg Down │     ] } │            │     ) > │     1 ! │     2 @ │     3 # │       * │       / │	{Control}
			└─────────┴─────────┴─────────┴───┬─────┴───┬─────┴───┬─────┴───┐    ┌───┴─────┬───┴─────┬───┴─────┬───┴─────────┴─────────┴─────────┘
											  │     Alt │         │   Space │    │     0 ) │       . │       , │
											  └─────────┴─────────┴─────────┘    └─────────┴─────────┴─────────┘
															{FKY}   {NAVNUM}  	   {NAVNUM}    {FKY}

Q:	should COMMA and DOT switch places?
Q:  layout of left keyboard - one blank key?
TODO: no FKEY
TODO: DEL layer

*/

  [_NAVNUM] = LAYOUT_split_3x6_3(
		  _______ ,  KC_GRV ,  KC_TAB , KC_HOME , KC_PGUP ,  KC_END ,              EQL_NUM ,    KC_7 ,    KC_8 ,    KC_9 , KC_PMNS , _______ ,
		  _______ ,SLSH_UNDS, KC_LEFT ,   KC_UP , KC_RGHT , KC_LBRC ,             L_PRN_ABK,    KC_4 ,    KC_5 ,    KC_6 , KC_PPLS ,RSFT_PENT,
		  _______ , KC_BSLS , XXXXXXX , KC_DOWN , KC_PGDN , KC_RBRC ,             R_PRN_ABK,    KC_1 ,    KC_2 ,    KC_3 , KC_PAST ,RCTL_PSLS,
										   LALT_TNKY, _______ , _______ ,      R_NUM_0 ,COMM_COMM, RALT_DOT
  ),

  [_R_NUM] = LAYOUT_split_3x6_3(
	// to allow access to KC_0 with right-one-handed operation of the number keys
		  _______ , _______ , _______ , _______ , _______ , _______ ,              _______ , _______ , _______ , _______ , _______ , _______ ,
		  _______ , _______ , _______ , _______ , _______ , _______ ,              _______ , _______ , _______ , _______ , _______ , _______ ,
		  _______ , _______ , _______ , _______ , _______ , _______ ,              _______ , _______ , _______ , _______ , _______ , _______ ,
										    _______ , _______ , _______ ,      _______ ,    KC_0 , _______
  ),

  [_NUM_ON] = LAYOUT_split_3x6_3(
		  _______ , _______ , _______ , _______ , _______ , _______ ,              _______ , _______ , _______ , _______ , _______ , _______ ,
		  _______ , _______ , _______ , _______ , _______ , _______ ,              _______ , _______ , _______ , _______ , _______ , _______ ,
		  _______ , _______ , _______ , _______ , _______ , _______ ,              _______ , _______ , _______ , _______ , _______ , _______ ,
										    _______ , _______ ,  KC_SPC ,         KC_0 , _______ , _______
  ),

  [_TENKEY] = LAYOUT_split_3x6_3(
	// to allow access to number pad keys
		  _______ , _______ , _______ , _______ , _______ , _______ ,              _______ ,   KC_P7 ,   KC_P8 ,   KC_P9 , _______ , _______ ,
		  _______ , _______ , _______ , _______ , _______ , _______ ,              _______ ,   KC_P4 ,   KC_P5 ,   KC_P6 , _______ , _______ ,
		  _______ , _______ , _______ , _______ , _______ , _______ ,              _______ ,   KC_P1 ,   KC_P2 ,   KC_P3 , _______ , _______ ,
										    _______ , _______ , _______ ,        KC_P0 , _______ ,RALT_PDOT
  ),


  [_FKEY] = LAYOUT_split_3x6_3(
		  _______ , KC_VOLU ,   KC_F1 ,   KC_F2 ,   KC_F3 ,   KC_F4 ,               KC_END , KC_PGUP , KC_HOME ,  KC_TAB , KC_PSCR ,  KC_DEL ,
		  _______ , KC_VOLD ,   KC_F5 ,   KC_F6 ,   KC_F7 ,   KC_F8 ,              XXXXXXX , KC_LEFT ,   KC_UP , KC_RGHT , KC_SCRL , _______ ,
		  _______ , KC_MUTE ,   KC_F9 ,  KC_F10 ,  KC_F11 ,  KC_F12 ,              XXXXXXX , KC_PGDN , KC_DOWN , XXXXXXX , KC_PAUS , _______ ,
										    _______ , _______ , _______ ,      _______ , _______ , _______ 
  ),


  [_LAYOUT] = LAYOUT_split_3x6_3(
		  XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,  QWERTY ,              RGB_TOG , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,
		  _______ , TARMAK1 , TARMAK2 , TARMAK3 , TARMAK4 , COLEMAK ,              RGB_MOD , RGB_M_P , RGB_M_B , RGB_M_R , RGB_M_SW, _______ ,
		  _______ , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,              XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , _______ ,
										    _______ , _______ , XXXXXXX ,      XXXXXXX , _______ , _______ 
  ),

};



