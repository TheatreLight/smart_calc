#include "credit.h"

#include <math.h>

double monthPay(double credit_amount, double interest_rate, int credit_term) {
    double monthly_rate = interest_rate/(100 * 12);
    return credit_amount * (monthly_rate / (1 - (pow((1 + monthly_rate), -1 * credit_term))));
}

double totalSum(double monthly_fee, int credit_term) {
    return monthly_fee * credit_term;
}

double overPay(double total_amount, double credit_amount) {
    return total_amount - credit_amount;
}

double difCreditAmountMonth(double credit_amount, int credit_term) {
    return credit_amount / credit_term;
}

double diffPay(double amount_month, double remain, double interest_rate, int credit_term) {
    int rate_period;
    if (credit_term >= 12)
      rate_period = 12;
    else
      rate_period = credit_term;
    double diff_fee = amount_month + remain * (interest_rate/100) / rate_period;
    return diff_fee;
}
