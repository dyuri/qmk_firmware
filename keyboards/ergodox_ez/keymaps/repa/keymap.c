#include QMK_KEYBOARD_H
#include "version.h"

#define BASE 0 // default layer
#define SYMB 1 // symbols
#define QWER 2 // media keys
#define ESAB 3 // mirrored base

enum custom_keycodes {
#ifdef ORYX_CONFIGURATOR
    VRSN = EZ_SAFE_RANGE,
#else
    VRSN = SAFE_RANGE,
#endif
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
        KC_ESC,         KC_1,         KC_2,   KC_3,   KC_4,   KC_5,   TG(QWER),
        KC_TAB,         KC_QUOT,      KC_COMM,KC_DOT, KC_P,   KC_Y,   SCMD_T(KC_NO),
        KC_RALT,        KC_A,         KC_O,   KC_E,   KC_U,   KC_I,
        KC_LSFT,        KC_SCLN,      KC_Q,   KC_J,   KC_K,   KC_X,   LT(SYMB, KC_NO),
        KC_LCTL,        KC_GRAVE,     KC_BSLS,KC_LBRC,KC_RBRC,
                                                      KC_LGUI,KC_LALT,
                                                              KC_HOME,
                                              LT(ESAB,KC_SPC),KC_BSPC,LT(SYMB, KC_END),
        // right hand
             TG(QWER),    KC_6,   KC_7,  KC_8,   KC_9,   KC_0,             KC_EQL,
             MEH_T(KC_NO),KC_F,   KC_G,  KC_C,   KC_R,   KC_L,             KC_SLSH,
                          KC_D,   KC_H,  KC_T,   KC_N,   KC_S,             GUI_T(KC_MINS),
             KC_FN1,      KC_B,   KC_M,  KC_W,   KC_V,   KC_Z,             KC_RSFT,
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
       KC_TRNS,KC_TRNS,KC_TRNS,KC_MS_U,KC_TRNS,KC_TRNS,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_MS_L,KC_MS_D,KC_MS_R,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_MS_D,KC_TRNS,KC_TRNS,KC_TRNS,
         RESET,KC_TRNS,KC_TRNS,KC_BTN1,KC_BTN2,
                                       KC_TRNS,KC_TRNS,
                                               KC_TRNS,
                               KC_BTN1,KC_BTN2,KC_TRNS,
       // right hand
       KC_TRNS, KC_F6,   KC_F7,  KC_F8,   KC_F9,   KC_F10,  KC_F11,
       KC_TRNS, KC_UP,   KC_P7,  KC_P8,   KC_P9,   KC_PAST, KC_F12,
                KC_DOWN, KC_P4,  KC_P5,   KC_P6,   KC_PPLS, KC_PMNS,
       KC_TRNS, KC_AMPR, KC_P1,  KC_P2,   KC_P3,   KC_PSLS, KC_TRNS,
                         KC_P0,  KC_PDOT, KC_P0,   KC_EQL,  RESET,
       BL_DEC, BL_INC,
       KC_TRNS,
       KC_TRNS,BL_TOGG,BL_BRTG
    ),
[QWER] = LAYOUT_ergodox(  // layer 2 : qwerty
        // left hand
        KC_TRNS,        KC_TRNS,      KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
        KC_TRNS,        KC_Q,         KC_W,   KC_E,   KC_R,   KC_T,   KC_TRNS,
        KC_TRNS,        KC_A,         KC_S,   KC_D,   KC_F,   KC_G,
        KC_TRNS,        KC_Z,         KC_X,   KC_C,   KC_V,   KC_B,   KC_TRNS,
        KC_TRNS,        KC_TRNS,      KC_TRNS,KC_TRNS,KC_TRNS,
                                                      KC_TRNS,KC_TRNS,
                                                              KC_TRNS,
                                               KC_SPC,KC_TRNS,LT(BASE, KC_TRNS),
        // right hand
             KC_TRNS,     KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,         KC_TRNS,
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
             KC_EQL, KC_0,   KC_9,  KC_8,   KC_7,   KC_6,             KC_NO,
             KC_SLSH,KC_L,   KC_R,  KC_C,   KC_G,   KC_F,             MEH_T(KC_NO),
             GUI_T(KC_MINS), KC_S,   KC_N,  KC_T,   KC_H,   KC_D,
             KC_RSFT,        KC_Z,   KC_V,  KC_W,   KC_M,   KC_B,     KC_ENT,
             KC_RCTRL,       KC_LEFT,KC_DOWN,KC_UP,  KC_RIGHT,
                                                      KC_LGUI,KC_LALT,
                                                              KC_HOME,
                                               KC_SPC,KC_BSPC,LT(SYMB, KC_END),
        // right hand
             KC_NO,     KC_5,         KC_4,   KC_3,   KC_2,   KC_1,   KC_ESC,
          SCMD_T(KC_NO),KC_Y,         KC_P,   KC_DOT, KC_COMM,KC_QUOT,KC_TAB,
                        KC_I,         KC_U,   KC_E,   KC_O,   KC_A,   KC_RALT,
        LT(SYMB, KC_NO),KC_X,         KC_K,   KC_J,   KC_Q,   KC_SCLN,KC_LSFT,
                        KC_RBRC,      KC_LBRC,KC_BSLS,KC_GRAVE,KC_LCTL,
             KC_RALT,        KC_RGUI,
             KC_PGUP,
             KC_PGDN,KC_ENT, KC_RALT
    ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch (keycode) {
            case VRSN:
                SEND_STRING(QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
                return false;
        }
    }
    return true;
}

// Runs just one time when the keyboard initializes.
void keyboard_post_init_user(void) {
#ifdef RGBLIGHT_COLOR_LAYER_0
    rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
};

// Runs whenever there is a layer state change.
layer_state_t layer_state_set_user(layer_state_t state) {
    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();

    uint8_t layer = get_highest_layer(state);
    switch (layer) {
        case 0:
#ifdef RGBLIGHT_COLOR_LAYER_0
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
            break;
        case 1:
            ergodox_right_led_1_on();
#ifdef RGBLIGHT_COLOR_LAYER_1
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_1);
#endif
            break;
        case 2:
            ergodox_right_led_2_on();
#ifdef RGBLIGHT_COLOR_LAYER_2
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_2);
#endif
            break;
        case 3:
            ergodox_right_led_3_on();
#ifdef RGBLIGHT_COLOR_LAYER_3
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_3);
#endif
            break;
        case 4:
            ergodox_right_led_1_on();
            ergodox_right_led_2_on();
#ifdef RGBLIGHT_COLOR_LAYER_4
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_4);
#endif
            break;
        case 5:
            ergodox_right_led_1_on();
            ergodox_right_led_3_on();
#ifdef RGBLIGHT_COLOR_LAYER_5
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_5);
#endif
            break;
        case 6:
            ergodox_right_led_2_on();
            ergodox_right_led_3_on();
#ifdef RGBLIGHT_COLOR_LAYER_6
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
#endif
            break;
        case 7:
            ergodox_right_led_1_on();
            ergodox_right_led_2_on();
            ergodox_right_led_3_on();
#ifdef RGBLIGHT_COLOR_LAYER_7
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_7);
#endif
            break;
        default:
            break;
    }

    return state;
};
