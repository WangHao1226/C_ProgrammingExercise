//6. 修改上题，用如下公式对多项式求值：
//((((3x + 2) x - 5)x - 1)x + 7)x - 6
//注意，修改后的程序所需的乘法次数减少了。这种多项式求值方法即 Horner 法则。

#include <stdio.h>

int exercise2_6(){
    printf("输入x的值:");
    fflush(stdout);
    int x;
    scanf("%d",&x);
    printf("((((3x + 2) x - 5)x - 1)x + 7)x - 6的值为:%d",
           ((((3 * x + 2) * x - 5) * x - 1) * x + 7) * x - 6);
    return 0;
}