//7. 编写程序读取一个 5×5 的整数数组，然后显示出每行的和与每列的和。
//Enter row 1: 8 3 9 0 10
//Enter row 2: 3 5 17 1 1
//Enter row 3: 2 8 6 23 1
//Enter row 4: 15 7 3 2 9
//Enter row 5: 6 14 2 6 0
//Row totals: 30 27 40 36 28
//Column totals: 34 37 37 32 21

#include <stdio.h>

#define N 5

int exercise8_7() {
    int arr[N][N], number;
    for(int i = 0 ; i < N ; i ++){
        printf("Enter row %d: ", i + 1);
        fflush(stdout);
        for(int j = 0 ; j < N ; j ++){
            scanf("%d", &number);
            arr[i][j] = number;
        }
    }
    printf("Row totals: ");
    for(int i = 0 ; i < N ; i ++){
        int row = 0;
        for(int j = 0 ; j < N ; j ++){
            row += arr[i][j];
        }
        printf("%d ", row);
    }

    printf("\nColumn totals: ");
    for(int j = 0 ; j < N ; j ++){
        int column = 0;
        for(int i = 0 ; i < N ; i ++){
            column += arr[i][j];
        }
        printf("%d ", column);
    }

}