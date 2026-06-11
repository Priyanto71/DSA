#include<iostream>
using namespace std;

int main(){
    char T[100], P[50], R[50], N[100];
    cout<<"Enter the text: ";
    cin.getline(T, 100);
    cout<<"Enter the pattern to Replace: ";
    cin.getline(P, 50);
    cout<<"Enter the replacement pattern: ";
    cin.getline(R, 50);
    int lenT = 0, lenP = 0, lenR = 0;
    for(int i = 0; T[i] != '\0'; i++){
        lenT++;
    }
    for(int i = 0; P[i] != '\0'; i++){
        lenP++;
    }
    for(int i = 0; R[i] != '\0'; i++){
        lenR++;
    }
    int i = 0, k = 0;
    while(i < lenT){
        int match = 1;
        if(i <= lenT - lenP){
            for(int j = 0; j < lenP; j++){
                if(T[i + j] != P[j]){
                    match = 0;
                    break;
                }
            }
        }else{
            match = 0;
        }
        if(match){
            for(int j = 0; j < lenR; j++){
                N[k++] = R[j];
                i += lenP;
            }
        }else{
            N[k++] = T[i++];
        }

    }
    N[k] = '\0';
    cout<<"Text after replacing the pattern: "<< N <<endl;

}