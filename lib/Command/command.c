#include "command.h"
#include <stdio.h>

/* T maju, elemen waktu pada Inventory I dan Delivery D berkurang*/
void timePass(int mm, Time *T, Inventory *I, Delivery *D, int* *invNotif, int* *delivNotif){
// I.S mm,T,I,D,invNotif,delivNotif terdefinisi
// F.S T maju sebanyak mm menit, elemen waktu pada Inventory I dan Delivery D berkurang sebanyak mm menit, dan elemen time yang <0 dihapus 
    incNMinute(T,mm);
    timePassQ(I,mm);
    timePassQ(D,mm);
    *invNotif = listIdNotPos(*I);
    *delivNotif = listIdNotPos(*D);
    keepPosTimeQ(I);
    keepPosTimeQ(D);
}

// Memajukan time sebanyak input pengguna
void Wait(Time *T, Inventory *I, Delivery *D, int* *invNotif, int* *delivNotif){
// I.S mm,T,I,D,invNotif,delivNotif terdefinisi
// F.S T, I, D, invNotif, delivNotif berubah sesuai timePass()
    int hh, mm;
    STARTWORD();
    hh = wordToInt(currentWord);
    STARTWORD();
    mm = wordToInt(currentWord);

    mm += hh*60;
    timePass(mm,T,I,D,invNotif,delivNotif);
}

/* Menggerakan simulator sesuai input user, jika simulator berpindah posisi, waktu bertambah 1 menit*/
void Move(Peta *p, Simulator *s,Time *T, Inventory *I, Delivery *D, int* *invNotif, int* *delivNotif){
// I.S. Simulator berada pada posisi (x, y)
// F.S. Jika pergerakan valid, simulator sekarang berada pada posisi baru dan semua elemen waktu maju
    STARTWORD();
    Point p0 = Lokasi(*s);

    if (isWordStrEq(currentWord,"NORTH")){
       moveNorth(p,s);
    } else if (isWordStrEq(currentWord,"WEST")){
       moveWest(p,s);
    } else if (isWordStrEq(currentWord,"SOUTH")){
       moveSouth(p,s);
    } else if (isWordStrEq(currentWord,"EAST")){
       moveEast(p,s);
    } else {
       printf("Input invalid\n");
    }

    Point pt = Lokasi(*s);
    if (!isEqual(p0,pt)){ //pergerakan valid
        timePass(1,T,I,D,invNotif,delivNotif);//waktu berjalan 1 menit
    }
}

/* Menampilkan bahan makanan yang tersedia dalam aplikasi dan informasinya*/
void Catalog(ListMakanan lM){
    printf("List Makanan\n");
    printf("(nama - durasi kedaluwarsa - aksi yang diperlukan - delivery time - durasi aksi)\n");

    for (int i=0; i<lM.len; i++){
        DisplayMakanan(lM.contents[i]);
        printf("\n");
    }
}

/*UNDO REDO*/
void undo(Stack *UndoSt, Stack *RedoSt, ElTypeStack *X, Peta *P, Simulator *S, Delivery *D, Time *T, Inventory *I)
/*Membatalkan command yang dilakukan dan mengembalikan*/
/*state aplikasi sebelum command tersebut*/
{
    if (!IsEmptyStack(*UndoSt)) {
        // *X = TOP_STACK(*UndoSt); buat pertama doang
        // PushStack(RedoSt, *X);

        PushStack(RedoSt, *X);
        PopStack(UndoSt, X);

        *S = SIMULATOR_STACK(*X);
        *D = DELIVERY_STACK(*X);
        *T = TIME_STACK(*X);
        *I = INVENTORY_STACK(*X);
        setPetaFromSimulator(P, *S);

        // PushStack(RedoSt, *X);

    } 
    else {
        printf("Tidak bisa undo\n");
        // *P = *P;
        // *S = *S;
        // *D = *D;
        // *T = *T;
        // *I = *I;

    }
}

void redo(Stack *UndoSt, Stack *RedoSt, ElTypeStack *X, Peta *P, Simulator *S, Delivery *D, Time *T, Inventory *I)
/*Membatalkan command undo pada Stack S*/
{
    if (!IsEmptyStack(*RedoSt)) {
        // *X = TOP_STACK(*RedoSt);     buat pertama doang
        // PushStack(UndoSt, *X);
        
        PushStack(UndoSt, *X);   
        PopStack(RedoSt, X);

        *S = SIMULATOR_STACK(*X);
        *D = DELIVERY_STACK(*X);
        *T = TIME_STACK(*X);
        *I = INVENTORY_STACK(*X);
        setPetaFromSimulator(P, *S);

        //PushStack(UndoSt, *X);
    } 
    else {
        printf("Tidak bisa redo\n");
    }    
}