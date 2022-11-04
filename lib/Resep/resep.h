/* Definisi ADT Resep dengan implementasi list statik */
#ifndef RESEP_H
#define RESEP_H

#include "tree.h"
#include "../Inventory/inventory.h"
#include "../Peta/peta.h"
#include "../parser/wordmachine.h"
#include "../Makanan/listmakanan.h"

#define RESEP_CAPACITY 100    // Kapasitas maksimum dari list resep

typedef address resepElType;    // Elemen dari list resep

/* ADT Resep dengan implementasi list statik */
typedef struct resep
{
  resepElType contents[RESEP_CAPACITY];   // List statik tempat menyimpan resep
  int nResep;                             // Jumlah elemen pada list resep
} Resep;

/* KONSTRUKTOR, SELEKTOR, dan INPUT/OUTPUT */

/* Konstruktor pembentuk resep */
void createResep(Resep* resep);
// I.S. List resep sembarang
// F.S. List resep terdefinisi

/* Selektor */
#define R_ELMT(R, i) (R).contents[i]   // Selektor elemen resep ke-i
#define N_RESEP(R) (R).nResep          // Selektor jumlah elemen pada list resep

/* Membaca resep dari file konfigurasi */
void readResep(Resep* resep, char* filepath, ListMakanan listMakanan);
// I.S. File konfigurasi valid dan list resep sembarang
// F.S. List resep terbentuk sesuai dengan file konfigurasi

/* Menampilkan seluruh resep ke layar dengan command COOKBOOK */
void displayCookbook(Resep resep);
// I.S. Resep terdefinisi
// F.S. Seluruh resep ditampilkan di layar sesuai format pada spesifikasi

/* Menampilkan sebuah node resep ke layar */
void displayResep(address node);
// I.S. Sebuah node resep terdefinisi
// F.S. Sebuah node resep ditampilkan di layar sesuai format pada spesifikasi

/* OPERASI-OPERASI PADA RESEP */

/* Menghasilkan data makanan berdasarkan id */
Makanan searchMakananById(ListMakanan listMakanan, int id);

/* Menghasilkan bahan makanan untuk membuat sebuah makanan */
ListDin bahanMakanan(Resep resep, int id);

/* Menampilkan daftar makanan yang dapat dibuat oleh sebuah operasi pengolahan makanan */
ListMakanan displayOperasiMakanan(ListMakanan listMakanan, char* operasi);
// I.S. Operasi merupakan operasi pengolahan makanan yang valid
// F.S. Semua makanan yang dapat dibuat dari operasi tersebut ditampilkan di layar
//      sesuai format pada spesifikasi

/* Melakukan operasi pengolahan makanan */
boolean olahMakanan(Makanan makanan, Inventory* inventory, Resep resep);
// I.S. Makanan merupakan makanan yang ingin dibuat
// F.S. Jika bahan makanan tersedia pada inventory, makanan hasil pengolahan ditambahkan
//      ke dalam inventory dan bahan makanan dihilangkan dari inventory

#endif
