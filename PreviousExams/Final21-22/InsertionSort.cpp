#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter the number of elements: ";
    cin>>n;
    int arr[100];
    cout<<"Enter the elements: ";
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    cout<<"\nBefore sorting: ";
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    for(int i = 1; i < n; i++){
        int key = arr[i];
        int j = i - 1;
        while(j >= 0 && arr[j] > key){
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
        for(int x = 0; x<n; x++){
                cout<<arr[x]<<" ";
            }            
            cout<<endl;
    }
    cout<<"\nAfter sorting: ";
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}