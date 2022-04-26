#ifndef SRC_RPN_H_
#define SRC_RPN_H_

void check_for_comma(char *str);
void copy_tokens(char *src, char *dst, int *current_position, int length);
int check_token_priority(char *src, char *on_top);
#ifdef __cplusplus
extern "C" {
#endif  // __cplusplus
int input(char *str, char *inp_str);
char *get_rpn(char *src, char *dst);
double rpn_calculate(char *str, double x);
double graph_build(double x, char *str);
#ifdef __cplusplus
}  // extern "C"
#endif  // __cplusplus

#endif  // SRC_RPN_H_
