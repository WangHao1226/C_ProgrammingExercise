//9. 第2章的编程题8要求编程计算第一、第二、第三个月还贷后剩余的贷款金额。修改该程序，要求用
//        户输入还贷的次数并显示每次还贷后剩余的贷款金额。

#include <stdio.h>

int exercise6_9() {
    float loan_amount, annual_interest_rate, monthly_payment;
    float monthly_interest_rate, balance;
    int payment_times;

    // 获取用户输入
    printf("Enter amount of loan: ");
    fflush(stdout);
    scanf("%f", &loan_amount);

    printf("Enter interest rate: ");
    fflush(stdout);
    scanf("%f", &annual_interest_rate);

    printf("Enter monthly payment: ");
    fflush(stdout);
    scanf("%f", &monthly_payment);

    printf("Enter number of payments: ");
    fflush(stdout);
    scanf("%d", &payment_times);

    // 计算月利率（将年利率转换为小数再除以12）
    monthly_interest_rate = (annual_interest_rate / 100.0f) / 12.0f;

    // 初始化余额为贷款总额
    balance = loan_amount;

    // 使用循环计算每次还款后的余额
    for (int i = 1; i <= payment_times; i++) {
        balance = balance - monthly_payment + (balance * monthly_interest_rate);
        printf("Balance remaining after payment %d: $%.2f\n", i, balance);

        // 如果余额为0或负数，说明贷款已还清
        if (balance <= 0) {
            printf("Loan paid off!\n");
            break;
        }
    }

}