#include <iostream>
using namespace std;

int stack1[100], stack2[100], stack3[100];
int top1 = -1, top2 = -1, top3 = -1;

void push(int s[], int &top, int val) {
    top++;
    s[top] = val;
}

int pop(int s[], int &top) {
    int val = s[top];
    top--;
    return val;
}

int peek(int s[], int top) {
    if (top == -1) return -1;
    return s[top];
}

void moveDisk(int s1[], int &t1, char from,
              int s2[], int &t2, char to) {
    int disk1 = peek(s1, t1);
    int disk2 = peek(s2, t2);

    if (disk1 == -1) {
        push(s1, t1, pop(s2, t2));
        cout << "Move disk from " << to << " to " << from << endl;
    } else if (disk2 == -1) {
        push(s2, t2, pop(s1, t1));
        cout << "Move disk from " << from << " to " << to << endl;
    } else if (disk1 > disk2) {
        push(s1, t1, pop(s2, t2));
        cout << "Move disk from " << to << " to " << from << endl;
    } else {
        push(s2, t2, pop(s1, t1));
        cout << "Move disk from " << from << " to " << to << endl;
    }
}

void hanoiIterative(int n) {
    char src = 'A', dest = 'B', aux = 'C';

    if (n % 2 == 0) {
        char temp = dest;
        dest = aux;
        aux = temp;
    }

    int totalMoves = 1;
    for (int i = 0; i < n; i++) totalMoves *= 2;
    totalMoves -= 1;

    for (int i = n; i >= 1; i--) {
        push(stack1, top1, i);
    }

    for (int move = 1; move <= totalMoves; move++) {
        if (move % 3 == 1)
            moveDisk(stack1, top1, src, stack3, top3, dest);
        else if (move % 3 == 2)
            moveDisk(stack1, top1, src, stack2, top2, aux);
        else
            moveDisk(stack2, top2, aux, stack3, top3, dest);
    }
}

int main() {
    int n;
    cout << "Enter number of disks: ";
    cin >> n;
    hanoiIterative(n);
    return 0;
}