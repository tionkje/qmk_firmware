


#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _FNL 1
#define _FNR 2
#define _NUM 3
#define _ARROW 4
#define _FUNk 5



enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  FNL,
  FNR,
};





// increase readability 
#define _______ KC_TRNS
#define XXXXXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Default Layer
   * ,-----------------------------------------------------------.
   * | Esc|  Q |  W |  E |  R |  T |  Y |  U |  I |  O |  P | BS |
   * |-----------------------------------------------------------|
   * | Tab |  A |  S |  D |  F |  G |  H |  J |  K |  L | Ent    |
   * |-----------------------------------------------------------|
   * | LSft   |  Z |  X |  C |  V |  B |  N |  M |  ,  |  . | /? |
   * |-----------------------------------------------------------|
   * | LCtl | LGui| LAlt|  spc fn0  |  spc fn1    |fn2|RAlt|RCtl |
   * `-----------------------------------------------------------'
   */
  /* [_QWERTY] = LAYOUT( \ */
  /*     KC_ESC,  KC_Q,    KC_W,    KC_E,     KC_R,   KC_T,    KC_Y,  KC_U, KC_I, KC_O, KC_P, KC_BSPC, \ */
  /*     KC_TAB,  KC_A,    KC_S,    KC_D,     KC_F,   KC_G,    KC_H,  KC_J, KC_K, KC_L, KC_ENT, \ */
  /*     KC_LSFT, KC_Z,    KC_X,    KC_C,     KC_V,   KC_B,    KC_N,  KC_M, KC_SLASH, KC_UP, KC_RSHIFT, \ */
  /*     KC_LCTL, KC_LGUI, KC_LALT, LT(_FNL, KC_SPC), LT(_FNR, KC_SPC), KC_LEFT, KC_DOWN, KC_RIGHT\ */
  /*     ), */

  
  // TODO: KC_COMMA(,<), KC_DOT(.>), KC_BSLASH(\|)
  // F7 - F12
  /* Function Layer 1 HHKB style
   * ,-----------------------------------------------------------.
   * |   `  |   1   |  2  | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 0 |  -   |
   * |-----------------------------------------------------------|
   * |       | F1 | F2 | F3 | Ins |Home|PgUp| { | } | = |        |
   * |-----------------------------------------------------------|
   * |        | F4 | F5 |  F6  | Del |End|PgDn| ; | '  |    |    |
   * |-----------------------------------------------------------|
   * |   RESET  |     |           |             |     |    |     |
   * `-----------------------------------------------------------'
   */
  /* [_FNL] = LAYOUT( \ */
  /*     KC_GRAVE, KC_1, KC_2,   KC_3, KC_4,  KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINUS, \ */
  /*     _______, KC_F1,   KC_F2,   KC_F3,  KC_INS,  KC_HOME,  KC_PGUP, KC_LBRACKET, KC_RBRACKET, KC_EQUAL, _______, \ */
  /*     _______,   KC_F4,   KC_F5,   KC_F6,  KC_DEL,  KC_END,  KC_PGDN, KC_SCOLON, KC_QUOTE, _______, _______, \ */
  /*     RESET, _______, _______, _______, _______, _______, _______, _______ \ */
  /*     ), */
  /* [_FNR] = LAYOUT( \ */
  /*     KC_GRAVE, KC_1, KC_2,   KC_3, KC_4,  KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINUS, \ */
  /*     _______, KC_F1,   KC_F2,   KC_F3,  KC_INS,  KC_HOME,  KC_PGUP, KC_LBRACKET, KC_RBRACKET, KC_EQUAL, _______, \ */
  /*     _______,   KC_F4,   KC_F5,   KC_F6,  KC_DEL,  KC_END,  KC_PGDN, KC_SCOLON, KC_QUOTE, _______, _______, \ */
  /*     RESET, _______, _______, _______, _______, _______, _______, _______ \ */
  /*     ), */


  [_QWERTY] = LAYOUT( \
      KC_ESC,  KC_Q,    KC_W,    KC_E,     KC_R,   KC_T,    KC_Y,  KC_U, KC_I, KC_O, KC_P, KC_BSPC, \
      KC_TAB,  KC_A,    KC_S,    KC_D,     LT(_NUM, KC_F),   KC_G,    KC_H,  LT(_FUNk,KC_J), LT(_ARROW,KC_K), KC_L, KC_ENT, \
      KC_LSFT, KC_Z,    KC_X,    KC_C,     KC_V,   KC_B,    KC_N,  KC_M, KC_COMMA, KC_DOT, RSFT_T(KC_SLASH), \
      KC_LCTL, KC_LGUI, KC_LALT, LT(_FNL, KC_SPC), LT(_FNR, KC_SPC), KC_SLASH, XXXXXXX, XXXXXXX\
    ),
  [_FNL] = LAYOUT( \
      _______, RESET, KC_KP_ASTERISK, KC_KP_MINUS,KC_7,    KC_8,   KC_9, _______, _______, _______, KC_EQUAL, KC_MINUS, \
      _______, _______,   KC_KP_SLASH,   KC_KP_PLUS,  KC_4,  KC_5,  KC_6, KC_LBRACKET, KC_RBRACKET, KC_BSLASH, KC_SCOLON, \
      _______,   _______,   KC_KP_DOT,      KC_0,     KC_1,  KC_2,  KC_3, KC_SCOLON, KC_QUOTE, KC_UP, _______, \
      _______, _______, _______,                  _______,               _______, KC_LEFT, KC_DOWN, KC_RIGHT \
      ),
  
  [_FNR] = LAYOUT( \
      /* KC_GRAVE, KC_EXLM, KC_AT,  KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______, \ */
      KC_GRAVE, KC_1, KC_2,   KC_3, KC_4,  KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, _______, \
      _______, KC_F1,   KC_F2,   KC_F3,  KC_INS,  KC_HOME,  KC_PGUP, KC_F7, KC_F8, KC_F9, _______, \
      _______,   KC_F4,   KC_F5,   KC_F6,  KC_DEL,  KC_END,  KC_PGDN, KC_F10, KC_F11, KC_F12, _______, \
      _______, _______, _______, _______, _______, _______, _______, _______ \
      ),

  [_NUM] = LAYOUT( \
      _______, _______, _______,   _______, _______,  _______, KC_KP_SLASH, KC_7, KC_8, KC_9, KC_KP_MINUS, _______, \
      _______, _______,   _______,   _______,  _______,  _______,  KC_KP_ASTERISK, KC_4, KC_5, KC_6, KC_KP_PLUS, \
      _______,   _______,   _______,   _______,  _______, _______,_______,   KC_1, KC_2, KC_3, _______, \
      _______, _______, _______, _______, KC_0, KC_DOT, _______, _______ \
      ),
  [_ARROW] = LAYOUT( \
      _______, _______, KC_UP,   _______, _______,  _______, _______, _______, _______, _______, _______, _______, \
      _______, KC_LEFT,   KC_DOWN,   KC_RIGHT,  _______,  _______,  _______, _______, _______, _______, _______, \
      _______,   _______,   _______,   _______,  _______,  _______,  _______, _______, _______, _______, _______, \
      _______, _______, _______, _______, _______, _______, _______, _______ \
      ),
  [_FUNk] = LAYOUT( \
      _______, KC_F1, KC_F2,   KC_F3, KC_F4,  _______, _______, _______, _______, _______, _______, _______, \
      _______, KC_F5,   KC_F6,   KC_F7,  KC_F8,  _______,  _______, _______, _______, _______, _______, \
      _______,   KC_F9,   KC_F10,   KC_F11,  KC_F12,  _______,  _______, _______, _______, _______, _______, \
      _______, _______, _______, _______, _______, _______, _______, _______ \
      ),

  // All transparent
      /* _______, _______, _______,   _______, _______,  _______, _______, _______, _______, _______, _______, _______, \ */
      /* _______, _______,   _______,   _______,  _______,  _______,  _______, _______, _______, _______, _______, \ */
      /* _______,   _______,   _______,   _______,  _______,  _______,  _______, _______, _______, _______, _______, \ */
      /* _______, _______, _______, _______, _______, _______, _______, _______ \ */

  // OLD
  /* Function Layer 1 HHKB style
   * ,-----------------------------------------------------------.
   * |   ~  |   !   |  @  | # | $ | % | ^ | & | * | ( | ) | Bkspc|
   * |-----------------------------------------------------------|
   * |   F1   | F2 | F3 | F4 | F5 |  F6 | _ | + | [ | ] |  Pipe  |
   * |-----------------------------------------------------------|
   * |    F7    | F8 | F9 |  F10  |  F11 |  F12 | End|PgDn| ↓ |     |    |
   * |-----------------------------------------------------------|
   * |     |    |     |           |             | Stop| App|     |
   * `-----------------------------------------------------------'
   */



};




/* enum function_id { */
/*     LAUNCH, */
/*     RGBLED_TOGGLE, */
/* }; */

/* const uint16_t PROGMEM fn_actions[] = { */
/* 	[0]  = ACTION_LAYER_TAP_KEY(_LOWER, KC_SPC), */
/* 	[1]  = ACTION_LAYER_TAP_KEY(_RAISE, KC_SPC), */
/* 	[2]  = ACTION_LAYER_TAP_KEY(_ADJUST, KC_LGUI), */
/*  */
/* }; */




const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function

  return MACRO_NONE;
};




bool process_record_user(uint16_t keycode, keyrecord_t *record) {

  switch (keycode) {

    case FNL:
      if (record->event.pressed) {
        layer_on(_FNL);
      } else {
        layer_off(_FNL);
      }
      return false;
      break;
    case FNR:
      if (record->event.pressed) {
        layer_on(_FNR);
      } else {
        layer_off(_FNR);
      }
      return false;
      break;
  }
  return true;
}
