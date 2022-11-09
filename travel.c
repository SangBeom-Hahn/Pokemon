# include<stdio.h>
# include<stdlib.h>
# include<windows.h>
# include<unistd.h> //sleep 함수 명시적으로 선언
# include"Pokemon.h"

// 1번을 누르면 여행을 떠나는 함수
void travel(void){
    int turn = 0; // 짝수면 내가 공격하는 거고 홀수면 상대가 공격한다.
    int flagFinish=0, flagMyPokemonCnt = 0;
    fightMyPokomomNum = 0;

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
        int sixRepeat, wildPokemonWholeHp;
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
            
                enemyAttackFunc();

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
