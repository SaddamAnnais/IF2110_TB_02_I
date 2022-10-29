/* Definisi ADT Resep dengan implementasi list statik untuk menyimpan root dari tree */
#ifndef RESEP_H
#define RESEP_H

#include "tree.h"

#define CAPACITY 100    // Kapasitas maksimum dari list resep

typedef address resepElType;    // Elemen dari list resep
/* ADT Resep */
typedef struct resep
{
  resepElType contents[CAPACITY];   // List statik tempat menyimpan resep
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
void readResep(Resep* r, char* filepath);
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

// Melakukan operasi mix makanan
void mix();


/* Menampil*/

#endif