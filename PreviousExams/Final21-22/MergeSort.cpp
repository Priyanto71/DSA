#include<iostream>
using namespace std;

void Merge(int arr[], int left, int mid, int right){
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int leftArr[n1], rightArr[n2];
    for(int i = 0; i < n1; i++){
        leftArr[i] = arr[left + i];
    }
    for(int j = 0; j < n2; j++){
        rightArr[j] = arr[mid + j + 1];
    }
    int i = 0, j = 0, k = left;
    while(i<n1 && j<n2){
        if(leftArr[i] <= rightArr[j]){
            arr[k] = leftArr[i];
            i++;
        }else{
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }
    while(i<n1){
        arr[k] = leftArr[i];
        i++;
        k++;
    }
    while(j<n2){
        arr[k] = rightArr[j];
        j++;
        k++;
    }
    cout << endl;
    for(int x = left; x<=right; x++){
        cout<<arr[x]<<" ";
    }
}

void MergeSort(int arr[], int left, int right){
    if(left >= right){
        return;
    }
    int mid = left + (right - left) / 2;
    MergeSort(arr, left, mid);
    MergeSort(arr, mid + 1, right);
    Merge(arr, left, mid, right);
}

int main(){
    int n;
    cout<<"Enter the number of elements: ";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements: ";
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    cout<<"\nBefore sorting: ";
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    //Merge Sort
    MergeSort(arr, 0, n-1);
    cout<<"\nAfter Merge sorting: ";
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}