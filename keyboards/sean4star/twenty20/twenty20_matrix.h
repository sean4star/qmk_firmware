#ifndef KB_H
#define KB_H

#include "quantum.h"

/*  The keyboard is actually a pair of 2x 5x4 keyboards, one for each hand.
 *  The Teensy will be mounted in the left keypad with a connecting cable to the right.
 *  Instead of using the same row pins and wiring the keypads in parallel, the matrix is completely split.
 *  Also, due to the straight columns/staggered rows setup of the keypads, it was easier to wire the diodes
 *  vertically, so the entire matrix is sideways...10 rows and 8 columns (5x4 per keypad)
 *
 *       PC
 *       | _
 *       |/ \
 *       1   2
 */

#define LAYOUT( \
	K003, K103, K203, K303, K403,   K507, K607, K707, K807, K907, \
	K002, K102, K202, K302, K402,   K506, K606, K706, K806, K906, \
	K001, K101, K201, K301, K401,   K505, K605, K705, K805, K905, \
	K000, K100, K200, K300, K400,   K504, K604, K704, K804, K904  \
) { \
	{  K000,   K001,   K002,   K003,  KC_NO,  KC_NO,  KC_NO,  KC_NO }, \
	{  K100,   K101,   K102,   K103,  KC_NO,  KC_NO,  KC_NO,  KC_NO }, \
	{  K200,   K201,   K202,   K203,  KC_NO,  KC_NO,  KC_NO,  KC_NO }, \
	{  K300,   K301,   K302,   K303,  KC_NO,  KC_NO,  KC_NO,  KC_NO }, \
	{  K400,   K401,   K402,   K403,  KC_NO,  KC_NO,  KC_NO,  KC_NO }, \
	{ KC_NO,  KC_NO,  KC_NO,  KC_NO,   K504,   K505,   K506,   K507 }, \
	{ KC_NO,  KC_NO,  KC_NO,  KC_NO,   K604,   K605,   K606,   K607 }, \
	{ KC_NO,  KC_NO,  KC_NO,  KC_NO,   K704,   K705,   K706,   K707 }, \
	{ KC_NO,  KC_NO,  KC_NO,  KC_NO,   K804,   K805,   K806,   K807 }, \
	{ KC_NO,  KC_NO,  KC_NO,  KC_NO,   K904,   K905,   K906,   K907 }  \
}

#endif