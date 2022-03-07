#include QMK_KEYBOARD_H


enum custom_layers {
    _BASE,
    _ONE,
    _RAISE,
    _ADJUST,
};

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
};

#define EISU LALT(KC_GRV)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Base
   * ,----------------------------------------------------------------------------------------------------------------------.
   * |  TG1 |   Esc  |   1  |   2  |   3  |   4  |   5  |                    |   =  |   Y  |   U  |   I  |   O  |   P  |  \   |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * | C  |   Tab  |   Q  |   W  |   E  |   R  |   6  |                    |   ]  |   H  |   J  |   K  |   L  |   ;  |  "   |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * | U |   Shift  |   A  |   S  |   D  |   F  | G  |                    | Enter|   N  |   M  |   ,  |   .  |   /  | Shift|
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * | I |  CTRL |  Z | X |||||||| V  | Alt  |Space        |||||||| Bksp | Enter| Raise|||||||| Left | Down |  Up  | Right|
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_BASE] = LAYOUT( \
    TG(1),  KC_GESC,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                        KC_EQL , KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS, \
    KC_C,  KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_6,                        KC_RBRC, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
    KC_U, KC_LSFT,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G ,                        KC_ENT , KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, \
    KC_I, KC_LCTL, KC_Z, KC_X,             KC_V,   KC_LALT , KC_SPC,        KC_BSPC,KC_ENT , RAISE,            KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT  \
  ),

  /* One
   * ,----------------------------------------------------------------------------------------------------------------------.
   * |   TG  |   ___  |   ___  |   ___  |   ___  |  ___  |   _  |         |   +  |   ^  |   &  |   *  |   (  |   )  |  |   |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * |   __ |   RGB TG  |   Bright +  |  Mode +  |   __  |  P  |   __  |        |   }  | Left | Down |  Up  | Right|   :  |  "   |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * | __|   __  |  Bright -  |   Mode -  |  N  |   M | LSHFT|          | Enter|   N  |   M  |   <  |   >  |   ?  | Shift|
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * | F1 |  F2 |  F3 | F4 |||||||| ____| Ctrl |Delete|||||||| Bksp | Enter| Raise|||||||| Home |PageDn|PageUp|  End |
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_ONE] = LAYOUT(
    TG(1) , TG(2), KC_TRNS,   KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,                        KC_PLUS, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PIPE, \
    KC_TRNS, RGB_TOG,    RGB_VAI,    RGB_MOD,    KC_TRNS,    KC_P,    KC_TRNS,                        KC_RCBR, KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, KC_COLN, KC_DQT , \
    KC_TRNS, KC_TRNS,    RGB_VAD,    RGB_RMOD,    KC_N,    KC_M,    KC_LSFT ,                        KC_ENT , KC_N,    KC_M,    KC_LT,   KC_GT,   KC_QUES, KC_RSFT, \
    KC_F1, KC_F2, KC_F3, KC_F4,             KC_TRNS,   KC_LCTL , KC_DEL,        KC_BSPC,KC_ENT , RAISE,            KC_HOME, KC_PGDN, KC_PGUP, KC_END   \
  ),

  /* Raise
  * ,----------------------------------------------------------------------------------------------------------------------.
  * |   `  |   !  |   @  |   #  |   $  |   %  |   _  |                    |   +  |   ^  |   &  |   *  |   (  |   )  |  |   |
  * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
  * |   ~  |   F1 |   F2 |   F3 |   F4 |   F5 |   {  |                    |   }  | Left | Down |  Up  | Right|   :  |  "   |
  * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
  * | Shift|   F6 |   F7 |   F8 |   F9 |  F10 | Space|                    | Enter|   N  |   M  |   <  |   >  |   ?  | Shift|
  * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
  * | Ctrl |  F11 |  F12 | EISU |||||||| Lower| Space|Delete|||||||| Bksp | Enter| Raise|||||||| Home |PageDn|PageUp|  End |
  * ,----------------------------------------------------------------------------------------------------------------------.
  */
  [_RAISE] = LAYOUT(
    TG(2) , KC_TRNS, KC_TRNS,   KC_HASH, KC_DLR,  KC_PERC, KC_UNDS,                        KC_PLUS, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PIPE, \
    KC_TILD, KC_TRNS,   KC_A,   KC_W,   KC_D,   KC_F5,   KC_LCBR,                        KC_RCBR, KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, KC_COLN, KC_DQT , \
    KC_LSFT, KC_F6,   KC_TRNS,   KC_S,   KC_F9,   KC_F10,  KC_SPC ,                        KC_ENT , KC_N,    KC_M,    KC_LT,   KC_GT,   KC_QUES, KC_RSFT, \
    KC_LCTL, KC_F11 , KC_F12,  EISU,             KC_V,   KC_LSFT , KC_DEL,        KC_BSPC,KC_ENT , RAISE,            KC_HOME, KC_PGDN, KC_PGUP, KC_END   \
    ),

  /* Adjust
   * ,----------------------------------------------------------------------------------------------------------------------.
   * |      | Reset|RGB ON|  MODE|  HUE-|  HUE+|      |                    |      |  SAT-|  SAT+|  VAL-|  VAL+|      |      |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |                    |      |      |      |      |      |      |      |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |                    |      |      |      |      |      |      |      |
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * |      |      |      |      ||||||||      |      |      ||||||||      |      |      ||||||||      |      |      |      |
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_ADJUST] = LAYOUT(
    _______, RESET  , RGB_TOG, RGB_MOD, RGB_HUD, RGB_HUI,_______,                       _______, RGB_SAD, RGB_SAI, RGB_VAD, RGB_VAI, _______, _______, \
    _______, _______, BL_TOGG, BL_BRTG, BL_INC , BL_DEC ,_______,                       _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______,_______,                       _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______,          _______,_______,_______,       _______,_______, _______,          _______, _______, _______, _______  \
  )
};

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
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_ONE, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_ONE, _RAISE, _ADJUST);
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
  }
  return true;
}
