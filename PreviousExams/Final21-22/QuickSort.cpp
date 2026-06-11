#include<iostream>
using namespace std;

void QuickSort(int arr[], int low, int high, int n){
    if(low >= high){
        return;
    }

    int pivot = arr[high];
    int i = low - 1;

    for(int j = low; j < high; j++){
        if(arr[j] < pivot){
            i++;
            swap(arr[i], arr[j]);
            cout << "Pivot " << pivot << " placed: ";
            for(int x = 0; x < n; x++){
                cout << arr[x] << " ";
            }
            cout << endl;
        }
    }

    swap(arr[i + 1], arr[high]);

    int p = i + 1;   // Pivot index

    QuickSort(arr, low, p - 1, n);
    QuickSort(arr, p + 1, high, n);
}

int main(){
    int n;

    cout << "Enter the number of elements: ";
    cin >> n;

    int arr[n];

    cout << "Enter the elements: ";
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    cout << "\nBefore sorting: ";
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }

    cout << endl;

    QuickSort(arr, 0, n - 1, n);

    cout << "\nAfter sorting: ";
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }

    return 0;
}