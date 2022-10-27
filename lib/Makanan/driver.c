#include "makanan.h"
#include "listmakanan.h"
#include <stdio.h>

int main() {
    ListMakanan l;
    CreateListMakanan(&l);
    BacaMakanan(&l, "test.txt");
    printListMakanan(l);
    // STARTWORDFILE("test.txt");
    // printWord(currentWord);     // N
    // ADVWORD();
    // printWord(currentWord);      // ID
    // ADVLINE();
    // printWord(currentWord);     // Nama makanan
    // ADVWORD();
    // printWord(currentWord);     // kadaluarsa - hari 
    // ADVWORD();
    // printWord(currentWord);     // kadaluarsa - jam
    // ADVWORD();
    // printWord(currentWord);     // kadaluarsa - menit

    return 0;
}