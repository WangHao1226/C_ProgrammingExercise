//6. 欧洲国家及地区不使用北美的 12 位通用产品代码（UPC），而使用 13 位的欧洲商品编码（European
//        Article Number, EAN）。跟 UPC 一样，每个 EAN 码的最后也有一个校验位。计算校验位的方法也类
//        似：首先把第 2位、第 4位、第 6位、第 8位、第 10位和第 12位数字相加；然后把第 1位、第 3位、
//第 5 位、第 7 位、第 9 位和第 11位数字相加；接着把第一次加法的结果乘以 3，再和第二次加法的结
//        果相加；随后，再把上述结果减去 1；相减后的结果除以 10 取余数；最后用 9 减去上一步骤中得到
//        的余数。
//以 Güllüoglu 牌土耳其软糖（开心果和椰子口味）为例，其 EAN 码为 8691484260008。第一个和为
//6+1+8+2+0+0=17，第二个和为 8+9+4+4+6+0=31。第一个和乘以 3 再加上第二个和得到 82，减 1 得
//        到 81。这个结果除以 10 的余数是 1，再用 9 减去余数得到 8，与原始编码的最后一位一致。请修改
//4.1 节的 upc.c 程序以计算 EAN 的校验位。用户把 EAN 的前 12 位当作一个数输入：
//Enter the first 12 digits of an EAN: 869148426000
//Check digit: 8

#include <stdio.h>

void exercise4_6(void) {
    printf("Enter the first 12 digits of an EAN: ");
    fflush(stdout);
    // 读取12位EAN码
    char ean[13]; // 12位数字 + 空字符
    scanf("%12s", ean);

    // 计算偶数位和奇数位的和
    int sum_even = 0; // 第2、4、6、8、10、12位
    int sum_odd = 0;  // 第1、3、5、7、9、11位

    // 遍历每个数字字符
    for (int i = 0; i < 12; i++) {
        int digit = ean[i] - '0'; // 将字符转换为数字

        // 注意：数组索引从0开始，所以第1位是索引0，第2位是索引1，以此类推
        if ((i + 1) % 2 == 0) { // 偶数位（第2、4、6、8、10、12位）
            sum_even += digit;
        } else { // 奇数位（第1、3、5、7、9、11位）
            sum_odd += digit;
        }
    }

    // 计算校验位
    int total = sum_even * 3 + sum_odd; // 偶数位和乘以3，再加上奇数位和
    total = total - 1;                  // 减去1
    int remainder = total % 10;         // 除以10取余数
    int check_digit = 9 - remainder;    // 用9减去余数

    printf("Check digit: %d\n", check_digit);
}