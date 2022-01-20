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
    _AZERTY = 0,
    _SYMBOLS,
    _MAJ_ACC,
    _NUM_NAV,
    _FN_HYPER,
    _GAMES
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_AZERTY] = LAYOUT_moonlander(
    _______, _______, _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______, _______, _______,
    _______, FR_A,    FR_Z,    KC_E,    KC_R,    KC_T,    _______,      _______, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    _______,
    _______, HOME_Q,  HOME_S,  HOME_D,  HOME_F,  KC_G,    _______,      _______, KC_H,    HOME_J,  HOME_K,  HOME_L,  HOME_M,  _______,
    _______, FR_W,    KC_X,    KC_C,    KC_V,    KC_B,                           KC_N,    FR_COMM, FR_SCLN, FR_COLN, FR_EQL,  _______,
    _______, _______, _______, MO(2),   MO(1),            _______,      _______,          MO(3),   _______, _______, _______, _______,
                                        KC_SPC,  _______, _______,      _______, KC_LGUI, KC_RSFT
  ),
  [_SYMBOLS] = LAYOUT_moonlander(
    RESET,   _______, _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______, _______, _______,
    _______, FR_CIRC, FR_EACU, FR_DQUO, FR_QUOT, _______, _______,      _______, FR_GRV,  FR_EGRV, FR_UNDS, FR_CCED, FR_AGRV, _______,
    _______, FR_MINS, FR_DLR,  FR_LPRN, FR_RPRN, _______, _______,      _______, FR_HASH, FR_LCBR, FR_RCBR, FR_ASTR, FR_UGRV, _______,
    _______, FR_AT,   FR_AMPR, FR_LABK, FR_RABK, _______,                        _______, FR_LBRC, FR_RBRC, FR_PERC, FR_EXLM, _______,
    _______, _______, _______, _______, _______,          _______,      _______,          MO(4),   _______, _______, _______, _______,
                                        _______, _______, _______,      _______, _______, _______
  ),
  [_MAJ_ACC] = LAYOUT_moonlander(
    _______, _______, _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______, _______, _______,
    _______, _______, E_A_MAJ, _______, _______, _______, _______,      _______, _______, E_G_MAJ, _______, C_C_MAJ, A_G_MAJ, _______,
    _______, KC_MUTE, KC_VOLD, KC_VOLU, _______, _______, _______,      _______, _______, FR_TILD, FR_BSLS, _PIPE,   _______, _______,
    _______, _______, KC_BRID, KC_BRIU, _______, _______,                        _______, CTL_MIN, CTL_PLU, CTL_ZER, _______, _______,
    _______, _______, _______, _______, _______,          _______,      _______,          _______, _______, _______, _______, _______,
                                        _______, _______, _______,      _______, _______, _______
  ),
  [_NUM_NAV] = LAYOUT_moonlander(
    _______, _______, _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______, _______, _______,
    _______, FR_6,    FR_7,    FR_8,    FR_9,    FR_0,    _______,      _______, _______, _______, _______, _______, _______, _______,
    _______, FR_1,    FR_2,    FR_3,    FR_4,    FR_5,    _______,      _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, VIM_ALT, _______,
    _______, _______, _______, _______, _______, _______,                        _______, SC_DOWN, SC_UP,   SC_HOME, WI_NEXT, _______,
    _______, _______, _______, _______, MO(4),            _______,      _______,          _______, _______, _______, _______, _______,
                                        _______, _______, _______,      _______, _______, _______
  ),
  [_FN_HYPER] = LAYOUT_moonlander(
    _______, _______, _______, _______, _______, _______, _______,      TO(5),   _______, _______, _______, _______, _______, _______,
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______,      _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______,
    _______, HYPER_A, HYPER_S, HYPER_D, HYPER_F, HYPER_G, _______,      _______, HYPER_H, HYPER_J, HYPER_K, HYPER_L, KC_F11,  _______,
    _______, _______, _ORYX,   _______, HYPER_V, _______,                        _______, HYPR_CO, _______, _______, KC_F12,  _______,
    _______, _______, _______, _______, _______,          _______,      _______,          _______, _______, _______, _______, _______,
                                        _______, _______, _______,      _______, _______, _______
  ),
  [_GAMES] = LAYOUT_moonlander(
    _______, _______, _______, _______, _______, _______, _______,      TO(0),   _______, _______, _______, _______, _MISTER, KC_F12,
    _______, KC_ESC,  FR_A,    FR_Z,    KC_E,    KC_R,    _______,      _______, KC_T,    KC_Y,    KC_UP,   KC_I,    KC_O,    KC_P,
    _______, KC_LCTL, FR_Q,    KC_S,    KC_D,    KC_F,    _______,      _______, KC_G,    KC_LEFT, KC_DOWN, KC_RGHT, KC_L,    KC_SCLN,
    _______, KC_LSFT, FR_W,    KC_X,    KC_C,    KC_V,                           KC_B,    KC_N,    KC_M,    KC_COMM, KC_RALT, KC_SLSH,
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

const uint8_t PROGMEM ledmap[][DRIVER_LED_TOTAL][3] = {
    [0] = { _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF },
    [1] = { _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF },
    [2] = { _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF },
    [3] = { _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF },
    [4] = { _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF },
    [5] = { _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF },
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
