

// State variables
uint8_t mod_state;
static bool held_L_NUM = false;
static bool held_R_NUM = false;
static bool held_NUM_ON = false;
static bool held_L_FKEY = false;
static bool held_R_FKEY = false;


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
/*
#ifdef OLED_ENABLE
  if (record->event.pressed) {
    set_keylog(keycode, record);
  }
  return true;
#endif			// OLED_ENABLE
*/

mod_state = get_mods();


    switch (keycode) {
		
        case QUES_EXLM: {
		// tap = ? (shifted KC_SLSH)	shift + tap = ! (shifted KC_1)
			static bool shifted_Q_EXMRK = false;
			if (record->event.pressed) {
				if (mod_state & MOD_MASK_SHIFT) {
					shifted_Q_EXMRK = true;
					register_code(KC_1);
				} else {
					register_mods(MOD_BIT(KC_LSFT));
					register_code(KC_SLSH);
					unregister_code(KC_SLSH);
					unregister_mods(MOD_BIT(KC_LSFT));
				}
            } else {
				if (shifted_Q_EXMRK) {
					shifted_Q_EXMRK = false;
					unregister_code(KC_1);
				} else {
					return false;
				}
			}
		}
        return false;
        break;

        case L_PRN_ABK: {
		// tap = ( (shifted KC_9)		shift + tap = < (shifted KC_COMM)
			static bool shifted_L_PRN_ABK = false;
			if (record->event.pressed) {
				if (mod_state & MOD_MASK_SHIFT) {
					shifted_L_PRN_ABK = true;
					register_code(KC_COMM);
				} else {
					register_mods(MOD_BIT(KC_LSFT));
					register_code(KC_9);
				}
            } else {
				if (shifted_L_PRN_ABK) {
					shifted_L_PRN_ABK = false;
					unregister_code(KC_COMM);
				} else {
					unregister_code(KC_9);
					unregister_mods(MOD_BIT(KC_LSFT));
				}
			}
		}
        return false;
        break;

        case R_PRN_ABK: {
		// tap = ) (shifted KC_0)		shift + tap = > (shifted KC_DOT)
			static bool shifted_R_PRN_ABK = false;
			if (record->event.pressed) {
				if (mod_state & MOD_MASK_SHIFT) {
					shifted_R_PRN_ABK = true;
					register_code(KC_DOT);
				} else {
					register_mods(MOD_BIT(KC_LSFT));
					register_code(KC_0);
				}
            } else {
				if (shifted_R_PRN_ABK) {
					shifted_R_PRN_ABK = false;
					unregister_code(KC_DOT);
				} else {
					unregister_code(KC_0);
					unregister_mods(MOD_BIT(KC_LSFT));
				}
			}
		}
        return false;
        break;

        case COMM_SCLN: {
		// tap = , (KC_COMM)			shift + tap = ; (unshifted KC_SCLN)
			static bool shifted_COM_SCLN = false;
			if (record->event.pressed) {
				if (mod_state & MOD_MASK_SHIFT) {
					shifted_COM_SCLN = true;
					del_mods(MOD_MASK_SHIFT);
					register_code(KC_SCLN);
					set_mods(mod_state);
				} else {
					register_code(KC_COMM);
				}
            } else {
				if (shifted_COM_SCLN) {
					shifted_COM_SCLN = false;
					unregister_code(KC_SCLN);
				} else {
					unregister_code(KC_COMM);
				}
			}
		}
        return false;
        break;

        case DOT_COLN: {
		// tap = . (KC_DOT)				shift + tap = : (shifted KC_SCLN)
			static bool shifted_DOT_COLN = false;
			if (record->event.pressed) {
				if (mod_state & MOD_MASK_SHIFT) {
					shifted_DOT_COLN = true;
					register_code(KC_SCLN);
				} else {
					register_code(KC_DOT);
				}
            } else {
				if (shifted_DOT_COLN) {
					shifted_DOT_COLN = false;
					unregister_code(KC_SCLN);
				} else {
					unregister_code(KC_DOT);
				}
			}
		}
        return false;
        break;

        case SLSH_UNDS: {
		// tap = / (KC_SLSH)			shift + tap = _ (shifted KC_MINS)
			static bool shifted_SLSH_UNDS = false;
			if (record->event.pressed) {
				if (mod_state & MOD_MASK_SHIFT) {
					shifted_SLSH_UNDS = true;
					register_code(KC_MINS);
				} else {
					register_code(KC_SLSH);
				}
            } else {
				if (shifted_SLSH_UNDS) {
					shifted_SLSH_UNDS = false;
					unregister_code(KC_MINS);
				} else {
					unregister_code(KC_SLSH);
				}
			}
		}
        return false;
        break;

        case COMM_COMM: {
		// tap = , (KC_COMM)			shift + tap = , (unshifted KC_COMM)
			static bool shifted_COMM_COMM = false;
			if (record->event.pressed) {
				if (mod_state & MOD_MASK_SHIFT) {
					shifted_COMM_COMM = true;
					del_mods(MOD_MASK_SHIFT);
					register_code(KC_COMM);
					set_mods(mod_state);
				} else {
					register_code(KC_COMM);
				}
            } else {
				if (shifted_COMM_COMM) {
					shifted_COMM_COMM = false;
					unregister_code(KC_COMM);
				} else {
					unregister_code(KC_COMM);
				}
			}
		}
        return false;
        break;

        case QWERTY: {
		// tap = set default layer to _QWERTY
			if (record->event.pressed) {
				set_single_persistent_default_layer(_QWERTY);
            } else {
				return false;
			}
		}
        return false;
        break;

        case TARMAK1: {
		// tap = set default layer to _TARMAK1
			if (record->event.pressed) {
				set_single_persistent_default_layer(_TARMAK1);
            } else {
				return false;
			}
		}
        return false;
        break;

        case TARMAK2: {
		// tap = set default layer to _TARMAK2
			if (record->event.pressed) {
				set_single_persistent_default_layer(_TARMAK2);
            } else {
				return false;
			}
		}
        return false;
        break;

        case TARMAK3: {
		// tap = set default layer to _TARMAK3
			if (record->event.pressed) {
				set_single_persistent_default_layer(_TARMAK3);
            } else {
				return false;
			}
		}
        return false;
        break;

        case TARMAK4: {
		// tap = set default layer to _TARMAK4
			if (record->event.pressed) {
				set_single_persistent_default_layer(_TARMAK4);
            } else {
				return false;
			}
		}
        return false;
        break;

        case COLEMAK: {
		// tap = set default layer to _COLEMAK
			if (record->event.pressed) {
				set_single_persistent_default_layer(_COLEMAK);
            } else {
				return false;
			}
		}
        return false;
        break;

		// EQL_NUM key				tap = = (KC_EQL - KC_PEQL does not work)				shift + tap = toggle NUM_ON layer
        case LT(0,KC_0): {
			if (record->event.pressed) {
				if (record->tap.count <= 0) {
					if (mod_state & MOD_MASK_SHIFT) {
						if (held_NUM_ON) {
							held_NUM_ON = false;
							layer_off(_NUM_ON);
							layer_off(_NAVNUM);
						} else {
							held_NUM_ON = true;
							layer_off(_R_NUM);
							layer_on(_NUM_ON);
						}
					} else {
						return false;
					}
				} else {
					register_code(KC_EQL);
				}
			} else {
				if (record->tap.count <= 0) {
					return false;
				} else {
					unregister_code(KC_EQL);
				}
			}
		}
        return false;
        break;
		
		// L_NUM_SPC key			tap = space				hold = temporary NAVNUM layer
        case LT(0,KC_1): {
			if (record->event.pressed) {
				if (record->tap.count <= 0) {
					held_L_NUM = true;
					layer_on(_NAVNUM);
				} else {
					register_code(KC_SPC);
				}
			} else {
				if (record->tap.count <= 0) {
					held_L_NUM = false;
					if (held_R_NUM || held_NUM_ON) {
						return false;
					} else {
						layer_off(_NAVNUM);
					}
				} else {
					unregister_code(KC_SPC);
				}
			}
		}
        return false;
        break;
		
		// R_NUM_SPC key			tap = space				hold = temporary NAVNUM & R_NUM layers
        case LT(0,KC_2): {
			if (record->event.pressed) {
				if (record->tap.count <= 0) {
					held_R_NUM = true;
					layer_on(_NAVNUM);
					layer_on(_R_NUM);
				} else {
					register_code(KC_SPC);
				}
			} else {
				if (record->tap.count <= 0) {
					held_R_NUM = false;
					layer_off(_R_NUM);
					if (held_L_NUM || held_NUM_ON) {
						return false;
					} else {
						layer_off(_NAVNUM);
					}
				} else {
					unregister_code(KC_SPC);
				}
			}
		}
        return false;
        break;
		
		// R_NUM_0 key
		// tap = 0					hold = temporary R_NUM layer
        case LT(0,KC_3): {
			if (record->event.pressed) {
				if (record->tap.count <= 0) {
					held_R_NUM = true;
					layer_on(_R_NUM);
				} else {
					register_code(KC_0);
				}
			} else {
				if (record->tap.count <= 0) {
					held_R_NUM = false;
					layer_off(_R_NUM);
					if (held_L_NUM || held_NUM_ON) {
						return false;
					} else {
						layer_off(_NAVNUM);
					}
				} else {
					unregister_code(KC_0);
				}
			}
		}
        return false;
        break;
		
		// DOT_DEL key
		// tap = . (KC_DOT)			shift + tap = . (KC_DOT)		hold = temporary DEL layer
        case LT(0,KC_4): {
			static bool shifted_DOT_DEL = false;
			if (record->event.pressed) {
				if (record->tap.count <= 0) {
					layer_on(_DEL);
				} else {
					if (mod_state & MOD_MASK_SHIFT) {
						shifted_DOT_DEL = true;
						del_mods(MOD_MASK_SHIFT);
						register_code(KC_DOT);
						set_mods(mod_state);
					} else {
						register_code(KC_DOT);
					}
				}
			} else {
				if (record->tap.count <= 0) {
					layer_off(_DEL);
				} else {
					if (shifted_DOT_DEL) {
						shifted_DOT_DEL = false;
						unregister_code(KC_DOT);
					} else {
						unregister_code(KC_DOT);
					}
				}
			}
		}
        return false;
        break;

		// LCTL_CAPS key			right shift + tap = caps lock			all else = left control
        case LT(0,KC_5): {
			static bool shifted_LCTL_CAPS = false;
			if (record->event.pressed) {
				if (record->tap.count <= 0) {
					register_mods(MOD_BIT(KC_LCTL));
				} else {
					if ((mod_state & MOD_BIT(KC_RSFT)) == MOD_BIT(KC_RSFT)) {
						shifted_LCTL_CAPS = true;
						register_code(KC_CAPS);
					} else {
						register_mods(MOD_BIT(KC_LCTL));
					}
				}
			} else {
				if (record->tap.count <= 0) {
					unregister_mods(MOD_BIT(KC_LCTL));
				} else {
					if (shifted_LCTL_CAPS) {
						shifted_LCTL_CAPS = false;
						unregister_code(KC_CAPS);
					} else {
						unregister_mods(MOD_BIT(KC_LCTL));
					}
				}
			}
		}
        return false;
        break;

		// LGUI_FKEY key			tap = left GUI			double tap and hold = hold left GUI				hold = temporary FKEY layer
        case LT(0,KC_6): {
			if (record->event.pressed) {
				if (record->tap.count <= 0) {
					held_L_FKEY = true;
					layer_on(_FKEY);
					if (held_R_FKEY) {
						layer_on(_FUNCTION);
					}
				} else if (record->tap.count >= 1) {
					register_mods(MOD_BIT(KC_LGUI));
				} else {
					register_mods(MOD_BIT(KC_LGUI));
				}
			} else {
				if (record->tap.count <= 0) {
					held_L_FKEY = false;
					layer_off(_FUNCTION);
					if (held_R_FKEY) {
						return false;
					} else {
						layer_off(_FKEY);
					}
				} else if (record->tap.count >= 1) {
					unregister_mods(MOD_BIT(KC_LGUI));
				} else {
					unregister_mods(MOD_BIT(KC_LGUI));
				}
			}
		}
        return false;
        break;
		
		// RGUI_FKEY key			tap = right GUI				hold = temporary FKEY layer
        case LT(0,KC_7): {
			if (record->event.pressed) {
				if (record->tap.count <= 0) {
					held_R_FKEY = true;
					layer_on(_FKEY);
					if (held_L_FKEY) {
						layer_on(_FUNCTION);
					} else {
						return false;
					}
				} else {
					register_mods(MOD_BIT(KC_RGUI));
				}
			} else {
				if (record->tap.count <= 0) {
					held_R_FKEY = false;
					layer_off(_FUNCTION);
					if (held_L_FKEY) {
						return false;
					} else {
						layer_off(_FKEY);
					}
				} else {
					unregister_mods(MOD_BIT(KC_RGUI));
				}
			}
		}
        return false;
        break;


		// MAGIC KEYCODES defined in: \qmk_firmware\quantum\process_keycode\process_magic.c
		// save a little space with MAGIC_ENABLE = no
		// only define the Magic keys needed for this layout
		// Same as MAGIC_TOGGLE_NKRO
		case TOG_NKRO:
			if (record->event.pressed) {
				clear_keyboard();  // clear first buffer to prevent stuck keys
				keymap_config.nkro = !keymap_config.nkro;
/*				if (keymap_config.nkro) {			// can use something similar for OLED display?
					print("NKRO: on\n");
				} else {
					print("NKRO: off\n");
				}	*/
			} else {
				return false;
			}
		break;


    }
    return true;
};											




/*



        case LT(0,KC_0): {
		// EQL_NUM key
		// tap = = (KC_EQL - KC_PEQL does not work)				shift +  = toggle NUM_ON layer
			if (record->event.pressed) {
				if (held_NUM_ON) {
					held_NUM_ON = false;
					layer_off(_NUM_ON);
					layer_off(_NAVNUM);
				} else {
					held_NUM_ON = true;
					layer_off(_R_NUM);
					layer_on(_NUM_ON);
				}
			} else {
				return false;
			}
		}
        return false;
        break;

		

        case LT(0,KC_0): {
		// EQL_NUM key
		// tap = = (KC_EQL - KC_PEQL does not work)		shift + tap = numlock				shift + hold = toggle TENKEY layer
			static bool shifted_EQL_NUM = false;
			if (record->event.pressed) {
				if (mod_state & MOD_MASK_SHIFT) {
					shifted_EQL_NUM = true;
					if (record->tap.count <= 0) {
						layer_invert(_TENKEY);
					} else {
						register_code(KC_NUMLOCK);
					}
				} else {
					register_code(KC_EQL);
				}
			} else {
				if (shifted_EQL_NUM) {
					shifted_EQL_NUM = false;
					if (record->tap.count <= 0) {
						return false;
					} else {
						unregister_code(KC_NUMLOCK);
					}
				} else {
					unregister_code(KC_EQL);
				}
			}
		}
        return false;
        break;
		
		
        case LT(0,KC_6): {
		// R_NUM_SPC key
		// tap = toggle NUM_ON layer			hold = momentary TENKEY layer with left alt modifier
			if (record->event.pressed) {
				if (record->tap.count <= 0) {
					register_mods(MOD_BIT(KC_LALT));
					layer_on(_TENKEY);
				} else {
					NUM_ON = true;
					if (held_R_NUM)
						layer_off(_R_NUM);
					}
				}
			} else {
				if (record->tap.count <= 0) {
					layer_off(_TENKEY);
					unregister_mods(MOD_BIT(KC_LALT));
				} else {
					unregister_code(KC_SPC);
				}
			}
		}
        return false;
        break;
		


		// In order to track the HOLD and TAP status must use key overrides (https://docs.qmk.fm/#/feature_key_overrides).
		// Must use a MOD_TAP function (such as LT(layer,key) ) to record HOLD and TAP events and then define custom behaviour.
		//
		// #define		EXAMPLE_KEY			LT(0,KC_0)			// the layer and key don't matter (must be unique for each custom key)
		//
		// EXAMPLE_KEY key
        case LT(0,KC_0): {
			
			// variable to track if the key was pressed while SHIFT was held
			static bool shifted_XXXXXX;
		
			// if the key is pressed
			if (record->event.pressed) {

				// if either SHIFT key is held
				if (mod_state & MOD_MASK_SHIFT) {
					
					// record key was pressed while SHIFT was held
					// necessary for logic when key is released
					shifted_XXXXXX = true;

					// if the key is held or interrupted by another key press
					// recognizing the key as held when interrupted is helpful for fast typing needs such as shift
					// remove " || record->tap.interrupted" if the held action is triggered too easily
					if (record->tap.count <= 0 || record->tap.interrupted) {
					
					// 
					right_shift = true;
					register_mods(MOD_BIT(KC_LSFT));
				} else {
					register_code(KC_9);
				}


			static bool shifted_RALT_DOT = false;
			if (record->event.pressed) {
				if (record->tap.count <= 0) {
					register_mods(MOD_BIT(KC_RALT));
				} else {
					if (mod_state & MOD_MASK_SHIFT) {
						shifted_RALT_DOT = true;
						del_mods(MOD_MASK_SHIFT);
						register_code(KC_DOT);
						set_mods(mod_state);
					} else {
						register_code(KC_DOT);
					}
				}
			} else {
				if (record->tap.count <= 0) {
					unregister_mods(MOD_BIT(KC_RALT));
				} else {
					if (shifted_RALT_DOT) {
						shifted_RALT_DOT = false;
						unregister_code(KC_DOT);
					} else {
						unregister_code(KC_DOT);
					}
				}
			}
		}
        return false;
        break;



				
			// when the key is released
			} else {
				if (record->tap.count <= 0 || record->tap.interrupted) {
					unregister_mods(MOD_BIT(KC_LSFT));
					right_shift = false;
				} else {
					unregister_code(KC_9);
				}
			}
        return false;
        break;
*/





