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

{
     "keyboard": "macro1",
     "keymap": "ErlendHM",
     "host_language": "Norwegian",
 }

enum {
    KC_APPROX,
    KC_FRACTION,
    KC_MULTIPLICATION,
    KC_SQUAREROOT,
    KC_TO_THE_POWER,
    KC_PLUSMINUS,
    KC_LATEX_SPACE,
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	[0] = LAYOUT_numpad(
		RSFT(KC_ENTER), KC_BSPC,     KC_DEL,
		KC_KP_EQUAL, KC_KP_SLASH, KC_KP_ASTERISK, KC_KP_MINUS,
		KC_KP_7, KC_KP_8,     KC_KP_9,        KC_KP_PLUS,
		KC_KP_4, KC_KP_5,     KC_KP_6,
		KC_KP_1, KC_KP_2,     KC_KP_3,        KC_KP_ENTER,
		KC_KP_0, MO(1)),

	[1] = LAYOUT_numpad(
		KC_TRNS, KC_TRNS, KC_TRNS,
		KC_APPROX, KC_FRACTION, KC_MULTIPLICATION, KC_SQUAREROOT,
		KC_LEFT_PAREN, KC_RIGHT_PAREN, KC_TO_THE_POWER, KC_PLUSMINUS,
		X, KC_Y, KC_Z,
		A, KC_B, KC_C, KC_LATEX_SPACE,
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
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_APPROX:
            if (record->event.pressed) {
                SEND_STRING("≈");
            }
            return false;
    }

    return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_FRACTION:
            if (record->event.pressed) {
                SEND_STRING("\dfrac{}{}"SS_TAP(X_LEFT) SS_TAP(X_LEFT) SS_TAP(X_LEFT));
            }
            return false;
    }

    return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_MULTIPLICATION:
            if (record->event.pressed) {
                SEND_STRING("⋅");
            }
            return false;
    }

    return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_SQUAREROOT:
            if (record->event.pressed) {
                SEND_STRING("\sqrt{}" SS_TAP(X_LEFT));
            }
            return false;
    }

    return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_TO_THE_POWER:
            if (record->event.pressed) {
            SEND_STRING("^{}" SS_TAP(X_LEFT));
            }
            return false;
    }

    return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_PLUSMINUS:
            if (record->event.pressed) {
                SEND_STRING("±");
            }
            return false;
    }

    return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_LATEX_SPACE:
            if (record->event.pressed) {
                SEND_STRING("\,");
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
            }
            else if (index == 1) {
                if (clockwise) {
                    tap_code(KC_PGDN);
                } else {
                    tap_code(KC_PGUP);
                }
            }
            return false;
        }
