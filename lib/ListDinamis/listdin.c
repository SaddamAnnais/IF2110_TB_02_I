/* File: listdin.c */
#include <stdlib.h>
#include <stdio.h>
#include "listdin.h"
/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create list kosong  */
void CreateListDin(ListDin *l, int capacity)
/* I.S. l sembarang, capacity > 0 */
/* F.S. Terbentuk list dinamis l kosong dengan kapasitas capacity */
{
    BUFFER(*l) = (ElType *) malloc(capacity * sizeof(ElType));
    LISTDINCAPACITY(*l) = capacity;
    NEFF(*l) = 0;
}
void dealocateList(ListDin *l)
/* I.S. l terdefinisi; */
/* F.S. (l) dikembalikan ke system, CAPACITY(l)=0; NEFF(l)=0 */
{

    free(BUFFER(*l));
    LISTDINCAPACITY(*l) = 0;
    NEFF(*l) = 0;
}
/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int listLength(ListDin l)
/* Mengirimkan banyaknya elemen efektif list */
/* Mengirimkan nol jika list l kosong */
/* *** Daya tampung container *** */
{
    return NEFF(l);
}
/* *** Selektor INDEKS *** */
IdxType getFirstIdx(ListDin l)
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l pertama */
{
	return (IDX_MIN);
}
IdxType getLastIdx(ListDin l)
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l terakhir */
{

    return (IdxType) (listLength(l) - 1);
}
/* ********** Test Indeks yang valid ********** */
boolean isIdxValid(ListDin l, IdxType i)
/* Mengirimkan true jika i adalah indeks yang valid utk kapasitas list l */
/* yaitu antara indeks yang terdefinisi utk container*/
{
    return (i >= 0 && i < (IdxType) LISTDINCAPACITY(l));
}
boolean isIdxEff(ListDin l, IdxType i)
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk list */
/* yaitu antara 0..NEFF(l) */
{
    return (i >= 0 && i <= getLastIdx(l));
}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test list kosong *** */
boolean isEmpty(ListDin l)
/* Mengirimkan true jika list l kosong, mengirimkan false jika tidak */
/* *** Test list penuh *** */
{
    return (NEFF(l) == 0);
}
boolean isFull(ListDin l)
/* Mengirimkan true jika list l penuh, mengirimkan false jika tidak */
{
    return (NEFF(l) == LISTDINCAPACITY(l));
}
/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi list dari pembacaan *** */
void readList(ListDin *l)
/* I.S. l sembarang dan sudah dialokasikan sebelumnya */
/* F.S. List l terdefinisi */
/* Proses : membaca banyaknya elemen l dan mengisi nilainya */
/* 1. Baca banyaknya elemen diakhiri enter, misalnya N */
/*    Pembacaan diulangi sampai didapat N yang benar yaitu 0 <= N <= CAPACITY(l) */
/*    Jika N tidak valid, tidak diberikan pesan kesalahan */
/* 2. Jika 0 < N <= CAPACITY(l); Lakukan N kali: Baca elemen mulai dari indeks
      0 satu per satu diakhiri enter */
/*    Jika N = 0; hanya terbentuk l kosong */
{
    IdxType i;
    int N;

    do {
        scanf("%d", &N);
    } while(N < 0 || N > LISTDINCAPACITY(*l));

    for (i = 0; i < (IdxType) N; i++) {
        scanf("%d", &ELMT(*l, i));
    }

    NEFF(*l) = N;
}
void printList(ListDin l)
/* Proses : Menuliskan isi list dengan traversal, list ditulis di antara kurung siku;
   antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan karakter di depan,
   di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. l boleh kosong */
/* F.S. Jika l tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
{
    /* KAMUS */
    IdxType i;

    /* ALGORITMA */
    printf("[");
    for (i = 0; i <= getLastIdx(l); i++) {
        if (i != getLastIdx(l)) {
            printf("%d,", ELMT(l, i));
        }
        else {
            printf("%d", ELMT(l, i));
        }
    }
    printf("]");
}

/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan list : < =, > *** */
boolean isListEqual(ListDin l1, ListDin l2)
/* Mengirimkan true jika l1 sama dengan l2 yaitu jika nEff l1 = l2 dan semua elemennya sama */
{
    /* KAMUS */
    IdxType i;
    boolean eq;

    /* ALGORITMA */
    eq = true;

    if (listLength(l1) != listLength(l2)) {
        eq = false;
    }
    else {
        i = 0;
        while (i <= getLastIdx(l1) && eq) {
            if (ELMT(l1, i) != ELMT(l2, i)) {
                eq = false;
            }
            i++;
        }
    }

    return eq;
}
/* ********** SEARCHING ********** */
/* ***  Perhatian : list boleh kosong!! *** */
IdxType indexOf(ListDin l, ElType val)
/* Search apakah ada elemen List l yang bernilai val */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = val */
/* Jika tidak ada, mengirimkan IDX_UNDEF */
/* Menghasilkan indeks tak terdefinisi (IDX_UNDEF) jika List l kosong */
/* Skema Searching yang digunakan bebas */
{
    /* KAMUS */
    IdxType i, index;

    /* ALGORITMA */
    index = IDX_UNDEF;
    i = 0;

    while (i <= getLastIdx(l) && index == IDX_UNDEF) {
        if (ELMT(l, i) == val) {
            index = i;
        }
        i++;
    }

    return index;
}

/* ********** OPERASI LAIN ********** */
void copyList(ListDin lIn, ListDin *lOut)
/* I.S. lIn terdefinisi tidak kosong, lOut sembarang */
/* F.S. lOut berisi salinan dari lIn (identik, nEff dan capacity sama) */
/* Proses : Menyalin isi lIn ke lOut */ 
{
    /* KAMUS */
    IdxType i;

    /* ALGORITMA */
    CreateListDin(lOut, LISTDINCAPACITY(lIn));

    NEFF(*lOut) = listLength(lIn);

    for (i = 0; i <= getLastIdx(lIn); i++) {
        ELMT(*lOut, i) = ELMT(lIn, i);
    }
}

int countVal(ListDin l, ElType val)
/* Menghasilkan berapa banyak kemunculan val di l */
/* Jika l kosong menghasilkan 0 */
{
    /* KAMUS */
    int hasil;
    IdxType i;

    /* ALGORITMA */
    hasil = 0;

    for (i = 0; i <= getLastIdx(l); i++) {
        if (ELMT(l, i) == val) {
            hasil++;
        }
    }

    return hasil;
}

/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
/* *** Menambahkan elemen terakhir *** */
void insertLast(ListDin *l, ElType val)
/* Proses: Menambahkan val sebagai elemen terakhir list */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen terakhir l yang baru */
{
    ELMT(*l, getLastIdx(*l) + 1) = val;
    NEFF(*l)++;
}
/* ********** MENGHAPUS ELEMEN ********** */
void deleteLast(ListDin *l, ElType *val)
/* Proses : Menghapus elemen terakhir list */
/* I.S. List tidak kosong */
/* F.S. val adalah nilai elemen terakhir l sebelum penghapusan, */
/*      Banyaknya elemen list berkurang satu */
/*      List l mungkin menjadi kosong */
{
    *val = ELMT(*l, getLastIdx(*l));
    NEFF(*l)--;
}

/* ********* MENGUBAH UKURAN ARRAY ********* */
void expandList(ListDin *l, int num)
/* Proses : Menambahkan capacity l sebanyak num */
/* I.S. List sudah terdefinisi */
/* F.S. Ukuran list bertambah sebanyak num */
{
    /* KAMUS */
    int awal_CAP, awal_NEFF;
    IdxType i;
    ListDin temp;

    /* ALGORITMA */
    copyList(*l, &temp);
    awal_CAP = LISTDINCAPACITY(*l);
    awal_NEFF = NEFF(*l);

    dealocateList(l);

    CreateListDin(l, awal_CAP + num);
    NEFF(*l) = awal_NEFF;

    for (i = 0; i <= getLastIdx(*l); i++) {
        ELMT(*l, i) = ELMT(temp, i);
    }
}
void shrinkList(ListDin *l, int num)
/* Proses : Mengurangi capacity sebanyak num */
/* I.S. List sudah terdefinisi, ukuran capacity > num, dan nEff < capacity - num. */
/* F.S. Ukuran list berkurang sebanyak num. */
{
    /* KAMUS */
    int awal_CAP, awal_NEFF;
    IdxType i;
    ListDin temp;

    /* ALGORITMA */
    copyList(*l, &temp);
    awal_CAP = LISTDINCAPACITY(*l);
    awal_NEFF = NEFF(*l);

    dealocateList(l);

    CreateListDin(l, awal_CAP - num);
    NEFF(*l) = awal_NEFF;

    for (i = 0; i <= getLastIdx(*l); i++) {
        ELMT(*l, i) = ELMT(temp, i);
    }
}
void compressList(ListDin *l)
/* Proses : Mengubah capacity sehingga nEff = capacity */
/* I.S. List tidak kosong */
/* F.S. Ukuran nEff = capacity */
{
    /* KAMUS */
    int awal_NEFF;
    IdxType i;
    ListDin temp;

    /* ALGORITMA */
    copyList(*l, &temp);
    awal_NEFF = NEFF(*l);

    dealocateList(l);

    CreateListDin(l, awal_NEFF);
    NEFF(*l) = awal_NEFF;

    for (i = 0; i <= getLastIdx(*l); i++) {
        ELMT(*l, i) = ELMT(temp, i);
    }
}