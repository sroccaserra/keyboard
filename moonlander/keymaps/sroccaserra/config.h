/*
  Set any config.h overrides for your specific keymap here.
  See config.h options at https://docs.qmk.fm/#/config_options?id=the-configh-file
*/
#define ORYX_CONFIGURATOR
#undef TAPPING_TERM
#define TAPPING_TERM 200

#define PERMISSIVE_HOLD
// #define IGNORE_MOD_TAP_INTERRUPT // commented because it's now the default & would not compile

#define USB_SUSPEND_WAKEUP_DELAY 0
#define FIRMWARE_VERSION u8"jXKZa/mDJvX"
#define RGB_MATRIX_STARTUP_SPD 60

#define COMBO_TERM 40
#define COMBO_PERMISSIVE_HOLD

#define BOTH_SHIFTS_TURNS_ON_CAPS_WORD
