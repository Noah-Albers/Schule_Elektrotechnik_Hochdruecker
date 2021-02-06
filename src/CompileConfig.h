#pragma once

// Holds the pins on which the leds are connected
const char LED_PINS[5] = {32,33,25,26,27};

// The pins for the buttons (switch and trigger)
const int BUTTON_PIN_SWITCH = 14;
const int BUTTON_PIN_TRIGGER = 12;

/*
 * The following part of the script doesn't need to be changed, it will be autogenerated
 */

// How many leds are connected
const int AMOUNT_LEDS = sizeof(LED_PINS)/sizeof(*LED_PINS);