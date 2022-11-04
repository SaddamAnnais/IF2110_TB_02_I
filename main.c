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
#include "./lib/Command/command.c"
#include "./lib/Stack/stack.c"
#include "./lib/Resep/resep.c"
#include "./lib/Resep/tree.c"
#include "./lib/ListDinamis/listdin.c"

void idle(Simulator S, Peta P, Time T, int notif[2][100], ListMakanan lM,Inventory I,Delivery D, boolean alurMaju){
    printf("\n\n\n");
    displayLokasi(S);
    displayTime(T);
    displayPeta(P);
    printf("\n");
    // notifQ(invenNotif,true); //notif sementara
    // notifQ(delivNotif,false);
    displayNotif(notif, alurMaju, lM);
    matIdNotPos(notif,I,D);
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
    boolean start = isWordStrEq(currentWord, "START");
    if (start) // Memulai program
    {
        Simulator S; Time T; ListMakanan l; Peta P; Inventory I; 
        Delivery D; Stack UndoSt, RedoSt; ElTypeStack ElmtUndoRedo; Resep R;
        int notif[2][100];
        boolean isValid, alurMaju=true;
        printf("Masukkan nama pengguna: ");
        STARTWORD();
        CreateSimulator(&S, currentWord);
        readPeta(&P, "./config/peta.txt", &S);
        createTime(&T,0,0,0);
        BacaMakanan(&l, "./config/makanan.txt");
        createInventory(&I); //sementara inventory kosong
        createDelivery(&D);
        CreateStack(&UndoSt);
        CreateStack(&RedoSt);
        readResep(&R, "./config/resep.txt", l);

        matIdNotPos(notif,I,D);
        

        CreateElTypeStack(&ElmtUndoRedo,S, D, T, I, notif);
        PushStack(&UndoSt, ElmtUndoRedo);

        while (start){
            isValid = false;
            idle(S,P,T,notif,l,I,D,alurMaju);

            if (isWordStrEq(currentWord,"MOVE")){
                Move(&P,&S,&T,&I,&D,notif,&isValid,l);
            } else if (isWordStrEq(currentWord,"WAIT")){
                Wait(&T,&I,&D,notif,&isValid,l);
            } else if(isWordStrEq(currentWord,"EXIT")){
                start=false;
            } else if (isWordStrEq(currentWord,"BUY")){
                Buy(&P,&S,l,&D,&T,&I,notif,&isValid);
            } else if (isWordStrEq(currentWord, "CATALOG")){
                Catalog(l);
            } else if (isWordStrEq(currentWord, "DELIVERY")){
                PrintDelivery(l, D);
            } else if (isWordStrEq(currentWord, "INVENTORY")){
                PrintInventory(l, I);
            } else if (isWordStrEq(currentWord, "UNDO")) {
                undo(&UndoSt, &RedoSt, &P, &S, &D, &T, &I, &notif);
                alurMaju = false;
            } else if (isWordStrEq(currentWord, "REDO")) {
                redo(&UndoSt, &RedoSt, &P, &S, &D, &T, &I, &notif);
                alurMaju = true;
            } else if (isWordStrEq(currentWord, "FRY")) {
                PengolahanMakanan(currentWord, "Fry", l, &I, R, &T, &D, notif, P, S, &isValid);
            } else if (isWordStrEq(currentWord, "MIX")) {
                PengolahanMakanan(currentWord, "Mix", l, &I, R, &T, &D, notif, P, S, &isValid);
            } else if (isWordStrEq(currentWord, "CHOP")) {
                PengolahanMakanan(currentWord, "Chop", l, &I, R, &T, &D, notif, P, S, &isValid);
            } else if (isWordStrEq(currentWord, "BOIL")) {
                PengolahanMakanan(currentWord, "Boil", l, &I, R, &T, &D, notif, P, S, &isValid);
            } else if (isWordStrEq(currentWord, "COOKBOOK")) {
                displayCookbook(R);
            }
            
            if ((!isWordStrEq(currentWord, "UNDO")) && (!isWordStrEq(currentWord, "REDO") && isValid)) {   // Untuk keperluan undo dan redo
                CreateElTypeStack(&ElmtUndoRedo,S, D, T, I, notif);
                PushStack(&UndoSt, ElmtUndoRedo);
                CreateStack(&RedoSt);
                makeNotifMundur(&UndoSt);
                alurMaju = true;
            }
        }
    
    }

    return 0;
}