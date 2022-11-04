
#include "stack.h"

int main() {
    ElTypeStack el1, el2, dump;
    Simulator s;
    Inventory inv;
    Delivery deliv;
    Time t;

    STARTWORD();

    Stack st;
    CreateStack(&st);
    printf("kosong? : %d\n", IsEmptyStack(st));
    printf("penuh? : %d\n", IsFullStack(st));
    printf("len : %d\n", lenStack(st));

    CreateSimulator(&s, currentWord);
    createInventory(&inv);
    createDelivery(&deliv);
    createTime(&t, 2, 2, 2);

    CreateElTypeStack(&el1, s, deliv, t, inv);
    CreateElTypeStack(&el2, s, deliv, t, inv);

    printWord(Nama(SIMULATOR_STACK(el1)));
    printf("\n");
    PushStack(&st, el1);
    printf("kosong? : %d\n", IsEmptyStack(st));
    printStack(st);
    printf("\nlen : %d\n", lenStack(st));
    PopStack(&st, &dump);
    printWord(Nama(SIMULATOR_STACK(dump)));
    printf("\n");    
    printf("kosong? : %d\n", IsEmptyStack(st));
    printf("len : %d\n", lenStack(st));    
    printStack(st);
    // PopStack(&st, &dump);
    // printf("kosong? : %d", IsEmptyStack(st));
}