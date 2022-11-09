# include"Pokemon.h"
# include<stdio.h>
# include<string.h>
# include<stdlib.h>
# include"Pokemon.h"

void enemyAttackFunc(){
    strcpy(fightingPokemon, PL[wildPokemonNumber].property);
    strcpy(enemyPokemon, myPokemon[fightMyPokomomNum].property);
    printf("적 [%s]가 공격한다! \n", PL[wildPokemonNumber].name);

    // 속성 차이 함수로 만들자
    attackPower = fight(fightingPokemon, enemyPokemon);

    myPokemon[fightMyPokomomNum].hp -= PL[wildPokemonNumber].power*attackPower;
    printf("[%s]의 남은 체력 : %d\n", myPokemon[fightMyPokomomNum].name, myPokemon[fightMyPokomomNum].hp);
    printf("[%s]의 남은 체력 : %d\n\n", PL[wildPokemonNumber].name, PL[wildPokemonNumber].hp);
}

