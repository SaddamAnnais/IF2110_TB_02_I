#include "stack.h"
#include "../parser/wordmachine.h"

/*KONSTRUKTOR*/
void CreateStack(Stack *S)
/* I.S. sembarang; */
/* F.S. Membuat Stack S kosong dengan index top bernilai IDX_UNDEF_STACK */
{
    IDX_TOP_STACK(*S) = IDX_UNDEF_STACK;
}

void CreateNotif(Notif *elmt, int notif[2][100]) { 
/* I.S. elmt sembarang; */
/* F.S. elmt terdefinisi sesuai input */
    for (int i = 0; i<2; i++) {
        for (int j = 0; j<100; j++) {
            (*elmt)[i][j] = notif[i][j];
       }
    }
}

void CreateElTypeStack(ElTypeStack *elmt, Simulator S, Delivery D, Time t, Inventory I, int notif[2][100])
/* I.S. elmt sembarang; */
/* F.S. elmt memiliki value sesuai parameter */
/* Ciri stack kosong : idxTop bernilai IDX_UNDEF_STACK */
{
    SIMULATOR_STACK(*elmt) = S;
    DELIVERY_STACK(*elmt) = copyQ(D);
    TIME_STACK(*elmt) = t;
    INVENTORY_STACK(*elmt) = copyQ(I);
    CreateNotif(&NOTIF_MAJU_STACK(*elmt), notif);
}

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsEmptyStack(Stack S)
/* Mengirim true jika Stack kosong: lihat definisi di atas */
{
    return (IDX_TOP_STACK(S) == 0);
}

boolean IsFullStack(Stack S)
/* Mengirim true jika tabel penampung nilai elemen stack penuh */
{
    return (IDX_TOP_STACK(S) == CAPACITY_STACK - 1);
}

void PushStack(Stack * S, ElTypeStack X)
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong*/
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */
{
    /*KAMUS LOKAL*/

    /* ALGORITMA */
    if (IsFullStack(*S)) {
        for (int i = 0; i < CAPACITY_STACK-1 ; i++) {
            ELMT_STACK(*S, i) = ELMT_STACK(*S, i+1); 
        }
        TOP_STACK(*S) = X;
    }
    else {
        IDX_TOP_STACK(*S)++;
        TOP_STACK(*S) = X;
    }
}

/* ************ Menghapus sebuah elemen Stack ************ */
void PopStack(Stack *S, ElTypeStack *X)
/* Menghapus X dari Stack S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */
{
    // if (IDX_TOP_STACK(*S) == 0) {
        *X = TOP_STACK(*S);
        IDX_TOP_STACK(*S)--;    
    // }
    // else {
    //     IDX_TOP_STACK(*S)--;
    //     *X = TOP_STACK(*S);
    // }
}

int lenStack(Stack s)
/*Mengirimkan jumlah elemen pada stack*/
{
    return IDX_TOP_STACK(s) + 1;
}

void printStack(Stack s) 
/* I.S. S terdefinisi, bisa kosong */
/* F.S. Output stack dengan format <ORDINAT_ELEMEN0, ABSIS_ELEMEN0>;<ORDINAT_ELEMEN1, ABSIS_ELEMEN1>;... */
{
    if (IsEmptyStack(s)) {
        printf("< >");
    }

    for (int i = 0; i<lenStack(s); i++) {
        printf("<%d, %d>", ORDINAT(Lokasi(SIMULATOR_STACK(ELMT_STACK(s, i)))), ABSIS(Lokasi(SIMULATOR_STACK(ELMT_STACK(s, i))))); 
    }
}

void makeNotifMundur(Stack *S) {
/* I.S. S terdefinisi, bisa kosong */
/* F.S. elemen mundur terdefinisi seperti maju*/
    for (int i = 1; i<CAPACITY_STACK && i<=IDX_TOP_STACK(*S); i++) {
        for (int j = 0; j<2; j++) {
            for (int k = 0; k<100; k++) {
                NOTIF_MUNDUR_STACK(ELMT_STACK(*S, i-1))[j][k] = NOTIF_MAJU_STACK(ELMT_STACK(*S, i))[j][k];
            }
        }
    }
}
