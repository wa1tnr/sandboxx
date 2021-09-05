#define DATESTAMP "Sun Sep  5 02:37:20 UTC 2021"
#include <Arduino.h>

#define msg00 "Magic 8 Ball"
const String p_project = msg00; // "Magic 8 Ball";
const uint8_t version_hi = 0;
const uint8_t version_lo = 1;
#define msg01 "It is certain"
const String response01 = msg01; // "It is certain";
#define msg02 "Without a doubt"
const String response02 = msg02; // "Without a doubt";
#define msg03 "You may rely on it"
const String response03 = msg03; // "You may rely on it";
#define msg04 "Yes definitely"
const String response04 = msg04; // "Yes definitely";
#define msg05 "It is decidedly so"
const String response05 = msg05; // "It is decidedly so";
#define msg06 "As I see it, yes"
const String response06 = msg06; // "As I see it, yes";
#define msg07 "Most likely"
const String response07 = msg07; // "Most likely";
#define msg08 "Yes"
const String response08 = msg08; // "Yes";
#define msg09 "Outlook good"
const String response09 = msg09; // "Outlook good";
#define msg10 "Signs point to yes"
const String response10 = msg10; // "Signs point to yes";
#define msg11 "Reply hazy try again"
const String response11 = msg11; // "Reply hazy try again";
#define msg12 "Better not tell you now"
const String response12 = msg12; // "Better not tell you now";
#define msg13 "Ask again later"
const String response13 = msg13; // "Ask again later";
#define msg14 "Cannot predict now"
const String response14 = msg14; // "Cannot predict now";
#define msg15 "Concentrate and ask again"
const String response15 = msg15; // "Concentrate and ask again";
#define msg16 "Don’t count on it"
const String response16 = msg16; // "Don’t count on it";
#define msg17 "Outlook not so good"
const String response17 = msg17; // "Outlook not so good";
#define msg18 "My sources say no"
const String response18 = msg18; // "My sources say no";
#define msg19 "Very doubtful"
const String response19 = msg19; // "Very doubtful";
#define msg20 "My reply is no"
const String response20 = msg20; // "My reply is no";
int generateRando;
int serialData;

void versionPrint (void) {
    Serial.println (DATESTAMP);
}

extern void init_gpio ();
extern void init_serial ();

void setup () {
    delay (5000);
    // Serial.begin (9600);
    init_gpio ();
    init_serial ();
    versionPrint ();
    randomSeed (analogRead (26));
    Serial.println ("Welcome to Magic 8 ball");
    Serial.println ("Please ask your question");
}

void generateAnswer () {
    generateRando = random (1, 20);
    Serial.print ("rando: ");
    Serial.println (generateRando);
    switch (generateRando) {
    case 1:
        Serial.println (msg01);
        break;
    case 2:
        Serial.println (msg02);
        break;
    case 3:
        Serial.println (msg03);
        break;
    case 4:
        Serial.println (msg04);
        break;
    case 5:
        Serial.println (msg05);
        break;
    case 6:
        Serial.println (msg06);
        break;
    case 7:
        Serial.println (msg07);
        break;
    case 8:
        Serial.println (msg08);
        break;
    case 9:
        Serial.println (msg09);
        break;
    case 10:
        Serial.println (msg10);
        break;
    case 11:
        Serial.println (msg11);
        break;
    case 12:
        Serial.println (msg12);
        break;
    case 13:
        Serial.println (msg13);
        break;
    case 14:
        Serial.println (msg14);
        break;
    case 15:
        Serial.println (msg15);
        break;
    case 16:
        Serial.println (msg16);
        break;
    case 17:
        Serial.println (msg17);
        break;
    case 18:
        Serial.println (msg18);
        break;
    case 19:
        Serial.println (msg19);
        break;
    case 20:
        Serial.println (msg20);
        break;
    default:
        break;
    }
    // DEBUG // Serial.println("generateRando SEEN");
    generateRando = 0;
}

extern void readword ();

void waitForQuestion () {
    readword ();
    generateAnswer ();
}

void loop () {
    waitForQuestion ();
}

// END
