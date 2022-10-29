#include "time.h"
#include <stdio.h>

/* Membentuk sebuah TIME dari komponen-komponennya yang valid */
void createTime (Time * T, int DD, int HH, int MM){
/* Prekondisi : DD, MM, SS valid untuk membentuk TIME */
/* I.S T sembarang */
/* F.S T terdefinisi dengan DD,MM,SS valid*/
    Day(*T) = DD;
    Hour(*T) = HH;
    Minute(*T) = MM;
}

/* Menulis nilai setiap komponen T ke layar dalam format DD.HH.MM*/
void tulisTime (Time T){
/* I.S. : T sembarang */
/* F.S. : Nilai T ditulis dg format DD.HH.MM */
    printf("%d.%02d.%02d", Day(T),Hour(T),Minute(T));
}

/* Mengembalikan konversi Time menjadi Minute */
int timeToMinute (Time T){
    return 1440*Day(T) + 60*Hour(T) + Minute(T);
}

/* Mengembalikan konversi Time menjadi Minute */
Time minuteToTime (int N){
    Time T;
    Day(T) = N / 1440;
    Hour(T) = (N % 1440) / 60;
    Minute(T) = N % 60;
    return T;
}

/* Mengirim 1 menit setelah T dalam bentuk Time */
void incMinute (Time *T){
    incNMinute(T,1);
}

/* Mengirim N menit setelah T dalam bentuk Time */
void incNMinute(Time *T, int N){
    int MM;
    MM = timeToMinute(*T)+N;
    *T = minuteToTime(MM);
}

/* Mengirim 1 menit sebelum T dalam bentuk Time */
void decMinute (Time *T){
    decNMinute(T,1);
}

/* Mengirim N menit sebelum T dalam bentuk Time */
void decNMinute (Time *T, int N){
    int MM;
    MM = timeToMinute(*T)-N;
    if (MM<0) MM=0;
    *T = minuteToTime(MM);
}

/* Menampilkan informasi waktu pada aplikasi*/
void displayTime(Time T){
    printf("Waktu: ");
    tulisTime(T);
    printf("\n");
}

/* display time format (dd hari mm jam mm menit)*/
void displayTime1(Time T){
    boolean space=false;
    if (Day(T)>0) {
        printf("%d hari",Day(T));
        space=true;
    }
    if (Hour(T)>0) {
        if (space) printf(" ");
        printf("%d jam", Hour(T));
        space=true;
    }
    if (Minute(T)>0){
        if (space) printf(" ");
        printf("%d menit", Minute(T));
    }
    if (timeToMinute(T)==0) printf("0 menit");
}
