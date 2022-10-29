/* Definisi ADT Peta */
#ifndef PETA_H
#define PETA_H

#include "../ADT Matrix/matrix.h"
#include "../ADT Point/point.h"
#include "../utility/boolean.h"
#include "../Simulator/simulator.h"

/* ADT Peta berupa matriks of char */
typedef Matrix Peta;

/* Konstruktor pembentuk peta */
void createPeta(Peta* p, int nRow, int nCol);
// I.S. nRow dan nCol merupakan ukuran peta yang valid
// F.S. Peta p berukuran nRow x nCol terdefinisi dengan batasan '*'

/* Membaca peta */
void readPeta(Peta* p, char* filename, Simulator* s);
// I.S. Peta p terdefinisi
// F.S. Peta p sesuai dengan konfigurasi

/* Menampilkan peta */
void displayPeta(Peta p);
// I.S. Peta p terdefinisi
// F.S. Peta p ditampilkan di layar

/* Operasi-operasi pada peta */

/* Menghasilkan true jika index i dan j merupakan batas pada peta */
boolean isBatas(Peta p, int i, int j);

/* Menghasilkan true jika koordinat i dan j merupakan koordinat yang valid untuk simulator */
boolean isCoordSimValid(Peta p, int i, int j);

/* Menggerakkan simulator ke arah utara */
void moveNorth(Peta* p, Simulator* s);
// I.S. Simulator berada pada posisi (x, y)
// F.S. Jika pergerakan valid, simulator sekarang berada pada posisi (x, y-1)

/* Menggerakkan simulator ke arah timur */
void moveEast(Peta* p, Simulator* s);
// I.S. Simulator berada pada posisi (x, y)
// F.S. Jika pergerakan valid, simulator sekarang berada pada posisi (x+1, y)

/* Menggerakkan simulator ke arah selatan */
void moveSouth(Peta* p, Simulator* s);
// I.S. Simulator berada pada posisi (x, y)
// F.S. Jika pergerakan valid, simulator sekarang berada pada posisi (x, y+1)

/* Menggerakkan simulator ke arah barat */
void moveWest(Peta* p, Simulator* s);
// I.S. Simulator berada pada posisi (x, y)
// F.S. Jika pergerakan valid, simulator sekarang berada pada posisi (x-1, y)

/* Menghasilkan true jika simulator berada di dekat x */
boolean isNear(Peta p, Simulator s, char x);

/* Menghasilkan true jika simulator berada di dekat telepon */
boolean isNearTelepon(Peta p, Simulator s);

/* Menghasilkan true jika simulator berada di dekat tempat mixing */
boolean isNearMixing(Peta p, Simulator s);

/* Menghasilkan true jika simulator berada di dekat tempat memotong */
boolean isNearMemotong(Peta p, Simulator s);

/* Menghasilkan true jika simulator berada di dekat tempat menggoreng */
boolean isNearMenggoreng(Peta p, Simulator s);

/* Menghasilkan true jika simulator berada di dekat tempat merebus */
boolean isNearMerebus(Peta p, Simulator s);


#endif