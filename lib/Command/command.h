/* File : command.h */
/* fungsi/prosedur untuk menjalankan command yang ada*/

#include "../Simulator/simulator.h"
#include "../Time/time.h"
#include "../Peta/peta.h"
#include "../Inventory/inventory.h"
#include "../Delivery/delivery.h"
#include "../Makanan/listmakanan.h"
#include "../Stack/stack.h"


/* T maju, elemen waktu pada Inventory I dan Delivery D berkurang*/
void timePass(int mm, Time *T, Inventory *I, Delivery *D, int (*notif)[100]);
// I.S mm,T,I,D,invNotif,delivNotif terdefinisi
// F.S T maju sebanyak mm menit, elemen waktu pada Inventory I dan Delivery D berkurang sebanyak mm menit, dan elemen time yang <0 dihapus 

// Memajukan time sebanyak input pengguna
void Wait(Time *T, Inventory *I, Delivery *D, int (*notif)[100]);
// I.S mm,T,I,D,invNotif,delivNotif terdefinisi
// F.S T, I, D, invNotif, delivNotif berubah sesuai timePass()

/* Menggerakan simulator sesuai input user, jika simulator berpindah posisi, waktu bertambah 1 menit */
void Move(Peta *p, Simulator *s,Time *T, Inventory *I, Delivery *D, int (*notif)[100]);
// I.S. Simulator berada pada posisi (x, y)
// F.S. Jika pergerakan valid, simulator sekarang berada pada posisi baru dan semua elemen waktu maju

/* Menampilkan bahan makanan yang tersedia dalam aplikasi dan informasinya*/
void Catalog(ListMakanan lM);

void undo(Stack *UndoSt, Stack *RedoSt, ElTypeStack *X, Peta *P, Simulator *S, Delivery *D, Time *T, Inventory *I);
/* I.S. S terdefinisi, mungkin kosong*/
/* F.S  S ter-pop atau kosong. 
        X berisi Top stack jika S awal tidak kosong */

void redo(Stack *UndoSt, Stack *RedoSt, ElTypeStack *X, Peta *P, Simulator *S, Delivery *D, Time *T, Inventory *I);
/* I.S. S terdefinisi, mungking kosong */
/* F.S  S ter-push jika tedapat elemen redo. 
        S tidak ter-push jika redo habis */
        
/* Melakukan pemesanan makanan */
void Buy(Peta *p, Simulator *s, ListMakanan lM, Delivery *D, Time *T, Inventory *I, int (*notif)[100]);
