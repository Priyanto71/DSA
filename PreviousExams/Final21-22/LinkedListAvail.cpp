#include<iostream>
using namespace std;
#define MAX 20

struct Node {
    int data;
    int next;  
};

Node L[MAX];   
Node A[MAX];  
int listHead = -1;
int availHead = -1;

void initAvail(int size) {
    for (int i = 0; i < size - 1; i++) A[i].next = i + 1;
    A[size-1].next = -1;
    availHead = 0;
}

int getFromAvail() {
    if (availHead == -1) { cout << "Avail list empty!\n"; return -1; }
    int idx = availHead;
    availHead = A[availHead].next;
    return idx;
}

void insertAfterX(int X, int N) {
   
    int cur = listHead, prev = -1;
    while (cur != -1 && L[cur].data != X) { prev = cur; cur = L[cur].next; }
    if (cur == -1) { cout << "X not found!\n"; return; }

    int newIdx = getFromAvail();
    if (newIdx == -1) return;

    L[newIdx].data = N;
    L[newIdx].next = L[cur].next;  
    L[cur].next    = newIdx;      

    cout << "Inserted " << N << " after " << X << "\n";
}

void buildList(int vals[], int size) {
    listHead = 0;
    for (int i = 0; i < size - 1; i++) { L[i].data = vals[i]; L[i].next = i+1; }
    L[size-1].data = vals[size-1]; L[size-1].next = -1;
}

void printList() {
    int cur = listHead;
    while (cur != -1) { cout << L[cur].data << " -> "; cur = L[cur].next; }
    cout << "NULL\n";
}

int main() {
    int vals[] = {10, 20, 30, 40, 50};
    buildList(vals, 5);
    initAvail(10);

    cout << "Original List: "; printList();
    insertAfterX(20, 25);
    cout << "Updated List:  "; printList();
    return 0;
}