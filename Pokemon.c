# include<stdio.h>
# include<stdlib.h>
# include<string.h>
# include<conio.h> // getch �Լ� ��������� ����

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
    int i=0, myPokemonNum;
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

        do{ 
            printf("��� ���ϸ��� ���ðڽ��ϱ�? 1. ���̸�, 2. �̻��ؾ�, 3. ���α�\n");
            scanf(">> %d", &myPokemonNum);
            printf("%d", myPokemonNum);
            getchar();
            printf("%d", myPokemonNum);

            printf("������ �Է��ϼ���!\n>>");
            scanf("%d", &myPokemonNickName);
            strcpy(myPokemon.nickName, myPokemonNickName);

            printf("%d", myPokemonNum);

            if(myPokemonNum == 1){
                printf("%d", myPokemonNum);
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
            else{ // ��¥ �������� �� �Ѱ� ����!!!!!!!!!!!!!!!!!!!! �̷� ������ �׻� �������� ���и� �׻� ����ؾ��Ѵ�.
                printf("������ �Ѿ �߸��� �Է��Դϴ�.\n"); 
            }
        }while(myPokemonNum<0 || myPokemonNum >3);

        printf("�̸��� : %s\n�Ӽ��� : %s\n������ : %s\nü���� : %d\n���ݷ��� : %d\n", myPokemon.name, myPokemon.property, myPokemon.nickName, myPokemon.hp, myPokemon.power);
    }        

    fclose(fp);
}