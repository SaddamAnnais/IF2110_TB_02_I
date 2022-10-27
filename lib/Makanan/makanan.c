/* ADT Makanan*/
#include "makanan.h"

/*KONSTRUKTOR*/
Makanan CreateMakanan(int id, Word nama, Word aksi, Time kadaluarsa, Time pengiriman)
/* Membentuk sebuah Makanan dari komponen-komponennya */
{
    /*KAMUS*/
    Makanan M;

    /*ALGORITMA*/
    ID(M) = id;
    NAMA_MAKANAN(M) = nama;
    WAKTU_KADALUARSA(M) = kadaluarsa;
    AKSI_MAKANAN(M) = aksi;
    LAMA_PENGIRIMAN(M) = pengiriman;  
}

void DisplayMakanan(Makanan M)
/* I.S. : M terdefinisi */
/* F.S. : M tertulis di layar sesuai dengan format */
{
    /* KAMUS */

    /* ALGORITMA */
    printWord(NAMA_MAKANAN(M));
    printf("   -   ");
    printf("%d Hari %d Jam %d Menit", Day(WAKTU_KADALUARSA(M)), Hour(WAKTU_KADALUARSA(M)), Minute(WAKTU_KADALUARSA(M)));
    printf("   -   ");
    printWord(AKSI_MAKANAN(M));
    printf("   -   ");
    printf("%d Hari %d Jam %d Menit", Day(LAMA_PENGIRIMAN(M)), Hour(LAMA_PENGIRIMAN(M)), Minute(LAMA_PENGIRIMAN(M)));

}