#include "resep.h"
#include <stdlib.h>

/* Konstruktor pembentuk resep */
void createResep(Resep* r)
// I.S. Resep sembarang
// F.S. Resep terdefinisi
{
  /* KAMUS LOKAL */

  /* ALGORITMA */
  NRESEP(*r) = 0;
}

/* Membaca resep dari file konfigurasi */
void readResep(Resep* r, char* filepath, ListMakanan l)
// I.S. File konfigurasi valid dan resep r sembarang
// F.S. Resep r terbentuk sesuai dengan file konfigurasi 
{
  /* KAMUS LOKAL */
  int lineCount = 0, i, j, k, currId, numCount;
  Makanan currMakanan;
  address p;

  /* ALGORITMA */
  STARTWORDFILE(filepath);
  createResep(r);
  while(!EndWord) {
    if(lineCount > 0) {
      // printWord(currentWord);
      numCount = 0;
      for(i = 0; i < currentWord.Length; i++) {
        currId = 0;
        while(currentWord.TabWord[i] != BLANK && i < currentWord.Length) {
          currId *= 10;
          currId += currentWord.TabWord[i] - '0';
          i++;
        }
        numCount++;
        currMakanan = searchMakanan(l, currId);

        if(numCount == 1) {
          createTree(&RELMT(*r, NRESEP(*r)), newTreeNode(currMakanan));
          NRESEP(*r)++;
        } else if(numCount > 2) {
          addChild(&RELMT(*r, NRESEP(*r)-1), newTreeNode(currMakanan));
        } 
      }
    }
    lineCount++;
    ADVLINE();
  }

  // for(i = 0; i < NRESEP(*r); i++) {
  //   for(j = 0; j < NRESEP(*r); j++) {
  //     if(j!=i && RELMT(*r, j) != NULL) {
  //       p = searchTree(RELMT(*r, j), ID(INFO(RELMT(*r, i))));
  //       if(p != TREE_IDX_UNDEF) {
  //         for(k = 0; k < NEFF(CHILDREN(RELMT(*r, i))); k++) {
  //           addChild(&p, ELMT(CHILDREN(RELMT(*r, i)), k));
  //         }
  //         RELMT(*r, i) = NULL;
  //         break;
  //       } 
  //     }
  //   }
  // }
}

/* Menampilkan seluruh resep ke layar */
void displayCookbook(Resep r)
// I.S. Resep terdefinisi
// F.S. Seluruh resep ditampilkan di layar
{
  /* KAMUS LOKAL */
  int i, num = 1;

  /* ALGORITMA */
  printf("List Resep\n(aksi yang diperlukan - bahan...)");
  for(i = 0; i < NRESEP(r); i++) {
    if(RELMT(r, i)!=NULL) {
      printf("\n%d.  ", i+1);
      printWord(NAMA_MAKANAN(INFO(RELMT(r, i))));
      printf("\n    ");
      printWord(AKSI_MAKANAN(INFO(RELMT(r, i))));
      displayResep(RELMT(r, i));
    }
  }
}

/* Menampilkan sebuah node resep ke layar */
void displayResep(address p)
// I.S. Node p terdefinisi
// F.S. Node p ditampilkan di layar dengan semua childnya
{
  /* KAMUS LOKAL */
  int i;

  /* ALGORITMA */
  for(i = 0; i < NEFF(CHILDREN(p)); i++) {
    printf(" - ");
    printWord(NAMA_MAKANAN(INFO(ELMT(CHILDREN(p), i))));
  }
}

/* Operasi-operasi pada resep */

// Menghasilkan data makanan berdasarkan id
Makanan searchMakanan(ListMakanan l, int id)
{
  /* KAMUS LOKAL */
  IdxType i;

  /* ALGORITMA */
  for(i = 0; i < l.len; i++) {
    if(ID(ElmtListMakanan(l, i)) == id) {
      return ElmtListMakanan(l, i);
    }
  }
}

// Melakukan operasi pengolahan makanan
void olahMakanan(Makanan m, Inventory* i, char o);

// Melakukan operasi mix makanan
void mix(Makanan m, Inventory* i);

// Melakukan operasi chop makanan
void chop(Makanan m, Inventory* i);

// Melakukan operasi fry makanan
void fry(Makanan m, Inventory* i);

// Melakuka operasi boil makanan
void boil(Makanan m, Inventory* i);