#include<iostream>
using namespace std;
struct cll{
    public:
    int data;
    struct cll*next;
};
typedef struct cll node;
node*head=NULL;
void findsize();
int main(){
int n;
cin>>n;
int i=0;
node*tail=NULL;
while(i!=n){
    node*newnode=new node;
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
findsize();
}
void findsize(){

    node*temp=head;
    if(head==NULL){
        cout<<0;
        return;
    }
    int cnt=0;
    do{
        cnt++;
        temp=temp->next;
    }while(temp!=head);
    cout<<cnt;
}
