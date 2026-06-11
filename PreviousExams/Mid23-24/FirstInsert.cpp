#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter the size of the array: ";
    cin>>n;
    int arr[100];
    cout<<"Enter the elements of the array: ";
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }
    int item;
    cout<<"Enter the element to be inserted: ";
    cin>>item;
    for(int i = n; i > 0; i--){
        arr[i] = arr[i-1];
    }
    arr[0] = item;
    cout<<"Array after insertion: ";
    for(int i = 0; i <= n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}