 #include<iostream>
#include<set>
using namespace std;

struct Node{
    int data;
    Node* next;
};

Node* newNode(int data){
    Node* node = new Node;
    node->data = data;
    node->next = NULL;
    return node;
}
bool detectLoop(Node* head){
    set<Node*> st;

    Node* temp = head;

    while (temp != NULL) {
        if (st.find(temp) != st.end()){
           cout<<"FOUND";
        }

        st.insert(temp);  
        temp = temp->next;
    }
    cout<<"NOT FOUND";
 
}
int main(){

    Node* head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(3);
    head->next->next->next = head->next;
     detectLoop(head);

}