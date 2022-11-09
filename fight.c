# include<stdio.h>
# include<stdlib.h>
# include<windows.h>
# include<unistd.h> //sleep 함수 명시적으로 선언
# include"Pokemon.h"

// 여행을 떠나다가 공격을 하는 함수
double fight(char fightingPokemon[], char enemyPokemon[]){
    if(strcmp(fightingPokemon, "불") == 0) {
        if(strcmp(enemyPokemon, "풀") == 0){
            printf("효과가 굉장했다(푸슝~)  \n\n");
            return 1.5;
        }
        else if(strcmp(enemyPokemon, "물") == 0){
            printf("효과가 별로인 듯 하다.(후ㅜㅜㅜ)  \n\n");
            return 0.5;
        }
        else   
            return 1;

    }
    else if( strcmp(fightingPokemon, "물") == 0){
        if(strcmp(enemyPokemon, "불") == 0){
            printf("효과가 굉장했다(푸슝~).  \n\n");
            return 1.5;
        } 
        else if(strcmp(enemyPokemon, "풀") == 0){
            printf("효과가 별로인 듯 하다.(후ㅜㅜㅜ)  \n\n");
            return 0.5;
        }
        else   
            return 1;            



    }
    else{
        if(strcmp(enemyPokemon, "물") == 0){
            printf("효과가 굉장했다(푸슝~).  \n\n");
            return 1.5;
        }  
        else if(strcmp(enemyPokemon, "불") == 0){
            printf("효과가 별로인 듯 하다.(후ㅜㅜㅜ)  \n\n");
            return 0.5;
        }
        else   
            return 1;
    }
}
