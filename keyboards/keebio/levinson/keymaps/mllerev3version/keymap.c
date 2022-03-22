#include QMK_KEYBOARD_H


// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _BASE 0
#define _ONE 1

enum custom_keycodes {
  BASE = SAFE_RANGE,
  ONE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Base
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |  ;  | Enter |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |  "'  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Ctrl| LAlt | Copy  | ~`  |    \| |Layer |Space |   -_ | +=  |  CLock |  WIn  | Del |
 * `-----------------------------------------------------------------------------------'
 */
[_BASE] = LAYOUT_ortho_4x12( \
  KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC, \
  KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT, \
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_QUOT , \
  KC_LCTL,  KC_LALT, KC_COPY, KC_GRV, KC_BSLS,   TG(1),  KC_SPC,  KC_MINS,   KC_EQL, KC_CAPS, KC_LGUI,   KC_DEL \
),

/* One
 * ,-----------------------------------------------------------------------------------.
 * | `~  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | -_    |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | __  |  __  | __  | Up  | ___ | PgUp | Mute |Vol+| Play/Pause|   |\  | =+  |  Bksp |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|RGB  |Left  | Down  | Rght  | PgDwn| Prev  |  Vol- |  Next | ___ |  [{ | }] |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Calc| Ctrl | ___ | ___ |___ | Layer |Layer |  ____ | ____ | Space |  Layer  |Layer |
 * `-----------------------------------------------------------------------------------'
 */
[_ONE] = LAYOUT_ortho_4x12( \
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,       KC_6,    KC_7,    KC_8,    KC_9,    KC_0,       KC_MINS, \
_______, RGB_MOD, _______,   KC_UP,  _______, _______,    KC_MUTE,   KC_VOLU,   KC_MPLY,   KC_BSLS,    KC_EQL,    KC_BSPC, \
  KC_LSFT, RGB_TOG, KC_LEFT, KC_DOWN, KC_RGHT, _______,    KC_MPRV,  KC_VOLD,  KC_MNXT, _______,   KC_LBRC,   KC_RBRC , \
  KC_CALC,  KC_LCTL, BL_TOGG, _______, _______,   TG(1),    TG(1),  _______,   _______,   KC_SPC,    BASE,    BASE \
),



};


void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}