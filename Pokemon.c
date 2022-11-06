# include<stdio.h>
# include<stdlib.h>
# include<string.h>
# include<conio.h> // getch 함수 명시적으로 선언
# include<time.h>
# include<unistd.h> //sleep 함수 명시적으로 선언
# include "Pokemon.h"

/*이 플젝에서 제일 포인트는 현재 싸우는 포켓몬 변수를 만들고 리스트에서 하나씩 꺼내서 대입하는 것!!!*/

PokemonList PL[13]; //파일의 길이를 알면 좋을 텐데
MyPokemon myPokemon[6]; //같은 이유로 밖으로 뺌

//처음에는 위에 두개였는데 점점 쌓인다...
int currentMyPokemonCnt = 1;
//내 포켓몬 리스트 중에서 처음으로 싸우는 내 포켓몬은 무조건 0번 인덱스임 + 이런걸 프로토타입으로 해놓으면 나중에도 기억나겠지?(다시 보는 시점에 이거 쓴 기억 1도 없음 ㅋㅋ)
int fightMyPokomomNum = 0; //이거 아예 밖으로 빼야할 수 도?? 1번을 눌렀을 때 내포켓몬 말고 리스트의 다른 포켓몬이 나올 수 도 있다/
int selectNextMyPokemon;
int ballCnt, portionCnt;

//지금까지 flag는 전역에는 없었는데 이건 main이랑 travel을 거치는 flag라서 전역!
int flagMoreGame;

// 여행을 떠나다가 공격을 하는 함수
double fight(char fightingPokemon[], char enemyPokemon[]){
    if(strcmp(fightingPokemon, "불") == 0) {
        if(strcmp(enemyPokemon, "풀") == 0){
            printf("효과가 굉장했다(푸슝~)  \n\n");
            return 1.5;
        }
        else if(strcmp(enemyPokemon, "물") == 0){
            printf("효과가 별로인 듯 하다.(후ㅜㅜㅜ)  \n\n");
            return 0.5;
        }
        else   
            return 1;
        



    }
    else if( strcmp(fightingPokemon, "물") == 0){
        if(strcmp(enemyPokemon, "불") == 0){
            printf("효과가 굉장했다(푸슝~).  \n\n");
            return 1.5;
        } 
        else if(strcmp(enemyPokemon, "풀") == 0){
            printf("효과가 별로인 듯 하다.(후ㅜㅜㅜ)  \n\n");
            return 0.5;
        }
        else   
            return 1;            



    }
    else{
        if(strcmp(enemyPokemon, "물") == 0){
            printf("효과가 굉장했다(푸슝~).  \n\n");
            return 1.5;
        }  
        else if(strcmp(enemyPokemon, "불") == 0){
            printf("효과가 별로인 듯 하다.(후ㅜㅜㅜ)  \n\n");
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
    int flagFinish=0, flagMyPokemonCnt = 0;

    /*
    ★★★ 엄청 중요한게 이 변수의 위치가 여기인 이유가 6번이 반복될 건데 처음 시작만 0이고 그 후에는 반복이 진행되면서 바뀔 것이기 때문에 이러한 경우에는 
    while문 밖에 쓰면 되겠다!!
    원래 fightMyPokemonNum 여기였음 ㅋㅋ
    */
    while(1){
        //★5번 반복 부분
        if(flagFinish){
            break;
        }
        if(flagMyPokemonCnt){
            break;
        }

        printf("================================\n");
        printf("\t길을 걷는 중... ... ...\n");
        
        sleep(1+rand()%3);

        int flagEnemyDown = 0, flagEnemyRun = 0; // 이것도 왜 여기 있을까? 이거는 6번에 쓰이는 flag로 시작은 무조건 0이다. "이거는 6번 중에 break을 하면 5번도 나가야한다.!!" -> 그래서 여기
        int wildPokemonNumber, sixRepeat, wildPokemonWholeHp;
        double attackPower;
        int flagCatch = 0, flagRun = 0;
        char catchPokemonName[10];
        srand(time(NULL));

        printf("================================\n");
        printf("\t야생의 포켓몬이 나타났다!\n");

        // 야생 포켓몬 번호 대표 변수
        wildPokemonNumber = rand() % 13;
        wildPokemonWholeHp = PL[wildPokemonNumber].hp;
        printf("이름은 : %s\n속성은 : %s\n체력은 : %d\n공격력은 : %d\n", PL[wildPokemonNumber].name, PL[wildPokemonNumber].property, \
        PL[wildPokemonNumber].hp, PL[wildPokemonNumber].power);

        while(1){
            if(flagFinish){
                PL[wildPokemonNumber].hp = wildPokemonWholeHp; //원상복구
                break;
            }

            // 6번으로 반복
            // 여기서 Pokemon.c의 Pokemon List를 꺼내야하는데 이런게 안돼서 객체지향 언어를 쓰나??
            printf("1. 공격 2. 도망치기 3. 가방 열기>>");
            scanf("%d", &sixRepeat);

            if(sixRepeat == 1){
                int i=0; // 내 포켓몬들 체력 전부 0인지 보기 위한 i

                //여기에 속성 강 vs 약 넣자 -> 이런 변화와 할 일 예정 등을 형상 관리를 해야한다 이거야

                // strcpy는 왜 굳이 했니? 나중에 보면 못알아볼까봐 여러 포켓몬이 들어갈 거니 대표변수처럼 한 것
                strcpy(fightingPokemon, myPokemon[fightMyPokomomNum].property); strcpy(enemyPokemon, PL[wildPokemonNumber].property);
                printf("내 [%s]가 공격한다! \n", myPokemon[fightMyPokomomNum].name);

                // 속성 차이 함수로 만들자
                attackPower = fight(fightingPokemon, enemyPokemon);

                PL[wildPokemonNumber].hp -= myPokemon[fightMyPokomomNum].power*attackPower;
                printf("[%s]의 남은 체력 : %d\n", myPokemon[fightMyPokomomNum].name, myPokemon[fightMyPokomomNum].hp);
                printf("[%s]의 남은 체력 : %d\n\n", PL[wildPokemonNumber].name, PL[wildPokemonNumber].hp);
                
                sleep(2);
            
                strcpy(fightingPokemon, PL[wildPokemonNumber].property); strcpy(enemyPokemon, myPokemon[fightMyPokomomNum].property);
                printf("적 [%s]가 공격한다! \n", PL[wildPokemonNumber].name);

                // 속성 차이 함수로 만들자
                attackPower = fight(fightingPokemon, enemyPokemon);

                myPokemon[fightMyPokomomNum].hp -= PL[wildPokemonNumber].power*attackPower;
                printf("[%s]의 남은 체력 : %d\n", myPokemon[fightMyPokomomNum].name, myPokemon[fightMyPokomomNum].hp);
                printf("[%s]의 남은 체력 : %d\n\n", PL[wildPokemonNumber].name, PL[wildPokemonNumber].hp);

/*======================================================================================================================================================================*/



                if(myPokemon[fightMyPokomomNum].hp < 0){
                    myPokemon[fightMyPokomomNum].hp = 0; // 내 포켓몬 체력이 음수가 되어 0으로 맞춤

                    // 내 포켓몬 리스트의 모든 애들을 for문 돌려서(이때 배열크기는 정해져 있기 때문에 요소 개수를[현재 용량]이 필요한 거구나!) 모두 hp가 0이면 4번으로 이동
                    for(i=0; i<currentMyPokemonCnt; i++){
                        if(myPokemon[i].hp != 0){
                            break;
                        }
                    }
                    
                    if(i == currentMyPokemonCnt){
                        printf("눈 앞이 캄캄해졌다....\n\n보유하고 계신 모든 포켓몬이 체력을 회복하였습니다.\n");
                        for(int j=0; j<currentMyPokemonCnt; j++){
                            myPokemon[j].hp = 1000; //새 삶을 살기 위해 쓰러지면 모두 다 체력을 1000으로 가자~~
                        }
                    
                        flagFinish = 1;
                        break;
                    }

                    for(int i=0; i<currentMyPokemonCnt; i++){
                        printf("%d.   %s   %s   %d\n", i+1, myPokemon[i].name, myPokemon[i].property, myPokemon[i].hp); //현재 내 포켓몬의 개수(currentMyPokemonCnt)를 나타내는 변수도 마련해 놓으면 배열에 쓰기 좋겠다.

                    }
                    printf("어느 포켓몬을 내보내시겠습니까? : ");
                    scanf("%d", &selectNextMyPokemon); //구조체 배열에서 진짜로 체력을 깎으면 대입 안해도 되나?/
                    fightMyPokomomNum = selectNextMyPokemon-1;
                    continue;
                }


/*======================================================================================================================================================================*/

                if(PL[wildPokemonNumber].hp < 0){
                    printf("적 포켓몬을 쓰러뜨렸다!\n");
                    PL[wildPokemonNumber].hp = wildPokemonWholeHp; //원상복구
                    flagEnemyDown = 1;
                    break;
                }
                else if (PL[wildPokemonNumber].hp == 0)
                {
                    /* code */
                    printf("적 포켓몬이 도망갔다....!\n");
                    PL[wildPokemonNumber].hp = wildPokemonWholeHp; //원상복구
                    flagEnemyRun = 1;
                    break;

                }
                
            }
            else if(sixRepeat == 2){
                //도망치기
                int randNum = rand() % 100 + 1;
                int percentage = (int)(PL[wildPokemonNumber].hp/wildPokemonNumber) * 100;
                if(percentage == 100){
                    if(randNum <= 10){
                        //여기도 flag로 처리 가능하겠다! 반복되는 곳은 다 flag로 가능??
                        printf("도망 성공!(룰루 랄라)\n");
                        flagRun = 1;
                    }
                    else
                        printf("도망 실패 ㅜㅠㅜㅠ\n");
                }
                else if (percentage >= 50 && percentage < 100)
                {
                    /* code */
                    if(randNum <= 40){
                        printf("도망 성공!(룰루 랄라)\n");
                        flagRun = 1;
                    }
                    else
                        printf("도망 실패 ㅜㅠㅜㅠ\n");
                }
                else if (percentage >= 25 && percentage < 50)
                {
                    /* code */
                    if(randNum <= 70){
                        printf("도망 성공!(룰루 랄라)\n");
                        flagRun = 1;
                    }
                    else
                        printf("도망 실패 ㅜㅠㅜㅠ\n");
                }
                else{
                    if(randNum <= 90){
                        printf("도망 성공!(룰루 랄라)\n");
                        flagRun = 1;
                    }
                    else
                        printf("도망 실패 ㅜㅠㅜㅠ\n");
                }                    
            }
            else if(sixRepeat == 3){ // 6번을 반복하다가 3을 누르면 가방 열기
                int choose;
                if(ballCnt == 0 && portionCnt == 0){
                    // 아무것도 없는 경우에는 다른 선택을 유도
                    printf("가방이 비어있습니다.\n");
                    continue;
                }

                printf("1. 몬스터 볼    x%d\n",ballCnt);
                printf("2. 회복 물약    x%d\n",portionCnt);

                printf("어떤 아이템을 사용하시겠습니까? : ");
                scanf("%d", &choose);
                if(choose == 1){
                    // 몬스터 볼을 선택한 경우
                    if(PL[wildPokemonNumber].hp >= wildPokemonWholeHp * 0.5){
                        //이 부분을 위해서 가져왔다 만약 된다면 나중에 함수화하자 하지만 이 부분을 위에서 가져 온 것도 다 fight를 함수화 해두어서 가능한 일이다!!/
                        printf("체력을 더 깎아주세요......\n\n");

                        strcpy(fightingPokemon, PL[wildPokemonNumber].property);
                        strcpy(enemyPokemon, myPokemon[fightMyPokomomNum].property);
                        printf("적 %s가 공격한다! \n", PL[wildPokemonNumber].name);

                        // 속성 차이 함수로 만들자
                        attackPower = fight(fightingPokemon, enemyPokemon);

                        myPokemon[fightMyPokomomNum].hp -= PL[wildPokemonNumber].power*attackPower;
                        printf("%s의 남은 체력 : %d\n", myPokemon[fightMyPokomomNum].name, myPokemon[fightMyPokomomNum].hp);
                        printf("%s의 남은 체력 : %d\n\n", PL[wildPokemonNumber].name, PL[wildPokemonNumber].hp);
                        continue;
                    }
                    else{
                        //잡으면 여행을 계속하기 위해 5번으로 가고 빠져나오면 계속 싸워야하니 6번으로 가자

                        // 퍼센트가 계속 바뀔 거니까 여기!
                        int percent = (int)(PL[wildPokemonNumber].hp/wildPokemonWholeHp)*100;
                        int randNum = rand() % 100 + 1;

                        if( percent >= 30 && percent <=50 ){
                            if(randNum < 30){
                                // 코드 반복을 막음
                                flagCatch = 1;
                            }
                        }
                        else if(percent >= 10 && percent <= 30){
                            if(randNum < 60){
                                flagCatch = 1;
                            }
                        }
                        else{
                            if(randNum < 90){
                                flagCatch = 1;
                            }
                        }
                    }

                    ballCnt--;
                    // flag를 주면 반복 코드도 줄일 수 있다. 포켓몬을 잡았다고 flag를 줬기에 아래 잡은 후 코드를 위에 반복하지 않아도 된다!
                    if(flagCatch){ 
                        printf("포켓몬을 잡았다!! 별명을 입력해주세요!! : ");
                        scanf("%s", catchPokemonName);

                        strcpy(myPokemon[currentMyPokemonCnt].name, PL[wildPokemonNumber].name);
                        strcpy(myPokemon[currentMyPokemonCnt].nickName, catchPokemonName);
                        strcpy(myPokemon[currentMyPokemonCnt].property, PL[wildPokemonNumber].property);
                        myPokemon[currentMyPokemonCnt].hp = PL[wildPokemonNumber].hp;
                        myPokemon[currentMyPokemonCnt].power = PL[wildPokemonNumber].power;

                        // 인덱스 정보를 활용하기 위해 처음에 Cnt가 1이니 대입 먼저하고 ++해야 대입도 되고 Cnt도 2마리로 된다.
                        currentMyPokemonCnt++;
                        PL[wildPokemonNumber].hp = wildPokemonWholeHp;

                        if(currentMyPokemonCnt == 6){
                            //귀찮아서 그냥 여기 썼다 개선때 다시 보자
                            char moreGame;
                            do{
                                printf("6마리 수집 완료!! 넌 이제 내꺼야!!!! 여행을 더 떠나볼까(Y/N)? : ");
                                scanf("%c", &moreGame);
                            }while(moreGame != 'Y' || moreGame != 'N');

                            if(moreGame == 'Y'){
                                currentMyPokemonCnt = 1;
                                flagMoreGame = 1;
                                flagMyPokemonCnt = 1;
                                break;
                            }
                            else{
                                flagMyPokemonCnt = 1;
                                break;
                            }
                        }
                        break;
                    }
                    else{
                        printf("포켓몬이 몬스터볼을 빠져 나왔다\n");

                        // 이것 역시 가져다 씀 함수화 필수!!!
                        strcpy(fightingPokemon, PL[wildPokemonNumber].property);
                        strcpy(enemyPokemon, myPokemon[fightMyPokomomNum].property);
                        printf("적 %s가 공격한다! \n", PL[wildPokemonNumber].name);

                        // 속성 차이 함수로 만들자
                        attackPower = fight(fightingPokemon, enemyPokemon);

                        myPokemon[fightMyPokomomNum].hp -= PL[wildPokemonNumber].power*attackPower;
                        printf("%s의 남은 체력 : %d\n", myPokemon[fightMyPokomomNum].name, myPokemon[fightMyPokomomNum].hp);
                        printf("%s의 남은 체력 : %d\n\n", PL[wildPokemonNumber].name, PL[wildPokemonNumber].hp);
                    }
                }
                else{
                    //물약을 선택한 경우
                    myPokemon[fightMyPokomomNum].hp += 300;
                    portionCnt--;
                    printf("%s의 체력디 (300) 회복되었습니다.\n", myPokemon[fightMyPokomomNum].name);

                    // 이것 역시 가져다 씀 함수화 필수!!!
                    strcpy(fightingPokemon, PL[wildPokemonNumber].property);
                    strcpy(enemyPokemon, myPokemon[fightMyPokomomNum].property);
                    printf("적 %s가 공격한다! \n", PL[wildPokemonNumber].name);

                    // 속성 차이 함수로 만들자
                    attackPower = fight(fightingPokemon, enemyPokemon);

                    myPokemon[fightMyPokomomNum].hp -= PL[wildPokemonNumber].power*attackPower;
                    printf("%s의 남은 체력 : %d\n", myPokemon[fightMyPokomomNum].name, myPokemon[fightMyPokomomNum].hp);
                    printf("%s의 남은 체력 : %d\n\n", PL[wildPokemonNumber].name, PL[wildPokemonNumber].hp);
                }
            }
            // 0을 누르면 5번으로 이동
            else{
               break;
            }
            if(flagRun){
            // 내가 도망가면 
            PL[wildPokemonNumber].hp = wildPokemonWholeHp; //내가 도망가면 적 체력 원상복구
            flagRun = 0;
            break;
        }
        }
        if(flagEnemyDown){
            PL[wildPokemonNumber].hp = wildPokemonWholeHp; //적이 쓰러지면 적 체력 원상복구
            flagEnemyDown = 0;
            break;
        }
        if(flagEnemyRun){
            PL[wildPokemonNumber].hp = wildPokemonWholeHp; //적이 도망가면 적 체력 원상복구
            flagEnemyRun = 0;
            break;
        }
    }
}










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
    int money = 10000;

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