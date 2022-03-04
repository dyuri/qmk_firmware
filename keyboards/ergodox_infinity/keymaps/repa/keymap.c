#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "version.h"

enum layer_names {
  BASE,
  SYMB,
  QWER,
  ESAB
};

enum custom_keycodes {
  VRSN = SAFE_RANGE, // can always be here
  EPRM,
  RGB_SLD
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |  ESC   |   1  |   2  |   3  |   4  |   5  |  L2  |           |  L2  |   6  |   7  |   8  |   9  |   0  |   =    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |  TAB   |   '  |   ,  |   .  |   P  |   Y  | SGui |           | Meh  |   F  |   G  |   C  |   R  |   L  |   /    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |  RAlt  |   A  |   O  |   E  |   U  |   I  |------|           |------|   D  |   H  |   T  |   N  |   S  |- / Gui |
 * |--------+------+------+------+------+------|  L1t |           | tL1t |------+------+------+------+------+--------|
 * | LShift |   ;  |   Q  |   J  |   K  |   X  |      |           |      |   B  |   M  |   W  |   V  |   Z  | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | LCtrl|   `  |   \  |   [  |   ]  |                                       | Left | Down |  Up  | Right| RCtrl|
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | LGui | LAlt |       | RAlt | RGui |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |Mirror|      | Home |       | PgUp |      |      |
 *                                 |/Space|Backsp|------|       |------| Enter| RAlt |
 *                                 |      |ace   |L1/End|       | PgDn |      |      |
 *                                 `--------------------'       `--------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[BASE] = LAYOUT_ergodox(  // layer 0 : default
        // left hand
        KC_ESC,         KC_1,         KC_2,   KC_3,   KC_4,   KC_5,   TO(QWER),
        KC_TAB,         KC_QUOT,      KC_COMM,KC_DOT, KC_P,   KC_Y,   SCMD_T(KC_NO),
        KC_RALT,        KC_A,         KC_O,   KC_E,   KC_U,   KC_I,
        KC_LSFT,        KC_SCLN,      KC_Q,   KC_J,   KC_K,   KC_X,   LT(SYMB, KC_NO),
        KC_LCTL,        KC_GRAVE,     KC_BSLS,KC_LBRC,KC_RBRC,
                                                      KC_LGUI,KC_LALT,
                                                              KC_HOME,
                                              LT(ESAB,KC_SPC),KC_BSPC,LT(SYMB, KC_END),
        // right hand
             TO(QWER),    KC_6,   KC_7,  KC_8,   KC_9,   KC_0,             KC_EQL,
             MEH_T(KC_NO),KC_F,   KC_G,  KC_C,   KC_R,   KC_L,             KC_SLSH,
                          KC_D,   KC_H,  KC_T,   KC_N,   KC_S,             GUI_T(KC_MINS),
             LT(SYMB,KC_NO),KC_B, KC_M,  KC_W,   KC_V,   KC_Z,             KC_RSFT,
                                 KC_LEFT,KC_DOWN,KC_UP,  KC_RIGHT,         KC_RCTRL,
             KC_RALT,        KC_RGUI,
             KC_PGUP,
             KC_PGDN,KC_ENT, KC_DEL
    ),
/* Keymap 1: Symbol Layer
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |Version  |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |         |      |      | MsUp |      |      |      |           |      |   Up |   7  |   8  |   9  |   *  |   F12  |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |      |MsLeft|MsDown|MsRght|      |------|           |------| Down |   4  |   5  |   6  |   +  |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |      |      |MsDown|      |      |      |           |      |   &  |   1  |   2  |   3  |   \  |        |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | Reset |      |      | LClck| RClck|                                       |      |    . |   0  |   =  | Reset|
 *   `-----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       | Led- | Led+ |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 | LClck| RClck|------|       |------|Toggle|Breath|
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// SYMBOLS
[SYMB] = LAYOUT_ergodox(
       // left hand
       VRSN,   KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_TRNS,
       EPRM,   KC_TRNS,KC_TRNS,KC_MS_U,KC_TRNS,KC_TRNS,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_MS_L,KC_MS_D,KC_MS_R,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_MS_D,KC_TRNS,KC_TRNS,KC_TRNS,
         RESET,KC_TRNS,KC_TRNS,KC_BTN1,KC_BTN2,
                                       KC_TRNS,KC_TRNS,
                                               KC_TRNS,
                               KC_BTN1,KC_BTN2,KC_TRNS,
       // right hand
       VRSN,    KC_F6,   KC_F7,  KC_F8,   KC_F9,   KC_F10,  KC_F11,
       KC_TRNS, KC_UP,   KC_P7,  KC_P8,   KC_P9,   KC_PAST, KC_F12,
                KC_DOWN, KC_P4,  KC_P5,   KC_P6,   KC_PPLS, KC_PMNS,
       KC_TRNS, KC_AMPR, KC_P1,  KC_P2,   KC_P3,   KC_PSLS, KC_TRNS,
                         KC_P0,  KC_PDOT, KC_P0,   KC_EQL,  RESET,
       BL_DEC, BL_INC,
       KC_TRNS,
       KC_TRNS,KC_PENT,BL_TOGG
    ),
[QWER] = LAYOUT_ergodox(  // layer 2 : qwerty
        // left hand
        KC_TRNS,        KC_TRNS,      KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,TO(BASE),
        KC_TRNS,        KC_Q,         KC_W,   KC_E,   KC_R,   KC_T,   KC_TRNS,
        KC_TRNS,        KC_A,         KC_S,   KC_D,   KC_F,   KC_G,
        KC_TRNS,        KC_Z,         KC_X,   KC_C,   KC_V,   KC_B,   KC_TRNS,
        KC_TRNS,        KC_TRNS,      KC_TRNS,KC_TRNS,KC_TRNS,
                                                      KC_TRNS,KC_TRNS,
                                                              KC_TRNS,
                                               KC_SPC,KC_TRNS,LT(BASE, KC_TRNS),
        // right hand
             TO(BASE),    KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,         KC_TRNS,
             KC_TRNS,     KC_Y,   KC_U,  KC_I,   KC_O,   KC_P,             KC_TRNS,
                          KC_H,   KC_J,  KC_K,   KC_L,   KC_SCLN,          KC_TRNS,
             KC_TRNS,     KC_N,   KC_M,  KC_COMM,KC_DOT, CTL_T(KC_SLSH),   KC_TRNS,
                                 KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,          KC_TRNS,
             KC_TRNS,KC_TRNS,
             KC_TRNS,
             KC_TRNS,KC_TRNS,KC_TRNS
    ),
[ESAB] = LAYOUT_ergodox(  // layer 3 : default mirrored
        // left hand
             KC_EQL, KC_0,   KC_9,  KC_8,   KC_7,   KC_6,             TO(BASE),
             KC_SLSH,KC_L,   KC_R,  KC_C,   KC_G,   KC_F,             MEH_T(KC_NO),
             GUI_T(KC_MINS), KC_S,   KC_N,  KC_T,   KC_H,   KC_D,
             KC_RSFT,        KC_Z,   KC_V,  KC_W,   KC_M,   KC_B,     KC_ENT,
             KC_RCTRL,       KC_LEFT,KC_DOWN,KC_UP,  KC_RIGHT,
                                                      KC_TRNS,KC_TRNS,
                                                              KC_TRNS,
                                              KC_TRNS,KC_TRNS,KC_TRNS,
        // right hand
          TO(BASE),     KC_5,         KC_4,   KC_3,   KC_2,   KC_1,   KC_ESC,
          SCMD_T(KC_NO),KC_Y,         KC_P,   KC_DOT, KC_COMM,KC_QUOT,KC_TAB,
                        KC_I,         KC_U,   KC_E,   KC_O,   KC_A,   KC_RALT,
        LT(SYMB, KC_NO),KC_X,         KC_K,   KC_J,   KC_Q,   KC_SCLN,KC_LSFT,
                        KC_RBRC,      KC_LBRC,KC_BSLS,KC_GRAVE,KC_LCTL,
             KC_TRNS,        KC_TRNS,
             KC_TRNS,
             KC_TRNS,KC_TRNS,KC_TRNS
    ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // dynamically generate these.
    case EPRM:
      if (record->event.pressed) {
        eeconfig_init();
      }
      return false;
      break;
    case VRSN:
      if (record->event.pressed) {
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      return false;
      break;
    case RGB_SLD:
      if (record->event.pressed) {
        #ifdef RGBLIGHT_ENABLE
          rgblight_mode(1);
        #endif
      }
      return false;
      break;
  }
  return true;
}

#ifdef ST7565_ENABLE
void st7565_task_user(void) {
  if (is_keyboard_master()) {
    st7565_write_P(PSTR("L: "), false);
    switch (get_highest_layer(layer_state)) {
      case BASE:
        st7565_write_P(PSTR("REPA\n"), false);
        ergodox_infinity_lcd_color(UINT16_MAX / 2, UINT16_MAX / 2, UINT16_MAX / 2);
        break;
      case SYMB:
        st7565_write_P(PSTR("SYMB\n"), false);
        ergodox_infinity_lcd_color(UINT16_MAX / 2, 0, 0);
        break;
      case QWER:
        st7565_write_P(PSTR("QWERTY\n"), false);
        ergodox_infinity_lcd_color(0, UINT16_MAX / 2, 0);
        break;
      case ESAB:
        st7565_write_P(PSTR("Reversed\n"), false);
        ergodox_infinity_lcd_color(0, 0, UINT16_MAX / 2);
        break;
      default:
        st7565_write_ln_P(PSTR("???\n"), false);
    }

    // LED status
    led_t led_state = host_keyboard_led_state();
    st7565_write_P(led_state.num_lock ? PSTR("NUM ") : PSTR("    "), false);
    st7565_write_P(led_state.caps_lock ? PSTR("CAP ") : PSTR("    "), false);
    st7565_write_P(led_state.scroll_lock ? PSTR("SCR ") : PSTR("    "), false);
  } else {
    // Draw logo
    static const char qmk_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xB0, 0xB1, 0xB2, 0xB3, 0xB4,
        0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0x00
    };

    st7565_write(qmk_logo, false);
    st7565_write("  Infinity  Ergodox  ", false);
  }
}
#endif
