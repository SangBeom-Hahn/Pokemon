#ifndef HEADER_H
# define HEADER_H

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

#endif