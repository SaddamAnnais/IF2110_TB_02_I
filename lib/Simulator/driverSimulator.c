/* File: driverSimulator.c */
/* Driver ADT Simulator */

#include <stdio.h>
#include "simulator.h"
#include "../parser/wordmachine.h"

int main(){
    STARTWORD();
    Simulator S;
    CreateSimulator(&S,currentWord);
    displayLokasi(S);
}