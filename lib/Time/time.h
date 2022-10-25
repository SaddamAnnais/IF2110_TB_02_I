#ifndef TIME_H
#define TIME_H

#include "boolean.h"

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

int timeToMinute (Time T);
/* Mengembalikan konversi Time menjadi Minute */

Time minuteToTime (int N); 
/* Mengembalikan konversi Detik ke Time */

void incMinute (Time *T);
/* Mengirim 1 menit setelah T dalam bentuk Time */

void incNMinute(Time *T, int N);
/* Mengirim N menit setelah T dalam bentuk Time */

void decMinute (Time *T);
/* Mengirim 1 menit sebelum T dalam bentuk Time */

void decNMinute (Time *T, int N);
/* Mengirim N menit sebelum T dalam bentuk Time */



#endif
