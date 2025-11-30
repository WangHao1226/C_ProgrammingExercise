//2. 修改 6.3 节的程序 square2.c，每 24 次平方运算后暂停，并显示下列信息：
//Press Enter to continue...
//显示完上述消息后，程序应该使用 getchar 函数读入一个字符。getchar 函数读到用户输入的回车
//键才允许程序继续。

#include <stdio.h>

int exercise7_2() {
    int n;
    printf("This program prints a table of squares.\n");
    printf("Enter number of entries in table: ");
    fflush(stdout);
    scanf("%d", &n);
    while (getchar() != '\n');

    for(int i = 1; i <= n; i++){
        printf("%10d%10d\n", i, i * i);
        if(i % 24 == 0 && i != n){
            printf("Press Enter to continue...");
            fflush(stdout);

            while (getchar() != '\n');
        }
    }


}