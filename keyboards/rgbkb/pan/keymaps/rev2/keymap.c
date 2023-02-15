 /* Copyright 2020 RGBKB
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
// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#include QMK_KEYBOARD_H

#define _BASE 
#define _RAISE 
#define _ADJUST  
#define _ONE 

enum custom_keycodes  {
    _BASE,
    _RAISE,
    _ADJUST,
    _ONE 
};


#define FN_ESC   LT(_RAISE, KC_ESC)
#define FN_CAPS  LT(_RAISE, KC_CAPS)
#define QWERTY   DF(_BASE)
#define COLEMAK  DF(_ADJUST)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_all(
        KC_NO,                                                                                                      KC_NO,
        GRAVE_ESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,   KC_6,   KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC, KC_BSPC,
        KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,   KC_Y,   KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS, 
        FN_CAPS,   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,   KC_H,   KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT,
        KC_LSFT,   KC_Z, KC_X,    KC_C,    KC_V,    KC_B,   KC_N,   KC_M,    KC_COMM,    KC_DOT, KC_SLSH,  KC_SLSH, _______,
        KC_LCTL,   KC_LGUI, KC_LALT, RGB_TOG, KC_SPC, TG(_ONE), KC_SPC, KC_SPC, KC_LEFT, KC_DOWN, KC_QUOT,   KC_DEL
    ),

    [_ADJUST] = LAYOUT_all(
        KC_NO,                                                                                                      KC_NO,
        GRAVE_ESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,   KC_6,   KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC, _______,
        KC_TAB,    KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,   KC_J,   KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSLS,
        FN_CAPS,   KC_A,    KC_R,    KC_S,    KC_T,    KC_D,   KC_H,   KC_N,    KC_E,    KC_I,    KC_O,    KC_ENT,
        KC_LSFT,   KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,   KC_N,   KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSPC, _______,
        KC_LCTL,   KC_LGUI, KC_LALT, RGB_TOG, MO(_ONE),KC_SPC, KC_SPC, MO(_RAISE), KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT
    ),

    [_RAISE] = LAYOUT_all(
        KC_NO,                                                                                                      KC_NO,
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12, _______,
        _______, KC_PGDN, KC_UP,   KC_PGUP, _______, _______, _______, KC_PGDN, KC_UP,   KC_PGUP, KC_PSCR, KC_HOME,
        _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, KC_INS,  KC_END,
        _______, _______, _______, _______, _______, _______, _______, KC_LBRC, _______, KC_RBRC, _______, _______, _______,
        _______, _______, _______, RGB_MOD, _______, _______, _______, KC_P0,   KC_PDOT, KC_NLCK, _BASE, _BASE
    ),

    [_ONE] = LAYOUT_all(
        KC_NO,                                                                                                      KC_NO,
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12, _______,
        _______, RGB_SAD, RGB_VAI, RGB_SAI, RESET,   _______, _______, KC_P7,   KC_P8,   KC_P9,   _______, _______,
        _______, RGB_HUD, RGB_VAD, RGB_HUI, _______, _______, _______, KC_P4,   KC_P5,   KC_P6,   _______, _______,
        _______, RGB_SPD, _______, RGB_SPI, _______, _______, _______, KC_P1,   KC_P2,   KC_P3,   _______, _______, _______,
        _______, _______, _______, RGB_MOD, TG(_BASE), TG(_BASE), TG(_BASE), KC_P0,   KC_PDOT, KC_NLCK, _BASE, _BASE
    )
};

#ifdef OLED_ENABLE
void oled_task_user(void) {
    // Host Keyboard Layer Status
    oled_write_P(PSTR("RGBKB Pan\n"), false);
    oled_write_P(PSTR("Layer: "), false);
    uint8_t layer = layer_state ? biton(layer_state) : biton32(default_layer_state);
    switch (layer) {
        case _BASE:
            oled_write_P(PSTR("Default\n"), false);
            break;
        case _RAISE:
            oled_write_P(PSTR("Colemak\n"), false);
            break;
        case _ADJUST:
            oled_write_P(PSTR("Function\n"), false);
            break;
        case _ONE:
            oled_write_P(PSTR("Layer\n"), false);
            break;
        default:
            oled_write_P(PSTR("Undefined\n"), false);
            // Or use the write_ln shortcut over adding '\n' to the end of your string
            //oled_write_ln_P(PSTR("Undefined"), false);
    }
    led_t led_state = host_keyboard_led_state();
    oled_write_P(led_state.num_lock ? PSTR("Numlock On\n") : PSTR("           \n"), false);
    oled_write_P(led_state.caps_lock ? PSTR("Capslock On \n") : PSTR("           \n"), false);
}
#endif
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case _ONE:
      if (record->event.pressed) {
        layer_on(_ONE);
        update_tri_layer(_ONE, _RAISE, _ADJUST);
      } else {
        layer_off(_ONE);
        update_tri_layer(_ONE, _RAISE, _ADJUST);
      }
      return false;
      break;
    case _RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_ONE, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_ONE, _RAISE, _ADJUST);
      }
      return false;
      break;
    case _ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
  }
  return true;
bool encoder_update_user(uint8_t index, bool clockwise) {
  if (index == 0) {         // First encoder - right
    if (clockwise) {
      tap_code(KC_VOLU);
    } else {
      tap_code(KC_VOLD);
    }
  } else if (index == 1) {  // Second encoder - left
    if (clockwise) {
      tap_code(KC_VOLU);
    } else {
      tap_code(KC_VOLD);
    }
  }
    return true;
}
