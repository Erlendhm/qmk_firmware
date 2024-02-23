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

enum custom_keycodes {
     KC_CANCELLING = SAFE_RANGE,
     KC_APPROX,
     KC_FRACTION,
     KC_MULTIPLICATION,
     KC_SQUAREROOT,
     KC_ALIGN,
     KC_PARENTHESES,
     KC_TO_THE_POWER,
     KC_LATEX_SPACE,
     KC_LATEX_RETURN,
 };

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

 [0] = LAYOUT_numpad(
     RSFT(KC_ENTER), KC_BSPC,     KC_DEL,
     KC_KP_EQUAL, KC_KP_SLASH, KC_MULTIPLICATION, KC_KP_MINUS,
     KC_KP_7, KC_KP_8,     KC_KP_9,        KC_KP_PLUS,
     KC_KP_4, KC_KP_5,     KC_KP_6,
     KC_KP_1, KC_KP_2,     KC_KP_3,        KC_KP_ENTER,
     KC_KP_0, MO(1)),

 [1] = LAYOUT_numpad(
     KC_TRNS, KC_CANCELLING, KC_TRNS,
     KC_APPROX, KC_FRACTION, KC_KP_ASTERISK, KC_SQUAREROOT,
     KC_ALIGN, KC_PARENTHESES, KC_TO_THE_POWER, KC_LATEX_SPACE,
     KC_X, KC_Y, KC_Z,
     KC_A, KC_B, KC_C, KC_LATEX_RETURN,
     KC_KP_DOT, KC_TRNS),

 [2] = LAYOUT_numpad(
     KC_TRNS, KC_TRNS, KC_TRNS,
     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
     KC_TRNS, KC_TRNS, KC_TRNS,
     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
     KC_TRNS, KC_TRNS), };
/*
Macros:
*/
bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    switch (keycode) {
        case KC_CANCELLING:
            if (record->event.pressed) {
                tap_code16(S(A(KC_7)));
                SEND_STRING("cancel");
                tap_code16(S(A(KC_8)));
                tap_code16(S(A(KC_9)));
                SEND_STRING (SS_TAP(X_LEFT));
        }
            return false;
        case KC_APPROX:
            if (record->event.pressed) {
                tap_code16(A(KC_0));
                SEND_STRING(" ");
            }
            return false;
        case KC_FRACTION:
            if (record->event.pressed) {
                tap_code16(S(A(KC_7)));
                SEND_STRING("dfrac");
                tap_code16(S(A(KC_8)));
                tap_code16(S(A(KC_9)));
                tap_code16(S(A(KC_8)));
                tap_code16(S(A(KC_9)));
                SEND_STRING (SS_TAP(X_LEFT) SS_TAP(X_LEFT) SS_TAP(X_LEFT));
            }
            return false;
        case KC_MULTIPLICATION:
            if (record->event.pressed) {
                tap_code16(LCTL(LALT(LGUI(S(KC_EQUAL)))));
            }
            return false;
        case KC_SQUAREROOT:
        if (record->event.pressed) {
            tap_code16(S(A(KC_7)));
            SEND_STRING("sqrt");
            tap_code16(S(A(KC_8)));
            tap_code16(S(A(KC_9)));
            SEND_STRING (SS_TAP(X_LEFT));
        }
            return false;
        case KC_ALIGN:
        if (record->event.pressed) {
            tap_code16(S(A(KC_7)));
            SEND_STRING("begin");
            tap_code16(S(A(KC_8)));
            SEND_STRING("align");
            tap_code16(S(A(KC_9)));
            tap_code16(S(KC_ENTER));
            tap_code16(S(KC_ENTER));
            tap_code16(S(A(KC_7)));
            SEND_STRING("end");
            tap_code16(S(A(KC_8)));
            SEND_STRING("align");
            tap_code16(S(A(KC_9)));
            SEND_STRING (SS_TAP(X_UP));
        }
            return false;
        case KC_PARENTHESES:
        if (record->event.pressed) {
            tap_code16(S(KC_8));
            tap_code16(S(KC_9));
            SEND_STRING (SS_TAP(X_LEFT));
        }
            return false;
        case KC_TO_THE_POWER:
        if (record->event.pressed) {
            tap_code16(S(KC_RIGHT_BRACKET));
            tap_code16(S(A(KC_8)));
            tap_code16(S(A(KC_9)));
            SEND_STRING (SS_TAP(X_LEFT));
        }
            return false;
        case KC_LATEX_SPACE:
        if (record->event.pressed) {
            tap_code16(S(A(KC_7)));
            SEND_STRING("; ");
        }
            return false;
        case KC_LATEX_RETURN:
        if (record->event.pressed) {
            tap_code16(S(A(KC_7)));
            tap_code16(S(A(KC_7)));
            tap_code16(S(A(KC_7)));
            tap_code16(S(A(KC_7)));
            tap_code16(S(KC_ENTER));
        }
            return false;
}
    return true;
}

/*
Rotary:
*/

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_RIGHT);
        } else {
            tap_code(KC_LEFT);
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


