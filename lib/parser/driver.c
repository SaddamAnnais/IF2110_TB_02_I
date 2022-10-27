#include <stdio.h>
#include "wordmachine.h"

int main() {
    STARTWORD();
    Word w1 = currentWord;
    
    while (!EndWord) {
        printf("%d ", isWordEq(w1, currentWord));
        printWord(currentWord);
        printf("\n");

        ADVWORD();
    } 

    STARTWORDFILE("test.txt");
    Word w2 = currentWord;
    
    printWord(currentWord);
    printf("\n");

    printf("%d\n", wordToInt(currentWord));
    ADVLINE();
    printWord(currentWord);
    printf("\n");
    ADVWORD();
    printWord(currentWord);
    printf("\n");
    ADVWORD();
    printWord(currentWord);
    printf("\n");

    printf("%d", isWordStrEq(currentWord, "12"));
    return 0;
}