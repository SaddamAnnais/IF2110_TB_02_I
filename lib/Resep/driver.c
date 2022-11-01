#include "resep.h"
#include <stdio.h>

int main() {
  // Insialisasi program
  Resep resep;
  ListMakanan listMakanan;
  Inventory inventory;
  createInventory(&inventory);

  // Read dari file konfigurasi
  BacaMakanan(&listMakanan, "../../config/makanan.txt");
  readResep(&resep, "../../config/resep.txt", listMakanan);

  // Insialisasi inventory
  for(int i = 0; i < lenListMakanan(listMakanan); i++) {
    if(isWordStrEq(AKSI_MAKANAN(ElmtListMakanan(listMakanan, i)), "Buy")) {
      infotype infoMakanan;
      setInfotypeQ(&infoMakanan, ID(ElmtListMakanan(listMakanan, i)), timeToMinute(WAKTU_KADALUARSA(ElmtListMakanan(listMakanan, i))));
      enqueue(&inventory, infoMakanan);
    }
  }

  // Menampilkan cookbook
  displayCookbook(resep);

  // Menampilkan semua makanan yang dapat dibuat oleh sebuah operasi pengolahan makanan
  ListMakanan temp1 = displayOperasiMakanan(listMakanan, "Fry");
  ListMakanan temp2 = displayOperasiMakanan(listMakanan, "Boil");

  // Pengolahan makanan
  printPrioQ(inventory);
  Makanan makanan = searchMakananById(listMakanan, 1);
  olahMakanan(makanan, &inventory, resep);
  printPrioQ(inventory);
  makanan = searchMakananById(listMakanan, 5);
  olahMakanan(makanan, &inventory, resep);
  printPrioQ(inventory);

  return 0;
}
