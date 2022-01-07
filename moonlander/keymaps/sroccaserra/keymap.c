#include QMK_KEYBOARD_H
#include "version.h"
#include "keymap_french.h"

enum custom_keycodes {
  RGB_SLD = ML_SAFE_RANGE,
  ST_MACRO_0,
  ST_MACRO_1,
  ST_MACRO_2,
  ST_MACRO_3,
  FR_LSPO,
  FR_RSPC,
};

#define HOME_Q MT(MOD_LCTL, FR_Q)
#define HOME_S MT(MOD_LALT, FR_S)
#define HOME_D MT(MOD_LGUI, FR_D)
#define HOME_F MT(MOD_LSFT, FR_F)

#define HOME_J MT(MOD_RSFT, FR_J)
#define HOME_K MT(MOD_RGUI, FR_K)
#define HOME_L MT(MOD_RALT, FR_L)
#define HOME_M MT(MOD_RCTL, FR_M)

#define HYPER_A LALT(LGUI(LCTL(LSFT(KC_A))))
#define HYPER_S LALT(LGUI(LCTL(LSFT(KC_S))))
#define HYPER_D LALT(LGUI(LCTL(LSFT(KC_D))))
#define HYPER_F LALT(LGUI(LCTL(LSFT(KC_F))))
#define HYPER_G LALT(LGUI(LCTL(LSFT(KC_G))))
#define HYPER_V LALT(LGUI(LCTL(LSFT(KC_V))))

#define HYPER_H LALT(LGUI(LCTL(LSFT(KC_H))))
#define HYPER_J LALT(LGUI(LCTL(LSFT(KC_J))))
#define HYPER_K LALT(LGUI(LCTL(LSFT(KC_K))))
#define HYPER_L LALT(LGUI(LCTL(LSFT(KC_L))))
#define HYPER_COMM LALT(LGUI(LCTL(LSFT(FR_COMM))))

#include "keymap_combo.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_moonlander(
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, /**/ KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, FR_A,    FR_Z,    KC_E,    KC_R,    KC_T,    KC_TRNS, /**/ KC_TRNS, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_TRNS,
    KC_BSPC, HOME_Q,  HOME_S,  HOME_D,  HOME_F,  KC_G,    KC_TRNS, /**/ KC_TRNS, KC_H,    HOME_J,  HOME_K,  HOME_L,  HOME_M,  KC_TRNS,
    KC_TRNS, FR_W,    KC_X,    KC_C,    KC_V,    KC_B,             /**/          KC_N,    FR_COMM, FR_SCLN, FR_COLN, FR_EQL,  KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, MO(2),   MO(1),   KC_LGUI,          /**/          KC_TRNS, MO(3),   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_SPC,  KC_TAB,  KC_TRNS,                                     /**/ KC_TRNS, KC_ESC,  KC_ENTER
  ),
  [1] = LAYOUT_moonlander(
    RESET,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, /**/ KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, FR_CIRC, FR_EACU, FR_DQUO, FR_QUOT, KC_TRNS, KC_TRNS, /**/ KC_TRNS, FR_GRV,  FR_EGRV, FR_UGRV, FR_CCED, FR_AGRV, KC_TRNS,
    KC_TRNS, FR_MINS, FR_DLR,  FR_LPRN, FR_RPRN, KC_TRNS, KC_TRNS, /**/ KC_TRNS, FR_HASH, FR_LCBR, FR_RCBR, FR_ASTR, FR_UNDS, KC_TRNS,
    KC_TRNS, FR_AT,   FR_AMPR, FR_LABK, FR_RABK, KC_TRNS,          /**/          KC_TRNS, FR_LBRC, FR_RBRC, FR_PERC, FR_EXLM, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          /**/          KC_TRNS, MO(4),   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS,                                     /**/ KC_TRNS, KC_TRNS, KC_TRNS
  ),
  [2] = LAYOUT_moonlander(
    KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS,     KC_TRNS, KC_TRNS,         KC_TRNS, /**/ KC_TRNS, KC_TRNS, KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,   KC_TRNS,
    KC_TRNS, KC_TRNS, ST_MACRO_0,LALT(FR_DLR),KC_TRNS, LGUI(LSFT(KC_5)),KC_TRNS, /**/ KC_TRNS, KC_TRNS, ST_MACRO_1,   KC_TRNS,      ST_MACRO_2,   ST_MACRO_3,KC_TRNS,
    KC_TRNS, KC_MUTE, KC_VOLD,   KC_VOLU,     KC_TRNS, KC_TRNS,         KC_TRNS, /**/ KC_TRNS, KC_TRNS, FR_TILD,      FR_BSLS,      RALT(FR_MINS),KC_TRNS,   KC_TRNS,
    KC_TRNS, KC_TRNS, KC_BRID,   KC_BRIU,     KC_TRNS, KC_TRNS,                  /**/          KC_TRNS, LCTL(FR_MINS),LCTL(FR_PLUS),LCTL(FR_0),   KC_TRNS,   KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS,     KC_TRNS, KC_TRNS,                  /**/          KC_TRNS, KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,   KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS,                                                   /**/ KC_TRNS, KC_TRNS, KC_TRNS
  ),
  [3] = LAYOUT_moonlander(
    KC_TRNS, KC_TRNS,    KC_TRNS, KC_TRNS,         KC_TRNS,         KC_TRNS,      KC_TRNS, /**/ KC_TRNS, KC_TRNS, KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,         KC_TRNS,
    KC_TRNS, FR_1,       FR_2,    FR_3,            FR_4,            FR_5,         KC_TRNS, /**/ KC_TRNS, FR_6,    FR_7,         FR_8,         FR_9,         FR_0,            KC_TRNS,
    KC_TRNS, KC_LCTRL,   KC_LALT, KC_LGUI,         KC_LSHIFT,       KC_HOME,      KC_TRNS, /**/ KC_TRNS, KC_LEFT, KC_DOWN,      KC_UP,        KC_RIGHT,     LCTL(RALT(KC_9)),KC_TRNS,
    KC_TRNS, LCTL(KC_F4),KC_DEL,  LCTL(LSFT(KC_C)),LCTL(LSFT(KC_V)),LALT(KC_LEFT),         /**/          KC_TRNS, LGUI(KC_PGDN),LGUI(KC_PGUP),LGUI(KC_HOME),LALT(FR_SUP2),   KC_TRNS,
    KC_TRNS, KC_TRNS,    KC_TRNS, KC_TRNS,         MO(4),           KC_TRNS,               /**/          KC_TRNS, KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,         KC_TRNS,
    KC_TRNS, KC_TRNS,    KC_TRNS,                                                          /**/ KC_TRNS, KC_TRNS, KC_TRNS
  ),
  [4] = LAYOUT_moonlander(
    KC_TRNS, KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, /**/ TO(5),   KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_F1,      KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_TRNS, /**/ KC_TRNS, KC_F6,   KC_F7,     KC_F8,   KC_F9,   KC_F10,  KC_TRNS,
    KC_TRNS, HYPER_A,    HYPER_S, HYPER_D, HYPER_F, HYPER_G, KC_TRNS, /**/ KC_TRNS, HYPER_H, HYPER_J,   HYPER_K, HYPER_L, KC_F11,  KC_TRNS,
    KC_TRNS, KC_TRNS,    KC_TRNS, KC_TRNS, HYPER_V, KC_TRNS,          /**/          KC_TRNS, HYPER_COMM,KC_TRNS, KC_TRNS, KC_F12,  KC_TRNS,
    KC_TRNS, WEBUSB_PAIR,KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          /**/          KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS,    KC_TRNS,                                     /**/ KC_TRNS, KC_TRNS, KC_TRNS
  ),
  [5] = LAYOUT_moonlander(
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, /**/ TO(0),   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, LALT(KC_F12),KC_F12,
    KC_TRNS, KC_ESC,  FR_A,    FR_Z,    KC_E,    KC_R,    KC_TRNS, /**/ KC_TRNS, KC_T,    KC_Y,    KC_UP,   KC_I,    KC_O,        KC_P,
    KC_TRNS, KC_LCTL, FR_Q,    KC_S,    KC_D,    KC_F,    KC_TRNS, /**/ KC_TRNS, KC_G,    KC_LEFT, KC_DOWN, KC_RIGHT,KC_L,        KC_SCOLON,
    KC_TRNS, KC_LSFT, FR_W,    KC_X,    KC_C,    KC_V,             /**/          KC_B,    KC_N,    KC_M,    KC_COMMA,KC_RALT,     KC_SLASH,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          /**/          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS,                                     /**/ KC_TRNS, KC_TRNS, KC_TRNS
  ),
};

extern bool g_suspend_state;
extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}

const uint8_t PROGMEM ledmap[][DRIVER_LED_TOTAL][3] = {
    [0] = { {0,0,0}, {0,0,0}, {14,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {35,255,255}, {14,255,255}, {35,255,255}, {0,0,0}, {0,0,0}, {35,255,255}, {14,255,255}, {35,255,255}, {0,0,0}, {0,0,0}, {35,255,255}, {14,255,255}, {35,255,255}, {31,255,255}, {0,0,0}, {35,255,255}, {14,255,255}, {35,255,255}, {154,255,255}, {0,0,0}, {35,255,255}, {35,255,255}, {35,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {14,255,255}, {14,255,255}, {0,0,0}, {35,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {35,255,255}, {14,255,255}, {35,255,255}, {0,0,0}, {0,0,0}, {35,255,255}, {14,255,255}, {35,255,255}, {0,0,0}, {0,0,0}, {35,255,255}, {14,255,255}, {35,255,255}, {0,0,0}, {0,0,0}, {35,255,255}, {14,255,255}, {35,255,255}, {105,255,255}, {0,0,0}, {35,255,255}, {35,255,255}, {35,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {14,255,255}, {14,255,255}, {0,0,0}, {0,0,0} },

    [1] = { {249,228,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {154,255,255}, {154,255,255}, {154,255,255}, {0,0,0}, {0,0,0}, {154,255,255}, {154,255,255}, {154,255,255}, {0,0,0}, {0,0,0}, {154,255,255}, {154,255,255}, {154,255,255}, {0,0,0}, {0,0,0}, {154,255,255}, {154,255,255}, {154,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {154,255,255}, {154,255,255}, {154,255,255}, {0,0,0}, {0,0,0}, {154,255,255}, {154,255,255}, {154,255,255}, {0,0,0}, {0,0,0}, {154,255,255}, {154,255,255}, {154,255,255}, {0,0,0}, {0,0,0}, {154,255,255}, {154,255,255}, {154,255,255}, {249,228,255}, {0,0,0}, {154,255,255}, {154,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [2] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {31,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {31,255,255}, {31,255,255}, {31,255,255}, {0,0,0}, {0,0,0}, {31,255,255}, {31,255,255}, {31,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {31,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {31,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {31,255,255}, {31,255,255}, {31,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {31,255,255}, {31,255,255}, {0,0,0}, {0,0,0}, {31,255,255}, {31,255,255}, {31,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [3] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {105,255,255}, {105,255,255}, {105,255,255}, {0,0,0}, {0,0,0}, {105,255,255}, {105,255,255}, {105,255,255}, {0,0,0}, {0,0,0}, {105,255,255}, {105,255,255}, {105,255,255}, {0,0,0}, {0,0,0}, {105,255,255}, {105,255,255}, {105,255,255}, {249,228,255}, {0,0,0}, {105,255,255}, {105,255,255}, {105,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {105,255,255}, {105,255,255}, {105,255,255}, {0,0,0}, {0,0,0}, {105,255,255}, {105,255,255}, {105,255,255}, {0,0,0}, {0,0,0}, {105,255,255}, {105,255,255}, {105,255,255}, {0,0,0}, {0,0,0}, {105,255,255}, {105,255,255}, {105,255,255}, {0,0,0}, {0,0,0}, {105,255,255}, {105,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [4] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {249,228,255}, {249,228,255}, {0,0,0}, {249,228,255}, {0,0,0}, {249,228,255}, {249,228,255}, {0,0,0}, {0,0,0}, {0,0,0}, {249,228,255}, {249,228,255}, {0,0,0}, {0,0,0}, {0,0,0}, {249,228,255}, {249,228,255}, {249,228,255}, {0,0,0}, {0,0,0}, {249,228,255}, {249,228,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {249,228,255}, {249,228,255}, {249,228,255}, {0,0,0}, {0,0,0}, {249,228,255}, {249,228,255}, {0,0,0}, {0,0,0}, {0,0,0}, {249,228,255}, {249,228,255}, {0,0,0}, {0,0,0}, {0,0,0}, {249,228,255}, {249,228,255}, {249,228,255}, {0,0,0}, {0,0,0}, {249,228,255}, {249,228,255}, {0,0,0}, {15,166,195}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [5] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {31,255,255}, {35,255,255}, {35,255,255}, {0,0,0}, {0,0,0}, {15,166,195}, {15,166,195}, {15,166,195}, {0,0,0}, {0,0,0}, {15,166,195}, {15,166,195}, {15,166,195}, {0,0,0}, {0,0,0}, {15,166,195}, {15,166,195}, {15,166,195}, {0,0,0}, {0,0,0}, {15,166,195}, {15,166,195}, {15,166,195}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {15,166,195}, {15,166,195}, {15,166,195}, {15,166,195}, {0,0,0}, {15,166,195}, {15,166,195}, {15,166,195}, {35,255,255}, {0,0,0}, {0,0,0}, {15,166,195}, {0,183,238}, {15,166,195}, {0,0,0}, {0,0,0}, {0,183,238}, {0,183,238}, {15,166,195}, {0,0,0}, {0,0,0}, {15,166,195}, {0,183,238}, {15,166,195}, {0,0,0}, {0,0,0}, {15,166,195}, {15,166,195}, {15,166,195}, {15,166,195}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

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
    case ST_MACRO_0:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_CAPSLOCK) SS_DELAY(100) SS_TAP(X_2) SS_DELAY(100) SS_TAP(X_CAPSLOCK));

    }
    break;
    case ST_MACRO_1:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_CAPSLOCK) SS_DELAY(100) SS_TAP(X_7) SS_DELAY(100) SS_TAP(X_CAPSLOCK));

    }
    break;
    case ST_MACRO_2:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_CAPSLOCK) SS_DELAY(100) SS_TAP(X_9) SS_DELAY(100) SS_TAP(X_CAPSLOCK));

    }
    break;
    case ST_MACRO_3:
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
