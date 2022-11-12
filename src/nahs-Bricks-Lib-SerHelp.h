#ifndef NAHS_BRICKS_LIB_SERHELP_H
#define NAHS_BRICKS_LIB_SERHELP_H

#include <Arduino.h>

class NahsBricksLibSerHelp {
    private:

    public:
        NahsBricksLibSerHelp();
        String readLine();
        void printBool(bool var);
        void printlnBool(bool var);
};

#if !defined(NO_GLOBAL_INSTANCES)
extern NahsBricksLibSerHelp SerHelp;
#endif

#endif // NAHS_BRICKS_LIB_SERHELP_H
