/* File : command.h */
/* fungsi/prosedur untuk menjalankan command yang ada*/

#include "../Simulator/simulator.h"
#include "../Time/time.h"
#include "../Peta/peta.h"
#include "../Inventory/inventory.h"
#include "../Delivery/delivery.h"
#include "../Makanan/listmakanan.h"
#include "../Stack/stack.h"
#include "../Resep/resep.h"
#include "../Kulkas/kulkas.h"

/* T maju, elemen waktu pada Inventory I dan Delivery D berkurang*/
void timePass(int mm, Time *T, Inventory *I, Delivery *D, int (*notif)[100], ListMakanan lM);
// I.S mm,T,I,D,notif terdefinisi
// F.S T maju sebanyak mm menit, elemen waktu pada Inventory I dan Delivery D berkurang sebanyak mm menit, dan elemen time yang <0 dihapus 

/* Menambahkan makanan yang telah sampai ke Inventory*/
void delivToInv(Delivery D, Inventory *I,ListMakanan lM);
// I.S notif, I, lM terdefinisi
// F.S makanan D yang memiliki elemen time <= 0 akan masuk Inventory


// Memajukan time sebanyak input pengguna
void Wait(Time *T, Inventory *I, Delivery *D, int (*notif)[100], boolean *isValid, ListMakanan lM);
// I.S mm,T,I,D,invNotif,delivNotif terdefinisi
// F.S T, I, D, invNotif, delivNotif berubah sesuai timePass()

/* Menggerakan simulator sesuai input user, jika simulator berpindah posisi, waktu bertambah 1 menit */
void Move(Peta *p, Simulator *s,Time *T, Inventory *I, Delivery *D, int (*notif)[100],boolean *isValid, ListMakanan lM);
// I.S. Simulator berada pada posisi (x, y)
// F.S. Jika pergerakan valid, simulator sekarang berada pada posisi baru dan semua elemen waktu maju

/* Menampilkan bahan makanan yang tersedia dalam aplikasi dan informasinya*/
void Catalog(ListMakanan lM);

void undo(Stack *UndoSt, Stack *RedoSt, Peta *P, Simulator *S, Delivery *D, Time *T, Inventory *I, Notif *notif);
/* I.S. S terdefinisi, mungkin kosong*/
/* F.S  S ter-pop atau kosong. 
        X berisi Top stack jika S awal tidak kosong */

void redo(Stack *UndoSt, Stack *RedoSt, Peta *P, Simulator *S, Delivery *D, Time *T, Inventory *I, Notif *notif);
/* I.S. S terdefinisi, mungking kosong */
/* F.S  S ter-push jika tedapat elemen redo. 
        S tidak ter-push jika redo habis */
        
/* Melakukan pemesanan makanan */
void Buy(Peta *p, Simulator *s, ListMakanan lM, Delivery *D, Time *T, Inventory *I, int (*notif)[100], boolean *isValid);

/* Melihat Delivery List */
void PrintDelivery(ListMakanan lM, Delivery D);

/* Melihat makanan yang dimiliki di Inventory */
void PrintInventory(ListMakanan lM, Inventory I);

void displayNotif(int notif[2][100], boolean alurMaju, ListMakanan lM);
/* Proses: Mengoutput notif makanan/bahan kadaluarsa atau delivery bahan sampai.*/
/* I.S. listId terdefinisi. Elemen bernilai Nil dianggap sebagai value kosong (tidak dioutput)*/
/* F.S. Output notif makanan/bahan kadaluarsa atau delivery bahan sampai*/

// void undoNotif(StackNotif *UndoStNotif, StackNotif *RedoStNotif, Notif *notif);
// /*Membatalkan command yang dilakukan dan mengembalikan*/
// /*state notif aplikasi sebelum command tersebut*/

// void redoNotif(StackNotif *UndoStNotif, StackNotif *RedoStNotif, Notif *notif);
// /*Membatalkan command undo pada notif aplikasi*/

/* Melakukan operasi pengolahan makanan */
void PengolahanMakanan(Word opWord, char* op, ListMakanan listMakanan, Inventory* inventory, Resep resep, Time* time, Delivery* delivery, int (*notif)[100], Peta peta, Simulator simulator, boolean *isValid);
// I.S. Semua parameter terdefinisi
// F.S. Jika operasi berhasil, maka isi dari inventory simulator akan berubah

/* Membuka kulkas */
void OpenKulkas(ListMakanan listmakanan, Inventory* inventory, Kulkas* kulkas);
// I.S. Semua parameter terdefinisi
// F.S. Menambahkan atau mengeluarkan makanan dari kulkas
