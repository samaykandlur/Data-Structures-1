#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char c) {
    if (top < MAX - 1)
        stack[++top] = c;
    else
        printf("Stack overflow\n");
}

char pop() {
    if (top >= 0)
        return stack[top--];
    else
        return '\0';
}

char peek() {
    if (top >= 0)
        return stack[top];
    else
        return '\0';
}


int precedence(char op) {
    switch (op) {
        case '^': return 3;
        case '*':
        case '/': return 2;
        case '+':
        case '-': return 1;
        default: return 0;
    }
}


int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}


void infixToPostfix(char infix[], char postfix[]) {
    int i = 0, k = 0;
    char c;
    top = -1;

    while ((c = infix[i++]) != '\0') {
        if (isalnum(c)) {

            postfix[k++] = c;
        } else if (c == '(') {
            push(c);
        } else if (c == ')') {

            while (top != -1 && peek() != '(') {
                postfix[k++] = pop();
            }
            if (top != -1) pop();
        } else if (isOperator(c)) {
            while (top != -1 && precedence(peek()) >= precedence(c)) {
                if (c == '^' && peek() == '^') break;
                else postfix[k++] = pop();
            }
            push(c);
        }
    }

    while (top != -1) {
        postfix[k++] = pop();
    }
    postfix[k] = '\0';
}

int evalStack[MAX];
int evalTop = -1;

void evalPush(int val) {
    if (evalTop < MAX - 1)
        evalStack[++evalTop] = val;
    else
        printf("Evaluation stack overflow\n");
}

int evalPop() {
    if (evalTop >= 0)
        return evalStack[evalTop--];
    else {
        printf("Evaluation stack underflow\n");
        return 0;
    }
}

int evaluatePostfix(char postfix[]) {
    evalTop = -1;
    int i = 0;
    char c;

    while ((c = postfix[i++]) != '\0') {
        if (isdigit(c)) {

            evalPush(c - '0');
        } else if (isOperator(c)) {
            int val2 = evalPop();
            int val1 = evalPop();
            int res = 0;

            switch (c) {
                case '+': res = val1 + val2; break;
                case '-': res = val1 - val2; break;
                case '*': res = val1 * val2; break;
                case '/': res = val1 / val2; break;
                case '^': res = (int)pow(val1, val2); break;
            }
            evalPush(res);
        }
    }
    return evalPop();
}

int main() {
    char infix[MAX], postfix[MAX];

    printf("Enter an infix expression (operands single-digit letters or digits): ");
    fgets(infix, sizeof(infix), stdin);
    infix[strcspn(infix, "\n")] = '\0';


    infixToPostfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);

    int canEvaluate = 1;
    for (int i = 0; postfix[i] != '\0'; i++) {
        if (isalnum(postfix[i]) && !isdigit(postfix[i])) {
            canEvaluate = 0;
            break;
        }
    }

    if (canEvaluate) {
        int result = evaluatePostfix(postfix);
        printf("Evaluation result: %d\n", result);
    } else {
        printf("Postfix contains non-digit operands, skipping evaluation.\n");
    }

    return 0;
}
