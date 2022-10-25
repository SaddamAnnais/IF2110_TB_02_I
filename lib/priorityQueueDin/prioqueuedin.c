#include <stdio.h>
#include <stdlib.h>
#include "prioqueuedin.h"

/* ********* Prototype ********* */
boolean isEmptyQ (PrioQueueTime Q)
/* Mengirim true jika Q kosong, Q kosong memiliki index head Nil dan index tail Nil */
{
    return (HeadQ(Q) == Nil && TailQ(Q) == Nil);
}

boolean isFullQ (PrioQueueTime Q)
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak MaxEl */
{
    return (NBElmtQ(Q) == MaxElQ(Q));
}

int NBElmtQ (PrioQueueTime Q)
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */
{
    if (isEmptyQ(Q)) {
        return 0;
    }
    else {
        return TailQ(Q) - HeadQ(Q) + 1;
    }
}

/* *** Kreator *** */
void makeEmptyQ (PrioQueueTime * Q, int Max)
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk. Tabel memori dialokasi berukuran Max */
{
    HeadQ(*Q) = Nil;
    TailQ(*Q) = Nil;
    BufferQ(*Q) = (infotype*)malloc(Max * sizeof(infotype)); // Alokasi buffer
    MaxElQ(*Q) = Max;
}

/* *** Destruktor *** */
void deAlokasiQ(PrioQueueTime * Q)
/* Proses: Mengembalikan memori Q */
/* I.S. Q pernah dialokasi */
/* F.S. Q menjadi tidak terdefinisi lagi, MaxEl(Q) diset 0 */
{
    MaxElQ(*Q) = 0;
    HeadQ(*Q) = Nil;
    TailQ(*Q) = Nil;
    free(BufferQ(*Q));   // Dealokasi buffer
}

/* *** Primitif Add/Delete *** */
void enqueue (PrioQueueTime * Q, infotype X)
/* Proses: Menambahkan X pada Q dengan aturan priority queue, terurut membesar berdasarkan time */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X disisipkan pada posisi yang tepat sesuai dengan prioritas */
{
    int idxInsert = 0;
    if (isEmptyQ(*Q)) {
        HeadQ(*Q) = 0;
        TailQ(*Q) = 0;
        ElmtQ(*Q, 0) = X;
    }
    else {
        if ((MaxElQ(*Q)-NBElmtQ(*Q))<20) {
            growPrioQueue(Q, 20);
        }

        while (idxInsert<=TailQ(*Q) && Time(ElmtQ(*Q, idxInsert))<=Time(X)) {       // mendapatkan index untuk disisipkan
            idxInsert++;
        }
        for (int i = TailQ(*Q); i>=idxInsert; i--) {  // menggeser elemen ke kanan sebanyak 1 dari idxInsert
            ElmtQ(*Q, i+1) = ElmtQ(*Q, i);
        }
        ElmtQ(*Q, idxInsert) = X; // memasukkan X di idxInsert
        TailQ(*Q)++;
    }
}

void dequeue (PrioQueueTime * Q, infotype * X)
/* Proses: Menghapus X pada Q dengan aturan FIFO */
/* I.S. Q tidak mungkin kosong */
/* F.S. Elemen head di keluarkan, semua elemen bergeser ke kiri 1. 
Index head tetap di 0 dan index tail = tail - 1. Mungkin menjadi Q kosong*/
{
    *X = InfoHeadQ(*Q);
    if (NBElmtQ(*Q)==1) {
        HeadQ(*Q) = Nil;
        TailQ(*Q) = Nil;
    }
    else {
        if ((MaxElQ(*Q)-NBElmtQ(*Q))>40) {
            shrinkPrioQueue(Q, 20);
        }

        for (int i = 0; i<TailQ(*Q); i++) {
           ElmtQ(*Q, i) = ElmtQ(*Q, i+1);
        }
        TailQ(*Q)--;
    }
    
}

/* Operasi Tambahan */
void printPrioQ (PrioQueueTime Q)
/* Mencetak isi queue Q ke layar */
/* I.S. Q terdefinisi, mungkin kosong */
/* F.S. Q tercetak ke layar dengan format:
<id-0, time-0>; <id-1, time-1>; ... 
*/
{
    if (!isEmptyQ(Q)) {
        printf("<%d, %d>", Id(ElmtQ(Q, 0)), Time(ElmtQ(Q, 0)));
        for (int i = 1; i<=TailQ(Q); i++) {
            printf("; <%d, %d>", Id(ElmtQ(Q, i)), Time(ElmtQ(Q, i)));
        }
    }
    printf("\n");
}

void setInfotypeQ(infotype *val, int id, int time)
/* I.S. val sembarang*/
/* F.S. val terdefinisi dengan id dan time sesuai input*/
{
    Time(*val) = time;
    Id(*val) = id;
}

void growPrioQueue(PrioQueueTime *Q, int num)
/* Proses: Ruang penyimpanan pada Q bertambah sebesar num */
/* I.S. Q terdefinisi dengan ukuran tabel penyimpanan sebesar MaxEl*/
/* F.S. Q terdefinisi dengan ukuran tabel penyimpanan sebesar MaxEl + num*/
{
    int i;
    PrioQueueTime tempQ;

    //printPrioQueue(*Q);
    makeEmptyQ(&tempQ, MaxElQ(*Q)+num);
    //printPrioQueue(*Q);
    HeadQ(tempQ) = HeadQ(*Q);
    TailQ(tempQ) = (TailQ(*Q)>MaxElQ(tempQ)-1)?  MaxElQ(tempQ)-1 :  TailQ(*Q);
    for (int i = 0; i<=TailQ(tempQ); i++) {
        ElmtQ(tempQ, i) = ElmtQ(*Q, i);
    }

    deAlokasiQ(Q);
    BufferQ(*Q) = BufferQ(tempQ);
    MaxElQ(*Q) = MaxElQ(tempQ);
    HeadQ(*Q) = HeadQ(tempQ);
    TailQ(*Q) = TailQ(tempQ);
}

void shrinkPrioQueue(PrioQueueTime *Q, int num)
/* Proses: Ruang penyimpanan pada Q berkurang sebesar num */
/* I.S. Q terdefinisi dengan ukuran tabel penyimpanan sebesar MaxEl*/
/* F.S. Q terdefinisi dengan ukuran tabel penyimpanan sebesar MaxEl - num*/
{
    growPrioQueue(Q, num*(-1));
}

boolean isIdInQ(PrioQueueTime Q, int id)
/* Menghasilkan true jika suatu id makanan/bahan berada di Q */ 
{
    if (!isEmptyQ(Q)) {
        for (int i = 0; i<=TailQ(Q); i++) {
            //printf("%d", Id(Elmt(Q, i)));
            if (Id(ElmtQ(Q, i))==id) {
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
/* Proses: elemen pertama yang memiliki id adalah id akan dihapus */
/* I.S. Q terdefinisi, terdapat elemen yang memiliki id adalah id*/
/* F.S. elemen pertama yang memiliki id adalah id dihapus dari Q*/
{
    int idx=0;
    while (id != Id(ElmtQ(*Q, idx))) {     // mendapatkan index dari id dalam Q
        idx++;
    }
    //printf("%d", idx);

    for (int i = idx; i<TailQ(*Q); i++) {
        ElmtQ(*Q, i) = ElmtQ(*Q, i+1);
    }
    TailQ(*Q)--;
}

void timePassQ(PrioQueueTime *Q, int mnt)
/* Proses: setiap elemen time akan berkurang sebesar mnt */
/* I.S. Q terdefinisi*/
/* F.S. semua time elemen berkurang sebesar mnt*/
{
    for (int i = 0; i<=TailQ(*Q); i++) {
        Time(ElmtQ(*Q, i)) = Time(ElmtQ(*Q, i)) - mnt;
    }
}

int *listIdNotPos(PrioQueueTime Q)
/* Mengembalikan array yang berisi list dari elemen yang memiliki time <=0*/
{
    static int listId[100], idx=0;

    for (int i = 0; i<100; i++) {
        listId[i] = Nil;
    }

    for (int i = 0; i<=TailQ(Q); i++) {
        if (Time(ElmtQ(Q, i)) <= 0) {
            listId[idx] = Id(ElmtQ(Q, i));
            idx++;
        }
    }
    return listId;
}

void keepPosTimeQ(PrioQueueTime *Q)
/* Proses: setiap elemen time <= 0 akan dihapus */
/* I.S. Q terdefinisi*/
/* F.S. semua elemen time lebih besar dari 0*/
{
    static int listId[100], i=0;
    for (int i = 0; i<100; i++) {
        listId[i] = Nil;
    }

    do {
        if(Time(ElmtQ(*Q, i))<=0) {
            delIdFromQ(Q, Id(ElmtQ(*Q, i)));
            i = -1;               
        }
        i++;
    } while (i<=TailQ(*Q));
}

void notifQ(int listId[], boolean inventory)
/* Proses: Mengoutput notif makanan/bahan kadaluarsa atau delivery bahan sampai.*/
/* I.S. listId terdefinisi. Elemen bernilai Nil dianggap sebagai value kosong (tidak dioutput)*/
/* F.S. Output notif makanan/bahan kadaluarsa atau delivery bahan sampai*/
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