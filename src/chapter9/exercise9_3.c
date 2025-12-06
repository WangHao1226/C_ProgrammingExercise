//3. 修改第 8 章的编程题 9，使其包含下列函数：
//void generate_random_walk(char walk[10][10]);
//void print_array(char walk[10][10]);
//main 函数首先调用 generate_random_walk，该函数把所有数组元素都初始化为字符'.'，然后将
//        其中一些字符替换为 A~Z 的字母，详见原题的描述。接着，main 函数调用 print_array 函数来显
//示数组。
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>
#define N 10

void generate_random_walk(char walk[N][N]){

    // 初始化数组为'.'
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            walk[i][j] = '.';
        }
    }

    int direction, row = 0, col = 0;
    char letter = 'A';

    // 设置随机种子
    srand((unsigned)time(NULL));

    // 标记起始位置
    walk[row][col] = letter++;

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
               walk[new_row][new_col] == '.') {
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
        walk[row][col] = letter++;
    }
}

void print_array(char walk[N][N]){
    // 打印数组
    printf("\n随机步法结果：\n");
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            printf("%c ", walk[i][j]);
        }
        printf("\n");
    }
}

int exercise9_3() {
    char matrix[N][N];
    generate_random_walk(matrix);

    print_array(matrix);

}