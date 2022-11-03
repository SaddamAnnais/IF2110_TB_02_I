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
            Time(X)=timeToMinute(WAKTU_KADALUARSA(ElmtListMakanan(lM,Id(X))));
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
void undo(Stack *UndoSt, Stack *RedoSt, ElTypeStack *X, Peta *P, Simulator *S, Delivery *D, Time *T, Inventory *I)
/*Membatalkan command yang dilakukan dan mengembalikan*/
/*state aplikasi sebelum command tersebut*/
{
    if (!IsEmptyStack(*UndoSt)) {
        // *X = TOP_STACK(*UndoSt); buat pertama doang
        // PushStack(RedoSt, *X);

        PushStack(RedoSt, *X);
        PopStack(UndoSt, X);

        *S = SIMULATOR_STACK(*X);
        *D = DELIVERY_STACK(*X);
        *T = TIME_STACK(*X);
        *I = INVENTORY_STACK(*X);
        setPetaFromSimulator(P, *S);

        // PushStack(RedoSt, *X);

    } 
    else {
        printf("Tidak bisa undo\n");
        // *P = *P;
        // *S = *S;
        // *D = *D;
        // *T = *T;
        // *I = *I;

    }
}

void redo(Stack *UndoSt, Stack *RedoSt, ElTypeStack *X, Peta *P, Simulator *S, Delivery *D, Time *T, Inventory *I)
/*Membatalkan command undo pada Stack S*/
{
    if (!IsEmptyStack(*RedoSt)) {
        // *X = TOP_STACK(*RedoSt);     buat pertama doang
        // PushStack(UndoSt, *X);
        
        PushStack(UndoSt, *X);   
        PopStack(RedoSt, X);

        *S = SIMULATOR_STACK(*X);
        *D = DELIVERY_STACK(*X);
        *T = TIME_STACK(*X);
        *I = INVENTORY_STACK(*X);
        setPetaFromSimulator(P, *S);

        //PushStack(UndoSt, *X);
    } 
    else {
        printf("Tidak bisa redo\n");
    }    
}

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
    printf("(nama - waktu sisa delivery)\n");
    for (int i = 0; i <= TailQ(I); i++){
        printf("    %d. ", i+1);
        printWord(NAMA_MAKANAN(ElmtListMakanan(lM, Id(ElmtQ(I, i)))));
        printf(" - ");
        displayTime1(minuteToTime(Time(ElmtQ(I,i))));
        printf("\n");
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
  if(!isNear(peta, simulator, op[0]))

  // Menampilkan jenis operasi pada layar
  for(i = 0; i <= 22; i++) printf("="); 
  printf("\n=");
  for(i = 0; i <= (20-opWord.Length)/2; i++) printf(" ");
  printWord(opWord);
  for(i = 0; i <= (opWord.Length - ((20-opWord.Length)/2)); i++) printf((" "));
  printf("=\n");
  for(i = 0; i <= 22; i++) printf("=");
  printf("\n");

  // Menampilkan makanan yang dapat diolah
  pilihanMakanan = displayOperasiMakanan(listMakanan, op);

  // Menerima input pilihan makanan yang akan diolah
    printf("\nKirim 0 untuk exit.\n");
  while(true) {
    printf("\nEnter Command: ");
    STARTWORD();
    currInput = wordToInt(currentWord);

    // Validasi input
    if(currInput > lenListMakanan(pilihanMakanan) || currInput < 0) {
      printf("\nInput tidak valid");
    } else if(currInput == 0) {
      break;
    }

    // Melakukan pengolahan makanan
    isSucceed = olahMakanan(ElmtListMakanan(pilihanMakanan, currInput), inventory, resep);
    if(isSucceed) {
      timePass(DURASI_AKSI(ElmtListMakanan(pilihanMakanan, currInput)), time, inventory, delivery, notif, listMakanan);
      *isValid = true;
    }
  } 
}