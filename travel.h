# include<stdio.h>
# include<stdlib.h>
# include<windows.h>
# include "Pokemon.h"

void travel(void){
    printf("================================\n");
    printf("\t길을 걷는 중... ... ...\n");
    
    sleep(1+rand()%3);

    printf("================================\n");
    printf("\t야생의 포켓몬이 나타났다!\n");


    // 여기서 Pokemon.c의 Pokemon List를 꺼내야하는데 이런게 안돼서 객체지향 언어를 쓰나??
    printf("1. 공격 2. 도망치기 3. 가방 열기\n>>");


    
}