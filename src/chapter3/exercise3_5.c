//5. 编写一个程序，要求用户（按任意次序）输入 1~16 的所有整数，然后用 4×4 矩阵的形式将它们显示
//        出来，再计算出每行、每列和每条对角线上的和：
//Enter the numbers from 1 to 16 in any order:
//16 3 2 13 5 10 11 8 9 6 7 12 4 15 14 1
//16 3 2 13
//5 10 11 8
//9 6 7 12
//4 15 14 1
//Row sums: 34 34 34 34
//Column sums: 34 34 34 34
//Diagonal sums: 34 34
//如果行、列和对角线上的和都一样（如本例所示），则称这些数组成一个幻方（magic square）。这里
//        给出的幻方出现于艺术家和数学家 Albrecht Dürer 创作于 1514 年的一幅画中。（注意，矩阵的最后一
//        行中间的两个数给出了该画的创作年代。）

#include <stdio.h>

void exercise3_5(void) {
    int numbers[4][4];

    printf("Enter the numbers from 1 to 16 in any order:\n");
    fflush(stdout);

    // 读取16个数字并存入4×4数组
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            scanf("%d", &numbers[i][j]);
        }
    }

    // 显示4×4矩阵
    printf("\n");
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%2d ", numbers[i][j]);
        }
        printf("\n");
    }

    // 计算行和
    printf("Row sums: ");
    for (int i = 0; i < 4; i++) {
        int row_sum = 0;
        for (int j = 0; j < 4; j++) {
            row_sum += numbers[i][j];
        }
        printf("%d ", row_sum);
    }
    printf("\n");

    // 计算列和
    printf("Column sums: ");
    for (int j = 0; j < 4; j++) {
        int col_sum = 0;
        for (int i = 0; i < 4; i++) {
            col_sum += numbers[i][j];
        }
        printf("%d ", col_sum);
    }
    printf("\n");

    // 计算对角线之和
    int diag1 = 0, diag2 = 0;
    for (int i = 0; i < 4; i++) {
        diag1 += numbers[i][i];           // 主对角线
        diag2 += numbers[i][3 - i];       // 副对角线
    }
    printf("Diagonal sums: %d %d\n", diag1, diag2);
}