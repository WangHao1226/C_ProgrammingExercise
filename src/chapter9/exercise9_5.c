//5. 修改第 8 章的编程题 17，使其包含下列函数：
//void create_magic_square(int n, int magic_square[n][n]);
//void print_magic_square(int n, int magic_square[n][n]);
//获得用户输入的数 n 之后，main 函数调用 create_magic_square 函数，另一个调用参数是在 main
//内部声明的n×n的数组。create_magic_square函数用1, 2, …, n2
//        填充数组，如原题所述。接下来，
//main 函数调用 print_magic_square，按原题描述的格式显示数组。注意：如果你的编译器不支持
//        变长数组，请把 main 中的数组声明为 99×99 而不是 n×n，并使用下面的原型：
//void create_magic_square(int n, int magic_square[99][99]);
//void print_magic_square(int n, int magic_square[99][99]);
#include <stdio.h>

void create_magic_square(int n, int magic_square[n][n]){

    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            magic_square[i][j] = 0;
        }
    }

    int num = 1, row = 0, col = n / 2;
    while (num <= n * n){
        magic_square[row][col] = num;
        num++;

        int old_row = row, old_col = col;

        row--;
        col++;
        if(row < 0){
            row = n -1;
        }
        if(col >= n){
            col = 0;
        }

        if(magic_square[row][col] != 0){
            row = old_row + 1;
            col = old_col;

            if(row >= n){
                row = 0;
            }
        }
    }
}

void print_magic_square(int n, int magic_square[n][n]){
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            printf("%d\t", magic_square[i][j]);
        }
        printf("\n");
    }
}

int exercise9_5() {
    printf("This program creates a magic square of a specified size.\n");
    printf("The size must be an odd number between 1 and 99.\n");
    printf("Enter size of magic square: ");
    fflush(stdout);

    int size;
    scanf("%d", &size);
    int arr[size][size];

    create_magic_square(size, arr);

    print_magic_square(size, arr);

}