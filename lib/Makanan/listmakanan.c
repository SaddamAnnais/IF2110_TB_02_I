#include "listmakanan.h"
#include <stdio.h>

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create List kosong  */
void CreateListMakanan(ListMakanan *l)
/* I.S. l sembarang */
/* F.S. Terbentuk List l kosong dengan kapasitas CAPACITY */
/* Proses: Inisialisasi semua ID makanan UNDEF_ID */
{
    /*KAMUS LOKAL*/
    int i;
    /*ALGORITMA*/
    for (i = IDX_MIN; i < CAPACITY; i++){
        ELMT(*l, i) = UNDEF_ID;
    }
}
int listLength(ListMakanan l)
/* Mengirimkan banyaknya elemen efektif List */
/* Mengirimkan nol jika List kosong */  
{
    /*KAMUS LOKAL*/
    int i = 0;
    /*ALGORITMA*/
 
    while (ELMT(l, i) != MARK) {
        i++;
    }
    return i;
}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test List kosong *** */
boolean isEmpty(ListStatik l)
/* Mengirimkan true jika List l kosong, mengirimkan false jika tidak */
{
    return (listLength(l) == 0);
}
/* *** Test List penuh *** */
boolean isFull(ListMakanan l)
/* Mengirimkan true jika List l penuh, mengirimkan false jika tidak */
{
    return (ListMakanan(l) == CAPACITY);
}

void printList(ListStatik l)
/* Proses : Menuliskan isi List dengan traversal, List ditulis di antara kurung 
   siku; antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan 
   karakter di depan, di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. l boleh kosong */
/* F.S. Jika l tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika List kosong : menulis [] */
{
    int i;
    printf("[");
    for (i = 0; i <= listLength(l) - 1; i++)
    {
        printf(ELMT(l, i));
        if (i != listLength(l) - 1){
            printf(",");
        }
    }
    printf("]");
}
