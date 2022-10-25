#include QMK_KEYBOARD_H
#include "version.h"
#include "keymap_french.h"

#include "./keymap_defines.h"
#include "./keymap_combo.h"

enum custom_keycodes {
  RGB_SLD = ML_SAFE_RANGE,
  E_A_MAJ, // É
  E_G_MAJ, // È
  C_C_MAJ, // Ç
  A_G_MAJ, // À
  FR_LSPO,
  FR_RSPC,
};

enum layers {
    _AZ = 0,  // AZerty
    _DV,  // DVorak
    _GA,  // GAmes
    _SY,  // SYmbols
    _NU,  // NUm & nav
    _ME,  // MEdia
    _HY,  // HYper
    _MO  // MOuse
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // Rationale:
  // - Use azerty keys for letters
  // - Use the azerty symbol keys on the main 3 x 10 matrix, this allows to have a full shift layer
  // - Use the azerty symbol keys on the main 8 keys of num rows, they are a little far but on the default layer it's ok
  // - Ctrl keys are on the home row
  [_AZ] = LAYOUT_moonlander(
    _______, FR_AMPR, FR_EACU, FR_DQUO, FR_QUOT, _______, TO(_DV),      TO(_GA), _______, FR_EGRV, FR_UNDS, FR_CCED, FR_AGRV, KC_DEL,
    KC_TAB,  FR_A,    FR_Z,    KC_E,    KC_R,    KC_T,    _______,      _______, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    M_C_ESC, FR_Q,    HOME_S,  HOME_D,  KC_F,    KC_G,    _______,      _______, KC_H,    KC_J,    HOME_K,  HOME_L,  FR_M,    KC_RCTL,
    KC_LSFT, FR_W,    KC_X,    KC_C,    KC_V,    KC_B,                           KC_N,    FR_COMM, FR_SCLN, FR_COLN, FR_EQL,  KC_RSFT,
    _______, _______, _______, MO(_ME), MO(_SY),          _______,      _______,          MO(_NU), MO(_MO), _______, _______, _______,
                                        KC_SPC,  _______, _______,      _______, KC_LGUI, KC_ENT
  ),
  // Rationale:
  // - The OS keyboard layout should be azerty
  // - The four Dvorak punctuation keys are replaced by four azerty punctuation keys
  // - This allows the number row to use the same symbols as azerty layout, making the transition easier
  // - This in turn allows to share a common symbol layer between azerty and Dvorak layout
  [_DV] = LAYOUT_moonlander(
    _______, _______, _______, _______, _______, _______, TO(_AZ),      _______, _______, _______, _______, _______, _______, _______,
    _______, FR_COLN, FR_SCLN, FR_COMM, KC_P,    KC_Y,    _______,      _______, KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    _______,
    _______, FR_A,    HOME_O,  HOME_E,  KC_U,    KC_I,    _______,      _______, KC_D,    KC_H,    HOME_T,  HOME_N,  KC_S,    _______,
    _______, FR_EQL,  FR_Q,    KC_J,    KC_K,    KC_X,                           KC_B,    FR_M,    FR_W,    KC_V,    FR_Z,    _______,
    _______, _______, _______, _______, _______,          _______,      _______,          _______, _______, _______, _______, _______,
                                        _______, _______, _______,      _______, _______, _______
  ),
  [_GA] = LAYOUT_moonlander(
    _______, _______, _______, _______, _______, _______, _______,      TO(_AZ), _______, _______, _______, _______, _MISTER, KC_F12 ,
    _______, KC_ESC , _______, KC_UP  , _______, _______, _______,      _______, _______, FR_W   , KC_X   , FR_Q   , KC_S   , _______,
    _______, KC_D   , KC_LEFT, KC_DOWN, KC_RGHT, KC_C   , _______,      _______, FR_A   , FR_Q   , KC_S   , KC_D   , FR_A   , _______,
    _______, KC_LCTL, KC_LALT, _______, _______, _______,                        FR_Q   , FR_W   , KC_X   , KC_C   , FR_Z   , _______,
    _______, _______, _______, _______, _______,          KC_F1  ,      KC_BSPC,          _______, _______, _______, _______, _______,
                                        KC_UP  , _______, _______,      _______, KC_RSFT, KC_ENT
  ),
  // Rationale:
  // - only 3 rows, 8 columns if possible (avoid reaching too far on a non default layer)
  // - (), {}, and [] are on the home row, in symetric positions
  // - - is on the home row
  // - @, #, $ and * are on the same column as on qwerty
  // - ~ is on the same key as n
  // - \ is on the same key as french /
  // - | is on the same column as l and french /
  // - ` is on the same column as french è
  // - ù is on the same column as à and just beside o
  // - ^ is easy to reach & combine with e
  // - % is on the same column as ù
  // - Accented upper case letters match accented lower case letters
  [_SY] = LAYOUT_moonlander(
    RESET,   _______, E_A_MAJ, _______, _______, _______, _______,      _______, _______, E_G_MAJ, _______, C_C_MAJ, A_G_MAJ, _______,
    _______, FR_CIRC, FR_AT,   FR_HASH, FR_DLR,  _______, _______,      _______, _______, FR_GRV,  FR_ASTR, _PIPE,   FR_UGRV, _______,
    _______, FR_MINS, FR_LBRC, FR_LCBR, FR_LPRN, _______, _______,      _______, _______, FR_RPRN, FR_RCBR, FR_RBRC, FR_PERC, _______,
    _______, _______, _______, FR_LABK, FR_RABK, _______,                        FR_TILD, _______, _______, FR_BSLS, FR_EXLM, _______,
    _______, _______, _______, _______, _______,          _______,      _______,          MO(_HY), _______, _______, _______, _______,
                                        _______, _______, _______,      _______, _______, _______
  ),
  [_NU] = LAYOUT_moonlander(
    _______, _______, _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______, _______, _______,
    _______, FR_6,    FR_7,    FR_8,    FR_9,    FR_0,    _______,      _______, _______, KC_HOME, KC_END,  _______, KC_PSCR, _______,
    _______, FR_1,    FR_2,    FR_3,    FR_4,    FR_5,    _______,      _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, VIM_ALT, _______,
    _______, _______, _______, _______, FR_MINS, FR_BSLS,                        _______, SC_DOWN, SC_UP,   SC_HOME, WI_NEXT, _______,
    _______, _______, _______, _______, MO(_HY),            _______,      _______,          _______, _______, _______, _______, _______,
                                        _______, _______, _______,      _______, _______, _______
  ),
  [_ME] = LAYOUT_moonlander(
    _______, _______, _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______, _______, _______,
    _______, KC_MUTE, KC_VOLD, KC_VOLU, _______, _______, _______,      _______, _______, CTL_MIN, CTL_PLU, CTL_ZER, _______, _______,
    _______, _______, KC_BRID, KC_BRIU, _______, _______,                        _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______,          _______,      _______,          _______, _______, _______, _______, _______,
                                        _______, _______, _______,      _______, _______, _______
  ),
  [_HY] = LAYOUT_moonlander(
    _______, _______, _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______, _______, _______,
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______,      _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______,
    _______, HYPER_A, HYPER_S, HYPER_D, HYPER_F, HYPER_G, _______,      _______, HYPER_H, HYPER_J, HYPER_K, HYPER_L, KC_F11,  _______,
    _______, _______, _ORYX,   _______, HYPER_V, _______,                        _______, HYPR_CO, _______, _______, KC_F12,  _______,
    _______, _______, _______, _______, _______,          _______,      _______,          _______, _______, _______, _______, _______,
                                        _______, _______, _______,      _______, _______, _______
  ),
  [_MO] = LAYOUT_moonlander(
    _______, _______, _______, _______, _______, _______, _______,      TO(_AZ), _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,      _______, _______, _______, KC_BTN1, KC_MS_U, KC_BTN2, _______,
    _______, _______, _______, _______, _______, _______, _______,      _______, _______, _______, KC_MS_L, KC_MS_D, KC_MS_R, _______,
    _______, _______, _______, _______, _______, _______,                        _______, _______, KC_WH_U, KC_WH_D, _______, _______,
    _______, _______, _______, _______, _______,          _______,      _______,          _______, _______, _______, _______, _______,
                                        _______, _______, _______,      _______, _______, _______
  ),
};

extern bool g_suspend_state;
extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}

#define _OFF {0,0,0}
#define __ON {255,0,255}

const uint8_t PROGMEM ledmap[][DRIVER_LED_TOTAL][3] = {
    [0] = { _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF },
    [1] = { _OFF, __ON, __ON, __ON, _OFF, __ON, __ON, __ON, __ON, __ON, __ON, __ON, __ON, __ON, __ON, __ON, __ON, __ON, __ON, __ON, __ON, __ON, __ON, __ON, __ON, __ON, __ON, __ON, __ON, __ON, __ON, __ON, __ON, __ON, __ON, __ON, __ON, __ON, __ON, __ON, __ON, __ON, __ON, __ON, __ON, __ON, __ON, __ON, __ON, __ON, __ON, __ON, __ON, __ON, __ON, __ON, __ON, __ON, __ON, __ON, __ON, __ON, __ON, __ON, __ON, __ON, __ON, __ON, __ON, __ON, __ON, __ON },
    [2] = { _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF },
    [3] = { _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF },
    [4] = { _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF },
    [5] = { _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF },
    [6] = { _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF },
    [7] = { _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF },
};

void set_layer_color(int layer) {
  for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
    HSV hsv = {
      .h = pgm_read_byte(&ledmap[layer][i][0]),
      .s = pgm_read_byte(&ledmap[layer][i][1]),
      .v = pgm_read_byte(&ledmap[layer][i][2]),
    };
    if (!hsv.h && !hsv.s && !hsv.v) {
        rgb_matrix_set_color( i, 0, 0, 0 );
    } else {
        RGB rgb = hsv_to_rgb( hsv );
        float f = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
        rgb_matrix_set_color( i, f * rgb.r, f * rgb.g, f * rgb.b );
    }
  }
}

void rgb_matrix_indicators_user(void) {
  if (keyboard_config.disable_layer_led) { return; }
  switch (biton32(layer_state)) {
    case 0:
      set_layer_color(0);
      break;
    case 1:
      set_layer_color(1);
      break;
    case 2:
      set_layer_color(2);
      break;
    case 3:
      set_layer_color(3);
      break;
    case 4:
      set_layer_color(4);
      break;
    case 5:
      set_layer_color(5);
      break;
    case 6:
      set_layer_color(6);
      break;
   default:
    if (rgb_matrix_get_flags() == LED_FLAG_NONE)
      rgb_matrix_set_color_all(0, 0, 0);
    break;
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case E_A_MAJ:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_CAPSLOCK) SS_DELAY(100) SS_TAP(X_2) SS_DELAY(100) SS_TAP(X_CAPSLOCK));

    }
    break;
    case E_G_MAJ:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_CAPSLOCK) SS_DELAY(100) SS_TAP(X_7) SS_DELAY(100) SS_TAP(X_CAPSLOCK));

    }
    break;
    case C_C_MAJ:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_CAPSLOCK) SS_DELAY(100) SS_TAP(X_9) SS_DELAY(100) SS_TAP(X_CAPSLOCK));

    }
    break;
    case A_G_MAJ:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_CAPSLOCK) SS_DELAY(100) SS_TAP(X_0) SS_DELAY(100) SS_TAP(X_CAPSLOCK));

    }
    break;
    case FR_LSPO:
      perform_space_cadet(record, keycode, KC_LSFT, KC_TRNS, FR_LPRN);
      return false;
    case FR_RSPC:
      perform_space_cadet(record, keycode, KC_LSFT, KC_TRNS, FR_RPRN);
      return false;
    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
  }
  return true;
}

bool caps_word_press_user(uint16_t keycode) {
    switch (keycode) {
        // Keycodes that continue Caps Word, with shift applied.
        case KC_A ... KC_L:
        case FR_M:
        case KC_N ... KC_Z:
            add_weak_mods(MOD_BIT(KC_LSFT));  // Apply shift to next key.
            return true;

        // Keycodes that continue Caps Word, without shifting.
        case FR_1 ... FR_0:
        case FR_MINS:
        case FR_UNDS:
        case KC_BSPC:
        case KC_DEL:
            return true;

        default:
            return false;  // Deactivate Caps Word.
    }
}
