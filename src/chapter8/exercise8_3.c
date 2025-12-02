//3. 修改 8.1节的程序 repdigit.c，使得用户可以输入多个数进行重复数字的判断。当用户输入的数小于或
//        等于 0 时，程序终止。

#include <stdio.h>

int exercise8_3() {

    int digit_seen[10] = {0};
    int digit, n;
    while (1){
        printf("Enter a number: ");
        fflush(stdout);
        scanf("%d", &n);
        if(n <= 0){
            break;
        }
        while (n > 0) {
            digit = n % 10;
            digit_seen[digit] ++;
            n /= 10;
        }

    }
    printf("Digit: ");
    for(int i = 0;i < 10; i ++){
        printf("%d ", i);
    }
    printf("\nOccurrences: ");
    for(int i = 0; i < 10; i ++){
        printf("%d ", digit_seen[i]);
    }


}