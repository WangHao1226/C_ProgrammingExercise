//17. 编写程序打印 n×n 的幻方（1, 2, …, n2的方阵排列，且每行、每列和每条对角线上的和都相等）。由
//        用户指定 n 的值：
//This program creates a magic square of a specified size.
//The size must be an odd number between 1 and 99.
//Enter size of magic square: 5
//17 24 1 8 15
//23 5 7 14 16
//4 6 13 20 22
//10 12 19 21 3
//11 18 25 2 9
//把幻方存储在一个二维数组中。起始时把数 1 放在第 0 行的中间，剩下的数 2, 3, …, n2依次向上移动
//        一行并向右移动一列。当可能越过数组边界时需要“绕回”到数组的另一端。例如，如果需要把下
//        一个数放到第-1 行，我们就将其存储到第 n-1 行（最后一行）；如果需要把下一个数放到第 n 列，
//我们就将其存储到第 0 列。如果某个特定的数组元素已被占用，那就把该数存储在前一个数的正下
//        方。如果你的编译器支持变长数组，则声明数组有 n 行 n 列，否则声明数组有 99 行 99 列。

#include <stdio.h>

int exercise8_17() {
    printf("This program creates a magic square of a specified size.\n");
    printf("The size must be an odd number between 1 and 99.\n");
    printf("Enter size of magic square: ");
    fflush(stdout);

    int size;
    scanf("%d", &size);
    int arr[size][size];
    for(int i = 0 ; i < size ; i++){
        for(int j = 0 ; j < size ; j++){
            arr[i][j] = 0;
        }
    }

    int num = 1, row = 0, col = size / 2;
    while (num <= size * size){
        arr[row][col] = num;
        num++;

        int old_row = row, old_col = col;

        row--;
        col++;
        if(row < 0){
            row = size -1;
        }
        if(col >= size){
            col = 0;
        }

        if(arr[row][col] != 0){
            row = old_row + 1;
            col = old_col;

            if(row >= size){
                row = 0;
            }
        }
    }

    for(int i = 0 ; i < size ; i++){
        for(int j = 0 ; j < size ; j++){
            printf("%d\t", arr[i][j]);
        }
        printf("\n");
    }

}