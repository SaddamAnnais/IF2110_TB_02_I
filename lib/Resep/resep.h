/* Definisi ADT Resep dengan implementasi list statik untuk menyimpan root dari tree */
#ifndef RESEP_H
#define RESEP_H

#include "tree.h"
#include "../Inventory/inventory.h"
#include "../Peta/peta.h"
#include "../parser/wordmachine.h"
#include "../Makanan/listmakanan.h"

#define RESEP_CAPACITY 100    // Kapasitas maksimum dari list resep

typedef address resepElType;    // Elemen dari list resep
/* ADT Resep */
typedef struct resep
{
  resepElType contents[RESEP_CAPACITY];   // List statik tempat menyimpan resep
  int nResep;   // Jumlah elemen pada list resep
} Resep;

/* Konstruktor pembentuk resep */
void createResep(Resep* r);
// I.S. Resep sembarang
// F.S. Resep terdefinisi

/* Selektor */
#define RELMT(R, i) (R).contents[i]   // Elemen resep ke-i
#define NRESEP(R) (R).nResep    // Jumlah elemen pada list resep

/* Membaca resep dari file konfigurasi */
void readResep(Resep* r, char* filepath, ListMakanan l);
// I.S. File konfigurasi valid dan resep r sembarang
// F.S. Resep r terbentuk sesuai dengan file konfigurasi 

/* Menampilkan seluruh resep ke layar */
void displayCookbook(Resep r);
// I.S. Resep terdefinisi
// F.S. Seluruh resep ditampilkan di layar

/* Menampilkan sebuah node resep ke layar */
void displayResep(address p);
// I.S. Node p terdefinisi
// F.S. Node p ditampilkan di layar dengan semua childnya

/* Operasi-operasi pada resep */

// Menghasilkan data makanan berdasarkan id
Makanan searchMakanan(ListMakanan l, int id);

// Melakukan operasi pengolahan makanan
void olahMakanan(Makanan m, Inventory* i, char o);
// I.S. o merupakan operasi yang akan dilakukan
// F.S. Jika berhasil, bahan makanan diubah menjadi makanan baru pada inventory

// Melakukan operasi mix makanan
void mix(Makanan m, Inventory* i);

// Melakukan operasi chop makanan
void chop(Makanan m, Inventory* i);

// Melakukan operasi fry makanan
void fry(Makanan m, Inventory* i);

// Melakuka operasi boil makanan
void boil(Makanan m, Inventory* i);

#endif