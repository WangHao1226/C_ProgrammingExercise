//5. 编写名为 sum.c 的程序，用来对命令行参数（假设都是整数）求和。如果输入
//        sum 8 24 62
//运行程序，产生的输出应为
//        Total: 94
//提示：用 atoi 函数（ 26.2 节）把每个命令行参数从字符串格式转换为整数格式。

#include <stdio.h>
#include <stdlib.h>

int exercise13_5(int argc, char *argv[]) {
    int sum = 0;
    for (int i = 0; i < argc; i++) {
        sum += atoi(argv[i]);

        // 如果不是最后一个输出的参数，后面加空格
        if (i > 1) {
            printf(" ");
        }
    }
    printf("Total: %d", sum);
}