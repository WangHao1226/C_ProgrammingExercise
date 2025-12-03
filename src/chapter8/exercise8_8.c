//8. 修改编程题 7，使其提示用户输入每个学生 5 门测验的成绩，一共有 5 个学生。然后计算每个学生的
//        总分和平均分，以及每门测验的平均分、高分和低分。
//Enter row 1: 8 3 9 0 10
//Enter row 2: 3 5 17 1 1
//Enter row 3: 2 8 6 23 1
//Enter row 4: 15 7 3 2 9
//Enter row 5: 6 14 2 6 0

#include <stdio.h>

#define N 5

int exercise8_8() {
    int arr[N][N], number;
    for(int i = 0 ; i < N ; i ++){
        printf("学生%d: ", i + 1);
        fflush(stdout);
        for(int j = 0 ; j < N ; j ++){
            scanf("%d", &number);
            arr[i][j] = number;
        }
    }
    for(int i = 0 ; i < N ; i ++){
        int row = 0;
        for(int j = 0 ; j < N ; j ++){
            row += arr[i][j];
        }
        printf("学生%d总分: %d, 平均分%.2f\n", i, row, row / 5.0);
    }

    printf("\n每门测验平均分: ");
    for(int j = 0 ; j < N ; j ++){
        int column = 0;
        for(int i = 0 ; i < N ; i ++){
            column += arr[i][j];
        }
        printf("%.2f ", column / 5.0);
    }

    for(int j = 0 ; j < N ; j ++){
        int max = arr[0][0], min = arr[0][0];
        for(int i = 0 ; i < N ; i ++){
            if(arr[i][j] > max){
                max = arr[i][j];
            }
            if(arr[i][j] < min){
                min = arr[i][j];
            }
        }
        printf("\n第%d门测验最高分、最低分: %d %d", j + 1, max, min);
    }

}