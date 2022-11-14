/* Implementasi dari ADT Set */
#include "set.h"
#include <stdio.h>

/* IMPLEMENTASI KONSTRUKTOR dan INPUT/OUTPUT */

/* Konstruktor pembentuk set */
void createSet(Set* set);
// I.S. Set sembarang
// F.S. Set terdefinisi

/* Menampilkan set ke layar */
void displaySet(Set set);
// I.S. Set terdefinisi
// F.S. Semua elemen set ditampilkan di layar

/* IMPLEMENTASI OPERASI-OPERASI PADA SET */

/* Menghasilkan true jika set kosong */
boolean isEmpty(Set set);

/* Menambahkan elemen ke set */
void addToSet(Set* set, ElType x);
// I.S. Set terdefinisi dan mungkin kosong
// F.S. Menambahkan elemen ke set jika x belum terdapat di set

/* Menghapus elemen dari set */
void removeFromSet(Set* set, ElType x);
// I.S. Set tidak kosong dan x terdapat di dalam set
// F.S. X terhapus dari set

/* Menghasilkan true jika x terdapat di dalam set */
boolean isIn(Set set, ElType x);

/* Menghasilkan true jika s1 = s2 */
boolean isEqual(Set s1, Set s2);

/* Menghasilkan gabungan dari s1 dan s2 */
Set unionSet(Set s1, Set s2);

/* Menghasilkan irisan dari s1 dan s2 */
Set intersectionSet(Set s1, Set s2);

/* Menghasilkan true jika s1 merupakan subset dari s2 */
boolean isSubset(Set s1, Set s2);