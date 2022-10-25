#include <stdio.h>
#include "prioqueuedin.h"

int main () {
    PrioQueueTime q, q1;
    infotype val1, val2, val3, val4, val5;
    infotype dump;
    int *arr1, *arr2;
    setInfotypeQ(&val1, 20, 1);setInfotypeQ(&val2, 21, 2);
    setInfotypeQ(&val3, 22, 1);setInfotypeQ(&val4, 23, 3);
    setInfotypeQ(&val5, 19, 7);

    int nEl = 3;

    makeEmptyQ(&q, nEl);
    printf("Kosong?: %d\n", isEmptyQ(q));

    //printPrioQueue(q);
    for (int i = 0; i<5; i++) {
        enqueue(&q, val1);
        enqueue(&q, val2);
        enqueue(&q, val3);
        enqueue(&q, val4);
    }
    printPrioQ(q);
    printf("%d\n", MaxElQ(q));
    printf("%d\n", NBElmtQ(q));
    printf("%d\n", isIdInQ(q, 21));
    
    for (int i = 0; i<4; i++) {
        dequeue(&q, &dump);
    }

    printf("%d\n", MaxElQ(q));
    printf("%d\n", NBElmtQ(q));

    enqueue(&q, val5);
    printPrioQ(q);
    delIdFromQ(&q, 19);
    printPrioQ(q);

    timePassQ(&q, 2);
    printPrioQ(q);

    arr1 = listIdNotPos(q);
    keepPosTimeQ(&q);
    printPrioQ(q);

    for (int i = 0; (i < 100) && arr1[i]!=Nil; i++)
    {
        printf("%d;", arr1[i]);
    }
    printf("\n");

    notifQ(arr1, true);
    notifQ(arr1, false);

    makeEmptyQ(&q1, nEl);
    enqueue(&q1, val1);
    arr2 = listIdNotPos(q1); 
    keepPosTimeQ(&q1);
    notifQ(arr2, true);
}