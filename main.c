#include <stdio.h>

#include "./lib/Splash/splash.c"
#include "./lib/parser/charmachine.c"
#include "./lib/parser/wordmachine.c"
#include "./lib/Simulator/simulator.c"
#include "./lib/Inventory/inventory.c"
#include "./lib/priorityQueueDin/prioqueuedin.c"
#include "./lib/Peta/peta.c"
#include "./lib/ADT Matrix/matrix.c"
#include "./lib/Makanan/listMakanan.c"
#include "./lib/Makanan/makanan.c"
#include "./lib/Time/time.c"
// #include "./lib/Makanan/makanan.c"

int main(){
    //SPLASH SCREEN
    splash();
    // START or EXIT
    printf("START/EXIT?\n");
    STARTWORD();
    // Membandingkan input pengguna dengan kata "START"
    boolean start = isWordStrEq(currentWord, "START");
    
    if (start) // Memulai program
    {
        printf("Masukkan nama pengguna: ");
        STARTWORD();
        Simulator S;
        CreateSimulator(&S, currentWord);
        Peta P;
        ListMakanan l;
        readPeta(&P, "./config/peta.txt", &S);
        BacaMakanan(&l, "./config/makanan.txt");

        displayPeta(P);
    }

    return 0;
}