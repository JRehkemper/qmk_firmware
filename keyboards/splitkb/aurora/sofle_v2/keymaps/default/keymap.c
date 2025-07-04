#include QMK_KEYBOARD_H
#include "keymap_german.h"


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

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[0] = LAYOUT(
            KC_ESC,     DE_1,       DE_2,           DE_3,           DE_4,           DE_5,                                   DE_6,       DE_7,           DE_8,           DE_9,           DE_0,       DE_SS,
            KC_TAB,     DE_Q,       DE_W,           DE_E,           DE_R,           DE_T,                                   DE_Z,       DE_U,           DE_I,           DE_O,           DE_P,       DE_UDIA,
            TG(3),      DE_A,       DE_S,           DE_D,           DE_F,           DE_G,                                   DE_H,       DE_J,           DE_K,           DE_L,           DE_ODIA,    DE_ADIA,
            DE_LABK,    DE_Y,       LALT_T(DE_X),   LGUI_T(DE_C),   LCTL_T(DE_V),   DE_B,       _______,        _______,    DE_N,       LCTL_T(DE_M),   LGUI_T(DE_COMM),LALT_T(DE_DOT), DE_MINS,    DE_HASH,
                                    DF(1),        KC_LCTL,        MO(2),          KC_LSFT,    KC_BSPC,        KC_ENT,     KC_SPC,     MO(2),          KC_LCTL,        KC_RALT
    ),
	[1] = LAYOUT(
            KC_ESC,     DE_1,       DE_2,           DE_3,           DE_4,           DE_5,                                   DE_6,       DE_7,           DE_8,           DE_9,           DE_0,       DE_SS,
            KC_TAB,     DE_Q,       DE_W,           DE_E,           DE_R,           DE_T,                                   DE_Z,       DE_U,           DE_I,           DE_O,           DE_P,       DE_UDIA,
            TG(3),      DE_A,       DE_S,           DE_D,           DE_F,           DE_G,                                   DE_H,       DE_J,           DE_K,           DE_L,           DE_ODIA,    DE_ADIA,
            DE_LABK,    DE_Y,       LCMD_T(DE_X),   LOPT_T(DE_C),   LCTL_T(DE_V),   DE_B,       _______,        _______,    DE_N,       LCTL_T(DE_M),   LOPT_T(DE_COMM),LCMD_T(DE_DOT), DE_MINS,    DE_HASH,
                                    DF(0),        KC_LCMD,        MO(2),          KC_LSFT,    KC_BSPC,        KC_ENT,     KC_SPC,     MO(2),          KC_LCTL,        KC_RALT
    ),

	[2] = LAYOUT(
            DE_CIRC,    KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5,                              KC_F6,      KC_F7,      KC_F8,      KC_F9,      KC_F10,     KC_F11,
            _______,    DE_LBRC,    DE_RBRC,    DE_LCBR,    DE_RCBR,    _______,                            DE_LPRN,    DE_RPRN,    DE_PLUS,    DE_MINS,    _______,    KC_F12,
            _______,    KC_MS_LEFT, KC_MS_DOWN, KC_MS_UP,   KC_MS_RIGHT,DE_PERC,                            KC_LEFT,    KC_DOWN,    KC_UP,      KC_RIGHT,   _______,    _______,
            DE_PIPE,    DE_EQL,     KC_MS_BTN1, KC_MS_BTN3, KC_MS_BTN2, DE_RCBR, _______,       _______,    KC_HOME,    KC_PGDN,    KC_PGUP,    KC_END,     _______,    DE_ACUT,
                                    _______,    _______,    _______,    _______, KC_DEL,        _______,    _______,    _______,    _______,    _______
    ),
	[3] = LAYOUT(
            _______,    _______,    _______,    _______,    _______,    _______,                            _______,    _______,    _______,    _______,    _______,    _______,
            _______,    _______,    _______,    _______,    _______,    _______,                            _______,    KC_WH_D,    KC_WH_U,    KC_MS_BTN4, KC_MS_BTN5, _______,
            _______,    _______,    _______,    LSFT(KC_TAB),KC_TAB,    _______,                            KC_MS_LEFT, KC_MS_DOWN, KC_MS_UP,   KC_MS_RIGHT,_______,    _______,
            _______,    _______,    KC_MS_BTN2, KC_MS_BTN3, KC_MS_BTN1, _______, _______,        _______,   KC_HOME,    KC_MS_BTN1, KC_MS_BTN3, KC_MS_BTN2, _______,    _______,
                                    _______,    _______,    MO(2),      KC_LALT, _______,        _______,   _______,    MO(2),      _______,    _______
    )
};

#if defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {

};
#endif // defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)



