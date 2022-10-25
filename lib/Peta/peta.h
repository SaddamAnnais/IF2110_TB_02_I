/* Definisi ADT Peta */
#ifndef PETA_H
#define PETA_H

#include "matrix.h"
#include "point.h"
#include "boolean.h"

/* ADT Peta berupa matriks of char */
typedef struct peta 
{
  Matrix mem;     // Matrix tempat menyimpan peta
  Point posisi;   // Posisi simulator yang sekarang
} Peta;

/* Konstruktor pembentuk peta */
void createPeta(Peta* p, int nRow, int nCol);
// I.S. nRow dan nCol merupakan ukuran peta yang valid
// F.S. Peta p berukuran nRow x nCol terdefinisi dengan batasan '*'

/* Selektor */
#define MATRIX(p) (p).mem       // Matrix tempat menyimpan peta
#define POSISI(p) (p).posisi    // Posisi simulator yang sekarang

/* Membaca peta */
void readPeta(Peta* p);
// I.S. Peta p terdefinisi
// F.S. Peta p sesuai dengan konfigurasi

/* Menampilkan peta */
void displayPeta(Peta p);
// I.S. Peta p terdefinisi
// F.S. Peta p ditampilkan di layar

/* Menghasilkan true jika index i dan j merupakan batas pada peta */
boolean isBatas(Peta p, int i, int j);

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

#endif