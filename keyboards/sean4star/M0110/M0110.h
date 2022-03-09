/* Copyright 2017 Ryan Mitchell (@newtmitch)
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

#pragma once

#include "quantum.h"

#define ___ KC_NO


/*
 *			Left																Right
 *       ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┐		┌───┬───┬───┬───┐
 *       │00 │01 │02 │03 │04 │05 │06 │07 │08 │09 │0A │0B │0C │  0D   │		│00 │01 │02 │03 │
 *       ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┤		├───┼───┼───┼───┤
 *       │10   │11 │12 │13 │14 │15 │16 │17 │18 │19 │1A │1B │1C │1D   │		│10 │11 │12 │13 │
 *       ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┤		├───┼───┼───┼───┤
 *       │20    │21 │22 │23 │24 │25 │26 │27 │28 │29 │2A │2B │   2D   │		│20 │21 │22 │23 │
 *       ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────────┤		├───┼───┼───┼───┤
 *       │30      │31 │32 │33 │34 │35 │36 │37 │38 │39 │3A │     3D   │		│30 │31 │32 │   │
 *       └────┬───┴┬──┴─┬─┴───┴───┴───┴───┴───┴───┴───┼───┴┬────┬────┘		├───┴───┼───┤   │
 *            │40  │41  │              45             │4A  │4D  │			│40     │42 │43 │
 *            └────┴────┴─────────────────────────────┴────┴────┘			└───────┴───┴───┘
 */


#define LAYOUT_all( \
    L00, L01, L02, L03, L04, L05, L06, L07, L08, L09, L0A, L0B, L0C,     L0D,			R00, R01, R02, R03, \
    L10,   L11, L12, L13, L14, L15, L16, L17, L18, L19, L1A, L1B, L1C,   L1D,			R10, R11, R12, R13, \
    L20,    L21, L22, L23, L24, L25, L26, L27, L28, L29, L2A, L2B,       L2D,			R20, R21, R22, R23, \
    L30,      L31, L32, L33, L34, L35, L36, L37, L38, L39, L3A,          L3D,			R30, R31, R32,      \
          L40,   L41,                L45,                  L4A,     L4D,     			R40,      R42, R43  \
) \
{ \
    { L00, L01, L02, L03, L04, L05, L06, L07, L08, L09, L0A, L0B, L0C, L0D }, \
    { L10, L11, L12, L13, L14, L15, L16, L17, L18, L19, L1A, L1B, L1C, L1D }, \
    { L20, L21, L22, L23, L24, L25, L26, L27, L28, L29, L2A, L2B, ___, L2D }, \
    { L30, L31, L32, L33, L34, L35, L36, L37, L38, L39, L3A, ___, ___, L3D }, \
    { L40, L41, ___, ___, ___, L45, ___, ___, ___, ___, L4A, ___, ___, L4D }, \
																			  \
    { R00, R01, R02, R03, ___, ___, ___, ___, ___, ___, ___, ___, ___, ___ }, \
    { R10, R11, R12, R13, ___, ___, ___, ___, ___, ___, ___, ___, ___, ___ }, \
    { R20, R21, R22, R23, ___, ___, ___, ___, ___, ___, ___, ___, ___, ___ }, \
    { R30, R31, R32, ___, ___, ___, ___, ___, ___, ___, ___, ___, ___, ___ }, \
    { R40, ___, R42, R43, ___, ___, ___, ___, ___, ___, ___, ___, ___, ___ }  \
}
