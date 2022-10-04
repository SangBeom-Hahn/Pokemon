# include<stdio.h>
# include<stdlib.h>
# include<string.h>
# include<conio.h> // getch �Լ� ��������� ����
# include<time.h>
# include<unistd.h> //sleep �Լ� ��������� ����
# include "Pokemon.h"

PokemonList PL[13]; //������ ���̸� �˸� ���� �ٵ�
MyPokemon myPokemon; //���� ������ ������ ��

//����!!!!!!! �Ӽ� ��

double fight(char fightingPokemon[], char enemyPokemon[]){
    if(strcmp(fightingPokemon, "��") == 0) {
        if(strcmp(enemyPokemon, "Ǯ") == 0){
            printf("ȿ���� �����ߴ�.");
            return 1.5;
        }
        else if(strcmp(enemyPokemon, "��") == 0){
            printf("ȿ���� ������ �� �ϴ�.");
            return 0.5;
        }
        else   
            return 1;
        



    }
    else if( strcmp(fightingPokemon, "��") == 0){
        if(strcmp(enemyPokemon, "��") == 0){
            printf("ȿ���� �����ߴ�.");
            return 1.5;
        } 
        else if(strcmp(enemyPokemon, "Ǯ") == 0){
            printf("ȿ���� ������ �� �ϴ�.");
            return 0.5;
        }
        else   
            return 1;            



    }
    else{
        if(strcmp(enemyPokemon, "��") == 0){
            printf("ȿ���� �����ߴ�.");
            return 1.5;
        }  
        else if(strcmp(enemyPokemon, "��") == 0){
            printf("ȿ���� ������ �� �ϴ�.");
            return 0.5;
        }
        else   
            return 1;
    }
}

void travel(void){
    int turn = 0; // ¦���� ���� �����ϴ� �Ű� Ȧ���� ��밡 �����Ѵ�.
    char fightingPokemon[10], enemyPokemon[10];

    printf("================================\n");
    printf("\t���� �ȴ� ��... ... ...\n");
    
    sleep(1+rand()%3);

    int wildPokemonNumber, sixRepeat;
    double attackPower;
    srand(time(NULL));

    printf("================================\n");
    printf("\t�߻��� ���ϸ��� ��Ÿ����!\n");

    wildPokemonNumber = rand() % 13;
    printf("�̸��� : %s\n�Ӽ��� : %s\nü���� : %d\n���ݷ��� : %d\n", PL[wildPokemonNumber].name, PL[wildPokemonNumber].property, \
    PL[wildPokemonNumber].hp, PL[wildPokemonNumber].power);

    while(1){
        // ������ �ݺ�
        // ���⼭ Pokemon.c�� Pokemon List�� �������ϴµ� �̷��� �ȵż� ��ü���� �� ����??
        printf("1. ���� 2. ����ġ�� 3. ���� ����>>");
        scanf("%d", &sixRepeat);

        if(sixRepeat == 1){
            //���⿡ �Ӽ� �� vs �� ���� -> �̷� ���� ���� ������ �ؾ��Ѵ� �̰ž�
            
            strcpy(fightingPokemon, myPokemon.property);
            strcpy(enemyPokemon, PL[wildPokemonNumber].property);
            printf("�� %s�� �����Ѵ�! \n", myPokemon.name);

            // �Ӽ� ���� �Լ��� ������
            attackPower = fight(fightingPokemon, enemyPokemon);

            PL[wildPokemonNumber].hp -= myPokemon.power*attackPower;
            printf("%s�� ���� ü�� : %d\n", myPokemon.name, myPokemon.hp);
            printf("%s�� ���� ü�� : %d\n\n", PL[wildPokemonNumber].name, PL[wildPokemonNumber].hp);
            
            sleep(2);
           
            strcpy(fightingPokemon, PL[wildPokemonNumber].property);
            strcpy(enemyPokemon, myPokemon.property);
            printf("�� %s�� �����Ѵ�! \n", PL[wildPokemonNumber].name);

            // �Ӽ� ���� �Լ��� ������
            attackPower = fight(fightingPokemon, enemyPokemon);

            myPokemon.hp -= PL[wildPokemonNumber].power*attackPower;
            printf("%s�� ���� ü�� : %d\n", myPokemon.name, myPokemon.hp);
            printf("%s�� ���� ü�� : %d\n\n", PL[wildPokemonNumber].name, PL[wildPokemonNumber].hp);
        }
        else if(sixRepeat == 2){

        }
        else{

        }



        // �� ���ϸ��� �������ų�, ���ϸ��� ��Ұų�, 0�� �����ų� �ϸ� break�� �ؼ� �� �̻� ���� �� �������� ����
    }
}



void main(void){
    FILE *fp;
    fp = fopen("pokemon_list.txt", "r");

    // PokemonList PL[13]; ���� ���⿴�µ� travel �Լ����� ���� ���� ������ ����.
    int pokemonListSize = sizeof(PL) / sizeof(PL[0]);
    int i=0, myPokemonNum;
    int travelQA;
    char myPokemonNickName[20];
    char enter;

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
        // �Ѹ���� �� ���� play��� �Լ��� �� �ϳ��� �θ� ���� �� ���� ���� ����� �̰���!!/
        srand(time(NULL));

        do{ // ������ ����ؾ� �Ʒ��� ������ �� ���� ���̽㿡���� ���Ⱑ while - if ������ ���� ���ڴ�./ do-while�� ���ĺ��� while�� ���� �͵� ����
            printf("��� ���ϸ��� ���ðڽ��ϱ�? 1. ���̸�, 2. �̻��ؾ�, 3. ���α�\n");
            scanf("%d", &myPokemonNum);
            if(myPokemonNum <= 0 || myPokemonNum > 3)
                puts("������ �̻��մϴ�!!!");
            
        }while(myPokemonNum <= 0 || myPokemonNum > 3);
        
        printf("������ �Է��ϼ���!\n>>");
        scanf("%d", &myPokemonNickName);
        strcpy(myPokemon.nickName, myPokemonNickName);
        
        if(myPokemonNum == 1){
            strcpy(myPokemon.name, "���̸�");
            strcpy(myPokemon.property, "��");
            myPokemon.hp = 500 + rand() % 501;
            myPokemon.power = 100 + rand() % 51;
        }
        else if (myPokemonNum == 2)
        {
            /* code */
            strcpy(myPokemon.name, "�̻��ؾ�");
            strcpy(myPokemon.property, "Ǯ");
            myPokemon.hp = 500 + rand() % 501;
            myPokemon.power = 100 + rand() % 51;
        }
        else if(myPokemonNum == 3){
            strcpy(myPokemon.name, "������");
            strcpy(myPokemon.property, "��");
            myPokemon.hp = 500 + rand() % 501;
            myPokemon.power = 100 + rand() % 51;
        }   
        // else{ // ��¥ �������� �� �Ѱ� ����!!!!!!!!!!!!!!!!!!!! �̷� ������ �׻� �������� ���и� �׻� ����ؾ��Ѵ�.
        //         printf("������ �Ѿ �߸��� �Է��Դϴ�.\n");               
        // }

        printf("�̸��� : %s\n�Ӽ��� : %s\n������ : %s\nü���� : %d\n���ݷ��� : %d\n", myPokemon.name, myPokemon.property, myPokemon.nickName, myPokemon.hp, myPokemon.power);
    }   

        printf("===========================\n\t\t������ �����ðڽ��ϱ�?\n\t1. ��\t2. �ƴϿ�(���忩�μ���)\t3. ��������(���ͺ��� ȸ�� ���� ���)\n");
        scanf("%d", &travelQA);
         // �Է��� �ȵǴ� ������ ���� ���ڸ� ������ �ذ��,,,,,����

        if(travelQA == 1){
            travel();
        }
        else if(travelQA == 2){
            
        }
        else{
            
        }

    fclose(fp);
}