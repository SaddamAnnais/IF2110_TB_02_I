/* ADT Makanan*/
#include "makanan.h"

/*KONSTRUKTOR*/
Makanan CreateMakanan(int id, Word nama, Lokasi aksi, TIME kadaluarsa, int pengiriman)
/* Membentuk sebuah Makanan dari komponen-komponennya */
{
    /*KAMUS*/
    Makanan M;

    /*ALGORITMA*/
    ID(M) = UNDEF_ID;
    NAMA_MAKANAN(M) = nama;
    WAKTU_KADALUARSA(M) = UNDEF_TIME;
    AKSI_MAKANAN(M) = aksi;
    LAMA_PENGIRIMAN(M) = UNDEF_TIME;  
}

/* BACA/TULIS */
void BacaMakanan(Makanan *M, ListDin daftarLokasi)
/* Membaca ID, lokasi aksi, serta waktu kadaluarsa
   dan membentuk Makanan M berdasarkan nilai tersebut */
/* Semua komponen ditulis dalam 1 baris, dipisahkan 1 spasi */
/* I.S. : M sembarang */
/* F.S. : M terdefinisi */
{
    /* KAMUS */
    int i;

    /* ALGORITMA */
    advWordFile();
    ID(*M) = wordToInt(currentWord);

    advWordFile();
    NAMA_MAKANAN(*M) = currentWord;

    advWordFile();
    WAKTU_KADALUARSA(*M) = wordToInt(currentWordFile);

    advWordFile();
    i = 0;
    while ((i < listLength(daftarLokasi)) && (NAMA_LOKASI(ELMT(daftarLokasi, i)) != currentWordFile.contents[0])) {
        i++; //"daftarLokasi namanya hrs sesuaiin func yg di file lokasi"
    }
    AKSI_MAKANAN(*M) = ELMT(daftarLokasi, i);

    advWordFile();
    LAMA_PENGIRIMAN(*M) = wordToInt(currentWord);

    advCharFile(); /* Membaca baris berikutnya */
}

void DisplayMakanan(Makanan M)
/* I.S. : M terdefinisi */
/* F.S. : M tertulis di layar sesuai dengan format */
{
    /* KAMUS */

    /* ALGORITMA */
    printfFile("%d %c", ID(M), NAMA_MAKANAN(M));
    printfFile(WAKTU_KADALUARSA(M));
    printfFile(AKSI_MAKANAN(M));
    printfFile("%d", LAMA_PENGIRIMAN(M));

}