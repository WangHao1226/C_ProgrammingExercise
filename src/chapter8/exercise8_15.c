//15. 目前已知的最古老的一种加密技术是恺撒加密（得名于 Julius Caesar）。该方法把一条消息中的每个字
//        母用字母表中固定距离之后的那个字母来替代。（如果越过了字母 Z，则会绕回到字母表的起始位
//        置。例如，如果每个字母都用字母表中两个位置之后的字母代替，那么Y就被替换为A，Z就被替换
//        为 B。）编写程序用恺撒加密方法对消息进行加密。用户输入待加密的消息和移位计数（字母移动的
//        位置数目）
//Enter message to be encrypted: Go ahead, make my day.
//Enter shift amount (1-25): 3
//Encrypted message: Jr dkhdg, pdnh pb gdb.
//注意，当用户输入 26 与移位计数的差值时，程序可以对消息进行解密：
//Enter message to be encrypted: Jr dkhdg, pdnh pb gdb.
//Enter shift amount (1-25): 23
//Encrypted message: Go ahead, make my day.
//可以假定消息的长度不超过 80 个字符。不是字母的那些字符不要改动。此外，加密时不要改变字母
//        的大小写。提示：为了解决前面提到的绕回问题，可以用表达式((ch - 'A') + n) % 26 + 'A'计
//        算大写字母的密码，其中 ch 存储字母，n 存储移位计数。（小写字母也需要一个类似的表达式。）

#include <stdio.h>
#include <string.h>

#define N 80

int exercise8_15() {
    char message[N];
    int shift, length = 0;

    printf("Enter message to be encrypted: ");
    fflush(stdout);

    // 读取字符直到遇到换行符或达到最大长度
    while (length < N) {
        char ch = getchar();
        if (ch == '\n') {
            break;
        }
        message[length++] = ch;
    }

    printf("Enter shift amount (1-25): ");
    fflush(stdout);
    scanf("%d", &shift);

    // 确保移位计数在有效范围内
    shift = shift % 26;

    // 加密消息
    for (int i = 0; i < length; i++) {
        if (message[i] >= 'A' && message[i] <= 'Z') {
            // 大写字母加密
            message[i] = ((message[i] - 'A') + shift) % 26 + 'A';
        } else if (message[i] >= 'a' && message[i] <= 'z') {
            // 小写字母加密
            message[i] = ((message[i] - 'a') + shift) % 26 + 'a';
        }
        // 非字母字符保持不变
    }

    printf("Encrypted message: ");
    for (int i = 0; i < length; i++) {
        putchar(message[i]);
    }
    printf("\n");

}