 #include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
};

Node* head = NULL;

void insertAtBeginning(int x) {
    Node* newNode = new Node;
    newNode->data = x;
    if (head == NULL) {
        newNode->next = newNode;
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != head)
        temp = temp->next;
    temp->next = newNode;
    newNode->next = head;
    head = newNode;
}

void insertAtEnd(int x) {
    Node* newNode = new Node;
    newNode->data = x;
    if (head == NULL) {
        newNode->next = newNode;
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != head)
        temp = temp->next;
    temp->next = newNode;
    newNode->next = head;
}

void insertAfter(int key, int x) {
    Node* temp = head;
    if (temp == NULL) return;
    do {
        if (temp->data == key) {
            Node* newNode = new Node;
            newNode->data = x;
            newNode->next = temp->next;
            temp->next = newNode;
            return;
        }
        temp = temp->next;
    } while (temp != head);
    cout << "Node " << key << " not found"<<endl;
}

void deleteNode(int key) {
    if (head == NULL) {
        cout << "List is empt"<<endl;
        return;
    }
    Node* temp = head, *prev = NULL;
    do {
        if (temp->data == key)
            break;
        prev = temp;
        temp = temp->next;
    } while (temp != head);

    if (temp->data != key) {
        cout << "Node " << key << " not found"<<endl;
        return;
    }

    if (temp == head && temp->next == head) {
        head = NULL; // only one node
    } else if (temp == head) {
        Node* last = head;
        while (last->next != head)
            last = last->next;
        head = head->next;
        last->next = head;
    } else {
        prev->next = temp->next;
    }
    delete temp;
    cout << "Node " << key << " deleted"<<endl;
}

void searchNode(int key) {
    if (head == NULL) {
        cout << "List empty"<<endl;
        return;
    }
    Node* temp = head;
    int pos = 1;
    do {
        if (temp->data == key) {
            cout << "Node " << key << " found at position " << pos << endl;
            return;
        }
        temp = temp->next;
        pos++;
    } while (temp != head);
    cout << "Node " << key << " not found"<<endl;
}

void display() {
    if (head == NULL) {
        cout << "List empty!\n";
        return;
    }
    Node* temp = head;
    cout << "Circular Linked List: ";
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
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
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value: "<<endl;
            cin >> value;
            insertAtBeginning(value);
            break;
        case 2:
            cout << "Enter value: "<<endl;
            cin >> value;
            insertAtEnd(value);
            break;
        case 3:
            cout << "Enter key (after which to insert): "<<endl;
            cin >> key;
            cout << "Enter value: "<<endl;
            cin >> value;
            insertAfter(key, value);
            break;
        case 4:
            cout << "Enter node value to delete: "<<endl;
            cin >> value;
            deleteNode(value);
            break;
        case 5:
            cout << "Enter value to search: "<<endl;
            cin >> value;
            searchNode(value);
            break;
        case 6:
            display();
            break;
        case 7:
            cout << "Exiting"<<endl;
            return 0;
        default:
            cout << "Invalid choice"<<endl;
        }
    }
}