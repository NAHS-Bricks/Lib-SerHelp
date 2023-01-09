#include <nahs-Bricks-Lib-SerHelp.h>

NahsBricksLibSerHelp::NahsBricksLibSerHelp() {
}

/*
Helper to read one line from Serial as input
*/
String NahsBricksLibSerHelp::readLine(bool blocking) {
  while (true) {
    if (Serial.available() > 0) {
      char input = Serial.read();
      if (input == '\n') {
        readLine_inputBuffer[readLine_nextPos] = '\0';
        Serial.print('\n');
        readLine_nextPos = 0;
        return String(readLine_inputBuffer);
      }
      if (input == '\b') {
        if (readLine_nextPos > 0) {
          readLine_nextPos--;
          readLine_inputBuffer[readLine_nextPos] = '\b';
          Serial.print('\b');
        }
      }
      else if (input != '\r') {
        readLine_inputBuffer[readLine_nextPos] = input;
        readLine_nextPos++;
        if (readLine_nextPos >= INPUT_BUFFER_LENGTH) readLine_nextPos--;
        Serial.print(input);
      }
    }
    else if(!blocking) {
      return String('\n');
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
