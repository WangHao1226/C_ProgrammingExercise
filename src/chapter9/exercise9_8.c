//8. 编写函数模拟掷骰子的游戏（两个骰子）。第一次掷的时候，如果点数之和为 7 或 11 则获胜；如果点
//        数之和为2、3或12则落败；其他情况下的点数之和称为“目标”，游戏继续。在后续的投掷中，如
//        果玩家再次掷出“目标”点数则获胜，掷出 7 则落败，其他情况都忽略，游戏继续进行。每局游戏
//        结束时，程序询问用户是否再玩一次，如果用户输入的回答不是y或 Y，程序会显示胜败的次数然后
//        终止。
//You rolled: 8
//Your point is 8
//You rolled: 3
//You rolled: 10
//You rolled: 8
//You win!
//Play again? y
//        You rolled: 6
//Your point is 6
//You rolled: 5
//You rolled: 12
//You rolled: 3
//You rolled: 7
//You lose!
//Play again? y
//        You rolled: 11
//You win!
//Play again? n
//        Wins: 2 Losses: 1
//编写三个函数：main、roll_dice 和 play_game。下面给出了后两个函数的原型：
//int roll_dice(void);
//bool play_game(void);
//roll_dice 应生成两个随机数（每个都在 1~6 范围内），并返回它们的和。play_game 应进行一次掷
//骰子游戏（调用 roll_dice 确定每次掷的点数），如果玩家获胜则返回 true，如果玩家落败则返回
//        false。play_game 函数还要显示玩家每次掷骰子的结果。main 函数反复调用 play_game 函数，记
//        录获胜和落败的次数，并显示“you win”和“you lose”消息。提示：使用 rand 函数生成随机数。
//关于如何调用 rand 和相关的 srand 函数，见 8.2 节 deal.c 程序中的例子。

#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>
#include <ctype.h>

int roll_dice(void){
    int random_num1 = rand() % 6 + 1, random_num2 = rand() % 6 + 1;
    return random_num1 + random_num2;
}

bool play_game(void){
    int point = roll_dice();
    printf("You rolled: %d\n", point);

    if(point == 7 || point == 11){
        return true;
    } else if(point == 2 || point == 3 || point == 12){
        return false;
    } else{
        printf("Your point is %d\n", point);

        while (1){
            int rolled = roll_dice();
            printf("You rolled: %d\n", rolled);

            if(rolled == point){
                return true;
            }else if(rolled == 7){
                return false;
            }
        }
    }

}

int exercise9_8() {
    srand(time(NULL));
    int win_times = 0, lose_times = 0;
    char choice;

    do{
        if(play_game()){
            printf("You win!\n");
            win_times++;
        } else{
            printf("You lose!\n");
            lose_times++;
        }

        printf("Play again? ");
        fflush(stdout);
        scanf(" %c", &choice);

        while (getchar() != '\n');
    }while (toupper(choice) == 'Y');
    printf("Wins: %d, Losses: %d\n", win_times, lose_times);
}