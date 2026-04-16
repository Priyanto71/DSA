#include<iostream>
using namespace std;
//Pattern Matching
int INDEX(char T[], char P[]){
    for(int i = 0; T[i] != '\0'; i++){
        int j = 0;
        while(P[j] != '\0' && T[i+j] == P[j]){
            j++;
        }
        if(P[j] == '\0'){
            return i;
        }
    }
    return -1;
}
//Pattern Replacement
void REPLACE(char T[], char P[], char Q[], int K){
    int Tsize = 0;
    int Psize = 0;
    int Qsize = 0;
    while(T[Tsize] != '\0'){
        Tsize++;
    }
    while(P[Psize] != '\0'){
        Psize++;
    }
    while(Q[Qsize] != '\0'){
        Qsize++;
    }
    char temp[200];
    //Copying the text before the pattern
    int i = 0, j = 0, k = 0;
    while(i < K){
        temp[k++] = T[i++];
    }
    //Copying the replacement pattern
    for(j = 0; j < Qsize; j++){
        temp[k++] = Q[j];
    }
    i = K + Psize;
    //Copying the text after the pattern
    while(T[i] != '\0'){
        temp[k++] = T[i++];
    }
    temp[k] = '\0';
    i = 0;
    //Copying the modified text back to T
    while(temp[i] != '\0'){
        T[i] = temp[i];
        i++;
    }
    T[i] = '\0';
}

int main(){
    cout << "Enter Text: ";
    char T[100];
    cin.getline(T,100);
    cout << "Enter Pattern: ";
    char P[100];
    cin.getline(P,100);
    cout << "Pattern to be replaced: ";
    char Q[100];
    cin.getline(Q,100);
    
    int K = INDEX(T,P);
    while(K != -1){
        REPLACE(T, P, Q, K);
        K = INDEX(T,P);
    }
    cout << "Text after replacement: " << T;
    return 0;
}