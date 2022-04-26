#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "_my_stack.h"

int input(char *str, char *inp_str) {
  char *temp = str;
  char ch = *inp_str;
  char tmp = '\0';
  int open_count = 0;
  int closed_count = 0;
  while (ch != '\0') {
    if (ch != ' ') {
      if ((ch >= 40 && ch <= 43) || ch == 45 || ch == 47 ||
          ch == 94) {  // если ()+-/*^
        int i = 1;
        int n = 3;
        if ((tmp >= 97 && tmp <= 122) || (tmp >= 48 && tmp <= 57))
          i--;  // если в буфере буква или число
        if ((tmp == '\0' || tmp == 40 || tmp == 42 || tmp == 43 ||
             tmp == 45 ||  // если в буфере любой знак, кроме закрывающей скобки
             tmp == 47 || tmp == 94) &&
            (ch == '+' || ch == '-')) {
          i = n;
          *str = ch;
          str++;
        }
        for (; i < n; i++, str++) {
          if (i % 2 == 0)
            *str = ' ';
          else
            *str = ch;
          tmp = ch;
        }
        if (ch == 40) open_count++;
        if (ch == 41) closed_count++;
      } else if (ch == 'm') {
        *str = ' ';
        str++;
        *str = ch;
        str++;
        tmp = ch;
      } else if (ch == 'd') {
        *str = ch;
        str++;
        *str = ' ';
        str++;
        tmp = ch;
      } else {  // если любая цифра или буква
        *str = ch;
        str++;
        tmp = ch;
      }
    }
    inp_str++;
    ch = *inp_str;
  }
  if (open_count != closed_count) {
    return 0;
  }

  return strlen(temp);
}

void check_for_comma(char *str) {
  for (int i = 0; i < (int)strlen(str); i++) {
    if (str[i] == ',') {
      str[i] = '.';
      break;
    }
  }
}

void copy_tokens(char *src, char *dst, int *current_position, int length) {
  int dst_length = *current_position + length;
  for (int i = *current_position, j = 0; i < dst_length; i++, j++) {
    dst[i] = src[j];
  }
  dst[dst_length] = ' ';
  *current_position = dst_length + 1;
}

int check_token_priority(char *src, char *on_top) {
  int res = 0;
  if (on_top[0] == '^' && src[0] != '^') {
    res = 1;
  } else if ((on_top[0] == '*' || on_top[0] == '/' || on_top[0] == 'm') &&
             src[0] != '^') {
    res = 1;
  } else if ((on_top[0] == '+' || on_top[0] == '-') &&
             (src[0] == '+' || src[0] == '-')) {
    res = 1;
  }

  return res;
}

char *get_rpn(char *src, char *dst) {
  if (src == NULL) return NULL;
  Stack *stack = NULL;
  int pos = 0;
  char *point = strtok(src, " ");
  char tmp[5] = {0};
  while (point != NULL) {
    int length = strlen(point);
    int is_digit = strspn(point, "x0123456789.,");
    int is_signed_digit = length > 1 && strspn(point, "+-x0123456789.,");
    int is_prefix_func = strspn(point, "sinctalnsqr");
    int is_open_bracket = !strcmp(point, "(");
    int is_closed_bracket = !strcmp(point, ")");
    int is_bin_operation =
        !strcmp(point, "mod") || (length == 1 && strspn(point, "+-/*^"));
    if (is_digit) {
      check_for_comma(point);
      copy_tokens(point, dst, &pos, length);
    } else if (is_signed_digit) {
      check_for_comma(point);
      copy_tokens(point, dst, &pos, length);
    } else if (is_prefix_func) {
      push(&stack, point);
    } else if (is_open_bracket) {
      push(&stack, point);
    } else if (is_closed_bracket) {
      while (stack->data[0] != '(') {
        pop(&stack, tmp);
        length = strlen(tmp);
        copy_tokens(tmp, dst, &pos, length);
      }
      pop(&stack, tmp);
    } else if (is_bin_operation) {
      if (stack == NULL) {
        push(&stack, point);
      } else {
        is_prefix_func = strspn(stack->data, "sctl");
        int priority = check_token_priority(point, stack->data);
        while ((is_prefix_func || priority) && stack != NULL) {
          pop(&stack, tmp);
          copy_tokens(tmp, dst, &pos, strlen(tmp));
          if (stack != NULL) {
            is_prefix_func = strspn(stack->data, "sctl");
            priority = check_token_priority(point, stack->data);
          }
        }
        push(&stack, point);
      }
    }
    point = strtok(NULL, " \n");
  }
  while (stack != NULL) {
    pop(&stack, tmp);
    strcat(dst, tmp);
    strcat(dst, " ");
  }
  return dst;
}

double rpn_calculate(char *str, double x) {
  if (str == NULL) return 0;
  double result = 0;
  D_stack *stack = NULL;
  char *point = strtok(str, " ");
  while (point != NULL) {
    if ((point[0] >= 48 && point[0] <= 57) ||
        (point[1] >= 48 && point[1] <= 57)) {  // it means it is a number
      double buf = atof(point);
      d_push(&stack, buf);
    } else if (point[0] == 'x') {
      d_push(&stack, x);
    } else if (point[0] == '+' || point[0] == '-' || point[0] == '*' ||
               point[0] == '/' || point[0] == '^' ||
               point[0] == 'm') {  // means it is an operator
      double b = d_pop(&stack);
      double a = d_pop(&stack);
      switch (point[0]) {
        case '+':
          result = a + b;
          break;
        case '-':
          result = a - b;
          break;
        case '*':
          result = a * b;
          break;
        case '/':
          result = a / b;
          break;
        case '^':
          result = pow(a, b);
          break;
        case 'm':
          result = fmod(a, b);
          break;
        default:
          break;
      }
      d_push(&stack, result);
    } else if (point[0] == 's' || point[0] == 'c' || point[0] == 't' ||
               point[0] == 'a' || point[0] == 'l') {
      result = d_pop(&stack);
      switch (point[0]) {
        case 's':
          if (point[1] == 'i') {
            result = sin(result);
          } else if (point[1] == 'q') {
            result = sqrt(result);
          }
          break;
        case 'c':
          result = cos(result);
          break;
        case 't':
          result = tan(result);
          break;
        case 'a':
          if (point[1] == 's')
            result = asin(result);
          else if (point[1] == 'c')
            result = acos(result);
          else if (point[1] == 't')
            result = atan(result);
          break;
        case 'l':
          if (point[1] == 'o')
            result = log10(result);
          else if (point[1] == 'n')
            result = log(result);
          break;
        default:
          break;
      }
      d_push(&stack, result);
    }
    point = strtok(NULL, " \n");
  }
  result = d_pop(&stack);
  return result;
}

double graph_build(double x, char *str) {
  char *edit_str = (char *)calloc(strlen(str) * 2, sizeof(char));
  input(edit_str, str);
  char *rpn_str = (char *)calloc(strlen(edit_str), sizeof(char));
  get_rpn(edit_str, rpn_str);
  free(edit_str);
  double y = rpn_calculate(rpn_str, x);
  free(rpn_str);
  return y;
}
