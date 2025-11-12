#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
};

Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = temp->right = NULL;
    return temp;
}

void inorder(Node* root, vector<int> &arr) {
    if (root == NULL) return;
    inorder(root->left, arr);
    arr.push_back(root->data);
    inorder(root->right, arr);
}

bool isBST(Node* root) {
    vector<int> arr;
    inorder(root, arr);

    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] <= arr[i - 1]) 
            return false;
    }
    return true;
}
int main() {
    Node* root = newNode(4);
    root->left = newNode(2);
    root->right = newNode(6);
    root->left->left = newNode(1);
    root->left->right = newNode(3);
    root->right->left = newNode(5);
    root->right->right = newNode(7);

    if (isBST(root))
        cout << "The tree is a BST";
    else
        cout << " The tree is NOT a BST";

    return 0;
}