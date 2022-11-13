#include "point.c"
#include <stdio.h>

int main() {
  // Inisialisasi program
  Point p1, p2, p3;
  createPoint(&p1, 3, 0);
  createPoint(&p2, 2, 4);

  // Menampilkan point
  printf("P1: ");
  displayPoint(p1);
  printf("\nP2: ");
  displayPoint(p2);

  // Predikat dan Operasi dasar pada point
  printf("\nisOnSumbuX: %d\n", isOnSumbuX(p1));
  printf("isOnSumbuY: %d\n", isOnSumbuY(p1));
  printf("Kuadran: %d\n", kuadran(p2));
  printf("Panjang: %.2f\n", panjang(p1, p2));

  return 0;
}