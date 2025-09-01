#include <iostream>
using namespace std;

#define MAX 100
char stackArr[MAX];
int top = -1;

void push(char c) { 
    stackArr[++top] = c;
 }

char pop() {
     return stackArr[top--]; 
}

char peek() { 
    return stackArr[top]; 
}

bool isEmpty() {
     return top == -1; 
}

int prec(char c) {
    if (c == '^') return 3;
    else if (c == '*' || c == '/') return 2;
    else if (c == '+' || c == '-') return 1;
    return -1;
}

void inToPost(char infix[]) {
    char postfix[100];
    int k = 0;

    for (int i = 0; infix[i] != '\0'; i++) {
        char c = infix[i];

        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) {
            postfix[k++] = c;
        }
        else if (c == '(') {
            push(c);
        }
        else if (c == ')') {
            while (!isEmpty() && peek() != '(') {
                postfix[k++] = pop();
            }
            pop();
        }
        else {
            while (!isEmpty() && prec(peek()) >= prec(c)) {
                postfix[k++] = pop();
            }
            push(c);
        }
    }
    
    while (!isEmpty()) {
        postfix[k++] = pop();
    }
    postfix[k] = '\0';
    cout << "Postfix: " << postfix << endl;
}

int main() {
    char exp[100];
    cout << "Enter infix expression: ";
    cin >> exp;
    inToPost(exp);
    return 0;
}