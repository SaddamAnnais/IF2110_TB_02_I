/* Definisi ADT n-ary Tree */
#ifndef TREE_H
#define TREE_H

#define TREE_IDX_UNDEF NULL

#include "../ListDinamis/listdin.h"
#include "../Makanan/makanan.h"
#include "../utility/boolean.h"

typedef Makanan treeInfo;   // Isi dari sebuah node
typedef struct tTreeNode* address;    // Pointer ke node

/* Node dari sebuah tree */
typedef struct tTreeNode
{
  treeInfo info;      // Isi dari node
  ListDin children;   // Children dari node 
} TreeNode;

/* ADT n-ary Tree */
typedef address Tree;

/* Mengalokasikan memory untuk sebuah node */
address newTreeNode(treeInfo val);

/* Konstruktor pembentuk tree */
void createTree(Tree* t, address p);
// I.S. Tree sembarang
// F.S. Tree terdefinisi

/* Selektor */
#define INFO(p) (p)->info    // Isi dari node
#define CHILDREN(p) (p)->children    // List children dari sebuah node

/* Menampilkan tree */
void displayTree(Tree t);
// I.S. Tree terdefinisi
// F.S. Semua elemen tree ditampilkan di layar 

/* Operasi-operasi pada tree */

/* Menghasilkan true jika tree memiliki >= 1 children */
boolean isTreeHasChildren(Tree t);

/* Menambahkan sebuah child pada tree */
void addChild(Tree* t, address p);
// I.S. Node p sudah dialokasi
// F.S. Node p menjadi salah satu children dari tree

/* Menghasilkan address dari sebuah val pada tree */
address searchTree(Tree t, int val);

#endif