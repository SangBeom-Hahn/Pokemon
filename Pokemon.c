# include<stdio.h>
# include<stdlib.h>
# include<string.h>
# include<conio.h> // getch 함수 명시적으로 선언
# include<time.h>
# include<unistd.h> //sleep 함수 명시적으로 선언
# include "Pokemon.h"

PokemonList PL[13]; //파일의 길이를 알면 좋을 텐데
MyPokemon myPokemon[6]; //같은 이유로 밖으로 뺌

// 여행을 떠나다가 공격을 하는 함수
double fight(char fightingPokemon[], char enemyPokemon[]){
    if(strcmp(fightingPokemon, "불") == 0) {
        if(strcmp(enemyPokemon, "풀") == 0){
            printf("효과가 굉장했다.");
            return 1.5;
        }
        else if(strcmp(enemyPokemon, "물") == 0){
            printf("효과가 별로인 듯 하다.");
            return 0.5;
        }
        else   
            return 1;
        



    }
    else if( strcmp(fightingPokemon, "물") == 0){
        if(strcmp(enemyPokemon, "불") == 0){
            printf("효과가 굉장했다.");
            return 1.5;
        } 
        else if(strcmp(enemyPokemon, "풀") == 0){
            printf("효과가 별로인 듯 하다.");
            return 0.5;
        }
        else   
            return 1;            



    }
    else{
        if(strcmp(enemyPokemon, "물") == 0){
            printf("효과가 굉장했다.");
            return 1.5;
        }  
        else if(strcmp(enemyPokemon, "불") == 0){
            printf("효과가 별로인 듯 하다.");
            return 0.5;
        }
        else   
            return 1;
    }
}


// 1번을 누르면 여행을 떠나는 함수
void travel(void){
    int turn = 0; // 짝수면 내가 공격하는 거고 홀수면 상대가 공격한다.
    char fightingPokemon[10], enemyPokemon[10];

    // ★★★ 엄청 중요한게 이 변수의 위치가 여기인 이유가 6번이 반복될 건데 처음 시작만 0이고 그 후에는 반복이 진행되면서 바뀔 것이기 때문에 이러한 경우에는 
    // while문 밖에 쓰면 되겠다!!

    //내 포켓몬 리스트 중에서 처음으로 싸우는 내 포켓몬은 무조건 0번 인덱스임 
    int fightMyPokomom = 0; 

    while(1){
        //★5번 반복 부분
        printf("================================\n");
        printf("\t길을 걷는 중... ... ...\n");
        
        sleep(1+rand()%3);

        int wildPokemonNumber, sixRepeat;
        double attackPower;
        srand(time(NULL));

        printf("================================\n");
        printf("\t야생의 포켓몬이 나타났다!\n");

        wildPokemonNumber = rand() % 13;
        printf("이름은 : %s\n속성은 : %s\n체력은 : %d\n공격력은 : %d\n", PL[wildPokemonNumber].name, PL[wildPokemonNumber].property, \
        PL[wildPokemonNumber].hp, PL[wildPokemonNumber].power);


        while(1){
            // 6번으로 반복
            // 여기서 Pokemon.c의 Pokemon List를 꺼내야하는데 이런게 안돼서 객체지향 언어를 쓰나??
            printf("1. 공격 2. 도망치기 3. 가방 열기>>");
            scanf("%d", &sixRepeat);



            if(sixRepeat == 1){
                //여기에 속성 강 vs 약 넣자 -> 이런 변화와 할 일 예정 등을 형상 관리를 해야한다 이거야
                strcpy(fightingPokemon, myPokemon[fightMyPokomom].property);
                strcpy(enemyPokemon, PL[wildPokemonNumber].property);
                printf("내 %s가 공격한다! \n", myPokemon[fightMyPokomom].name);

                // 속성 차이 함수로 만들자
                attackPower = fight(fightingPokemon, enemyPokemon);

                PL[wildPokemonNumber].hp -= myPokemon[fightMyPokomom].power*attackPower;
                printf("%s의 남은 체력 : %d\n", myPokemon[fightMyPokomom].name, myPokemon[fightMyPokomom].hp);
                printf("%s의 남은 체력 : %d\n\n", PL[wildPokemonNumber].name, PL[wildPokemonNumber].hp);
                
                sleep(2);
            
                strcpy(fightingPokemon, PL[wildPokemonNumber].property);
                strcpy(enemyPokemon, myPokemon[fightMyPokomom].property);
                printf("적 %s가 공격한다! \n", PL[wildPokemonNumber].name);

                // 속성 차이 함수로 만들자
                attackPower = fight(fightingPokemon, enemyPokemon);

                myPokemon[fightMyPokomom].hp -= PL[wildPokemonNumber].power*attackPower;
                printf("%s의 남은 체력 : %d\n", myPokemon[fightMyPokomom].name, myPokemon[fightMyPokomom].hp);
                printf("%s의 남은 체력 : %d\n\n", PL[wildPokemonNumber].name, PL[wildPokemonNumber].hp);

                // 내 포켓몬이 쓰러지면 포켓몬 잡고나서 생각하자
                // if(myPokemon[fightMyPokomom].hp < 0){
                //     //내 포켓몬 리스트의 모든 애들을 for문 돌려서(이때 배열크기는 정해져 있기 때문에 요소 개수를[현재 용량]이 필요한 거구나!) 모두 hp가 0이면 4번으로 이동
                //     if()
                // }
            }
            else if(sixRepeat == 2){

            }
            else if(sixRepeat == 3){

            }
            // 0을 누르면 5번으로 이동
            else{
               break;
            }
            // 내 포켓몬이 쓰러지거나, 포켓몬을 잡았거나, 0을 누르거나 하면 break를 해서 더 이상 6.이 안 나오도록 하자
        }
    }
}


// 메인 함수
void main(void){
    FILE *fp;
    fp = fopen("pokemon_list.txt", "r");

    // PokemonList PL[13]; 원래 여기였는데 travel 함수에서 쓰기 위해 전역으로 뺐다.
    int pokemonListSize = sizeof(PL) / sizeof(PL[0]);
    int i=0, myPokemonNum;
    int travelQA;
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
        // 여기에 게임을 시작하는 함수를 넣을 것 같음 -> 게임 시작 함수 play를 따로 만들 예정(반복되는 코드는 무조건 함수화지만 이거는 뭔가 구분하면 좋을 것 같단 느낌이 듬..!)
        // 한마디로 이 밑을 play라는 함수 딱 하나만 두면 가독성에 좋을 것 같단 맘이 생긴다 이거지!!/
        srand(time(NULL));

        do{ // 형식을 통과해야 아래로 내려갈 수 있음 파이썬에서는 여기가 while - if 문으로 쓰기 좋겠다./ do-while로 형식보고 while을 쓰는 것도 가능
            printf("어느 포켓몬을 고르시겠습니까? 1. 파이리, 2. 이상해씨, 3. 꼬부기\n");
            scanf("%d", &myPokemonNum);
            if(myPokemonNum <= 0 || myPokemonNum > 3)
                puts("범위가 이상합니다!!!");
            
        }while(myPokemonNum <= 0 || myPokemonNum > 3);
        
        printf("별명을 입력하세요!\n>>");
        scanf("%s", myPokemonNickName);
        strcpy(myPokemon[0].nickName, myPokemonNickName);
        
        if(myPokemonNum == 1){
            strcpy(myPokemon[0].name, "파이리");
            strcpy(myPokemon[0].property, "불");
            myPokemon[0].hp = 500 + rand() % 501;
            myPokemon[0].power = 100 + rand() % 51;
        }
        else if (myPokemonNum == 2)
        {
            /* code */
            strcpy(myPokemon[0].name, "이상해씨");
            strcpy(myPokemon[0].property, "풀");
            myPokemon[0].hp = 500 + rand() % 501;
            myPokemon[0].power = 100 + rand() % 51;
        }
        else if(myPokemonNum == 3){
            strcpy(myPokemon[0].name, "꼬북이");
            strcpy(myPokemon[0].property, "물");
            myPokemon[0].hp = 500 + rand() % 501;
            myPokemon[0].power = 100 + rand() % 51;
        }   
        // else{ // 진짜 오류잡기로 잘 한거 같다!!!!!!!!!!!!!!!!!!!! 이런 습관을 항상 유지하자 실패하는 경우를 항상 고려해야한다.
        //         printf("범위를 넘어선 잘못된 입력입니다.\n");               
        // }

        printf("이름은 : %s\n속성은 : %s\n별명은 : %s\n체력은 : %d\n공격력은 : %d\n", myPokemon[0].name, myPokemon[0].property, myPokemon[0].nickName, myPokemon[0].hp, myPokemon[0].power);
    }

    while(1){
        //4번 반복
        printf("===========================\n\t\t여행을 떠나시겠습니까?\n\t1. 네\t2. 아니요(저장여부선택)\t3. 상점가기(몬스터볼과 회복 물약 사기)\n");
        scanf("%d", &travelQA);
        // 입력이 안되는 문제는 별명에 숫자를 넣으면 해결됨,,,,,ㅋz 하 입력 형식지정자 %d로 해놨음 역시 모든건 내 잘못 컴퓨터 잘못 없다!!

        if(travelQA == 1){
            travel();
        }
        else if(travelQA == 2){
            
        }
        else{
            
        }
    }    
    

    fclose(fp);
}