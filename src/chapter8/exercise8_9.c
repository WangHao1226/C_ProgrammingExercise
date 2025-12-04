//9. 编写程序，生成一种贯穿 10×10 字符数组（初始时全为字符'.'）的“随机步法”。程序必须随机地
//        从一个元素 “走到”另一个元素，每次都向上、向下、向左或向右移动一个元素位置。已访问过的
//        元素按访问顺序用字母 A~Z 进行标记。下面是一个输出示例
//        提示：利用 srand 函数和 rand 函数（见程序 deal.c）产生随机数，然后查看此数除以 4 的余数。余
//        数一共有 4 种可能的值（0、1、2 和 3），指示下一次移动的 4 种可能方向。在执行移动操作之前，
//需要检查两个条件：一是不能走到数组外面，二是不能走到已有字母标记的位置。只要有一个条件
//        不满足，就得尝试换一个方向移动。如果 4 个方向都堵住了，程序就必须终止了。下面是提前结束
//        的一个示例：
//因为 Y 移动的 4 个方向都堵住了，所以没有地方可以放置下一步的 Z 了。

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>
#define N 10

int exercise8_9() {
    char matrix[N][N];

    // 初始化数组为'.'
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            matrix[i][j] = '.';
        }
    }

    int direction, row = 0, col = 0;
    char letter = 'A';

    // 设置随机种子
    srand((unsigned)time(NULL));

    // 标记起始位置
    matrix[row][col] = letter++;

    // 最多放置26个字母（A到Z）
    while(letter <= 'Z') {
        // 记录当前可用的方向
        bool move_possible = false;
        bool tried_directions[4] = {false};
        int new_row, new_col;

        // 尝试四个方向，直到找到一个可行的方向或所有方向都尝试过
        while(true) {
            // 如果所有方向都尝试过了，则终止
            int tried_count = 0;
            for(int i = 0; i < 4; i++) {
                if(tried_directions[i]) {
                    tried_count++;
                }
            }
            if(tried_count == 4) {
                move_possible = false;
                break;
            }

            // 随机选择一个未尝试过的方向
            direction = rand() % 4;
            if(tried_directions[direction]) {
                continue;
            }
            tried_directions[direction] = true;

            // 根据方向计算新位置
            new_row = row;
            new_col = col;

            switch(direction) {
                case 0: new_row--; break; // 上
                case 1: new_row++; break; // 下
                case 2: new_col--; break; // 左
                case 3: new_col++; break; // 右
            }

            // 检查新位置是否有效
            if(new_row >= 0 && new_row < N &&
               new_col >= 0 && new_col < N &&
               matrix[new_row][new_col] == '.') {
                move_possible = true;
                break;
            }
        }

        // 如果没有可移动的方向，提前结束
        if(!move_possible) {
            printf("\n提前结束：没有可用的方向放置字母%c\n", letter);
            break;
        }

        // 移动到新位置并标记
        row = new_row;
        col = new_col;
        matrix[row][col] = letter++;
    }

    // 打印数组
    printf("\n随机步法结果：\n");
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            printf("%c ", matrix[i][j]);
        }
        printf("\n");
    }

}