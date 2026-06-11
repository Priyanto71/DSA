#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter the size of the array: ";
    cin>>n;
    int arr[100];
    cout<<"Enter the elements of the array: ";
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n-i-1; j++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
        cout<<"The array after pass "<<i+1<<" is: ";
        for(int k=0; k<n; k++){
            cout<<arr[k]<<" ";
        }
        cout<<endl;
    }
    cout<<"The sorted array is: ";
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
}