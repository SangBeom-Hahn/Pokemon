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
int currentMyPokemonCnt = 2;
//�� ���ϸ� ����Ʈ �߿��� ó������ �ο�� �� ���ϸ��� ������ 0�� �ε����� + �̷��� ������Ÿ������ �س����� ���߿��� ��ﳪ����?(�ٽ� ���� ������ �̰� �� ��� 1�� ���� ����)
int fightMyPokomomNum = 0; //�̰� �ƿ� ������ ������ �� ��?? 1���� ������ �� �����ϸ� ���� ����Ʈ�� �ٸ� ���ϸ��� ���� �� �� �ִ�/
int selectNextMyPokemon;
int ballCnt, portionCnt;

// ������ �����ٰ� ������ �ϴ� �Լ�
double fight(char fightingPokemon[], char enemyPokemon[]){
    if(strcmp(fightingPokemon, "��") == 0) {
        if(strcmp(enemyPokemon, "Ǯ") == 0){
            printf("ȿ���� �����ߴ�(Ǫ��~)  ");
            return 1.5;
        }
        else if(strcmp(enemyPokemon, "��") == 0){
            printf("ȿ���� ������ �� �ϴ�.(�Ĥ̤̤�)  ");
            return 0.5;
        }
        else   
            return 1;
        



    }
    else if( strcmp(fightingPokemon, "��") == 0){
        if(strcmp(enemyPokemon, "��") == 0){
            printf("ȿ���� �����ߴ�(Ǫ��~).  ");
            return 1.5;
        } 
        else if(strcmp(enemyPokemon, "Ǯ") == 0){
            printf("ȿ���� ������ �� �ϴ�.(�Ĥ̤̤�)  ");
            return 0.5;
        }
        else   
            return 1;            



    }
    else{
        if(strcmp(enemyPokemon, "��") == 0){
            printf("ȿ���� �����ߴ�(Ǫ��~).  ");
            return 1.5;
        }  
        else if(strcmp(enemyPokemon, "��") == 0){
            printf("ȿ���� ������ �� �ϴ�.(�Ĥ̤̤�)  ");
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

    // �ڡڡ� ��û �߿��Ѱ� �� ������ ��ġ�� ������ ������ 6���� �ݺ��� �ǵ� ó�� ���۸� 0�̰� �� �Ŀ��� �ݺ��� ����Ǹ鼭 �ٲ� ���̱� ������ �̷��� ��쿡�� 
    // while�� �ۿ� ���� �ǰڴ�!!

    //���� fightmypokemon ���⿴�� ����

    while(1){
        //��5�� �ݺ� �κ�
        printf("================================\n");
        printf("\t���� �ȴ� ��... ... ...\n");
        
        sleep(1+rand()%3);

        int flagEnemyDown = 0, flagEnemyRun = 0; // �̰͵� �� ���� ������? �̰Ŵ� 6���� ���̴� flag�� ������ ������ 0�̴�. "�̰Ŵ� 6�� �߿� break�� �ϸ� 5���� �������Ѵ�.!!" -> �׷��� ����
        int wildPokemonNumber, sixRepeat, wildPokemonWholeHp;
        double attackPower;
        srand(time(NULL));

        printf("================================\n");
        printf("\t�߻��� ���ϸ��� ��Ÿ����!\n");

        wildPokemonNumber = rand() % 13;
        wildPokemonWholeHp = PL[wildPokemonNumber].hp;
        printf("�̸��� : %s\n�Ӽ��� : %s\nü���� : %d\n���ݷ��� : %d\n", PL[wildPokemonNumber].name, PL[wildPokemonNumber].property, \
        PL[wildPokemonNumber].hp, PL[wildPokemonNumber].power);


        while(1){
            // 6������ �ݺ�
            // ���⼭ Pokemon.c�� Pokemon List�� �������ϴµ� �̷��� �ȵż� ��ü���� �� ����??
            printf("1. ���� 2. ����ġ�� 3. ���� ����>>");
            scanf("%d", &sixRepeat);



            if(sixRepeat == 1){
                //���⿡ �Ӽ� �� vs �� ���� -> �̷� ��ȭ�� �� �� ���� ���� ���� ������ �ؾ��Ѵ� �̰ž�
                strcpy(fightingPokemon, myPokemon[fightMyPokomomNum].property);
                strcpy(enemyPokemon, PL[wildPokemonNumber].property);
                printf("�� %s�� �����Ѵ�! \n", myPokemon[fightMyPokomomNum].name);

                // �Ӽ� ���� �Լ��� ������
                attackPower = fight(fightingPokemon, enemyPokemon);

                PL[wildPokemonNumber].hp -= myPokemon[fightMyPokomomNum].power*attackPower;
                printf("%s�� ���� ü�� : %d\n", myPokemon[fightMyPokomomNum].name, myPokemon[fightMyPokomomNum].hp);
                printf("%s�� ���� ü�� : %d\n\n", PL[wildPokemonNumber].name, PL[wildPokemonNumber].hp);
                
                sleep(2);
            
                strcpy(fightingPokemon, PL[wildPokemonNumber].property);
                strcpy(enemyPokemon, myPokemon[fightMyPokomomNum].property);
                printf("�� %s�� �����Ѵ�! \n", PL[wildPokemonNumber].name);

                // �Ӽ� ���� �Լ��� ������
                attackPower = fight(fightingPokemon, enemyPokemon);

                myPokemon[fightMyPokomomNum].hp -= PL[wildPokemonNumber].power*attackPower;
                printf("%s�� ���� ü�� : %d\n", myPokemon[fightMyPokomomNum].name, myPokemon[fightMyPokomomNum].hp);
                printf("%s�� ���� ü�� : %d\n\n", PL[wildPokemonNumber].name, PL[wildPokemonNumber].hp);

/*======================================================================================================================================================================*/



                // �� ���ϸ��� �������� ���ϸ� ����� ��������
                // if(myPokemon[fightMyPokomomNum].hp < 0){
                //     //�� ���ϸ� ����Ʈ�� ��� �ֵ��� for�� ������(�̶� �迭ũ��� ������ �ֱ� ������ ��� ������[���� �뷮]�� �ʿ��� �ű���!) ��� hp�� 0�̸� 4������ �̵�
                //     if()

                    // for(int i=0; i<currentMyPokemonCnt; i++){
                    //     printf("%d.   %s   %s   %d\n", i+1, myPokemon[i].name, myPokemon[i].property, myPokemon[i].hp); //���� �� ���ϸ��� ������ ��Ÿ���� ������ ������ ������ �迭�� ���� ���ڴ�.

                    
                    // }
                    // printf("��� ���ϸ��� �������ðڽ��ϱ�? : ");
                    // scanf("%d", &selectNextMyPokemon); //����ü �迭���� ��¥�� ü���� ������ ���� ���ص� �ǳ�?/
                    // fightMyPokomomNum = selectNextMyPokemon-1;
                
                // }


/*======================================================================================================================================================================*/

                if(PL[wildPokemonNumber].hp < 0){
                    printf("�� ���ϸ��� �����߷ȴ�!\n");
                    flagEnemyDown = 1;
                    break;
                }
                else if (PL[wildPokemonNumber].hp == 0)
                {
                    /* code */
                    printf("�� ���ϸ��� ��������....!\n");
                    flagEnemyRun = 1;
                    break;

                }
                
            }
            else if(sixRepeat == 2){
                //����ġ��
                int randNum = rand() % 100 + 1;
                int percentage = (int)(PL[wildPokemonNumber].hp/wildPokemonNumber) * 100;
                if(percentage == 100){
                    if(randNum <= 10)
                        printf("���� ����!(��� ����)\n");
                    else
                        printf("���� ���� �̤Ф̤�\n");
                }
                else if (percentage >= 50 && percentage < 100)
                {
                    /* code */
                    if(randNum <= 40)
                        printf("���� ����!(��� ����)\n");
                    else
                        printf("���� ���� �̤Ф̤�\n");
                }
                else if (percentage >= 25 && percentage < 50)
                {
                    /* code */
                    if(randNum <= 70)
                        printf("���� ����!(��� ����)\n");
                    else
                        printf("���� ���� �̤Ф̤�\n");
                }
                else{
                    if(randNum <= 90)
                        printf("���� ����!(��� ����)\n");
                    else
                        printf("���� ���� �̤Ф̤�\n");
                }                    
            }
            else if(sixRepeat == 3){ //������ if�ȿ� �ݺ����̿��߸� �ϴµ� �� �ѹ� �õ��ϰ� if�� ������ ������ �ƴϴ�!!
                // 6���� �ݺ��ϴٰ� 3�� ������ ���� ����
                int choose;

                printf("1. ���� ��    x%d\n",ballCnt);
                printf("2. ȸ�� ����    x%d\n",portionCnt);

                printf("� �������� ����Ͻðڽ��ϱ�? : ");
                scanf("%d", &choose);
                if(choose == 1){
                    // ���� ���� ������ ���
                    if(PL[wildPokemonNumber].hp >= wildPokemonWholeHp * 0.5){
                        //�� �κ��� ���ؼ� �����Դ� ���� �ȴٸ� ���߿� �Լ�ȭ���� ������ �� �κ��� ������ ���� �� �͵� �� fight�� �Լ�ȭ �صξ ������ ���̴�!!/

                        printf("ü���� �� ����ּ���......\n");
                        strcpy(fightingPokemon, PL[wildPokemonNumber].property);
                        strcpy(enemyPokemon, myPokemon[fightMyPokomomNum].property);
                        printf("�� %s�� �����Ѵ�! \n", PL[wildPokemonNumber].name);

                        // �Ӽ� ���� �Լ��� ������
                        attackPower = fight(fightingPokemon, enemyPokemon);

                        myPokemon[fightMyPokomomNum].hp -= PL[wildPokemonNumber].power*attackPower;
                        printf("%s�� ���� ü�� : %d\n", myPokemon[fightMyPokomomNum].name, myPokemon[fightMyPokomomNum].hp);
                        printf("%s�� ���� ü�� : %d\n\n", PL[wildPokemonNumber].name, PL[wildPokemonNumber].hp);
                    }
                    else{
                        // �ۼ�Ʈ�� ��� �ٲ� �Ŵϱ� ����!
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
            // 0�� ������ 5������ �̵�
            else{
               break;
            }
            // �� ���ϸ��� �������ų�, ���ϸ��� ��Ұų�, 0�� �����ų� �ϸ� break�� �ؼ� �� �̻� 6.�� �� �������� ����
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


// ���� �Լ�
void main(void){
    FILE *fp;
    fp = fopen("pokemon_list.txt", "r");

    // PokemonList PL[13]; ���� ���⿴�µ� travel �Լ����� ���� ���� �������� ����.
    int pokemonListSize = sizeof(PL) / sizeof(PL[0]);
    int i=0, myPokemonNum;
    int travelQA;
    char myPokemonNickName[20];
    char enter;
    int money = 10000;

    if(fp == NULL){
        printf("������ �����ϴ�.");
        exit(1);
    }

    while(1){
        
        if(feof(fp))
            break;

        fscanf(fp, "%s %s %d %d", &PL[i].name, &PL[i].property, &PL[i].power, &PL[i].hp);
        i++;
    }
    


    printf("================================================\n\t\t���ϸ���\n\tpress enter key to start\n");
    enter = getch();
    if(enter){ //���۰� ���� ���͸� �ؾ� ���͸� �ι� ������ ���� ����
        // ���⿡ ������ �����ϴ� �Լ��� ���� �� ���� -> ���� ���� �Լ� play�� ���� ���� ����(�ݺ��Ǵ� �ڵ�� ������ �Լ�ȭ���� �̰Ŵ� ���� �����ϸ� ���� �� ���� ������ ��..!)
        // �Ѹ���� �� ���� play��� �Լ� �� �ϳ��� �θ� �������� ���� �� ���� ���� ����� �̰���!!/
        srand(time(NULL));

        do{ // ������ ����ؾ� �Ʒ��� ������ �� ���� ���̽㿡���� ���Ⱑ while - if ������ ���� ���ڴ�./ do-while�� ���ĺ��� while�� ���� �͵� ����
            printf("��� ���ϸ��� ���ðڽ��ϱ�? 1. ���̸�, 2. �̻��ؾ�, 3. ���α�\n");
            scanf("%d", &myPokemonNum);
            if(myPokemonNum <= 0 || myPokemonNum > 3)
                puts("������ �̻��մϴ�!!!");
            
        }while(myPokemonNum <= 0 || myPokemonNum > 3);
        
        printf("������ �Է��ϼ���!\n>>");
        scanf("%s", myPokemonNickName);
        strcpy(myPokemon[0].nickName, myPokemonNickName);
        
        if(myPokemonNum == 1){
            strcpy(myPokemon[0].name, "���̸�");
            strcpy(myPokemon[0].property, "��");
            myPokemon[0].hp = 500 + rand() % 501;
            myPokemon[0].power = 100 + rand() % 51;
        }
        else if (myPokemonNum == 2)
        {
            /* code */
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
        // else{ // ��¥ �������� �� �Ѱ� ����!!!!!!!!!!!!!!!!!!!! �̷� ������ �׻� �������� �����ϴ� ��츦 �׻� ����ؾ��Ѵ�.
        //         printf("������ �Ѿ �߸��� �Է��Դϴ�.\n");               
        // }

        printf("�̸��� : %s\n�Ӽ��� : %s\n������ : %s\nü���� : %d\n���ݷ��� : %d\n", myPokemon[0].name, myPokemon[0].property, myPokemon[0].nickName, myPokemon[0].hp, myPokemon[0].power);
    }

    while(1){
        //4�� �ݺ�
        printf("===========================\n\t\t������ �����ðڽ��ϱ�?\n\t1. ��\t2. �ƴϿ�(���忩�μ���)\t3. ��������(���ͺ��� ȸ�� ���� ���)");
        scanf("%d", &travelQA);
        // �Է��� �ȵǴ� ������ ���� ���ڸ� ������ �ذ��,,,,,��z �� �Է� ���������� %d�� �س��� ���� ���� �� �߸� ��ǻ�� �߸� ����!!


        // �̰͵��� ó������ 0�ε� �� ���� �����ϴ� �ݺ����� ����� ������ �ٽ� 0�� �Ǹ� �ȵǱ� ������ �ۿ� �����ؾ��Ѵ�.
        // �ٵ� �� 4�� �ݺ��� ���� 0������ �����ؾ��ؼ� ����!!!
        // int ballCnt, portionCnt; �ٵ� �ο� �� ����ϳ�... �̷��� ������ ���°� �¾�??

        if(travelQA == 1){
            travel();
        }
        else if(travelQA == 3){
            // whatBuy�� �ۿ� ���� �ȿ� ���� ������� �ų� -> flag�� ������ ����� ���� �� �߿������� �ܼ� �Է��� �������
            int whatBuy;
            char yesOrNo;
            while(1){
                printf("\t\t\t���� ���� �ݾ� : %d\n", money);
                printf("\t 1. ���ͺ�\t1000\n");
                printf("\t 2. ȸ������\t2500\n");

                puts("� �������� ��ðڽ��ϱ�? : ");
                scanf("%d", &whatBuy);

                printf("������ ������!!"); //�� �ؿ� ���ε��� ���� �Ⱦ �� ���̶� ������ �� �ִ� �� �÷ȴ�.
                if(whatBuy == 0){
                    break;
                }
                // ��� : ���� if�� �ȿ� ���ε��� ���� ������ ��¿ �� ����,,,
                // �ƴ� �� �� 2500���� ���� ���ϴ� �Ŷ� 1000���� ���� ���ϴ°� �޶� �̷���,,,
                else if(whatBuy == 1){
                    scanf("%d", &ballCnt);
                    printf("���� �Ͻðڽ��ϱ�? (y/n)");
                    // yesOrNo = getchar(); // scanf�� getchar�� ���̰� �����̶� �ֳ� ������ =  ����.
                    getchar();
                    scanf("%c", &yesOrNo);
                    
                    if(yesOrNo == 'y'){
                        if(1000 * ballCnt < money){
                            puts("���������� ���� ���� �����Ͽ���");
                            money -= (1000*ballCnt);
                        }
                        else{
                            puts("���� �����Ͽ� �� �� �����ϴ�.");    
                        }
                    }
                    else{
                        puts("n�� �Է��ϼ̽��ϴ�.");
                    }
                }
                else{
                    scanf("%d", &portionCnt);
                    puts("���� �Ͻðڽ��ϱ�? (y/n)");
                    getchar();
                    yesOrNo = getchar(); // scanf�� getchar�� ���̰� �����̶� �ֳ� ������
                    
                    if(yesOrNo == 'y'){
                        if(2500 * portionCnt < money){
                            puts("���������� ȸ�������� �����Ͽ���");
                            money -= (2500*portionCnt);
                        }
                        else{
                            puts("���� �����Ͽ� �� �� �����ϴ�.");    
                        }
                    }
                    else{
                        puts("n�� �Է��ϼ̽��ϴ�.");
                    }
                }
            }    
        }
        // else{

        // }
    }
    fclose(fp);
}