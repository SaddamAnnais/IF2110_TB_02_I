#include <stdio.h>
#include <stdlib.h>
#include "prioqueuedin.h"

/* ********* Prototype ********* */
boolean isEmpty (PrioQueueTime Q)
/* Mengirim true jika Q kosong, Q kosong memiliki index head Nil dan index tail Nil */
{
    return (Head(Q) == Nil && Tail(Q) == Nil);
}

boolean isFull (PrioQueueTime Q)
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak MaxEl */
{
    return (NBElmt(Q) == MaxEl(Q));
}

int NBElmt (PrioQueueTime Q)
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */
{
    if (isEmpty(Q)) {
        return 0;
    }
    else {
        return Tail(Q) - Head(Q) + 1;
    }
}

/* *** Kreator *** */
void makeEmpty (PrioQueueTime * Q, int Max)
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb: */
/* Jika alokasi berhasil, Tabel memori dialokasi berukuran Max */
{
    Head(*Q) = Nil;
    Tail(*Q) = Nil;
    Buffer(*Q) = (infotype*)malloc(Max * sizeof(infotype)); // Alokasi buffer
    MaxEl(*Q) = Max;
}

/* *** Destruktor *** */
void deAlokasi(PrioQueueTime * Q)
/* Proses: Mengembalikan memori Q */
/* I.S. Q pernah dialokasi */
/* F.S. Q menjadi tidak terdefinisi lagi, MaxEl(Q) diset 0 */
{
    MaxEl(*Q) = 0;
    Head(*Q) = Nil;
    Tail(*Q) = Nil;
    free(Buffer(*Q));   // Dealokasi buffer
}

/* *** Primitif Add/Delete *** */
void enqueue (PrioQueueTime * Q, infotype X)
/* Proses: Menambahkan X pada Q dengan aturan priority queue, terurut membesar berdasarkan time */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X disisipkan pada posisi yang tepat sesuai dengan prioritas */
{
    int idxInsert = 0;
    if (isEmpty(*Q)) {
        Head(*Q) = 0;
        Tail(*Q) = 0;
        Elmt(*Q, 0) = X;
    }
    else {
        if ((MaxEl(*Q)-NBElmt(*Q))<20) {
            growPrioQueue(Q, 20);
        }

        while (idxInsert<=Tail(*Q) && Time(Elmt(*Q, idxInsert))<=Time(X)) {       // mendapatkan index untuk disisipkan
            idxInsert++;
        }
        for (int i = Tail(*Q); i>=idxInsert; i--) {  // menggeser elemen ke kanan sebanyak 1 dari idxInsert
            Elmt(*Q, i+1) = Elmt(*Q, i);
        }
        Elmt(*Q, idxInsert) = X; // memasukkan X di idxInsert
        Tail(*Q)++;
    }
}

void dequeue (PrioQueueTime * Q, infotype * X)
/* Proses: Menghapus X pada Q dengan aturan FIFO */
/* I.S. Q tidak mungkin kosong */
/* F.S. Elemen head di keluarkan, semua elemen bergeser ke kiri 1. 
Index head tetap di 0 dan index tail = tail - 1. Mungkin menjadi Q kosong*/
{
    *X = InfoHead(*Q);
    if (NBElmt(*Q)==1) {
        Head(*Q) = Nil;
        Tail(*Q) = Nil;
    }
    else {
        if ((MaxEl(*Q)-NBElmt(*Q))>40) {
            shrinkPrioQueue(Q, 20);
        }

        for (int i = 0; i<Tail(*Q); i++) {
           Elmt(*Q, i) = Elmt(*Q, i+1);
        }
        Tail(*Q)--;
    }
    
}

/* Operasi Tambahan */
void printPrioQueue (PrioQueueTime Q)
/* Mencetak isi queue Q ke layar */
/* I.S. Q terdefinisi, mungkin kosong */
/* F.S. Q tercetak ke layar dengan format:
<id-0, time-0>; <id-1, time-1>; ... 
*/
{
    if (!isEmpty(Q)) {
        printf("<%d, %d>", Id(Elmt(Q, 0)), Time(Elmt(Q, 0)));
        for (int i = 1; i<=Tail(Q); i++) {
            printf("; <%d, %d>", Id(Elmt(Q, i)), Time(Elmt(Q, i)));
        }
    }
    printf("\n");
}

void setInfotype(infotype *val, int id, int time)
// set elemen infotype
{
    Time(*val) = time;
    Id(*val) = id;
}

void growPrioQueue(PrioQueueTime *Q, int num)
// ruang penyimpanan pada Q bertambah sebesar num 
{
    int i;
    PrioQueueTime tempQ;

    //printPrioQueue(*Q);
    makeEmpty(&tempQ, MaxEl(*Q)+num);
    //printPrioQueue(*Q);
    Head(tempQ) = Head(*Q);
    Tail(tempQ) = (Tail(*Q)>MaxEl(tempQ)-1)?  MaxEl(tempQ)-1 :  Tail(*Q);
    for (int i = 0; i<=Tail(tempQ); i++) {
        Elmt(tempQ, i) = Elmt(*Q, i);
    }

    deAlokasi(Q);
    Buffer(*Q) = Buffer(tempQ);
    MaxEl(*Q) = MaxEl(tempQ);
    Head(*Q) = Head(tempQ);
    Tail(*Q) = Tail(tempQ);
}

void shrinkPrioQueue(PrioQueueTime *Q, int num)
// ruang penyimpanan pada Q berkurang sebesar num 
{
    growPrioQueue(Q, num*(-1));
}

boolean isIdInQ(PrioQueueTime Q, int id)
// menghasilkan true jika suatu id makanan/bahan berada di Q
{
    if (!isEmpty(Q)) {
        for (int i = 0; i<=Tail(Q); i++) {
            //printf("%d", Id(Elmt(Q, i)));
            if (Id(Elmt(Q, i))==id) {
                return true;
            }
        }
        return false;
    }
    else {
        return false;
    }
}


void delIdFromQ(PrioQueueTime *Q, int id)
// Id makanan/bahan ada di Q. Menghapus elemen id pertama yang muncul dari Q
{
    int idx=0;
    while (id != Id(Elmt(*Q, idx))) {     // mendapatkan index dari id dalam Q
        idx++;
    }
    //printf("%d", idx);

    for (int i = idx; i<Tail(*Q); i++) {
        Elmt(*Q, i) = Elmt(*Q, i+1);
    }
    Tail(*Q)--;
}

void timePass(PrioQueueTime *Q, int mnt)
// time berkurang sebanyak mnt menit pada semua elmt di Q
{
    for (int i = 0; i<=Tail(*Q); i++) {
        Time(Elmt(*Q, i)) = Time(Elmt(*Q, i)) - mnt;
    }
}

int keepPosTime(PrioQueueTime *Q)
// menyimpan elmt yang memiliki time bernilai positif (menghapus elmt yang <= 0)
// mengembalikan list of int yang berisi id apa saja yang dihapus
{
    int listId[100], idx=0;
    for (int i = 0; i<100; i++) {
        listId[i] = Nil;
    }

    for (int i = 0; i<Tail(*Q); i++) {
        if (Time(Elmt(*Q, i))<=0) {
            listId[idx] = Id(Elmt(*Q, i));
            delIdFromQ(Q, Id(Elmt(*Q, i)));
            i = 0;           
        }
    }

    return listId;
}

void notif(int listId[], boolean inventory)
// mengoutput notif makanan/bahan kadaluarsa atau delivery bahan sampai
// argumen inventory bernilai true untuk list bahan/makanan kadaluarsa dan 
// bernilai negatif untuk list delivery bahan sampai   
{
    printf("Notifikasi: ");
    if (listId[0]==Nil) {
        printf("-\n");
    } 
    else {
        printf("\n");
        for (int i = 0; i<100 && listId[i]!= Nil; i++) {
            if (inventory) {
                printf("    %d. <%d> kadaluwarsa :(\n", i+1, listId[i]);
            }
            else {
                printf("    %d. <%d> sudah diterima BNMO! :D\n", i+1, listId[i]);
            }
        }
    }
}