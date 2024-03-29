/* Implementasi ADT Kulkas */
#include "kulkas.h"
#include <stdio.h>

/* IMPLEMENTASI KONSTRUKTOR dan INPUT/OUTPUT */

/* Konstruktor pembentuk kulkas */
void createKulkas(Kulkas* kulkas)
// I.S. Kulkas sembarang
// F.S. Kulkas terdefinisi
{
  /* KAMUS LOKAL */
  int i, j;

  /* ALGORITMA */
  createMatrix(12, 22, &((*kulkas).buffer));
  for(i = 0; i < 12; i++) {
    for(j = 0; j < 22; j++) {
      if(i == 0 || i == 11 || j == 0 || j == 21 ) {
        K_ELMT(*kulkas, i, j) = '*';
      } else {
        K_ELMT(*kulkas, i, j) = ' ';
      }
    }
  }
  for(i = 0; i < 100; i++) {
    K_MAKANAN(*kulkas, i) = -1;
    K_KADALUARSA(*kulkas, i) = -1;
  }
}

/* Menampilkan kulkas ke layar */
void displayKulkas(Kulkas kulkas)
// I.S. Kulkas terdefinisi
// F.S. Makanan yang ada di kulkas ditampilkan di layar
{
  /* KAMUS LOKAL */

  /* ALGORITMA */
  displayMatrix(kulkas.buffer);
}

/* IMPLEMENTASI OPERASI-OPERASI PADA KULKAS */

/* Menghasilkan true jika index pada kulkas dapat diisi dengan makanan berukuran p x l */
boolean isKulkasIdxValid(Kulkas kulkas, int b, int k, int p, int l)
{
  /* KAMUS LOKAL */
  int i, j;

  /* ALGORITMA */
  for(i = b; i < b+p; i++) {
    for(j = k; j < k+l; j++) {
      if(i < 1 || i > 10 || j < 1 || j > 20) {
        return false;
      } else if(MATRIX_ELMT(kulkas.buffer, i, j) != ' ') {
        return false;
      }
    }
  }
  return true;
}

/* Menambahkan makanan ke kulkas */
void insertToKulkas(Kulkas* kulkas, Inventory* inventory, int id, int b, int k, int p, int l)
// I.S. id merupakan id makanan yang terdapat pada inventory
// F.S. Makanan dihapus dari inventory dan ditambahkan ke kulkas
{
  /* KAMUS LOKAL */
  int i, j, time, idx;

  /* ALGORITMA */
  for(i = 0; i <= TailQ(*inventory); i++) {
    if(Id(ElmtQ(*inventory, i)) == id) {
      time = Time(ElmtQ(*inventory, i));
      break;
    }
  }

  for(i = 0; i < 100; i++) {
    if(K_MAKANAN(*kulkas, i) == -1) {
      idx = i;
      break;
    }
  }

  K_MAKANAN(*kulkas, idx) = id;
  K_KADALUARSA(*kulkas, idx) = time;
  for(i = b; i < b+p; i++) {
    for(j = k; j < k+l; j++) {
      K_ELMT(*kulkas, i, j) = (char) 'A' + idx;
    }
  }
  delIdFromQ(inventory, id);
}

/* Mengeluarkan makanan dari kulkas */
void removeFromKulkas(Kulkas* kulkas, Inventory* inventory, char x)
// I.S. id merupakan id makanan yang terdapat pada kulkas
// F.S. Makanan dihapus dari kulkas dan ditambahkan ke inventory
{
  /* KAMUS LOKAL */
  int i, j;
  infotype m;

  /* ALGORITMA */
  Time(m) = K_KADALUARSA(*kulkas, ((int) x) - ((int) 'A'));
  Id(m) = K_MAKANAN(*kulkas, ((int) x) - ((int) 'A'));
  enqueue(inventory, m);

  for(i = 1; i < 11; i++) {
    for(j = 1; j < 21; j++) {
      if(K_ELMT(*kulkas, i, j) == x) {
        K_ELMT(*kulkas, i, j) = ' ';
      }
    }
  }

  K_MAKANAN(*kulkas, ((int) x) - ((int) 'A')) = -1;
  K_KADALUARSA(*kulkas, ((int) x) - ((int) 'A')) = -1;
}
