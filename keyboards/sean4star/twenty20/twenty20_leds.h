/*
 *    LEDs!
 */

/* LED pin configuration
 *
 * CAPS         PC7
 * Scroll Lock  PD6
 * Num Lock     XXX
 *
 * BACKLIGHT    PD4
 */

/*
 *    System LEDs
 */

void led_set_user(uint8_t usb_led) {

    DDRC |= (1<<7);
    DDRD |= (1<<6);

	if (usb_led & (1 << USB_LED_NUM_LOCK)) {
	} else {
	}
	if (usb_led & (1 << USB_LED_CAPS_LOCK)) {
        PORTC |= (1<<7);
	} else {
        PORTC &= ~(1<<7);
	}
	if (usb_led & (1 << USB_LED_SCROLL_LOCK)) {
	} else {
	}
	if (usb_led & (1 << USB_LED_COMPOSE)) {
	} else {
	}
	if (usb_led & (1 << USB_LED_KANA)) {
	} else {
	}
}

/*
 *    Layer state to trigger LED
 */
uint32_t layer_state_set_kb(uint32_t state) {

    DDRD |= (1<<4);

	if (state & (1<<BTK)){
		PORTD |= (1 << 4);
	}
	else{
		PORTD &= ~(1 << 4);
	}
	return state;
}