#include <check.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "rpn.h"

START_TEST(input_string1) {
  char inp_str[] = "sin(2-x)*(sqrt(log(ln(-8)))--2+6^(x-1)";
  char curr_str[] =
      "sin ( 2 - x ) * ( sqrt ( log ( ln ( -8 ) ) ) - -2 + 6 ^ ( x - 1 ) ";
  char *result_str = (char *)calloc(strlen(curr_str)+1, sizeof(char));
  input(result_str, inp_str);
  ck_assert_int_eq(strcmp(curr_str, result_str), 0);
  free(result_str);
}
END_TEST

START_TEST(input_string2) {
  char inp_str[] = "cos(atan(10000/4mod6+-7)";
  char curr_str[] =
      "cos ( atan ( 10000 / 4 mod 6 + -7 ) ";
  char *result_str = (char *)calloc(strlen(curr_str)+1, sizeof(char));
  input(result_str, inp_str);
  ck_assert_int_eq(strcmp(curr_str, result_str), 0);
  free(result_str);
}
END_TEST

START_TEST(input_string3) {
  char inp_str[] = "cos (atan(     10000/4mod6+ -7)       ";
  char curr_str[] =
      "cos ( atan ( 10000 / 4 mod 6 + -7 ) ";
  char *result_str = (char *)calloc(strlen(curr_str)+1, sizeof(char));
  input(result_str, inp_str);
  ck_assert_int_eq(strcmp(curr_str, result_str), 0);
  free(result_str);
}
END_TEST

START_TEST(rpn_convert1) {
  char inp_str[] = "sin ( 2 - x ) * sqrt ( log ( ln ( 8 ) ) ) - -2 + 6 ^ ( x - 1 ) ";
  char curr_str[] = "2 x - sin 8 ln log sqrt * -2 - 6 x 1 - ^ + ";
  char *result_str = (char*)calloc(strlen(curr_str)+1, sizeof(char));
  result_str = get_rpn(inp_str, result_str);
  ck_assert_int_eq(strcmp(curr_str, result_str), 0);
  free(result_str);
}
END_TEST

START_TEST(rpn_convert2) {
  char inp_str[] = "10 mod 3 + sin ( tan ( -1 ) ) / sqrt ( 13 mod 3 ) ";
  char curr_str[] = "10 3 mod -1 tan sin 13 3 mod sqrt / + ";
  char *result_str = (char*)calloc(strlen(curr_str)+1, sizeof(char));
  result_str = get_rpn(inp_str, result_str);
  ck_assert_int_eq(strcmp(curr_str, result_str), 0);
  free(result_str);
}
END_TEST

START_TEST(rpn_convert3) {
  char inp_str[] = "10 ^ sin ( 3 ) ^ log ( sqrt ( 4 ) ) ^ ( 15 mod 4 ) ";
  char curr_str[] = "10 3 sin 4 sqrt log 15 4 mod ^ ^ ^ ";
  char *result_str = (char*)calloc(strlen(curr_str)+1, sizeof(char));
  result_str = get_rpn(inp_str, result_str);
  ck_assert_int_eq(strcmp(curr_str, result_str), 0);
  free(result_str);
}
END_TEST

START_TEST(rpn_convert4) {
  char inp_str[] = "1.56239874 * 0,00235897 - 1.0002356 * sqrt ( 2,36958 ) ";
  char curr_str[] = "1.56239874 0.00235897 * 1.0002356 2.36958 sqrt * - ";
  char *result_str = (char*)calloc(strlen(curr_str)+1, sizeof(char));
  result_str = get_rpn(inp_str, result_str);
  ck_assert_int_eq(strcmp(curr_str, result_str), 0);
  free(result_str);
}
END_TEST

START_TEST(arithmetic1) {
  char inp_str[] = "10 3 sin 4 sqrt log 15 4 mod ^ ^ ^ ";
  double orig = 8.87125884688;
  double result = rpn_calculate(inp_str, 1);
  ck_assert_double_eq_tol(orig, result, 0.00000000001);
}
END_TEST

START_TEST(arithmetic2) {
  char inp_str[] = "10 3 mod -1 tan sin 13 3 mod sqrt / + ";
  double orig = 0.00008962599;
  double result = rpn_calculate(inp_str, 1);
  ck_assert_double_eq_tol(orig, result, 0.00000000001);
}
END_TEST

START_TEST(arithmetic3) {
  char inp_str[] = "2 x - sin 8 ln log sqrt * -2 - 6 x 1 - ^ + ";
  double orig = 3.47447825858;
  double result = rpn_calculate(inp_str, 1);
  ck_assert_double_eq_tol(orig, result, 0.00000000001);
}
END_TEST

START_TEST(arithmetic4) {
  char inp_str[] = "1 atan asin";
  double orig = 0.903339110767;
  double result = rpn_calculate(inp_str, 1);
  ck_assert_double_eq_tol(orig, result, 0.00000000001);
}
END_TEST

START_TEST(arithmetic5) {
  char inp_str[] = "1.56239874 0.000235897 * 1.0002356 2.36958 sqrt * - ";
  double orig = -1.53933812041;
  double result = rpn_calculate(inp_str, 1);
  ck_assert_double_eq_tol(orig, result, 0.00000000001);
}
END_TEST

START_TEST(graphic1) {
  char inp_str[] = "tan(x)";
  double orig = 1.55740772465;
  double result = graph_build(1, inp_str);
  ck_assert_double_eq_tol(orig, result, 0.00000000001);
}
END_TEST

Suite *Input_check() {
  Suite *s1 = suite_create("Check of the input line");
  TCase *tc1 = tcase_create("");
  suite_add_tcase(s1, tc1);
  tcase_add_test(tc1, input_string1);
  tcase_add_test(tc1, input_string2);
  tcase_add_test(tc1, input_string3);
  return s1;
}

Suite *RPN_check() {
  Suite *s2 = suite_create("Check of the RPN-line");
  TCase *tc1 = tcase_create("");
  suite_add_tcase(s2, tc1);
  tcase_add_test(tc1, rpn_convert1);
  tcase_add_test(tc1, rpn_convert2);
  tcase_add_test(tc1, rpn_convert3);
  tcase_add_test(tc1, rpn_convert4);

  return s2;
}

Suite *Arithmetic() {
  Suite *s3 = suite_create("Arithmetic");
  TCase *tc1 = tcase_create("simple arithmetic");
  suite_add_tcase(s3, tc1);
  tcase_add_test(tc1, arithmetic1);
  tcase_add_test(tc1, arithmetic2);
  tcase_add_test(tc1, arithmetic3);
  tcase_add_test(tc1, arithmetic4);
  tcase_add_test(tc1, arithmetic5);

  return s3;
}

Suite *Graphic() {
  Suite *s4 = suite_create("Graphic build");
  TCase *tc1 = tcase_create("");
  suite_add_tcase(s4, tc1);
  tcase_add_test(tc1, graphic1);
  return s4;
}

int main() {
  int nf = 0;
  Suite *s1 = Input_check();
  Suite *s2 = RPN_check();
  Suite *s3 = Arithmetic();
  Suite *s4 = Graphic();

  SRunner *sr1 = srunner_create(s1);
  SRunner *sr2 = srunner_create(s2);
  SRunner *sr3 = srunner_create(s3);
  SRunner *sr4 = srunner_create(s4);

  srunner_run_all(sr1, CK_VERBOSE);
  nf += srunner_ntests_failed(sr1);
  srunner_free(sr1);

  srunner_run_all(sr2, CK_VERBOSE);
  nf += srunner_ntests_failed(sr2);
  srunner_free(sr2);

  srunner_run_all(sr3, CK_VERBOSE);
  nf += srunner_ntests_failed(sr3);
  srunner_free(sr3);

  srunner_run_all(sr4, CK_VERBOSE);
  nf += srunner_ntests_failed(sr4);
  srunner_free(sr4);

  return nf == 0 ? 0 : 1;
}
