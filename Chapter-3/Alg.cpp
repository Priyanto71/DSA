#include <iostream>
using namespace std;

int main() {
    char T[200], P[50];
    int S = 0, R = 0;
    int K, i;

    cout << "Enter Text T: ";
    cin >> T;

    cout << "Enter Pattern P: ";
    cin >> P;

    cout << "Enter Position K: ";
    cin >> K;

    while (T[S] != '\0')
        S++;

    while (P[R] != '\0')
        R++;

    for (i = S; i >= K - 1; i--) {
        T[i + R] = T[i];
    }

    for (i = 0; i < R; i++) {
        T[K - 1 + i] = P[i];
    }

    cout << "Result: " << T << endl;

    return 0;
}
