#include <iostream>
#include <algorithm> 
using namespace std;
struct bst {
    int data;
    struct bst *left, *right;
};
typedef struct bst node;

node* createnode(int value) {
    node* newnode = new node;
    newnode->data = value;
    newnode->left = newnode->right = NULL;
    return newnode;
}


node* insert(node* root, int value) {
    if (root == NULL)
        return createnode(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);
    else
        cout << "Duplicate not allowed: " << value << endl;

    return root;
}


node* findMin(node* root) {
    while (root && root->left != NULL)
        root = root->left;
    return root;
}


node* deleteNode(node* root, int key) {
    if (root == NULL)
        return root;

    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else {
      
        if (root->left == NULL && root->right == NULL) {
            delete root;
            return NULL;
        } else if (root->left == NULL) {
            node* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == NULL) {
            node* temp = root->left;
            delete root;
            return temp;
        } else {
        
            node* temp = findMin(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }
    return root;
}

int maxDepth(node* root) {
    if (root == NULL)
        return 0;
    return 1 + max(maxDepth(root->left), maxDepth(root->right));
}


int minDepth(node* root) {
    if (root == NULL)
        return 0;


    if (!root->left)
        return 1 + minDepth(root->right);
    if (!root->right)
        return 1 + minDepth(root->left);

    return 1 + min(minDepth(root->left), minDepth(root->right));
}


void inorder(node* root) {
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    node* root = NULL;
    int n, val;

    cout << "Enter number of elements: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> val;
        root = insert(root, val);
    }

    cout << "Inorder traversal of BST: ";
    inorder(root);
    cout << endl;
    int key;
    cout << "Enter element to delete: ";
    cin >> key;
    root = deleteNode(root, key);
    cout << "BST after deletion: ";
    inorder(root);
    cout << endl;
    cout << "Maximum Depth of BST: " << maxDepth(root)<<endl;
    cout << "Minimum Depth of BST: " << minDepth(root) << endl;

    return 0;
}