#ifndef TIME_H
#define TIME_H

#include "../utility/boolean.h"

/* *** Definisi TYPE TIME <DD:HH:MM> *** */
typedef struct { 
	int DD;
	int HH; /* integer [0..23] */
	int MM; /* integer [0..59] */
} Time;

/* *** Notasi Akses: selektor TIME *** */
#define Day(T) (T).DD
#define Hour(T) (T).HH
#define Minute(T) (T).MM

/* *** Konstruktor: Membentuk sebuah TIME dari komponen-komponennya *** */
void createTime (Time * T, int DD, int HH, int MM);
/* Membentuk sebuah TIME dari komponen-komponennya yang valid */
/* Prekondisi : DD, MM, SS valid untuk membentuk TIME */

void tulisTime (Time T);
/* I.S. : T sembarang */
/* F.S. : Nilai T ditulis dg format DD.HH.MM */
/* Proses : menulis nilai setiap komponen T ke layar dalam format DD.HH.MM */ 

/* Mengembalikan konversi Time menjadi Minute */
int timeToMinute (Time T);

/* Mengembalikan konversi Detik ke Time */
Time minuteToTime (int N); 

/* Mengirim N menit setelah T dalam bentuk Time */
void incMinute (Time *T);

/* Mengirim N menit setelah T dalam bentuk Time */
void incNMinute(Time *T, int N);

/* Mengirim 1 menit sebelum T dalam bentuk Time */
void decMinute (Time *T);

/* Mengirim N menit sebelum T dalam bentuk Time */
void decNMinute (Time *T, int N);

/* T maju, elemen waktu pada Inventory I dan Delivery D berkurang*/
void timePass(int mm, Time *T, Inventory *I, Delivery *D, int* *invNotif, int* *delivNotif);
// I.S mm,T,I,D,invNotif,delivNotif terdefinisi
// F.S T maju sebanyak mm menit, elemen waktu pada Inventory I dan Delivery D berkurang sebanyak mm menit, dan elemen time yang <0 dihapus 

// Memajukan time sebanyak input pengguna
void wait(Time *T, Inventory *I, Delivery *D, int* *invNotif, int* *delivNotif);
// I.S mm,T,I,D,invNotif,delivNotif terdefinisi
// F.S T, I, D, invNotif, delivNotif berubah sesuai timePass()




#endif
