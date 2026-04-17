#include<iostream>
using namespace std;

struct Node{
    int DATA;
    Node* NEXT;
};

void Traversal(Node* START){
    Node* PTR = START;
    while(PTR != NULL){
        cout << PTR->DATA << " -> ";
        PTR = PTR->NEXT;
    }
    cout << "NULL" << endl;
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
int main(){
    Node* START = new Node{10, NULL};
    START->NEXT = new Node{20, NULL};
    START->NEXT->NEXT = new Node{30, NULL};
    START->NEXT->NEXT->NEXT = new Node{40, NULL};

    Traversal(START);
    int ITEM = 0;
    cout << "Enter ITEM: ";
    cin >> ITEM;

    Node* LOC = FINDA(START, ITEM);
    if(LOC == NULL){
        cout << "LOC = NULL";
    }else{
        cout << "LOC DATA = " << LOC->DATA;
    }
    return 0;
}