#include<iostream>
using namespace std;

class dll {
public:
    int data;
    dll *next;
    dll *prev;
};

typedef dll node;
node* head = NULL;

void findsize_dll() ;
int main() {
    int n;
    cin >> n;
    node* tail = NULL;

    for (int i = 0; i < n; i++) {
        node* newnode = new node;
        cin >> newnode->data;
        newnode->next = NULL;
        newnode->prev = NULL;

        if (head == NULL) {
            head = newnode;
            tail = newnode;
        } else {
            tail->next = newnode;
            newnode->prev = tail;
            tail = newnode;
        }
    }

    findsize_dll();
}
void findsize_dll() {
    int cnt = 0;
    node* temp = head;
    while (temp != NULL) {
        cnt++;
        temp = temp->next;
    }
    cout << cnt;
}