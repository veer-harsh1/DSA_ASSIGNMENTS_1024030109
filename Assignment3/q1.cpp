#include <iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    int stack[n];
    int top = -1;
    int choice, value;

    while (true) {
        cin >> choice;

        switch (choice) {
            case 1: // Push
                cout << "Enter value to push: ";
                cin >> value;
                if (top == n-1) {
                    cout << "Stack Overflow Cannot push " << value << endl;
                } else {
                    stack[++top] = value;
                    cout << value << " pushed into stack." << endl;
                }
                break;

            case 2: // Pop
                if (top == -1) {
                    cout << "Stack Underflow" << endl;
                } else {
                    cout << stack[top--] << " popped from stack." << endl;
                }
                break;

            case 3: // isEmpty
                if (top==-1)
                {
                    cout<<"Stack is empty";
                }
                else{
                    cout<<"Stack is full";
                }
                
                break;

            case 4: // isFull
                if (top==n-1)
                {
                    cout<<"Stack is full";
                }
                else{
                    cout<<"Stack is not full";
                }
                
                break;

            case 5: // Display
                if (top == -1) {
                    cout << "Stack is empty" << endl;
                } else {
                    cout << "Stack elements are: ";
                    for (int i = top; i >= 0; i--) {
                        cout << stack[i] << " ";
                    }
                    cout << endl;
                }
                break;

            case 6: // Peek
                if (top == -1) {
                    cout << "Stack is empty!" << endl;
                } else {
                    cout << "Top element is: " << stack[top] << endl;
                }
                break;

            case 7: // Exit
                cout << "Exiting program..." << endl;
                return 0; 

            default:
                cout << "Invalid choice " << endl;
        }
    }

    return 0;
}