#include<iostream>
using namespace std;
class dll{
public:
int data;
struct dll*next;
struct dll* prev;

};
typedef struct dll node;
node*head=NULL;
node*tail=NULL;
void checkpalindrome();
int main(){
  int n;
  cin>>n;
  int i=0;
  while(i!=n){
    node*newnode=new node;
    int x;
    cin>>x;
    newnode->data=x;
    newnode->next=NULL;
    newnode->prev=NULL;
    if(head==NULL){
        head=newnode;
        tail=newnode;
        tail->next=NULL;
    }
    else{
        tail->next=newnode;
        newnode->prev=tail;
        tail=newnode;
    }
    i++;
  }
  checkpalindrome();
}
void checkpalindrome(){
    node*temp=head;
    node* end=tail;
    bool flag=true;
    while(temp!=end&&temp->prev!=end){
        if(temp->data==end->data){
            temp=temp->next;
            end=end->prev;
        }
        else{
            flag=false;
            break;
        }
    }
    if(flag==true){
        cout<<"This is a palindrome"<<endl;
    }
    else{
        cout<<"This is not a plaindrome";
    }
    
}