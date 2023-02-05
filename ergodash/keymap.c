#include QMK_KEYBOARD_H


enum layer_names {
    _QWERTY,
    _COLEMAK,
    _QWERTY_M,
    _COLEMAK_M,
    _NUMS,
    _LOWER,
    _RAISE,
    _ADJUST
};

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAK,
  QWERTY_M,
  COLEMAK_M,
  NUMS,
  LOWER,
  RAISE,
  ADJUST,
};

// Qwerty home row mods
#define Q_A    LSFT_T(KC_A)
#define Q_S    LGUI_T(KC_S)
#define Q_D    LALT_T(KC_D)
#define Q_F    LCTL_T(KC_F)

#define Q_J    LCTL_T(KC_J)
#define Q_K    LALT_T(KC_K)
#define Q_L    LGUI_T(KC_L)
#define Q_SCLN LSFT_T(KC_SCLN)

// Colemak home row mods
#define C_A    LSFT_T(KC_A)
#define C_R    LGUI_T(KC_R)
#define C_S    LALT_T(KC_S)
#define C_T    LCTL_T(KC_T)

#define C_M    LCTL_T(KC_M)
#define C_N    LALT_T(KC_N)
#define C_E    LGUI_T(KC_E)
#define C_I    LSFT_T(KC_I)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Qwerty
   * ,----------------------------------------------------------------------------------------------------------------------.
   * | Tab  |   1  |   2  |   3  |   4  |   5  | Caps |                    | Mods |   6  |   7  |   8  |   9  |   0  | PgUp |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * |  `   |   Q  |   W  |   E  |   R  |   T  | Home |                    | End  |   Y  |   U  |   I  |   O  |   P  | PgDn |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * | Esc  |   A  |   S  |   D  |   F  |   G  | Clmk |                    | Del  |   H  |   J  |   K  |   L  |   ;  |  "   |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * | Shift|   Z  |   X  |   C  |   V  |   B  | Space|                    | Bksp |   N  |   M  |   ,  |   .  |   /  | Enter|
   * |-------------+------+------+------+------|      |--------------------|      |------+------+------+------+-------------|
   * | Ctrl |  GUI |  Alt | NUMS |||||||| Lower| Space|                    | Bksp | Raise|||||||| Left | Down |  Up  | Right|
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_QWERTY] = LAYOUT(
    KC_TAB,  KC_1,    KC_2,    KC_3,   KC_4,   KC_5,  KC_CAPS,                       TG(2),   KC_6,   KC_7,   KC_8,    KC_9,    KC_0,    KC_PGUP,
    KC_GRV,  KC_Q,    KC_W,    KC_E,   KC_R,   KC_T,  KC_HOME,                       KC_END,  KC_Y,   KC_U,   KC_I,    KC_O,    KC_P,    KC_PGDN,
    KC_ESC,  KC_A,    KC_S,    KC_D,   KC_F,   KC_G,  TG(1),                         KC_DEL,  KC_H,   KC_J,   KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,   KC_V,   KC_B,  KC_SPC,                        KC_BSPC, KC_N,   KC_M,   KC_COMM, KC_DOT,  KC_SLSH, KC_SFTENT,
    KC_LCTL, KC_LGUI, KC_LALT, NUMS,           LOWER, KC_SPC,  KC_NO,         KC_NO, KC_BSPC, RAISE,          KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
  ),

  /* Colemak-DH
   * ,----------------------------------------------------------------------------------------------------------------------.
   * | Tab  |   1  |   2  |   3  |   4  |   5  | Caps |                    | Mods |   6  |   7  |   8  |   9  |   0  | PgUp |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * |  `   |   Q  |   W  |   F  |   P  |   B  | Home |                    | End  |   J  |   L  |   U  |   P  |   ;  | PgDn |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * | Esc  |   A  |   R  |   S  |   T  |   G  | Qwty |                    | Del  |   M  |   N  |   E  |   I  |   O  |  "   |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * | Shift|   Z  |   X  |   C  |   D  |   V  | Space|                    | Bksp |   K  |   H  |   ,  |   .  |   /  | Enter|
   * |-------------+------+------+------+------|      |--------------------|      |------+------+------+------+-------------|
   * | Ctrl |  GUI |  Alt | NUMS |||||||| Lower| Space|                    | Bksp | Raise|||||||| Left | Down |  Up  | Right|
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_COLEMAK] = LAYOUT(
    KC_TAB,  KC_1,    KC_2,    KC_3,   KC_4,   KC_5,  KC_CAPS,                       TG(3),   KC_6,   KC_7,   KC_8,    KC_9,    KC_0,    KC_PGUP,
    KC_GRV,  KC_Q,    KC_W,    KC_F,   KC_P,   KC_B,  KC_HOME,                       KC_END,  KC_J,   KC_L,   KC_U,    KC_P,    KC_SCLN  KC_PGDN,
    KC_ESC,  KC_A,    KC_R,    KC_S,   KC_T,   KC_G,  TG(0),                         KC_DEL,  KC_M,   KC_N,   KC_E,    KC_I,    KC_O,    KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,   KC_D,   KC_V,  KC_SPC,                        KC_BSPC, KC_K,   KC_H,   KC_COMM, KC_DOT,  KC_SLSH, KC_SFTENT,
    KC_LCTL, KC_LGUI, KC_LALT, NUMS,           LOWER, KC_SPC,  KC_NO,         KC_NO, KC_BSPC, RAISE,          KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
  ),

  /* The next two layers are identical but with home row modifier keys
   */
  [_QWERTY_M] = LAYOUT(
    KC_TAB,  KC_1,    KC_2,    KC_3, KC_4, KC_5,  KC_CAPS,                       TG(0),   KC_6,   KC_7, KC_8,    KC_9,    KC_0,    KC_PGUP,
    KC_GRV,  KC_Q,    KC_W,    KC_E, KC_R, KC_T,  KC_HOME,                       KC_END,  KC_Y,   KC_U, KC_I,    KC_O,    KC_P,    KC_PGDN,
    KC_ESC,  Q_A,     Q_S,     Q_D,  Q_F,  KC_G,  TG(3),                         KC_DEL,  KC_H,   Q_J,  Q_K,     Q_L,     Q_SCLN,  KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C, KC_V, KC_B,  KC_SPC,                        KC_BSPC, KC_N,   KC_M, KC_COMM, KC_DOT,  KC_SLSH, KC_SFTENT,
    KC_LCTL, KC_LGUI, KC_LALT, NUMS,       LOWER, KC_SPC,  KC_NO,         KC_NO, KC_BSPC, RAISE,        KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
  ),
  [_COLEMAK_M] = LAYOUT(
    KC_TAB,  KC_1,    KC_2,    KC_3, KC_4, KC_5,  KC_CAPS,                       TG(1),   KC_6,   KC_7, KC_8,    KC_9,    KC_0,    KC_PGUP,
    KC_GRV,  KC_Q,    KC_W,    KC_F, KC_P, KC_B,  KC_HOME,                       KC_END,  KC_J,   KC_L, KC_U,    KC_P,    KC_SCLN  KC_PGDN,
    KC_ESC,  C_A,     C_R,     C_S,  C_T,  KC_G,  TG(2),                         KC_DEL,  KC_M,   C_N,  C_E,     C_I,     C_O,     KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C, KC_D, KC_V,  KC_SPC,                        KC_BSPC, KC_K,   KC_H, KC_COMM, KC_DOT,  KC_SLSH, KC_SFTENT,
    KC_LCTL, KC_LGUI, KC_LALT, NUMS,       LOWER, KC_SPC,  KC_NO,         KC_NO, KC_BSPC, RAISE,        KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
  ),

  /* Nums
   * ,----------------------------------------------------------------------------------------------------------------------.
   * |      |  F1  |  F2  |  F3  |  F4  |      | Home |                    |      |      |      |      |      |      | PgUp |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * |      |  F5  |  F6  |  F7  |  F8  |      | Caps |                    |      |      |      |      |      |      | PgDn |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * |      |  F9  |  F10 |  F11 |  F12 |      | Pscr |                    |      |      |      |      |      |      |      |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * |      |  F13 |  F14 |  F15 |  F16 |      | Space|                    | Bksp |      |      |      |      |      | Enter|
   * |-------------+------+------+------+------|      |--------------------|      |------+------+------+------+-------------|
   * | Ctrl |  GUI |  Alt | NUMS |||||||| Lower| Space|                    | Bksp | Raise|||||||| Left | Down |  Up  | Right|
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_NUMS] = LAYOUT(
    KC_TAB,  KC_1,    KC_2,    KC_3,   KC_4,   KC_5,   KC_HOME,                       KC_END,    KC_6,   KC_7,   KC_8,    KC_9,    KC_0,    KC_PGUP,
    KC_GRV,  KC_Q,    KC_W,    KC_E,   KC_R,   KC_T,   KC_CAPS,                       TG(1),     KC_Y,   KC_U,   KC_I,    KC_O,    KC_P,    KC_PGDN,
    KC_ESC,  Q_A,     Q_S,     Q_D,    Q_F,    KC_G,   KC_PSCR,                       KC_DEL,    KC_H,   Q_J,    Q_K,     Q_L,     Q_SCLN,  KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,   KC_V,   KC_B,   KC_SPC,                        KC_BSPC,   KC_N,   KC_M,   KC_COMM, KC_DOT,  KC_SLSH, KC_SFTENT,
    KC_LCTL, KC_LGUI, KC_LALT, NUMS,           LOWER,  KC_SPC,  KC_NO,         KC_NO, KC_BSPC,   RAISE,          KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
  ),

  /* Lower
   * ,----------------------------------------------------------------------------------------------------------------------.
   * |      |      |      |      |      |      |      |                    |      |      |      |      |      |      |      |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |                    |      |      |      |      |      |      |      |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |                    |      |      |      |      |      |      |      |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |                    |      |      |      |      |      |      |      |
   * |-------------+------+------+------+------|      |--------------------|      |------+------+------+------+-------------|
   * | Ctrl |  GUI |  Alt | NUMS |||||||| Lower| Space|                    | Bksp | Raise|||||||| Left | Down |  Up  | Right|
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_LOWER] = LAYOUT(
    KC_F11,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_LCBR,                        KC_RCBR, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F12,
    KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_UNDS,                        KC_PLUS, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PIPE,
    KC_TAB,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_DEL ,                        KC_BSPC, KC_H,    KC_J,    KC_K,    KC_L,    KC_COLN, KC_DQT ,
    KC_LSFT, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_SPC ,                        KC_ENT , KC_N,    KC_M,    KC_LT,   KC_GT,   KC_QUES, KC_RSFT,
    KC_LCTL, KC_LGUI, KC_LALT, NUMS,             LOWER,   KC_SPC ,KC_DEL,         KC_BSPC,KC_ENT , RAISE,            KC_HOME, KC_PGDN, KC_PGUP, KC_END
  ),

  /* Raise
   * ,----------------------------------------------------------------------------------------------------------------------.
   * |      |      |      |      |      |      |      |                    |      |      |      |      |      |      |      |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |                    |      |      |      |      |      |      |      |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |                    |      |      |      |      |      |      |      |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |                    |      |      |      |      |      |      |      |
   * |-------------+------+------+------+------|      |--------------------|      |------+------+------+------+-------------|
   * | Ctrl |  GUI |  Alt | NUMS |||||||| Lower| Space|                    | Bksp | Raise|||||||| Left | Down |  Up  | Right|
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_RAISE] = LAYOUT(
    KC_F11,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_LCBR,                        KC_RCBR, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F12,
    KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_UNDS,                        KC_PLUS, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PIPE,
    KC_TAB,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_DEL ,                        KC_BSPC, KC_H,    KC_J,    KC_K,    KC_L,    KC_COLN, KC_DQT ,
    KC_LSFT, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_SPC ,                        KC_ENT , KC_N,    KC_M,    KC_LT,   KC_GT,   KC_QUES, KC_RSFT,
    KC_LCTL, KC_LGUI, KC_LALT, NUMS,             LOWER,   KC_SPC ,KC_DEL,         KC_BSPC,KC_ENT , RAISE,            KC_HOME, KC_PGDN, KC_PGUP, KC_END
  ),

  /* Adjust
   * ,----------------------------------------------------------------------------------------------------------------------.
   * |      |      |      |      |      |      |      |                    |      |      |      |      |      |      |      |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * |      | Reset|RGB ON|  MODE|  HUE-|  HUE+|      |                    |      |  SAT-|  SAT+|  VAL-|  VAL+|      |      |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * |      |      | BL ON|  BRTG|  INC|   DEC|      |                    |      |      |      |      |      |      |      |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |                    |      |      |      |      |      |      |      |
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * |      |      |      |      ||||||||      |      |      ||||||||      |      |      ||||||||      |      |      |      |
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_ADJUST] = LAYOUT(
    _______, _______, _______, _______, _______, _______,_______,                       _______, _______, _______, _______, _______, _______, _______,
    _______, QK_BOOT  , RGB_TOG, RGB_MOD, RGB_HUD, RGB_HUI,_______,                       _______, RGB_SAD, RGB_SAI, RGB_VAD, RGB_VAI, _______, _______,
    _______, _______, BL_TOGG, BL_BRTG, BL_INC , BL_DEC ,_______,                       _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,_______,                       _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______,          _______,_______,_______,       _______,_______, _______,          _______, _______, _______, _______
  )
};

#ifdef AUDIO_ENABLE
float tone_qwerty[][2]     = SONG(QWERTY_SOUND);
#endif

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
         print("mode just switched to qwerty and this is a huge string\n");
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
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
