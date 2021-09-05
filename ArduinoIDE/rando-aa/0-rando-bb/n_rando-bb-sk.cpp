#define DATESTAMP "Sun Sep  5 04:26:39 UTC 2021"
// swap these two to use 'cppcheck --enable=all ./thisfile.cpp'
#define N_CPPCHECK
#undef  N_CPPCHECK

#ifndef  N_CPPCHECK
#include <Arduino.h>
#endif

#define DDEBUG_LVL 0

#define msg00 "Magic 8 Ball"

const String p_project = msg00; // "Magic 8 Ball";
const uint8_t version_hi = 0;
const uint8_t version_lo = 1;

// https://en.wikipedia.org/wiki/Icosahedron

const char icosahdrn_face_message[][28] { // exact count
    "It is certain            ",
    "Without a doubt          ",
    "You may rely on it       ",
    "Yes definitely           ",
    "It is decidedly so       ",
    "As I see it, yes         ",
    "Most likely              ",
    "Yes                      ",
    "Outlook good             ",
    "Signs point to yes       ",
    "Reply hazy try again     ",
    "Better not tell you now  ",
    "Ask again later          ",
    "Cannot predict now       ",
    "Concentrate and ask again",
    "Don’t count on it        ",
    "Outlook not so good      ",
    "My sources say no        ",
    "Very doubtful            ",
    "My reply is no           ",};
   //   1...v....x....v....x....v..

int generateRando;
int serialData;

void versionPrint (void) {
    Serial.println (DATESTAMP);
}

extern void init_gpio ();
extern void init_serial ();

void generateAnswer () {
    generateRando = random (1, 20);
    Serial.print ("rando: ");
    Serial.println (generateRando);
    Serial.print ("bracket >> ");
    // Serial.print (   dodeca_face_message[generateRando]);
    Serial.print (icosahdrn_face_message[generateRando]);
    Serial.println (" << bracket");
    generateRando = 0;
}

extern void readword (); // keyboard input via USB serial port

void waitForQuestion () {
    readword ();
    generateAnswer ();
}

void setup () {
    delay (5000);
    init_gpio ();
    init_serial ();
    versionPrint ();
    randomSeed (analogRead (26));
    Serial.println ("Welcome to Magic 8 ball");
    Serial.println ("Please ask your question");
}

void loop () {
    waitForQuestion ();
}

#ifdef  N_CPPCHECK
int main (void) {
    setup ();
    loop ();
}
#endif

// $  cppcheck --enable=all ./n_rando-bb-sk.cpp
// Checking n_rando-bb-sk.cpp ...
// END
