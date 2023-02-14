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
  TMUX_T, // Ctrl-Space Ctrl-T, my tmux shortcut to re-run the other window's last command
};

enum layers {
    _AZ = 0,  // AZerty
    _DV,  // DVorak
    _GA,  // GAmes
    _SY,  // SYmbols
    _NU,  // NUm & nav
    _ME,  // MEdia
    _HY,  // HYper
    _MO,  // MOuse
    _IJ   // IntelliJ
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // Rationale:
  // - Use azerty keys for letters
  // - Use the azerty symbol keys on the main 3 x 10 matrix, this allows to have a full shift layer
  // - Ctrl keys are on the home row
  // - (), {}, and [] are on the num row, in symetric positions
  // - & is on its azerty position
  // - % is on the same column as ù
  [_AZ] = LAYOUT_moonlander(
    KC_ESC,  FR_AMPR, FR_LBRC, FR_LCBR, FR_LPRN, _______, TO(_DV),      TO(_GA), _______, FR_RPRN, FR_RCBR, FR_RBRC, FR_PERC, KC_DEL,
    KC_TAB,  FR_A,    FR_Z,    KC_E,    KC_R,    KC_T,    _______,      _______, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    M_C_ESC, FR_Q,    HOME_S,  HOME_D,  KC_F,    KC_G,    TMUX_T,       _______, KC_H,    KC_J,    HOME_K,  HOME_L,  FR_M,    KC_RCTL,
    KC_LSFT, FR_W,    KC_X,    KC_C,    KC_V,    KC_B,                           KC_N,    FR_COMM, FR_SCLN, FR_COLN, FR_EQL,  KC_RSFT,
    MO(_IJ), _______, _______, MO(_ME), MO(_SY),          _______,      _______,          MO(_NU), MO(_MO), _______, _______, MO(_IJ),
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
  // - Only 3 rows, 8 columns if possible (avoid reaching too far on a non default layer)
  // - Exclude the other azerty symbol face value keys on the main 8 num row keys, they are already accessible on the default layer
  // - - is on the home row
  // - @, #, $ and * are on the same column as on qwerty
  // - ~ is on the same key as n
  // - \ is on the same key as french /
  // - | is on the same column as l and french /
  // - ` is on the home row, on the same column as french è
  // - All french accents on the same layer
  // - ù is on the same column as à and on its azerty row
  // - ^ is easy to reach & combine with e
  // - Use the azerty symbol face value keys on the main 8 num row keys, they are a little far but without mod it's ok
  // - Accented upper case letters match accented lower case letters
  [_SY] = LAYOUT_moonlander(
    RESET,   _______, E_A_MAJ, _______, _______, _______, _______,      _______, _______, E_G_MAJ, _______, C_C_MAJ, A_G_MAJ, _______,
    _______, FR_CIRC, FR_EACU, FR_DQUO, FR_QUOT, _______, _______,      _______, _______, FR_EGRV, FR_UNDS, FR_CCED, FR_AGRV, KC_DEL,
    _______, FR_MINS, FR_AT,   FR_HASH, FR_DLR,  _______, _______,      _______, _______, FR_GRV,  FR_ASTR, _PIPE,   FR_UGRV, _______,
    _______, _______, _______, FR_LABK, FR_RABK, _______,                        FR_TILD, _______, _______, FR_BSLS, FR_EXLM, _______,
    _______, _______, _______, _______, _______,          _______,      _______,          MO(_HY), _______, _______, _______, _______,
                                        _______, _______, _______,      _______, _______, _______
  ),
  [_NU] = LAYOUT_moonlander(
    _______, _______, _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______, _______, _______,
    _______, FR_5,    FR_6,    FR_7,    FR_8,    FR_9,    _______,      _______, _______, KC_HOME, KC_END,  _______, KC_PSCR, _______,
    _______, FR_1,    FR_2,    FR_3,    FR_4,    FR_0,    _______,      _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, VIM_ALT, _______,
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
    _______, _______, _______, KC_MS_U, _______, _______, _______,      _______, _______, KC_WH_U, KC_WH_D, _______, _______, _______,
    _______, _______, KC_MS_L, KC_MS_D, KC_MS_R, _______, _______,      _______, _______, KC_BTN1, KC_BTN2, KC_BTN3, _______, _______,
    _______, _______, _______, _______, _______, _______,                        _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______,          _______,      _______,          _______, _______, _______, _______, _______,
                                        _______, _______, _______,      _______, _______, _______
  ),
  [_IJ] = LAYOUT_moonlander(
    _______, IJ_PROJ, IJ_BOOK, IJ_FIND, IJ_TEST, _______, _______,      _______, _______, _______, _______, IJ_GIT,  _______, _______,
    _______, IJ_SELA, _______, _______, IJ_REFA, IJ_TERM, _______,      _______, _______, IJ_USAG, IJ_NEXT, IJ_PREV, _______, _______,
    _______, _______, IJ_CHGS, IJ_GDEF, IJ_RENA, _______, _______,      _______, _______, IJ_STDO, IJ_STUP, KC_F4,   _______, _______,
    _______, IJ_CLOS, _______, _______, IJ_RECT, _______,                        _______, IJ_SETT, IJ_PSET, _______, _______, _______,
    _______, _______, _______, _______, _______,          _______,      _______,          _______, _______, _______, _______, _______,
                                        _______, _______, _______,      _______, IJ_RUNC, IJ_RUN
  ),
};

extern bool g_suspend_state;
extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}

#define _OFF {HSV_BLACK}
#define _DVC {HSV_GOLD}
#define _GAC {HSV_GREEN}

const uint8_t PROGMEM ledmap[][DRIVER_LED_TOTAL][3] = {
    [_AZ] = { _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF },
    [_DV] = { _OFF, _DVC, _DVC, _DVC, _OFF, _DVC, _DVC, _DVC, _DVC, _DVC, _DVC, _DVC, _DVC, _DVC, _DVC, _DVC, _DVC, _DVC, _DVC, _DVC, _DVC, _DVC, _DVC, _DVC, _DVC, _DVC, _DVC, _DVC, _DVC, _DVC, _DVC, _DVC, _DVC, _DVC, _DVC, _DVC, _DVC, _DVC, _DVC, _DVC, _DVC, _DVC, _DVC, _DVC, _DVC, _DVC, _DVC, _DVC, _DVC, _DVC, _DVC, _DVC, _DVC, _DVC, _DVC, _DVC, _DVC, _DVC, _DVC, _DVC, _DVC, _DVC, _DVC, _DVC, _DVC, _DVC, _DVC, _DVC, _DVC, _DVC, _DVC, _DVC },
    [_GA] = { _GAC, _GAC, _GAC, _GAC, _GAC, _GAC, _GAC, _GAC, _GAC, _GAC, _GAC, _GAC, _GAC, _GAC, _GAC, _GAC, _GAC, _GAC, _GAC, _GAC, _GAC, _GAC, _GAC, _GAC, _GAC, _GAC, _GAC, _GAC, _GAC, _GAC, _GAC, _GAC, _GAC, _GAC, _GAC, _GAC, _GAC, _GAC, _GAC, _GAC, _GAC, _GAC, _GAC, _GAC, _GAC, _GAC, _GAC, _GAC, _GAC, _GAC, _GAC, _GAC, _GAC, _GAC, _GAC, _GAC, _GAC, _GAC, _GAC, _GAC, _GAC, _GAC, _GAC, _GAC, _GAC, _GAC, _GAC, _GAC, _GAC, _GAC, _GAC, _GAC },
    [_SY] = { _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF },
    [_NU] = { _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF },
    [_ME] = { _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF },
    [_HY] = { _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF },
    [_MO] = { _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF },
    [_IJ] = { _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF, _OFF },
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
    case TMUX_T:
    if (record->event.pressed) {
      SEND_STRING(SS_DOWN(X_LCTL) SS_TAP(X_SPACE) SS_DELAY(100) SS_TAP(X_T) SS_UP(X_LCTL));
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
