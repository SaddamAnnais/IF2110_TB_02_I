/* File: time.c*/

#include "time.h"
#include <stdio.h>
#include <math.h>
     
/* ***************************************************************** */
/* DEFINISI PRIMITIF                                                 */
/* ***************************************************************** */
/* KELOMPOK VALIDASI TERHADAP TYPE                                   */
/* ***************************************************************** */
boolean IsTIMEValid (int H, int M, int S){
/* Mengirim true jika H,M,S dapat membentuk T yang valid */
/* dipakai untuk mentest SEBELUM membentuk sebuah Jam */
	return ((H >= 0 && H <= 23) && (M >= 0 && M <= 59) && (S >=0 && S <= 59));
}

/* *** Konstruktor: Membentuk sebuah TIME dari komponen-komponennya *** */
void CreateTime (TIME * T, int HH, int MM, int SS){
/* Membentuk sebuah TIME dari komponen-komponennya yang valid */
/* Prekondisi : HH, MM, SS valid untuk membentuk TIME */
        Hour(*T) = HH;
        Minute(*T) = MM;
        Second(*T) = SS;
}

/* ***************************************************************** */
/* KELOMPOK BACA/TULIS                                               */
/* ***************************************************************** */
void BacaTIME (TIME * T){
/* I.S. : T tidak terdefinisi */
/* F.S. : T terdefinisi dan merupakan jam yang valid */
/* Proses : mengulangi membaca komponen HH, MM, SS sehingga membentuk T */
/* yang valid. Tidak mungkin menghasilkan T yang tidak valid. */
/* Pembacaan dilakukan dengan mengetikkan komponen HH, MM, SS
   dalam satu baris, masing-masing dipisahkan 1 spasi, diakhiri enter. */
/* Jika TIME tidak valid maka diberikan pesan: "Jam tidak valid", dan pembacaan
   diulangi hingga didapatkan jam yang valid. */
/* Contoh: 
   60 3 4
   Jam tidak valid
   1 3 4
   --> akan terbentuk TIME <1,3,4> */
	int HH, MM, SS;
    scanf("%d %d %d", &HH, &MM, &SS);
    while (! IsTIMEValid(HH, MM, SS)) {
    	printf("Jam tidak valid\n");
    	scanf("%d %d %d", &HH, &MM, &SS);
    }
    CreateTime(T, HH, MM, SS);
}
   
void TulisTIME (TIME T){
/* I.S. : T sembarang */
/* F.S. : Nilai T ditulis dg format HH:MM:SS */
/* Proses : menulis nilai setiap komponen T ke layar dalam format HH:MM:SS
   tanpa karakter apa pun di depan atau belakangnya, termasuk spasi, enter, dll.*/ 

/* ***************************************************************** */
/* KELOMPOK KONVERSI TERHADAP TYPE                                   */
/* ***************************************************************** */
	printf("%d:%d:%d", Hour(T), Minute(T), Second(T));
}
long TIMEToDetik (TIME T){
/* Diberikan sebuah TIME, mengkonversi menjadi jumlah detik dari pukul 0:0:0 */
/* Rumus : detik = 3600*HH + 60*MM + SS */
/* Nilai maksimum = 3600*23+59*60+59 */
  return((Hour(T)*3600 + Minute(T)*60 + Second(T)) % 86400);
}

TIME DetikToTIME (long N){

/* Mengirim  konversi detik ke TIME */
/* Catatan: Jika N >= 86400, maka harus dikonversi dulu menjadi jumlah detik yang 
   mewakili jumlah detik yang mungkin dalam 1 hari, yaitu dengan rumus: 
   N1 = N mod 86400, baru N1 dikonversi menjadi TIME */

/* ***************************************************************** */
/* KELOMPOK OPERASI TERHADAP TYPE                                    */
/* ***************************************************************** */
    /*KAMUS LOKAL*/
    TIME T_DetikToTIME;
    if (N >= 86400){
      N = N % 86400;
    }

	/*ALGORITMA*/
    Hour(T_DetikToTIME) = N/3600;
    Minute(T_DetikToTIME) = (N%3600) / 60;
    Second(T_DetikToTIME) = ((N%3600) % 60) % 60;
    return T_DetikToTIME;
}

/* *** Kelompok Operator Relational *** */
boolean TEQ (TIME T1, TIME T2)
/* Mengirimkan true jika T1=T2, false jika tidak */
{
	return (TIMEToDetik(T1) == TIMEToDetik(T2));
}

boolean TNEQ (TIME T1, TIME T2)
/* Mengirimkan true jika T1 tidak sama dengan T2 */
{
	return (TIMEToDetik(T1) != TIMEToDetik(T2));
}

boolean TLT (TIME T1, TIME T2)
/* Mengirimkan true jika T1<T2, false jika tidak */
{
	return(TIMEToDetik(T1) < TIMEToDetik(T2));
}
boolean TGT (TIME T1, TIME T2)
/* Mengirimkan true jika T1>T2, false jika tidak */
{
	return(TIMEToDetik(T1) > TIMEToDetik(T2));
}

/* *** Operator aritmatika TIME *** */
TIME NextDetik (TIME T)
/* Mengirim 1 detik setelah T dalam bentuk TIME */
{
	return(DetikToTIME(TIMEToDetik(T) + 1));
}
TIME NextNDetik (TIME T, int N)
/* Mengirim N detik setelah T dalam bentuk TIME */
{
	return(DetikToTIME(TIMEToDetik(T) + N));
}
TIME PrevDetik (TIME T)
/* Mengirim 1 detik sebelum T dalam bentuk TIME */
{
  int T_PrevDetik;

  T_PrevDetik = TIMEToDetik(T)-1;
  while (T_PrevDetik < 0) {
    T_PrevDetik += 86400;
  }
	return(DetikToTIME(T_PrevDetik));
}

TIME PrevNDetik (TIME T, int N)
/* Mengirim N detik sebelum T dalam bentuk TIME */
/* *** Kelompok Operator Aritmetika *** */
{
  int T_PrevNDetik;

  T_PrevNDetik = TIMEToDetik(T)-N;
  while(T_PrevNDetik < 0){
    T_PrevNDetik += 86400;
  }
	return(DetikToTIME(T_PrevNDetik));
}
long Durasi (TIME TAw, TIME TAkh)
/* Mengirim TAkh-TAw dlm Detik, dengan kalkulasi */
/* Jika TAw > TAkh, maka TAkh adalah 1 hari setelah TAw */
{    
    int selisih;
    selisih = TIMEToDetik(TAkh) - TIMEToDetik(TAw);
    while(selisih < 0){
        selisih += 86400;
    }
    return selisih;
}