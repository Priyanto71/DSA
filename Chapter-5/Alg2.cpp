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

Node* SEARCH(Node* START, int ITEM){
    Node* PTR = START;
    while(PTR != NULL){
        if(PTR->DATA == ITEM){
            return PTR;
        }else{
            PTR = PTR->NEXT;
        }
    }
    return NULL;
}
int main(){
    Node* START = NULL;
    START = createNode(10);
    START->NEXT = createNode(30);
    START->NEXT->NEXT = createNode(20);
    START->NEXT->NEXT->NEXT = createNode(40);

    int ITEM = 0;
    cout << "Searching ITEM: ";
    cin >> ITEM;
    Node* LOC = SEARCH(START, ITEM);
    if(LOC == NULL){
        cout << "ITEM is not in the linked list";
    }else{
        cout << "ITEM is found at address: " << LOC;
    }
    return 0;
}