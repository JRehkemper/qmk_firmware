#include QMK_KEYBOARD_H
#include "keymap_german.h"

// Layer Definitions
enum layers {
    _ALPHA = 0,
    _LOWER,
    _UPPER
};

// Custom Keycodes for Smart OS Symbols
/*enum custom_keycodes {
    MY_OS_TOGG = SAFE_RANGE, // Esc + M toggle
    SM_AT,   // @ (AltGr+Q or Alt+L)
    SM_EURO, // € (AltGr+E or Alt+E)
    SM_TILD, // ~ (AltGr++ or Alt+N)
    SM_PIPE, // | (AltGr+< or Alt+7)
    SM_BSLS, // \ (AltGr+ß or S+Alt+7)
    SM_LCBR, // {
    SM_RCBR, // }
    SM_LBRC, // [
    SM_RBRC, // ]
};*/

// --- COMBOS ---
// Define the keys that trigger the combo
/*const uint16_t PROGMEM slash_combo[] = {KC_S, KC_L, COMBO_END};
const uint16_t PROGMEM bsls_combo[]  = {KC_LSFT, KC_S, KC_L, COMBO_END};
const uint16_t PROGMEM pipe_combo[]  = {KC_F, KC_J, COMBO_END};
const uint16_t PROGMEM tab_combo[]   = {KC_D, KC_K, COMBO_END};
const uint16_t PROGMEM copy_combo[]  = {KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM past_combo[]  = {KC_C, KC_V, COMBO_END};
const uint16_t PROGMEM cut_combo[]   = {KC_X, KC_V, COMBO_END};
const uint16_t PROGMEM os_togg_combo[]= {KC_ESC, KC_M, COMBO_END};

*/
combo_t key_combos[] = {
    /*COMBO(slash_combo, KC_SLSH),
    COMBO(bsls_combo, SM_BSLS),
    COMBO(pipe_combo, SM_PIPE),
    COMBO(tab_combo, KC_TAB),
    COMBO(copy_combo, LCTL(KC_C)),
    COMBO(past_combo, LCTL(KC_V)),
    COMBO(cut_combo, LCTL(KC_X)),
    COMBO(os_togg_combo, MY_OS_TOGG),*/
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


#if defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {

};
#endif // defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)


// Tap Dance declarations
enum {
    TD_Q_AT,
    TD_E_EURO,
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
    [TD_Q_AT] = ACTION_TAP_DANCE_DOUBLE(DE_Q, KC_AT),
    [TD_E_EURO] = ACTION_TAP_DANCE_DOUBLE(DE_E, MT(MOD_LSFT, DE_E)),
    [TD_A] = ACTION_TAP_DANCE_DOUBLE(DE_A, DE_ADIA),
    [TD_S] = ACTION_TAP_DANCE_DOUBLE(DE_S, DE_SS),
    [TD_U] = ACTION_TAP_DANCE_DOUBLE(DE_U, DE_UDIA),
    [TD_O] = ACTION_TAP_DANCE_DOUBLE(DE_O, DE_ODIA),
    [TD_PLUS] = ACTION_TAP_DANCE_DOUBLE(KC_PLUS, KC_ASTR),
    [TD_MINUS] = ACTION_TAP_DANCE_DOUBLE(DE_MINS, DE_TILD),
    [TD_QUOTES] = ACTION_TAP_DANCE_DOUBLE(DE_DQUO, DE_QUOT),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_ALPHA] = LAYOUT(
  	KC_NO,   	DE_1,    	DE_2,    	DE_3,    	    DE_4,    	        DE_5,                      					DE_6,       DE_7,               DE_8,           DE_9,           DE_0,       KC_NO,
  	KC_NO,   	TD(TD_Q_AT),DE_W,    	TD(TD_E_EURO),  DE_R,    	        DE_T,                      					DE_Z,       TD(TD_U),           DE_I,           TD(TD_O),       DE_P,       KC_NO,
  	KC_NO,   	TD(TD_A),   TD(TD_S),   DE_D,    	    DE_F,    	        DE_G,                      					DE_H,       DE_J,               DE_K,           DE_L,           KC_TAB,      KC_NO,
    KC_NO,   	DE_Y,    	LCMD_T(DE_X),LOPT_T(DE_C),  LCTL_T(DE_V),    	DE_B,		KC_NO,         		KC_NO,		DE_N,       LCTL_T(DE_M),       LOPT_T(DE_COMM),LCMD_T(DE_DOT), DE_MINS,    KC_NO,
            				KC_NO,   	KC_ESC,  	    MO(_LOWER),         KC_LSFT, 	KC_BSPC,			KC_ENT,		KC_SPC,     MO(_UPPER),         DE_SLSH,        KC_NO
),

[_LOWER] = LAYOUT(
    KC_F1,      KC_F2,      KC_F3,      KC_F4,          KC_F5,              KC_F6,                                      KC_F7,      KC_F8,              KC_F9,          KC_F10,         KC_F11,     KC_F12,
    KC_NO,      KC_NO,      KC_NO,      KC_NO,          KC_NO,              KC_NO,                                      KC_NO,      KC_KP_7,            KC_KP_8,        KC_KP_9,        KC_NO,      KC_NO,
    KC_NO,      KC_NO,      KC_NO,      KC_NO,          KC_NO,              KC_NO,                                      KC_NO,      KC_KP_4,            KC_KP_5,        KC_KP_6,        KC_NO,      KC_NO,
    KC_NO,      KC_NO,      KC_NO,      KC_NO,          KC_NO,              KC_NO,      KC_NO,              KC_NO,      KC_NO,      KC_KP_1,            KC_KP_2,        KC_KP_3,        KC_NO,      KC_NO,
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

// --- LOGIC ENGINE ---
//bool is_mac_mode = false;

/*void tap_smart_key(uint16_t pc_mod, uint16_t pc_key, uint16_t mac_mod, uint16_t mac_key) {
    if (is_mac_mode) {
        register_code(mac_mod); tap_code(mac_key); unregister_code(mac_mod);
    } else {
        register_code(pc_mod); tap_code(pc_key); unregister_code(pc_mod);
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch (keycode) {
            case MY_OS_TOGG:
                is_mac_mode = !is_mac_mode;
                keymap_config.swap_lalt_lgui = is_mac_mode;
                eeconfig_update_keymap(keymap_config.raw);
                return false;
            case SM_AT:   tap_smart_key(KC_RALT, KC_Q, KC_LALT, KC_L); return false;
            case SM_EURO: tap_smart_key(KC_RALT, KC_E, KC_LALT, KC_E); return false;
            case SM_TILD: tap_smart_key(KC_RALT, KC_RBRC, KC_LALT, KC_N); return false;
            case SM_PIPE: tap_smart_key(KC_RALT, KC_NONUS_BACKSLASH, KC_LALT, KC_7); return false;
            case SM_BSLS:
                if (is_mac_mode) {
                    register_code(KC_LSFT); register_code(KC_LALT); tap_code(KC_7); unregister_code(KC_LALT); unregister_code(KC_LSFT);
                } else {
                    register_code(KC_RALT); tap_code(KC_MINS); unregister_code(KC_RALT);
                }
                return false;
            case SM_LCBR: tap_smart_key(KC_RALT, KC_7, KC_LALT, KC_8); return false;
            case SM_RCBR: tap_smart_key(KC_RALT, KC_0, KC_LALT, KC_9); return false;
            case SM_LBRC: tap_smart_key(KC_RALT, KC_8, KC_LALT, KC_5); return false;
            case SM_RBRC: tap_smart_key(KC_RALT, KC_9, KC_LALT, KC_6); return false;
        }
    }
    return true;
}*/
