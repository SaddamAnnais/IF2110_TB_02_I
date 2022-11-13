#include "matrix.c"
#include <stdio.h>

int main() {
  // Inisialisasi program
  Matrix matriks;
  createMatrix(3, 3, &matriks);
  int i, j;
  for(i = 0; i < 3; i++) {
    for(j = 0; j < 3; j++) {
      MATRIX_ELMT(matriks, i, j) = (char) 'A'+i+j;
    }
  }

  // Menampilkan matrix
  displayMatrix(matriks);

  // Predikat dan operasi dasar pada matrix
  printf("isSquare: %d\n", isSquare(matriks));
  printf("isSymmetric: %d\n", isSymmetric(matriks));
  printf("countElmt: %d\n", countElmt(matriks));

  return 0;
}