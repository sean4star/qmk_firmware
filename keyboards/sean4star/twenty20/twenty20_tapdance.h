/*
 *    Tap Dance!
 */


// Tap Types
enum {
  ONE_TAP = 1,
  TWO_TAP = 2,
  THREE_TAP = 3,
  FOUR_TAP = 4,
  FIVE_TAP = 5,
  SIX_TAP = 6,
  SINGLE_HOLD = 7,
};

// Custom tap dance keycodes
enum tapdance_keycodes {
    // TD_APP_DOT = 0,
    TD_APP_COL = 0,
};

// Shortened Keycode Names

//#define APP_DOT   TD(TD_APP_DOT)
//#define APP_COL   TD(TD_APP_COL)


typedef struct {
  bool is_press_action;
  int state;
} xtap;

/*
 *    Tap & Hold Type Definitions
 */

/*
// To activate SINGLE_HOLD, you will need to hold for 200ms first. 
// This tap dance favors keys that are used frequently in typing like 'f'
int cur_dance (qk_tap_dance_state_t *state) {
  if (state->count == 1) {
    //If count = 1, and it has been interrupted - it doesn't matter if it is pressed or not: Send SINGLE_TAP
    if (state->interrupted) {
      //     if (!state->pressed) return SINGLE_TAP; 
      //need "permissive hold" here.
      //     else return SINGLE_HOLD; 
      //If the interrupting key is released before the tap-dance key, then it is a single HOLD
      //However, if the tap-dance key is released first, then it is a single TAP
      //But how to get access to the state of the interrupting key????
      return SINGLE_TAP;
    }
    else {
      if (!state->pressed) return SINGLE_TAP;
      else return SINGLE_HOLD;
    }
  }
  //If count = 2, and it has been interrupted - assume that user is trying to type the letter associated
  //with single tap.
  else if (state->count >= 2) {
    if (state->pressed) return DOUBLE_HOLD;
    else return DOUBLE_TAP; 
  }
  else return 8; //magic number. At some point this method will expand to work for more presses
}
*/

//This works well if you want this key to work as a "fast modifier". It favors being held over being tapped.
int hold_cur_dance (qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted) {
            if (!state->pressed) return ONE_TAP; 
            else return SINGLE_HOLD; 
        } else {
            if (!state->pressed) return ONE_TAP;
            else return SINGLE_HOLD;
        }
    } else if (state->count == 2) {
        return TWO_TAP;
    } else if (state->count == 3) {
        return THREE_TAP;
    } else if (state->count == 4) {
        return FOUR_TAP;
    } else if (state->count == 5) {
        return FIVE_TAP;
    } else if (state->count >= 6) {
        return SIX_TAP;
    } else return 8; //magic number. At some point this method will expand to work for more presses
}


/*
 *     App & Period
 */
/*static xtap app_period_state = { 
  .is_press_action = true,
  .state = 0
};
void app_period_finished (qk_tap_dance_state_t *state, void *user_data) {
    app_period_state.state = hold_cur_dance(state);
    switch (app_period_state.state) {
        case ONE_TAP:   register_code(KC_DOT); break;
        case TWO_TAP:   register_code(KC_DOT); unregister_code(KC_DOT);
                        register_code(KC_DOT); break;
        case THREE_TAP: register_code(KC_DOT); unregister_code(KC_DOT);
                        register_code(KC_DOT); unregister_code(KC_DOT);
                        register_code(KC_DOT); break;
        case FOUR_TAP:  register_code(KC_DOT); unregister_code(KC_DOT);
                        register_code(KC_DOT); unregister_code(KC_DOT);
                        register_code(KC_DOT); unregister_code(KC_DOT);
                        register_code(KC_DOT); break;
        case FIVE_TAP:  register_code(KC_DOT); unregister_code(KC_DOT);
                        register_code(KC_DOT); unregister_code(KC_DOT);
                        register_code(KC_DOT); unregister_code(KC_DOT);
                        register_code(KC_DOT); unregister_code(KC_DOT);
                        register_code(KC_DOT); break;
        case SIX_TAP:   register_code(KC_DOT); unregister_code(KC_DOT);
                        register_code(KC_DOT); unregister_code(KC_DOT);
                        register_code(KC_DOT); unregister_code(KC_DOT);
                        register_code(KC_DOT); unregister_code(KC_DOT);
                        register_code(KC_DOT); unregister_code(KC_DOT);
                        register_code(KC_DOT); break;
        case SINGLE_HOLD: register_code(KC_APP); unregister_code(KC_APP); break;
    }
}
void app_period_reset (qk_tap_dance_state_t *state, void *user_data) {
    switch (app_period_state.state) {
        case ONE_TAP:   unregister_code(KC_DOT); break;
        case TWO_TAP:   unregister_code(KC_DOT); break;
        case THREE_TAP: unregister_code(KC_DOT); break;
        case FOUR_TAP:  unregister_code(KC_DOT); break;
        case FIVE_TAP:  unregister_code(KC_DOT); break;
        case SIX_TAP:   unregister_code(KC_DOT); break;
        case SINGLE_HOLD: break;
  }
  app_period_state.state = 0;
}
*/
/*
 *     App & Colon
 */
/*static xtap app_colon_state = { 
  .is_press_action = true,
  .state = 0
};
void app_colon_finished (qk_tap_dance_state_t *state, void *user_data) {
    app_colon_state.state = hold_cur_dance(state);
    switch (app_colon_state.state) {
        case ONE_TAP:   register_code(KC_SCLN); break;
        case TWO_TAP:   register_code(KC_SCLN); unregister_code(KC_SCLN);
                        register_code(KC_SCLN); break;
        case THREE_TAP: register_code(KC_SCLN); unregister_code(KC_SCLN);
                        register_code(KC_SCLN); unregister_code(KC_SCLN);
                        register_code(KC_SCLN); break;
        case FOUR_TAP:  register_code(KC_SCLN); unregister_code(KC_SCLN);
                        register_code(KC_SCLN); unregister_code(KC_SCLN);
                        register_code(KC_SCLN); unregister_code(KC_SCLN);
                        register_code(KC_SCLN); break;
        case FIVE_TAP:  register_code(KC_SCLN); unregister_code(KC_SCLN);
                        register_code(KC_SCLN); unregister_code(KC_SCLN);
                        register_code(KC_SCLN); unregister_code(KC_SCLN);
                        register_code(KC_SCLN); unregister_code(KC_SCLN);
                        register_code(KC_SCLN); break;
        case SIX_TAP:   register_code(KC_SCLN); unregister_code(KC_SCLN);
                        register_code(KC_SCLN); unregister_code(KC_SCLN);
                        register_code(KC_SCLN); unregister_code(KC_SCLN);
                        register_code(KC_SCLN); unregister_code(KC_SCLN);
                        register_code(KC_SCLN); unregister_code(KC_SCLN);
                        register_code(KC_SCLN); break;
        case SINGLE_HOLD: register_code(KC_APP); unregister_code(KC_APP); break;
    }
}
void app_colon_reset (qk_tap_dance_state_t *state, void *user_data) {
    switch (app_colon_state.state) {
        case ONE_TAP:   unregister_code(KC_SCLN); break;
        case TWO_TAP:   unregister_code(KC_SCLN); break;
        case THREE_TAP: unregister_code(KC_SCLN); break;
        case FOUR_TAP:  unregister_code(KC_SCLN); break;
        case FIVE_TAP:  unregister_code(KC_SCLN); break;
        case SIX_TAP:   unregister_code(KC_SCLN); break;
        case SINGLE_HOLD: break;
  }
  app_colon_state.state = 0;
}
*/

// Tap dance actions
// individual items can be commented out <but>
// DO NOT comment out the section - won't build without it
qk_tap_dance_action_t tap_dance_actions[] = {
    // [TD_LSFT_Z] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, left_shift_z_finished, left_shift_z_reset),
    // [TD_LSFT_ENT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, left_shift_enter_finished, left_shift_enter_reset),
    // [TD_RSFT_ENT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, right_shift_enter_finished, right_shift_enter_reset),
    // [TD_RSFT_PLS] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, right_shift_plus_finished, right_shift_plus_reset),
    // [TD_APP_DOT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, app_period_finished, app_period_reset),
    // [TD_APP_COL] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, app_colon_finished, app_colon_reset),
};