#include <stdio.h>
#include "delivery.h"

int main () {
    Delivery d;

    createDelivery(&d);
    printf("%d\n", isEmptyQ(d));

    return 0;
}