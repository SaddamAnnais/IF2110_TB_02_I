#include "../utility/boolean.h"
#include "time.h"
#include <stdio.h>

/* *** Konstruktor: Membentuk sebuah TIME dari komponen-komponennya *** */
void createTime (Time * T, int DD, int HH, int MM){
/* Membentuk sebuah TIME dari komponen-komponennya yang valid */
/* Prekondisi : DD, MM, SS valid untuk membentuk TIME */
    Day(*T) = DD;
    Hour(*T) = HH;
    Minute(*T) = MM;
}

void tulisTime (Time T){
/* I.S. : T sembarang */
/* F.S. : Nilai T ditulis dg format DD.HH.MM */
/* Proses : menulis nilai setiap komponen T ke layar dalam format DD.HH.MM */ 
    printf("%d.%02d.%02d", Day(T),Hour(T),Minute(T));
}

int timeToMinute (Time T){
/* Mengembalikan konversi Time menjadi Minute */
    return 1440*Day(T) + 60*Hour(T) + Minute(T);
}

Time minuteToTime (int N){
/* Mengembalikan konversi Detik ke Time */
    Time T;
    Day(T) = N / 1440;
    Hour(T) = (N % 1440) / 60;
    Minute(T) = N % 60;
    return T;
}

void incMinute (Time *T){
/* Mengirim 1 menit setelah T dalam bentuk Time */
    incNMinute(T,1);
}

void incNMinute(Time *T, int N){
/* Mengirim N menit setelah T dalam bentuk Time */
    int MM;
    MM = timeToMinute(*T)+N;
    *T = minuteToTime(MM);
}

void decMinute (Time *T){
/* Mengirim 1 menit sebelum T dalam bentuk Time */
    decNMinute(T,1);
}

void decNMinute (Time *T, int N){
/* Mengirim N menit sebelum T dalam bentuk Time */
    int MM;
    MM = timeToMinute(*T)-N;
    if (MM<0) MM=0;
    *T = minuteToTime(MM);
}