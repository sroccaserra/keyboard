#ifndef __KEYMAP_DEFINES_H__
#define __KEYMAP_DEFINES_H__

#include "keymap_french.h"

#define HOME_Q MT(MOD_LCTL, FR_Q)
#define HOME_S MT(MOD_LALT, FR_S)
#define HOME_D MT(MOD_LGUI, FR_D)
#define HOME_F MT(MOD_LSFT, FR_F)

#define HOME_J MT(MOD_RSFT, FR_J)
#define HOME_K MT(MOD_RGUI, FR_K)
#define HOME_L MT(MOD_RALT, FR_L)
#define HOME_M MT(MOD_RCTL, FR_M)

#define HYPE_SP MT(MOD_LCTL | MOD_LGUI | MOD_LALT | MOD_LSFT, KC_SPC)

// For Dvorak layer
#define HOME_O MT(MOD_LALT, KC_O)
#define HOME_E MT(MOD_LGUI, KC_E)
#define HOME_T MT(MOD_RGUI, KC_T)
#define HOME_N MT(MOD_RALT, KC_N)

#define TAB_SYM LT(_SYMBOLS, KC_TAB)
#define ENT_NUM LT(_NUM_NAV, KC_ENT)

#define M_C_ESC MT(MOD_LCTL, KC_ESC)
#define CTL_PLU LCTL(FR_PLUS)
#define CTL_MIN LCTL(FR_MINS)
#define CTL_ZER LCTL(FR_0)
#define _PIPE   RALT(FR_MINS)
#define FR_MDOT RALT(FR_COLN)

#define SC_DOWN LGUI(KC_PGDN)
#define SC_HOME LGUI(KC_HOME)
#define SC_UP   LGUI(KC_PGUP)
#define VIM_ALT LCTL(RALT(KC_9))
#define WI_NEXT LALT(FR_SUP2)

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
#define HYPR_CO LALT(LGUI(LCTL(LSFT(FR_COMM))))
#define _ORYX   WEBUSB_PAIR

#define _MISTER LALT(KC_F12)

#define IJ_RUN LSFT(KC_F10)
#define IJ_RUNC ALGR(LSFT(KC_F10))

#define IJ_PREV LALT(KC_LEFT)
#define IJ_NEXT LALT(KC_RIGHT)
#define IJ_GDEF LALT(KC_D)
#define IJ_SETT LCTL(LALT(KC_S))
#define IJ_PSET LCTL(LALT(LSFT(KC_S)))
#define IJ_PROJ LALT(FR_AMPR)
#define IJ_BOOK LALT(FR_EACU)
#define IJ_FIND LALT(FR_DQUO)
#define IJ_TEST LALT(FR_QUOT)
#define IJ_GIT  LALT(FR_CCED)
#define IJ_USAG LALT(LSFT(FR_EGRV))
#define IJ_REFA LCTL(LALT(LSFT(KC_T)))
#define IJ_CLOS LCTL(LSFT(KC_F4))
#define IJ_TERM LALT(KC_F12)

#define IJ_ALTE LALT(KC_ENT)
#define IJ_RENA LSFT(KC_F6)
#define IJ_CHGS LCTL(KC_F6)
#define IJ_STUP LCTL(LSFT(KC_UP))
#define IJ_STDO LCTL(LSFT(KC_DOWN))
#define IJ_RECT LALT(LSFT(KC_INS))
// add cursors for all occurence of word
#define IJ_SELA LCTL(LALT(LSFT(KC_J)))
#define IJ_COMM LCTL(KC_KP_SLASH)

#define OSM_ALT OSM(MOD_LALT)
#define OSM_ALG OSM(MOD_RALT)

#endif // __KEYMAP_DEFINES_H__
