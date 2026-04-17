#include<iostream>
using namespace std;
int main(){
    int LA[10] = {1,2,3,4,6,7,8,9,10};
    int ITEM = 5;
    int N = 10;
    int J = N;
    int K = 4;
    cout << "Before Inserting:" << endl;
    for(int i = 0; i < N - 1; i++){
        cout << LA[i] << " ";
    }
     cout << endl << "After Inserting:" << endl;
    while(J >= K){
        int temp = LA[J + 1];
        LA[J + 1] = LA[J];
        LA[J] = temp;
        J = J - 1;
    }
    LA[K] = ITEM;
    N = N + 1;
    for(int i = 0; i < N - 1; i++){
        cout << LA[i] << " ";
    }
}