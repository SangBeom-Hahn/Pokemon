# include<stdio.h>
# include<stdlib.h>
# include<windows.h>
# include<unistd.h> //sleep �Լ� ��������� ����
# include"Pokemon.h"

// 1���� ������ ������ ������ �Լ�
void travel(void){
    int turn = 0; // ¦���� ���� �����ϴ� �Ű� Ȧ���� ��밡 �����Ѵ�.
    int flagFinish=0, flagMyPokemonCnt = 0;
    fightMyPokomomNum = 0;

    /*
    �ڡڡ� ��û �߿��Ѱ� �� ������ ��ġ�� ������ ������ 6���� �ݺ��� �ǵ� ó�� ���۸� 0�̰� �� �Ŀ��� �ݺ��� ����Ǹ鼭 �ٲ� ���̱� ������ �̷��� ��쿡�� 
    while�� �ۿ� ���� �ǰڴ�!!
    ���� fightMyPokemonNum ���⿴�� ����
    */
    while(1){
        //��5�� �ݺ� �κ�
        if(flagFinish){
            break;
        }
        if(flagMyPokemonCnt){
            break;
        }

        printf("================================\n");
        printf("\t���� �ȴ� ��... ... ...\n");
        
        sleep(1+rand()%3);

        int flagEnemyDown = 0, flagEnemyRun = 0; // �̰͵� �� ���� ������? �̰Ŵ� 6���� ���̴� flag�� ������ ������ 0�̴�. "�̰Ŵ� 6�� �߿� break�� �ϸ� 5���� �������Ѵ�.!!" -> �׷��� ����
        int sixRepeat, wildPokemonWholeHp;
        int flagCatch = 0, flagRun = 0;
        char catchPokemonName[10];
        srand(time(NULL));

        printf("================================\n");
        printf("\t�߻��� ���ϸ��� ��Ÿ����!\n");

        // �߻� ���ϸ� ��ȣ ��ǥ ����
        wildPokemonNumber = rand() % 13;
        wildPokemonWholeHp = PL[wildPokemonNumber].hp;
        printf("�̸��� : %s\n�Ӽ��� : %s\nü���� : %d\n���ݷ��� : %d\n", PL[wildPokemonNumber].name, PL[wildPokemonNumber].property, \
        PL[wildPokemonNumber].hp, PL[wildPokemonNumber].power);

        while(1){
            if(flagFinish){
                PL[wildPokemonNumber].hp = wildPokemonWholeHp; //���󺹱�
                break;
            }

            // 6������ �ݺ�
            // ���⼭ Pokemon.c�� Pokemon List�� �������ϴµ� �̷��� �ȵż� ��ü���� �� ����??
            printf("1. ���� 2. ����ġ�� 3. ���� ����>>");
            scanf("%d", &sixRepeat);

            if(sixRepeat == 1){
                int i=0; // �� ���ϸ�� ü�� ���� 0���� ���� ���� i

                //���⿡ �Ӽ� �� vs �� ���� -> �̷� ��ȭ�� �� �� ���� ���� ���� ������ �ؾ��Ѵ� �̰ž�

                // strcpy�� �� ���� �ߴ�? ���߿� ���� ���˾ƺ���� ���� ���ϸ��� �� �Ŵ� ��ǥ����ó�� �� ��
                strcpy(fightingPokemon, myPokemon[fightMyPokomomNum].property); strcpy(enemyPokemon, PL[wildPokemonNumber].property);
                printf("�� [%s]�� �����Ѵ�! \n", myPokemon[fightMyPokomomNum].name);

                // �Ӽ� ���� �Լ��� ������
                attackPower = fight(fightingPokemon, enemyPokemon);

                PL[wildPokemonNumber].hp -= myPokemon[fightMyPokomomNum].power*attackPower;
                printf("[%s]�� ���� ü�� : %d\n", myPokemon[fightMyPokomomNum].name, myPokemon[fightMyPokomomNum].hp);
                printf("[%s]�� ���� ü�� : %d\n\n", PL[wildPokemonNumber].name, PL[wildPokemonNumber].hp);
                
                sleep(2);
            
                enemyAttackFunc();

/*======================================================================================================================================================================*/



                if(myPokemon[fightMyPokomomNum].hp < 0){
                    myPokemon[fightMyPokomomNum].hp = 0; // �� ���ϸ� ü���� ������ �Ǿ� 0���� ����

                    // �� ���ϸ� ����Ʈ�� ��� �ֵ��� for�� ������(�̶� �迭ũ��� ������ �ֱ� ������ ��� ������[���� �뷮]�� �ʿ��� �ű���!) ��� hp�� 0�̸� 4������ �̵�
                    for(i=0; i<currentMyPokemonCnt; i++){
                        if(myPokemon[i].hp != 0){
                            break;
                        }
                    }
                    
                    if(i == currentMyPokemonCnt){
                        printf("�� ���� įį������....\n\n�����ϰ� ��� ��� ���ϸ��� ü���� ȸ���Ͽ����ϴ�.\n");
                        for(int j=0; j<currentMyPokemonCnt; j++){
                            myPokemon[j].hp = 1000; //�� ���� ��� ���� �������� ��� �� ü���� 1000���� ����~~
                        }
                    
                        flagFinish = 1;
                        break;
                    }

                    for(int i=0; i<currentMyPokemonCnt; i++){
                        printf("%d.   %s   %s   %d\n", i+1, myPokemon[i].name, myPokemon[i].property, myPokemon[i].hp); //���� �� ���ϸ��� ����(currentMyPokemonCnt)�� ��Ÿ���� ������ ������ ������ �迭�� ���� ���ڴ�.

                    }
                    printf("��� ���ϸ��� �������ðڽ��ϱ�? : ");
                    scanf("%d", &selectNextMyPokemon); //����ü �迭���� ��¥�� ü���� ������ ���� ���ص� �ǳ�?/
                    fightMyPokomomNum = selectNextMyPokemon-1;
                    continue;
                }


/*======================================================================================================================================================================*/

                if(PL[wildPokemonNumber].hp < 0){
                    printf("�� ���ϸ��� �����߷ȴ�!\n");
                    PL[wildPokemonNumber].hp = wildPokemonWholeHp; //���󺹱�
                    flagEnemyDown = 1;
                    break;
                }
                else if (PL[wildPokemonNumber].hp == 0)
                {
                    /* code */
                    printf("�� ���ϸ��� ��������....!\n");
                    PL[wildPokemonNumber].hp = wildPokemonWholeHp; //���󺹱�
                    flagEnemyRun = 1;
                    break;

                }
                
            }
            else if(sixRepeat == 2){
                //����ġ��
                int randNum = rand() % 100 + 1;
                int percentage = (int)(PL[wildPokemonNumber].hp/wildPokemonNumber) * 100;
                if(percentage == 100){
                    if(randNum <= 10){
                        //���⵵ flag�� ó�� �����ϰڴ�! �ݺ��Ǵ� ���� �� flag�� ����??
                        printf("���� ����!(��� ����)\n");
                        flagRun = 1;
                    }
                    else
                        printf("���� ���� �̤Ф̤�\n");
                }
                else if (percentage >= 50 && percentage < 100)
                {
                    /* code */
                    if(randNum <= 40){
                        printf("���� ����!(��� ����)\n");
                        flagRun = 1;
                    }
                    else
                        printf("���� ���� �̤Ф̤�\n");
                }
                else if (percentage >= 25 && percentage < 50)
                {
                    /* code */
                    if(randNum <= 70){
                        printf("���� ����!(��� ����)\n");
                        flagRun = 1;
                    }
                    else
                        printf("���� ���� �̤Ф̤�\n");
                }
                else{
                    if(randNum <= 90){
                        printf("���� ����!(��� ����)\n");
                        flagRun = 1;
                    }
                    else
                        printf("���� ���� �̤Ф̤�\n");
                }                    
            }
            else if(sixRepeat == 3){ // 6���� �ݺ��ϴٰ� 3�� ������ ���� ����
                int choose;
                if(ballCnt == 0 && portionCnt == 0){
                    // �ƹ��͵� ���� ��쿡�� �ٸ� ������ ����
                    printf("������ ����ֽ��ϴ�.\n");
                    continue;
                }

                printf("1. ���� ��    x%d\n",ballCnt);
                printf("2. ȸ�� ����    x%d\n",portionCnt);

                printf("� �������� ����Ͻðڽ��ϱ�? : ");
                scanf("%d", &choose);
                if(choose == 1){
                    // ���� ���� ������ ���
                    if(PL[wildPokemonNumber].hp >= wildPokemonWholeHp * 0.5){
                        //�� �κ��� ���ؼ� �����Դ� ���� �ȴٸ� ���߿� �Լ�ȭ���� ������ �� �κ��� ������ ���� �� �͵� �� fight�� �Լ�ȭ �صξ ������ ���̴�!!/
                        printf("ü���� �� ����ּ���......\n\n");

                        strcpy(fightingPokemon, PL[wildPokemonNumber].property);
                        strcpy(enemyPokemon, myPokemon[fightMyPokomomNum].property);
                        printf("�� %s�� �����Ѵ�! \n", PL[wildPokemonNumber].name);

                        // �Ӽ� ���� �Լ��� ������
                        attackPower = fight(fightingPokemon, enemyPokemon);

                        myPokemon[fightMyPokomomNum].hp -= PL[wildPokemonNumber].power*attackPower;
                        printf("%s�� ���� ü�� : %d\n", myPokemon[fightMyPokomomNum].name, myPokemon[fightMyPokomomNum].hp);
                        printf("%s�� ���� ü�� : %d\n\n", PL[wildPokemonNumber].name, PL[wildPokemonNumber].hp);
                        continue;
                    }
                    else{
                        //������ ������ ����ϱ� ���� 5������ ���� ���������� ��� �ο����ϴ� 6������ ����

                        // �ۼ�Ʈ�� ��� �ٲ� �Ŵϱ� ����!
                        int percent = (int)(PL[wildPokemonNumber].hp/wildPokemonWholeHp)*100;
                        int randNum = rand() % 100 + 1;

                        if( percent >= 30 && percent <=50 ){
                            if(randNum < 30){
                                // �ڵ� �ݺ��� ����
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
                    // flag�� �ָ� �ݺ� �ڵ嵵 ���� �� �ִ�. ���ϸ��� ��Ҵٰ� flag�� ��⿡ �Ʒ� ���� �� �ڵ带 ���� �ݺ����� �ʾƵ� �ȴ�!
                    if(flagCatch){ 
                        printf("���ϸ��� ��Ҵ�!! ������ �Է����ּ���!! : ");
                        scanf("%s", catchPokemonName);

                        strcpy(myPokemon[currentMyPokemonCnt].name, PL[wildPokemonNumber].name);
                        strcpy(myPokemon[currentMyPokemonCnt].nickName, catchPokemonName);
                        strcpy(myPokemon[currentMyPokemonCnt].property, PL[wildPokemonNumber].property);
                        myPokemon[currentMyPokemonCnt].hp = PL[wildPokemonNumber].hp;
                        myPokemon[currentMyPokemonCnt].power = PL[wildPokemonNumber].power;

                        // �ε��� ������ Ȱ���ϱ� ���� ó���� Cnt�� 1�̴� ���� �����ϰ� ++�ؾ� ���Ե� �ǰ� Cnt�� 2������ �ȴ�.
                        currentMyPokemonCnt++;
                        PL[wildPokemonNumber].hp = wildPokemonWholeHp;

                        if(currentMyPokemonCnt == 6){
                            //�����Ƽ� �׳� ���� ��� ������ �ٽ� ����
                            char moreGame;
                            do{
                                printf("6���� ���� �Ϸ�!! �� ���� ������!!!! ������ �� ��������(Y/N)? : ");
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
                        printf("���ϸ��� ���ͺ��� ���� ���Դ�\n");

                        // �̰� ���� ������ �� �Լ�ȭ �ʼ�!!!
                        strcpy(fightingPokemon, PL[wildPokemonNumber].property);
                        strcpy(enemyPokemon, myPokemon[fightMyPokomomNum].property);
                        printf("�� %s�� �����Ѵ�! \n", PL[wildPokemonNumber].name);

                        // �Ӽ� ���� �Լ��� ������
                        attackPower = fight(fightingPokemon, enemyPokemon);

                        myPokemon[fightMyPokomomNum].hp -= PL[wildPokemonNumber].power*attackPower;
                        printf("%s�� ���� ü�� : %d\n", myPokemon[fightMyPokomomNum].name, myPokemon[fightMyPokomomNum].hp);
                        printf("%s�� ���� ü�� : %d\n\n", PL[wildPokemonNumber].name, PL[wildPokemonNumber].hp);
                    }
                }
                else{
                    //������ ������ ���
                    myPokemon[fightMyPokomomNum].hp += 300;
                    portionCnt--;
                    printf("%s�� ü�µ� (300) ȸ���Ǿ����ϴ�.\n", myPokemon[fightMyPokomomNum].name);

                    // �̰� ���� ������ �� �Լ�ȭ �ʼ�!!!
                    strcpy(fightingPokemon, PL[wildPokemonNumber].property);
                    strcpy(enemyPokemon, myPokemon[fightMyPokomomNum].property);
                    printf("�� %s�� �����Ѵ�! \n", PL[wildPokemonNumber].name);

                    // �Ӽ� ���� �Լ��� ������
                    attackPower = fight(fightingPokemon, enemyPokemon);

                    myPokemon[fightMyPokomomNum].hp -= PL[wildPokemonNumber].power*attackPower;
                    printf("%s�� ���� ü�� : %d\n", myPokemon[fightMyPokomomNum].name, myPokemon[fightMyPokomomNum].hp);
                    printf("%s�� ���� ü�� : %d\n\n", PL[wildPokemonNumber].name, PL[wildPokemonNumber].hp);
                }
            }
            // 0�� ������ 5������ �̵�
            else{
               break;
            }
            if(flagRun){
            // ���� �������� 
            PL[wildPokemonNumber].hp = wildPokemonWholeHp; //���� �������� �� ü�� ���󺹱�
            flagRun = 0;
            break;
        }
        }
        if(flagEnemyDown){
            PL[wildPokemonNumber].hp = wildPokemonWholeHp; //���� �������� �� ü�� ���󺹱�
            flagEnemyDown = 0;
            break;
        }
        if(flagEnemyRun){
            PL[wildPokemonNumber].hp = wildPokemonWholeHp; //���� �������� �� ü�� ���󺹱�
            flagEnemyRun = 0;
            break;
        }
    }
}
