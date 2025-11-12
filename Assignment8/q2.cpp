#include <iostream>
using namespace std;

struct bst {
    int data;
    struct bst* left;
    struct bst* right;
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

    return root;
}
node* searchRecursive(node* root, int key) {
    if (root == NULL || root->data == key)
        return root;

    if (key < root->data)
        return searchRecursive(root->left, key);
    else
        return searchRecursive(root->right, key);
}


node* searchIterative(node* root, int key) {
    while (root != NULL) {
        if (root->data == key)
            return root;
        else if (key < root->data)
            root = root->left;
        else
            root = root->right;
    }
    return NULL;
}

node* findMax(node* root) {
    if (root == NULL)
        return NULL;
    while (root->right != NULL)
        root = root->right;
    return root;
}

node* findMin(node* root) {
    if (root == NULL)
        return NULL;
    while (root->left != NULL)
        root = root->left;
    return root;
}

node* inorderSuccessor(node* root, node* target) {
    if (target->right != NULL)
        return findMin(target->right);

    node* successor = NULL;
    while (root != NULL) {
        if (target->data < root->data) {
            successor = root;
            root = root->left;
        } else if (target->data > root->data) {
            root = root->right;
        } else
            break;
    }
    return successor;
}

node* inorderPredecessor(node* root, node* target) {
    if (target->left != NULL)
        return findMax(target->left);

    node* predecessor = NULL;
    while (root != NULL) {
        if (target->data > root->data) {
            predecessor = root;
            root = root->right;
        } else if (target->data < root->data) {
            root = root->left;
        } else
            break;
    }
    return predecessor;
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

    cout << "Enter elements of BST: ";
    for (int i = 0; i < n; i++) {
        cin >> val;
        root = insert(root, val);
    }
    cout << "Inorder traversal of BST: ";
    inorder(root);

    // Searching
    int key;
    cout << "Enter value to search: ";
    cin >> key;
    node* found = searchRecursive(root, key);
    if (found)
        cout << key << " found (Recursive)"<<endl;
    else
        cout << key << " not found (Recursive)"<<endl;

    found = searchIterative(root, key);
    if (found)
        cout << key << " found (Iterative)\n";
    else
        cout << key << " not found (Iterative)\n";

    // Maximum and Minimum
    node* maxNode = findMax(root);
    node* minNode = findMin(root);
    cout << "Maximum element: " << maxNode->data;
    cout << "Minimum element: " << minNode->data;

    // Inorder Successor and Predecessor
    cout << "\n\nEnter node value to find successor and predecessor: ";
    int targetVal;
    cin >> targetVal;
    node* target = searchRecursive(root, targetVal);
    if (target == NULL) {
        cout << "Node not found"<<endl;
        return 0;
    }
    node* succ = inorderSuccessor(root, target);
    node* pred = inorderPredecessor(root, target);
    if (succ)
        cout << "Inorder Successor of " << targetVal << " is " << succ->data << endl;
    else
        cout << "Inorder Successor does not exist"<<endl;

    if (pred)
        cout << "Inorder Predecessor of " << targetVal << " is " << pred->data << endl;
    else
        cout << "Inorder Predecessor does not exist"<<endl;
              return 0;
}