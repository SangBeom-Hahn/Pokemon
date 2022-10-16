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
int currentMyPokemonCnt = 2;
//내 포켓몬 리스트 중에서 처음으로 싸우는 내 포켓몬은 무조건 0번 인덱스임 + 이런걸 프로토타입으로 해놓으면 나중에도 기억나겠지?(다시 보는 시점에 이거 쓴 기억 1도 없음 ㅋㅋ)
int fightMyPokomomNum = 0; //이거 아예 밖으로 빼야할 수 도?? 1번을 눌렀을 때 내포켓몬 말고 리스트의 다른 포켓몬이 나올 수 도 있다/
int selectNextMyPokemon;
int ballCnt, portionCnt;

// 여행을 떠나다가 공격을 하는 함수
double fight(char fightingPokemon[], char enemyPokemon[]){
    if(strcmp(fightingPokemon, "불") == 0) {
        if(strcmp(enemyPokemon, "풀") == 0){
            printf("효과가 굉장했다(푸슝~)  ");
            return 1.5;
        }
        else if(strcmp(enemyPokemon, "물") == 0){
            printf("효과가 별로인 듯 하다.(후ㅜㅜㅜ)  ");
            return 0.5;
        }
        else   
            return 1;
        



    }
    else if( strcmp(fightingPokemon, "물") == 0){
        if(strcmp(enemyPokemon, "불") == 0){
            printf("효과가 굉장했다(푸슝~).  ");
            return 1.5;
        } 
        else if(strcmp(enemyPokemon, "풀") == 0){
            printf("효과가 별로인 듯 하다.(후ㅜㅜㅜ)  ");
            return 0.5;
        }
        else   
            return 1;            



    }
    else{
        if(strcmp(enemyPokemon, "물") == 0){
            printf("효과가 굉장했다(푸슝~).  ");
            return 1.5;
        }  
        else if(strcmp(enemyPokemon, "불") == 0){
            printf("효과가 별로인 듯 하다.(후ㅜㅜㅜ)  ");
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

    //원래 fightmypokemon 여기였음 ㅋㅋ

    while(1){
        //★5번 반복 부분
        printf("================================\n");
        printf("\t길을 걷는 중... ... ...\n");
        
        sleep(1+rand()%3);

        int flagEnemyDown = 0, flagEnemyRun = 0; // 이것도 왜 여기 있을까? 이거는 6번에 쓰이는 flag로 시작은 무조건 0이다. "이거는 6번 중에 break을 하면 5번도 나가야한다.!!" -> 그래서 여기
        int wildPokemonNumber, sixRepeat, wildPokemonWholeHp;
        double attackPower;
        srand(time(NULL));

        printf("================================\n");
        printf("\t야생의 포켓몬이 나타났다!\n");

        wildPokemonNumber = rand() % 13;
        wildPokemonWholeHp = PL[wildPokemonNumber].hp;
        printf("이름은 : %s\n속성은 : %s\n체력은 : %d\n공격력은 : %d\n", PL[wildPokemonNumber].name, PL[wildPokemonNumber].property, \
        PL[wildPokemonNumber].hp, PL[wildPokemonNumber].power);


        while(1){
            // 6번으로 반복
            // 여기서 Pokemon.c의 Pokemon List를 꺼내야하는데 이런게 안돼서 객체지향 언어를 쓰나??
            printf("1. 공격 2. 도망치기 3. 가방 열기>>");
            scanf("%d", &sixRepeat);



            if(sixRepeat == 1){
                //여기에 속성 강 vs 약 넣자 -> 이런 변화와 할 일 예정 등을 형상 관리를 해야한다 이거야
                strcpy(fightingPokemon, myPokemon[fightMyPokomomNum].property);
                strcpy(enemyPokemon, PL[wildPokemonNumber].property);
                printf("내 %s가 공격한다! \n", myPokemon[fightMyPokomomNum].name);

                // 속성 차이 함수로 만들자
                attackPower = fight(fightingPokemon, enemyPokemon);

                PL[wildPokemonNumber].hp -= myPokemon[fightMyPokomomNum].power*attackPower;
                printf("%s의 남은 체력 : %d\n", myPokemon[fightMyPokomomNum].name, myPokemon[fightMyPokomomNum].hp);
                printf("%s의 남은 체력 : %d\n\n", PL[wildPokemonNumber].name, PL[wildPokemonNumber].hp);
                
                sleep(2);
            
                strcpy(fightingPokemon, PL[wildPokemonNumber].property);
                strcpy(enemyPokemon, myPokemon[fightMyPokomomNum].property);
                printf("적 %s가 공격한다! \n", PL[wildPokemonNumber].name);

                // 속성 차이 함수로 만들자
                attackPower = fight(fightingPokemon, enemyPokemon);

                myPokemon[fightMyPokomomNum].hp -= PL[wildPokemonNumber].power*attackPower;
                printf("%s의 남은 체력 : %d\n", myPokemon[fightMyPokomomNum].name, myPokemon[fightMyPokomomNum].hp);
                printf("%s의 남은 체력 : %d\n\n", PL[wildPokemonNumber].name, PL[wildPokemonNumber].hp);

/*======================================================================================================================================================================*/



                // 내 포켓몬이 쓰러지면 포켓몬 잡고나서 생각하자
                // if(myPokemon[fightMyPokomomNum].hp < 0){
                //     //내 포켓몬 리스트의 모든 애들을 for문 돌려서(이때 배열크기는 정해져 있기 때문에 요소 개수를[현재 용량]이 필요한 거구나!) 모두 hp가 0이면 4번으로 이동
                //     if()

                    // for(int i=0; i<currentMyPokemonCnt; i++){
                    //     printf("%d.   %s   %s   %d\n", i+1, myPokemon[i].name, myPokemon[i].property, myPokemon[i].hp); //현재 내 포켓몬의 개수를 나타내는 변수도 마련해 놓으면 배열에 쓰기 좋겠다.

                    
                    // }
                    // printf("어느 포켓몬을 내보내시겠습니까? : ");
                    // scanf("%d", &selectNextMyPokemon); //구조체 배열에서 진짜로 체력을 깎으면 대입 안해도 되나?/
                    // fightMyPokomomNum = selectNextMyPokemon-1;
                
                // }


/*======================================================================================================================================================================*/

                if(PL[wildPokemonNumber].hp < 0){
                    printf("적 포켓몬을 쓰러뜨렸다!\n");
                    flagEnemyDown = 1;
                    break;
                }
                else if (PL[wildPokemonNumber].hp == 0)
                {
                    /* code */
                    printf("적 포켓몬이 도망갔다....!\n");
                    flagEnemyRun = 1;
                    break;

                }
                
            }
            else if(sixRepeat == 2){
                //도망치기
                int randNum = rand() % 100 + 1;
                int percentage = (int)(PL[wildPokemonNumber].hp/wildPokemonNumber) * 100;
                if(percentage == 100){
                    if(randNum <= 10)
                        printf("도망 성공!(룰루 랄라)\n");
                    else
                        printf("도망 실패 ㅜㅠㅜㅠ\n");
                }
                else if (percentage >= 50 && percentage < 100)
                {
                    /* code */
                    if(randNum <= 40)
                        printf("도망 성공!(룰루 랄라)\n");
                    else
                        printf("도망 실패 ㅜㅠㅜㅠ\n");
                }
                else if (percentage >= 25 && percentage < 50)
                {
                    /* code */
                    if(randNum <= 70)
                        printf("도망 성공!(룰루 랄라)\n");
                    else
                        printf("도망 실패 ㅜㅠㅜㅠ\n");
                }
                else{
                    if(randNum <= 90)
                        printf("도망 성공!(룰루 랄라)\n");
                    else
                        printf("도망 실패 ㅜㅠㅜㅠ\n");
                }                    
            }
            else if(sixRepeat == 3){ //상점은 if안에 반복문이여야만 하는데 얜 한번 시도하고 if문 밖으로 나가서 아니다!!
                // 6번을 반복하다가 3을 누르면 가방 열기
                int choose;

                printf("1. 몬스터 볼    x%d\n",ballCnt);
                printf("2. 회복 물약    x%d\n",portionCnt);

                printf("어떤 아이템을 사용하시겠습니까? : ");
                scanf("%d", &choose);
                if(choose == 1){
                    // 몬스터 볼을 선택한 경우
                    if(PL[wildPokemonNumber].hp >= wildPokemonWholeHp * 0.5){
                        //이 부분을 위해서 가져왔다 만약 된다면 나중에 함수화하자 하지만 이 부분을 위에서 가져 온 것도 다 fight를 함수화 해두어서 가능한 일이다!!/

                        printf("체력을 더 깎아주세요......\n");
                        strcpy(fightingPokemon, PL[wildPokemonNumber].property);
                        strcpy(enemyPokemon, myPokemon[fightMyPokomomNum].property);
                        printf("적 %s가 공격한다! \n", PL[wildPokemonNumber].name);

                        // 속성 차이 함수로 만들자
                        attackPower = fight(fightingPokemon, enemyPokemon);

                        myPokemon[fightMyPokomomNum].hp -= PL[wildPokemonNumber].power*attackPower;
                        printf("%s의 남은 체력 : %d\n", myPokemon[fightMyPokomomNum].name, myPokemon[fightMyPokomomNum].hp);
                        printf("%s의 남은 체력 : %d\n\n", PL[wildPokemonNumber].name, PL[wildPokemonNumber].hp);
                    }
                    else{
                        // 퍼센트가 계속 바뀔 거니까 여기!
                        int percent = (int)(PL[wildPokemonNumber].hp/wildPokemonWholeHp)*100;
                        int randNum = rand() % 100 + 1;

                        if( percent >= 30 && percent <=50 ){
                            if(randNum < 30){

                            }
                        }
                        else if(percent >= 10 && percent <= 30){
                            if(randNum < 60){

                            }
                        }
                        else{
                            if(randNum < 90){

                            }
                        }
                    }

                    ballCnt--;
                }
                else{

                }






            }
            // 0을 누르면 5번으로 이동
            else{
               break;
            }
            // 내 포켓몬이 쓰러지거나, 포켓몬을 잡았거나, 0을 누르거나 하면 break를 해서 더 이상 6.이 안 나오도록 하자
        }
        if(flagEnemyDown){
            flagEnemyDown = 0;
            break;
        }
        if(flagEnemyRun){
            flagEnemyRun = 0;
            break;
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
    int money = 10000;

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
        printf("===========================\n\t\t여행을 떠나시겠습니까?\n\t1. 네\t2. 아니요(저장여부선택)\t3. 상점가기(몬스터볼과 회복 물약 사기)");
        scanf("%d", &travelQA);
        // 입력이 안되는 문제는 별명에 숫자를 넣으면 해결됨,,,,,ㅋz 하 입력 형식지정자 %d로 해놨음 역시 모든건 내 잘못 컴퓨터 잘못 없다!!


        // 이것들은 처음에는 0인데 살 것을 선택하는 반복문이 실행될 때마다 다시 0이 되면 안되기 때문에 밖에 선언해야한다.
        // 근데 또 4를 반복할 때는 0개부터 시작해야해서 여기!!!
        // int ballCnt, portionCnt; 근데 싸울 때 써야하네... 이렇게 밖으로 가는게 맞아??

        if(travelQA == 1){
            travel();
        }
        else if(travelQA == 3){
            // whatBuy는 밖에 쓰는 안에 쓰는 상관없는 거네 -> flag나 수량은 기록이 남는 게 중요하지만 단순 입력은 상관없지
            int whatBuy;
            char yesOrNo;
            while(1){
                printf("\t\t\t현재 소유 금액 : %d\n", money);
                printf("\t 1. 몬스터볼\t1000\n");
                printf("\t 2. 회복물약\t2500\n");

                puts("어떤 아이템을 사시겠습니까? : ");
                scanf("%d", &whatBuy);

                printf("수량을 고르세요!!"); //↓ 밑에 따로따로 쓰기 싫어서 한 줄이라도 공유할 수 있는 거 올렸다.
                if(whatBuy == 0){
                    break;
                }
                // 고민 : 나는 if문 안에 따로따로 쓰기 싫은데 어쩔 수 없나,,,
                // 아니 살 때 2500원에 개수 곱하는 거랑 1000원에 개수 곱하는게 달라서 이래ㅏ,,,
                else if(whatBuy == 1){
                    scanf("%d", &ballCnt);
                    printf("구매 하시겠습니까? (y/n)");
                    // yesOrNo = getchar(); // scanf와 getchar의 차이가 조금이라도 있나 보려고 =  없다.
                    getchar();
                    scanf("%c", &yesOrNo);
                    
                    if(yesOrNo == 'y'){
                        if(1000 * ballCnt < money){
                            puts("성공적으로 몬스터 볼을 구매하였다");
                            money -= (1000*ballCnt);
                        }
                        else{
                            puts("돈이 부족하여 살 수 없습니다.");    
                        }
                    }
                    else{
                        puts("n을 입력하셨습니다.");
                    }
                }
                else{
                    scanf("%d", &portionCnt);
                    puts("구매 하시겠습니까? (y/n)");
                    getchar();
                    yesOrNo = getchar(); // scanf와 getchar의 차이가 조금이라도 있나 보려고
                    
                    if(yesOrNo == 'y'){
                        if(2500 * portionCnt < money){
                            puts("성공적으로 회복물약을 구매하였다");
                            money -= (2500*portionCnt);
                        }
                        else{
                            puts("돈이 부족하여 살 수 없습니다.");    
                        }
                    }
                    else{
                        puts("n을 입력하셨습니다.");
                    }
                }
            }    
        }
        // else{

        // }
    }
    fclose(fp);
}