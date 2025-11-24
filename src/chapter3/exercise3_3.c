//3. 图书用国际标准书号（ISBN）进行标识。2007 年 1 月 1 日之后分配的 ISBN 包含 13 位数字（旧的 ISBN
//使用 10 位数字），分为 5 组，如 978-0-393-97950-3。第一组（GS1 前缀）目前为 978 或 979。第二
//        组（组标识）指明语言或者原出版国及地区（如 0 和 1 用于讲英语的国家）。第三组（出版商编号）
//表示出版商（393 是 W. W. Norton 出版社的编号）。第四组（产品编号）是由出版商分配的用于识别
//        具体哪一本书的编号（97950）。ISBN 的末尾是一个校验数字，用于验证前面数字的准确性。编写一
//        个程序来分解用户输入的 ISBN 信息：
//Enter ISBN: 978-0-393-97950-3
//GS1 prefix: 978
//Group identifier: 0
//Publisher code: 393
//Item number: 97950
//Check digit: 3
//注意：每组中数字的个数是可变的，不能认为每组的长度都与示例一样。用实际的 ISBN 值（通常放
//        在书的封底和版权页上）测试你编写的程序。

#include <stdio.h>

void exercise3_3(void) {
    printf("Enter ISBN:");
    fflush(stdout);
    int part1, part2, part3, part4, part5;
    scanf("%d-%d-%d-%d-%d", &part1, &part2, &part3, &part4, &part5);
    printf("GS1 prefix: %d\n", part1);
    printf("Group identifier: %d\n", part2);
    printf("Publisher code: %d\n", part3);
    printf("Item number: %d\n", part4);
    printf("Check digit: %d\n", part5);
}