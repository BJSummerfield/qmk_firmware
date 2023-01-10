// this is the style you want to emulate.
// This is the canonical layout file for the Quantum project. If you want to add another keyboard,

#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.

enum ferris_layers {
  _COLMAK = 0,
  _GAME,
  _SYMBOL,
  _NAV,
  _FUNCTION
};

//Left Home row mods
#define HOME_A LSFT_T(KC_A)
#define HOME_R LALT_T(KC_R)
#define HOME_S LGUI_T(KC_S)
#define HOME_T LCTL_T(KC_T)

//Right Home row mods
#define HOME_O RSFT_T(KC_O)
#define HOME_I RALT_T(KC_I)
#define HOME_E LGUI_T(KC_E)
#define HOME_N RCTL_T(KC_N)

//Thumb clusters
#define SYMBOL LT(_SYMBOL, KC_TAB)
#define NAV LT(_NAV, KC_ENT)



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_COLMAK] = LAYOUT(
    KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,            KC_J,    KC_L,   KC_U,    KC_Y,   KC_SCLN,
    HOME_A,  HOME_R,  HOME_S,  HOME_T,  KC_G,            KC_M,    HOME_N, HOME_E,  HOME_I, HOME_O,
    KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,            KC_K,    KC_H,  KC_COMM, KC_DOT, KC_SLASH,
                                    SYMBOL, KC_BSPC, KC_SPC, NAV
  ),
  [_GAME] = LAYOUT(
    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,            KC_TRNS,    KC_TRNS,   KC_TRNS,    KC_TRNS,   KC_TRNS,
    KC_TRNS,    KC_S,       KC_D,       KC_F,       KC_TRNS,            KC_TRNS,    KC_TRNS,   KC_TRNS,    KC_TRNS,   KC_TRNS,
    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,            KC_TRNS,    KC_TRNS,   KC_TRNS,    KC_TRNS,   KC_TRNS,
                                    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
  ),
  [_SYMBOL] = LAYOUT(
    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,            KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
    KC_DLR,  KC_PLUS, KC_LPRN, KC_RPRN, KC_AT,           KC_PIPE, KC_MINS, KC_EQL,  KC_UNDS, KC_ASTR,
    KC_EXLM, KC_HASH, KC_LCBR, KC_RCBR, KC_TILD,         KC_AMPR, KC_LBRC, KC_RBRC, KC_PERC, KC_CIRC,
                                    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
  ),
  [_NAV] = LAYOUT(
    KC_NO,    KC_NO,    KC_NO,    KC_NO,     KC_NO,         KC_NO,  KC_NO,    KC_UP,    KC_NO,     KC_NO,
    KC_LSFT,  KC_LALT,  KC_LGUI,  KC_LCTL,   KC_NO,         KC_NO,  KC_LEFT,  KC_DOWN,  KC_RIGHT,  KC_NO,
    KC_NO,    KC_NO,    KC_NO,    KC_NO,     KC_NO,         KC_NO,  KC_NO,    KC_NO,    KC_NO,     KC_NO,
                                    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
  ),
  [_FUNCTION] = LAYOUT(
    KC_F1,   KC_F2,   KC_F3,   KC_F4,        KC_F5,           KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,
    KC_F11,   KC_F12,   KC_NO,   KC_NO,        KC_NO,           KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
    KC_NO,   KC_NO,   KC_NO,   DF(_COLMAK),  DF(_GAME),       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
                                    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
  )
};

//COMBO's
const uint16_t PROGMEM function_layer[] = {SYMBOL, NAV, COMBO_END};
const uint16_t PROGMEM a_escape[] = {KC_BSPC, HOME_A, COMBO_END};
const uint16_t PROGMEM z_delete[] = {KC_BSPC, KC_Z, COMBO_END};
const uint16_t PROGMEM q_btick[] = {KC_BSPC, KC_Q, COMBO_END};
const uint16_t PROGMEM o_qt[] = {KC_SPC, HOME_O, COMBO_END};
const uint16_t PROGMEM scln_bsl[] = {KC_SPC, KC_SCLN, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    COMBO(function_layer, MO(_FUNCTION)),
    COMBO(a_escape, KC_ESC),
    COMBO(z_delete, KC_DEL),
    COMBO(q_btick, KC_GRV),
    COMBO(o_qt, KC_QUOT),
    COMBO(scln_bsl, KC_BSLS),
};

