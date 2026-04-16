#include<iostream>
using namespace std;
int main(){
    cout << "Enter Text: ";
    char T[100];
    cin.getline(T,100);
    cout << "Enter pattern: ";
    char P[100];
    cin.getline(P,100);
    int S = 0, R = 0;
    int INDEX = -1;
    while(T[S] != '\0'){
        S++;
    }
    while(P[R] != '\0'){
        R++;
    }
    int K = 0;
    int MAX = S - R;
    while(K <= MAX){
        int L;
        for(L = 0; L < R; L++){
            if(P[L] != T[K + L]){
                break;
            }
        }
        if(L == R){
            INDEX = K;
            break;
        }
        K = K + 1;
    }
    if(INDEX != -1){
        cout << "Pattern found at index: " << INDEX + 1;
    }else{
        cout << "Pattern not found in the text.";
    }
    return 0;
}