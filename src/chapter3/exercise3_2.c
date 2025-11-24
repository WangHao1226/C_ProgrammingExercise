//2. 编写一个程序，对用户输入的产品信息进行格式化。程序会话应类似下面这样：
//Enter item number: 583
//Enter unit price: 13.5
//Enter purchase date (mm/dd/yyyy): 10/24/2010
//Item Unit Purchase
//        Price Date
//583 $ 13.50 10/24/2010
//其中，产品编号和日期项采用左对齐方式，单位价格采用右对齐方式，允许美元金额最大取值为
//9999.99。提示：各个列使用制表符控制。

#include <stdio.h>

void exercise3_2(void) {
    printf("Enter item number:");
    fflush(stdout);
    int itemNumber;
    scanf("%d", &itemNumber);

    printf("Enter unit price:");
    fflush(stdout);
    float unitPrice;
    scanf("%f", &unitPrice);

    printf("Enter purchase date (mm/dd/yyyy):");
    fflush(stdout);
    int dd, mm, yyyy;
    scanf("%d/%d/%d", &dd, &mm, &yyyy);

    printf("Item\t\t\tUnit\t\t\tPurchase\n");
    printf("\t\t\t\tPrice\t\t\tDate\n");
    printf("%d\t\t\t\t&%8.2f\t\t%02d/%02d/%04d", itemNumber, unitPrice, dd, mm, yyyy);

}