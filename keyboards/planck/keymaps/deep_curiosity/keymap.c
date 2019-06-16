/* Copyright 2015-2017 Jack Humbert
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
#include "muse.h"

// #define GRID_LAYOUT

extern keymap_config_t keymap_config;

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

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAK,
  DVORAK,
  PLOVER,
  BACKLIT,
  EXT_PLV
};

#define NUMERIC MO(_NUMERIC)
#define SYMBOLIC MO(_SYMBOLIC)
#define NAVI MO(_NAVI)
// #define ADJUST MO(_ADJUST)
#define _LOWER _NUMERIC
#define _RAISE _SYMBOLIC

// Key aliases
#define ___ KC_TRNS
#define _x_ KC_NO


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Ctrl |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  | NAVI | Enter|
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  | Shift|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Adjust|  OS  | Alt  | Ctrl |Lower |    Space    |Raise | Ctrl |  Alt |  OS  |Adjust|
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_planck_mit(
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,   LT(_NAVI, KC_SCLN), CTL_T(KC_ENT),
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,  KC_RSFT,
    NAVI, KC_LGUI,  KC_LCTL,   KC_LALT, NUMERIC,   KC_SPC,  SYMBOLIC,   KC_LALT, KC_RCTL, KC_RGUI, LT(_NAVI, KC_ENT)
),

/* Numeric
 * ,-----------------------------------------------------------------------------------.
 * |  Esc |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |  Tr  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |  Tr  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  Tr  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |  Tr  |      |      |      |      |      |      |      |  Tr  |  Tr  |  Tr  |  Tr  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  Tr  | Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_NUMERIC] = LAYOUT_planck_mit(
    KC_ESC,  KC_1,  KC_2,  KC_3,  KC_4,  KC_5,  KC_6,  KC_7,  KC_8,  KC_9,  KC_0,  ___,
    ___,  KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F6,  KC_F7,  KC_F8,  KC_F9,  KC_F10,  ___,
    ___,  _x_,  _x_,  _x_,  _x_,  _x_,  _x_,  _x_,  ___,  ___,  ___,  ___,
    ___,  ___,  ___,  ___,  ___,  KC_BSPC,  ___,  ___,  ___,  ___,  ___
),

/* Symbolic
 * ,-----------------------------------------------------------------------------------.
 * |  `   |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |  -_  |  =+  |  \|  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |   <  |   [  |   {  |   (  |      |      |   )  |   }  |   ]  |   >  |  '"  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |   +  |      |      |   =  |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_SYMBOLIC] = LAYOUT_planck_mit(
    KC_GRV,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR,    KC_ASTR,    KC_MINS,  KC_PLUS,  KC_BSLS,
    ___,  KC_LABK,  KC_LBRC,  KC_LCBR,  KC_LPRN,  _x_,  _x_,  KC_RPRN,  KC_RCBR,  KC_RBRC,  KC_RABK,  KC_QUOT,
    ___,  _x_,  _x_,  _x_,  KC_PLUS,  _x_,  _x_,  KC_EQL,  _x_,  _x_,  _x_,  ___,
    ___,  ___,  ___,  ___,  ___,  KC_DEL,  ___,  ___,  ___,  ___,  ___
),


/* Adjust
 * ,-----------------------------------------------------------------------------------.
 * |      | Reset| Debug|      |      |      |      |      |      |      |      |  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |Aud on|Audoff|AGnorm|AGswap|QWERTY|      |      |PLOVER|      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|Musoff|MIDIon|MIDIof|      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
*/
[_ADJUST] = LAYOUT_planck_mit(
    ___, RESET,   DEBUG,   RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD,  RGB_VAI, RGB_VAD, KC_DEL ,
    ___, ___, MU_MOD,  AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, QWERTY,  ___,  ___,  PLOVER,  ___,
    ___, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  TERM_ON, TERM_OFF, ___, ___, ___,
    ___, ___, ___, ___, ___, ___, ___, ___,  ___, ___, ___
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
[_NAVI] = LAYOUT_planck_mit(
    KC_GRV, _x_, KC_BTN1,  KC_MS_U,  KC_BTN2,  KC_WH_U, KC_PGUP,  KC_HOME,  KC_UP,  KC_END,  ___,  ___,
    ___,  _x_, KC_MS_L,  KC_MS_D,  KC_MS_R,  KC_WH_D, KC_PGDN,  KC_LEFT,  KC_DOWN,  KC_RGHT,  ___,  ___,
    ___,  _x_,  _x_,  _x_,  _x_,  _x_,  _x_,  _x_,  _x_,  _x_,  _x_,  ___,
    ___,  ___,  ___,  ___,  ___,  ___,  ___,  ___,  ___,  ___,  ___
)

};

#ifdef AUDIO_ENABLE
  float plover_song[][2]     = SONG(PLOVER_SOUND);
  float plover_gb_song[][2]  = SONG(PLOVER_GOODBYE_SOUND);
#endif

uint32_t layer_state_set_user(uint32_t state) {
  return update_tri_layer_state(state, _NUMERIC, _SYMBOLIC, _ADJUST);
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
    case PLOVER:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          stop_all_notes();
          PLAY_SONG(plover_song);
        #endif
        layer_off(_RAISE);
        layer_off(_LOWER);
        layer_off(_ADJUST);
        layer_on(_PLOVER);
        if (!eeconfig_is_enabled()) {
            eeconfig_init();
        }
        keymap_config.raw = eeconfig_read_keymap();
        keymap_config.nkro = 1;
        eeconfig_update_keymap(keymap_config.raw);
      }
      return false;
      break;
  }
  return true;
}

bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

void encoder_update(bool clockwise) {
  if (muse_mode) {
    if (IS_LAYER_ON(_RAISE)) {
      if (clockwise) {
        muse_offset++;
      } else {
        muse_offset--;
      }
    } else {
      if (clockwise) {
        muse_tempo+=1;
      } else {
        muse_tempo-=1;
      }
    }
  } else {
    if (clockwise) {
      #ifdef MOUSEKEY_ENABLE
        register_code(KC_MS_WH_DOWN);
        unregister_code(KC_MS_WH_DOWN);
      #else
        register_code(KC_PGDN);
        unregister_code(KC_PGDN);
      #endif
    } else {
      #ifdef MOUSEKEY_ENABLE
        register_code(KC_MS_WH_UP);
        unregister_code(KC_MS_WH_UP);
      #else
        register_code(KC_PGUP);
        unregister_code(KC_PGUP);
      #endif
    }
  }
}

void dip_update(uint8_t index, bool active) {
  switch (index) {
    case 0:
      if (active) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(plover_song);
        #endif
        layer_on(_ADJUST);
      } else {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(plover_gb_song);
        #endif
        layer_off(_ADJUST);
      }
      break;
    case 1:
      if (active) {
        muse_mode = true;
      } else {
        muse_mode = false;
        #ifdef AUDIO_ENABLE
          stop_all_notes();
        #endif
      }
   }
}

void matrix_scan_user(void) {
  #ifdef AUDIO_ENABLE
    if (muse_mode) {
      if (muse_counter == 0) {
        uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
        if (muse_note != last_muse_note) {
          stop_note(compute_freq_for_midi_note(last_muse_note));
          play_note(compute_freq_for_midi_note(muse_note), 0xF);
          last_muse_note = muse_note;
        }
      }
      muse_counter = (muse_counter + 1) % muse_tempo;
    }
  #endif
}

bool music_mask_user(uint16_t keycode) {
  switch (keycode) {
    case NUMERIC:
    case SYMBOLIC:
      return false;
    default:
      return true;
  }
}
