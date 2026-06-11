#include<iostream>
using namespace std;
void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}
void printArray(int arr[], int n){
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int partition(int arr[], int low, int high, int n, int pivotChoice){
    int pivotIndex;
    if(pivotChoice == 1){
        pivotIndex = low;
    }else if(pivotChoice == 2){
        pivotIndex = high;
    }else{
        pivotIndex = low + (high - low) / 2;
    }
    swap(arr[pivotIndex], arr[high]);
    int pivot = arr[high];
    cout <<"Pivot Element: " << pivot << endl;
    int i = low - 1;
    for(int j = low; j < high; j++){
        if(arr[j] < pivot){
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[high]);
    cout<<"Array after partitioning: ";
    printArray(arr, n);
    return i + 1;

}
void quickSort(int arr[], int low, int high, int n, int choice){
    if(low < high){
        int pi = partition(arr, low, high, n, choice);
        quickSort(arr, low, pi - 1, n, choice);
        quickSort(arr, pi + 1, high, n, choice);
    }
}
int main(){
    int n;
    cout<<"Enter the number of elements: ";
    cin>>n;
    int arr[100];
    cout<<"Enter the elements of the array: ";
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    int choice;
    cout<<"Choose the pivot element: "<<endl;
    cout<<"1. First element"<<endl;
    cout<<"2. Last element"<<endl;
    cout<<"3. Middle element"<<endl;
    cin>>choice;
    cout<<"Initial array: ";
    printArray(arr, n);
    quickSort(arr, 0, n-1, n, choice);
    cout<<"Sorted array: ";
    printArray(arr, n);
    return 0;
}