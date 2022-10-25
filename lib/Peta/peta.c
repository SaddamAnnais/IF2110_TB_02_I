#include "peta.h"
#include "../parser/wordmachine.h"

/* Konstruktor pembentuk peta */
void createPeta(Peta* p, int nRow, int nCol)
// I.S. nRow dan nCol merupakan ukuran peta yang valid
// F.S. Peta p berukuran nRow x nCol terdefinisi dengan batasan '*'
{
  /* KAMUS LOKAL */
  IdxType i, j;

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
void readPeta(Peta* p, char* filename)
// I.S. Peta p sembarang
// F.S. Peta p sesuai dengan konfigurasi
{
  /* KAMUS LOKAL */
  int count = 0, nRow, nCol, i;

  /* ALGORITMA */
  STARTWORDFILE(filename);
  while(!EndWord) {
    if(count == 0) {
      nRow = 0;
      for(i = 0; i < currentWord.Length; i++) {
        nRow *= 10;
        nRow += currentWord.TabWord[i] - '0';
      }
    } else if(count == 1) {
      nCol = 0;
      for(i = 0; i < currentWord.Length; i++) {
        nCol *= 10;
        nCol += currentWord.TabWord[i] - '0';
      }
      createPeta(p, nRow, nCol);
    } else {
      for(i = 0; i < currentWord.Length; i++) {
        if(currentWord.TabWord[i] == '#') {
          ELMT(MATRIX(*p), count-1, i+1) = ' ';
        } else if(currentWord.TabWord[i] == 'S') {
          ELMT(MATRIX(*p), count-1, i+1) = 'S';
          //TODO : Sesuaikan dengan ADT Simulator
          createPoint(&POSISI(*p), i+1, count-1);
        } else {
          ELMT(MATRIX(*p), count-1, i+1) = currentWord.TabWord[i];
        }
      }
    }
    count++;
    ADVWORD();
  }
}

/* Menampilkan peta */
void displayPeta(Peta p)
// I.S. Peta p terdefinisi
// F.S. Peta p ditampilkan di layar
{
  /* KAMUS LOKAL */

  /* ALGORITMA */
  displayMatrix(MATRIX(p));
}

/* Operasi-operasi pada peta */

/* Menghasilkan true jika index i dan j merupakan batas pada peta */
boolean isBatas(Peta p, IdxType i, IdxType j)
{
  /* KAMUS LOKAL */

  /* ALGORITMA */
  return i == 0 || j == 0 || i == (ROW_EFF(MATRIX(p))-1) || j == (COL_EFF(MATRIX(p))-1);
}

/* Menghasilkan true jika index i dan j merupakan koordinat yang valid untuk simulator */
boolean isCoordSimValid(Peta p, IdxType i, IdxType j)
{
  /* KAMUS LOKAL */
  char element;

  /* ALGORITMA */
  element = ELMT(MATRIX(p), i, j);
  return element == ' ';
}

/* Menggerakkan simulator ke arah utara */
void moveNorth(Peta* p)
// I.S. Simulator berada pada posisi (x, y)
// F.S. Jika pergerakan valid, simulator sekarang berada pada posisi (x, y-1)
{
  /* KAMUS LOKAL */
  int newX, newY;

  /* ALGORITMA */
  // TODO: Sesuaikan dengan ADT Simulator
  newX = ABSIS(POSISI(*p));
  newY = ORDINAT(POSISI(*p)) - 1;
  if(isCoordSimValid(*p, newY, newX)) {
    ELMT(MATRIX(*p), ORDINAT(POSISI(*p)), ABSIS(POSISI(*p))) = ' ';
    ELMT(MATRIX(*p), newY, newX) = 'S';
    ABSIS(POSISI(*p)) = newX;
    ORDINAT(POSISI(*p)) = newY;
  } else {
    printf("Pergerakkan tidak valid karena terdapat rintangan\n");
  }
}

/* Menggerakkan simulator ke arah timur */
void moveEast(Peta* p)
// I.S. Simulator berada pada posisi (x, y)
// F.S. Jika pergerakan valid, simulator sekarang berada pada posisi (x+1, y)
{
  /* KAMUS LOKAL */
  int newX, newY;

  /* ALGORITMA */
  // TODO: Sesuaikan dengan ADT Simulator
  newX = ABSIS(POSISI(*p)) + 1;
  newY = ORDINAT(POSISI(*p));
  if(isCoordSimValid(*p, newY, newX)) {
    ELMT(MATRIX(*p), ORDINAT(POSISI(*p)), ABSIS(POSISI(*p))) = ' ';
    ELMT(MATRIX(*p), newY, newX) = 'S';
    ABSIS(POSISI(*p)) = newX;
    ORDINAT(POSISI(*p)) = newY;
  } else {
    printf("Pergerakkan tidak valid karena terdapat rintangan\n");
  }
}

/* Menggerakkan simulator ke arah selatan */
void moveSouth(Peta* p)
// I.S. Simulator berada pada posisi (x, y)
// F.S. Jika pergerakan valid, simulator sekarang berada pada posisi (x, y+1)
{
  /* KAMUS LOKAL */
  int newX, newY;

  /* ALGORITMA */
  // TODO: Sesuaikan dengan ADT Simulator
  newX = ABSIS(POSISI(*p));
  newY = ORDINAT(POSISI(*p)) + 1;
  if(isCoordSimValid(*p, newY, newX)) {
    ELMT(MATRIX(*p), ORDINAT(POSISI(*p)), ABSIS(POSISI(*p))) = ' ';
    ELMT(MATRIX(*p), newY, newX) = 'S';
    ABSIS(POSISI(*p)) = newX;
    ORDINAT(POSISI(*p)) = newY;
  } else {
    printf("Pergerakkan tidak valid karena terdapat rintangan\n");
  }
}

/* Menggerakkan simulator ke arah barat */
void moveWest(Peta* p)
// I.S. Simulator berada pada posisi (x, y)
// F.S. Jika pergerakan valid, simulator sekarang berada pada posisi (x-1, y)
{
  /* KAMUS LOKAL */
  int newX, newY;

  /* ALGORITMA */
  // TODO: Sesuaikan dengan ADT Simulator
  newX = ABSIS(POSISI(*p)) - 1;
  newY = ORDINAT(POSISI(*p));
  if(isCoordSimValid(*p, newY, newX)) {
    ELMT(MATRIX(*p), ORDINAT(POSISI(*p)), ABSIS(POSISI(*p))) = ' ';
    ELMT(MATRIX(*p), newY, newX) = 'S';
    ABSIS(POSISI(*p)) = newX;
    ORDINAT(POSISI(*p)) = newY;
  } else {
    printf("Pergerakkan tidak valid karena terdapat rintangan\n");
  }
}
