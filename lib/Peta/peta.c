#include "peta.h"
#include <stdio.h>

/* Konstruktor pembentuk peta */
void createPeta(Peta* p, int nRow, int nCol)
// I.S. nRow dan nCol merupakan ukuran peta yang valid
// F.S. Peta p berukuran nRow x nCol terdefinisi dengan batasan '*'
{
  /* KAMUS LOKAL */
  IdxType i, j;

  /* ALGORITMA */
  createMatrix(nRow+2, nCol+2, p);
  for(i = 0; i < ROW_EFF(*p); i++) {
    for(j = 0; j < COL_EFF(*p); j++) {
      if(isBatas(*p, i, j)) {
        MATRIX_ELMT(*p, i, j) = '*';
      }
    }
  }
}

/* Membaca peta */
void readPeta(Peta* p, char* filename, Simulator* s)
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
          MATRIX_ELMT(*p, count-1, i+1) = ' ';
        } else if(currentWord.TabWord[i] == 'S') {
          MATRIX_ELMT(*p, count-1, i+1) = 'S';
          ABSIS(Lokasi(*s)) = i;
          ORDINAT(Lokasi(*s)) = count-2; 
        } else {
          MATRIX_ELMT(*p, count-1, i+1) = currentWord.TabWord[i];
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
  displayMatrix(p);
}

/* Operasi-operasi pada peta */

/* Menghasilkan true jika index i dan j merupakan batas pada peta */
boolean isBatas(Peta p, IdxType i, IdxType j)
{
  /* KAMUS LOKAL */

  /* ALGORITMA */
  return i == 0 || j == 0 || i == (ROW_EFF(p)-1) || j == (COL_EFF(p)-1);
}

/* Menghasilkan true jika index i dan j merupakan koordinat yang valid untuk simulator */
boolean isCoordSimValid(Peta p, IdxType i, IdxType j)
{
  /* KAMUS LOKAL */
  char element;

  /* ALGORITMA */
  element = MATRIX_ELMT(p, i, j);
  return element == ' ';
}

/* Menggerakkan simulator ke arah utara */
void moveNorth(Peta* p, Simulator* s)
// I.S. Simulator berada pada posisi (x, y)
// F.S. Jika pergerakan valid, simulator sekarang berada pada posisi (x, y-1)
{
  /* KAMUS LOKAL */
  int newX, newY;

  /* ALGORITMA */
  newX = ABSIS(Lokasi(*s)) + 1;
  newY = ORDINAT(Lokasi(*s));
  if(isCoordSimValid(*p, newY, newX)) {
    MATRIX_ELMT(*p, ORDINAT(Lokasi(*s))+1, ABSIS(Lokasi(*s))+1) = ' ';
    MATRIX_ELMT(*p, newY, newX) = 'S';
    ABSIS(Lokasi(*s)) = newX-1;
    ORDINAT(Lokasi(*s)) = newY-1;
  } else {
    printf("Pergerakkan tidak valid karena terdapat rintangan\n");
  }
}

/* Menggerakkan simulator ke arah timur */
void moveEast(Peta* p, Simulator* s)
// I.S. Simulator berada pada posisi (x, y)
// F.S. Jika pergerakan valid, simulator sekarang berada pada posisi (x+1, y)
{
  /* KAMUS LOKAL */
  int newX, newY;

  /* ALGORITMA */
  newX = ABSIS(Lokasi(*s)) + 2;
  newY = ORDINAT(Lokasi(*s)) + 1;
  if(isCoordSimValid(*p, newY, newX)) {
    MATRIX_ELMT(*p, ORDINAT(Lokasi(*s))+1, ABSIS(Lokasi(*s))+1) = ' ';
    MATRIX_ELMT(*p, newY, newX) = 'S';
    ABSIS(Lokasi(*s)) = newX-1;
    ORDINAT(Lokasi(*s)) = newY-1;
  } else {
    printf("Pergerakkan tidak valid karena terdapat rintangan\n");
  }
}

/* Menggerakkan simulator ke arah selatan */
void moveSouth(Peta* p, Simulator* s)
// I.S. Simulator berada pada posisi (x, y)
// F.S. Jika pergerakan valid, simulator sekarang berada pada posisi (x, y+1)
{
  /* KAMUS LOKAL */
  int newX, newY;

  /* ALGORITMA */
  // TODO: Sesuaikan dengan ADT Simulator
  newX = ABSIS(Lokasi(*s)) + 1;
  newY = ORDINAT(Lokasi(*s)) + 2;
  if(isCoordSimValid(*p, newY, newX)) {
    MATRIX_ELMT(*p, ORDINAT(Lokasi(*s))+1, ABSIS(Lokasi(*s))+1) = ' ';
    MATRIX_ELMT(*p, newY, newX) = 'S';
    ABSIS(Lokasi(*s)) = newX-1;
    ORDINAT(Lokasi(*s)) = newY-1;
  } else {
    printf("Pergerakkan tidak valid karena terdapat rintangan\n");
  }
}

/* Menggerakkan simulator ke arah barat */
void moveWest(Peta* p, Simulator* s)
// I.S. Simulator berada pada posisi (x, y)
// F.S. Jika pergerakan valid, simulator sekarang berada pada posisi (x-1, y)
{
  /* KAMUS LOKAL */
  int newX, newY;

  /* ALGORITMA */
  // TODO: Sesuaikan dengan ADT Simulator
  newX = ABSIS(Lokasi(*s));
  newY = ORDINAT(Lokasi(*s)) + 1;
  if(isCoordSimValid(*p, newY, newX)) {
    MATRIX_ELMT(*p, ORDINAT(Lokasi(*s))+1, ABSIS(Lokasi(*s))+1) = ' ';
    MATRIX_ELMT(*p, newY, newX) = 'S';
    ABSIS(Lokasi(*s)) = newX-1;
    ORDINAT(Lokasi(*s)) = newY-1;
  } else {
    printf("Pergerakkan tidak valid karena terdapat rintangan\n");
  }
}

/* Menghasilkan true jika simulator berada di dekat x */
boolean isNear(Peta p, Simulator s, char c)
{
  /* KAMUS LOKAL */
  IdxType i, j;
  int x, y;

  /* ALGORITMA */
  x = ABSIS(Lokasi(s)) + 1;
  y = ORDINAT(Lokasi(s)) + 1;
  for(i = y-1; i <= y+1; i++) {
    for(j = x-1; j <= x+1; j++) {
      if(MATRIX_ELMT(p, i, j) == c) {
        return true;
      }
    }
  }
  return false;
}

/* Menghasilkan true jika simulator berada di dekat telepon */
boolean isNearTelepon(Peta p, Simulator s)
{
  /* KAMUS LOKAL */

  /* ALGORITMA */
  return isNear(p, s, 'T');
}

/* Menghasilkan true jika simulator berada di dekat tempat mixing */
boolean isNearMixing(Peta p, Simulator s)
{
  /* KAMUS LOKAL */

  /* ALGORITMA */
  return isNear(p, s, 'M');
}


/* Menghasilkan true jika simulator berada di dekat tempat memotong */
boolean isNearMemotong(Peta p, Simulator s)
{
  /* KAMUS LOKAL */

  /* ALGORITMA */
  return isNear(p, s, 'C');
}


/* Menghasilkan true jika simulator berada di dekat tempat menggoreng */
boolean isNearMenggoreng(Peta p, Simulator s)
{
  /* KAMUS LOKAL */

  /* ALGORITMA */
  return isNear(p, s, 'F');
}


/* Menghasilkan true jika simulator berada di dekat tempat merebus */
boolean isNearMerebus(Peta p, Simulator s)
{
  /* KAMUS LOKAL */

  /* ALGORITMA */
  return isNear(p, s, 'B');
}

void setPetaFromSimulator(Peta *p, Simulator s)
// I.S. Peta dengan lokasi simulator sembarang
// F.S. Terbentuk peta dengan lokasi simulator berada di ABSIS(Lokasi(s)), ORDINAT(Lokasi(s)) 
{
  for (int i = 0; i<ROW_EFF(*p); i++) {
    for (int j = 0; j<COL_EFF(*p); j++) {
      if (MATRIX_ELMT(*p, i, j) == 'S') {
        MATRIX_ELMT(*p, i, j) = ' ';
      }
    }
  }  
  MATRIX_ELMT(*p, ORDINAT(Lokasi(s))+1, ABSIS(Lokasi(s))+1) = 'S';
}

