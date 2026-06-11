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
    int item, pos;
    cout<<"Enter the element to be inserted: ";
    cin>>item;
    cout<<"Enter the position to insert the element: ";
    cin>>pos;
    for(int i = n; i >= pos; i--){
        arr[i] = arr[i-1];
    }
    arr[pos-1] = item;
    cout<<"Array after insertion: ";
    for(int i = 0; i <= n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}