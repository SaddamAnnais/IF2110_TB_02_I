#include "peta.h"

/* Konstruktor pembentuk peta */
void createPeta(Peta* p, int nRow, int nCol)
// I.S. nRow dan nCol merupakan ukuran peta yang valid
// F.S. Peta p berukuran nRow x nCol terdefinisi dengan batasan '*'
{
  /* KAMUS LOKAL */
  int i, j;

  /* ALGORITMA */
  createMatrix(nRow+2, nCol+2, &MATRIX(*p));
  for(i = 0; i < ROW_EFF(MATRIX(*p)); i++) {
    for(j = 0; j < COL_EFF(MATRIX(*p)); j++) {
      if(isBatas(*p, i, j)) {
        ELMT(MATRIX(*p), i, j) = '*';
      }
    }
  }
}

/* Membaca peta */
void readPeta(Peta* p);
// I.S. Peta p terdefinisi
// F.S. Peta p sesuai dengan konfigurasi

/* Menampilkan peta */
void displayPeta(Peta p)
// I.S. Peta p terdefinisi
// F.S. Peta p ditampilkan di layar
{
  /* KAMUS LOKAL */

  /* ALGORITMA */
  displayMatrix(MATRIX(p));
}

/* Menghasilkan true jika index i dan j merupakan batas pada peta */
boolean isBatas(Peta p, int i, int j)
{
  /* KAMUS LOKAL */

  /* ALGORITMA */
  return i == 0 || j == 0 || i == (ROW_EFF(MATRIX(p))+1) || j == (COL_EFF(MATRIX(p))+1);
}

/* Menggerakkan simulator ke arah utara */
void moveNorth(Peta* p);
// I.S. Simulator berada pada posisi (x, y)
// F.S. Jika pergerakan valid, simulator sekarang berada pada posisi (x, y-1)

/* Menggerakkan simulator ke arah timur */
void moveEast(Peta* p);
// I.S. Simulator berada pada posisi (x, y)
// F.S. Jika pergerakan valid, simulator sekarang berada pada posisi (x+1, y)

/* Menggerakkan simulator ke arah selatan */
void moveSouth(Peta* p);
// I.S. Simulator berada pada posisi (x, y)
// F.S. Jika pergerakan valid, simulator sekarang berada pada posisi (x, y+1)

/* Menggerakkan simulator ke arah barat */
void moveWest(Peta* p);
// I.S. Simulator berada pada posisi (x, y)
// F.S. Jika pergerakan valid, simulator sekarang berada pada posisi (x-1, y)