#include <stdio.h>
#include <string.h>

#define Max 100

char stack[Max];
int top = -1;

void push(char c) {
    if (top < Max - 1) {
        top++;
        stack[top] = c;
    } else {
        printf("Stack overflow\n");
    }
}

char pop() {
    if (top >= 0) {
        char c = stack[top];
        top--;
        return c;
    } else {
        printf("Stack underflow\n");
        return '\0';
    }
}

int isPAl(char str[]) {
    top = -1;
    int len = strlen(str);


    for (int i = 0; i < len; i++) {
        push(str[i]);
    }


    for (int i = 0; i < len; i++) {
        if (str[i] != pop()) {
            return 0;
        }
    }
    return 1;
}

int areParenthesesBalanced(char expr[]) {
    top = -1;
    for (int i = 0; expr[i] != '\0'; i++) {
        char c = expr[i];

        if (c == '(' || c == '{' || c == '[') {
            push(c);
        } else if (c == ')' || c == '}' || c == ']') {
            char popped = pop();
            if ((c == ')' && popped != '(') ||
                (c == '}' && popped != '{') ||
                (c == ']' && popped != '[')) {
                return 0;
            }
        }
    }
    return (top == -1);
}

int main() {
    char str1[Max];
    char expr1[Max];

    printf("Enter a string to check palindrome: ");
    fgets(str1, sizeof(str1), stdin);
    str1[strcspn(str1, "\n")] = '\0';

    if (isPAl(str1)) {
        printf("It is a palindrome.\n");
    } else {
        printf("It is not a palindrome.\n");
    }

    printf("Enter an expression to check for balanced parentheses: ");
    fgets(expr1, sizeof(expr1), stdin);
    expr1[strcspn(expr1, "\n")] = '\0';

    if (areParenthesesBalanced(expr1)) {
        printf("The parentheses in the expression are balanced.\n");
    } else {
        printf("The parentheses in the expression are not balanced.\n");
    }

    return 0;
}
