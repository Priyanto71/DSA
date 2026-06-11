#include<iostream>
using namespace std;
int main(){
    int m,n,o;
    cout<<"Enter the number of rows: ";
    cin>>m;
    cout<<"Enter the number of columns: ";
    cin>>n;
    cout<<"Enter the number of layers: ";
    cin>>o;
    static int arr[100][100][100];
    cout<<"Enter the elements of the array: ";
    for(int i=0; i<m; i++){
        for(int j = 0; j<n;j++){
            for(int k = 0; k<o; k++){
                cin>>arr[i][j][k];
            }
        }
    }
    cout<<"The elements of the array are: "<<endl;
    for(int i=0; i<m; i++){
        for(int j = 0; j<n;j++){
            for(int k = 0; k<o; k++){
                cout<<arr[i][j][k]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
    }
}
