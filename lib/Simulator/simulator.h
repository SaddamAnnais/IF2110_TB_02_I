/* File: simulator.h */
/* Definisi ADT Simulator */

#ifndef simulator_H
#define simulator_H

#include "../ADT Point/point.h"
#include "../parser/wordmachine.h"

typedef struct {
    Word namaPengguna; /* nama pengguna Simulator */
    Point Lokasi; /* lokasi Simulator di peta saat ini */
    //Inventory I; /* inventory makanan yang disimpan */
} Simulator;

/* Definisi akses dengan Selektor : Set dan Get */
#define Nama(S) (S).namaPengguna
#define Lokasi(S) (S).Lokasi
//#define Inventory(S) (S).I

/* ************ Prototype ************ */
/* *** KONSTRUKTOR *** */
void CreateSimulator(Simulator *S, Word nama);
/* I.S. Sembarang */
/* F.S. Sebuah Simulator dengan nama sesuai input terbentuk. */
/*      Lokasi Simulator di set sementara ke (-1,-1) */
/*      Inventory masih kosong */

/* *** Kelompok Baca/Tulis *** */
void displayLokasi(Simulator S);
/* I.S. S terdefinisi */
/* F.S. Menampilkan lokasi Simulator ke layar */

#endif