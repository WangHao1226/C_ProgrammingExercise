//3. 修改 5.2 节的 broker.c 程序，做出下面两种改变。
//(a) 不再直接输入交易额，而是要求用户输入股票的数量和每股的价格。
//(b) 增加语句用来计算经纪人竞争对手的佣金（少于 2000 股时佣金为每股 33 美元+3 美分，2000 股或更
//        多股时佣金为每股 33 美元+2美分）。在显示原有经纪人佣金的同时，也显示出竞争对手的佣金。

#include <stdio.h>

void exercise5_3(void) {
    int shares;
    float price_per_share, value, commission, rival_commission;

    // (a) 输入股票数量和每股价格，而不是直接输入交易额
    printf("Enter number of shares: ");
    fflush(stdout);
    scanf("%d", &shares);

    printf("Enter price per share: ");
    fflush(stdout);
    scanf("%f", &price_per_share);

    // 计算交易总额
    value = shares * price_per_share;

    // 原有经纪人佣金计算（保持不变）
    if (value < 2500.00f)
        commission = 30.00f + .017f * value;
    else if (value < 6250.00f)
        commission = 56.00f + .0066f * value;
    else if (value < 20000.00f)
        commission = 76.00f + .0034f * value;
    else if (value < 50000.00f)
        commission = 100.00f + .0022f * value;
    else if (value < 500000.00f)
        commission = 155.00f + .0011f * value;
    else
        commission = 255.00f + .0009f * value;

    if (commission < 39.00f)
        commission = 39.00f;

    // (b) 计算竞争对手的佣金
    if (shares < 2000)
        rival_commission = shares * 33.03f;  // 33美元 + 3美分 = 33.03美元
    else
        rival_commission = shares * 33.02f;  // 33美元 + 2美分 = 33.02美元

    // 显示结果
    printf("\nOriginal broker commission: $%.2f\n", commission);
    printf("Rival broker commission: $%.2f\n", rival_commission);
}