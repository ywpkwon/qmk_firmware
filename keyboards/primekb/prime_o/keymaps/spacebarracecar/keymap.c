#include QMK_KEYBOARD_H
#include "spacebarracecar.h"

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

#define LEFTNUM

enum layers {
  _BASE,
  _LOWER,
  _RAISE,
  _GAME = _NAV+1
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

#ifndef LEFTNUM
/* Base
,---------------------------------------------------------------------------------------------------------------------------------------------------------------.
|`        |1        |2        |3        |4        |5        |6        |7        |8        |9        |0        |\        |Numlock  |/        |*        |=        |
|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
|Tab      |Q        |W        |E        |R        |T        |Z        |U        |I        |O        |P        |Backspace|7        |8        |9        |-        |
|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
|Esc/Nav  |A        |S        |D        |F        |G        |H        |J        |K        |L        |;        |'        |4        |5        |6        |+        |
|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
|(/LShift |Y        |X        |C        |V        |B        |N        |M        |,        |.        |/        |)/RShift |1        |2        |3        |Enter    |
|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
|RCtrl    |         |Alt      |Win      |Lower    |Space    |Enter    |Raise    |Win      |AltGr    |         |LCtrl    |00       |0        |.        |Tab      |
`---------------------------------------------------------------------------------------------------------------------------------------------------------------'
*/

[_BASE] = LAYOUT(
  CU_GRV,   DE_1,     DE_2,     CU_3,     DE_4,     DE_5,     CU_6,     CU_7,     CU_8,     CU_9,     CU_0,     CU_BSLS,  KC_NLCK,  KC_PSLS,  KC_PAST,  KC_PMNS,
  KC_TAB,   DE_Q,     DE_W,     DE_E,     DE_R,     DE_T,     CU_Z,     DE_U,     DE_I,     DE_O,     DE_P,     KC_BSPC,  KC_P7,    KC_P8,    KC_P9,    KC_PPLS,
  CU_NAV,   DE_A,     DE_S,     DE_D,     DE_F,     DE_G,     DE_H,     DE_J,     DE_K,     DE_L,     CU_SCLN,  CU_QUOT,  KC_P4,    KC_P5,    KC_P6,    KC_PEQL,
  CU_LSFT,  CU_Y,     DE_X,     DE_C,     DE_V,     DE_B,     DE_N,     DE_M,     CU_COMM,  CU_DOT,   CU_SLSH,  CU_RSFT,  KC_P1,    KC_P2,    KC_P3,    KC_PENT,
  KC_LCTL,  XXXXXXX,  KC_LGUI,  KC_LALT,  LOWER,    KC_SPC,   KC_ENT,   RAISE,    KC_RALT,  KC_RGUI,  KC_APP,   KC_RCTL,  KC_P00,   KC_P0,    KC_PDOT,  KC_TAB
),

/* Lower
,---------------------------------------------------------------------------------------------------------------------------------------------------------------.
|`        |1        |2        |3        |4        |5        |6        |7        |8        |9        |0        |         |Numlock  |/        |*        |-        |
|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
|~        |!        |"        |#        |$        |%        |^        |&        |*        |(        |)        |         |7        |8        |9        |+        |
|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
|         |@        |Strg+X   |Strg+C   |Strg+V   |         |         |_        |+        |{        |}        ||        |4        |5        |6        |=        |
|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
|         |?        |         |         |         |         |         |         |         |         |         |         |1        |2        |3        |Enter    |
|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
|         |         |         |         |         |         |         |         |         |         |         |         |00       |0        |.        |Tab      |
`---------------------------------------------------------------------------------------------------------------------------------------------------------------'
*/

[_LOWER] = LAYOUT(
  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
  DE_TILD,  DE_EXLM,  DE_DQOT,  DE_HASH,  DE_DLR,   DE_PERC,  CU_CIRC,  DE_AMPR,  DE_ASTR,  DE_LPRN,  DE_RPRN,  _______,  _______,  _______,  _______,  _______,
  _______,  DE_AT,    CTRLX,    CTRLC,    CTRLV,    XXXXXXX,  XXXXXXX,  DE_UNDS,  DE_PLUS,  DE_LCBR,  DE_RCBR,  DE_PIPE,  _______,  _______,  _______,  _______,
  _______,  DE_EURO,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______
),

/* Raise
,---------------------------------------------------------------------------------------------------------------------------------------------------------------.
|`        |1        |2        |3        |4        |5        |6        |7        |8        |9        |0        |         |Numlock  |/        |*        |-        |
|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
|`        |1        |2        |3        |4        |5        |6        |7        |8        |9        |0        |         |7        |8        |9        |+        |
|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
|         |F1       |F2       |F3       |F4       |F5       |F6       |-        |=        |[        |]        |\        |4        |5        |6        |=        |
|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
|         |F7       |F8       |F9       |F10      |F11      |F12      |         |         |         |         |         |1        |2        |3        |Enter    |
|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
|         |         |         |         |         |         |         |         |         |         |         |         |00       |0        |.        |Tab      |
`---------------------------------------------------------------------------------------------------------------------------------------------------------------'
*/

[_RAISE] = LAYOUT(
  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
  CU_GRV,   DE_1,     DE_2,     CU_3,     DE_4,     DE_5,     CU_6,     CU_7,     CU_8,     CU_9,     CU_0,     _______,  _______,  _______,  _______,  _______,
  _______,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    DE_MINS,  CU_EQL,   CU_LBRC,  CU_RBRC,  CU_BSLS,  _______,  _______,  _______,  _______,
  _______,  KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______
),

/* Deadkey
,---------------------------------------------------------------------------------------------------------------------------------------------------------------.
|         |         |         |         |         |         |         |         |         |         |         |         |Numlock  |/        |*        |-        |
|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
|         |         |         |         |         |         |         |Ü        |         |Ö        |         |         |7        |8        |9        |+        |
|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
|         |Ä        |ß        |         |         |         |         |         |         |         |         |         |4        |5        |6        |=        |
|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
|         |         |         |         |         |         |         |         |         |         |         |         |1        |2        |3        |Enter    |
|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
|         |         |         |         |         |"        |"        |         |         |         |         |         |00       |0        |.        |Tab      |
`---------------------------------------------------------------------------------------------------------------------------------------------------------------'
*/

[_DEADKEY] = LAYOUT(
  CU_ED,    CU_ED,    CU_ED,    CU_ED,    CU_ED,    CU_ED,    CU_ED,    CU_ED,    CU_ED,    CU_ED,    CU_ED,    CU_ED,    _______,  _______,  _______,  _______,
  KC_TAB,   CU_ED,    CU_ED,    CU_ED,    CU_ED,    CU_ED,    CU_ED,    CU_UE,    CU_ED,    CU_OE,    CU_ED,    _______,  _______,  _______,  _______,  _______,
  _______,  CU_AE,    CU_SS,    CU_ED,    CU_ED,    CU_ED,    CU_ED,    CU_ED,    CU_ED,    CU_ED,    CU_ED,    CU_DDQ,   _______,  _______,  _______,  _______,
  _______,  CU_ED,    CU_ED,    CU_ED,    CU_ED,    CU_ED,    CU_ED,    CU_ED,    CU_ED,    CU_ED,    CU_ED,    _______,  _______,  _______,  _______,  _______,
  _______,  _______,  _______,  _______,  _______,  CU_DDQ,   CU_DDQ,   _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______
),

/* Navigation
,---------------------------------------------------------------------------------------------------------------------------------------------------------------.
|Escape   |         |         |         |         |         |         |         |         |         |         |         |Numlock  |/        |*        |-        |
|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
|ESCT     |PageDown |Up       |PageUp   |Home     |         |         |         |Win+Up   |         |         |Del      |7        |8        |9        |+        |
|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
|         |Left     |Down     |Right    |End      |         |         |Win+Left |Win+Down |Win+Right|         |Enter    |4        |5        |6        |=        |
|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
|         |Prev     |Pause    |Next     |LowerVol |RaiseVol |Mute     |         |         |         |         |         |1        |2        |3        |Enter    |
|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
|RESET    |         |         |         |         |         |         |         |         |         |         |Game     |00       |0        |.        |Tab      |
`---------------------------------------------------------------------------------------------------------------------------------------------------------------'
*/

[_NAV] = LAYOUT(
  KC_ESC,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  _______,  _______,  _______,  _______,
  CU_ESCT,  KC_PGDN,  KC_UP,    KC_PGUP,  KC_HOME,  XXXXXXX,  XXXXXXX,  XXXXXXX,  GUIU,     XXXXXXX,  XXXXXXX,  KC_DEL,   _______,  _______,  _______,  _______,
  _______,  KC_LEFT,  KC_DOWN,  KC_RGHT,  KC_END,   XXXXXXX,  XXXXXXX,  GUIL,     GUID,     GUIR,     XXXXXXX,  KC_ENT,   _______,  _______,  _______,  _______,
  _______,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_VOLD,  KC_VOLU,  KC_MUTE,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  _______,  _______,  _______,  _______,  _______,
  RESET,    _______,  _______,  _______,  _______,  KC_SPC,   KC_ENT,   _______,  _______,  _______,  _______,  CU_GAME,  _______,  _______,  _______,  _______
),

// Can be used to place macros on the numpad
[_GAME] = LAYOUT(
  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______
)
#endif

#ifdef LEFTNUM
/* Base
,---------------------------------------------------------------------------------------------------------------------------------------------------------------.
|-        |*        |/        |Numlock  |`        |1        |2        |3        |4        |5        |6        |7        |8        |9        |0        |\        |
|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
|+        |7        |8        |9        |Tab      |Q        |W        |E        |R        |T        |Z        |U        |I        |O        |P        |Backspace|
|---------+---------+---------+---------|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
|=        |4        |5        |6        |Esc/Nav  |A        |S        |D        |F        |G        |H        |J        |K        |L        |;        |'        |
|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
|Enter    |1        |2        |3        |(/LShift |Y        |X        |C        |V        |B        |N        |M        |,        |.        |/        |)/RShift |
|---------+---------+---------+---------|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
|Backspace|.        |0        |00       |RCtrl    |         |Alt      |Win      |Lower    |Space    |Enter    |Raise    |Win      |AltGr    |         |LCtrl    |
`---------------------------------------------------------------------------------------------------------------------------------------------------------------'
*/

[_BASE] = LAYOUT(
  KC_PMNS,  KC_PAST,  KC_PSLS,  KC_NLCK,  CU_GRV,   DE_1,     DE_2,     CU_3,     DE_4,     DE_5,     CU_6,     CU_7,     CU_8,     CU_9,     CU_0,     CU_BSLS,
  KC_PPLS,  KC_P7,    KC_P8,    KC_P9,    KC_TAB,   DE_Q,     DE_W,     DE_E,     DE_R,     DE_T,     CU_Z,     DE_U,     DE_I,     DE_O,     DE_P,     KC_BSPC,
  KC_PEQL,  KC_P4,    KC_P5,    KC_P6,    CU_NAV,   DE_A,     DE_S,     DE_D,     DE_F,     DE_G,     DE_H,     DE_J,     DE_K,     DE_L,     CU_SCLN,  CU_QUOT,
  KC_PENT,  KC_P1,    KC_P2,    KC_P3,    CU_LSFT,  CU_Y,     DE_X,     DE_C,     DE_V,     DE_B,     DE_N,     DE_M,     CU_COMM,  CU_DOT,   CU_SLSH,  CU_RSFT,
  KC_BSPC,  KC_PDOT,  KC_P0,    KC_P00,   KC_LCTL,  XXXXXXX,  KC_LGUI,  KC_LALT,  LOWER,    KC_SPC,   KC_ENT,   RAISE,    KC_RALT,  KC_RGUI,  KC_APP,   KC_RCTL
),

/* Lower
,---------------------------------------------------------------------------------------------------------------------------------------------------------------.
|-        |*        |/        |Numlock  |`        |1        |2        |3        |4        |5        |6        |7        |8        |9        |0        |         |
|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
|+        |7        |8        |9        |~        |!        |"        |#        |$        |%        |^        |&        |*        |(        |)        |         |
|---------+---------+---------+---------|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
|=        |4        |5        |6        |         |@        |Strg+X   |Strg+C   |Strg+V   |         |         |_        |+        |{        |}        ||        |
|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
|Enter    |1        |2        |3        |         |?        |         |         |         |         |         |         |         |         |         |         |
|---------+---------+---------+---------|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
|Backspace|.        |0        |00       |         |         |         |         |         |         |         |         |         |         |         |         |
`---------------------------------------------------------------------------------------------------------------------------------------------------------------'
*/

[_LOWER] = LAYOUT(
  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
  _______,  _______,  _______,  _______,  DE_TILD,  DE_EXLM,  DE_DQOT,  DE_HASH,  DE_DLR,   DE_PERC,  CU_CIRC,  DE_AMPR,  DE_ASTR,  DE_LPRN,  DE_RPRN,  _______,
  _______,  _______,  _______,  _______,  _______,  DE_AT,    CTRLX,    CTRLC,    CTRLV,    XXXXXXX,  XXXXXXX,  DE_UNDS,  DE_PLUS,  DE_LCBR,  DE_RCBR,  DE_PIPE,
  _______,  _______,  _______,  _______,  _______,  DE_EURO,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  _______,  _______,  _______,  _______,
  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______
),

/* Raise
,---------------------------------------------------------------------------------------------------------------------------------------------------------------.
|-        |*        |/        |Numlock  |`        |1        |2        |3        |4        |5        |6        |7        |8        |9        |0        |         |
|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
|+        |7        |8        |9        |`        |1        |2        |3        |4        |5        |6        |7        |8        |9        |0        |         |
|---------+---------+---------+---------|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
|=        |4        |5        |6        |         |F1       |F2       |F3       |F4       |F5       |F6       |-        |=        |[        |]        |\        |
|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
|Enter    |1        |2        |3        |         |F7       |F8       |F9       |F10      |F11      |F12      |         |         |         |         |         |
|---------+---------+---------+---------|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
|Backspace|.        |0        |00       |         |         |         |         |         |         |         |         |         |         |         |         |
`---------------------------------------------------------------------------------------------------------------------------------------------------------------'
*/

[_RAISE] = LAYOUT(
  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
  _______,  _______,  _______,  _______,  CU_GRV,   DE_1,     DE_2,     CU_3,     DE_4,     DE_5,     CU_6,     CU_7,     CU_8,     CU_9,     CU_0,     _______,
  _______,  _______,  _______,  _______,  _______,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    DE_MINS,  CU_EQL,   CU_LBRC,  CU_RBRC,  CU_BSLS,
  _______,  _______,  _______,  _______,  _______,  KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   _______,  _______,  _______,  _______,  _______,
  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______
),

/* Deadkey
,---------------------------------------------------------------------------------------------------------------------------------------------------------------.
|-        |*        |/        |Numlock  |         |         |         |         |         |         |         |         |         |         |         |         |
|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
|+        |7        |8        |9        |         |         |         |         |         |         |         |Ü        |         |Ö        |         |         |
|---------+---------+---------+---------|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
|=        |4        |5        |6        |         |Ä        |ß        |         |         |         |         |         |         |         |         |         |
|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
|Enter    |1        |2        |3        |         |         |         |         |         |         |         |         |         |         |         |         |
|---------+---------+---------+---------|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
|Backspace|.        |0        |00       |         |         |         |         |         |"        |"        |         |         |         |         |         |
`---------------------------------------------------------------------------------------------------------------------------------------------------------------'
*/

[_DEADKEY] = LAYOUT(
  _______,  _______,  _______,  _______,  CU_ED,    CU_ED,    CU_ED,    CU_ED,    CU_ED,    CU_ED,    CU_ED,    CU_ED,    CU_ED,    CU_ED,    CU_ED,    CU_ED,
  _______,  _______,  _______,  _______,  KC_TAB,   CU_ED,    CU_ED,    CU_ED,    CU_ED,    CU_ED,    CU_ED,    CU_UE,    CU_ED,    CU_OE,    CU_ED,    _______,
  _______,  _______,  _______,  _______,  _______,  CU_AE,    CU_SS,    CU_ED,    CU_ED,    CU_ED,    CU_ED,    CU_ED,    CU_ED,    CU_ED,    CU_ED,    CU_DDQ,
  _______,  _______,  _______,  _______,  _______,  CU_ED,    CU_ED,    CU_ED,    CU_ED,    CU_ED,    CU_ED,    CU_ED,    CU_ED,    CU_ED,    CU_ED,    _______,
  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  CU_DDQ,   CU_DDQ,   _______,  _______,  _______,  _______,  _______
),

/* Navigation
,---------------------------------------------------------------------------------------------------------------------------------------------------------------.
|-        |*        |/        |Numlock  |Escape   |         |         |         |         |         |         |         |         |         |         |         |
|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
|+        |7        |8        |9        |ESCT     |PageDown |Up       |PageUp   |Home     |         |         |         |Win+Up   |         |         |Del      |
|---------+---------+---------+---------|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
|=        |4        |5        |6        |         |Left     |Down     |Right    |End      |         |         |Win+Left |Win+Down |Win+Right|         |Enter    |
|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
|Enter    |1        |2        |3        |         |Prev     |Pause    |Next     |LowerVol |RaiseVol |Mute     |         |         |         |         |         |
|---------+---------+---------+---------|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
|Backspace|.        |0        |00       |RESET    |         |         |         |         |         |         |         |         |         |         |Game     |
`---------------------------------------------------------------------------------------------------------------------------------------------------------------'
*/

[_NAV] = LAYOUT(
  _______,  _______,  _______,  _______,  KC_ESC,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
  _______,  _______,  _______,  _______,  CU_ESCT,  KC_PGDN,  KC_UP,    KC_PGUP,  KC_HOME,  XXXXXXX,  XXXXXXX,  XXXXXXX,  GUIU,     XXXXXXX,  XXXXXXX,  KC_DEL,
  _______,  _______,  _______,  _______,  _______,  KC_LEFT,  KC_DOWN,  KC_RGHT,  KC_END,   XXXXXXX,  XXXXXXX,  GUIL,     GUID,     GUIR,     XXXXXXX,  KC_ENT,
  _______,  _______,  _______,  _______,  _______,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_VOLD,  KC_VOLU,  KC_MUTE,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  _______,
  _______,  _______,  _______,  _______,  RESET,    _______,  _______,  _______,  _______,  KC_SPC,   KC_ENT,   _______,  _______,  _______,  _______,  CU_GAME
),

// Can be used to place macros on the numpad
[_GAME] = LAYOUT(
  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______
)
#endif

};

bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
switch (keycode) {
  case MO(_LOWER):
    if (game){
      if(record->event.pressed) {
        register_code(KC_SPC);
      } else {
        unregister_code(KC_SPC);
      }
      return false;
    } else {
      return true;
    }
  case CU_GAME:
    if(record->event.pressed) {
      if (game)
        layer_on(_GAME);
      else
        layer_off(_GAME);
    }
    return false;
  default:
    return true;
  }
}