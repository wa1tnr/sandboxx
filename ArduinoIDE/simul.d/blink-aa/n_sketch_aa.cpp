// wowiki
// blink-aa/n_sketch_aa.cpp

// https://wokwi.com/arduino/new?template=pi-pico

#define LDELAY 5000
#define SDELAY  1800

void blink(void) {
  digitalWrite(LED_BUILTIN, 1);
  Serial1.print(" BLINK  ");
  delay(SDELAY);
  digitalWrite(LED_BUILTIN, 0);
  Serial1.print(" --- ");
  delay(LDELAY);
}

void setup() {
  // put your setup code here, to run once:
  Serial1.begin(115200);
  delay(3000);
  Serial1.println("Hello, Raspberry Pi Pico!");
  for (int i=3;i>0;i--) {
    blink();
  }
  Serial1.println("DONE.");
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(1); // this speeds up the simulation
}

