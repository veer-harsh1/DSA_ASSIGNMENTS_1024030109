#include<iostream>
using namespace std;
class dll{
    public:
    int data;
    struct dll * next;
};
typedef struct dll node;
node*head=NULL;
void printcll();
int main(){
    int n;
    cin>>n;
    int i=0;
    node*tail=NULL;
    while(i!=n){
        node* newnode=new node;
           int x;
            cin>>x;
            newnode->data=x;
            newnode->next=NULL;
        if(head==NULL){
            head=newnode;
            tail=newnode;
           newnode->next=head;
        }
        else{
            tail->next=newnode;
            newnode->next=head;
            tail=newnode;
        }
        i++;
    }
    printcll();
}
void printcll(){
    node*temp=head;
    do{
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    while(temp!=head);
    cout << head->data; 
}