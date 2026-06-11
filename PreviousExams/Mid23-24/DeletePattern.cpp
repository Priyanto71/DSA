#include<iostream>
using namespace std;

int main(){
    char T[100], P[50];
    cout<<"Enter the text: ";
    cin.getline(T, 100);
    cout<<"Enter the pattern to delete: ";
    cin.getline(P, 50);
    int lenT = 0, lenP = 0;
    for(int i = 0; T[i] != '\0'; i++){
        lenT++;
    }
    for(int i = 0; P[i] != '\0'; i++){
        lenP++;
    }
    for(int i = 0; i <= lenT - lenP; ){
        int j;
        for(j = 0; j < lenP; j++){
            if(T[i + j] != P[j]){
                break;
            }
        }
        if(j == lenP){
            for(int k = i; k <= lenT - lenP; k++){
                T[k] = T[k + lenP];
            }
            lenT -= lenP;
            i--;
        }else{
            i++;
        }
    }
    cout<<"Text after deleting the pattern: "<<T<<endl;
    return 0;
}