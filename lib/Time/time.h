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

/* Membentuk sebuah TIME dari komponen-komponennya yang valid */
void createTime (Time * T, int DD, int HH, int MM);
/* Prekondisi : DD, MM, SS valid untuk membentuk TIME */
/* I.S T sembarang */
/* F.S T terdefinisi dengan DD,MM,SS valid*/

/* Menulis nilai setiap komponen T ke layar dalam format DD.HH.MM*/
void tulisTime (Time T);
/* I.S. : T sembarang */
/* F.S. : Nilai T ditulis dg format DD.HH.MM */

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

/* Menampilkan informasi waktu pada layar*/
void displayTime (Time T);

/* display time format (dd hari mm jam mm menit)*/
void displayTime1(Time T);


#endif
