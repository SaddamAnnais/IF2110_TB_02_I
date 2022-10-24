#include "time.c"
#include <stdio.h>

int main(){
    Time T;
    int x;
    createTime(&T,1,10,0);
    tulisTime(T);
    printf("\n");
    x = timeToMinute(T);
    printf("%d\n",x);
    T = minuteToTime(x);
    tulisTime(T);
    printf("\n");
    decMinute(&T);
    tulisTime(T);
    printf("\n");
    decNMinute(&T,20);
    tulisTime(T);
    printf("\n");
    incMinute(&T);
    tulisTime(T);
    printf("\n");
    incNMinute(&T,20);
    tulisTime(T);
    printf("\n");
    return 0;
}