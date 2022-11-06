/*
 Copyright (C) 2021,2022 Geno <geno@live.com>

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

#include "actionmap.h"
#include "action_code.h"
#include "actionmap_common.h"
#include "keyboard_fn.h"
#include "rgb_matrix.h"
#include "rgb_matrix_types.h"
#include "user_fn.h"

/* 
 * 定义需使用的FN按键
 */
#define AC_FN0	ACTION_LAYER_TAP(1, KC_SPC)

/* 
 * @brief 按键映射
 * 下面的按键映射与按键布局的第一组实际布局对应
 */


const action_t actionmaps[][MATRIX_ROWS][MATRIX_COLS] = { 
	[0] = ACTIONMAP_ROT(
	AC_ESC,   GRAVE,   1,    2,    3,    4,    5,    6,    7,    8,    9,    0,     MINUS,     EQL,    BSPC,   DEL,
	TAB,    Q,    W,    E,    R,    T,    Y,    U,    I,    O,    P,    LBRC,  RBRC,     BSLS,
	CAPS,   A,    S,    D,    F,    G,    H,    J,    K,    L,    SCLN, DUOT,  ENTER,
	LSFT,   Z,    X,    C,    V,    B,    N,    M,    COMM, DOT,  SLSH, RSFT,  UP,
	LCTL,  LGUI, LALT,   SPACE,    RALT,  FN0,  RCTL, LEFT, DOWN ,RIGHT,NUM),

	[1] = ACTIONMAP(
	ESC,   GRAVE,   F1,    F2,   F3,    F4,    F5,    F6,    F7,    F8,    F9,    F10,     F11,     F12,    BSPC,   INS,
	TAB,    Q,    W,    E,    R,    T,    Y,    U,    I,    O,    P,    LBRC,  RBRC,     BSLS,
	CAPS,   A,    S,    D,    F,    G,    H,    J,    K,    L,    SCLN, DUOT,  ENTER,
	LSFT,   Z,    X,    C,    V,    B,    N,    M,    COMM, DOT,  SLSH, RSFT,  UP,
	LCTL,  LGUI, LALT,   SPACE,    RALT,  FN0,  RCTL, LEFT, DOWN ,RIGHT,PSCR),
};

#define NO NO_LED

led_config_t g_led_config = {
    {
        // Key Matrix to LED Index
        {   0, 1, 2, 3, 4, 5, 6, 7, 8, 9,10,11,12,13,14,15 },
        {  16,17,18,19,20,21,22,23,24,25,26,27,28,29,NO,NO },
        {  30,31,32,33,34,35,36,37,38,39,40,41,42,NO,NO,NO },
        {  43,44,45,46,47,48,49,50,51,52,53,54,55,NO,NO,NO },
	{  56,57,58,NO,NO,59,NO,NO,60,61,62,63,64,NO,65,66 },
    },
    { // LED Index to Physical Position
		// x = 224 / (NUMBER_OF_COLS - 1) * COL_POSITION
		// y = 64 / (NUMBER_OF_ROWS - 1) * ROW_POSITION
        { 0,  0 },{ 15,  0 },{ 30,  0 },{ 45,  0 },{ 60,  0 },{ 75,  0 },{ 90,  0 },{ 105,  0 },{ 120,  0 },{ 135,  0 },{ 150,  0 },{ 165,  0 },{ 180,  0 },{ 195,  0 },{ 210,  0 },{ 224,  0 },  \
        { 4, 16 },{ 15, 16 },{ 30,  16 },{ 45, 16 },{ 60,  16 },{ 75,  16 },{ 90,  16 },{ 105,  16 },{ 120,  16 },{ 135,  16 },{ 150,  16 },{ 165,  16 },{ 180,  16 },{ 195,  16 },  \
        { 6, 32 },{ 15, 32 },{ 30,  32 },{ 45, 32 },{ 60,  32 },{ 75,  32 },{ 90,  32 },{ 105,  32 },{ 120,  32 },{ 135,  32 },{ 150,  32 },{ 165,  32 },{ 180,  32 },  \
        { 8, 48 },{ 15, 48 },{ 30,  48 },{ 45, 48 },{ 60,  48 },{ 75,  48 },{ 90,  48 },{ 105,  48 },{ 120,  48 },{ 135,  48 },{ 150,  48 },{ 165,  48 },{ 180,  48 },  \
	{ 10, 64 },{ 15, 64 },{ 30,  64 },{ 75,  64 },{ 120,  64 },{ 135,  64 },{ 150,  64 },{ 165,  64 },{ 180,  64 },{ 210,  64 },{ 224,  64 },  \
	 },
    { // LED Index to Flag
        4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, \
	4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, \
	4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, \
	4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, \
	4, 4, 4,       4,       4, 4, 4, 4, 4,    4, 4, \
    }
};
