#include<iostream>
using namespace std;
int main(){
    string A[10] = {"BBBB", "DDDD", "MMMM", "XXXX"};
    int n = 4;
    string item = "FFFF";
    int pos = 0;
    cout<<"Before Adding new elements: ";
    for(int i = 0; i<n; i++){
        cout<<A[i]<< " ";
    }
    cout<<endl;
    while(pos<n && A[pos] < item){
        pos++;
    }
    for(int i = n; i > pos; i--){
        A[i] = A[i-1];
    }
    A[pos] = item;
    n++;
    item = "ZZZZ";
    pos = 0;
    while(pos<n && A[pos] < item){
        pos++;
    }
    for(int i = n; i > pos; i--){
        A[i] = A[i-1];
    }
    A[pos] = item;
    n++;
    cout<<"The elements of the array are: "<<endl;
    for(int i = 0; i < n;i++){
        cout<<A[i]<<" ";
    }
    cout<<endl;

}