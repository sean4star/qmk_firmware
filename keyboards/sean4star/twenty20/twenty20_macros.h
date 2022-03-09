/*
 *    Macros!
 */


/*
 *    New Method
 */

// Custom macro keycodes
enum macro_keycodes {
    LALT_TAB = SAFE_RANGE,
//    RALT_SCL_TEST,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {

        case LALT_TAB:
            if (record->event.pressed) {
                SEND_STRING(SS_DOWN(X_LALT));
                layer_on(TAB);
            } else {
                layer_off(TAB);
                SEND_STRING(SS_UP(X_LALT));
            }
        return false;
        break;
    }
    return true;
};



/*
 *    Old School Macros
 */


// Macro ID numbers
#define M_LSFT_Z   1
#define M_RSFT_ENT 2
#define M_LSFT_ENT 3 
#define M_RSFT_PLS 4
#define M_APP_DOT  5
#define M_RALT_COM 6
#define M_Q_EX_MRK 7
#define M_APP_PDOT 8
#define M_NLCK_EQL 9
#define M_LGUI     10
#define M_LPRN_LAB 11
#define M_RPRN_RAB 12
#define M_LGUI_BTK 13
#define M_TRI_ZERO 14
#define M_ZERO_DEL 15
#define M_LALT_CAP 16
#define M_LSFT_MUT 17
#define M_LGUI_PLY 18
#define M_APP_SLCK 19

// Shortened Keycode Names
#define LSFT_Z    MACROTAP(M_LSFT_Z)
#define RSFT_ENT  MACROTAP(M_RSFT_ENT)
#define LSFT_ENT  MACROTAP(M_LSFT_ENT)
#define RSFT_PLS  MACROTAP(M_RSFT_PLS)
#define APP_DOT   MACROTAP(M_APP_DOT)
#define RALT_COM  MACROTAP(M_RALT_COM)
#define Q_EX_MRK  MACROTAP(M_Q_EX_MRK)
#define APP_PDOT  MACROTAP(M_APP_PDOT)
#define NLCK_EQL  MACROTAP(M_NLCK_EQL)
#define LGUI_HLD  MACROTAP(M_LGUI)
#define LPRN_LAB  MACROTAP(M_LPRN_LAB)
#define RPRN_RAB  MACROTAP(M_RPRN_RAB)
#define LGUI_BTK  MACROTAP(M_LGUI_BTK)
#define TRI_ZERO  MACROTAP(M_TRI_ZERO)
#define ZERO_DEL  MACROTAP(M_ZERO_DEL)
#define LALT_CAP  MACROTAP(M_LALT_CAP)
#define LSFT_MUT  MACROTAP(M_LSFT_MUT)
#define LGUI_PLY  MACROTAP(M_LGUI_PLY)
#define APP_SLCK  MACROTAP(M_APP_SLCK)


static bool left_shift_held = false;
static bool right_shift_held = false;


// Customizable key
#define CUSTOM_TAP_HOLD_KEY(record, hold_press, hold_release, tap_press, tap_release) \
( record->event.pressed ? \
     ( (record->tap.count <= 0 || record->tap.interrupted) ? (hold_press) : (tap_press) ) : \
     ( (record->tap.count > 0 && !record->tap.interrupted) ? (tap_release) : (hold_release) ) )


// Don't use MACRO(DOWN(mod)) - the mod turns off every layer change - i.e. can't hold shift/alt/ctl between alpha and number layers  //
#define TAP_KEY_HOLD_LSFT(record, key) CUSTOM_TAP_HOLD_KEY( record, {left_shift_held = true; register_mods(MOD_BIT(KC_LSFT)); MACRO_NONE; }, \
																	{left_shift_held = false; unregister_mods(MOD_BIT(KC_LSFT)); MACRO_NONE; }, \
																	MACRO(DOWN(key), END), MACRO(UP(key), END) )

#define TAP_KEY_HOLD_RSFT(record, key) CUSTOM_TAP_HOLD_KEY( record, {right_shift_held = true; register_mods(MOD_BIT(KC_RSFT)); MACRO_NONE; }, \
																	{right_shift_held = false; unregister_mods(MOD_BIT(KC_RSFT)); MACRO_NONE; }, \
																	MACRO(DOWN(key), END), MACRO(UP(key), END) )

#define TAP_KEY_HOLD_MOD(record, key, mod) CUSTOM_TAP_HOLD_KEY( record, {register_mods(MOD_BIT(mod)); MACRO_NONE; }, {unregister_mods(MOD_BIT(mod)); MACRO_NONE; }, \
																		MACRO(DOWN(key), END), MACRO(UP(key), END) )

#define TAP_KEY_HOLD_LAYER(record, key, layer) CUSTOM_TAP_HOLD_KEY( record, {layer_on(layer); MACRO_NONE; }, {layer_off(layer); MACRO_NONE; }, \
																			MACRO(DOWN(key), END), MACRO(UP(key), END) )

#define TAP_KEY_HOLD_MOD_LAYER(record, key, mod, layer) CUSTOM_TAP_HOLD_KEY( record, {layer_on(layer); register_mods(MOD_BIT(mod)); MACRO_NONE; }, \
                                                                                     {layer_off(layer); unregister_mods(MOD_BIT(mod)); MACRO_NONE; }, \
																			         MACRO(DOWN(key), END), MACRO(UP(key), END) )

#define TAP_KEY_HOLD_PR_MOD(record, key, mod) CUSTOM_TAP_HOLD_KEY( record, MACRO(TYPE(mod), END), MACRO_NONE, \
																				 MACRO(DOWN(key), END), MACRO(UP(key), END) )

#define TAP_TOGGLE_LAYER_HOLD_MOD(record, mod, layer) CUSTOM_TAP_HOLD_KEY( record, {register_mods(MOD_BIT(mod)); MACRO_NONE; }, {unregister_mods(MOD_BIT(mod)); MACRO_NONE; }, \
																		 MACRO_NONE, {layer_invert(layer); MACRO_NONE; } )


#define CUSTOM_TAP_HOLD_KEY_NTI(record, hold_press, hold_release, tap_press, tap_release) \
( record->event.pressed ? \
     ( (record->tap.count <= 0) ? (hold_press) : (tap_press) ) : \
     ( (record->tap.count > 0) ? (tap_release) : (hold_release) ) )

#define TAP_KEY_HOLD_PR_MOD_NTI(record, key, mod) CUSTOM_TAP_HOLD_KEY_NTI( record, MACRO(TYPE(mod), END), MACRO_NONE, \
																				 MACRO(DOWN(key), END), MACRO(UP(key), END) )


// Super customizable key - detects both shift and tap states
#define SUPER_CUSTOM_KEY(record, \
		press_bothshifted_hold, release_bothshifted_hold, \
		press_bothshifted_tap, release_bothshifted_tap, \
		press_leftshifted_hold, release_leftshifted_hold, \
		press_leftshifted_tap, release_leftshifted_tap, \
		press_rightshifted_hold, release_rightshifted_hold, \
		press_rightshifted_tap, release_rightshifted_tap, \
		press_unshifted_hold, release_unshifted_hold, \
		press_unshifted_tap, release_unshifted_tap) \
( record->event.pressed ? \
	( (left_shift_held && right_shift_held) ? \
		( (record->tap.count <= 0 || record->tap.interrupted) ? (press_bothshifted_hold) : (press_bothshifted_tap) ) : \
	( (left_shift_held && !right_shift_held) ? \
		( (record->tap.count <= 0 || record->tap.interrupted) ? (press_leftshifted_hold) : (press_leftshifted_tap) ) : \
	( (!left_shift_held && right_shift_held) ? \
		( (record->tap.count <= 0 || record->tap.interrupted) ? (press_rightshifted_hold) : (press_rightshifted_tap) ) : \
	( (record->tap.count > 0 && !record->tap.interrupted) ? (press_unshifted_tap) : (press_unshifted_hold) ) ) ) ) : \
( (!left_shift_held && !right_shift_held) ? \
	( (record->tap.count > 0 && !record->tap.interrupted) ? (release_unshifted_tap) : (release_unshifted_hold) ) : \
( (!left_shift_held && right_shift_held) ? \
	( (record->tap.count > 0 && !record->tap.interrupted) ? (release_rightshifted_tap) : (release_rightshifted_hold) ) : \
( (left_shift_held && !right_shift_held) ? \
	( (record->tap.count > 0 && !record->tap.interrupted) ? (release_leftshifted_tap) : (release_leftshifted_hold) ) : \
( (record->tap.count > 0 && !record->tap.interrupted) ? (release_bothshifted_tap) : (release_bothshifted_hold) ) ) ) ) )


#define UNSHIFTED_TAP_KEY_HOLD_MOD(record, key, unshifted_key, mod) \
	SUPER_CUSTOM_KEY( record, \
		{register_mods(MOD_BIT(mod)); MACRO_NONE; }, {unregister_mods(MOD_BIT(mod)); MACRO_NONE; }, \
		{unregister_mods(MOD_BIT(KC_LSFT)); unregister_mods(MOD_BIT(KC_RSFT)); MACRO(DOWN(unshifted_key), END); }, {register_mods(MOD_BIT(KC_LSFT)); register_mods(MOD_BIT(KC_RSFT)); MACRO(UP(unshifted_key), END); }, \
		{register_mods(MOD_BIT(mod)); MACRO_NONE; }, {unregister_mods(MOD_BIT(mod)); MACRO_NONE; }, \
		{unregister_mods(MOD_BIT(KC_LSFT)); MACRO(DOWN(unshifted_key), END); }, {register_mods(MOD_BIT(KC_LSFT)); MACRO(UP(unshifted_key), END); }, \
		{register_mods(MOD_BIT(mod)); MACRO_NONE; }, {unregister_mods(MOD_BIT(mod)); MACRO_NONE; }, \
		{unregister_mods(MOD_BIT(KC_RSFT)); MACRO(DOWN(unshifted_key), END); }, {register_mods(MOD_BIT(KC_RSFT)); MACRO(UP(unshifted_key), END); }, \
		{register_mods(MOD_BIT(mod)); MACRO_NONE; }, {unregister_mods(MOD_BIT(mod)); MACRO_NONE; }, \
		MACRO(DOWN(key), END), MACRO(UP(key), END) )

#define FORCE_SHIFTED_TAP_KEY(record, key, shifted_key) \
	SUPER_CUSTOM_KEY( record, \
		MACRO(DOWN(shifted_key), END), MACRO(UP(shifted_key), END), \
		MACRO(DOWN(shifted_key), END), MACRO(UP(shifted_key), END), \
		MACRO(DOWN(shifted_key), END), MACRO(UP(shifted_key), END), \
		MACRO(DOWN(shifted_key), END), MACRO(UP(shifted_key), END), \
		MACRO(DOWN(shifted_key), END), MACRO(UP(shifted_key), END), \
		MACRO(DOWN(shifted_key), END), MACRO(UP(shifted_key), END), \
		{register_mods(MOD_BIT(KC_LSFT)); MACRO(DOWN(key), END); }, {unregister_mods(MOD_BIT(KC_LSFT)); MACRO(UP(key), END); }, \
		{register_mods(MOD_BIT(KC_LSFT)); MACRO(DOWN(key), END); }, {unregister_mods(MOD_BIT(KC_LSFT)); MACRO(UP(key), END); } )

#define FORCE_SHIFTED_TAP_KEY_HOLD_PR_MOD(record, key, shifted_key, mod) \
	SUPER_CUSTOM_KEY( record, \
		MACRO(TYPE(mod), END), MACRO_NONE, \
		MACRO(DOWN(shifted_key), END), MACRO(UP(shifted_key), END), \
		MACRO(TYPE(mod), END), MACRO_NONE, \
		MACRO(DOWN(shifted_key), END), MACRO(UP(shifted_key), END), \
		MACRO(TYPE(mod), END), MACRO_NONE, \
		MACRO(DOWN(shifted_key), END), MACRO(UP(shifted_key), END), \
		MACRO(TYPE(mod), END), MACRO_NONE, \
		MACRO(DOWN(key), END), MACRO(UP(key), END) )

#define THOUSANDS_KEY_HOLD_LAYER(record, key, layer) \
	SUPER_CUSTOM_KEY( record, \
		{layer_on(layer); MACRO_NONE; }, {layer_off(layer); MACRO_NONE; }, \
		{unregister_mods(MOD_BIT(KC_LSFT)); unregister_mods(MOD_BIT(KC_RSFT)); MACRO(TYPE(key), TYPE(key), END); }, {register_mods(MOD_BIT(KC_LSFT)); register_mods(MOD_BIT(KC_RSFT)); MACRO_NONE; }, \
		{layer_on(layer); MACRO_NONE; }, {layer_off(layer); MACRO_NONE; }, \
		{unregister_mods(MOD_BIT(KC_LSFT)); MACRO(TYPE(key), TYPE(key), END); }, {register_mods(MOD_BIT(KC_LSFT)); MACRO_NONE; }, \
		{layer_on(layer); MACRO_NONE; }, {layer_off(layer); MACRO_NONE; }, \
		{unregister_mods(MOD_BIT(KC_RSFT)); MACRO(TYPE(key), TYPE(key), END); }, {register_mods(MOD_BIT(KC_RSFT)); MACRO_NONE; }, \
		{layer_on(layer); MACRO_NONE; }, {layer_off(layer); MACRO_NONE; }, \
		MACRO(TYPE(key), TYPE(key), TYPE(key), END), MACRO_NONE  )


#define SUPER_CUSTOM_KEY_NTI(record, \
		press_bothshifted_hold, release_bothshifted_hold, \
		press_bothshifted_tap, release_bothshifted_tap, \
		press_leftshifted_hold, release_leftshifted_hold, \
		press_leftshifted_tap, release_leftshifted_tap, \
		press_rightshifted_hold, release_rightshifted_hold, \
		press_rightshifted_tap, release_rightshifted_tap, \
		press_unshifted_hold, release_unshifted_hold, \
		press_unshifted_tap, release_unshifted_tap) \
( record->event.pressed ? \
	( (left_shift_held && right_shift_held) ? \
		( (record->tap.count <= 0) ? (press_bothshifted_hold) : (press_bothshifted_tap) ) : \
	( (left_shift_held && !right_shift_held) ? \
		( (record->tap.count <= 0) ? (press_leftshifted_hold) : (press_leftshifted_tap) ) : \
	( (!left_shift_held && right_shift_held) ? \
		( (record->tap.count <= 0) ? (press_rightshifted_hold) : (press_rightshifted_tap) ) : \
	( (record->tap.count > 0) ? (press_unshifted_tap) : (press_unshifted_hold) ) ) ) ) : \
( (!left_shift_held && !right_shift_held) ? \
	( (record->tap.count > 0) ? (release_unshifted_tap) : (release_unshifted_hold) ) : \
( (!left_shift_held && right_shift_held) ? \
	( (record->tap.count > 0) ? (release_rightshifted_tap) : (release_rightshifted_hold) ) : \
( (left_shift_held && !right_shift_held) ? \
	( (record->tap.count > 0) ? (release_leftshifted_tap) : (release_leftshifted_hold) ) : \
( (record->tap.count > 0) ? (release_bothshifted_tap) : (release_bothshifted_hold) ) ) ) ) )

#define UNSHIFTED_TAP_KEY_HOLD_MOD_NTI(record, key, unshifted_key, mod) \
	SUPER_CUSTOM_KEY_NTI( record, \
		{register_mods(MOD_BIT(mod)); MACRO_NONE; }, {unregister_mods(MOD_BIT(mod)); MACRO_NONE; }, \
		{unregister_mods(MOD_BIT(KC_LSFT)); unregister_mods(MOD_BIT(KC_RSFT)); MACRO(DOWN(unshifted_key), END); }, {register_mods(MOD_BIT(KC_LSFT)); register_mods(MOD_BIT(KC_RSFT)); MACRO(UP(unshifted_key), END); }, \
		{register_mods(MOD_BIT(mod)); MACRO_NONE; }, {unregister_mods(MOD_BIT(mod)); MACRO_NONE; }, \
		{unregister_mods(MOD_BIT(KC_LSFT)); MACRO(DOWN(unshifted_key), END); }, {register_mods(MOD_BIT(KC_LSFT)); MACRO(UP(unshifted_key), END); }, \
		{register_mods(MOD_BIT(mod)); MACRO_NONE; }, {unregister_mods(MOD_BIT(mod)); MACRO_NONE; }, \
		{unregister_mods(MOD_BIT(KC_RSFT)); MACRO(DOWN(unshifted_key), END); }, {register_mods(MOD_BIT(KC_RSFT)); MACRO(UP(unshifted_key), END); }, \
		{register_mods(MOD_BIT(mod)); MACRO_NONE; }, {unregister_mods(MOD_BIT(mod)); MACRO_NONE; }, \
		MACRO(DOWN(key), END), MACRO(UP(key), END) )

#define FORCE_SHIFTED_TAP_KEY_HOLD_PR_MOD_NTI(record, key, shifted_key, mod) \
	SUPER_CUSTOM_KEY_NTI( record, \
		MACRO(TYPE(mod), END), MACRO_NONE, \
		MACRO(DOWN(shifted_key), END), MACRO(UP(shifted_key), END), \
		MACRO(TYPE(mod), END), MACRO_NONE, \
		MACRO(DOWN(shifted_key), END), MACRO(UP(shifted_key), END), \
		MACRO(TYPE(mod), END), MACRO_NONE, \
		MACRO(DOWN(shifted_key), END), MACRO(UP(shifted_key), END), \
		MACRO(TYPE(mod), END), MACRO_NONE, \
		MACRO(DOWN(key), END), MACRO(UP(key), END) )


const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
    switch (id) {
        case M_LSFT_Z: {
            return TAP_KEY_HOLD_LSFT(record, KC_Z);
        }
        break;
        case M_RSFT_ENT: {
            return TAP_KEY_HOLD_RSFT(record, KC_ENT);
        }
        break;
        case M_LSFT_ENT: {
            return TAP_KEY_HOLD_LSFT(record, KC_ENT);
        }
        break;
        case M_RSFT_PLS: {
            return TAP_KEY_HOLD_RSFT(record, KC_PPLS);
        }
        break;
        case M_LSFT_MUT: {
            return TAP_KEY_HOLD_LSFT(record, KC_MUTE);
        }
        break;
        case M_APP_DOT: {
            return FORCE_SHIFTED_TAP_KEY_HOLD_PR_MOD_NTI(record, KC_DOT, KC_SCLN, KC_APP);
        }
        break;
        case M_RALT_COM: {
            return UNSHIFTED_TAP_KEY_HOLD_MOD_NTI(record, KC_COMM, KC_SCLN, KC_RALT);
        }
        break;
        case M_Q_EX_MRK: {
            return FORCE_SHIFTED_TAP_KEY(record, KC_SLSH, KC_1);
        }
        break;
        case M_APP_PDOT: {
            return TAP_KEY_HOLD_PR_MOD_NTI(record, KC_PDOT, KC_APP);
        }
        break;
        case M_APP_SLCK: {
            return TAP_KEY_HOLD_PR_MOD(record, KC_SLCK, KC_APP);
        }
        break;
        case M_NLCK_EQL: {
            return TAP_KEY_HOLD_PR_MOD_NTI(record, KC_EQL, KC_NLCK);
        }
        break;
        case M_LGUI: {
            return TAP_KEY_HOLD_MOD(record, KC_LGUI, KC_LGUI);
        }
        break;
        case M_LGUI_PLY: {
            return TAP_KEY_HOLD_MOD(record, KC_MPLY, KC_LGUI);
        }
        break;
        case M_LPRN_LAB: {
            return FORCE_SHIFTED_TAP_KEY(record, KC_9, KC_COMM);
        }
        break;
        case M_RPRN_RAB: {
            return FORCE_SHIFTED_TAP_KEY(record, KC_0, KC_DOT);
        }
        break;
        case M_LGUI_BTK: {
            return TAP_TOGGLE_LAYER_HOLD_MOD(record, KC_LGUI, BTK);
        }
        break;
        case M_LALT_CAP: {
            return TAP_KEY_HOLD_MOD_LAYER(record, KC_CAPS, KC_LALT, NPD);
        }
        break;
        case M_TRI_ZERO: {
            return THOUSANDS_KEY_HOLD_LAYER(record, KC_0, DEL);
        }
        break;
        case M_ZERO_DEL: {
            return TAP_KEY_HOLD_LAYER(record, KC_0, DEL);
        }
        break;
     }
    return MACRO_NONE;
};