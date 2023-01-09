#ifndef NAHS_BRICKS_LIB_SERHELP_H
#define NAHS_BRICKS_LIB_SERHELP_H

#include <Arduino.h>

class NahsBricksLibSerHelp {
    private:
        static const byte INPUT_BUFFER_LENGTH = 32;
        char readLine_inputBuffer[INPUT_BUFFER_LENGTH];
        byte readLine_nextPos = 0;
    public:
        NahsBricksLibSerHelp();
        String readLine(bool blocking = true);
        void printBool(bool var);
        void printlnBool(bool var);
};

#if !defined(NO_GLOBAL_INSTANCES)
extern NahsBricksLibSerHelp SerHelp;
#endif

#endif // NAHS_BRICKS_LIB_SERHELP_H
