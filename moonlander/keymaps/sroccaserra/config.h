/*
  Set any config.h overrides for your specific keymap here.
  See config.h options at https://docs.qmk.fm/#/config_options?id=the-configh-file
*/
#define ORYX_CONFIGURATOR
#undef TAPPING_TERM
#define TAPPING_TERM 170

#define PERMISSIVE_HOLD

#define USB_SUSPEND_WAKEUP_DELAY 0
#define FIRMWARE_VERSION u8"jXKZa/mDJvX"
#define RGB_MATRIX_STARTUP_SPD 60

// Note: COMBO_COUNT will no longer be needed with firmware 21, see:
// - https://github.com/qmk/qmk_firmware/pull/8591
#define COMBO_COUNT 2
#define COMBO_TERM 40
#define COMBO_PERMISSIVE_HOLD
