#include QMK_KEYBOARD_H
#include "sendstring_german.h"
#include "keymap_german.h"

#define SCREENSAVE_DELAY 110000  //configure how long to wait after last activity. 120000ms = 2 mins

uint32_t last_activity_timer = 0;

void matrix_scan_user(void) {
    if (last_activity_timer) {                                             //if screensaver mode is active
        if (timer_elapsed32(last_activity_timer) > SCREENSAVE_DELAY) {  //and no key has been pressed in more than SCREENSAVE_DELAY ms
            tap_code16(KC_F13);                                         //  tap F13
            last_activity_timer = timer_read32();                       //  reset last_activity_timer
        }
    }
}

const qk_ucis_symbol_t ucis_symbol_table[] = UCIS_TABLE(
    UCIS_SYM("poop", 0x1F4A9),                // 💩
    UCIS_SYM("rofl", 0x1F923),                // 🤣

    UCIS_SYM("cuba", 0x1F1E8, 0x1F1FA),       // 🇨🇺
    UCIS_SYM("look", 0x0CA0, 0x005F, 0x0CA0)  // ಠ_ಠ
);

enum custom_keycodes {
    QMKBEST = SAFE_RANGE,
    NO_SLEEP,
    QMKBT,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        last_activity_timer = 0;  //turn off screensaver mode on any keypress
    }
    switch (keycode) {
    case NO_SLEEP:
        if (record->event.pressed) {               //if NO_SLEEP is pressed
            last_activity_timer = timer_read32();  //reset timer
            if(last_activity_timer!=0) {
                SEND_STRING("OK");
            }
        }
        break;
    case QMKBT:
        if (record->event.pressed) {
            SEND_STRING("`");
        } else {
            // when keycode QMKBEST is released
        }
        break;
    case QMKBEST:
        if (record->event.pressed) {
//send_unicode_string("(ノಠ痊ಠ)ノ彡┻━┻");
            SEND_STRING("https://github.com/mknj/qmk_firmware/blob/develop/keyboards/markus/keymaps/default/keymap.c");
        } else {
            // when keycode QMKBEST is released
        }
        break;
    }
    return true;
};


void keyboard_post_init_user(void) {
  // Customise these values to desired behaviour
  debug_enable=true;
  debug_matrix=true;
  debug_keyboard=true;
  //debug_mouse=true;
}
// DEL RETURN RIGHT F7 F1 F3 F5 DOWN
// 3 W A 4 Z S E LSHIFT
// 5 R D 6 C F T X
// 7 Y G 8 B H U V
// 9 I J 0 M K O N
// PLUS P L MINUS DOT COLON AT COMMA
// POUND STAR SEMICOLON RSHIFT EQUAL UP SLASH
// 1 LEFT CTRL 2 SPACE COMMODORE Q STOP

// send shifted keys https://github.com/qmk/qmk_firmware/issues/6175
// tab dance https://github.com/samhocevar-forks/qmk-firmware/blob/master/docs/feature_tap_dance.md
// https://github.com/qmk/qmk_firmware/blob/master/docs/keycodes.md
// https://github.com/qmk/qmk_firmware/blob/master/docs/config_options.md
// #define MATRIX_HAS_GHOST
// https://github.com/qmk/qmk_firmware/blob/develop/docs/platformdev_rp2040.md
// https://golem.hu/article/pro-micro-pinout/
// https://www.dg1sfj.de/index.php/elektronik/selbstbau/38-c64-und-sx64-keyboard-matrix

/*  */
enum tap_dance {
    TD_1 ,
    TD_2 ,
};

void td_1_finished(qk_tap_dance_state_t *state, void *user_data)
{
    if (state->count == 1) {
        layer_on(1);
    } else {
        layer_on(3);
    }
}

void td_1_reset(qk_tap_dance_state_t *state, void *user_data)
{
    if (state->count == 1) {
        layer_off(1);
    } else {
        layer_off(3);
    }
}
void td_2_finished(qk_tap_dance_state_t *state, void *user_data)
{
    switch(state->count) {
        case 1:
            layer_on(2);
            break;
        case 2:
          layer_on(2);
          register_code(KC_LCTL);
            break;
        case 3:
          layer_on(2);
          register_code(KC_LCTL);
          register_code(KC_LSFT);
    }
}

void td_2_reset(qk_tap_dance_state_t *state, void *user_data)
{
    switch(state->count) {
        case 1:
            layer_off(2);
            break;
        case 2:
          unregister_code(KC_LCTL);
          layer_off(2);
            break;
        case 3:
          unregister_code(KC_LSFT);
          unregister_code(KC_LCTL);
          layer_off(2);
    }
}


qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_1] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_1_finished, td_1_reset),
    [TD_2] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_2_finished, td_2_reset),
};

#define MY_SPC LCTL_T(KC_SPC)
#define MY_ENT LALT_T(KC_ENT)
#define MY_BSPC RALT_T(KC_BSPC)

#define MY_P LT(4,KC_P)
#define MY_ESC LT(3,KC_ESC)
#define MY_MINS RSFT_T(DE_MINS)

#define MY_Q LGUI_T(KC_Q)
#define MY_A LT(1,KC_A)
#define MY_Z LSFT_T(KC_Z)
#define MY_CUT LCTL(KC_X)
#define MY_COPY LCTL(KC_C)
#define MY_PASTE LCTL(KC_V)
const uint16_t keymaps[DYNAMIC_KEYMAP_LAYER_COUNT][MATRIX_ROWS][MATRIX_COLS] = {

[0] = {
{ XXXXXXX , MY_Q    , KC_W    , KC_E    , KC_R    , KC_T    , KC_Y    , KC_U    , KC_I    , KC_O    , MY_P    , KC_3},
{ XXXXXXX , MY_A    , KC_S    , KC_D    , KC_F    , KC_G    , KC_H    , KC_J    , KC_K    , KC_L    , MY_ESC  , XXXXXXX},
{ XXXXXXX , MY_Z    , KC_X    , KC_C    , KC_V    , KC_B    , KC_N    , KC_M    , KC_COMM , KC_DOT  , MY_MINS , XXXXXXX},
{ MY_SPC  , XXXXXXX , QK_BOOT , XXXXXXX , XXXXXXX , TD(TD_2), MY_BSPC , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , MY_ENT },
},
[1] = { // PROGRAMMING SYMBOLS (A)                          |
{ XXXXXXX , _______ , XXXXXXX , DE_LBRC , DE_RBRC , DE_HASH , DE_EXLM , DE_LABK , DE_RABK , DE_EQL  , DE_AMPR , XXXXXXX},
{ XXXXXXX , _______ , XXXXXXX , DE_LCBR , DE_RCBR , DE_ASTR , DE_QUES , DE_LPRN , DE_RPRN , DE_SLSH , DE_BSLS , XXXXXXX},
{ XXXXXXX , _______ , DE_DLR  , DE_PIPE , DE_TILD , QMKBEST , NO_SLEEP, DE_PERC , DE_DQUO , DE_QUOT , DE_UNDS , XXXXXXX},
{ _______ , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , _______},
},
[2] = { //  CURSOR AND NUMBERS (LTHUMB2)                    |
{ XXXXXXX , KC_BSPC , KC_PGUP , KC_UP   , KC_PGDN , KC_DEL  , XXXXXXX , KC_7    , KC_8    , KC_9    , XXXXXXX , XXXXXXX},
{ XXXXXXX , KC_HOME , KC_LEFT , KC_DOWN , KC_RIGHT, KC_END  , KC_0    , KC_4    , KC_5    , KC_6    , DE_PLUS , XXXXXXX},
{ XXXXXXX , KC_TAB  , MY_CUT  , MY_COPY , MY_PASTE, KC_F15  , XXXXXXX , KC_1    , KC_2    , KC_3    , _______ , XXXXXXX},
{ _______ , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , KC_DEL  , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , _______},
},
[3] = { //  UMLAUTS AND OTHER LANGUAGESYMBOLS (ö)           |
{ XXXXXXX , DE_SUP2 , DE_SUP3 , DE_EURO , DE_SECT , KC_MPLY , DE_GRV , DE_UDIA  , KC_APP  , DE_ODIA , XXXXXXX , XXXXXXX},
{ XXXXXXX , DE_ADIA , DE_SS   , DE_AT   , KC_WREF , DE_DEG  , DE_CIRC , KC_WHOM , KC_CALC , KC_WSCH , XXXXXXX , XXXXXXX},
{ XXXXXXX , KC_F2   , KC_F10  , KC_F11  , KC_F12  , KC_F1   , DE_ACUT , DE_MICR , KC_PSCR , QMKBT   , _______ , XXXXXXX},
{ _______ , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , _______},
},
[4] = { //, MOUSE  (P)                                      |
{ XXXXXXX , NO_SLEEP, KC_MS_U , KC_MS_U , XXXXXXX , XXXXXXX , XXXXXXX , KC_WH_D , KC_WH_L , XXXXXXX , _______ , XXXXXXX},
{ XXXXXXX , XXXXXXX , KC_MS_L , KC_MS_D , KC_MS_R , XXXXXXX , XXXXXXX , KC_BTN1 , KC_BTN2 , KC_BTN3 , EE_CLR  , XXXXXXX},
{ XXXXXXX , KC_BRID , KC_BRIU , KC_VOLD , KC_VOLU , KC_MUTE , XXXXXXX , KC_WH_U , KC_WH_R , XXXXXXX , QK_BOOT , XXXXXXX},
{ _______ , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , KC_BTN1}, 
}};
