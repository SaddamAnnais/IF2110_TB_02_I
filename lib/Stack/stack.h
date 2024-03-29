#ifndef STACK_H
#define STACK_H

#include "../utility/boolean.h"
#include "../Simulator/simulator.h"
#include "../Delivery/delivery.h"
#include "../Inventory/inventory.h"
#include "../Time/time.h"
#include "../Peta/peta.h"
#include "../ADT Matrix/matrix.h"
#include "../parser/wordmachine.h"
#include "../parser/charmachine.h"
#include "../priorityQueueDin/prioqueuedin.h"

#include <stdio.h>
#include <stdlib.h>

#define IDX_UNDEF_STACK -1
#define CAPACITY_STACK 100

/* Implementasi penyimpanan statik sehinnga undo dapat dilakukan sebanyak CAPACITY_STACK */

typedef int Notif[2][100];

typedef struct {
  Simulator simul;      /* simulator */
  Delivery deliv;       /* delivery */
  Time time;            /* time */
  Inventory inv;        /* inventory*/
  Notif alurMaju;
  Notif alurMundur;
} ElTypeStack;

/* akses ElTypeStack e: */
#define SIMULATOR_STACK(e)       (e).simul
#define DELIVERY_STACK(e)        (e).deliv
#define TIME_STACK(e)            (e).time
#define INVENTORY_STACK(e)       (e).inv
#define NOTIF_MAJU_STACK(e)      (e).alurMaju
#define NOTIF_MUNDUR_STACK(e)    (e).alurMundur   

typedef struct { 
  ElTypeStack buffer[CAPACITY_STACK]; /* tabel penyimpan elemen */
  int idxTop;                         /* alamat TOP: elemen puncak */
} Stack;

/* ********* AKSES (Selektor) ********* */
/* akses elemen Stack s: */
#define ELMT_STACK(s, i) (s).buffer[i]
#define IDX_TOP_STACK(s) (s).idxTop
#define TOP_STACK(s)     (s).buffer[(s).idxTop]

/*KONSTRUKTOR*/
void CreateStack(Stack *S);
/* I.S. S sembarang; */
/* F.S. Membuat sebuah stack S yang kosong */
/* Ciri stack kosong : idxTop bernilai IDX_UNDEF_STACK */

void CreateNotif(Notif *elmt, int notif[2][100]);
/* I.S. elmt sembarang; */
/* F.S. elmt terdefinisi sesuai input */

void CreateElTypeStack(ElTypeStack *elmt, Simulator S, Delivery D, Time t, Inventory I, int notif[2][100]);
/* I.S. elmt sembarang; */
/* F.S. elmt memiliki value sesuai parameter */
/* Ciri stack kosong : idxTop bernilai IDX_UNDEF_STACK */

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsEmptyStack(Stack S);
/* Mengirim true jika Stack kosong: lihat definisi di atas */

boolean IsFullStack(Stack S);
/* Mengirim true jika tabel penampung nilai elemen stack penuh */

void PushStack(Stack *S, ElTypeStack X);
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */

void PopStack(Stack *S, ElTypeStack *X);
/* Menghapus X dari Stack S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */

int lenStack(Stack s);
/* Mengirimkan jumlah elemen pada stack */

void printStack(Stack s);
/* I.S. S terdefinisi, bisa kosong */
/* F.S. Output stack dengan format <ORDINAT_ELEMEN0, ABSIS_ELEMEN0>;<ORDINAT_ELEMEN1, ABSIS_ELEMEN1>;... */

void makeNotifMundur(Stack *S);
/* I.S. S terdefinisi, bisa kosong */
/* F.S. Notif alurMundur memiliki 1 state lebih mundur dari Notif alurMaju*/

#endif
