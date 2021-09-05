// swap these two to use 'cppcheck --enable=all ./thisfile.cpp'
#define N_CPPCHECK
#undef  N_CPPCHECK

#ifndef  N_CPPCHECK
#include <Arduino.h>
#endif

#define DDEBUG_LVL 0 // 2

/* Terminal Input Buffer for interpreter */
const byte maxtib = 64; // 16 may be more appropriate
char tib[maxtib];
byte pos;
char ch;

#define EOL_CHAR '\n'
/* Incrementally read command line from serial port */
byte reading () {
    if (!Serial.available ())
        return 1;
    ch = Serial.read ();
    Serial.print (ch); // keystroke echo.  OPTIONAL.

    if (ch == EOL_CHAR) {
        Serial.print ('\r');
    } // try to do CR without LF here

    if (ch == EOL_CHAR) {
        return 0;
    }
    if ((ch == '\010') || (ch == '\177')) { // backspace or rubout
        if (ch == '\177') {
            Serial.print ("\010"); // 0x08
            Serial.print (" mutt and jeff "); // 0x08
        }
        Serial.print (' ');
        Serial.print ("\010"); // 0x08
        if (pos == 0) {
            return 1;
        }
        tib[pos--] = 0;
        tib[pos] = 0;
        return 1; // continue reading keystrokes
    }

    if (pos < maxtib) {
        tib[pos++] = ch;
        tib[pos] = 0;
    }
    // individual, non-special compositional keystrokes
    // fall through to here:
    return 1;
}

/* Block on reading the command line from serial port */
/* then echo each word */
void readword () {
    pos = 0;
    tib[0] = 0;
    while (reading ());
    if (DDEBUG_LVL == 2) {
        Serial.print (tib);
        Serial.print (" ");
        Serial.println ("  that was \'tib\'  for you.");
    }
}

// / Run a word via its name /

bool pin_state; // is this really a bool or just an int that is equal to zero, or to one

void cpl (int pin) {
    pin_state = digitalRead (LED_BUILTIN);
    pin_state = !pin_state; // how does this interface to typing as bool or as int
    digitalWrite (LED_BUILTIN, pin_state);
}

void delayed (void) {
    if (pin_state != false) { // obeyed bool typing - made explicit.  mistake?
        delay (10);
        return;
    }
    delay (3000); // harmless - waiting for serial
}

void blink (void) {
    cpl (LED_BUILTIN);
    delayed ();
}

void init_gpio (void) {
    pinMode (LED_BUILTIN, 1);
    digitalWrite (LED_BUILTIN, 0);
}

void init_serial (void) {
    Serial.begin (115200);
    while (!Serial) {
        blink ();
    }
}

#ifdef  N_CPPCHECK
int main (void) {
    init_gpio ();
    init_serial ();
    readword ();
}
#endif

// ENiD,
//
// $ cppcheck --enable=all ./qk_sketch_adds.cpp 
// Checking qk_sketch_adds.cpp ...
// $
// END.
