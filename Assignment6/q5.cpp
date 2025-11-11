#include<iostream>
using namespace std;
class cll {
public:
    int data;
    struct cll* next;
};
typedef struct cll node;
node* head = NULL;
void checkCircular();
int main() {
    int n;
    cin >> n;
    int i = 0;
    node* tail = NULL;
    while (i != n) {
        node* newnode = new node;
        int x;
        cin >> x;
        newnode->data = x;
        newnode->next = NULL;

        if (head == NULL) {
            head = newnode;
            tail = newnode;
            newnode->next = head; 
        } else {
            tail->next = newnode;
            newnode->next = head;
            tail = newnode;
        }
        i++;
    }

    checkCircular();
}
void checkCircular() {
    if (head == NULL) {
        cout << "List is empty";
        return;
    }

    node* temp = head->next;
    while (temp != NULL && temp != head) {
        temp = temp->next;
    }

    if (temp == head)
        cout << "True";
    else
        cout << "False";
}
