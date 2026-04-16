#include<iostream>
using namespace std;
//Patern Matching
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
//Pattern Deletion
void DELETE(char T[], int K, int Psize){
    int i = K;
    while(T[i+Psize] != '\0'){
        T[i] = T[i+Psize];
        i++;
    }
    T[i] = '\0';
}
int main(){
    cout << "Enter Text: ";
    char T[100];
    cin.getline(T,100);
    cout << "Pattern to be deleted: ";
    char P[100];
    cin.getline(P,100);
    int Tsize = 0;
    int Psize = 0;
    while(T[Tsize] != '\0'){
        Tsize++;
    }
    while(P[Psize] != '\0'){
        Psize++;
    }
    int K = INDEX(T,P);
    while(K != -1){
        DELETE(T, K, Psize);
        K = INDEX(T,P);
    }
    cout << "Text after deletion: " << T;
    return 0;
}