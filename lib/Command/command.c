#include "command.h"
#include <stdio.h>

/* T maju, elemen waktu pada Inventory I dan Delivery D berkurang*/
void timePass(int mm, Time *T, Inventory *I, Delivery *D, int (*notif)[100], ListMakanan lM){
// I.S mm,T,I,D,invNotif,delivNotif terdefinisi
// F.S T maju sebanyak mm menit, elemen waktu pada Inventory I dan Delivery D berkurang sebanyak mm menit, dan elemen time yang <0 dihapus 
    incNMinute(T,mm);
    timePassQ(I,mm);
    timePassQ(D,mm);
    matIdNotPos(notif,*I,*D);
    delivToInv(*D,I,lM);
    keepPosTimeQ(I);
    keepPosTimeQ(D);
}

void delivToInv(Delivery D, Inventory *I,ListMakanan lM){
    infotype X;
    for (int i = 0; i<=TailQ(D); i++) {
        if (Time(ElmtQ(D,i))<=0){
            Id(X)=Id(ElmtQ(D,i));
            Time(X)=timeToMinute(WAKTU_KADALUARSA(ElmtListMakanan(lM,Id(X))))+Time(ElmtQ(D,i));
        enqueue(I,X);
        }
    }
}

// Memajukan time sebanyak input pengguna
void Wait(Time *T, Inventory *I, Delivery *D, int (*notif)[100], boolean *isValid, ListMakanan lM){
// I.S mm,T,I,D,invNotif,delivNotif terdefinisi
// F.S T, I, D, invNotif, delivNotif berubah sesuai timePass()
    int hh, mm;
    STARTWORD();
    hh = wordToInt(currentWord);
    STARTWORD();
    mm = wordToInt(currentWord);
    if (hh>= 0 && mm>= 0 && (hh!=0 || mm!=0)){
        mm += hh*60;
        timePass(mm,T,I,D,notif,lM);
        *isValid = true;
    } else {
        printf("Waktu wait harus >0\n");
    }
}

/* Menggerakan simulator sesuai input user, jika simulator berpindah posisi, waktu bertambah 1 menit*/
void Move(Peta *p, Simulator *s,Time *T, Inventory *I, Delivery *D, int (*notif)[100],boolean *isValid, ListMakanan lM){
// I.S. Simulator berada pada posisi (x, y)
// F.S. Jika pergerakan valid, simulator sekarang berada pada posisi baru dan semua elemen waktu maju
    STARTWORD();
    Point p0 = Lokasi(*s);

    if (isWordStrEq(currentWord,"NORTH")){
       moveNorth(p,s);
    } else if (isWordStrEq(currentWord,"WEST")){
       moveWest(p,s);
    } else if (isWordStrEq(currentWord,"SOUTH")){
       moveSouth(p,s);
    } else if (isWordStrEq(currentWord,"EAST")){
       moveEast(p,s);
    } else {
       printf("Input invalid\n");
    }

    Point pt = Lokasi(*s);
    if (!isEqual(p0,pt)){ //pergerakan valid
        timePass(1,T,I,D,notif,lM);//waktu berjalan 1 menit
        *isValid = true;
    }
}

/* Menampilkan bahan makanan yang tersedia dalam aplikasi dan informasinya*/
void Catalog(ListMakanan lM){
    printf("List Makanan\n");
    printf("(nama - durasi kedaluwarsa - aksi yang diperlukan - delivery time - durasi aksi)\n");
    printf("------------------------------------------------------------------------------------\n");
    int count = 1;
    for (int i=0; i<CAPACITY_LIST_MAKANAN; i++){
        if (ID(ElmtListMakanan(lM, i)) != IDX_UNDEF) {
            printf("%d. ",count);
            DisplayMakanan(ElmtListMakanan(lM, i));    
            printf("\n");
            count++;
        }        
    }
}

/* Melakukan pemesanan makanan */
void Buy(Peta *p, Simulator *s, ListMakanan lM, Delivery *D, Time *T, Inventory *I, int (*notif)[100], boolean *isValid){
    if (!isNearTelepon(*p, *s)){
        printf("BNMO tidak berada di area telepon!\n");
    } else{
        printf("======================\n");
        printf("=        BUY         =\n");
        printf("======================\n");
        printf("List Bahan Makanan:\n");
        // display makanan
        int count = 1;
        for (int i = 0; i < CAPACITY_LIST_MAKANAN ;i++){
            if (isWordStrEq(AKSI_MAKANAN(ElmtListMakanan(lM,i)), "Buy") && (ID(ElmtListMakanan(lM, i)) != IDX_UNDEF)){
                printf("    %d. ", count);
                printWord(NAMA_MAKANAN(ElmtListMakanan(lM,i)));
                printf(" (");
                displayTime1(LAMA_PENGIRIMAN(ElmtListMakanan(lM,i)));
                printf(")\n");
                count++;
            }
        }
        printf("Kirim 0 untuk exit.\n");
        printf("Enter command: ");
        STARTWORD();
        int n = wordToInt(currentWord);
        if (n >= count || n < 0){
            printf("Perintah tidak valid.\n");
        } else if (n > 0){
            Makanan m;
            int count1 = 0;
            for (int i = 0; i < CAPACITY_LIST_MAKANAN; i++){
                if (isWordStrEq(AKSI_MAKANAN(ElmtListMakanan(lM,i)), "Buy") && (ID(ElmtListMakanan(lM, i)) != IDX_UNDEF)){
                    count1++;
                }
                if (count1 == n && (isWordStrEq(AKSI_MAKANAN(ElmtListMakanan(lM,i)), "Buy")) && (ID(ElmtListMakanan(lM, i)) != IDX_UNDEF)){
                    m = ElmtListMakanan(lM,i);
                }
            }
            infotype m1;
            Time(m1) = timeToMinute(LAMA_PENGIRIMAN(m));
            Id(m1) = ID(m);
            printf("Berhasil memesan ");
            printWord(NAMA_MAKANAN(m));
            printf(". ");
            printWord(NAMA_MAKANAN(m));
            printf(" akan diantar dalam ");
            displayTime1(LAMA_PENGIRIMAN(m));
            printf(".\n");
            timePass(1,T,I,D,notif,lM);//waktu berjalan 1 menit
            enqueue(D,m1);
            *isValid = true;
        }
    }
}
/*UNDO REDO*/
void undo(Stack *UndoSt, Stack *RedoSt, Peta *P, Simulator *S, Delivery *D, Time *T, Inventory *I, Notif *notif)
/*Membatalkan command yang dilakukan dan mengembalikan*/
/*state aplikasi sebelum command tersebut*/
{
    if (!IsEmptyStack(*UndoSt)) {
        ElTypeStack X;

        PopStack(UndoSt, &X);
        PushStack(RedoSt, X);

        *S = SIMULATOR_STACK(TOP_STACK(*UndoSt));
        *D = DELIVERY_STACK(TOP_STACK(*UndoSt));
        *T = TIME_STACK(TOP_STACK(*UndoSt));
        *I = INVENTORY_STACK(TOP_STACK(*UndoSt));
        setPetaFromSimulator(P, *S);
        CreateNotif(notif, NOTIF_MUNDUR_STACK(TOP_STACK(*UndoSt)));
    } 
    else {
        printf("Tidak bisa undo\n");
    }
}

void redo(Stack *UndoSt, Stack *RedoSt, Peta *P, Simulator *S, Delivery *D, Time *T, Inventory *I, Notif *notif)
/*Membatalkan command undo pada Stack S*/
{
    if (!(IDX_TOP_STACK(*RedoSt)==-1)) {
        ElTypeStack X;

        PopStack(RedoSt, &X);
        PushStack(UndoSt, X);   

        *S = SIMULATOR_STACK(TOP_STACK(*UndoSt));
        *D = DELIVERY_STACK(TOP_STACK(*UndoSt));
        *T = TIME_STACK(TOP_STACK(*UndoSt));
        *I = INVENTORY_STACK(TOP_STACK(*UndoSt));
        setPetaFromSimulator(P, *S);
        CreateNotif(notif, NOTIF_MAJU_STACK(TOP_STACK(*UndoSt)));
    } 
    else {
        printf("Tidak bisa redo\n");
    }    
}


// void undoNotif(StackNotif *UndoStNotif, StackNotif *RedoStNotif, Notif *notif)
// /*Membatalkan command yang dilakukan dan mengembalikan*/
// /*state notif aplikasi sebelum command tersebut*/
// {
//     if (!IsEmptyStackNotif(*UndoStNotif)) {
//         ElTypeStackNotif X;

//         PopStackNotif(UndoStNotif, &X);
//         PushStackNotif(RedoStNotif, X);
        
        
//     } 
//     else {
//         printf("Tidak bisa undo notif\n");
//     }
// }

// void redoNotif(StackNotif *UndoStNotif, StackNotif *RedoStNotif, Notif *notif)
// /*Membatalkan command undo pada notif aplikasi*/
// {
//     if (!(IDX_TOP_STACK_NOTIF(*RedoStNotif)==-1)) {
//         ElTypeStackNotif X;

//         PopStackNotif(RedoStNotif, &X);
//         PushStackNotif(UndoStNotif, X);
        
//         CreateNotif(notif, NOTIF_MAJU(TOP_STACK_NOTIF(*UndoStNotif)));
//     } 
//     else {
//         printf("Tidak bisa redo notif\n");
//     }
// }

/* Melihat Delivery List */
void PrintDelivery(ListMakanan lM, Delivery D){
    printf("List Makanan di Perjalanan\n");
    printf("(nama - waktu sisa delivery)\n");
    for (int i = 0; i <= TailQ(D); i++){
        printf("    %d. ", i+1);
        printWord(NAMA_MAKANAN(ElmtListMakanan(lM, Id(ElmtQ(D, i)))));
        printf(" - ");
        displayTime1(minuteToTime(Time(ElmtQ(D,i))));
        printf("\n");
    }
}

/* Melihat makanan yang dimiliki di Inventory */
void PrintInventory(ListMakanan lM, Inventory I){
    printf("List Makanan di Inventory\n");
    printf("(nama - waktu sisa kedaluarsa)\n");
    for (int i = 0; i <= TailQ(I); i++){
        printf("    %d. ", i+1);
        printWord(NAMA_MAKANAN(ElmtListMakanan(lM, Id(ElmtQ(I, i)))));
        printf(" - ");
        displayTime1(minuteToTime(Time(ElmtQ(I,i))));
        printf("\n");
    }
}

void displayNotif(int notif[2][100], boolean alurMaju, ListMakanan lM)
/* Proses: Mengoutput notif makanan/bahan kadaluarsa atau delivery bahan sampai.*/
/* I.S. listId terdefinisi. Elemen bernilai Nil dianggap sebagai value kosong (tidak dioutput)*/
/* F.S. Output notif makanan/bahan kadaluarsa atau delivery bahan sampai*/
{
    printf("Notifikasi: ");
    if (*(*(notif))==Nil && *(*(notif+1))==Nil) {
        printf("-\n");
    } 
    else {
        printf("\n");
        int num = 1;
        if (alurMaju){
            for (int i = 0; i<100 && notif[0][i]!= Nil; i++) {
                printf("    %d. ", num);
                printWord(NAMA_MAKANAN(ElmtListMakanan(lM, notif[0][i])));
                printf(" kadaluwarsa :(\n");
                num++;
            }
            for (int i = 0; i<100 && notif[1][i]!= Nil; i++) {
                printf("    %d. ", num);
                printWord(NAMA_MAKANAN(ElmtListMakanan(lM, notif[1][i])));
                printf(" sudah diterima BNMO! :D\n");
                num++;
            }         
        } else {
            for (int i = 0; i<100 && notif[0][i]!= Nil; i++) {
                printf("    %d. ", num);
                printWord(NAMA_MAKANAN(ElmtListMakanan(lM, notif[0][i])));
                printf(" dikembalikan ke inventory :)\n");
                num++;
            }
            for (int i = 0; i<100 && notif[1][i]!= Nil; i++) {
                printf("    %d. ", num);
                printWord(NAMA_MAKANAN(ElmtListMakanan(lM, notif[1][i])));
                printf(" dikeluarkan dari inventory D:\n");
                num++;
            }            
        }
    }
}
/* Melakukan operasi pengolahan makanan */
void PengolahanMakanan(Word opWord, char* op, ListMakanan listMakanan, Inventory* inventory, Resep resep, Time* time, Delivery* delivery, int (*notif)[100], Peta peta, Simulator simulator, boolean *isValid)
// I.S. Semua parameter terdefinisi
// F.S. Jika operasi berhasil, maka isi dari inventory simulator akan berubah
{
  /* KAMUS LOKAL */
  IdxType i;
  int currInput;
  ListMakanan pilihanMakanan;
  boolean isSucceed;

  /* ALGORITMA */
  // Validasi posisi simulator
  if(!isNear(peta, simulator, op[0])) {
    printf("BNMO tidak berada di area ");
    printWord(opWord);
    printf("\n");
    return;
  }

  // Menampilkan jenis operasi pada layar
  for(i = 0; i <= 22; i++) printf("="); 
  printf("\n=");
  for(i = 0; i <= (20-opWord.Length)/2; i++) printf(" ");
  printWord(opWord);
  for(i = 0; i <= ((20-opWord.Length) - ((20-opWord.Length)/2) - 1); i++) printf((" "));
  printf("=\n");
  for(i = 0; i <= 22; i++) printf("=");
  printf("\n");

  // Menampilkan makanan yang dapat diolah
  pilihanMakanan = displayOperasiMakanan(listMakanan, op);

  // Menerima input pilihan makanan yang akan diolah
  printf("\nKirim 0 untuk exit.\n");
  printf("\nEnter Command: ");
  STARTWORD();
  currInput = wordToInt(currentWord);

  // Validasi input
  if(currInput > lenListMakanan(pilihanMakanan) || currInput < 0) {
    printf("\nInput tidak valid");
    return;
  } else if(currInput == 0) {
    return;
  }

  // Melakukan pengolahan makanan
  isSucceed = olahMakanan(ElmtListMakanan(pilihanMakanan, currInput), inventory, resep);
  if(isSucceed) {
    timePass(DURASI_AKSI(ElmtListMakanan(pilihanMakanan, currInput)), time, inventory, delivery, notif, listMakanan);
    *isValid = true;
  }
}

/* Membuka kulkas */
void OpenKulkas(ListMakanan listmakanan, Inventory* inventory, Kulkas* kulkas)
// I.S. Semua parameter terdefinisi
// F.S. Menambahkan atau mengeluarkan makanan dari kulkas
{
  /* KAMUS LOKAL */
  int currInput, i, baris, kolom, panjang, lebar;
  boolean isKosong;

  /* ALGORITMA */
  isKosong = true;
  printf("======== KULKAS =======\n");
  displayKulkas(*kulkas);
  for(i = 0; i < 100; i++) {
    if(K_MAKANAN(*kulkas, i) != -1) {
      isKosong = false;
      printf("  %c: ", (char) ('A' + i));
      printWord(NAMA_MAKANAN(ElmtListMakanan(listmakanan, K_MAKANAN(*kulkas, i))));
      printf("\n");
    }
  }
  printf("\nPilih aksi yang ingin dilakukan\n");
  printf("  1. Masukkan makanan ke kulkas\n");
  printf("  2. Keluarkan makanan dari kulkas\n");
  printf("Enter command: ");
  STARTWORD();
  currInput = wordToInt(currentWord);

  if(currInput == 1) {
    if(TailQ(*inventory) < 0) {
      printf("\nInventory kosong, tidak ada makanan yang bisa dimasukkan.\n");
      return;
    } else {
      printf("\nPilih makanan yang ingin dimasukkan ke kulkas - (panjang x lebar)\n");
      for(i = 0; i <= TailQ(*inventory); i++) {
        printf("  %d. ", i+1);
        printWord(NAMA_MAKANAN(ElmtListMakanan(listmakanan, Id(ElmtQ(*inventory, i)))));
        printf(" - (%d x %d)\n", PANJANG(ElmtListMakanan(listmakanan, Id(ElmtQ(*inventory, i)))), LEBAR(ElmtListMakanan(listmakanan, Id(ElmtQ(*inventory, i)))));
      }
      printf("Enter command: ");
      STARTWORD();
      currInput = wordToInt(currentWord);

      if(currInput < 1 || currInput > TailQ(*inventory)+1) {
        printf("\nMasukkan tidak valid.\n");
        return;
      }
      currInput--;

      panjang = PANJANG(ElmtListMakanan(listmakanan, Id(ElmtQ(*inventory, currInput))));
      lebar = LEBAR(ElmtListMakanan(listmakanan, Id(ElmtQ(*inventory, currInput))));

      printf("Masukkan baris dan kolom pada kulkas: ");
      STARTWORD();
      baris = wordToInt(currentWord);
      STARTWORD();
      kolom = wordToInt(currentWord);

      if(!isKulkasIdxValid(*kulkas, baris, kolom, panjang, lebar)) {
        printf("\nBaris dan kolom tidak valid.\n");
        return;
      } else {
        insertToKulkas(kulkas, inventory, Id(ElmtQ(*inventory, currInput)), baris, kolom, panjang, lebar);
        printf("\nMakanan berhasil dimasukkan ke kulkas.\n");
        return;
      }
    }
  } else if(currInput == 2) {
    if(isKosong) {
      printf("\nKulkas kosong, tidak ada makanan yang bisa dikeluarkan.\n");
      return;
    } else {
      printf("Masukkan makanan yang ingin dikeluarkan: ");
      STARTWORD();
      currInput = currentWord.TabWord[0];
      if(((int) currInput - 'A') < 0 || ((int) currInput - 'A') > 100) {
        printf("\nMasukkan tidak valid.\n");
        return;
      } else if(K_MAKANAN(*kulkas, (int) currInput - 'A') == -1) {
        printf("\nMakanan tidak terdapat di kulkas.\n");
        return;
      } else {
        removeFromKulkas(kulkas, inventory, currInput);
        printf("\nMakanan berhasil dikeluarkan dari kulkas.\n");
        return;
      }
    }
  } else {
    printf("\nMasukkan tidak valid.\n");
    return;
  }
}
