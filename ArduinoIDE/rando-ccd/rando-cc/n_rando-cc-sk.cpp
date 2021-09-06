// #define DATESTAMP "Sun Sep  5 21:07:55 UTC 2021"
#include "p_rando.h"
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

// int generateRando;
int serialData;

void versionPrint (void) {
    Serial.println (DATESTAMP);
}

int generateAnswer (void) {
    int genRnd = random (1, 20);
    Serial.print ("rando: ");
    Serial.println (genRnd);
    return (genRnd);
}

// void reset_m8b (void) { generateRando = 0; }

void reportIcosaFaceMsg (int icos_idx) {
// int generateRando;

    if (DDEBUG_LVL == 2) {
        Serial.print ("bracket >> ");
    }

    Serial.print (icosahdrn_face_message[icos_idx]);

    if (DDEBUG_LVL == 0) {
        Serial.println ();
    }

    if (DDEBUG_LVL == 2) {
        Serial.println (" << bracket");
    }
}

void answerQuestion() {
    int answ = generateAnswer ();
    reportIcosaFaceMsg (answ);
}

extern void readword (); // keyboard input via USB serial port

void waitForQuestion () {
    readword ();
}

void greet(void) {
    Serial.println ("Welcome to Magic 8 ball");
    Serial.println ("Please ask your question");
}

#define ANA_PIN 26

void  randomize(void) {
    randomSeed (analogRead (ANA_PIN));
}

void hold_booting(void) {
    delay (1100);
}

extern void init_gpio ();
extern void init_serial ();

void setup () {
    hold_booting();
    init_gpio ();
    init_serial ();
    versionPrint ();
    randomize();
    greet();
}

void loop () {
    waitForQuestion ();
    answerQuestion();
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
