#include QMK_KEYBOARD_H
#include "keymap_german.h"

// Layer Definitions
enum layers {
    _ALPHA = 0,
    _LOWER,
    _UPPER
};

// Custom Keycodes for Smart OS Symbols
enum custom_keycodes {
    SM_AT, //(AltGr+Q or Alt+L)
    SM_TILD, // ~ (AltGr++ or Alt+N)
    SM_PIPE, // | (AltGr+< or Alt+7)
    SM_EURO, // € (AltGr+E or Alt+E)
    SM_BSLS, // \ (AltGr+ß or S+Alt+7)
    SM_COPY,
    SM_PASTE
    /*SM_LCBR, // {
    SM_RCBR, // }
    SM_LBRC, // [
    SM_RBRC, // ]   
    MY_OS_TOGG = SAFE_RANGE, // Esc + M toggle
    */
};

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    os_variant_t host = detected_host_os();
    switch(keycode) {
        // match custom keycodes
        case SM_AT:
            if (host == OS_MACOS) {
                // execute this keycode
                tap_code16(RALT(DE_L));
            } else {
                tap_code16(RALT(DE_Q));
            }
            // Do not process further
            return false;
        case SM_TILD:
            if (host == OS_MACOS) {
                tap_code16(RALT(DE_N));
            } else {
                tap_code16(RALT(DE_PLUS));
            }
            return false;
        case SM_EURO:
            if (host == OS_MACOS) {
                tap_code16(RALT(DE_E));
            } else {
                tap_code16(RCMD(DE_E));
            }
            return false;
        case SM_PIPE:
            // check for keydown event to prevent second character on keyup event
            if (record->event.pressed) {
                if (host == OS_MACOS) {
                    tap_code16(RALT(DE_7));
                } else {
                    tap_code16(DE_PIPE);
                }
            }
            return false;
        case SM_BSLS:
            if (record->event.pressed) {
                if (host == OS_MACOS) {
                    tap_code16(RALT(DE_7));
                } else {
                    tap_code16(DE_BSLS);
                }
            }
            return false;
        default:
            return true;
    }
}

// Tap Dance declarations
enum {
    TD_Q_AT,
    TD_E_EURO,  // never triggers €
    TD_A,
    TD_S,
    TD_U,
    TD_O,
    TD_PLUS,
    TD_MINUS,
    TD_QUOTES,
};

// Tap Dance definitions
tap_dance_action_t tap_dance_actions[] = {
    [TD_Q_AT] = ACTION_TAP_DANCE_DOUBLE(DE_Q, DE_AT),
    [TD_E_EURO] = ACTION_TAP_DANCE_DOUBLE(DE_E, SM_EURO),
    [TD_A] = ACTION_TAP_DANCE_DOUBLE(DE_A, DE_ADIA),
    [TD_S] = ACTION_TAP_DANCE_DOUBLE(DE_S, DE_SS),
    [TD_U] = ACTION_TAP_DANCE_DOUBLE(DE_U, DE_UDIA),
    [TD_O] = ACTION_TAP_DANCE_DOUBLE(DE_O, DE_ODIA),
    [TD_PLUS] = ACTION_TAP_DANCE_DOUBLE(KC_PLUS, KC_ASTR),
    [TD_MINUS] = ACTION_TAP_DANCE_DOUBLE(DE_MINS, DE_TILD),
    [TD_QUOTES] = ACTION_TAP_DANCE_DOUBLE(DE_DQUO, DE_QUOT),
};

// --- COMBOS ---
// Define the keys that trigger the combo
const uint16_t PROGMEM pipe_combo[]  = {KC_F, KC_J, COMBO_END};
const uint16_t PROGMEM slsh_combo[]  = {TD(TD_S), KC_L, COMBO_END}; 
const uint16_t PROGMEM bsls_combo[]  = {KC_LSFT, TD(TD_S), KC_L, COMBO_END};
const uint16_t PROGMEM tab_combo[]   = {KC_D, KC_K, COMBO_END};
const uint16_t PROGMEM copy_combo[]  = {DE_Y, LGUI_T(DE_C), COMBO_END};
const uint16_t PROGMEM past_combo[]  = {DE_Y, LCTL_T(DE_V), COMBO_END};
const uint16_t PROGMEM cut_combo[]   = {DE_Y, LALT_T(DE_X), COMBO_END};

combo_t key_combos[] = {
    COMBO(pipe_combo, SM_PIPE),
    COMBO(slsh_combo, DE_SLSH),
    COMBO(bsls_combo, SM_BSLS),
    COMBO(tab_combo, KC_TAB),
    COMBO(copy_combo, C(KC_C)),
    COMBO(past_combo, C(KC_V)),
    COMBO(cut_combo, C(KC_X)),
};




const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_ALPHA] = LAYOUT(
  	KC_ESC,   	DE_1,    	DE_2,    	DE_3,    	    DE_4,    	        DE_5,                      					DE_6,       DE_7,               DE_8,           DE_9,           DE_0,       KC_TRNS,
  	KC_TRNS,	TD(TD_Q_AT),DE_W,    	TD(TD_E_EURO),  DE_R,    	        DE_T,                      					DE_Z,       TD(TD_U),           DE_I,           TD(TD_O),       DE_P,       KC_TRNS,
  	KC_TRNS,	TD(TD_A),   TD(TD_S),   DE_D,    	    DE_F,    	        DE_G,                      					DE_H,       DE_J,               DE_K,           DE_L,           KC_TAB,     KC_TRNS,
    KC_TRNS,	DE_Y,    	LALT_T(DE_X),LGUI_T(DE_C),  LCTL_T(DE_V),    	DE_B,		KC_TRNS,      		KC_TRNS,	DE_N,       LCTL_T(DE_M),       LGUI_T(DE_COMM),LALT_T(DE_DOT), DE_MINS,    KC_TRNS,
            				KC_TRNS,	KC_ESC,  	    MO(_LOWER),         KC_LSFT, 	KC_BSPC,			KC_ENT,		KC_SPC,     MO(_UPPER),         DE_SLSH,        KC_TRNS
),

[_LOWER] = LAYOUT(
    KC_TRNS,    KC_F1,      KC_F2,      KC_F3,          KC_F4,              KC_F5,                                      KC_F6,      KC_F7,              KC_F8,          KC_F9,          KC_F10,     KC_F11,
    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,        KC_TRNS,            KC_TRNS,                                    KC_TRNS,    KC_KP_7,            KC_KP_8,        KC_KP_9,        KC_TRNS,    KC_F12,
    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,        KC_TRNS,            KC_TRNS,                                    KC_TRNS,    KC_KP_4,            KC_KP_5,        KC_KP_6,        KC_TRNS,    KC_TRNS,
    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,        KC_TRNS,            KC_TRNS,    KC_TRNS,            KC_TRNS,    KC_TRNS,    KC_KP_1,            KC_KP_2,        KC_KP_3,        KC_TRNS,    KC_TRNS,
                            KC_NO,      KC_TRNS,        KC_TRNS,            KC_TRNS,    KC_TRNS,            KC_TRNS,    KC_TRNS,    KC_PDOT,            KC_KP_0,        KC_PCMM
),

[_UPPER] = LAYOUT(
    KC_NO,      KC_CIRC,    KC_NO,      KC_NO,          KC_NO,              KC_NO,                                      KC_NO,      KC_NO,              KC_NO,          KC_NO,          KC_NO,      KC_NO,
    KC_NO,      KC_LCBR,    KC_RCBR,    DE_LBRC,        DE_RBRC,            KC_DLR,                                     KC_HOME,    KC_PGDN,            KC_PGUP,        KC_END,         KC_NO,      KC_NO,
    KC_NO,      TD(TD_PLUS),TD(TD_MINUS),DE_EQL,        DE_PERC,            DE_AMPR,                                    KC_LEFT,    KC_DOWN,            KC_UP,          KC_RGHT,        KC_NO,      KC_NO,
    KC_NO,      KC_LABK,    KC_RABK,    TD(TD_QUOTES),  KC_HASH,            DE_ACUT,    KC_NO,              KC_NO,      KC_NO,      KC_NO,              KC_NO,          KC_NO,          KC_NO,      KC_NO,
                            KC_NO,      KC_TRNS,        KC_TRNS,            KC_TRNS,    KC_TRNS,            KC_TRNS,    KC_TRNS,    KC_TRNS,            KC_TRNS,        KC_NO
)
};

/* Second half is addressed from LED 35 to 70 */
const rgblight_segment_t PROGMEM my_layer_0[] = RGBLIGHT_LAYER_SEGMENTS(
        {0,70, HSV_RED}
);

const rgblight_segment_t PROGMEM my_layer_2[] = RGBLIGHT_LAYER_SEGMENTS(
        {0,70, HSV_CYAN}
);

const rgblight_segment_t PROGMEM my_layer_3[] = RGBLIGHT_LAYER_SEGMENTS(
        {0,70, HSV_BLUE}
);

const rgblight_segment_t PROGMEM my_layer_1[] = RGBLIGHT_LAYER_SEGMENTS(
        {0,70, HSV_GREEN}
);

const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    my_layer_0,
    my_layer_1,
	my_layer_2,
	my_layer_3
);

void keyboard_post_init_user(void) {
    rgblight_layers = my_rgb_layers;
}

layer_state_t default_layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(0, layer_state_cmp(state, 0));
    return state;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(1, layer_state_cmp(state, 1));
    rgblight_set_layer_state(2, layer_state_cmp(state, 2));
    rgblight_set_layer_state(3, layer_state_cmp(state, 3));
    return state;
}


/*
#if defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {

};
#endif // defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)
*/
