/* File: wordmachine.h */
/* Definisi Word Machine: Model Akuisisi Versi I */

#ifndef __MESINKATA_H__
#define __MESINKATA_H__

#include "charmachine.h"

#define NMax 50
#define BLANK ' '
#define NEWLINE '\n'

typedef struct
{
   char TabWord[NMax]; /* container penyimpan kata, indeks yang dipakai [0..NMax-1] */
   int Length;
} Word;

/* State Mesin Word */
extern boolean EndWord;
extern Word currentWord;

void IgnoreBlanksNewLine();
/* Mengabaikan BLANK atau NEWLINE
   I.S. : currentChar sembarang
   F.S. : currentChar ≠ BLANK atau currentChar = MARK */

void STARTWORD();
/* Proses : membaca dari terminal
   I.S.  currentChar sembarang
   F.S.  EndWord = true, dan currentChar = MARK;
         atau EndWord = false, currentWord adalah kata yang sudah diakuisisi,
         currentChar karakter pertama sesudah karakter terakhir kata */

void STARTWORDFILE(char *filename);
/* Proses : membaca dari file txt
   I.S.  currentChar sembarang
   F.S.  EndWord = true, dan currentChar = MARK;
         atau EndWord = false, currentWord adalah kata yang sudah diakuisisi,
         currentChar karakter pertama sesudah karakter terakhir kata */

void ADVWORD();
/* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
   F.S. : currentWord adalah kata terakhir yang sudah diakuisisi,
          currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika currentChar = MARK, EndWord = true.
   Proses : Akuisisi kata menggunakan procedure SalinWord */

void CopyWord();
/* Mengakuisisi kata, menyimpan dalam currentWord
   I.S. : currentChar adalah karakter pertama dari kata
   F.S. : currentWord berisi kata yang sudah diakuisisi;
          currentChar = BLANK atau currentChar = MARK;
          currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */

boolean isWordEq(Word w1, Word w2);
/* Mengembalikan nilai true jika w1 dan w2 adalah sama */        

void printWord(Word w);
/* Mengoutput w ke layar*/

int wordToInt(Word w);
/* Merubah sebuah word menjadi integer kemudian mengembalikannya */

#endif
