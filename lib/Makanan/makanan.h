/* ADT Makanan*/

#ifndef MAKANAN_H
#define MAKANAN_H

#include "../utility/boolean.h"
#include "../Time/time.h"
#include "../parser/wordmachine.h"
#include <stdio.h>

#define UNDEF_TIME -1
#define UNDEF_ID -1

typedef struct {
    int id_makanan;         // durasi makanan
    Word nama_makanan;      // nama makanan
    Word aksi_makanan;      // aksi makanan
    Time waktu_kadaluarsa;  // durasi kadaluwarsa
    Time lama_pengiriman;   // durasi pengiriman
    int durasi_aksi;        // durasi aksi
} Makanan;

/*SELEKTOR*/
#define ID(x) (x).id_makanan
#define NAMA_MAKANAN(x) (x).nama_makanan
#define WAKTU_KADALUARSA(x) (x).waktu_kadaluarsa
#define AKSI_MAKANAN(x) (x).aksi_makanan
#define LAMA_PENGIRIMAN(x) (x).lama_pengiriman
#define DURASI_AKSI(x) (x).durasi_aksi

//#define BUY_MAKANAN(x) (x).buy
//#define FRY_MAKANAN(x) (x).fry

/*KONSTRUKTOR*/
Makanan CreateMakanan(int id, Word nama, Word aksi, Time kadaluarsa, Time pengiriman, int durasi_aksi);
/* Membentuk sebuah Makanan dari komponen-komponennya */

void DisplayMakanan(Makanan M);
/* I.S. : M terdefinisi */
/* F.S. : M tertulis di layar sesuai dengan format */

#endif
