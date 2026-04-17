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

Node* INSLOC(Node* START, Node*& AVAIL, Node* LOC, int ITEM){
    if(AVAIL == NULL){
        cout << "Overflow\n";
        return START;
    }
    Node* NEW = getNode(AVAIL);
    NEW->DATA = ITEM;
    if(LOC == NULL){
        NEW->NEXT = START;
        START = NEW;
    }else{
        NEW->NEXT = LOC->NEXT;
        LOC->NEXT = NEW;
    }
    return START;
}

Node* FINDA(Node* START, int ITEM){
    if(START == NULL){
        return NULL;
    }
    if(ITEM < START->DATA){
        return NULL;
    }
    Node* SAVE = START;
    Node* PTR = START->NEXT;

    while(PTR != NULL){
        if(ITEM < PTR->DATA){
            return SAVE;
        }
        SAVE = PTR;
        PTR = PTR->NEXT;
    }
    return SAVE;
}

Node* INSSRT(Node* START, Node*& AVAIL, int ITEM){
    Node* LOC = FINDA(START, ITEM);
    START = INSLOC(START, AVAIL, LOC, ITEM);
    return START;
}

void Traversal(Node* START){
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
    AVAIL->NEXT->NEXT->NEXT = new Node();
    AVAIL->NEXT->NEXT->NEXT->NEXT = new Node();
    AVAIL->NEXT->NEXT->NEXT->NEXT->NEXT = NULL;

    START = INSSRT(START, AVAIL, 20);
    START = INSSRT(START, AVAIL, 10);
    START = INSSRT(START, AVAIL, 30);
    START = INSSRT(START, AVAIL, 25);
    Traversal(START);
    return 0;

}