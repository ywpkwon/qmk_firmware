#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
// #define _QWERTY 0
// #define _COLEMAK 1
// #define _DVORAK 2
// #define _LOWER 3
// #define _RAISE 4
// #define _ADJUST 16

enum planck_layers {
  _QWERTY,
  // _COLEMAK,
  // _LOWER,
  // _RAISE,
  _NUMERIC,
  _SYMBOLIC,
  _NAVI,
  _PLOVER,
  _ADJUST
};

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAK,
  DVORAK,
  // LOWER,
  // RAISE,
  ADJUST,
};

// Tap Dance Declarations
enum {
  TD_TAB_GRV = 0
};

#define NUMERIC MO(_NUMERIC)
#define SYMBOLIC MO(_SYMBOLIC)
#define NAVI MO(_NAVI)
#define ADJUST MO(_ADJUST)
#define _LOWER _NUMERIC
#define _RAISE _SYMBOLIC

// Key aliases
#define ___ KC_TRNS
#define xxx KC_NO
#define KC_ALTKN ALT_T(KC_LANG1)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Ctrl |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  | NAVI | Enter|
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  | Shift|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Adjust|  OS  | Alt  | Ctrl |Lower |    Space    |Raise | Left | Down |  Up  | Right|
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_ortho_4x12( \
    TD(TD_TAB_GRV),  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    CTL_T(KC_ESC), LT(_NAVI, KC_A),    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,   LT(_NAVI, KC_SCLN), CTL_T(KC_ENT),
    OSM(MOD_LSFT), KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,  OSM(MOD_LSFT),
    ADJUST, KC_LGUI,  KC_LCTL,   KC_LALT, LT(_NUMERIC, KC_SPC),   LT(_NUMERIC, KC_SPC),  LT(_SYMBOLIC, KC_BSPC),  LT(_SYMBOLIC, KC_BSPC),   KC_LEFT, KC_DOWN, KC_UP, KC_RGHT
),


/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |  Esc |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |  Tr  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |  Tr  |  F1  |  F2  |  F3  |  F4  |  F5  |      |   4  |   5  |   6  |  Tr  |  Tr  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |  Tr  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |   1  |   2  |   3  |  Tr  |  Tr  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  Tr  |  Tr  |  Tr  |  Tr  |Lower |   BkSpace   |Raise |   0  |   .  |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_NUMERIC] = LAYOUT_ortho_4x12( \
    KC_ESC,  KC_1,  KC_2,  KC_3,  KC_4,  KC_5,  KC_6,  KC_7,  KC_8,  KC_9,  KC_0,  ___,
    ___,  KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F11,  KC_4,  KC_5,  KC_6,  ___,  ___,
    ___,  KC_F6,  KC_F7,  KC_F8,  KC_F9,  KC_F10,  KC_F12,  KC_1,  KC_2,  KC_3,  ___,  ___,
    ___,  ___,  ___,  ___,  ___,  ___,  KC_BSPC, KC_BSPC,  KC_0,  KC_DOT,  ___,  ___
),

/* Symbolic
 * ,-----------------------------------------------------------------------------------.
 * |  `   |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |  -_  |  =+  |   \  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |   <  |   [  |   {  |   (  |   '  |   "  |   )  |   }  |   ]  |   >  |   |  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |   +  |      |      |   =  |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |     Del     |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_SYMBOLIC] = LAYOUT_ortho_4x12( \
    KC_GRV,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR,    KC_ASTR,    KC_MINS,  KC_EQL,  KC_BSLS,
    ___,  KC_LABK,  KC_LBRC,  KC_LCBR,  KC_LPRN,  KC_QUOT,  KC_DOUBLE_QUOTE,  KC_RPRN,  KC_RCBR,  KC_RBRC,  KC_RABK,  KC_PIPE,
    ___,  xxx,  xxx,  xxx,  KC_PLUS,  xxx,  xxx,  KC_EQL,  xxx,  xxx,  xxx,  ___,
    ___,  ___,  ___,  KC_ALTKN,  KC_DEL,  KC_DEL,  ___, ___,  ___,  ___,  ___,  ___
),


/* Navi
 * ,-----------------------------------------------------------------------------------.
 * |   `  |      | Mck1 | M-up | Mck2 |ScrllU| Pgup | home |  up  | end  |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      | M-lf | M-dn | M-rg |ScrllD| Pgdn | left | down | rght |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_NAVI] = LAYOUT_ortho_4x12( \
    KC_GRV, xxx, KC_BTN1,  KC_MS_U,  KC_BTN2,  KC_WH_U, KC_PGUP,  KC_HOME,  KC_UP,  KC_END,  ___,  ___,
    ___,  xxx, KC_MS_L,  KC_MS_D,  KC_MS_R,  KC_WH_D, KC_PGDN,  KC_LEFT,  KC_DOWN,  KC_RGHT,  ___,  ___,
    ___,  xxx,  xxx,  xxx,  xxx,  xxx,  xxx,  xxx,  xxx,  xxx,  xxx,  ___,
    ___,  ___,  ___,  ___,  ___,  ___,  ___,  ___,  ___,  ___,  ___,  ___
),


/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |      | Reset|      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |Aud on|Audoff|AGnorm|AGswap|      |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      | Hue+ | Hue- | Sat+ | Sat- | Brt+ | Brt- |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] =  LAYOUT_ortho_4x12( \
  _______, RESET,   BL_TOGG, RGB_TOG, RGB_MODE_FORWARD, RGB_MODE_PLAIN, RGB_MODE_SWIRL, _______, _______, _______, _______, _______, \
  _______, _______, _______, AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, QWERTY,  _______, _______,  _______, _______, \
  _______, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, KC_RALT, _______, _______, _______ \
)

};

#ifdef AUDIO_ENABLE
float tone_qwerty[][2]     = SONG(QWERTY_SOUND);
float tone_dvorak[][2]     = SONG(DVORAK_SOUND);
float tone_colemak[][2]    = SONG(COLEMAK_SOUND);
#endif

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(tone_qwerty);
        #endif
        persistent_default_layer_set(1UL<<_QWERTY);
      }
      return false;
      break;
    case NUMERIC:
      if (record->event.pressed) {
        layer_on(_NUMERIC);
        update_tri_layer(_NUMERIC, _SYMBOLIC, _ADJUST);
      } else {
        layer_off(_NUMERIC);
        update_tri_layer(_LOWER, _SYMBOLIC, _ADJUST);
      }
      return false;
      break;
    case SYMBOLIC:
      if (record->event.pressed) {
        layer_on(_SYMBOLIC);
        update_tri_layer(_NUMERIC, _SYMBOLIC, _ADJUST);
      } else {
        layer_off(_SYMBOLIC);
        update_tri_layer(_NUMERIC, _SYMBOLIC, _ADJUST);
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

// Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_TAB_GRV]  = ACTION_TAP_DANCE_DOUBLE(KC_TAB, KC_GRV)
// Other declarations would go here, separated by commas, if you have them
};
