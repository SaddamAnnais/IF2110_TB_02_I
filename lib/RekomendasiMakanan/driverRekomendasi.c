#include "set.c"
#include "../Makanan/makanan.c"
#include "../Resep/resep.c"
#include "../Inventory/inventory.c"
#include "rekomendasi.c"
#include "../Resep/tree.c"
#include "../parser/charmachine.c"
#include "../parser/wordmachine.c"
#include "../Makanan/listmakanan.c"
#include "../priorityQueueDin/prioqueuedin.c"
#include "../ListDinamis/listdin.c"
#include "../Time/time.c"
#include <stdio.h>

int main() {
  Set s;
  createSet(&s);
  addToSet(&s, 1);
  addToSet(&s, 2);
  addToSet(&s, 3);
  addToSet(&s, 1);
  displaySet(s);
  addToSet(&s, 4);
  removeFromSet(&s, 1);
  displaySet(s);
  addToSet(&s, 1);
  addToSet(&s, 4);
  displaySet(s);


  Set s2;
  createSet(&s2);
  addToSet(&s2, 1);
  addToSet(&s2, 4);
  printf("%d\n", isSubset(s2, s));
  addToSet(&s2, 1);
  printf("%d\n", isSubset(s2, s));
  addToSet(&s2, 5);
  printf("%d\n", isSubset(s2, s));

  Resep resep;
  ListMakanan listMakanan;
  Inventory inventory;
  SetResep setResep;
  createInventory(&inventory);

  BacaMakanan(&listMakanan, "../../config/makanan.txt");
  readResep(&resep, "../../config/resep.txt", listMakanan);
  createSetResep(&setResep, resep);
  int i;
  for(i = 0; i < N_RESEP(resep); i++) {
    unionResep(&setResep);
  }
  for(i = 0; i < CAPACITY_LIST_MAKANAN; i++) {
    if(!isSetEmpty(setResep.buffer[i])) {
      printf("%d ", i);
      displaySet(setResep.buffer[i]);
    }
  }
  
  for(int i = 0; i < CAPACITY_LIST_MAKANAN; i++) {
    if (ID(ElmtListMakanan(listMakanan, i)) != IDX_UNDEF) {
      if(isWordStrEq(AKSI_MAKANAN(ElmtListMakanan(listMakanan, i)), "Buy")) {
        infotype infoMakanan;
        setInfotypeQ(&infoMakanan, ID(ElmtListMakanan(listMakanan, i)), timeToMinute(WAKTU_KADALUARSA(ElmtListMakanan(listMakanan, i))));
        enqueue(&inventory, infoMakanan);
      }
    }
  }

  rekomendasi(setResep, inventory, listMakanan);

  return 0;
}
