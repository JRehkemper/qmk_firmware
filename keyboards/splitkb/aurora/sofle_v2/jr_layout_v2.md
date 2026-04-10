# JR Layout V2
## Keymap
```
Layer 0: Lower
|-----|-----|-----|-----|-----|-----|                 |-----|-----|-----|-----|-----|-----|
|     |     |     |     |     |     |                 |     |  /  |  *  |  -  |     |     |
|-----|-----|-----|-----|-----|-----|                 |-----|-----|-----|-----|-----|-----|
|     |     |     |     |     |     |                 |     |  7  |  8  |  9  |  +  |     |
|-----|-----|-----|-----|-----|-----|                 |-----|-----|-----|-----|-----|-----|
|     |     |     |     |     |     |                 |     |  4  |  5  |  6  |     |     |
|-----|-----|-----|-----|-----|-----|                 |-----|-----|-----|-----|-----|-----|
|     |     |     |     |     |     |                 |     |  1  |  2  |  3  |enter|     |
|-----|-----|-----|-----|-----|-----|-----|     |-----|-----|-----|-----|-----|-----|-----|
            |     |     |     |     |     |     |     |     |  .  |  0  |  ,  | 
            |-----|-----|-----|-----|-----|     |-----|-----|-----|-----|-----|

Layer 1: Alpha
|-----|-----|-----|-----|-----|-----|                 |-----|-----|-----|-----|-----|-----|
|     |  1  |  2  |  3  |  4  |  5  |                 |  6  |  7  |  8  |  9  |  0  |     |
|-----|-----|-----|-----|-----|-----|                 |-----|-----|-----|-----|-----|-----|
|     |q (@)|  w  |e (€)|  r  |  t  |                 |  z  | u(ü)|  i  | o(ö)|  p  |     |
|-----|-----|-----|-----|-----|-----|                 |-----|-----|-----|-----|-----|-----|
|     | a(ä)| s(ß)|  d  |  f  |  g  |                 |  h  |  j  |  k  |  l  | tab |     |
|-----|-----|-----|-----|-----|-----|                 |-----|-----|-----|-----|-----|-----|
|     |  y  |  x  |  c  |  v  |  b  |                 |  n  |  m  |  ,  |  .  |  -  |     |
|-----|-----|-----|-----|-----|-----|-----|     |-----|-----|-----|-----|-----|-----|-----|
            |     | esc |lower|shift|delet|     |enter|space|upper|  /  |     | 
            |-----|-----|-----|-----|-----|     |-----|-----|-----|-----|-----|

Layer 2: Upper
|-----|-----|-----|-----|-----|-----|                 |-----|-----|-----|-----|-----|-----|
|     |     |     |     |     |     |                 |     |     |     |     |     |     |
|-----|-----|-----|-----|-----|-----|                 |-----|-----|-----|-----|-----|-----|
|     |{ (})|[ (])|  $  |  %  |  &  |                 | pos1| pgdn| pgup| end |     |     |
|-----|-----|-----|-----|-----|-----|                 |-----|-----|-----|-----|-----|-----|
|     |  #  |+ (~)|  !  |  "  |  $  |                 | left| down|  up |right|     |     |
|-----|-----|-----|-----|-----|-----|                 |-----|-----|-----|-----|-----|-----|
|     |< (>)|  ^  |  '  |  =  |     |                 |     |     |     |     |     |     |
|-----|-----|-----|-----|-----|-----|-----|     |-----|-----|-----|-----|-----|-----|-----|
            |     |     |     |     |     |     |     |     |     |     |     | 
            |-----|-----|-----|-----|-----|     |-----|-----|-----|-----|-----|
```
### Combos
```
s + l = /
shift + s + l = \
d + K = tab
f + j = |

x + c = Ctrl + C (Copy)
c + v = Ctrl + V (Paste)
x + v = Ctrl + X (Cut)
```
### Magic Key
```
exc + m = switch between Mac and Pc
```


### Gemini Keymap
```keymap.c
#include QMK_KEYBOARD_H

// Layer Definitions
enum layers {
    _ALPHA = 0,
    _LOWER,
    _UPPER
};

// Custom Keycodes for Smart OS Symbols
enum custom_keycodes {
    OS_TOGG = SAFE_RANGE, // Esc + M toggle
    SM_AT,   // @ (AltGr+Q or Alt+L)
    SM_EURO, // € (AltGr+E or Alt+E)
    SM_TILD, // ~ (AltGr++ or Alt+N)
    SM_PIPE, // | (AltGr+< or Alt+7)
    SM_BSLS, // \ (AltGr+ß or S+Alt+7)
    SM_LCBR, // {
    SM_RCBR, // }
    SM_LBRC, // [
    SM_RBRC, // ]
};

// --- COMBOS ---
// Define the keys that trigger the combo
const uint16_t PROGMEM slash_combo[] = {KC_S, KC_L, COMBO_END};
const uint16_t PROGMEM bsls_combo[]  = {KC_LSFT, KC_S, KC_L, COMBO_END};
const uint16_t PROGMEM pipe_combo[]  = {KC_F, KC_J, COMBO_END};
const uint16_t PROGMEM tab_combo[]   = {KC_D, KC_K, COMBO_END};
const uint16_t PROGMEM copy_combo[]  = {KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM past_combo[]  = {KC_C, KC_V, COMBO_END};
const uint16_t PROGMEM cut_combo[]   = {KC_X, KC_V, COMBO_END};
const uint16_t PROGMEM os_togg_combo[]= {KC_ESC, KC_M, COMBO_END};

combo_t key_combos[] = {
    COMBO(slash_combo, KC_SLSH),
    COMBO(bsls_combo, SM_BSLS),
    COMBO(pipe_combo, SM_PIPE),
    COMBO(tab_combo, KC_TAB),
    COMBO(copy_combo, LCTL(KC_C)),
    COMBO(past_combo, LCTL(KC_V)),
    COMBO(cut_combo, LCTL(KC_X)),
    COMBO(os_togg_combo, OS_TOGG),
};

// --- KEYMAP ---
// LT(_LAYER, KC) means: Hold for Layer, Tap for Key.
// Since you want Shift and Space dedicated, I've left them as pure keys.

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_ALPHA] = LAYOUT(
  KC_NO,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_NO,
  KC_NO,   SM_AT,   KC_W,    SM_EURO, KC_R,    KC_T,                      KC_Z,    KC_U,    KC_I,    KC_O,    KC_P,    KC_NO,
  KC_NO,   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                      KC_H,    KC_J,    KC_K,    KC_L,    KC_TAB,  KC_NO,
  KC_NO,   KC_Y,    KC_X,    KC_C,    KC_V,    KC_B,                      KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_MINS, KC_NO,
           KC_NO,   KC_ESC,  LT(_LOWER, KC_TAB), KC_LSFT, KC_DEL,       KC_ENT,  KC_SPC,  LT(_UPPER, KC_ENT), KC_SLSH, KC_NO
),

[_LOWER] = LAYOUT(
  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                     KC_NO,   KC_PSLS, KC_PAST, KC_PMNS, KC_NO,   KC_NO,
  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                     KC_NO,   KC_7,    KC_8,    KC_9,    KC_PPLS, KC_NO,
  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                     KC_NO,   KC_4,    KC_5,    KC_6,    KC_NO,   KC_NO,
  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                     KC_NO,   KC_1,    KC_2,    KC_3,    KC_PENT, KC_NO,
           KC_NO,   KC_TRNS, KC_TRNS, KC_LSFT, KC_TRNS,               KC_TRNS, KC_TRNS, KC_PDOT, KC_0,    KC_PCOMM, KC_NO
),

[_UPPER] = LAYOUT(
  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                     KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
  KC_NO,   SM_LCBR, SM_LBRC, KC_DLR,  KC_PERC, KC_AMPR,                   KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_NO,   KC_NO,
  KC_NO,   KC_HASH, KC_PPLS, KC_EXLM, KC_DQUO, KC_DLR,                    KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_NO,   KC_NO,
  KC_NO,   KC_LABK, KC_CIRC, KC_NO,   KC_ACUT, KC_NO,                     KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
           KC_NO,   KC_TRNS, KC_TRNS, KC_LSFT, KC_TRNS,               KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO
)
};

// --- LOGIC ENGINE ---
bool is_mac_mode = false; 

void tap_smart_key(uint16_t pc_mod, uint16_t pc_key, uint16_t mac_mod, uint16_t mac_key) {
    if (is_mac_mode) {
        register_code(mac_mod); tap_code(mac_key); unregister_code(mac_mod);
    } else {
        register_code(pc_mod); tap_code(pc_key); unregister_code(pc_mod);
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch (keycode) {
            case OS_TOGG:
                is_mac_mode = !is_mac_mode;
                keymap_config.swap_lalt_lgui = is_mac_mode;
                eeconfig_update_keymap(keymap_config.raw);
                return false;
            case SM_AT:   tap_smart_key(KC_RALT, KC_Q, KC_LALT, KC_L); return false;
            case SM_EURO: tap_smart_key(KC_RALT, KC_E, KC_LALT, KC_E); return false;
            case SM_TILD: tap_smart_key(KC_RALT, KC_RBRC, KC_LALT, KC_N); return false;
            case SM_PIPE: tap_smart_key(KC_RALT, KC_NONUS_BSLASH, KC_LALT, KC_7); return false;
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
}
```
