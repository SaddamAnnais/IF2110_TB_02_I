#include "matrix.h"
#include <stdio.h>

/* Konstruktor pembentuk matriks */
void createMatrix(int nRow, int nCol, Matrix* m)
// I.S. nRow dan nCol merupakan jumlah baris dan kolom yang valid untuk matriks
// F.S. Matriks m berukuran nRow x nCol terbentuk
{
  /* KAMUS LOKAL */

  /* ALGORITMA */
  ROW_EFF(*m) = nRow;
  COL_EFF(*m) = nCol;
}

/* Menampilkan matrix ke layar */
void displayMatrix(Matrix m)
// I.S. m terdefinisi
// F.S. Elemen-elemen dari m ditampilkan di layar
{
  /* KAMUS LOKAL */
  IdxType i, j;

  /* ALGORITMA */
  for(i = 0; i < ROW_EFF(m); i++) {
    for(j = 0; j < COL_EFF(m); j++) {
      printf("%c ", MATRIX_ELMT(m, i, j));
    }
    printf("\n");
  }
}

/* Operasi-operasi pada matriks */

/* Menghasilkan true jika i dan j merupakan indeks yang valid untuk sebuah matriks */
boolean isMatrixIdxValid(IdxType i, IdxType j)
{
  /* KAMUS LOKAL */

  /* ALGORITMA */
  return i >= 0 && i < 100 && j >= 0 && j < 100;
}

/* Menghasilkan true jika i dan j merupakan indeks efektif untuk matriks m */
boolean isMatrixIdxEff(Matrix m, IdxType i, IdxType j)
{
  /* KAMUS LOKAL */

  /* ALGORITMA */
  return i >= 0 && i < ROW_EFF(m) && j >= 0 && j < COL_EFF(m);
}

/* Melakukan assignment mOut <- mIn */
void copyMatrix(Matrix mIn, Matrix* mOut)
// I.S. mIn dan mOut terdefinisi dan berukuran sama
// F.S. mOut memiliki elemen-elemen yang sama dengan mIn
{
  /* KAMUS LOKAL */
  IdxType i, j;

  /* ALGORITMA */
  for(i = 0; i < ROW_EFF(mIn); i++) {
    for(j = 0; j < COL_EFF(mIn); j++) {
      MATRIX_ELMT(*mOut, i, j) = MATRIX_ELMT(mIn, i, j);
    }
  }
}

/* Selektor elemen diagonal ke-i */
MatrixElType getMATRIX_ELMTDiagonal(Matrix m, IdxType i)
{
  /* KAMUS LOKAL */

  /* ALGORITMA */
  return MATRIX_ELMT(m, i, i);
}

/* Menghasilkan true jika m1 dan m2 memiliki elemen-elemen yang sama */
boolean isMatrixEqual(Matrix m1, Matrix m2)
{
  /* KAMUS LOKAL */
  IdxType i, j;

  /* ALGORITMA */
  if(ROW_EFF(m1) != ROW_EFF(m2) || COL_EFF(m1) != COL_EFF(m2)) {
    return false;
  } else {
    for(i = 0; i < ROW_EFF(m1); i++) {
      for(j = 0; j < COL_EFF(m1); j++) {
        if(MATRIX_ELMT(m1, i, j) != MATRIX_ELMT(m2, i, j)) {
          return false;
        }
      }
    }
    return true;
  }
}

/* Menghitung jumlah elemen pada matriks */
int countElmt(Matrix m)
{
  /* KAMUS LOKAL */

  /* ALGORITMA */
  return ROW_EFF(m) * COL_EFF(m);
}

/* Menghasilkan true jika matriks m merupakan matriks persegi */
boolean isSquare(Matrix m)
{
  /* KAMUS LOKAL */

  /* ALGORITMA */
  return ROW_EFF(m) == COL_EFF(m);
}

/* Menghasilkan true jika matriks m simetris */
boolean isSymmetric(Matrix m)
{
  /* KAMUS LOKAL */
  IdxType i, j;

  /* ALGORITMA */
  for(i = 0; i < ROW_EFF(m); i++) {
    for(j = 0; j < COL_EFF(m); j++) {
      if(MATRIX_ELMT(m, i, j) != MATRIX_ELMT(m, j, i)) {
        return false;
      }
    }
  }
  return true;
}
