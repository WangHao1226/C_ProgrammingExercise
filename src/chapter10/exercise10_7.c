//7. 编写程序，提示用户输入一个数并显示该数，使用字符模拟七段显示器的效果：
//Enter a number: 491-9014
//非数字的字符都将被忽略。在程序中用一个名为 MAX_DIGITS 的宏来控制数的最大位数，MAX_DIGITS 的值为 10。
// 如果数中包含的数位大于这个数，多出来的数位将被忽略。提示：使用两个外部数
//        组，一个是 segments 数组（见第 8 章的练习题 6），用于存储表示数字和段之间对应关系的数据；
//另一个是 digits 数组，这是一个 3行（因为显示出来的每个数字高度都是 3个字符）、MAX_DIGITS×
//4 列（数字的宽度是 3 个字符，但为了可读性需要在数字之间增加一个空格）的字符数组。编写 4 个
//        函数：main、clear_digits_array、process_digit 和 print_digits_array。下面是后 3 个函数
//        的原型：
//void clear_digits_array(void);
//void process_digit(int digit, int position);
//void print_digits_array(void);
//clear_digits_array函数在digits数组的所有元素中存储空白字符。process_digit函数把digit
//        的七段表示存储到 digits 数组的指定位置（位置为 0~MAX_DIGITS-1）。print_digits_array 函数
//分行显示 digits 数组的每一行，产生的输出如示例图所示。


#include <stdio.h>
#include <ctype.h>

#define MAX_DIGITS 10

const int segments[MAX_DIGITS][7] = {
        {1, 1, 1, 1, 1, 1, 0},  /* 0 */
        {0, 1, 1, 0, 0, 0, 0},  /* 1 */
        {1, 1, 0, 1, 1, 0, 1},  /* 2 */
        {1, 1, 1, 1, 0, 0, 1},  /* 3 */
        {0, 1, 1, 0, 0, 1, 1},  /* 4 */
        {1, 0, 1, 1, 0, 1, 1},  /* 5 */
        {1, 0, 1, 1, 1, 1, 1},  /* 6 */
        {1, 1, 1, 0, 0, 0, 0},  /* 7 */
        {1, 1, 1, 1, 1, 1, 1},  /* 8 */
        {1, 1, 1, 1, 0, 1, 1}   /* 9 */
};

char digits[3][MAX_DIGITS * 4];

void clear_digits_array(void){
    for(int i = 0 ; i < 3; i++){
        for(int j = 0 ; j < MAX_DIGITS * 4; j++){
            digits[i][j] = ' ';
        }
    }
}

/* 处理单个数字，将其七段表示存储到指定位置 */
void process_digit(int digit, int position)
{
    int start_col = position * 4;  /* 每个数字占4列(3列显示+1列空格) */

    /* 根据七段显示规则设置字符 */
    if (segments[digit][0])
        digits[0][start_col + 1] = '_';  /* 上横线 */

    if (segments[digit][1])
        digits[1][start_col + 2] = '|';  /* 右上竖线 */

    if (segments[digit][2])
        digits[2][start_col + 2] = '|';  /* 右下竖线 */

    if (segments[digit][3])
        digits[2][start_col + 1] = '_';  /* 下横线 */

    if (segments[digit][4])
        digits[2][start_col] = '|';      /* 左下竖线 */

    if (segments[digit][5])
        digits[1][start_col] = '|';      /* 左上竖线 */

    if (segments[digit][6])
        digits[1][start_col + 1] = '_';  /* 中横线 */
}

/* 打印digits数组，显示七段数字 */
void print_digits_array(void)
{
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < MAX_DIGITS * 4; j++) {
            putchar(digits[i][j]);
        }
        putchar('\n');
    }
}

int exercise10_7(){
    char ch;
    int position = 0;

    clear_digits_array();

    printf("Enter a number: ");
    fflush(stdout);

    while ((ch = getchar()) != '\n' && position < MAX_DIGITS){
        if(isdigit((unsigned  char)ch)){
            int digit = ch - '0';
            process_digit(digit, position);
            position++;
        }
    }

    if(position == MAX_DIGITS){
        while ((ch = getchar()) != '\n'){
            if(isdigit((unsigned char)ch)){
                continue;
            }
        }
    }

    print_digits_array();
}