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
    /* I.S. : currentChar sembarang
       F.S. : endWord = true, dan currentChar = MARK;
              atau endWord = false, currentWord adalah kata yang sudah diakuisisi,
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
    //start word dari file
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
              Jika currentChar = MARK, endWord = true.
       Proses : Akuisisi kata menggunakan procedure CopyWord */
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
              currentChar = BLANK atau currentChar = MARK atau currentChar = NEWLINE;
              currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
              Jika panjang kata melebihi CAPACITY, maka sisa kata terpotong */
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
// Apakah word sama atau tidak. Mengembalikan true jika word sama
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
    // meng output word  
   for (int i = 0; i<w.Length; i++) {
      printf("%c", w.TabWord[i]);
   }
   printf("\n");
}