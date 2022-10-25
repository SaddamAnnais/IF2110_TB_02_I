#include <stdio.h>
#include "wordmachine.h"

int main() {
    STARTWORD();
    Word w1 = currentWord;
    
    while (!EndWord) {
        printf("%d ", isWordEq(w1, currentWord));
        printWord(currentWord);

        ADVWORD();
    } 

    STARTWORDFILE("test.txt");
    Word w2 = currentWord;
    
    while (!EndWord) {
        printf("%d ", isWordEq(w2, currentWord));
        printf("%d\n", wordToInt(currentWord));

    return 0;
}