#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.

enum layer_names {
  _BASE,
  _ONE,
  _RAISE,
  _ADJUST
};

enum custom_keycodes {
  BASE = SAFE_RANGE,
  ONE,
  DVORAK
};

#define ONE    TG(_ONE)
#define RAISE  TG(_RAISE)
#define ADJUST TG(_ADJUST)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_BASE] = LAYOUT_all(
   KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,            KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
   KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,   KC_MUTE, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT,
   KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,   KC_MUTE, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_QUOT ,
   KC_LCTL,  KC_LALT, KC_COPY, KC_GRV, KC_BSLS,  ONE, KC_MUTE,  KC_SPC,  KC_MINS,   KC_EQL, KC_CAPS, KC_LGUI,   KC_DEL
),

[_ONE] = LAYOUT_all(
  KC_DEL, KC_1, KC_2,   KC_3, KC_4,  KC_5,                        KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS,
  KC_DEL, _______, _______, KC_UP, _______,   _______,   _______, KC_F6,   KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE,
  _______, KC_F7,  KC_LEFT, KC_DOWN, KC_RIGHT,  KC_F11,  _______, _______,_______,_______,_______, _______, _______,
  _______, _______, _______, _______, _______, ONE, _______, ONE, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY
),

[_RAISE] = LAYOUT_all(
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,             KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,
  KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______, KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,
  _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  _______, KC_F12,  KC_NUHS, KC_NUBS, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY
),

[_ADJUST] =  LAYOUT_all(
  _______, RESET,   _______, _______, _______, _______,          _______, _______, _______, _______, _______, KC_DEL,
  _______, _______, _______, AU_ON,   AU_OFF,  AG_NORM, _______, AG_SWAP, ONE,  RAISE, _______,  _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
)
};

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _ONE, _RAISE, _ADJUST);
}
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case BASE:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_BASE);
             }
             break;
        case RAISE:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_RAISE);
            }
            break;
        case ADJUST:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_ADJUST);
            }
            break;
    }
    return true;
}

#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        // Volume control
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    } else if (index == 1) {
        // Page up/Page down
        if (clockwise) {
            tap_code(KC_PGDN);
        } else {
            tap_code(KC_PGUP);
        }
    }
    return true;
}
#endif