/* File : prioqueuetime.h */
/* Definisi ADT Priority Queue Time dengan representasi array secara eksplisit dan alokasi dinamik */
/* Model Implementasi Versi I*/
/* Elemen queue terurut membesar berdasarkan elemen time */

#ifndef prioqueuetime_H
#define prioqueuetime_H

#include "../utility/boolean.h"

#define Nil -1
/* Konstanta untuk mendefinisikan address tak terdefinisi */

/* Definisi elemen dan address */
typedef struct {
    int time;  /* dalam satuan menit */
    int id;  /* elemen makanan sementara berupa char, akan diganti dengan ADT Makanan*/
} infotype;

typedef int address;   /* indeks tabel */
/* Contoh deklarasi variabel bertype PrioQueueTime : */
/* Versi I : tabel dinamik, Head dan Tail eksplisit, ukuran disimpan */
typedef struct {
    infotype * T;   /* tabel penyimpan elemen */
    address HEAD;  /* alamat elemen pertama */
    address TAIL;  /* alamat elemen terakhir */
    int MaxEl;     /* Max elemen queue */
} PrioQueueTime;
/* Definisi PrioQueueTime kosong: HEAD=Nil; TAIL=Nil. */
/* Catatan implementasi: T[0] tidak pernah dipakai */

/* ********* AKSES (Selektor) ********* */
/* Jika e adalah infotype dan Q adalah PrioQueueTime, maka akses elemen : */
#define Time(e)     (e).time    // time infoType
#define Id(e)       (e).id      // id infoType
#define Head(Q)     (Q).HEAD    // index head
#define Tail(Q)     (Q).TAIL    // index tail
#define InfoHead(Q) (Q).T[(Q).HEAD]     // info head
#define InfoTail(Q) (Q).T[(Q).TAIL]     // info tail
#define MaxEl(Q)    (Q).MaxEl   // max elemen yang ditampung
#define Elmt(Q,i)   (Q).T[(i)]  // get Elmt index i dari q
#define Buffer(Q)   (Q).T       // buffer dari Q (tipe data InfoType)

/* ********* Prototype ********* */
boolean isEmpty (PrioQueueTime Q);
/* Mengirim true jika Q kosong: lihat definisi di atas */
boolean isFull (PrioQueueTime Q);
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak MaxEl */
int NBElmt (PrioQueueTime Q);
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */

/* *** Kreator *** */
void makeEmpty (PrioQueueTime * Q, int Max);
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb: */
/* Jika alokasi berhasil, Tabel memori dialokasi berukuran Max */

/* *** Destruktor *** */
void deAlokasi(PrioQueueTime * Q);
/* Proses: Mengembalikan memori Q */
/* I.S. Q pernah dialokasi */
/* F.S. Q menjadi tidak terdefinisi lagi, MaxEl(Q) diset 0 */

/* *** Primitif Add/Delete *** */
void enqueue (PrioQueueTime * Q, infotype X);
/* Proses: Menambahkan X pada Q dengan aturan priority queue, terurut membesar berdasarkan time */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X disisipkan pada posisi yang tepat sesuai dengan prioritas */

void dequeue (PrioQueueTime * Q, infotype * X);
/* Proses: Menghapus X pada Q dengan aturan FIFO */
/* I.S. Q tidak mungkin kosong */
/* F.S. Elemen head di keluarkan, semua elemen bergeser ke kiri 1. 
Index head tetap di 0 dan index tail = tail - 1. Mungkin menjadi Q kosong*/

/* Operasi Tambahan */
void printPrioQueue (PrioQueueTime Q);
/* Mencetak isi queue Q ke layar */
/* I.S. Q terdefinisi, mungkin kosong */
/* F.S. Q tercetak ke layar dengan format:
<id-0, time-0>; <id-1, time-1>; ... 
*/

void setInfotype(infotype *val, int id, int time);
// set elemen infotype

void growPrioQueue(PrioQueueTime *Q, int num);
// ruang penyimpanan pada Q bertambah sebesar num

void shrinkPrioQueue(PrioQueueTime *Q, int num);
// ruang penyimpanan pada Q berkurang sebesar num

boolean isIdInQ(PrioQueueTime Q, int id);
// menghasilkan true jika suatu id makanan/bahan berada di Q 

void delIdFromQ(PrioQueueTime *Q, int id);
// Id makanan/bahan ada di Q. Menghapus elemen id pertama yang muncul dari Q
#endif
