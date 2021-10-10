// n_sketch-tdefptr-aa.cpp
// Sun 10 Oct 21:58:14 UTC 2021
#define DATE_STAMP "Sun 10 Oct 21:54:26 UTC 2021"

// swap these two to use 'cppcheck --enable=all ./thisfile.cpp'
#define N_CPPCHECK
#undef  N_CPPCHECK

#ifndef  N_CPPCHECK
#include <Arduino.h>
#endif

// #include <Arduino.h>

typedef void (*func) (void); // compiles as-is!

void test_gpio_TEMP (void) {
    digitalWrite (LED_BUILTIN, 1);
    delay (100);
    digitalWrite (LED_BUILTIN, 0);
    delay (500);
}

void _execute (void) {
    func function; // see NOTE AA, bottom of file
    function = *test_gpio_TEMP; // flashDict[w - 1].function; Dictionary.
    function ();
}

void init_gpio (void) {
    pinMode (LED_BUILTIN, 1);
    digitalWrite (LED_BUILTIN, 0);
}

void init_serial (void) {
    Serial.begin (115200);
    while (!Serial) {
        // blink ();
    }
}

#define blinks 7
void setup (void) {
    init_gpio ();
    delay (3000);
    for (int count = blinks; count > 0; count--) {
        // test_gpio_TEMP();
        _execute ();
    }
    init_serial ();
    delay (2000);
    Serial.println ("HELLO");
    Serial.println (DATE_STAMP);
}

void loop (void) {
    // statements
}

//  NOTE AA
//  func function;
//  https://github.com/wa1tnr/ainsuForth-gen-exp-m4/blob/master/0-Distribution.d/YAFFA-ARM-master/Dictionary.ino#L1033

// END.
