/* Definisi ADT Point */
#ifndef POINT_H
#define POINT_H

#include "../utility/boolean.h"

/* ADT Point dengan absis dan ordinat integer */
typedef struct point
{
  int x;    // Absis
  int y;    // Ordinat
} Point;

/* Konstruktor pembentuk point */
void createPoint(Point* p, int x, int y);
// I.S. x dan y merupakan absis dan ordinat
// F.S. Point p dengan absis x dan ordinat y terbentuk

/* Selektor */
#define ABSIS(p) (p).x      // Absis dari point
#define ORDINAT(p) (p).y    // Ordinat dari point

/* Menampilkan point pada layar */
void displayPoint(Point p);
// I.S. Point p terdefinisi
// F.S. Point p ditampilkan di layar dengan format (x,y)

/* Operasi-operasi pada point */

/* Menghasilkan true jika point p1 = p2 */
boolean isEqual(Point p1, Point p2);

/* Menghasilkan true jika point p merupakan titik (0,0) */
boolean isOrigin(Point p);

/* Menghasilkan true jika point p berada pada sumbu x */
boolean isOnSumbuX(Point p);

/* Menghasilkan true jika point p berada pada sumbu y */
boolean isOnSumbuY(Point p);

/* Menghasilkan kuadran dari point p */
/* (Menghasilkan -1 jika point p berada di sumbu koordinat) */
int kuadran(Point p);

/* Menghitung panjang garis yang dibentuk oleh p1 dan p2 */
float panjang(Point p1, Point p2);

/* Menghasilkan point baru (x+deltaX,y+deltaY) dari point awal (x,y) */
Point plusDelta(Point p, int deltaX, int deltaY);

#endif