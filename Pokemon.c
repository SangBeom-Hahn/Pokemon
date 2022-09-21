# include<stdio.h>
# include<stdlib.h>
# include<string.h>
# include<conio.h> // getch 함수 명시적으로 선언
# include<time.h>

typedef struct{
    char name[20]; //파이리
    char property[10]; //불
    int power; //12
    int hp; //500
}PokemonList;

typedef struct 
{
    /* data */
    char name[20]; //파이리
    char nickName[100]; //꽁꽁이
    char property[10]; //불
    int power; //12
    int hp; //500
}MyPokemon;


void main(void){
    FILE *fp;
    fp = fopen("pokemon_list.txt", "r");

    PokemonList PL[13]; //파일의 길이를 알면 좋을 텐데
    int pokemonListSize = sizeof(PL) / sizeof(PL[0]);
    int i=0, myPokemonNum, travelQA;
    char myPokemonNickName[20];
    char enter;
    

    if(fp == NULL){
        printf("파일이 없습니다.");
        exit(1);
    }

    while(1){
        
        if(feof(fp))
            break;

        fscanf(fp, "%s %s %d %d", &PL[i].name, &PL[i].property, &PL[i].power, &PL[i].hp);
        i++;
    }
    
    

    printf("================================================\n\t\t포켓몬스터\n\tpress enter key to start\n");
    enter = getch();
    if(enter){ //버퍼가 없는 엔터를 해야 엔터를 두번 누르는 일이 없음
        // 여기에 게임을 시작하는 함수를 넣을 것 같음 -> 게임 시작 함수play를 따로 만들 예정
        MyPokemon myPokemon;
        srand(time(NULL));

        do{ // 형식을 통과해야 하래로 내려갈 수 있음 파이썬에서는 여기가 while - if 문으로 쓰기 좋겠다.
            printf("어느 포켓몬을 고르시겠습니까? 1. 파이리, 2. 이상해씨, 3. 꼬부기\n");
            scanf("%d", &myPokemonNum);
            if(myPokemonNum <= 0 || myPokemonNum > 3)
                puts("범위가 이상합니다!!!");
            
        }while(myPokemonNum <= 0 || myPokemonNum > 3);
        
        printf("별명을 입력하세요!\n>>");
        scanf("%d", &myPokemonNickName);
        strcpy(myPokemon.nickName, myPokemonNickName);
        
        if(myPokemonNum == 1){
            strcpy(myPokemon.name, "파이리");
            strcpy(myPokemon.property, "불");
            myPokemon.hp = 500 + rand() % 501;
            myPokemon.power = 100 + rand() % 51;
        }
        else if (myPokemonNum == 2)
        {
            /* code */
            strcpy(myPokemon.name, "이상해씨");
            strcpy(myPokemon.property, "풀");
            myPokemon.hp = 500 + rand() % 501;
            myPokemon.power = 100 + rand() % 51;
        }
        else if(myPokemonNum == 3){
            strcpy(myPokemon.name, "꼬북이");
            strcpy(myPokemon.property, "물");
            myPokemon.hp = 500 + rand() % 501;
            myPokemon.power = 100 + rand() % 51;
        }   
        // else{ // 진짜 오류잡기로 잘 한거 같다!!!!!!!!!!!!!!!!!!!! 이런 습관을 항상 유지하자 실패를 항상 고려해야한다.
        //         printf("범위를 넘어선 잘못된 입력입니다.\n");               
        // }

        printf("이름은 : %s\n속성은 : %s\n별명은 : %s\n체력은 : %d\n공격력은 : %d\n", myPokemon.name, myPokemon.property, myPokemon.nickName, myPokemon.hp, myPokemon.power);
    }   

        printf("================================================\n\t\t여행을 떠나시겠습니까?\n\t1. 네\t2. 아니요(저장요부선택)\t3. 상점가기(몬스터볼과 회복 물약 사기\n>>");
        scanf("%d", &travelQA);

    fclose(fp);
}