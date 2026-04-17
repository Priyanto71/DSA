#include<iostream>
using namespace std;
int main(){
    int A[3][3] = {1,2,3, 4,5,6, 7,8,9};
    int B[3][3] = {4,5,6, 7,8,9, 1,2,3};
    int C[3][3];
    int M = 3;
    int P = 3;
    int N = 3;
    int I = 0;
    cout << "Matrix A: " << endl;
    for(int a = 0; a < M; a++){
        for(int b = 0; b < N; b++){
            cout << A[a][b] << " ";
        }
        cout << endl;
    }
    cout << "Matrix B: " << endl;
    for(int a = 0; a < M; a++){
        for(int b = 0; b < N; b++){
            cout << B[a][b] << " ";
        }
        cout << endl;
    }
    cout << "Matrix C = A * B: " << endl;
    while(I < M){
            int J = 0;
        while(J < N){
            C[I][J] = 0;
                int K = 0;
            while(K < P){
                C[I][J] = C[I][J] + A[I][K] * B[K][J];
                K = K + 1;
            }
            J = J + 1;
        }
        I = I + 1;
    }
    for(int a = 0; a < M; a++){
        for(int b = 0; b < N; b++){
            cout << C[a][b] << " ";
        }
        cout << endl;
    }
}