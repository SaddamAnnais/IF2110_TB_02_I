#include <stdio.h>
#include "inventory.h"

int main () {
    Inventory inv;

    createInventory(&inv);
    printf("%d\n", isEmptyQ(inv));

    return 0;
}