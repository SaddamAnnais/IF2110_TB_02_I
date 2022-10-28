#include "tree.h"
#include <stdio.h>

int main() {
  Tree t;

  Word w;
  w.TabWord[0] = 'w';
  w.Length = 1;

  Time o;
  o.DD = 1;
  o.MM = 1;
  o.HH = 1;

  Makanan m;
  ID(m) = 4;

  createTree(&t, newTreeNode(m));

  ID(m) = 2;
  addChild(&t, newTreeNode(m));
  ID(m) = 1;
  address temp = newTreeNode(m);
  addChild(&t, temp);
  ID(m) = 3;
  addChild(&t, newTreeNode(m));
  ID(m) = 8;
  addChild(&temp, newTreeNode(m));
  ID(m) = 6;
  addChild(&temp, newTreeNode(m));
  ID(m) = 2;
  addChild(&temp, newTreeNode(m));
  ID(m) = 8;
  addChild(&temp, newTreeNode(m));
  ID(m) = 6;
  addChild(&temp, newTreeNode(m));
  ID(m) = 2;
  addChild(&temp, newTreeNode(m));

  // displayTree(t);

  printf("%d", ID(INFO(searchTree(t, 1))));
  return 0;
}