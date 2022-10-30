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
    int id;    /* elemen makanan sementara berupa char, akan diganti dengan ADT Makanan*/
} infotype;

/* Versi I : tabel dinamik, Head dan Tail eksplisit, ukuran disimpan */
typedef struct {
    infotype * T;   /* tabel penyimpan elemen */
    int HEAD;  /* alamat elemen pertama */
    int TAIL;  /* alamat elemen terakhir */
    int MaxEl;     /* Max elemen queue */
} PrioQueueTime;
/* Definisi PrioQueueTime kosong: HEAD=Nil; TAIL=Nil. */

/* ********* AKSES (Selektor) ********* */
/* Jika e adalah infotype dan Q adalah PrioQueueTime, maka akses elemen : */
#define Time(e)     (e).time    // time infoType
#define Id(e)       (e).id      // id infoType
#define HeadQ(Q)     (Q).HEAD    // index head
#define TailQ(Q)     (Q).TAIL    // index tail
#define InfoHeadQ(Q) (Q).T[(Q).HEAD]     // info head
#define InfoTailQ(Q) (Q).T[(Q).TAIL]     // info tail
#define MaxElQ(Q)    (Q).MaxEl   // max elemen yang ditampung
#define ElmtQ(Q,i)   (Q).T[(i)]  // get Elmt index i dari q
#define BufferQ(Q)   (Q).T       // buffer dari Q (tipe data InfoType)

/* ********* Prototype ********* */
boolean isEmptyQ (PrioQueueTime Q);
/* Mengirim true jika Q kosong. Head = Nil dan Tail = Nil */
boolean isFullQ (PrioQueueTime Q);
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak MaxEl */
int NBElmtQ (PrioQueueTime Q);
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */

/* *** Kreator *** */
void makeEmptyQ (PrioQueueTime * Q, int Max);
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk. Tabel memori dialokasi berukuran Max */

/* *** Destruktor *** */
void deAlokasiQ(PrioQueueTime * Q);
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
void printPrioQ (PrioQueueTime Q);
/* Mencetak isi queue Q ke layar */
/* I.S. Q terdefinisi, mungkin kosong */
/* F.S. Q tercetak ke layar dengan format:
<id-0, time-0>; <id-1, time-1>; ... 
*/

void setInfotypeQ(infotype *val, int id, int time);
/* I.S. val sembarang*/
/* F.S. val terdefinisi dengan id dan time sesuai input*/


void growPrioQueue(PrioQueueTime *Q, int num);
/* Proses: Ruang penyimpanan pada Q bertambah sebesar num */
/* I.S. Q terdefinisi dengan ukuran tabel penyimpanan sebesar MaxEl*/
/* F.S. Q terdefinisi dengan ukuran tabel penyimpanan sebesar MaxEl + num*/


void shrinkPrioQueue(PrioQueueTime *Q, int num);
/* Proses: Ruang penyimpanan pada Q berkurang sebesar num */
/* I.S. Q terdefinisi dengan ukuran tabel penyimpanan sebesar MaxEl*/
/* F.S. Q terdefinisi dengan ukuran tabel penyimpanan sebesar MaxEl - num*/

boolean isIdInQ(PrioQueueTime Q, int id);
/* Menghasilkan true jika suatu id makanan/bahan berada di Q */ 

void delIdFromQ(PrioQueueTime *Q, int id);
/* Proses: elemen pertama yang memiliki id adalah id akan dihapus */
/* I.S. Q terdefinisi, terdapat elemen yang memiliki id adalah id*/
/* F.S. elemen pertama yang memiliki id adalah id dihapus dari Q*/

void timePassQ(PrioQueueTime *Q, int mnt);
/* Proses: setiap elemen time akan berkurang sebesar mnt */
/* I.S. Q terdefinisi*/
/* F.S. semua time elemen berkurang sebesar mnt*/

int *listIdNotPosInv(PrioQueueTime Q);
/* Mengembalikan array yang berisi list dari elemen yang memiliki time <=0*/

int *listIdNotPosDeliv(PrioQueueTime Q);
/* Mengembalikan array yang berisi list dari elemen yang memiliki time <=0*/

void keepPosTimeQ(PrioQueueTime *Q);
/* Proses: setiap elemen time <= 0 akan dihapus */
/* I.S. Q terdefinisi*/
/* F.S. semua elemen time lebih besar dari 0*/

void notifQ(int listId[], boolean inventory);
/* Proses: Mengoutput notif makanan/bahan kadaluarsa atau delivery bahan sampai.*/
/* I.S. listId terdefinisi. Elemen bernilai Nil dianggap sebagai value kosong (tidak dioutput)*/
/* F.S. Output notif makanan/bahan kadaluarsa atau delivery bahan sampai*/

void matIdNotPos(int (*notif)[100],PrioQueueTime I, PrioQueueTime D);
/* Proses: Mengubah notif menjadi matrix yang berisi list id non positif dari Inventory dan Delivery.*/
/* I.S. notif sembarang, I dan D terdefinisi. */
/* F.S. notif berisi list id non positif dari Inventory dan Delivery. Elemen bernilai Nil dianggap sebagai value kosong. */

void displayNotif(int notif[2][100]);
/* Proses: Mengoutput notif makanan/bahan kadaluarsa atau delivery bahan sampai.*/
/* I.S. listId terdefinisi. Elemen bernilai Nil dianggap sebagai value kosong (tidak dioutput)*/
/* F.S. Output notif makanan/bahan kadaluarsa atau delivery bahan sampai*/




#endif
