/* Definisi ADT n-ary Tree */
#ifndef TREE_H
#define TREE_H

#define TREE_IDX_UNDEF NULL     // Digunakan dalam operasi pencarian pada tree

#include "../ListDinamis/listdin.h"
#include "../Makanan/makanan.h"
#include "../utility/boolean.h"

typedef Makanan treeInfo;             // Isi dari sebuah node
typedef struct tTreeNode* address;    // Pointer ke node

/* Node dari sebuah tree */
typedef struct tTreeNode
{
  treeInfo info;      // Isi dari node
  ListDin children;   // Children dari node 
} TreeNode;

/* ADT n-ary Tree */
typedef address Tree;

/* KONSTRUKTOR, SELEKTOR, dan INPUT/OUTPUT */

/* Mengalokasikan memory untuk sebuah node */
address newTreeNode(treeInfo value);

/* Konstruktor pembentuk tree */
void createTree(Tree* tree, address node);
// I.S. Tree sembarang
// F.S. Tree terdefinisi

/* Selektor */
#define INFO(p) (p)->info            // Selektor isi dari node
#define CHILDREN(p) (p)->children    // Selektor list children dari sebuah node

/* Menampilkan tree ke layar */
void displayTree(Tree tree);
// I.S. Tree terdefinisi
// F.S. Semua elemen tree ditampilkan di layar 

/* OPERASI-OPERASI PADA RESEP */

/* Menghasilkan true jika tree memiliki >= 1 children */
boolean isTreeHasChildren(Tree tree);

/* Menambahkan sebuah child pada tree */
void addChild(Tree* tree, address node);
// I.S. Node sudah dialokasi
// F.S. Node menjadi salah satu children dari tree

/* Melakukan operasi pencarian value pada tree */
address searchTree(Tree tree, int value);

#endif