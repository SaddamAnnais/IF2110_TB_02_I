#include <stdio.h>

#include "./lib/Splash/splash.c"
#include "./lib/parser/charmachine.c"
#include "./lib/parser/wordmachine.c"
#include "./lib/Simulator/simulator.c"
#include "./lib/Inventory/inventory.c"
#include "./lib/priorityQueueDin/prioqueuedin.c"
#include "./lib/Peta/peta.c"
#include "./lib/ADT Matrix/matrix.c"
// #include "./lib/Makanan/makanan.c"

int main(){
    //SPLASH SCREEN
    splash();
    // START or EXIT
    printf("START/EXIT?\n");
    STARTWORD();
    // Membandingkan input pengguna dengan kata "START"
    boolean start = true;
    char *s = "START";
    for (int i = 0; i < 5; i++){
        if(currentWord.TabWord[i] != s[i]){
            start = false;
        }
    }
    if (start) // Memulai program
    {
        printf("Masukkan nama pengguna: ");
        STARTWORD();
        Simulator S;
        CreateSimulator(&S, currentWord);
        Peta P;
        readPeta(&P, "./konfigurasi/konfigPeta.txt", &S);
        
    }
}