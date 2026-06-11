#include<iostream>
using namespace std;
int main(){
    char T[100], P[50];
    cout<<"Enter the text: ";
    cin.getline(T, 100);
    cout<<"Enter the pattern to search: ";
    cin.getline(P, 50);
    int lenT = 0, lenP = 0;
    for(int i = 0; T[i] != '\0'; i++){
        lenT++;
    }
    for(int i = 0; P[i] != '\0'; i++){
        lenP++;
    }
    int found = -1;
    for(int i = 0; i <= lenT-lenP; i++){
        int j;
        for(j = 0; j < lenP; j++){
            if(T[i+j] != P[j]){
                break;
            }
        }
        if(j == lenP){
            found = i;
            break;
        }
    }
    if(found != -1){
        cout<<"Pattern found at index: "<< found << endl;
    }else{
        cout<<"Pattern not found."<< endl;
    }
}