/* Definisi ADT Rekomendasi Makanan */
#ifndef REKOMENDASI_H
#define REKOMENDASI_H

#include "set.h"
#include "../Resep/resep.h"
#include "../Inventory/inventory.h"
#include "../Makanan/makanan.h"
#include "../Makanan/listmakanan.h"

/* ADT list statik untuk menyimpan set dari setiap makanan */
typedef struct setResep
{
  Set buffer[RESEP_CAPACITY];   // Array tempat menyimpan set
} SetResep;

/* KONSTRUKTOR, SELEKTOR, dan INPUT/OUTPUT */

/* Konstruktor pembentuk set resep */
void createSetResep(SetResep* setResep, Resep resep);
// I.S. setResep sembarang
// F.S. setResep terdefinisi

/* OPERASI-OPERASI REKOMENDASI MAKANAN  */

/* Melakukan union terhadap setiap resep makanan */
void unionResep(SetResep* setResep);
// I.S. setResep terdefinisi
// F.S. setResep berisi resep-resep yang hanya terdiri dari bahan-bahan dasar

/* Menampilkan rekomendasi makanan berdasarkan bahan pada inventory */
void rekomendasi(SetResep setResep, Inventory inventory, ListMakanan listMakanan);
// I.S. inventory dan setResep terdefinisi
// F.S. Makanan yang dapat dibuat oleh bahan-bahan pada inventory ditampilkan di layar

#endif