# include<stdio.h>
# include<stdlib.h>
# include<string.h>

typedef struct{
    char name[20]; //���̸�
    char property[10]; //��
    int power; //12
    int hp; //500
}PokemonList;

void main(void){
    FILE *fp;
    fp = fopen("pokemon_list.txt", "r");

    PokemonList PL[13]; //������ ���̸� �˸� ���� �ٵ�
    int pokemonListSize = sizeof(PL) / sizeof(PL[0]);
    int i=0;

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
    
    for(int i=0; i<pokemonListSize; i++){
        printf("%s %s %d %d\n", PL[i].name, PL[i].property, PL[i].power, PL[i].hp);
    }

    printf("================================================\n\t\t���ϸ���\n\tpress enter key to start");

    fclose(fp);
}