/* Copyright 2021 Laneware Peripherals
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
#include "sendstring_norwegian.h"

/*
 * ┌───┐   ┌───┬───┐
 * │K00│   │K02│K03│
 * └───┘   └───┴───┘
 * ┌───┬───┬───┬───┐
 * │K10│K11│K12│K13│
 * ├───┼───┼───┼───┤
 * │K20│K21│K22│K23│
 * ├───┼───┼───┤   │
 * │K30│K31│K32│   │
 * ├───┼───┼───┼───┤
 * │K40│K41│K42│K43│
 * ├───┴───┼───┤   │
 * │K50    │K52│   │
 * └───────┴───┴───┘
 */

#define RTRN_L1 LT(1, KC_KP_ENTER)
#define CMA_L2 LT(2, KC_DOT)
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {[0] = LAYOUT_numpad(LGUI(KC_S), KC_DEL, KC_KP_EQUAL, KC_BSPC, KC_KP_SLASH, KC_KP_ASTERISK, KC_KP_MINUS, KC_KP_7, KC_KP_8, KC_KP_9, KC_KP_PLUS, KC_KP_4, KC_KP_5, KC_KP_6, KC_KP_1, KC_KP_2, KC_KP_3, RTRN_L1, KC_KP_0, CMA_L2), [1] = LAYOUT_numpad(KC_TRNS, KC_TRNS, KC_TRNS, LOPT(KC_BSPC), KC_TRNS, KC_TRNS, KC_TRNS, LOPT(KC_LEFT), KC_UP, LOPT(KC_RIGHT), KC_TRNS, KC_LEFT, KC_DOWN, KC_RIGHT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_KP_DOT), [2] = LAYOUT_numpad(KC_TRNS, KC_TRNS, KC_TRNS, RGUI(KC_BSPC), KC_TRNS, KC_TRNS, KC_TRNS, RSFT(KC_8), RSFT(KC_9), KC_TRNS, KC_TRNS, RSA(KC_8), RSA(KC_9), KC_TRNS, RALT(KC_8), RALT(KC_9), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS)};

/*
Macros:
*/

/*
Rotary:
*/

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            register_code(KC_LGUI);
            register_code(KC_LSFT);
            tap_code(KC_Z);
            unregister_code(KC_LSFT);
            unregister_code(KC_LGUI);
        } else {
            register_code(KC_LGUI);
            tap_code(KC_Z);
            unregister_code(KC_LGUI);
        }
    } else if (index == 1) {
        if (clockwise) {
            tap_code(KC_PGDN);
        } else {
            tap_code(KC_PGUP);
        }
    }
    return false;
}
