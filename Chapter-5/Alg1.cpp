#include<iostream>
using namespace std;

struct Node{
    int DATA;
    Node* NEXT;
};

Node* createNode(int value){
    Node* newNode = new Node;

    if(newNode == NULL){
        cout << "Overflow";
        return NULL;
    }
    newNode->DATA = value;
    newNode->NEXT = NULL;
    return newNode;
}

Node* traverse(Node* START){
    Node* PTR;
    PTR = START;
    while(PTR != NULL){
        cout << PTR->DATA << " ";
        PTR = PTR->NEXT;
    }
    cout << "NULL\n";
}
int main(){
    Node* START = NULL;
    START = createNode(10);
    START->NEXT = createNode(20);
    START->NEXT->NEXT = createNode(30);
    START->NEXT->NEXT->NEXT = createNode(40);

    cout << "Linked List Traversal: \n";
    traverse(START);

    return 0;
}