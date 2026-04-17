#include<iostream>
using namespace std;
int main(){
    int LA[] = {1,2,3,4,5,6,7,8,9,10};
    int K = 4;
    int ITEM = LA[K];
    int J = K;
    int N = 10;
    cout << "Before Deleting:" << endl;
    for(int i = 0; i < N; i++){
        cout << LA[i] << " ";
    }
     cout << endl << "After Deleting:" << endl;
    while(J <= N - 1){
        int temp = LA[J];
        LA[J] = LA[J + 1];
        LA[J + 1] = temp;
        J = J + 1;
    }
    N = N - 1;
    for(int i = 0; i < N ; i++){
        cout << LA[i] << " ";
    }
}