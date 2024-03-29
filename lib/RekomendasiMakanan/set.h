/* Definisi ADT Set menggunakan konsep multiset */
#ifndef SET_H
#define SET_H

#define SET_CAPACITY 100    // Kapasitas maksimum dari set

#include "../utility/boolean.h"

typedef int setElType;   // Elemen pada set
/* ADT Set */
typedef struct set
{
  setElType buffer[SET_CAPACITY];    // Array tempat menyimpan set
  int length;                     // Jumlah elemen pada set
} Set;

/* KONSTRUKTOR, SELEKTOR, dan INPUT/OUTPUT */

/* Konstruktor pembentuk set */
void createSet(Set* set);
// I.S. Set sembarang
// F.S. Set terdefinisi

/* Selektor */
#define SET_ELMT(s, i) (s).buffer[i]    // Elemen dari sebuah set
#define SET_LENGTH(s) (s).length        // Jumlah elemen pada set

/* Menampilkan set ke layar */
void displaySet(Set set);
// I.S. Set terdefinisi
// F.S. Semua elemen set ditampilkan di layar

/* OPERASI-OPERASI PADA SET */

/* Menghasilkan true jika set kosong */
boolean isSetEmpty(Set set);

/* Menambahkan elemen ke set */
void addToSet(Set* set, setElType x);
// I.S. Set terdefinisi dan mungkin kosong
// F.S. Menambahkan elemen ke set

/* Menghapus elemen dari set */
void removeFromSet(Set* set, setElType x);
// I.S. Set tidak kosong dan x terdapat di dalam set
// F.S. X terhapus dari set

/* Meng-kopi sebuah set */
Set copySet(Set set);

/* Menghasilkan true jika x terdapat di dalam set */
boolean isIn(Set set, setElType x);

/* Menghasilkan true jika s1 = s2 */
boolean isSetEqual(Set s1, Set s2);

/* Menghasilkan gabungan dari s1 dan s2 */
Set unionSet(Set s1, Set s2);

/* Menghasilkan irisan dari s1 dan s2 */
Set intersectionSet(Set s1, Set s2);

/* Menghasilkan true jika s1 merupakan subset dari s2 */
boolean isSubset(Set s1, Set s2);

#endif