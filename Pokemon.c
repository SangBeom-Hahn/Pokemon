# include<stdio.h>
# include<stdlib.h>
# include<string.h>
# include<conio.h> // getch �Լ� ��������� ����
# include<time.h>
# include<unistd.h> //sleep �Լ� ��������� ����
# include "Pokemon.h"

/*�� �������� ���� ����Ʈ�� ���� �ο�� ���ϸ� ������ ����� ����Ʈ���� �ϳ��� ������ �����ϴ� ��!!!*/

PokemonList PL[13]; //������ ���̸� �˸� ���� �ٵ�
MyPokemon myPokemon[6]; //���� ������ ������ ��

//ó������ ���� �ΰ����µ� ���� ���δ�...
int currentMyPokemonCnt = 1;
//�� ���ϸ� ����Ʈ �߿��� ó������ �ο�� �� ���ϸ��� ������ 0�� �ε����� + �̷��� ������Ÿ������ �س����� ���߿��� ��ﳪ����?(�ٽ� ���� ������ �̰� �� ��� 1�� ���� ����)
int fightMyPokomomNum = 0; //�̰� �ƿ� ������ ������ �� ��?? 1���� ������ �� �����ϸ� ���� ����Ʈ�� �ٸ� ���ϸ��� ���� �� �� �ִ�/
int selectNextMyPokemon;
int ballCnt, portionCnt;

//���ݱ��� flag�� �������� �����µ� �̰� main�̶� travel�� ��ġ�� flag�� ����!
int flagMoreGame;

// ������ �����ٰ� ������ �ϴ� �Լ�
double fight(char fightingPokemon[], char enemyPokemon[]){
    if(strcmp(fightingPokemon, "��") == 0) {
        if(strcmp(enemyPokemon, "Ǯ") == 0){
            printf("ȿ���� �����ߴ�(Ǫ��~)  \n\n");
            return 1.5;
        }
        else if(strcmp(enemyPokemon, "��") == 0){
            printf("ȿ���� ������ �� �ϴ�.(�Ĥ̤̤�)  \n\n");
            return 0.5;
        }
        else   
            return 1;
        



    }
    else if( strcmp(fightingPokemon, "��") == 0){
        if(strcmp(enemyPokemon, "��") == 0){
            printf("ȿ���� �����ߴ�(Ǫ��~).  \n\n");
            return 1.5;
        } 
        else if(strcmp(enemyPokemon, "Ǯ") == 0){
            printf("ȿ���� ������ �� �ϴ�.(�Ĥ̤̤�)  \n\n");
            return 0.5;
        }
        else   
            return 1;            



    }
    else{
        if(strcmp(enemyPokemon, "��") == 0){
            printf("ȿ���� �����ߴ�(Ǫ��~).  \n\n");
            return 1.5;
        }  
        else if(strcmp(enemyPokemon, "��") == 0){
            printf("ȿ���� ������ �� �ϴ�.(�Ĥ̤̤�)  \n\n");
            return 0.5;
        }
        else   
            return 1;
    }
}














// 1���� ������ ������ ������ �Լ�
void travel(void){
    int turn = 0; // ¦���� ���� �����ϴ� �Ű� Ȧ���� ��밡 �����Ѵ�.
    char fightingPokemon[10], enemyPokemon[10];
    int flagFinish=0, flagMyPokemonCnt = 0;

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
        int wildPokemonNumber, sixRepeat, wildPokemonWholeHp;
        double attackPower;
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
            
                strcpy(fightingPokemon, PL[wildPokemonNumber].property); strcpy(enemyPokemon, myPokemon[fightMyPokomomNum].property);
                printf("�� [%s]�� �����Ѵ�! \n", PL[wildPokemonNumber].name);

                // �Ӽ� ���� �Լ��� ������
                attackPower = fight(fightingPokemon, enemyPokemon);

                myPokemon[fightMyPokomomNum].hp -= PL[wildPokemonNumber].power*attackPower;
                printf("[%s]�� ���� ü�� : %d\n", myPokemon[fightMyPokomomNum].name, myPokemon[fightMyPokomomNum].hp);
                printf("[%s]�� ���� ü�� : %d\n\n", PL[wildPokemonNumber].name, PL[wildPokemonNumber].hp);

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










// ���� �Լ�
void main(void){
    FILE *fp;
    fp = fopen("pokemon_list.txt", "r");

    // PokemonList PL[13]; ���� ���⿴�µ� travel �Լ����� ���� ���� ���� ������ ����.
    // �� ������������ ������ �ҷ��ͼ� ����ü �迭�� �����ϱ� ���� �͵�� main �Լ��� �ִ°� �´�. 
    int pokemonListSize = sizeof(PL) / sizeof(PL[0]);
    int i=0, myPokemonNum;
    int travelQA;
    char myPokemonNickName[20];
    char enter;
    int money = 10000;

    // �׻� �����ϴ� ��츦 �����ؾ� �Ѵ�.
    if(fp == NULL){
        printf("������ �����ϴ�.");
        exit(1);
    }

    while(1){
        if(feof(fp))
            break;

        fscanf(fp, "%s %s %d %d %d", &PL[i].name, &PL[i].property, &PL[i].power, &PL[i].hp, &PL[i].wholeHp);
        i++;
    }
    
    printf("================================================\n\t\t���ϸ���\n\tpress enter key to start\n");

    //���۰� ���� ���͸� �ؾ� ���͸� �ι� ������ ���� ����
    enter = getch();
    if(enter){ 
        /*
        ���⿡ ������ �����ϴ� �Լ��� ���� �� ���� -> ���� ���� �Լ� play�� ���� ���� ����(�ݺ��Ǵ� �ڵ�� ������ �Լ�ȭ���� �̰Ŵ� ���� �����ϸ� ���� �� ���� ������ ��..!)
        �Ѹ���� �� ���� play��� �Լ� �� �ϳ��� �θ� �������� ���� �� ���� ���� ����� �̰���!!/
        */
        
        srand(time(NULL));
        // ������ ����ؾ� �Ʒ��� ������ �� ���� ���̽㿡���� ���Ⱑ while - if ������ ���� ���ڴ�./ do-while�� ���ĺ��� while�� ���� �͵� ����
        do{ 
            printf("��� ���ϸ��� ���ðڽ��ϱ�? 1. ���̸�, 2. �̻��ؾ�, 3. ���α�\n");
            scanf("%d", &myPokemonNum);
            if(myPokemonNum <= 0 || myPokemonNum > 3) // ������ do-while ���� if���� �δ� ���� ���� �ڵ��ΰ� ������ �� �ʿ䰡 ���� ���� �˻縦 ������ ��..
                puts("������ �̻��մϴ�!!!");
            
        }while(myPokemonNum <= 0 || myPokemonNum > 3);
        
        printf("������ �Է��ϼ���!\n>>");
        // strcpy(myPokemon[0].nickName, myPokemonNickName); ������ �̰� ���µ� �ٷ� ����ü ����� ���� ����
        scanf("%s", myPokemon[0].nickName);
        
        // �̷��� ���� ���� �� �� ���� ����� �ڵ�� �ݺ����� ������ �Լ�ȭ���� �ʾƵ� �ȴ�.
        if(myPokemonNum == 1){
            strcpy(myPokemon[0].name, "���̸�");
            strcpy(myPokemon[0].property, "��");
            myPokemon[0].hp = 50000 + rand() % 501;
            myPokemon[0].power = 150 + rand() % 51;
        }
        else if (myPokemonNum == 2)
        {
            strcpy(myPokemon[0].name, "�̻��ؾ�");
            strcpy(myPokemon[0].property, "Ǯ");
            myPokemon[0].hp = 500 + rand() % 501;
            myPokemon[0].power = 100 + rand() % 51;
        }
        else if(myPokemonNum == 3){
            strcpy(myPokemon[0].name, "������");
            strcpy(myPokemon[0].property, "��");
            myPokemon[0].hp = 500 + rand() % 501;
            myPokemon[0].power = 100 + rand() % 51;
        }   
        else{ 
            // ��¥ �������� �� �Ѱ� ����!!!!!!! �̷� ������ �׻� �������� �����ϴ� ��츦 �׻� ����ؾ��Ѵ�.
                printf("������ �Ѿ �߸��� �Է��Դϴ�.\n");
        }

        printf("�̸��� : %s\n�Ӽ��� : %s\n������ : %s\nü���� : %d\n���ݷ��� : %d\n", myPokemon[0].name, myPokemon[0].property, myPokemon[0].nickName, myPokemon[0].hp, myPokemon[0].power);
    }

    while(1){
        // (4)�� �ݺ�(������Ʈ ���������� �ݺ��Ǵ� �κ�)
        printf("===========================\n\t\t������ �����ðڽ��ϱ�?\n\t1. ��\t2. �ƴϿ�(���忩�μ���)\t3. ��������(���ͺ��� ȸ�� ���� ���)");
        scanf("%d", &travelQA);
        // �Է��� �ȵǴ� ������ ���� ���ڸ� ������ �ذ��,,,,,��z �� �Է� ���������� %d�� �س��� ���� ���� �� �߸�, ��ǻ�� �߸� ����!!

        /*
        (int ballCnt, portionCnt;)
        �̰͵��� ó������ 0�ε� ������ ���� �ݺ����� ����� ������ �ٽ� 0�� �Ǹ� �ȵǱ� ������ �ۿ� �����ؾ��Ѵ�.
        �ٵ� �� 4�� �ݺ��� ���� 0������ �����ؾ��ؼ� ������ �� ����.
        �ٵ� �ο� �� ����ϳ�... �̷��� ������ ���°� �¾�??

        -> ���� �� �ۿ����� ���̸� �ۿ� �����ϴ� ���� ��¿ �� ����. ������ 4���� �ݺ��� �� 0������ �ٽ� �����ϴ� ���� flag�� �ּ� �ذ��Ѵ�.
        */

        if(travelQA == 1){
            travel();
            if(flagMoreGame)
                continue;
        }
        else if(travelQA == 3){
            // whatBuy�� �ۿ� ���� �ȿ� ���� ������� �ų� -> flag�� ������ ����� ���� �� �߿������� �ܼ� �Է��� �������
            int whatBuy;
            while(1){
                printf("\t\t\t���� ���� �ݾ� : %d\n", money);
                printf("\t 1. ���ͺ�\t1000\n");
                printf("\t 2. ȸ������\t2500\n");

                puts("� �������� ��ðڽ��ϱ�? (0) �Է½� ���� ����) : ");
                scanf("%d", &whatBuy);
                if(whatBuy == 0){ // �̰� ���⿡ ��� 0�� ������ �� ������ �������� �ȳ����µ� �׷��� if-else���� ������.
                    break;
                }
                if(whatBuy < 1 && whatBuy > 2){
                    puts("������ ��� �Է��Դϴ�.(1 or 2)");
                    continue;
                }

                printf("������ ������!!"); //�� �ؿ� ���ε��� ���� �Ⱦ �� ���̶� ������ �� �ִ� �� �÷ȴ�. �̷� �͵� ��������� �߾���Ѵ�.
                
                /*
                ��� : ���� if�� �ȿ� ���ε��� ���� ������ ��¿ �� ����,,,
                �ƴ� �� �� 2500���� ���� ���ϴ� �Ŷ� 1000���� ���� ���ϴ°� �޶� �̷�,,,
                */
                if(whatBuy == 1){
                    scanf("%d", &ballCnt);
                    buy(&ballCnt, 1000, "���ͺ�");
                }
                else{
                    scanf("%d", &portionCnt);
                    buy(&portionCnt, 2500, "ȸ������");
                }
            }    
        }
        // ������ ������ ���� ���
        else{
            puts("������ �����մϴ�.");
            break;
        }
    }
    fclose(fp);
}