#include <stdio.h>

#include "./lib/Splash/splash.c"
#include "./lib/parser/charmachine.c"
#include "./lib/parser/wordmachine.c"
#include "./lib/Simulator/simulator.c"
#include "./lib/Inventory/inventory.c"
#include "./lib/Delivery/delivery.c"
#include "./lib/priorityQueueDin/prioqueuedin.c"
#include "./lib/Peta/peta.c"
#include "./lib/ADT Matrix/matrix.c"
#include "./lib/ADT Point/point.c"
#include "./lib/Makanan/listMakanan.c"
#include "./lib/Makanan/makanan.c"
#include "./lib/Time/time.c"
// #include "./lib/Makanan/makanan.c"

void idle(Simulator S, Peta P, Time T, int* invenNotif, int* delivNotif){
    printf("\n\n\n");
    displayLokasi(S);
    displayTime(T);
    displayPeta(P);
    printf("\n");
    notifQ(invenNotif,true);
    notifQ(delivNotif,false);
    printf("\n");
    printf("Enter Command:  ");
    STARTWORD();
}

int main(){
    //SPLASH SCREEN
    splash();
    // START or EXIT
    printf("START/EXIT?\n");
    STARTWORD();
    // Membandingkan input pengguna dengan kata "START"
    boolean start = isWordStrEq(currentWord, "START");
    
    if (start) // Memulai program
    {
        Simulator S;
        Peta P;
        Time T;
        ListMakanan l;
        Inventory I;
        Delivery D;
        int* invNotif;
        int* delivNotif;
        printf("Masukkan nama pengguna: ");
        STARTWORD();
        CreateSimulator(&S, currentWord);
        readPeta(&P, "./config/peta.txt", &S);
        createTime(&T,0,0,0);
        BacaMakanan(&l, "./config/makanan.txt");
        createInventory(&I); //sementara inventory kosong
        createDelivery(&D);
        
        invNotif = listIdNotPos(I);
        delivNotif = listIdNotPos(D);

        while (start){
            idle(S,P,T,invNotif,delivNotif);
            if (isWordStrEq(currentWord,"MOVE")){
                Move(&P,&S,&T,&I,&D,&invNotif,&delivNotif);
            } else if(isWordStrEq(currentWord,"EXIT")){
                start=false;
            }
        }
    
    }

    return 0;
}