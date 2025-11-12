#include<iostream>
using namespace std;
struct bt {
public:
    int data;
    struct bt* right;
    struct bt* left;
};
typedef struct bt node;
node* createnode(int value) {
    node* newnode = new node;
    newnode->data = value;
    newnode->right = NULL;
    newnode->left = NULL;
    return newnode;
}
node* createtree() {
    int x;
    cin >> x;
    if (x == -1) {
        return NULL;
    }
    node* root = createnode(x);
    root->left = createtree();
    root->right = createtree();
    return root;
}
void preorder(node* root) {
    if (root == NULL) {
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}
void inorder(node* root) {
    if (root == NULL) {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
void postorder(node* root) {
    if (root == NULL) {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int main() {
    cout << "Enter elements in pre-order: ";
    node* root = createtree();
    cout << "Preorder Traversal: "<<endl;
    preorder(root);
    cout << "Inorder Traversal: "<<endl;
    inorder(root);
    cout << "Postorder Traversal: "<<endl;
    postorder(root);

    return 0;
}