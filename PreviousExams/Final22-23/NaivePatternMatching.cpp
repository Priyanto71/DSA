#include<iostream>
using namespace std;
int main(){
    char T[100], P[50];
    cout<<"Enter the text: ";
    cin.getline(T,100);
    cout<<"Enter the pattern: ";
    cin.getline(P,50);
    int lenT = 0, lenP = 0;
    while(T[lenT] != '\0'){
        lenT++;
    }
    while(P[lenP] != '\0'){
        lenP++;
    }
    cout<<"The pattern is found at indices: ";
    for(int i = 0; i <= lenT - lenP; i++){
        int j;
        for(j = 0; j < lenP; j++){
            if(T[i+j] != P[j]){
                break;
            }
        }
        if(j == lenP){
            cout<<i+1<<" ";
        }
    }
}