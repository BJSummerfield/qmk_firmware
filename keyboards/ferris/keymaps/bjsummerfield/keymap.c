// this is the style you want to emulate.
// This is the canonical layout file for the Quantum project. If you want to add another keyboard,

#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.

enum ferris_layers {
  _QWERTY = 0,
  _GAME,
  _SYMBOL,
  _NAV,
  _FUNCTION
};

//Left Home row mods
#define HOME_A LSFT_T(KC_A)
#define HOME_S LALT_T(KC_S)
#define HOME_D LGUI_T(KC_D)
#define HOME_F LCTL_T(KC_F)

//Right Home row mods
#define HOME_SCLN RSFT_T(KC_SCLN)
#define HOME_L RALT_T(KC_L)
#define HOME_K LGUI_T(KC_K)
#define HOME_J RCTL_T(KC_J)

//Thumb clusters
#define SYMBOL LT(_SYMBOL, KC_TAB)
#define NAV LT(_NAV, KC_ENT)



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT(
    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,            KC_Y,    KC_U,   KC_I,    KC_O,   KC_P,
    HOME_A,  HOME_S,  HOME_D,  HOME_F,  KC_G,            KC_H,    HOME_J, HOME_K,  HOME_L, HOME_SCLN,
    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,            KC_N,    KC_M,  KC_COMM, KC_DOT, KC_SLASH,
                                    SYMBOL, KC_BSPC, KC_SPC, NAV
  ),
  [_GAME] = LAYOUT(
    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,            KC_Y,    KC_U,   KC_I,    KC_O,   KC_P,
    HOME_A,    KC_S,    KC_D,    KC_F,    KC_G,            KC_H,    HOME_J, HOME_K,  HOME_L, HOME_SCLN,
    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,            KC_N,    KC_M,  KC_COMM, KC_DOT, KC_SLASH,
                                    SYMBOL, KC_BSPC, KC_SPC, NAV
  ),
  [_SYMBOL] = LAYOUT(
    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,            KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
    KC_DLR,  KC_PLUS, KC_LPRN, KC_RPRN, KC_AT,           KC_PIPE, KC_MINS, KC_EQL,  KC_UNDS, KC_ASTR,
    KC_EXLM, KC_HASH, KC_LCBR, KC_RCBR, KC_TILD,         KC_AMPR, KC_LBRC, KC_RBRC, KC_PERC, KC_CIRC,
                                    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
  ),
  [_NAV] = LAYOUT(
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,         KC_NO, KC_NO, KC_UP,   KC_NO, KC_NO,
    KC_LSFT, KC_LALT, KC_LGUI, KC_LCTL, KC_NO,         KC_NO, KC_LEFT, KC_DOWN, KC_RIGHT,KC_NO,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,         KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
                                    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
  ),
  [_FUNCTION] = LAYOUT(
    KC_F1,   KC_F2,   KC_F3,   KC_F4,        KC_F5,           KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,
    KC_NO,   KC_NO,   KC_NO,   KC_NO,        KC_NO,           KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
    KC_NO,   KC_NO,   KC_NO,   DF(_QWERTY),  DF(_GAME),       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
                                    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
  )
};

//COMBO's
const uint16_t PROGMEM function_layer[] = {SYMBOL, NAV, COMBO_END};
const uint16_t PROGMEM q_escape[] = {KC_SPC, KC_Q, COMBO_END};
const uint16_t PROGMEM a_delete[] = {KC_SPC, HOME_A, COMBO_END};
const uint16_t PROGMEM z_btick[] = {KC_SPC, KC_Z, COMBO_END};
const uint16_t PROGMEM scln_qt[] = {KC_BSPC, HOME_SCLN, COMBO_END};
const uint16_t PROGMEM p_bsl[] = {KC_BSPC, KC_P, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    COMBO(function_layer, MO(_FUNCTION)),
    COMBO(q_escape, KC_ESC),
    COMBO(a_delete, KC_DEL),
    COMBO(z_btick, KC_GRV),
    COMBO(scln_qt, KC_QUOT),
    COMBO(p_bsl, KC_BSLS),
};

