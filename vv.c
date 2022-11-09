// if(whatBuy == 1){
//     scanf("%d", &ballCnt);
//     buy(&ballCnt, 1000);
// }
// else{
//     scanf("%d", &portionCnt);
//     buy(&portionCnt, 2500);
// }


# include<stdio.h>
# include<stdlib.h>
# include<windows.h>
# include<unistd.h> //sleep 함수 명시적으로 선언
# include"Pokemon.h"

// 볼이냐 물약이냐에 따라 달라지는 부분 1. cnt, 2 money
// 와,, 이런 센스 price를 만들고 각각 인자를 다르게 주는 센스!!!
void buy(int* cnt, int price, char item){
    char yesOrNo;
    printf("구매 하시겠습니까? (y/n)");

    // yesOrNo = getchar(); // scanf와 getchar의 차이가 조금이라도 있나 보려고 =  없다.
    getchar();
    scanf("%c", &yesOrNo);
    
    if(yesOrNo == 'y'){
        if(1000 * (*cnt) <= money){
            printf("성공적으로 %s을 구매하였다", item);
            money -= (price*(*cnt));
        }
        else{
            puts("돈이 부족하여 살 수 없습니다.");    
        }
    }
    else{
        puts("n을 입력하셨습니다.");
    }
}


// 예전 코드
// if(whatBuy == 1){ // else if(whatBuy == 1){ 원래는 이거였는데 0을 누르는 것도 whatBuy로 해서 whatBuy를 통한 if문을 두개를 했는데 되네??
//     scanf("%d", &ballCnt);
//     printf("구매 하시겠습니까? (y/n)");

//     // yesOrNo = getchar(); // scanf와 getchar의 차이가 조금이라도 있나 보려고 =  없다.
//     getchar();
//     scanf("%c", &yesOrNo);
    
//     if(yesOrNo == 'y'){
//         if(1000 * ballCnt <= money){
//             puts("성공적으로 몬스터 볼을 구매하였다");
//             money -= (1000*ballCnt);
//         }
//         else{
//             puts("돈이 부족하여 살 수 없습니다.");    
//         }
//     }
//     else{
//         puts("n을 입력하셨습니다.");
//     }
// }
// else{
//     scanf("%d", &portionCnt);
//     puts("구매 하시겠습니까? (y/n)");
//     getchar();
//     yesOrNo = getchar(); // scanf와 getchar의 차이가 조금이라도 있나 보려고
    
//     if(yesOrNo == 'y'){
//         if(2500 * portionCnt <= money){
//             puts("성공적으로 회복물약을 구매하였다");
//             money -= (2500*portionCnt);
//         }
//         else{
//             puts("돈이 부족하여 살 수 없습니다.");    
//         }
//     }
//     else{
//         puts("n을 입력하셨습니다.");
//     }
// }