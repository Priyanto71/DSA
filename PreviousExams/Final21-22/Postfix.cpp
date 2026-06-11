#include <iostream>
using namespace std;

int stack[100];
int top = -1;

void push(int val) { stack[++top] = val; }
int pop() { return stack[top--]; }

bool isDigit(char c) {
    return c >= '0' && c <= '9';
}

int main() {
    char expr[100];
    cout << "Enter postfix expression: ";
    cin.getline(expr, 100);

    int len = 0;
    while (expr[len] != '\0') len++;

    for (int i = 0; i < len; i++) {
        char c = expr[i];

        if (c == ' ') continue;

        if (isDigit(c)) {
            push(c - '0');
        } else {
            int b = pop();
            int a = pop();

            if (c == '+') push(a + b);
            else if (c == '-') push(a - b);
            else if (c == '*') push(a * b);
            else if (c == '/') push(a / b);
        }
    }

    cout << "Result: " << pop() << endl;
    return 0;
}