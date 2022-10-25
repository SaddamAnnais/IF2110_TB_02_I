/* File: driverSimulator.c */
/* Driver ADT Simulator */

#include <stdio.h>
#include "simulator.h"
#include "../parser/charmachine.c"
#include "../parser/wordmachine.c"

int main(){
    STARTWORD();
    Simulator S;
    CreateSimulator(&S,currentWord);
    displayLokasi(S);
}