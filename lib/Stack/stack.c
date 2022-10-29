#include "stack.h"
#include "../parser/wordmachine.h"

/*KONSTRUKTOR*/
void CreateStack(Stack *S)
/* I.S. sembarang; */
/* F.S. Membuat Stack S kosong dengan index top bernilai IDX_UNDEF_STACK */
{
    IDX_TOP_STACK(*S) = IDX_UNDEF_STACK;
}

void CreateElTypeStack(ElTypeStack *elmt, Simulator S, Delivery D, Time t, Peta p, Inventory I)
/* Mengembalikan ElTypeStack yang terdefinisi sesuai input */
{
    SIMULATOR_STACK(*elmt) = S;
    DELIVERY_STACK(*elmt) = D;
    TIME_STACK(*elmt) = t;
    PETA_STACK(*elmt) = p;
    INVENTORY_STACK(*elmt) = I;
}

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsEmptyStack(Stack S)
/* Mengirim true jika Stack kosong: lihat definisi di atas */
{
    return (IDX_TOP_STACK(S) == IDX_UNDEF_STACK);
}

boolean IsFullStack(Stack S)
/* Mengirim true jika tabel penampung nilai elemen stack penuh */
{
     return (IDX_TOP_STACK(S) == CAPACITY_STACK - 1);
}

void PushStack(Stack * S, ElTypeStack X)
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */
{
    /*KAMUS LOKAL*/

    /* ALGORITMA */
    IDX_TOP_STACK(*S)++;
    TOP_STACK(*S) = X;
}

/* ************ Menghapus sebuah elemen Stack ************ */
void PopStack(Stack *S, ElTypeStack *X)
/* Menghapus X dari Stack S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */
{
    *X = TOP_STACK(*S);
    IDX_TOP_STACK(*S)--;
}

int lenStack(Stack s)
/*Mengirimkan jumlah elemen pada stack*/
{
    return IDX_TOP_STACK(s) + 1;
}

