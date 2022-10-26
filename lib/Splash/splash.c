#include <stdio.h>

int splash(void){
    // SPLASH SCREEN
    FILE *fptr = NULL;
 
    if((fptr = fopen("./lib/Splash/splash.txt","r")) == NULL){
        printf("error opening splash.txt\n");
        return 1;
    }
    
    char read_string[128];

    while(fgets(read_string,sizeof(read_string),fptr) != NULL){
        printf("%s",read_string);
    }

    fclose(fptr);
 
    return 0;
}