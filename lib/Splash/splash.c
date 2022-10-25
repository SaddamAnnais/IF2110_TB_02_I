#include <stdio.h>

int main(void)
{
    FILE *fptr = NULL;
 
    if((fptr = fopen("image.txt","r")) == NULL){
        printf("error opening image.txt\n");
        return 1;
    }
    
    char read_string[128];

    while(fgets(read_string,sizeof(read_string),fptr) != NULL){
        printf("%s",read_string);
    }

    fclose(fptr);
 
    return 0;
}