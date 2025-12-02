//2. 修改 8.1 节的程序 repdigit.c，使其打印出一份列表，显示出每个数字在数中出现的次数：
//Enter a number: 41271092
//Digit: 0 1 2 3 4 5 6 7 8 9
//Occurrences： 1 2 2 0 1 0 0 1 0 1

#include <stdio.h>

int exercise8_2() {
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
    printf("Digit: ");
    for(int i = 0;i < 10; i ++){
        printf("%d ", i);
    }
    printf("\nOccurrences: ");
    for(int i = 0; i < 10; i ++){
        printf("%d ", digit_seen[i]);
    }

}