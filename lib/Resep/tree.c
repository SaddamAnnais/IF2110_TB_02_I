/* Implementasi ADT n-ary Tree */
#include "tree.h"
#include <stdio.h>
#include <stdlib.h>

/* IMPLEMENTASI KONSTRUKTOR dan INPUT/OUTPUT */

/* Mengalokasikan memory untuk sebuah node */
address newTreeNode(treeInfo value)
{
  /* KAMUS LOKAL */
  address node;

  /* ALGORITMA */
  node = (address) malloc(sizeof(TreeNode));
  if(node != NULL) {
    ID(INFO(node)) = ID(value);
    NAMA_MAKANAN(INFO(node)) = NAMA_MAKANAN(value);
    WAKTU_KADALUARSA(INFO(node)) = WAKTU_KADALUARSA(value);
    AKSI_MAKANAN(INFO(node)) = AKSI_MAKANAN(value);
    LAMA_PENGIRIMAN(INFO(node)) = LAMA_PENGIRIMAN(value);
    DURASI_AKSI(INFO(node)) = DURASI_AKSI(value);

    CreateListDin(&CHILDREN(node), 5);
    return node;
  }
}

/* Konstruktor pembentuk tree */
void createTree(Tree* tree, address node)
// I.S. Tree sembarang
// F.S. Tree terdefinisi
{
  /* KAMUS LOKAL */

  /* ALGORITMA */
  *tree = node;
}

/* Menampilkan tree ke layar */
void displayTree(Tree tree)
// I.S. Tree terdefinisi
// F.S. Semua elemen tree ditampilkan di layar 
{
  /* KAMUS LOKAL */
  IdxType i;

  /* ALGORITMA */
  printf("%d", ID(INFO(tree)));

  if(isTreeHasChildren(tree)) {
    for(i = 0; i < NEFF(CHILDREN(tree)); i++) {
      printf("(");
      displayTree(ELMT(CHILDREN(tree), i));
      printf(")");
    }
  }
}

/* IMPLEMENTASI OPERASI-OPERASI PADA RESEP */

/* Menghasilkan true jika tree memiliki >= 1 children */
boolean isTreeHasChildren(Tree tree)
{
  /* KAMUS LOKAL */

  /* ALGORITMA */
  return NEFF(CHILDREN(tree)) > 0;
}

/* Menambahkan sebuah child pada tree */
void addChild(Tree* tree, address node)
// I.S. Node sudah dialokasi
// F.S. Node menjadi salah satu children dari tree
{
  /* KAMUS LOKAL */

  /* ALGORITMA */
  if(isFull(CHILDREN(*tree))) {
    expandList(&CHILDREN(*tree), LISTDINCAPACITY(CHILDREN(*tree)));
  }

  insertLast(&CHILDREN(*tree), node);
}

/* Melakukan operasi pencarian value pada tree */
address searchTree(Tree tree, int value)
{
  /* KAMUS LOKAL */
  address node, tempNode;
  IdxType i;
  
  /* ALGORITMA */
  if(ID(INFO(tree)) == value) {
    return tree;
  }

  if(isTreeHasChildren(tree)) {
    node = TREE_IDX_UNDEF;
    for(i = 0; i < NEFF(CHILDREN(tree)); i++) {
      tempNode = searchTree(ELMT(CHILDREN(tree), i), value);
      if(tempNode != TREE_IDX_UNDEF) {
        node = tempNode;
      }
    }
    return node;
  }
}
