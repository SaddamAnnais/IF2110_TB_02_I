#include "point.h"
#include <math.h>
#include <stdio.h>

/* Konstruktor pembentuk point */
void createPoint(Point* p, int x, int y)
// I.S. x dan y merupakan absis dan ordinat
// F.S. Point p dengan absis x dan ordinat y terbentuk
{
  /* KAMUS LOKAL */

  /* ALGORITMA */
  ABSIS(*p) = x;
  ORDINAT(*p) = y;
}

/* Menampilkan point pada layar */
void displayPoint(Point p)
// I.S. Point p terdefinisi
// F.S. Point p ditampilkan di layar dengan format (x,y)
{
  /* KAMUS LOKAL */

  /* ALGORITMA */
  printf("(%d,%d)", ORDINAT(p), ABSIS(p));
}

/* Operasi-operasi pada point */

/* Menghasilkan true jika point p1 = p2 */
boolean isEqual(Point p1, Point p2)
{
  /* KAMUS LOKAL */

  /* ALGORITMA */
  return ABSIS(p1) == ABSIS(p2) && ORDINAT(p1) == ORDINAT(p2);
}

/* Menghasilkan true jika point p merupakan titik (0,0) */
boolean isOrigin(Point p)
{
  /* KAMUS LOKAL */

  /* ALGORITMA */
  return ABSIS(p) == 0 && ORDINAT(p) == 0;
}

/* Menghasilkan true jika point p berada pada sumbu x */
boolean isOnSumbuX(Point p)
{
  /* KAMUS LOKAL */

  /* ALGORITMA */
  return ORDINAT(p) == 0;
}

/* Menghasilkan true jika point p berada pada sumbu y */
boolean isOnSumbuY(Point p)
{
  /* KAMUS LOKAL */

  /* ALGORITMA */
  return ABSIS(p) == 0;
}

/* Menghasilkan kuadran dari point p */
/* (Menghasilkan -1 jika point p berada di sumbu koordinat) */
int kuadran(Point p)
{
  /* KAMUS LOKAL */

  /* ALGORITMA */
  if(ABSIS(p) > 0 && ORDINAT(p) > 0) {
    return 1;
  } else if(ABSIS(p) < 0 && ORDINAT(p) > 0) {
    return 2;
  } else if(ABSIS(p) < 0 && ORDINAT(p) < 0) {
    return 3;
  } else if(ABSIS(p) > 0 && ORDINAT(p) < 0) {
    return 4;
  } else {
    return -1;
  }
}

/* Menghitung panjang garis yang dibentuk oleh p1 dan p2 */
float panjang(Point p1, Point p2)
{
  /* KAMUS LOKAL */

  /* ALGORITMA */
  return (float)sqrt((ABSIS(p1) - ABSIS(p2)) * ((ABSIS(p1) - ABSIS(p2))) + (ORDINAT(p1) - ORDINAT(p2)) * ((ORDINAT(p1) - ORDINAT(p2))));
}

/* Menghasilkan point baru (x+deltaX,y+deltaY) dari point awal (x,y) */
Point plusDelta(Point p, int deltaX, int deltaY)
{
  /* KAMUS LOKAL */
  Point pOut;

  /* ALGORITMA */
  createPoint(&pOut, ABSIS(p)+deltaX, ORDINAT(p)+deltaY);
  return pOut;
}
