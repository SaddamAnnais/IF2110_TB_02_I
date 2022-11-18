/* Implementasi rekomendasi makanan */
#include "rekomendasi.h"
#include <stdio.h>

/* IMPLEMENTASI KONSTRUKTOR dan INPUT/OUTPUT */

/* Konstruktor pembentuk set resep */
void createSetResep(SetResep* setResep, Resep resep)
// I.S. setResep sembarang
// F.S. setResep terdefinisi
{
  /* KAMUS LOKAL */
  int i, j;
  Set sTemp;

  /* ALGORITMA */
  for(i = 0; i < N_RESEP(resep); i++) {
    createSet(&sTemp);
    for(j = 0; j < NEFF(CHILDREN(R_ELMT(resep, i))); j++) {
      addToSet(&sTemp, ID(INFO(ELMT(CHILDREN(R_ELMT(resep, i)), j))));
    }

    (*setResep).buffer[ID(INFO(R_ELMT(resep, i)))] = sTemp;
  }
}

/* IMPLEMENTASI OPERASI-OPERASI REKOMENDASI MAKANAN  */

/* Melakukan union terhadap setiap resep makanan */
void unionResep(SetResep* setResep)
// I.S. setResep terdefinisi
// F.S. setResep berisi resep-resep yang hanya terdiri dari bahan-bahan dasar
{
  /* KAMUS LOKAL */
  int i, j, k, temp;

  /* ALGORITMA */
  for(i = 0; i < CAPACITY_LIST_MAKANAN; i++) {
    if(!isSetEmpty((*setResep).buffer[i])) {
      for(j = 0; j < SET_LENGTH((*setResep).buffer[i]); j++) {
        if(!isSetEmpty((*setResep).buffer[SET_ELMT((*setResep).buffer[i], j)])) {
          temp = SET_ELMT((*setResep).buffer[i], j);
          removeFromSet((*setResep).buffer + i, temp);
          for(k = 0; k < SET_LENGTH((*setResep).buffer[temp]); k++) {
            addToSet((*setResep).buffer + i, SET_ELMT((*setResep).buffer[temp], k));
          }
        }
      }
    }
  }
}

/* Menampilkan rekomendasi makanan berdasarkan bahan pada inventory */
void rekomendasi(SetResep setResep, Inventory inventory, ListMakanan listMakanan)
// I.S. inventory dan setResep terdefinisi
// F.S. Makanan yang dapat dibuat oleh bahan-bahan pada inventory ditampilkan di layar
{
  /* KAMUS LOKAL */
  int count, i, j, temp;
  Set setInv;

  /* ALGORITMA */
  createSet(&setInv);
  for(i = 0; i <= TailQ(inventory); i++) {
    addToSet(&setInv, Id(ElmtQ(inventory, i)));
  }
  for(i = 0; i < SET_LENGTH(setInv); i++) {
    if(!isSetEmpty(setResep.buffer[SET_ELMT(setInv, i)])) {
      temp = SET_ELMT(setInv, i);
      removeFromSet(&setInv, temp);
      for(j = 0; j < SET_LENGTH(setResep.buffer[temp]); j++) {
        addToSet(&setInv, SET_ELMT(setResep.buffer[temp], j));
      }
    }
  }

  printf("======================\n");
  printf("=     REKOMENDASI    =\n");
  printf("======================\n");

  count = 0;
  for(i = 0; i < CAPACITY_LIST_MAKANAN; i++) {
    if(!isSetEmpty(setResep.buffer[i]) && isSubset(setResep.buffer[i], setInv)) {
      count++;
      printf("\n  %d.  ", count);
      printWord(NAMA_MAKANAN(ElmtListMakanan(listMakanan, i)));
    }
  }
  if(count == 0) {
    printf("  Tidak ada makanan yang dapat direkomendasikan.\n");
  }
}