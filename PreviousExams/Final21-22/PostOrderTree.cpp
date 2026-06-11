#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int val) {
    Node* node = new Node();
    node->data = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

Node* insert(Node* root, int val) {
    if (root == NULL) return newNode(val);
    if (val < root->data)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);
    return root;
}

void postOrder(Node* root) {
    if (root == NULL) return;
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

int main() {
    int values[] = {44, 30, 50, 22, 60, 55, 77, 57};
    int n = 8;

    Node* root = NULL;
    for (int i = 0; i < n; i++) {
        root = insert(root, values[i]);
    }

    cout << "Post-order traversal: ";
    postOrder(root);
    cout << endl;

    return 0;
}