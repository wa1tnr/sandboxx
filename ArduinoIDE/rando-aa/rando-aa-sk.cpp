#define DATESTAMP "Sat Sep  4 19:49:32 UTC 2021"
#include <Arduino.h>

const String p_project = "Magic 8 Ball";
const uint8_t version_hi = 0;
const uint8_t version_lo = 1;
const String response01 = "It is certain";
const String response02 = "Without a doubt";
const String response03 = "You may rely on it";
const String response04 = "Yes definitely";
const String response05 = "It is decidedly so";
const String response06 = "As I see it, yes";
const String response07 = "Most likely";
const String response08 = "Yes";
const String response09 = "Outlook good";
const String response10 = "Signs point to yes";
const String response11 = "Reply hazy try again";
const String response12 = "Better not tell you now";
const String response13 = "Ask again later";
const String response14 = "Cannot predict now";
const String response15 = "Concentrate and ask again";
const String response16 = "Don’t count on it";
const String response17 = "Outlook not so good";
const String response18 = "My sources say no";
const String response19 = "Very doubtful";
const String response20 = "My reply is no";
int generateRando;
int serialData;

void versionPrint(void)
{
  Serial.println(DATESTAMP);
}

void setup() {
  delay(5000);
  Serial.begin(9600);
  versionPrint();
  randomSeed(analogRead(26));
  Serial.println("Welcome to Magic 8 ball");
  Serial.println("Please ask your question");
}

void loop() {
  waitForQuestion();
}

void waitForQuestion() {
  serialData = Serial.read();
  if (serialData >= 1) {
    serialData = 0;
    generateAnswer();
  }
}

void generateAnswer() {
  generateRando = random(1, 20);
  Serial.print("rando: ");
  Serial.println(generateRando);
  switch (generateRando) {
    case 1:
      Serial.println(response01);
      break;
    case 2:
      Serial.println(response02);
      break;
    case 3:
      Serial.println(response03);
      break;
    case 4:
      Serial.println(response04);
      break;
    case 5:
      Serial.println(response05);
      break;
    case 6:
      Serial.println(response06);
      break;
    case 7:
      Serial.println(response07);
      break;
    case 8:
      Serial.println(response08);
      break;
    case 9:
      Serial.println(response09);
      break;
    case 10:
      Serial.println(response10);
      break;
    case 11:
      Serial.println(response11);
      break;
    case 12:
      Serial.println(response12);
      break;
    case 13:
      Serial.println(response13);
      break;
    case 14:
      Serial.println(response14);
      break;
    case 15:
      Serial.println(response15);
      break;
    case 16:
      Serial.println(response16);
      break;
    case 17:
      Serial.println(response17);
      break;
    case 18:
      Serial.println(response18);
      break;
    case 19:
      Serial.println(response19);
      break;
    case 20:
      Serial.println(response20);
      break;
    default:
      break;
  }
  generateRando = 0;
}

// END
