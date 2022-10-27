#ifndef STACK_H
#define STACK_H

#include "../utility/boolean.h"
//#include "../Simulator/simulator.h"
//#include "../LinkedList/list_linked.h"
#include <stdio.h>
#include <stdlib.h>
#define IDX_UNDEF_STACK -1

typedef int infotype;
typedef int address;

typedef Simulator ElTypeStack;
typedef struct { 
  ElTypeStack* buffer; /* tabel penyimpan elemen */
  int idxTop;              /* alamat TOP: elemen puncak */
  int capacity;            /* kapasitas */
} Stack;

/*SELEKTOR*/
#define Top(S) (S).TOP
#define InfoTop(S) (S).T[(S).TOP]

/* ********* AKSES (Selektor) ********* */
/* akses elemen Stack s: */
#define BUFFER_STACK(s) (s).buffer
#define IDX_TOP_STACK(s) (s).idxTop
#define CAPACITY_STACK(s) (s).capacity
#define TOP_STACK(s) (s).buffer[(s).idxTop]

/*KONSTRUKTOR*/
void CreateStack(Stack *S);
/* I.S. sembarang; */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxEl */
/* jadi indeksnya antara 0.. MaxEl */
/* Ciri stack kosong : TOP bernilai Nil */

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsEmptyStack(Stack S);
/* Mengirim true jika Stack kosong: lihat definisi di atas */
boolean IsFullStack(Stack S);
/* Mengirim true jika tabel penampung nilai elemen stack penuh */

void PushStack(Stack * S, infotype X);
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */

void PopStack(Stack * S, infotype* X);
/* Menghapus X dari Stack S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */

void deleteAtStack(Stack* s, int idx, ElTypeStack* val);;
/* I.S. s tidak mungkin kosong dan idx terdefinisi */
/* F.S. val adalah nilai elemen ke idx yang lama */

int lenStack(Stack s);
/*Mengirimkan jumlah elemen pada stack*/

void deleteAtStack(Stack* s, int idx, ElTypeStack* val);

/*INPUT/OUTPUT STACK*/
void readStack(Stack*s);
/* Membaca Stack S dari file config lalu mengisi nilainya */
/* I.S. Stack s sembarang */
/* F.S. Stack s terdefinisi dengan nilai kapasitas dari file config */

void writeStack(Stack s);
/* Menulis isi Stack s pada file config */
/* I.S. Stack s terdefinisi */
/* F.S. Capacity Stack s ditulis di dalam file config */

Stack undo(Stack * S, ElTypeStack* X);
/*Membatalkan command yang dilakukan dan mengembalikan*/
/*state aplikasi sebelum command tersebut*/

Stack redo(Stack * S, ElTypeStack X);
/*Membatalkan command undo pada Stack S*/

#endif
