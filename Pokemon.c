# include<stdio.h>
# include<stdlib.h>
# include<string.h>
# include<conio.h> // getch �Լ� ��������� ����
# include<time.h>

typedef struct{
    char name[20]; //���̸�
    char property[10]; //��
    int power; //12
    int hp; //500
}PokemonList;

typedef struct 
{
    /* data */
    char name[20]; //���̸�
    char nickName[100]; //�ǲ���
    char property[10]; //��
    int power; //12
    int hp; //500
}MyPokemon;


void main(void){
    FILE *fp;
    fp = fopen("pokemon_list.txt", "r");

    PokemonList PL[13]; //������ ���̸� �˸� ���� �ٵ�
    int pokemonListSize = sizeof(PL) / sizeof(PL[0]);
    int i=0, myPokemonNum, travelQA;
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
        // ���⿡ ������ �����ϴ� �Լ��� ���� �� ���� -> ���� ���� �Լ�play�� ���� ���� ����
        MyPokemon myPokemon;
        srand(time(NULL));

        do{ // ������ ����ؾ� �Ϸ��� ������ �� ���� ���̽㿡���� ���Ⱑ while - if ������ ���� ���ڴ�.
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

        printf("================================================\n\t\t������ �����ðڽ��ϱ�?\n\t1. ��\t2. �ƴϿ�(�����μ���)\t3. ��������(���ͺ��� ȸ�� ���� ���\n>>");
        scanf("%d", &travelQA);

    fclose(fp);
}