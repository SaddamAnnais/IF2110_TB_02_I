/* File: simulator.c */
/* Implementasi ADT Simulator */

#include <stdio.h>
#include "simulator.h"

/* ************ Prototype ************ */
/* *** KONSTRUKTOR *** */
void CreateSimulator(Simulator *S, Word nama){
/* I.S. Sembarang */
/* F.S. Sebuah Simulator dengan nama sesuai input terbentuk. */
/*      Lokasi Simulator di set sementara ke (-1,-1) */
/*      Inventory masih kosong */    
    Nama(*S) = nama;
    Lokasi(*S).x = -1;
    Lokasi(*S).y = -1;
    //Inventory(*S) = NULL; //CreateEmptyInventory
}

/* *** Kelompok Baca/Tulis *** */
void displayLokasi(Simulator S){
/* I.S. S terdefinisi */
/* F.S. Menampilkan lokasi Simulator ke layar */
    printf("BNMO di posisi: (%d,%d)\n", Lokasi(S).x, Lokasi(S).y);
}