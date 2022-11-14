/* Implementasi dari ADT Set */
#include "set.h"
#include <stdio.h>

/* IMPLEMENTASI KONSTRUKTOR dan INPUT/OUTPUT */

/* Konstruktor pembentuk set */
void createSet(Set* set)
// I.S. Set sembarang
// F.S. Set terdefinisi
{
  /* KAMUS LOKAL */

  /* ALGORITMA */
  SET_LENGTH(*set) = 0;
}

/* Menampilkan set ke layar */
void displaySet(Set set)
// I.S. Set terdefinisi
// F.S. Semua elemen set ditampilkan di layar
{
  /* KAMUS LOKAL */
  int i;

  /* ALGORITMA */
  printf("(");
  for(i = 0; i < SET_LENGTH(set); i++) {
    printf("%d", SET_ELMT(set, i));
    if(i < SET_LENGTH(set)-1) {
      printf(", ");
    }
  }
  printf(")\n");
}

/* IMPLEMENTASI OPERASI-OPERASI PADA SET */

/* Menghasilkan true jika set kosong */
boolean isEmpty(Set set)
{
  /* KAMUS LOKAL */

  /* ALGORITMA */
  return SET_LENGTH(set) == 0;
}

/* Menambahkan elemen ke set */
void addToSet(Set* set, ElType x)
// I.S. Set terdefinisi dan mungkin kosong
// F.S. Menambahkan elemen ke set jika x belum terdapat di set
{
  /* KAMUS LOKAL */
  int i;

  /* ALGORITMA */
  for(i = 0; i < SET_LENGTH(*set); i++) {
    if(SET_ELMT(*set, i) == x) {
      return;
    }
  }
  SET_ELMT(*set, SET_LENGTH(*set)) = x;
  SET_LENGTH(*set)++;
}

/* Menghapus elemen dari set */
void removeFromSet(Set* set, ElType x)
// I.S. Set tidak kosong dan x terdapat di dalam set
// F.S. X terhapus dari set
{
  /* KAMUS LOKAL */
  int idx, i;

  /* ALGORITMA */
  for(i = 0; i < SET_LENGTH(*set); i++) {
    if(SET_ELMT(*set, i) == x) {
      idx = i;
      break;
    }
  }
  for(i = idx; i < SET_LENGTH(*set)-1; i++) {
    SET_ELMT(*set, i) = SET_ELMT(*set, i+1);
  }
  SET_LENGTH(*set)--;
}

/* Menghasilkan true jika x terdapat di dalam set */
boolean isIn(Set set, ElType x)
{
  /* KAMUS LOKAL */
  int i;

  /* ALGORITMA */
  for(i = 0; i < SET_LENGTH(set); i++) {
    if(SET_ELMT(set, i) == x) {
      return true;
    }
  }
  return false;
}

/* Menghasilkan true jika s1 = s2 */
boolean isEqual(Set s1, Set s2)
{
  /* KAMUS LOKAL */

  /* ALGORITMA */
  if(isEmpty(s1) && isEmpty(s2)) {
    return true;
  } else {
    return isSubset(s1, s2) && isSubset(s2, s1);
  }
}

/* Menghasilkan gabungan dari s1 dan s2 */
Set unionSet(Set s1, Set s2)
{
  /* KAMUS LOKAL */
  Set sOut;
  int i;

  /* ALGORITMA */
  createSet(&sOut);
  for(i = 0; i < SET_LENGTH(s1); i++) {
    addToSet(&sOut, SET_ELMT(s1, i));
  }
  for(i = 0; i < SET_LENGTH(s2); i++) {
    addToSet(&sOut, SET_ELMT(s2, i));
  }
  return sOut;
}

/* Menghasilkan irisan dari s1 dan s2 */
Set intersectionSet(Set s1, Set s2)
{
  /* KAMUS LOKAL */
  Set sOut;
  int i;

  /* ALGORITMA */
  createSet(&sOut);
  for(i = 0; i < SET_LENGTH(s1); i++) {
    if(isIn(s2, SET_ELMT(s1, i))) {
      addToSet(&sOut, SET_ELMT(s1, i));
    }
  }
}

/* Menghasilkan true jika s1 merupakan subset dari s2 */
boolean isSubset(Set s1, Set s2)
{
  /* KAMUS LOKAL */
  int i;

  /* ALGORITMA */
  for(i = 0; i < SET_LENGTH(s1); i++) {
    if(!isIn(s2, SET_ELMT(s1, i))) {
      return false;
    }
  }
  return true;
}
