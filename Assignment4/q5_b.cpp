#include <iostream>
using namespace std;

int q[100];
int frontQ = 0, rearQ = -1, sizeQ = 0;

bool isEmpty() { return sizeQ == 0; }
bool isFull()  { return sizeQ == 100; }

void enqueue(int x) {
    if (isFull()) return;
    rearQ = (rearQ + 1) % 100;
    q[rearQ] = x;
    sizeQ++;
}

void dequeue() {
    if (isEmpty()) return;
    frontQ = (frontQ + 1) % 100;
    sizeQ--;
}

int peek() {
    if (isEmpty()) return -1;
    return q[frontQ];
}

int getSize() { return sizeQ; }

void push(int x) {
    enqueue(x);
    int sz = getSize();
    for (int i = 0; i < sz - 1; i++) {
        enqueue(peek());
        dequeue();
    }
}

void pop() {
    if (!isEmpty()) dequeue();
    else cout << "Stack Empty" << endl;
}

int top() {
    if (!isEmpty()) return peek();
    return -1;
}

bool empty() {
    return isEmpty();
}

int main() {
    push(5);
    push(15);
    cout << "Top (One Queue): " << top() << endl;
    pop();
    cout << "Top after pop: " << top() << endl;
    return 0;
}
