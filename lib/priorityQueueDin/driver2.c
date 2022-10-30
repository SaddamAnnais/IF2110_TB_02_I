#include <stdio.h>
#include "prioqueuedin.c"

int main(){
    PrioQueueTime I, D;
    infotype val1, val2, val3, val4, val5;
    infotype dump;
    int *arr1, *arr2;
    setInfotypeQ(&val1, 20, 1);setInfotypeQ(&val2, 21, 2);
    setInfotypeQ(&val3, 22, 1);setInfotypeQ(&val4, 23, 3);
    setInfotypeQ(&val5, 19, 7);

    int notif[2][100];
    makeEmptyQ(&I,5);
    makeEmptyQ(&D,5);
    matIdNotPos(notif,I,D);
    enqueue(&I, val1);
    enqueue(&I, val2);
    enqueue(&I, val3);
    enqueue(&I, val4);
    enqueue(&D, val2);
    enqueue(&D, val3);
    enqueue(&D, val4);

    timePassQ(&I,2);
    printPrioQ(I);
    printPrioQ(D);
    matIdNotPos(notif,I,D);
    keepPosTimeQ(&I);
    keepPosTimeQ(&D);
    displayNotif(notif);

    timePassQ(&D,1);
    enqueue(&I, val5);
    printPrioQ(I);
    printPrioQ(D);
    matIdNotPos(notif,I,D);
    keepPosTimeQ(&I);
    keepPosTimeQ(&D);
    displayNotif(notif);



}