#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node *left,*right;
};

Node* create(int x)
{
    Node *p=new Node;
    p->data=x;
    p->left=p->right=NULL;
    return p;
}

void preorder(Node *root)
{
    if(root==NULL) return;

    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node *root)
{
    if(root==NULL) return;

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void postorder(Node *root)
{
    if(root==NULL) return;

    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

int main()
{
    Node *root=create(1);

    root->left=create(12);
    root->right=create(9);

    root->left->left=create(5);
    root->left->right=create(6);

    cout<<"Preorder: ";
    preorder(root);

    cout<<"\nInorder: ";
    inorder(root);

    cout<<"\nPostorder: ";
    postorder(root);

    return 0;
}