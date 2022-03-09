

const key_override_t next_track_override = 
    ko_make_with_layers_negmods_and_options(
        MOD_MASK_SHIFT,      				// Trigger modifiers: ctrl
        KC_VOLU,             				// Trigger key: volume up
        KC_MNXT,             				// Replacement key
        ~0,                  				// Activate on all layers
        MOD_MASK_CA,         				// Do not activate when shift or alt are pressed
        ko_option_no_reregister_trigger); 	// Specifies that the volume up key is not registered again after lifting ctrl
    
const key_override_t prev_track_override = ko_make_with_layers_negmods_and_options(MOD_MASK_CA, KC_VOLD,
                                            KC_MPRV, ~0, MOD_MASK_CA, ko_option_no_reregister_trigger);

const key_override_t vol_up_override = ko_make_with_layers_negmods_and_options(MOD_MASK_ALT, KC_MPLY,
                                            KC_VOLU, ~0, MOD_MASK_CS, ko_option_no_reregister_trigger);

const key_override_t vol_down_override = ko_make_with_layers_negmods_and_options(MOD_MASK_SA, KC_MPLY,
                                            KC_VOLD, ~0, MOD_MASK_CTRL, ko_option_no_reregister_trigger);

const key_override_t brightness_up_override = ko_make_with_layers_negmods_and_options(MOD_MASK_CA, KC_MPLY,
                                            KC_BRIU, ~0, MOD_MASK_SHIFT, ko_option_no_reregister_trigger);

const key_override_t brightness_down_override = ko_make_basic(MOD_MASK_CSA, KC_MPLY, KC_BRID);

// This globally defines all key overrides to be used
const key_override_t **key_overrides = (const key_override_t *[]){
    &next_track_override,
    &prev_track_override,
    &vol_up_override,
    &vol_down_override,
    &brightness_up_override,
    &brightness_down_override,
    NULL
};