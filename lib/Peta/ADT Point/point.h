/* Definisi ADT Point */
#ifndef POINT_H
#define POINT_H

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
#define ORDINAT(y) (p).y    // Ordinat dari point

#endif