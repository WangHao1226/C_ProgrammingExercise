//1. 修改 8.1 节的程序 repdigit.c，使其可以显示出哪些数字有重复（如果有的话）：
//Enter a number: 939577
//Repeated digit(s): 7 9

#include <stdio.h>
#include <stdbool.h>

int exercise8_1() {
    printf("Enter a number: ");
    fflush(stdout);
    int digit_seen[10] = {0};
    int digit, n;
    scanf("%d", &n);

    while (n > 0) {
        digit = n % 10;
        digit_seen[digit] ++;
        n /= 10;
    }
    printf("Repeated digit(s): ");
    fflush(stdout);
    for(int i = 0; i < 10; i ++){
        if(digit_seen[i] >= 2 ){
            printf("%d ", i);
        }
    }

}