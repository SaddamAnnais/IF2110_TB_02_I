#include <stdio.h>
#include "wordmachine.h"

boolean EndWord;
Word currentWord;

void IgnoreBlanksNewLine()
{
/* Mengabaikan BLANK atau NEWLINE
   I.S. : currentChar sembarang
   F.S. : currentChar ≠ BLANK atau currentChar = MARK */
    while (currentChar == BLANK || currentChar == NEWLINE)
    {
        ADV();
    }
}

void STARTWORD()
{
/* Proses : membaca dari terminal
   I.S.  currentChar sembarang
   F.S.  EndWord = true, dan currentChar = MARK;
         atau EndWord = false, currentWord adalah kata yang sudah diakuisisi,
         currentChar karakter pertama sesudah karakter terakhir kata */
    START();
    IgnoreBlanksNewLine();
    if (currentChar == MARK)
    {
        EndWord = true;
    }
    else
    {
        EndWord = false;
        CopyWord();
    }
}

void STARTWORDFILE(char *filename)
{
/* Proses : membaca dari file txt
   I.S.  currentChar sembarang
   F.S.  EndWord = true, dan currentChar = MARK;
         atau EndWord = false, currentWord adalah kata yang sudah diakuisisi,
         currentChar karakter pertama sesudah karakter terakhir kata */
    STARTFILE(filename);
    IgnoreBlanksNewLine();
    if (currentChar == MARK)
    {
        EndWord = true;
    }
    else
    {
        EndWord = false;
        CopyWord();
    }
}

void ADVWORD()
{
/* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
   F.S. : currentWord adalah kata terakhir yang sudah diakuisisi,
          currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika currentChar = MARK, EndWord = true.
   Proses : Akuisisi kata menggunakan procedure SalinWord */
    IgnoreBlanksNewLine();
    if (currentChar == MARK)
    {
        EndWord = true;
    }
    else
    {
        CopyWord();
        IgnoreBlanksNewLine();
    }
}

void CopyWord()
{
/* Mengakuisisi kata, menyimpan dalam currentWord
   I.S. : currentChar adalah karakter pertama dari kata
   F.S. : currentWord berisi kata yang sudah diakuisisi;
          currentChar = BLANK atau currentChar = MARK;
          currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */
    currentWord.Length = 0;
    while (currentChar != BLANK && currentChar != MARK && currentChar != NEWLINE)
    {
        if (currentWord.Length < NMax)
        { // jika lebih akan terpotong
            currentWord.TabWord[currentWord.Length++] = currentChar;
            ADV();
        }
        else
            break;
    }
}

boolean isWordEq(Word w1, Word w2) {
/* Mengembalikan nilai true jika w1 dan w2 adalah sama */ 
    if (w1.Length != w2.Length) {
        return false;
    } 
    else {
        for (int i = 0; i < w1.Length; i++) {
            if (w1.TabWord[i] != w2.TabWord[i]) {
                return false;
            }
        }
        return true;
    } 
}

void printWord(Word w) {
/* Mengoutput w ke layar*/
   for (int i = 0; i<w.Length; i++) {
      printf("%c", w.TabWord[i]);
   }
   printf("\n");
}

int wordToInt(Word w)
/* Merubah sebuah word menjadi integer kemudian mengembalikannya */
{
    int res = 0;
    for (int i = 0; i<w.Length; i++) {
        res = res*10 + (w.TabWord[i]-48);
    }
    return res;
}