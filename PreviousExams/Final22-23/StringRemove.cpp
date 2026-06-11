#include<iostream>
using namespace std;
int main(){
    string A[10] = {"BBBB", "DDDD", "MMMM", "XXXX"};
    int n = 4;
    string item = "MMMM";
    cout<<"Before Removing the element: ";
    for(int i = 0; i<n; i++){
        cout<<A[i]<< " ";
    }
    cout<<endl;
    int pos = -1;
    for(int i = 0; i<n; i++){
        if(A[i] == item){
            pos = i;
            break;
        }
    }
    if(pos!=-1){
        for(int i = pos; i < n-1; i++){
            A[i] = A[i+1];
        }
        n--;
    }
    cout<<"The elements of the array are: "<<endl;
    for(int i = 0; i < n;i++){
        cout<<A[i]<<" ";
    }
}