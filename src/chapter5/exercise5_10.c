//10. 利用 switch 语句编写一个程序，把用数字表示的成绩转换为字母表示的等级。
//Enter numerical grade: 84
//Letter grade: B
//
//        使用下面的等级评定规则：A 为 90～100，B 为 80～89，C 为 70～79，D 为 60～69，F 为 0～59。如
//        果成绩高于 100 或低于 0，则显示出错消息。提示：把成绩拆分成 2 个数字，然后使用 switch 语句
//        判定十位上的数字。

#include <stdio.h>

int exercise5_10() {
    printf("Enter numerical grade:  ");
    fflush(stdout);
    int grade;
    scanf("%d", &grade);

    if(grade > 100 || grade < 0){
        printf("Error");
        return 1;
    }

    printf("Letter grade: ");
    switch (grade / 10) {
        case 10:
        case 9:
            printf("A");
            break;
        case 8:
            printf("B");
            break;
        case 7:
            printf("C");
            break;
        case 6:
            printf("D");
        default:
            printf("F");

    }

}