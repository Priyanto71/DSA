#include<iostream>
using namespace std;

struct Node{
    int DATA;
    Node* NEXT;
};
Node* getNode(Node*& AVAIL){

    if(AVAIL == NULL){
        return NULL;
    }
    Node* temp = AVAIL;
    AVAIL = AVAIL->NEXT;
    return temp;
}

Node* INSFIRST(Node* START, Node*& AVAIL, int ITEM){
    if(AVAIL == NULL){
        cout << "Overflow";
        return START;
    }
    Node* NEW = getNode(AVAIL);
    NEW->DATA = ITEM;
    NEW->NEXT = START;
    START = NEW;
    return START;

}

Node* TRAVERSAL(Node* START){
    Node* PTR = START;
    while(PTR != NULL){
        cout << PTR->DATA << " -> ";
        PTR = PTR->NEXT;
    }
    cout << "NULL" << endl;

}

int main(){
    Node* START = NULL;
    Node* AVAIL = new Node();
    AVAIL->NEXT = new Node();
    AVAIL->NEXT->NEXT = new Node();
    AVAIL->NEXT->NEXT->NEXT = NULL;

    START = INSFIRST(START, AVAIL, 10);
    START = INSFIRST(START, AVAIL, 20);
    START = INSFIRST(START, AVAIL, 30);
    TRAVERSAL(START);
    START = INSFIRST(START, AVAIL, 40);
    return 0;

}