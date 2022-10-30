#include "resep.h"
#include <stdio.h>

int main() {
  Resep r;
  ListMakanan l;
  CreateListMakanan(&l);
  BacaMakanan(&l, "../Makanan/test.txt");
  printListMakanan(l);

  // Word w;
  // w.TabWord[0] = 'w';
  // w.Length = 1;

  // Time o;
  // o.DD = 1;
  // o.MM = 1;
  // o.HH = 1;

  // Makanan m;

  // ID(m) = 1;
  // ElmtListMakanan(l, lenListMakanan(l)) = m;
  // lenListMakanan(l)++;

  // ID(m) = 2;
  // ElmtListMakanan(l, lenListMakanan(l)) = m;
  // lenListMakanan(l)++;

  // ID(m) = 3;
  // ElmtListMakanan(l, lenListMakanan(l)) = m;
  // lenListMakanan(l)++;

  // ID(m) = 4;
  // ElmtListMakanan(l, lenListMakanan(l)) = m;
  // lenListMakanan(l)++;

  // ID(m) = 5;
  // ElmtListMakanan(l, lenListMakanan(l)) = m;
  // lenListMakanan(l)++;

  // ID(m) = 6;
  // ElmtListMakanan(l, lenListMakanan(l)) = m;
  // lenListMakanan(l)++;

  // ID(m) = 7;
  // ElmtListMakanan(l, lenListMakanan(l)) = m;
  // lenListMakanan(l)++;

  // ID(m) = 8;
  // ElmtListMakanan(l, lenListMakanan(l)) = m;
  // lenListMakanan(l)++;

  // ID(m) = 9;
  // ElmtListMakanan(l, lenListMakanan(l)) = m;
  // lenListMakanan(l)++;

  // ID(m) = 10;
  // ElmtListMakanan(l, lenListMakanan(l)) = m;
  // lenListMakanan(l)++;

  // ID(m) = 11;
  // ElmtListMakanan(l, lenListMakanan(l)) = m;
  // lenListMakanan(l)++;

  // ID(m) = 12;
  // ElmtListMakanan(l, lenListMakanan(l)) = m;
  // lenListMakanan(l)++;

  // readResep(&r, "./konfig2.txt", l);
  // displayCookbook(r);
  return 0;
}
