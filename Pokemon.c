# include<stdio.h>
# include<stdlib.h>
# include<string.h>
# include<conio.h> // getch 함수 명시적으로 선언
# include<time.h>
# include<unistd.h> //sleep 함수 명시적으로 선언
# include "Pokemon.h"

/*이 플젝에서 제일 포인트는 현재 싸우는 포켓몬 변수를 만들고 리스트에서 하나씩 꺼내서 대입하는 것!!!*/

// 메인 함수
void main(void){
    FILE *fp;
    fp = fopen("pokemon_list.txt", "r");

    // PokemonList PL[13]; 원래 여기였는데 travel 함수에서 쓰기 위해 전역 변수로 뺐다.
    // ↓ 지역변수들은 파일을 불러와서 구조체 배열에 저장하기 위한 것들로 main 함수에 있는게 맞다. 
    int pokemonListSize = sizeof(PL) / sizeof(PL[0]);
    int i=0, myPokemonNum;
    int travelQA;
    char myPokemonNickName[20];
    char enter;
    money = 10000; // 헤더 파일의 변수는 초기화를 할 수 없다. 따라서 선언만하고 사용하는 곳에서 한 번만 초기화

    // 항상 실패하는 경우를 생각해야 한다.
    if(fp == NULL){
        printf("파일이 없습니다.");
        exit(1);
    }

    while(1){
        if(feof(fp))
            break;

        fscanf(fp, "%s %s %d %d %d", &PL[i].name, &PL[i].property, &PL[i].power, &PL[i].hp, &PL[i].wholeHp);
        i++;
    }
    
    printf("================================================\n\t\t포켓몬스터\n\tpress enter key to start\n");

    //버퍼가 없는 엔터를 해야 엔터를 두번 누르는 일이 없음
    enter = getch();
    if(enter){ 
        /*
        여기에 게임을 시작하는 함수를 넣을 것 같음 -> 게임 시작 함수 play를 따로 만들 예정(반복되는 코드는 무조건 함수화지만 이거는 뭔가 구분하면 좋을 것 같단 느낌이 듬..!)
        한마디로 이 밑을 play라는 함수 딱 하나만 두면 가독성에 좋을 것 같단 맘이 생긴다 이거지!!/
        */
        
        srand(time(NULL));
        // 형식을 통과해야 아래로 내려갈 수 있음 파이썬에서는 여기가 while - if 문으로 쓰기 좋겠다./ do-while로 형식보고 while을 쓰는 것도 가능
        do{ 
            printf("어느 포켓몬을 고르시겠습니까? 1. 파이리, 2. 이상해씨, 3. 꼬부기\n");
            scanf("%d", &myPokemonNum);
            if(myPokemonNum <= 0 || myPokemonNum > 3) // 하지만 do-while 문에 if문을 두는 것이 좋은 코드인가 생각해 볼 필요가 있음 조건 검사를 여러번 함..
                puts("범위가 이상합니다!!!");
            
        }while(myPokemonNum <= 0 || myPokemonNum > 3);
        
        printf("별명을 입력하세요!\n>>");
        // strcpy(myPokemon[0].nickName, myPokemonNickName); 원래는 이거 였는데 바로 구조체 멤버에 대입 가능
        scanf("%s", myPokemon[0].nickName);
        
        // 이렇게 게임 시작 후 한 번만 실행될 코드는 반복되지 않으니 함수화하지 않아도 된다.
        if(myPokemonNum == 1){
            strcpy(myPokemon[0].name, "파이리");
            strcpy(myPokemon[0].property, "불");
            myPokemon[0].hp = 50000 + rand() % 501;
            myPokemon[0].power = 150 + rand() % 51;
        }
        else if (myPokemonNum == 2)
        {
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
        else{ 
            // 진짜 오류잡기로 잘 한거 같다!!!!!!! 이런 습관을 항상 유지하자 실패하는 경우를 항상 고려해야한다.
                printf("범위를 넘어선 잘못된 입력입니다.\n");
        }

        printf("이름은 : %s\n속성은 : %s\n별명은 : %s\n체력은 : %d\n공격력은 : %d\n", myPokemon[0].name, myPokemon[0].property, myPokemon[0].nickName, myPokemon[0].hp, myPokemon[0].power);
    }

    while(1){
        // (4)번 반복(프로젝트 구성도에서 반복되는 부분)
        printf("===========================\n\t\t여행을 떠나시겠습니까?\n\t1. 네\t2. 아니요(저장여부선택)\t3. 상점가기(몬스터볼과 회복 물약 사기)");
        scanf("%d", &travelQA);
        // 입력이 안되는 문제는 별명에 숫자를 넣으면 해결됨,,,,,ㅋz 하 입력 형식지정자 %d로 해놨음 역시 모든건 내 잘못, 컴퓨터 잘못 없다!!

        /*
        (int ballCnt, portionCnt;)
        이것들은 처음에는 0인데 상점에 가는 반복문이 실행될 때마다 다시 0이 되면 안되기 때문에 밖에 선언해야한다.
        근데 또 4를 반복할 때는 0개부터 시작해야해서 여기인 거 같다.
        근데 싸울 때 써야하네... 이렇게 밖으로 가는게 맞아??

        -> 현재 블럭 밖에서도 쓰이면 밖에 선언하는 것은 어쩔 수 없다. 하지만 4번이 반복될 때 0개부터 다시 시작하는 것은 flag를 둬서 해결한다.
        */

        if(travelQA == 1){
            travel();
            if(flagMoreGame)
                continue;
        }
        else if(travelQA == 3){
            // whatBuy는 밖에 쓰나 안에 쓰나 상관없는 거네 -> flag나 수량은 기록이 남는 게 중요하지만 단순 입력은 상관없지
            int whatBuy;
            while(1){
                printf("\t\t\t현재 소유 금액 : %d\n", money);
                printf("\t 1. 몬스터볼\t1000\n");
                printf("\t 2. 회복물약\t2500\n");

                puts("어떤 아이템을 사시겠습니까? (0) 입력시 상점 나감) : ");
                scanf("%d", &whatBuy);
                if(whatBuy == 0){ // 이걸 여기에 써야 0을 눌렀을 때 수량을 고르세요라고 안나오는데 그러면 if-else문이 깨진다.
                    break;
                }
                if(whatBuy < 1 && whatBuy > 2){
                    puts("범위를 벗어난 입력입니다.(1 or 2)");
                    continue;
                }

                printf("수량을 고르세요!!"); //↓ 밑에 따로따로 쓰기 싫어서 한 줄이라도 공유할 수 있는 거 올렸다. 이런 것도 형상관리를 했어야한다.
                
                /*
                고민 : 나는 if문 안에 따로따로 쓰기 싫은데 어쩔 수 없나,,,
                아니 살 때 2500원에 개수 곱하는 거랑 1000원에 개수 곱하는게 달라서 이래,,,
                */
                if(whatBuy == 1){
                    scanf("%d", &ballCnt);
                    buy(&ballCnt, 1000, "몬스터볼");
                }
                else{
                    scanf("%d", &portionCnt);
                    buy(&portionCnt, 2500, "회복물약");
                }
            }    
        }
        // 여행을 떠나지 않을 경우
        else{
            puts("게임을 종료합니다.");
            break;
        }
    }
    fclose(fp);
}