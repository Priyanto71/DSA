#include <iostream>
using namespace std;

#define MAX 10

int deque[MAX];
int front = -1, rear = -1;

bool isFull() {
    return (rear + 1) % MAX == front;
}
bool isEmpty() {
    return front == -1;
}

void insertFront(int val) {
    if (isFull()) { cout << "Full!" << endl; return; }
    if (isEmpty()) { front = 0; rear = 0; }
    else front = (front - 1 + MAX) % MAX;
    deque[front] = val;
    cout << val << " inserted at front." << endl;
}

void insertRear(int val) {
    if (isFull()) { cout << "Full!" << endl; return; }
    if (isEmpty()) { front = 0; rear = 0; }
    else rear = (rear + 1) % MAX;
    deque[rear] = val;
    cout << val << " inserted at rear." << endl;
}

void deleteFront() {
    if (isEmpty()) { cout << "Empty!" << endl; return; }
    cout << deque[front] << " deleted from front." << endl;
    if (front == rear) { front = -1; rear = -1; }
    else front = (front + 1) % MAX;
}

void deleteRear() {
    if (isEmpty()) { cout << "Empty!" << endl; return; }
    cout << deque[rear] << " deleted from rear." << endl;
    if (front == rear) { front = -1; rear = -1; }
    else rear = (rear - 1 + MAX) % MAX;
}

void display() {
    if (isEmpty()) { cout << "Empty!" << endl; return; }
    cout << "Deque: ";
    int i = front;
    while (true) {
        cout << deque[i] << " ";
        if (i == rear) break;
        i = (i + 1) % MAX;
    }
    cout << endl;
}

int main() {
    insertRear(10);
    insertRear(20);
    insertFront(5);
    insertRear(30);
    display();
    deleteFront();
    deleteRear();
    display();
    return 0;
}