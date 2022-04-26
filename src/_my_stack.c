#include "_my_stack.h"

#include <string.h>
#include <stdlib.h>

void push(Stack **head, char *data) {
    Stack *tmp = malloc(sizeof(Stack));
    if (tmp != NULL) {
    for (int i = 0; i <= (int)strlen(data); i++) {
        tmp->data[i] = data[i];
    }
    tmp->next = (*head);
    (*head) = tmp;
    }
}

void d_push(D_stack **head, double value) {
    D_stack *tmp = malloc(sizeof(D_stack));
    if (tmp != NULL) {
    tmp->value = value;
    tmp->next = (*head);
    (*head) = tmp;
    }
}

char *pop(Stack **head, char *data) {
    Stack *out;
    if (*head != NULL) {
        out = *head;
        *head = (*head)->next;
        for (int i = 0; i <= (int)strlen(data); i++) {
            data[i] = out->data[i];
        }
        free(out);
    }
    return data;
}

double d_pop(D_stack **head) {
    D_stack *out;
    double value = 0;
    if (*head != NULL) {
        out = *head;
        *head = (*head)->next;
        value = out->value;
        free(out);
    }
    return value;
}

