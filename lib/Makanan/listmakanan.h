#ifndef LISTMAKANAN_H
#define LISTMAKANAN_H

#include "../utility/boolean.h"
#include "makanan.h"

/*  Kamus Umum */
#define CAPACITY_LIST_MAKANAN 100
/* Kapasitas penyimpanan */
#define IDX_MIN 0
/* Indeks minimum list */
#define IDX_UNDEF -1
/* Indeks tak terdefinisi*/

/* Definisi elemen dan koleksi objek */
typedef Makanan ElTypeList;  /* type elemen List */
typedef int IdxType;
typedef struct {
   ElTypeList contents[CAPACITY_LIST_MAKANAN]; /* memori tempat penyimpan elemen (container) */
   int len;
} ListMakanan;


/* Definisi : 
   List kosong: len = 0 */

/* ********** SELEKTOR ********** */
#define ElmtListMakanan(l, i) (l).contents[(i)]
#define lenListMakanan(l) (l).len

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create List kosong  */
void CreateListMakanan(ListMakanan *l);
/* I.S. l sembarang */
/* F.S. Terbentuk List l kosong dengan kapasitas CAPACITY */
/* Proses: Inisialisasi semua elemen List l dengan MARK */  

void BacaMakanan(ListMakanan *l, char *filename);
/* Membaca ID, lokasi aksi, serta waktu kadaluarsa
   dan membentuk Makanan M berdasarkan nilai tersebut */
/* Semua komponen ditulis dalam 1 baris, dipisahkan 1 spasi */
/* I.S. : M sembarang */
/* F.S. : M terdefinisi */

void printListMakanan(ListMakanan l);
/* I.S.  */
/* F.S. */
/* Contoh :  */
#endif

