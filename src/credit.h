#ifndef SRC_CREDIT_H_
#define SRC_CREDIT_H_

#ifdef __cplusplus
extern "C" {
#endif
double monthPay(double credit_amount, double interest_rate, int credit_term);
double totalSum(double monthly_fee, int credit_term);
double overPay(double total_amount, double credit_amount);
double difCreditAmountMonth(double credit_amount, int credit_term);
double diffPay(double amount_month, double remain, double interest_rate, int credit_term);
#ifdef __cplusplus
}
#endif

#endif  // SRC_CREDIT_H_
