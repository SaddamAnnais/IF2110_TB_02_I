#include "tree.h"
#include <stdio.h>
#include <stdlib.h>

/* Mengalokasikan memory untuk sebuah node */
address newTreeNode(treeInfo val)
{
  /* KAMUS LOKAL */
  address p;

  /* ALGORITMA */
  p = (address) malloc(sizeof(TreeNode));
  if(p != NULL) {
    ID(INFO(p)) = ID(val);
    NAMA_MAKANAN(INFO(p)) = NAMA_MAKANAN(val);
    WAKTU_KADALUARSA(INFO(p)) = WAKTU_KADALUARSA(val);
    AKSI_MAKANAN(INFO(p)) = AKSI_MAKANAN(val);
    LAMA_PENGIRIMAN(INFO(p)) = LAMA_PENGIRIMAN(val);
    DURASI_AKSI(INFO(p)) = DURASI_AKSI(val);

    CreateListDin(&CHILDREN(p), 5);
    return p;
  }
}

/* Konstruktor pembentuk tree */
void createTree(Tree* t, address p)
// I.S. Tree sembarang
// F.S. Tree terdefinisi
{
  /* KAMUS LOKAL */

  /* ALGORITMA */
  *t = p;
}

/* Menampilkan tree */
void displayTree(Tree t)
// I.S. Tree terdefinisi
// F.S. Semua elemen tree ditampilkan di layar
{
  /* KAMUS LOKAL */
  IdxType i;

  /* ALGORITMA */
  printf("%d", ID(INFO(t)));

  if(isTreeHasChildren(t)) {
    for(i = 0; i < NEFF(CHILDREN(t)); i++) {
      printf("(");
      displayTree(ELMT(CHILDREN(t), i));
      printf(")");
    }
  }
}

/* Operasi-operasi pada tree */

/* Menghasilkan true jika tree memiliki >= 1 children */
boolean isTreeHasChildren(Tree t)
{
  /* KAMUS LOKAL */

  /* ALGORITMA */
  return NEFF(CHILDREN(t)) > 0;
}

/* Menambahkan sebuah child pada tree */
void addChild(Tree* t, address p)
// I.S. Node p sudah dialokasi
// F.S. Node p menjadi salah satu children dari tree
{
  /* KAMUS LOKAL */

  /* ALGORITMA */
  if(isFull(CHILDREN(*t))) {
    expandList(&CHILDREN(*t), LISTDINCAPACITY(CHILDREN(*t)));
  }

  insertLast(&CHILDREN(*t), p);
}

/* Menghasilkan address dari sebuah val pada tree */
address searchTree(Tree t, int val)
{
  /* KAMUS LOKAL */
  address p, temp;
  IdxType i;
  
  /* ALGORITMA */
  if(ID(INFO(t)) == val) {
    return t;
  }

  if(isTreeHasChildren(t)) {
    p = TREE_IDX_UNDEF;
    for(i = 0; i < NEFF(CHILDREN(t)); i++) {
      temp = searchTree(ELMT(CHILDREN(t), i), val);
      if(temp != TREE_IDX_UNDEF) {
        p = temp;
      }
    }
    return p;
  }
}
