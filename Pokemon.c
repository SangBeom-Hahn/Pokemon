# include<stdio.h>
# include<stdlib.h>
# include<string.h>
# include<conio.h> // getch �Լ� ��������� ����
# include<time.h>
# include<unistd.h> //sleep �Լ� ��������� ����
# include "Pokemon.h"

/*�� �������� ���� ����Ʈ�� ���� �ο�� ���ϸ� ������ ����� ����Ʈ���� �ϳ��� ������ �����ϴ� ��!!!*/

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
    money = 10000; // ��� ������ ������ �ʱ�ȭ�� �� �� ����. ���� �����ϰ� ����ϴ� ������ �� ���� �ʱ�ȭ

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