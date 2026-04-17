#include<iostream>
using namespace std;
int main(){
    int DATA[] = {1,4,2,5,3,10,6,8,7,9};
    int N = 10;
    int K = 0;
    cout << "Before Sorting:" << endl;
    for(int i = 0; i < N; i++){
        cout << DATA[i] << " ";
    }
    cout << endl << "After Sorting:" << endl;
    while(K < N - 1){
        int PTR = 0;
        while(PTR < N - K - 1){
            if(DATA[PTR] > DATA[PTR + 1]){
                int temp = DATA[PTR];
                DATA[PTR] = DATA[PTR + 1];
                DATA[PTR + 1] = temp;
            }
            PTR = PTR + 1;
        }
        K = K + 1;
    }
    for(int i = 0; i < N; i++){
        cout << DATA[i] << " ";
    }
}