#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "version.h"

#define BASE 0 // default layer
#define SYM 1 // symbols
#define NAV 2 // navigation and special keys
#define MAC 3 // Mac key combinations (command)
#define WIN 4 // Windows key combinations (control)

#define ALT_TAB LALT(KC_TAB)
#define S_ALT_T LSFT(LALT(KC_TAB))
#define SH_TAB  LSFT(KC_TAB)
#define CTL_Z   LCTL(KC_Z)
#define CTL_X   LCTL(KC_X)
#define CTL_C   LCTL(KC_C)
#define CTL_V   LCTL(KC_V)
#define ShCTL_Z LSFT(LCTL(KC_Z))
#define CTLxZ   CTL_T(KC_Z)
#define CTLxFSL CTL_T(KC_SLSH)
#define CTL_ALT LCTL(KC_LALT)
#define CTL_GRV LCTL(KC_GRV)
#define CMD_Z   LGUI(KC_Z)
#define CMD_X   LGUI(KC_X)
#define CMD_C   LGUI(KC_C)
#define CMD_V   LGUI(KC_V)
#define CMD_SPC LGUI(KC_SPC)
#define CMD_ENT LGUI(KC_ENT)

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  EPRM,
  VRSN,
  RGB_SLD
};
/* Blank template
        // left hand
        _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,

                                                     _______, _______,
                                                              _______,
                                            _______, _______, _______,

        // right hand
        _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,
                 _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,
                          _______, _______, _______, _______, _______,
        _______, _______,
        _______,
        _______, _______, _______
 */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 * under_score, under_scoreunder
 *
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | Grave  |   1  |   2  |   3  |   4  |   5  |AltTab|           |ShAlTb|   6  |   7  |   8  |   9  |   0  |   =    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |   _    |   Q  |   W  |   E  |   R  |   T  |  '   |           |   -  |   Y  |   U  |   I  |   O  |   P  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |(H)NAV  |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |  ;   |   '    |
 * |--------+------+------+------+------+------|  !   |           |   =  |------+------+------+------+------+--------|
 * | LShift |ZxCtrl|   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |/xCtrl| RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *  |  LAlt |(H)SYM|CtlAlt| shTab| Tab  |                                       |   :  |  Esc |CtlAlt|(H)Sym|  RAlt |
 *   `----------------------------------'                                       `----------------------------------'
 *
 *                                        ,-------------.       ,-------------.
 *                                        | Enter| LGui |       |      |        |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | CtlZ |       |Delete|        |      |
 *                                 |BSpace|Space |------|       |------|  Enter |Space |
 *                                 |      |      | Esc  |       |BSpace|        |      |
 *                                 `--------------------'       `----------------------'
 */
[BASE] = LAYOUT_ergodox(  // layer 0 : default
        // left hand
        KC_GRV , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , ALT_TAB,
        KC_UNDS, KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   , KC_QUOT,
        MO(NAV), KC_A   , KC_S   , KC_D   , KC_F   , KC_G   ,
        KC_LSFT, CTLxZ  , KC_X   , KC_C   , KC_V   , KC_B   , KC_EXLM,
        KC_LALT, MO(SYM), CTL_ALT, SH_TAB , KC_TAB ,

                                                     KC_ENT , KC_LGUI,
                                                              CTL_Z  ,
                                            KC_BSPC, KC_SPC , KC_ESC ,

        // right hand
        S_ALT_T,  KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_EQL ,
        KC_MINS,  KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_BSLS,
                  KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, KC_QUOT,
        KC_EQL ,  KC_N   , KC_M   , KC_COMM, KC_DOT , CTLxFSL, KC_RSFT,
                           KC_COLN, KC_ESC , CTL_ALT, MO(SYM), KC_RALT,
        _______, _______,
        KC_DEL ,
        KC_BSPC, KC_ENT , KC_SPC
    ),
/* Keymap 1: Symbol Layer
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |Version  |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |         |   #  |   @  |   {  |   }  |   "  |      |           |      |   +  |   7  |   8  |   9  |   *  |   F12  |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |  XXXXX  |   ^  |   $  |   (  |   )  |   ;  |------|           |------|   -  |   4  |   5  |   6  |   /  |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |    %    |   |  |   &  |   [  |   ]  |   =  |      |           |      |   ,  |   1  |   2  |   3  |      |        |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |       | XXXX |      |   <  |   >  |                                       |   0  |   .  |   *  | XXXX |      |
 *   `-----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// SYMBOLS
[SYM] = LAYOUT_ergodox(
        // left hand
        VRSN   , KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , _______,
        CTL_GRV, KC_HASH, KC_AT  , KC_LCBR, KC_RCBR, KC_DQUO, _______,
        _______, KC_CIRC, KC_DLR , KC_LPRN, KC_RPRN, KC_SCLN,
        KC_PERC, KC_PIPE, KC_AMPR, KC_LBRC, KC_RBRC, KC_EQL , _______,
        _______, _______, KC_UNDS, KC_LABK, KC_RABK,

                                                     _______, _______,
                                                              _______,
                                            _______, _______, _______,

        // right hand
        _______, KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 ,
        _______, KC_PLUS, KC_7   , KC_8   , KC_9   , KC_ASTR, KC_F12 ,
                 KC_MINS, KC_4   , KC_5   , KC_6   , KC_SLSH, _______,
        _______, KC_COMM, KC_1   , KC_2   , KC_3   , _______, _______,
                          KC_0   , KC_DOT , KC_ASTR, _______, _______,
        _______, _______,
        _______,
        _______, _______, _______
),
/* Keymap 2: Navigation and speciality keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           | RESET|      |      |      |      |      |  SLEEP |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      | MsUp |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | XXXXXX |      |MsLeft|MsDown|MsRght|      |------|           |------| Left | Down |  Up  | Right|      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        | GuiZ | GuiX | GuiC | GuiV |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      | XXXX |      | Lclk | Rclk |                                       |      |      |      | XXXX |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | Mclk | WhUp |       | VolUp| Mute |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      | WhDn |       | VolDn| Gui  | Gui  |
 *                                 | Lclk | Rclk |------|       |------|Enter |Space |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// NAVIGATION
[NAV] = LAYOUT_ergodox(
       // left hand
       _______, _______, _______, _______, _______, _______, _______,
       _______, _______, _______, KC_MS_U, _______, _______, _______,
       _______, _______, KC_MS_L, KC_MS_D, KC_MS_R, _______,
       _______, CTL_Z  , CTL_X  , CTL_C  , CTL_V  , _______, _______,
       _______, _______, _______, _______, _______,
                                                    KC_BTN3, KC_WH_U,
                                                             KC_WH_D,
                                           KC_BTN1, KC_BTN2, _______,

       // right hand
       RESET  ,  _______, _______, _______, _______, _______, KC_SLEP,
       _______,  _______, _______, _______, _______, _______, _______,
                 KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, _______, _______,
       _______,  _______, _______, _______, _______, _______, _______,
                          _______, _______, _______, _______, _______,
       KC_VOLU, KC_MUTE,
       KC_VOLD,
       _______, _______, _______
),

//TODO
[MAC] = LAYOUT_ergodox(
        // left hand
        _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, KC_MS_U, _______, _______, _______,
        _______, _______, KC_MS_L, KC_MS_D, KC_MS_R, _______,
        _______, CMD_Z  , CMD_X  , CMD_C  , CMD_V  , _______, _______,
        _______, _______, _______, _______, _______,
                                                     KC_BTN3, KC_WH_U,
                                                              KC_WH_D,
                                            KC_BTN1, KC_BTN2, _______,

        // right hand
        RESET  , _______, _______, _______, _______, _______, KC_SLEP,
        _______, _______, _______, _______, _______, _______, _______,
        KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,
                          _______, _______, _______, _______, _______,
        KC_VOLU, KC_MUTE,
        KC_VOLD,
        _______, CMD_ENT, CMD_SPC
),

};

const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_TAP_TOGGLE(SYM)                // FN1 - Momentary Layer 1 (Symbols)
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
  switch(id) {
    case 0:
      if (record->event.pressed) {
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      break;
    case 1:
      if (record->event.pressed) { // For resetting EEPROM
        eeconfig_init();
      }
      break;
  }
  return MACRO_NONE;
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

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
#ifdef RGBLIGHT_COLOR_LAYER_0
  rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

};

// Runs whenever there is a layer state change.
uint32_t layer_state_set_user(uint32_t state) {
  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();

  uint8_t layer = biton32(state);
  switch (layer) {
      case 0:
        #ifdef RGBLIGHT_COLOR_LAYER_0
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
        #else
          rgblight_init();
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
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
        #endif
        break;
      default:
        break;
    }

  return state;
};
