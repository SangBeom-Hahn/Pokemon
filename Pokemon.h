#ifndef HEADER_H
# define HEADER_H

/* <1. 원래 전역에 있던 애들> */
typedef struct{
    char name[20]; //파이리
    char property[10]; //불
    int power; //12
    int hp; //500
    int wholeHp; //500 변경
}PokemonList;

typedef struct 
{
    /* data */
    char name[20]; //파이리
    char nickName[100]; //꽁꽁이
    char property[10]; //불
    int power; //12
    int hp; //500
}MyPokemon;

// extern PokemonList PL[13]; //파일의 길이를 알면 좋을 텐데
// extern MyPokemon myPokemon[6]; //같은 이유로 밖으로 뺌

// //처음에는 위에 두개였는데 점점 쌓인다...
// extern int currentMyPokemonCnt;
// //내 포켓몬 리스트 중에서 처음으로 싸우는 내 포켓몬은 무조건 0번 인덱스임 + 이런걸 프로토타입으로 해놓으면 나중에도 기억나겠지?(다시 보는 시점에 이거 쓴 기억 1도 없음 ㅋㅋ)
// extern int fightMyPokomomNum; //이거 아예 밖으로 빼야할 수 도?? 1번을 눌렀을 때 내포켓몬 말고 리스트의 다른 포켓몬이 나올 수 도 있다/
// extern int selectNextMyPokemon;
// extern int ballCnt, portionCnt;

// //지금까지 flag는 전역에는 없었는데 이건 main이랑 travel을 거치는 flag라서 전역!
// extern int flagMoreGame;



// /* <2. travel 함수에 있던 애들> */
// extern int wildPokemonNumber;
// extern char fightingPokemon[10], enemyPokemon[10];
// extern double attackPower;

// /* <3. main 함수에 있던 애들*/
// extern int money;


// /*함수들*/
// extern void enemyAttackFunc();
// extern double fight(char fightingPokemon[], char enemyPokemon[]);
// extern void travel(void);
// extern void buy(int* cnt, int price, char item[]);

#endif