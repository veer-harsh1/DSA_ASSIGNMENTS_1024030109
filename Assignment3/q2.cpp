#include <iostream>
#include <string>
using namespace std;

int main() {
    char stackArr[100];
    int top = -1;
    string str;

    cout << "Enter a string: ";
    cin >> str;

   
    for (int i = 0; i < str.length(); i++) {
        stackArr[++top] = str[i];
        
    }

    cout << "Reversed string: ";
    while (top != -1) {
        cout << stackArr[top--];
       
    }
    cout << endl;

    return 0;
}