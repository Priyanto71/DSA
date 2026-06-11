#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter the size of the array: ";
    cin>>n;
    int arr[100];
    cout<<"Enter the elements of the sorted array: ";
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    int key;
    cout<<"Enter the element to be searched: ";
    cin>>key;
    int low = 0, high = n-1, mid;
    bool found = false;
    while(low <= high){
        mid = low + (high - low) / 2;
        if(arr[mid] == key){
            found = true;
            break;
        }
        else if(arr[mid] < key){
            low  = mid + 1;
        }else{
            high = mid - 1;
        }
    }
    if(found){
        cout<<"Element "<<key<<" found at position "<<mid+1<<endl;
    }else{
        cout<<"Element "<<key<<" not found in the array."<<endl;
    }

}