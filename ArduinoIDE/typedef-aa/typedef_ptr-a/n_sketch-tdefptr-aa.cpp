// n_sketch-tdefptr-aa.cpp
// Sun 10 Oct 21:06:13 UTC 2021

#include <Arduino.h>

void (*func)(void); // compiles as-is!

void test_gpio_TEMP(void) {
    digitalWrite (LED_BUILTIN, 1);
    delay(100);
    digitalWrite (LED_BUILTIN, 0);
    delay(500);
}

void init_gpio (void) {
    pinMode (LED_BUILTIN, 1);
    digitalWrite (LED_BUILTIN, 0);
}

#define blinks 7
void setup(void) {
    init_gpio ();
    delay(3000);
    for (int count = blinks; count >0; count--) {
        test_gpio_TEMP();
    }
}

void loop(void) {
    // statements
}

// END.
