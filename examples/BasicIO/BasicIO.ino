#include <Arduino.h>
#include <nahs-Bricks-Lib-SerHelp.h>

void setup() {
  Serial.begin(115200);
  Serial.println();

  Serial.print("What's your name?: ");
  String name = SerHelp.readLine();
  Serial.print("Hello ");
  Serial.println(name);

  Serial.print("How much loops?: ");
  uint8_t input = SerHelp.readLine().toInt();

  for(uint8_t i = 0; i < input; ++i) {
    Serial.print("Print ");
    SerHelp.printBool(true);
    Serial.println(" inline");
    Serial.print("Print ");
    SerHelp.printBool(false);
    Serial.println(" inline");
    Serial.print("Print linebreak: ");
    SerHelp.printlnBool(true);
    Serial.print("Print linebreak: ");
    SerHelp.printlnBool(false);
    Serial.println();
  }
}

void loop() {
}
