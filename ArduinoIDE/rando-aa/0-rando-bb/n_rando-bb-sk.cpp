#define DATESTAMP "Sun Sep  5 03:31:17 UTC 2021"
#include <Arduino.h>

#define msg00 "Magic 8 Ball"
const String p_project = msg00; // "Magic 8 Ball";
const uint8_t version_hi = 0;
const uint8_t version_lo = 1;

   //          1...v....x....v....x....v
const char dodeca_face_message [][28] { // exact count
 "It is certain            " ,
 "Without a doubt          " ,
 "You may rely on it       " ,
 "Yes definitely           " ,
 "It is decidedly so       " ,
 "As I see it, yes         " ,
 "Most likely              " ,
 "Yes                      " ,
 "Outlook good             " ,
 "Signs point to yes       " ,
 "Reply hazy try again     " ,
 "Better not tell you now  " ,
 "Ask again later          " ,
 "Cannot predict now       " ,
 "Concentrate and ask again" ,
 "Don’t count on it        " ,
 "Outlook not so good      " ,
 "My sources say no        " ,
 "Very doubtful            " ,
 "My reply is no           " ,
};

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
    Serial.print("bracket >> ");
    Serial.print(dodeca_face_message[generateRando]);
    Serial.println(" << bracket");
/*
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
*/
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
