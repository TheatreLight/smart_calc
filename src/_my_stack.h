#ifndef SRC__MY_STACK_H_
#define SRC__MY_STACK_H_

typedef struct Stack {
    struct Stack *next;
    char data[5];
} Stack;

typedef struct D_stack {
    struct D_stack *next;
    double value;
} D_stack;

void push(Stack **head, char *data);
char *pop(Stack **head, char *data);
void peek(Stack **head, char *data);
void remove_stack(Stack **head);

void d_push(D_stack **head, double value);
double d_pop(D_stack **head);
double d_peek(D_stack **head);


#endif  // SRC__MY_STACK_H_
