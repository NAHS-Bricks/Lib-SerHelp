#include <nahs-Bricks-Lib-SerHelp.h>

NahsBricksLibSerHelp::NahsBricksLibSerHelp() {
}

/*
Helper to read one line from Serial as input
*/
String NahsBricksLibSerHelp::readLine() {
  const byte maxChars = 32;
  char inputBuffer[maxChars];
  byte nextPos = 0;
  
  while (true) {
    if (Serial.available() > 0) {
      char input = Serial.read();
      if (input == '\n') {
        inputBuffer[nextPos] = '\0';
        Serial.print('\n');
        return String(inputBuffer);
      }
      if (input == '\b') {
        if (nextPos > 0) {
          nextPos--;
          inputBuffer[nextPos] = '\b';
          Serial.print('\b');
        }
      }
      else if (input != '\r') {
        inputBuffer[nextPos] = input;
        nextPos++;
        if (nextPos >= maxChars) nextPos--;
        Serial.print(input);
      }
    }
  }
}

/*
Helper to print a boolean variable as text
*/
void NahsBricksLibSerHelp::printBool(bool var) {
  if (var) Serial.print("true");
  else Serial.print("false");
}

/*
Helper to println a boolean variable as text
*/
void NahsBricksLibSerHelp::printlnBool(bool var) {
  if (var) Serial.println("true");
  else Serial.println("false");
}

//------------------------------------------
// globally predefined variable
#if !defined(NO_GLOBAL_INSTANCES)
NahsBricksLibSerHelp SerHelp;
#endif
