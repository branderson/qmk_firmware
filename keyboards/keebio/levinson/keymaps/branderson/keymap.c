#include QMK_KEYBOARD_H


// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _COLEMAK 1
#define _DVORAK 2
#define _LOWER 3
#define _RAISE 4
#define _NUMPAD 5
#define _ADJUST 6

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  NUMPAD,
  COLEMAK,
  DVORAK,
  LOWER,
  RAISE,
  ADJUST,
};

#define CTLESC MT(MOD_LCTL, KC_ESC)
#define ALTAB LALT_T(KC_TAB)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------.    .-----------------------------------------.
 * |AltTab|   Q  |   W  |   E  |   R  |   T  |    |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------|    |------+------+------+------+------+------|
 * |CtrEsc|   A  |   S  |   D  |   F  |   G  |    |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|    |------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |    |   N  |   M  |   ,  |   .  |   /  | Shift|
 * |------+------+------+------+-------------|    |-------------+------+------+------+------|
 * | Ctrl |Super | Alt  |      |Lower |Space |    |Enter |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------'    '-----------------------------------------'
 */
[_QWERTY] = LAYOUT_ortho_4x12(
  ALTAB,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
  CTLESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
  KC_LCTL, KC_LGUI, KC_LALT, _______, LOWER, KC_SPC,  KC_ENT,    RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),

/* Colemak
 * ,-----------------------------------------.    .-----------------------------------------.
 * |AltTab|   Q  |   W  |   F  |   P  |   G  |    |   J  |   L  |   U  |   Y  |   ;  | Bksp |
 * |------+------+------+------+------+------|    |------+------+------+------+------+------|
 * |CtrEsc|   A  |   R  |   S  |   T  |   D  |    |   H  |   N  |   E  |   I  |   O  |  "   |
 * |------+------+------+------+------+------|    |------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |    |   K  |   M  |   ,  |   .  |   /  | Shift|
 * |------+------+------+------+-------------|    |-------------+------+------+------+------|
 * | Ctrl |Super | Alt  |      |Lower |Space |    |Enter |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------'    '-----------------------------------------'
 */
[_COLEMAK] = LAYOUT_ortho_4x12(
  ALTAB,   KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSPC,
  CTLESC,  KC_A,    KC_R,    KC_S,    KC_T,    KC_D,    KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT,
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
  KC_LCTL, KC_LGUI, KC_LALT, _______, LOWER, KC_SPC,  KC_ENT,    RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),

/* Dvorak
 * ,-----------------------------------------.    .-----------------------------------------.
 * |AltTab|   "  |   ,  |   .  |   P  |   Y  |    |   F  |   G  |   C  |   R  |   L  | Bksp |
 * |------+------+------+------+------+------|    |------+------+------+------+------+------|
 * |CtrEsc|   A  |   O  |   E  |   U  |   I  |    |   D  |   H  |   T  |   N  |   S  |  /   |
 * |------+------+------+------+------+------|    |------+------+------+------+------+------|
 * | Shift|   ;  |   Q  |   J  |   K  |   X  |    |   B  |   M  |   W  |   V  |   Z  | Shift|
 * |------+------+------+------+-------------|    |-------------+------+------+------+------|
 * | Ctrl |Super | Alt  |      |Lower |Space |    |Enter |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------'    '-----------------------------------------'
 */
[_DVORAK] = LAYOUT_ortho_4x12(
  ALTAB,   KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,    KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_BSPC,
  CTLESC,     KC_A,    KC_O,   KC_E,  KC_U,    KC_I,    KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_SLSH,
  KC_LSFT, KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,    KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_RSFT,
  KC_LCTL, KC_LGUI, KC_LALT, _______, LOWER, KC_SPC,  KC_ENT,    RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),

/* Lower
 * ,-----------------------------------------.    .-----------------------------------------.
 * |AltTab|   1  |   2  |   3  |   4  |   5  |    |   6  |   7  |   8  |   9  |   0  | Del  |
 * |------+------+------+------+------+------|    |------+------+------+------+------+------|
 * |CtrEsc|  F1  |  F2  |  F3  |  F4  |  F5  |    | Left | Down |  Up  |Right |   \  |  |   |
 * |------+------+------+------+------+------|    |------+------+------+------+------+------|
 * | Shift|  F6  |  F7  |  F8  |  F9  |  F10 |    |      |ISO ~ |ISO | | Prev | Next | Play |
 * |------+------+------+------+-------------|    |-------------+------+------+------+------|
 * |      |  F11 |  F12 |   `  |      |      |    | Bksp |      |      | Vol+ | Vol- | Mute |
 * `-----------------------------------------'    '-----------------------------------------'
 */
[_LOWER] = LAYOUT_ortho_4x12(
   ALTAB,     KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_DEL,
   CTLESC,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5, KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, KC_BSLS, KC_PIPE,
   KC_LSFT,  KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10, _______,S(KC_NUHS),S(KC_NUBS),KC_MPRV,KC_MNXT,KC_MPLY,
   _______, KC_F11,  KC_F12,  KC_GRV, _______, _______,  KC_BSPC, _______, _______, KC_VOLU, KC_VOLD, KC_MUTE
),

/* Raise (Symbols)
 * ,-----------------------------------------.    .------------------------------------------.
 * |AltTab|   !  |   @  |   {  |   }  |   $  |    |   `  |    7  |   8  |   9  |   *  |NumLck|
 * |------+------+------+------+------+------|    |------+-------+------+------+------+------|
 * | Caps |   =  |   _  |   (  |   )  |   #  |    |   |  |    4  |   5  |   6  |   +  | PgUp |
 * |------+------+------+------+------+------|    |------+-------+------+------+------+------|
 * | Home |   %  |   ^  |   [  |   ]  |   ~  |    |   &  |    1  |   2  |   3  |   -  |PgDown|
 * |------+------+------+------+------+------|    |------+------+-------+------+------+------|
 * | End  |      |      |   `  |Adjust|      |    |Numpad|       |   0  |   .  |   /  |Enter |
 * `-----------------------------------------'    '------------------------------------------'
 */
[_RAISE] = LAYOUT_ortho_4x12(
   ALTAB,  KC_EXLM,   KC_AT, KC_LCBR, KC_RCBR,  KC_DLR,  KC_GRV,   KC_P7,   KC_P8,   KC_P9, KC_PAST,  KC_NUM,
   KC_CAPS, KC_EQL, KC_UNDS, KC_LPRN, KC_RPRN, KC_HASH, KC_PIPE,   KC_P4,   KC_P5,   KC_P6, KC_PPLS, KC_PGUP,
   KC_HOME,KC_PERC, KC_CIRC, KC_LBRC, KC_RBRC, KC_TILD, KC_AMPR,   KC_P1,   KC_P2,   KC_P3, KC_PMNS, KC_PGDN,
   KC_END, _______, _______,  KC_GRV,   LOWER, _______,  NUMPAD, _______,   KC_P0, KC_PDOT, KC_PSLS, KC_PENT
),

/* Numpad
 * ,-----------------------------------------.    .-----------------------------------------.
 * |      |      |      |      |      |      |    |      |   7  |   8  |   9  |   *  |NumLck|
 * |------+------+------+------+------+------|    |------+------+------+------+------+------|
 * |CtrEsc|      |      |      |      |      |    |      |   4  |   5  |   6  |   +  |      |
 * |------+------+------+------+------+------|    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |    |      |   1  |   2  |   3  |   -  |      |
 * |------+------+------+------+-------------|    |-------------+------+------+------+------|
 * |      |      |      |      |      |Space |    |Qwerty|      |      |   0  |   .  |Enter |
 * `-----------------------------------------'    '-----------------------------------------'
 */
[_NUMPAD] = LAYOUT_ortho_4x12(
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_P7,   KC_P8,   KC_P9, KC_PAST,  KC_NUM,
    CTLESC,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_P4,   KC_P5,   KC_P6, KC_PPLS,   KC_NO,
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_P1,   KC_P2,   KC_P3, KC_PMNS,   KC_NO,
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,  KC_SPC,  QWERTY,   KC_NO,   KC_NO,   KC_P0, KC_PDOT, KC_PENT
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------.    .-----------------------------------------.
 * |      | Reset|      |      |      |      |    |      |      |      |      |      |  Del |
 * |------+------+------+------+------+------|    |------+------+------+------+------+------|
 * |      |      |      |Aud on|Audoff|AGnorm|    |AGswap|Qwerty|Colemk|Dvorak|      |      |
 * |------+------+------+------+------+------|    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |    |      |      |      |      |      |      |
 * `-----------------------------------------'    '-----------------------------------------'
 */
[_ADJUST] =  LAYOUT_ortho_4x12(
  _______, RESET,   _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_DEL,
  _______, _______, _______, AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, QWERTY,  COLEMAK, DVORAK,  _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
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
    case COLEMAK:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(tone_colemak);
        #endif
        persistent_default_layer_set(1UL<<_COLEMAK);
      }
      return false;
      break;
    case DVORAK:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(tone_dvorak);
        #endif
        persistent_default_layer_set(1UL<<_DVORAK);
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
    case NUMPAD:
      if (record->event.pressed) {
        persistent_default_layer_set(1UL<<_NUMPAD);
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
