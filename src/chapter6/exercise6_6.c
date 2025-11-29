//6. 编写程序，提示用户输入一个数 n，然后显示出 1~n 的所有偶数平方值。例如，如果用户输入 100，
//那么程序应该显示出下列内容：
//4
//16
//36
//64
//100

#include <stdio.h>

int exercise6_6() {
    printf("Enter n:  ");
    fflush(stdout);

    int n;
    scanf("%d", &n);
    for(int i = 2; i <= n; i += 2){
        printf("%d\n", i * i);
        if(i > n){
            break;
        }
    }
}