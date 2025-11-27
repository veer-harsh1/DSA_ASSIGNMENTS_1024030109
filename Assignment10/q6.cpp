#include<iostream>
#include<set>
using namespace std;
set<int> st;
struct Node {
    int data;
    Node* left;
    Node* right;
};
Node* newNode(int data){
    Node* node = new Node;
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}
bool hasDuplicateHash(Node* root){

    if (root == NULL)
        return false;

    if (st.find(root->data) != st.end()) {
        cout << "FOUND ";
        return true;
    }

    st.insert(root->data);

    return hasDuplicateHash(root->left) || hasDuplicateHash(root->right);
}
int main(){
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(2); 

    if (hasDuplicateHash(root))
        cout << "Duplicates Found";
    else
        cout << "No Duplicates";
    return 0;
}
