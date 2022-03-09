

// Custom shortened key names
#define 	RCTL_ENT		RCTL_T(KC_ENT)				// tap = enter				hold = right control
#define 	RCTL_PENT		RCTL_T(KC_PENT)				// tap = numpad enter		hold = right control
#define 	RSFT_PSLS		RSFT_T(KC_PSLS)				// tap = numpad /			hold = right shift
#define 	PDOT_DEL		LT(_DEL,KC_PDOT)			// tap = . (KC_PDOT)		hold = momentary DEL layer
#define		LALT_TNKY		LM(_TENKEY,MOD_LALT)		// momentary TENKEY layer with left alt modifier
#define		LALT_TAB		LM(_TAB,MOD_LALT)			// momentary TAB layer with left alt modifier
#define		FKEY			MO(_FKEY)					// momentary FKEY
#define		TOG_STEN		TG(_STENO)					// toggle STENO layer


// Custom shortened key names - key override behaviour defined in process_record_user
#define		EQL_NUM			LT(0,KC_0)					// tap = equals (KC_EQL - PEQL does not work)		shift + tap = numlock				shift + hold = toggle TENKEY layer
#define		L_NUM_SPC		LT(0,KC_1)					// tap = space				hold = temporary NAVNUM layer
#define		R_NUM_SPC		LT(0,KC_2)					// tap = space				hold = temporary NAVNUM & R_NUM layers
#define		R_NUM_0			LT(0,KC_3)					// tap = 0					hold = temporary R_NUM layer
#define 	DOT_DEL			LT(0,KC_4)					// tap = . (KC_DOT)			shift + tap = . (KC_DOT)		hold = temporary DEL layer
#define 	LCTL_CAPS		LT(0,KC_5)					// right shift + tap = capslock			all else = left control
#define		LGUI_FKEY		LT(0,KC_6)					// tap = windows key		hold = temporary FKEY layer
#define		RGUI_FKEY		LT(0,KC_7)					// tap = application key	hold = temporary FKEY layer


// Custom keycodes - behaviour defined in process_record_user
enum custom_keycodes {
	QWERTY = SAFE_RANGE,								// tap = set default layer to _QWERTY
	TARMAK1,											// tap = set default layer to _TARMAK1
	TARMAK2,											// tap = set default layer to _TARMAK2
	TARMAK3,											// tap = set default layer to _TARMAK3
	TARMAK4,											// tap = set default layer to _TARMAK4
	COLEMAK,											// tap = set default layer to _COLEMAK
    QUES_EXLM,											// tap = ? (shifted KC_SLSH)	shift + tap = ! (shifted KC_1)
	L_PRN_ABK,											// tap = ( (shifted KC_9)		shift + tap = < (shifted KC_COMM)
	R_PRN_ABK,											// tap = ) (shifted KC_0)		shift + tap = > (shifted KC_DOT)
	COMM_SCLN,											// tap = , (KC_COMM)			shift + tap = ; (unshifted KC_SCLN)
	DOT_COLN,											// tap = . (KC_DOT)				shift + tap = : (shifted KC_SCLN)
	SLSH_UNDS,											// tap = / (KC_SLSH)			shift + tap = _ (shifted KC_MINS)
	COMM_COMM,											// tap = , (KC_COMM)			shift + tap = , (unshifted KC_COMM)
	TOG_NKRO,											// toggle NKRO
};



typedef enum {
    TD_NONE,
    TD_UNKNOWN,
    TD_SINGLE_TAP,
    TD_SINGLE_HOLD,
    TD_DOUBLE_TAP,
    TD_DOUBLE_HOLD,
    TD_DOUBLE_SINGLE_TAP, // Send two single taps
    TD_TRIPLE_TAP,
    TD_TRIPLE_HOLD
} td_state_t;

typedef struct {
    bool is_press_action;
    td_state_t state;
} td_tap_t;

// Tap dance enums
enum {
    X_CTL,
    SOME_OTHER_DANCE
};

td_state_t cur_dance(qk_tap_dance_state_t *state);

// For the x tap dance. Put it here so it can be used in any keymap
void x_finished(qk_tap_dance_state_t *state, void *user_data);
void x_reset(qk_tap_dance_state_t *state, void *user_data);