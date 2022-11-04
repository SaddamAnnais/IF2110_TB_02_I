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
//#include "./lib/Stack/stack_notif.c"

void idle(Simulator S, Peta P, Time T, int notif[2][100], ListMakanan lM, boolean alurMaju){
    printf("\n\n\n");
    displayLokasi(S);
    displayTime(T);
    displayPeta(P);
    printf("\n");
    // notifQ(invenNotif,true); //notif sementara
    // notifQ(delivNotif,false);
    displayNotif(notif, alurMaju, lM);
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
    

    //CreateStack(&UndoSt);

    //CreateStack(&UndoSt, &RedoSt);
    
    if (start) // Memulai program
    {
        Simulator S; Time T; ListMakanan l; Peta P; Inventory I; 
        Delivery D; Stack UndoSt, RedoSt; ElTypeStack ElmtUndoRedo;
        int* invNotif; int* delivNotif;
        Notif notif; boolean alurMaju = true;
        printf("Masukkan nama pengguna: ");
        STARTWORD();
        readPeta(&P, "./config/peta.txt", &S); BacaMakanan(&l, "./config/makanan.txt");
        CreateSimulator(&S, currentWord);createTime(&T,0,0,0);createInventory(&I);
        createDelivery(&D);CreateStack(&UndoSt); CreateStack(&RedoSt);
        matIdNotPos(notif,I,D);
        

        CreateElTypeStack(&ElmtUndoRedo,S, D, T, I, notif);
        PushStack(&UndoSt, ElmtUndoRedo);

        while (start){
            idle(S,P,T,notif,l,alurMaju);

            if (isWordStrEq(currentWord,"MOVE")){
                Move(&P,&S,&T,&I,&D,notif);
            } else if (isWordStrEq(currentWord,"WAIT")){
                Wait(&T,&I,&D,notif);
            } else if(isWordStrEq(currentWord,"EXIT")){
                start=false;
            } else if (isWordStrEq(currentWord,"BUY")){
                Buy(&P,&S,l,&D,&T,&I,notif);
            } else if (isWordStrEq(currentWord, "CATALOG")){
                Catalog(l);
            } else if (isWordStrEq(currentWord, "DELIVERY")){
                PrintDelivery(l, D);
            } else if (isWordStrEq(currentWord, "INVENTORY")){
                PrintInventory(l, I);
            } else if (isWordStrEq(currentWord, "UNDO")) {
                undo(&UndoSt, &RedoSt, &P, &S, &D, &T, &I, &notif);
                alurMaju = false;
                // printf("id: %d", notif[1][0]);
            } else if (isWordStrEq(currentWord, "REDO")) {
                redo(&UndoSt, &RedoSt, &P, &S, &D, &T, &I, &notif);
                alurMaju = true;
            }
            

            if ((!isWordStrEq(currentWord, "UNDO")) && (!isWordStrEq(currentWord, "REDO"))) {   // Untuk keperluan undo dan redo
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