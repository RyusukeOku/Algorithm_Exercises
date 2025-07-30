
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STACK_SIZE 100

// float型のスタックを定義
typedef struct {
    float stack[MAX_STACK_SIZE];
    int top;
} FloatStack;

// スタックを初期化
void initStack(FloatStack *s) {
    s->top = -1;
}

// スタックが空であるかどうか判定
bool isStackEmpty(const FloatStack *s) {
    return s->top == -1;
}

// Push
void push(FloatStack *s, float value) {
    if (s->top < MAX_STACK_SIZE - 1) {
        s->stack[++s->top] = value;
    } else {
        printf("Stack overflow\n");
    }
}

// Pop
float pop(FloatStack *s) {
    if (!isStackEmpty(s)) {
        return s->stack[s->top--];
    } else {
        printf("Stack underflow\n");
        return 0.0; // underflowなら0.0を返す
    }
}

// RPNで計算する関数
float evaluateRPN(char* expression) {
    FloatStack s;
    initStack(&s);

    char *token = strtok(expression, " ");
    while (token != NULL) {
        if (strcmp(token, "+") == 0) {
            float b = pop(&s);
            float a = pop(&s);
            push(&s, a + b);
        } else if (strcmp(token, "-") == 0) {
            float b = pop(&s);
            float a = pop(&s);
            push(&s, a - b);
        } else if (strcmp(token, "*") == 0) {
            float b = pop(&s);
            float a = pop(&s);
            push(&s, a * b);
        } else if (strcmp(token, "/") == 0) {
            float b = pop(&s);
            float a = pop(&s);
            push(&s, a / b);
        } else {
            push(&s, atof(token));
        }
        token = strtok(NULL, " ");
    }

    return pop(&s);
}

int main() {
    char expression[] = "3 4 + 2 7 * /"; // 例
    float result = evaluateRPN(expression);
    printf("Result: %f\n", result);
    return 0;
}
