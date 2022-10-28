#include "listmakanan.h"
#include <stdio.h>

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create List kosong  */
void CreateListMakanan(ListMakanan *l)
/* I.S. l sembarang */
/* F.S. Terbentuk List l kosong dengan kapasitas CAPACITY */
{
    lenListMakanan(*l) = 0;
}
/* ********** TEST KOSONG/PENUH ********** */

void printListMakanan(ListMakanan l)
/* Proses : Menuliskan isi List dengan traversal, List ditulis di antara kurung 
   siku; antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan 
   karakter di depan, di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. l boleh kosong */
/* F.S. Jika l tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika List kosong : menulis [] */
{
    printf("List Makanan:\n");
    printf("        (nama   -   durasi kadaluwarsa   -   aksi yang diperlukan   -   delivery time   -   lama pembuatan)\n");

    for (int i = 0; i <= lenListMakanan(l) - 1; i++)
    {
        printf("       %d. ", i+1);
        DisplayMakanan(ElmtListMakanan(l, i));
        printf("\n");
    }
}

/* BACA/TULIS */
void BacaMakanan(ListMakanan *l, char *filename)
/* Membaca ID, lokasi aksi, serta waktu kadaluarsa
   dan membentuk Makanan M berdasarkan nilai tersebut */
/* Semua komponen ditulis dalam 1 baris, dipisahkan 1 spasi */
/* I.S. : M sembarang */
/* F.S. : M terdefinisi */
{
    /* KAMUS */
    Makanan m;

    CreateListMakanan(l);

    Time kadaluarsa, pengiriman;
    int hari = 0, jam = 0, menit = 0;

    STARTWORDFILE(filename);
    int N = wordToInt(currentWord);
    ADVWORD();
    /* ALGORITMA */

    for (int i = 0; i<N; i++) {
        ID(m) = wordToInt(currentWord);
        ADVLINE();
        
        NAMA_MAKANAN(m) = currentWord;

        ADVWORD();
        hari = wordToInt(currentWord);
        ADVWORD();
        jam =  wordToInt(currentWord);
        ADVWORD();
        menit = wordToInt(currentWord);

        createTime(&kadaluarsa, hari, jam, menit);
        WAKTU_KADALUARSA(m) = kadaluarsa;

        ADVWORD();
        hari = wordToInt(currentWord);
        ADVWORD();
        jam =  wordToInt(currentWord);
        ADVWORD();
        menit = wordToInt(currentWord);

        createTime(&pengiriman, hari, jam, menit);
        LAMA_PENGIRIMAN(m) = pengiriman;

        ADVWORD();
        AKSI_MAKANAN(m) = currentWord;

        ADVWORD();
        DURASI_AKSI(m) = wordToInt(currentWord);

        ElmtListMakanan(*l, i) = m;
        lenListMakanan(*l)++;
        ADVWORD();
    }
}
