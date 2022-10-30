#include "command.h"
#include <stdio.h>

/* T maju, elemen waktu pada Inventory I dan Delivery D berkurang*/
void timePass(int mm, Time *T, Inventory *I, Delivery *D, int (*notif)[100]){
// I.S mm,T,I,D,invNotif,delivNotif terdefinisi
// F.S T maju sebanyak mm menit, elemen waktu pada Inventory I dan Delivery D berkurang sebanyak mm menit, dan elemen time yang <0 dihapus 
    incNMinute(T,mm);
    timePassQ(I,mm);
    timePassQ(D,mm);
    matIdNotPos(notif,*I,*D);
    keepPosTimeQ(I);
    keepPosTimeQ(D);
}

// Memajukan time sebanyak input pengguna
void Wait(Time *T, Inventory *I, Delivery *D, int (*notif)[100]){
// I.S mm,T,I,D,invNotif,delivNotif terdefinisi
// F.S T, I, D, invNotif, delivNotif berubah sesuai timePass()
    int hh, mm;
    STARTWORD();
    hh = wordToInt(currentWord);
    STARTWORD();
    mm = wordToInt(currentWord);

    mm += hh*60;
    timePass(mm,T,I,D,notif);
}

/* Menggerakan simulator sesuai input user, jika simulator berpindah posisi, waktu bertambah 1 menit*/
void Move(Peta *p, Simulator *s,Time *T, Inventory *I, Delivery *D, int (*notif)[100]){
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
        timePass(1,T,I,D,notif);//waktu berjalan 1 menit
    }
}

/* Menampilkan bahan makanan yang tersedia dalam aplikasi dan informasinya*/
void Catalog(ListMakanan lM){
    printf("List Makanan\n");
    printf("(nama - durasi kedaluwarsa - aksi yang diperlukan - delivery time - durasi aksi)\n");

    for (int i=0; i<lM.len; i++){
        DisplayMakanan(lM.contents[i]);
        printf("\n");
    }
}

/* Melakukan pemesanan makanan */
void Buy(Peta *p, Simulator *s, ListMakanan lM, Delivery *D, Time *T, Inventory *I, int (*notif)[100]){
    if (!isNearTelepon(*p, *s)){
        printf("BNMO tidak berada di area telepon!\n");
    } else{
        printf("======================\n");
        printf("=        BUY         =\n");
        printf("======================\n");
        printf("List Bahan Makanan:\n");
        // display makanan
        int count = 1;
        for (int i = 0; i < lM.len; i++){
            if (isWordStrEq(AKSI_MAKANAN(ElmtListMakanan(lM,i)), "BUY")){
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
        int n;
        scanf("%d", &n);
        if (n >= count || n < 0){
            printf("Perintah tidak valid.\n");
        } else if (n > 0){
            Makanan m;
            int count1 = 1;
            for (int i = 0; i < lM.len; i++){
                if (isWordStrEq(AKSI_MAKANAN(ElmtListMakanan(lM,i)), "BUY")){
                    count1++;
                }
                if (count1 == n){
                    m = ElmtListMakanan(lM,i);
                }
            }
            infotype m1;
            Time(m1) = timeToMinute(LAMA_PENGIRIMAN(m));
            //Makanan(m1) = m;
            timePass(1,T,I,D,notif);//waktu berjalan 1 menit
            enqueue(D,m1);
            printf("Berhasil memesan ");
            printWord(NAMA_MAKANAN(m));
            printf(". ");
            printWord(NAMA_MAKANAN(m));
            printf(" akan diantar dalam ");
            displayTime1(LAMA_PENGIRIMAN(m));
            printf(".\n");
        }
    }
}