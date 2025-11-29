//8. 编程计算第一、第二、第三个月还贷后剩余的贷款金额：
//Enter amount of loan: 20000.00
//Enter interest rate: 6.0
//Enter monthly payment: 386.66
//Balance remaining after first payment: $19713.34
//Balance remaining after second payment: $19425.25
//Balance remaining after third payment: $19135.71
//在显示每次还款后的余额时保留两位小数。提示：每个月的贷款余额减去还款金额后，还需要加上
//        贷款余额与月利率的乘积。月利率的计算方法是把用户输入的利率转换成百分数再除以 12。

#include <stdio.h>

int exercise2_8(){
    float loan_amount, annual_interest_rate, monthly_payment;
    float monthly_interest_rate, balance;

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

    // 计算月利率（将年利率转换为小数再除以12）
    monthly_interest_rate = (annual_interest_rate / 100.0f) / 12.0f;

    // 计算第一个月后的余额
    balance = loan_amount - monthly_payment + (loan_amount * monthly_interest_rate);
    printf("Balance remaining after first payment: $%.2f\n", balance);

    // 计算第二个月后的余额
    balance = balance - monthly_payment + (balance * monthly_interest_rate);
    printf("Balance remaining after second payment: $%.2f\n", balance);

    // 计算第三个月后的余额
    balance = balance - monthly_payment + (balance * monthly_interest_rate);
    printf("Balance remaining after third payment: $%.2f\n", balance);
}