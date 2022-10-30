/* Definisi ADT Matriks dengan element char dan index integer */
#ifndef MATRIX_H
#define MATRIX_H

#include "../utility/boolean.h"

#define ROW_CAP 100   // Ukuran maksimum baris
#define COL_CAP 100   // Ukuran maksimum kolom

typedef int IdxType;   // Indeks baris dan kolom
typedef char MatrixElType;   // Elemen pada matriks

/* ADT Matriks dengan elemen selalu di ujung kiri atas */
typedef struct matrix
{
  MatrixElType mem[ROW_CAP][COL_CAP];   // Array tempat menyimpan matrix
  int rowEff;   // Jumlah baris yang terdefinisi
  int colEff;   // Jumlah kolom yang terdefinisi
} Matrix;

/* Konstruktor pembentuk matriks */
void createMatrix(int nRow, int nCol, Matrix* m);
// I.S. nRow dan nCol merupakan jumlah baris dan kolom yang valid untuk matriks
// F.S. Matriks m berukuran nRow x nCol terbentuk

/* Selektor */
#define ROW_EFF(m) (m).rowEff   // Jumlah baris efektif pada matriks
#define COL_EFF(m) (m).colEff   // Jumlah kolom efektif pada matriks
#define MATRIX_ELMT(m, i, j) (m).mem[i][j]   // Elemen baris ke-i dan kolom ke-j pada matriks

/* Menampilkan matrix ke layar */
void displayMatrix(Matrix m);
// I.S. m terdefinisi
// F.S. Elemen-elemen dari m ditampilkan di layar

/* Operasi-operasi pada matriks */

/* Menghasilkan true jika i dan j merupakan indeks yang valid untuk sebuah matriks */
boolean isMatrixIdxValid(IdxType i, IdxType j);

/* Menghasilkan true jika i dan j merupakan indeks efektif untuk matriks m */
boolean isMatrixIdxEff(Matrix m, IdxType i, IdxType j);

/* Melakukan assignment mOut <- mIn */
void copyMatrix(Matrix mIn, Matrix* mOut);
// I.S. mIn dan mOut terdefinisi
// F.S. mOut memiliki elemen-elemen yang sama dengan mIn

/* Selektor elemen diagonal ke-i */
MatrixElType getElmtDiagonal(Matrix m, IdxType i);

/* Menghasilkan true jika m1 dan m2 memiliki elemen-elemen yang sama */
boolean isMatrixEqual(Matrix m1, Matrix m2);

/* Menghitung jumlah elemen pada matriks */
int countElmt(Matrix m);

/* Menghasilkan true jika matriks m merupakan matriks persegi */
boolean isSquare(Matrix m);

/* Menghasilkan true jika matriks m simetris */
boolean isSymmetric(Matrix m);

#endif