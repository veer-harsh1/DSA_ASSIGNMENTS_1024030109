#include <iostream>
using namespace std;

char stackArr[100];
int top = -1;

void push(char c)
{
    stackArr[++top] = c;
}

char pop()
{
    return stackArr[top--];
}

bool isEmpty()
{
    return top == -1;
}

bool isBalanced(char expr[])
{
    for (int i = 0; expr[i] != '\0'; i++)
    {
        char c = expr[i];
        if (c == '(' || c == '{' || c == '[')
        {
            push(c);
        }
        else if (c == ')' || c == '}' || c == ']')
        {
            if (isEmpty())
                return false;
            char x = pop();
            if ((c == ')' && x != '(') ||
                (c == '}' && x != '{') ||
                (c == ']' && x != '['))
            {
                return false;
            }
        }
    }
    return isEmpty();
}

int main()
{
    char expr[100];
    cout << "Enter expression: ";
    cin >> expr;

    if (isBalanced(expr))
        cout << "Balanced" << endl;
    else
        cout << "Not Balanced" << endl;
    return 0;
}
