#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;
};

Node* head = NULL;

void insertAtBeginning(int x) {
    Node* newNode = new Node;
    newNode->data = x;
    newNode->prev = NULL;
    newNode->next = head;
    if (head != NULL)
        head->prev = newNode;
    head = newNode;
}

void insertAtEnd(int x) {
    Node* newNode = new Node;
    newNode->data = x;
    newNode->next = NULL;
    if (head == NULL) {
        newNode->prev = NULL;
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
}

void insertAfter(int key, int x) {
    Node* temp = head;
    while (temp != NULL && temp->data != key)
        temp = temp->next;
    if (temp == NULL) {
        cout << "Node " << key << " not found!"<<endl;
        return;
    }
    Node* newNode = new Node;
    newNode->data = x;
    newNode->next = temp->next;
    newNode->prev = temp;
    if (temp->next != NULL)
        temp->next->prev = newNode;
    temp->next = newNode;
}

void deleteNode(int key) {
    Node* temp = head;
    while (temp != NULL && temp->data != key)
        temp = temp->next;
    if (temp == NULL) {
        cout << "Node " << key << " not found!"<<endl;
        return;
    }
    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    else
        head = temp->next; 

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    delete temp;
    cout << "Node " << key << " deleted.";
}

void searchNode(int key) {
    Node* temp = head;
    int pos = 1;
    while (temp != NULL) {
        if (temp->data == key) {
            cout << "Node " << key << " found at position " << pos << ".\n";
            return;
        }
        temp = temp->next;
        pos++;
    }
    cout <<" not found.";
}

void display() {
    Node* temp = head;
    cout << "List (forward): ";
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    int choice, value, key;

    while (true) {
        cout << "1. Insert at Beginning"<<endl;
        cout << "2. Insert at End"<<endl;
        cout << "3. Insert After a Node"<<endl;
        cout << "4. Delete a Node"<<endl;
        cout << "5. Search a Node"<<endl;
        cout << "6. Display"<<endl;
        cout << "7. Exit"<<endl;
        cout << "Enter your choice: "<<endl;
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            insertAtBeginning(value);
            break;
        case 2:
            cout << "Enter value: ";
            cin >> value;
            insertAtEnd(value);
            break;
        case 3:
            cout << "Enter key (after which to insert): ";
            cin >> key;
            cout << "Enter value: ";
            cin >> value;
            insertAfter(key, value);
            break;
        case 4:
            cout << "Enter node value to delete: ";
            cin >> value;
            deleteNode(value);
            break;
        case 5:
            cout << "Enter value to search: ";
            cin >> value;
            searchNode(value);
            break;
        case 6:
            display();
            break;
        case 7:
            cout << "Exiting...";
            return 0;
        default:
            cout << "Invalid choice!";
        }
    }
}