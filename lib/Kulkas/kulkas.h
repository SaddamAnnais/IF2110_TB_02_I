/* Definisi ADT Kulkas */
#ifndef KULKAS_H
#define KULKAS_H

#include "../ADT Matrix/matrix.h"
#include "../Time/time.h"
#include "../Inventory/inventory.h"
#include "../utility/boolean.h"

/* Isi Kulkas */
typedef struct isiKulkas
{
  int idMakanan;        // Id makanan yang terdapat di kulkas
  int waktuKadaluarsa;   // Sisa waktu kadaluarsa makanan sebelum disimpan di kulkas
} IsiKulkas;

/* ADT Kulkas */
typedef struct kulkas
{
  Matrix buffer;          // Matriks tempat menyimpan makanan
  IsiKulkas isi[100];     // List makanan yang ada di kulkas
} Kulkas;

/* KONSTRUKTOR, SELEKTOR, dan INPUT/OUTPUT */

/* Konstruktor pembentuk kulkas */
void createKulkas(Kulkas* kulkas);
// I.S. Kulkas sembarang
// F.S. Kulkas terdefinisi

/* Selektor */
#define K_ELMT(K, i, j) MATRIX_ELMT((K).buffer, i, j)   // Selektor elemen kulkas
#define K_MAKANAN(K, i) (K).isi[i].idMakanan              // Selektor makanan ke-i pada kulkas
#define K_KADALUARSA(K, i) (K).isi[i].waktuKadaluarsa   // Selektor sisa waktu makanan ke-i

/* Menampilkan kulkas ke layar */
void displayKulkas(Kulkas kulkas);
// I.S. Kulkas terdefinisi
// F.S. Makanan yang ada di kulkas ditampilkan di layar

/* OPERASI-OPERASI PADA KULKAS */

/* Menghasilkan true jika index pada kulkas dapat diisi dengan makanan berukuran p x l */
boolean isKulkasIdxValid(Kulkas kulkas, int b, int k, int p, int l);

/* Menambahkan makanan ke kulkas */
void insertToKulkas(Kulkas* kulkas, Inventory* inventory, int id, int b, int k, int p, int l);
// I.S. id merupakan id makanan yang terdapat pada inventory
// F.S. Makanan dihapus dari inventory dan ditambahkan ke kulkas

/* Mengeluarkan makanan dari kulkas */
void removeFromKulkas(Kulkas* kulkas, Inventory* inventory, char x);
// I.S. id merupakan id makanan yang terdapat pada kulkas
// F.S. Makanan dihapus dari kulkas dan ditambahkan ke inventory

#endif 