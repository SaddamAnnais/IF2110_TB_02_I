/* ADT Makanan*/

#ifndef MAKANAN_H
#define MAKANAN_H

#include "../utility/boolean.h"
#include "../Time/time.h"
#include "../parser/wordmachine.h"
#include "../ListStatik/liststatik.h"
//#include "../lokasi.h" (yg ini tgg nanti file lokasinya jadi)
#include <stdio.h>

#define UNDEF_TIME -1
#define UNDEF_ID -1

typedef struct makanan {
    int id_makanan;
    Word nama_makanan;
    TIME waktu_kadaluarsa;
    Lokasi aksi_akanan;
    int lama_pengiriman;
} Makanan;

/*SELEKTOR*/
#define ID(x) (x).id_makanan
#define NAMA_MAKANAN(x) (x).nama_makanan;
#define WAKTU_KADALUARSA(x) (x).waktu_kadaluarsa;
#define AKSI_MAKANAN(x) (x).aksi_makanan
#define LAMA_PENGIRIMAN(x) (x).lama_pengiriman

//#define BUY_MAKANAN(x) (x).buy
//#define FRY_MAKANAN(x) (x).fry

/*KONSTRUKTOR*/
Makanan CreateMakanan(int id, Word nama, Lokasi aksi, TIME kadaluarsa, int pengiriman);
/* Membentuk sebuah Makanan dari komponen-komponennya */


/* BACA/TULIS */
void BacaMakanan(Makanan *M);
/* Membaca ID, lokasi aksi, serta waktu kadaluarsa
   dan membentuk Makanan M berdasarkan nilai tersebut */
/* Semua komponen ditulis dalam 1 baris, dipisahkan 1 spasi */
/* I.S. : M sembarang */
/* F.S. : M terdefinisi */

void DisplayMakanan(Makanan M);
/* I.S. : M terdefinisi */
/* F.S. : M tertulis di layar sesuai dengan format */

#endif
