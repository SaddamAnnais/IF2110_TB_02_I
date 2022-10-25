#include <stdio.h>
#include "prioqueuedin.h"

int main () {
    PrioQueueTime q, q1;
    infotype val1, val2, val3, val4, val5;
    infotype dump;
    setInfotype(&val1, 20, 1);setInfotype(&val2, 21, 2);
    setInfotype(&val3, 22, 1);setInfotype(&val4, 23, 3);
    setInfotype(&val5, 19, 7);

    int nEl = 3;

    makeEmpty(&q, nEl);
    printf("Kosong?: %d\n", isEmpty(q));

    //printPrioQueue(q);
    for (int i = 0; i<5; i++) {
        enqueue(&q, val1);
        enqueue(&q, val2);
        enqueue(&q, val3);
        enqueue(&q, val4);
    }
    printPrioQueue(q);
    printf("%d\n", MaxEl(q));
    printf("%d\n", NBElmt(q));
    printf("%d\n", isIdInQ(q, 21));
    
    for (int i = 0; i<10; i++) {
        dequeue(&q, &dump);
    }

    printf("%d\n", MaxEl(q));
    printf("%d\n", NBElmt(q));

    enqueue(&q, val5);
    printPrioQueue(q);
    delIdFromQ(&q, 19);
    printPrioQueue(q);
}