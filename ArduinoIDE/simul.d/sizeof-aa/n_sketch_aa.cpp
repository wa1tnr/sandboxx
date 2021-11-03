// sizeof-aa/n_sketch_aa.cpp
// target: Uno R3
// sim: https://wokwi.com/arduino/new?template=arduino-uno
int myStr[] = {5, 6, 1, 3, 17, 27, 31, 93} ;

int ln_array = sizeof(myStr);
int ln_first_element = sizeof(myStr[0]);
int length = sizeof(myStr)/sizeof(myStr[0]);

void setup() {
  Serial.begin(9600);
  Serial.print("length of array in 'entries': ");
  Serial.println(length);
  Serial.print("length of array 'ln_array': ");
  Serial.println(ln_array);
  Serial.print("length of first element 'ln_first_element': ");
  Serial.println(ln_first_element);
  delay(6000); // give time to contemplate.
}

void loop() {
  for (byte i = 0; (i < length); i++) {
    Serial.print("i is: ");
    Serial.print(i, DEC);
    Serial.print(" = ");
    Serial.print(myStr[i]);
    Serial.print("  .. or .. ");
//  Serial.write(myStr[i] + 65 - 16 - 1);
    Serial.write(myStr[i] + 48); // ASCII encoded
    Serial.println();
  }
  delay(9000);  // slow down the program
}
