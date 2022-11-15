/* Implementasi ADT Resep */
#include "resep.h"
#include <stdlib.h>

/* IMPLEMENTASI KONSTRUKTOR dan INPUT/OUTPUT */

/* Konstruktor pembentuk resep */
void createResep(Resep* resep)
// I.S. List resep sembarang
// F.S. List resep terdefinisi
{
  /* KAMUS LOKAL */

  /* ALGORITMA */
  N_RESEP(*resep) = 0;
}

/* Membaca resep dari file konfigurasi */
void readResep(Resep* resep, char* filepath, ListMakanan listMakanan)
// I.S. File konfigurasi valid dan list resep sembarang
// F.S. List resep terbentuk sesuai dengan file konfigurasi
{
  /* KAMUS LOKAL */
  IdxType i, j, k;
  int lineCount, currentId, wordCount;
  Makanan currentMakanan;

  /* ALGORITMA */
  createResep(resep);
  lineCount = 0;

  STARTWORDFILE(filepath);
  while(!EndWord) {
    if(lineCount > 0) {
      wordCount = 0;
      for(i = 0; i < currentWord.Length; i++) {
        currentId = 0;
        while(currentWord.TabWord[i] != BLANK && i < currentWord.Length) {
          currentId *= 10;
          currentId += currentWord.TabWord[i] - '0';
          i++;
        }
        wordCount++;
        currentMakanan = ElmtListMakanan(listMakanan, currentId);

        if(wordCount == 1) {
          createTree(&R_ELMT(*resep, N_RESEP(*resep)), newTreeNode(currentMakanan));
          N_RESEP(*resep)++;
        } else if(wordCount > 2) {
          addChild(&R_ELMT(*resep, N_RESEP(*resep)-1), newTreeNode(currentMakanan));
        } 
      }
    }

    lineCount++;
    ADVLINE();
  }
}

/* Menampilkan seluruh resep ke layar dengan command COOKBOOK */
void displayCookbook(Resep resep)
// I.S. Resep terdefinisi
// F.S. Seluruh resep ditampilkan di layar sesuai format pada spesifikasi
{
  /* KAMUS LOKAL */
  IdxType i; 

  /* ALGORITMA */
  if(N_RESEP(resep) == 0) {
    printf("List resep kosong\n");
  } else {
    printf("List Resep\n(aksi yang diperlukan - bahan...)");
    for(i = 0; i < N_RESEP(resep); i++) {
      printf("\n  %d.  ", i+1);
      printWord(NAMA_MAKANAN(INFO(R_ELMT(resep, i))));
      printf("\n      ");
      printWord(AKSI_MAKANAN(INFO(R_ELMT(resep, i))));

      displayResep(R_ELMT(resep, i));
    }
    printf("\n");
  }
}

/* Menampilkan sebuah node resep ke layar */
void displayResep(address node)
// I.S. Sebuah node resep terdefinisi
// F.S. Sebuah node resep ditampilkan di layar sesuai format pada spesifikasi
{
  /* KAMUS LOKAL */
  IdxType i;

  /* ALGORITMA */
  for(i = 0; i < NEFF(CHILDREN(node)); i++) {
    printf(" - ");
    printWord(NAMA_MAKANAN(INFO(ELMT(CHILDREN(node), i))));
  }
}

/* IMPLEMENTASI OPERASI-OPERASI PADA RESEP */

/* Menghasilkan bahan makanan untuk membuat sebuah makanan */
ListDin bahanMakanan(Resep resep, int id)
{
  /* KAMUS LOKAL */
  IdxType i;

  /* ALGORITMA */
  for(i = 0; i < N_RESEP(resep); i++) {
    if(ID(INFO(R_ELMT(resep, i))) == id) {
      return CHILDREN(R_ELMT(resep, i));
    }
  }
}

/* Menampilkan daftar makanan yang dapat dibuat oleh sebuah operasi pengolahan makanan */
ListMakanan displayOperasiMakanan(ListMakanan listMakanan, char* operasi)
// I.S. Operasi merupakan operasi pengolahan makanan yang valid
// F.S. Semua makanan yang dapat dibuat dari operasi tersebut ditampilkan di layar
//      sesuai format pada spesifikasi
{
  /* KAMUS LOKAL */
  IdxType i;
  int numList;
  ListMakanan output;

  /* ALGORITMA */
  CreateListMakanan(&output);
  numList = 0;

  printf("List Bahan Makanan yang Bisa Dibuat:\n");
  for(i = 0; i < CAPACITY_LIST_MAKANAN; i++) {
    if (ID(ElmtListMakanan(listMakanan, i)) != IDX_UNDEF) {
      if(isWordStrEq(AKSI_MAKANAN(ElmtListMakanan(listMakanan, i)), operasi)) {
        printf("  %d. ", numList+1);
        printWord(NAMA_MAKANAN(ElmtListMakanan(listMakanan, i)));
        printf("\n");
        numList++;
        ElmtListMakanan(output, numList) = ElmtListMakanan(listMakanan, i);
        lenListMakanan(output)++;
      }
    }
  }
  
  if(numList == 0) {
    printf("Tidak ada bahan makanan yang dapat dibuat dengan operasi '%s'\n", operasi);
  }

  return output;
}

/* Melakukan operasi pengolahan makanan */
boolean olahMakanan(Makanan makanan, Inventory* inventory, Resep resep)
// I.S. Makanan merupakan makanan yang ingin dibuat
// F.S. Jika bahan makanan tersedia pada inventory, makanan hasil pengolahan ditambahkan
//      ke dalam inventory dan bahan makanan dihilangkan dari inventory
{
  /* KAMUS LOKAL */
  boolean isOpsValid;
  ListDin listBahan;
  IdxType i;
  infotype infoMakanan;
  int numList;
  Makanan tempMakanan;

  /* ALGORITMA */
  listBahan = bahanMakanan(resep, ID(makanan));

  isOpsValid = true;
  for(i = 0; i < NEFF(listBahan); i++) {
    if(!isIdInQ(*inventory, ID(INFO(ELMT(listBahan, i))))) {
      isOpsValid = false;
      break;
    }
  }

  if(isOpsValid) {
    for(i = 0; i < NEFF(listBahan); i++) {
      delIdFromQ(inventory, ID(INFO(ELMT(listBahan, i))));
    }
    setInfotypeQ(&infoMakanan, ID(makanan), timeToMinute(WAKTU_KADALUARSA(makanan)));
    enqueue(inventory, infoMakanan);
    printWord(NAMA_MAKANAN(makanan));
    printf(" selesai dibuat dan sudah masuk ke inventory!\n");
    return true;
  } else {
    printf("Gagal membuat ");
    printWord(NAMA_MAKANAN(makanan));
    printf(" karena kamu tidak memiliki bahan berikut:\n");

    numList = 1;
    for(i = 0; i < NEFF(listBahan); i++) {
      if(!isIdInQ(*inventory, ID(INFO(ELMT(listBahan, i))))) {
        printf("  %d.  ", numList);
        printWord(NAMA_MAKANAN((INFO(ELMT(listBahan, i)))));
        printf("\n");
        numList++;
      }
    }
    return false;
  }
}
