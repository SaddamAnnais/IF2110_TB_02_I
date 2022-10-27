#include "stack.h"
#include "../parser/wordmachine.h"

/*KONSTRUKTOR*/
void CreateStack(Stack *S)
/* I.S. sembarang; */
/* F.S. Membuat Stack S kosong dengan index top bernilai IDX_UNDEF */
/* Proses : Melakukan alokasi, membuat sebuah s kosong */
{
    CAPACITY_STACK(*S) = 3;
    BUFFER_STACK(*S) = (ElTypeStack*)malloc(CAPACITY_STACK(*S) * sizeof(ElTypeStack));
    IDX_TOP_STACK(*S) = IDX_UNDEF_STACK;
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
     return (IDX_TOP_STACK(S) == CAPACITY_STACK(S) - 1);
}

void PushStack(Stack * S, ElTypeStack X)
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */
{
    /*KAMUS LOKAL*/
    int i;
    ElTypeStack temp;

    /* ALGORITMA */
    if (isEmptyStack(*S)) {
        IDX_TOP_STACK(*S) = 0;
        TOP_STACK(*S) = X;
    }
    else {
        IDX_TOP_STACK(*S)++;
        TOP_STACK(*S) = X;
    }
}

/* ************ Menghapus sebuah elemen Stack ************ */
void PopStack(Stack * S, ElTypeStack* X)
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
    /*KAMUS LOKAL*/
    ElTypeStack temp;
    int len;

    /*ALGORITMA*/
    len = 0;
    while (!IsEmpty(s)){
        pop(&s, &temp);
        len++;
    }
    return len;
}

void deleteAtStack(Stack* S, int idx, ElTypeStack* val)
/*Menghapus element ke idx pada stack S dan menyimpan*/
/*nilainya pada val*/
{
    /*KAMUS LOKAL*/
    int i;

    /* ALGORITMA */
    *val = S->buffer[idx];

    i = idx;
    while (i < IDX_TOP_STACK(*S)) {
        S->buffer[i] = S->buffer[i + 1];
        i++;
    }
    IDX_TOP_STACK(*S)--;
}

/*INPUT/OUTPUT STACK*/
void readStack(Stack*s)
{
    /*KAMUS LOKAL*/

    /*ALGORITMA*/
    CreateStack(s);
    ADVWORD();
    CAPACITY_STACK(*s) = wordToInt(currentWord);
    ADVCHAR(); /* Membaca baris berikutnya */

}

void writeStack(Stack s)
{
     printfFile("%d\n", CAPACITY_STACK(s));
}

/*UNDO REDO SIMULATOR*/
Stack undo(Stack * S, ElTypeStack* X)
/*Membatalkan command yang dilakukan dan mengembalikan*/
/*state aplikasi sebelum command tersebut*/
{
    PopStack(&S, &X);
}

Stack redo(Stack * S, ElTypeStack X)
/*Membatalkan command undo pada Stack S*/
{
    PushStack(&S, X);
}