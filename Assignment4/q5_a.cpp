#include <iostream>
using namespace std;

int q1[100], q2[100];
int front1 = 0, rear1 = -1, size1 = 0;
int front2 = 0, rear2 = -1, size2 = 0;

bool isEmpty1() { return size1 == 0; }
bool isFull1() { return size1 == 100; }

bool isEmpty2() { return size2 == 0; }
bool isFull2() { return size2 == 100; }

void enqueue1(int x)
{
    if (isFull1())
        return;
    rear1 = (rear1 + 1) % 100;
    q1[rear1] = x;
    size1++;
}

void dequeue1()
{
    if (isEmpty1())
        return;
    front1 = (front1 + 1) % 100;
    size1--;
}

int peek1()
{
    if (isEmpty1())
        return -1;
    return q1[front1];
}

void enqueue2(int x)
{
    if (isFull2())
        return;
    rear2 = (rear2 + 1) % 100;
    q2[rear2] = x;
    size2++;
}

void dequeue2()
{
    if (isEmpty2())
        return;
    front2 = (front2 + 1) % 100;
    size2--;
}

int peek2()
{
    if (isEmpty2())
        return -1;
    return q2[front2];
}

void push(int x)
{
    enqueue2(x);

    while (!isEmpty1())
    {
        enqueue2(peek1());
        dequeue1();
    }

    swap(q1, q2);
    swap(front1, front2);
    swap(rear1, rear2);
    swap(size1, size2);
}

void pop()
{
    if (!isEmpty1())
    {
        dequeue1();
    }
    else
    {
        cout << "Stack Empty" << endl;
    }
}

int top()
{
    if (!isEmpty1())
    {
        return peek1();
    }
    return -1;
}

bool empty()
{
    return isEmpty1();
}

int main()
{
    push(10);
    push(20);
    cout << "Top (Two Queues): " << top() << endl;
    pop();
    cout << "Top after pop: " << top() << endl;
    return 0;
}
