#include<iostream>
using namespace std;
int main(){
    int N;
    cout << "Enter Size: ";
    cin >> N;
    int DATA[N];
    cout << "Values: ";
    for(int i = 0;i<N;i++){
        cin >> DATA[i];
    }
    int K = 0;
    int LOC = -1;
    int ITEM;
    cout << "Enter Item to find: ";
    cin >> ITEM;
    while(LOC == -1 && K<N){
        if(ITEM == DATA[K]){
            LOC = K+1;
        }
        K++;
    }
    if(LOC == -1){
        cout << "ITEM is not in the array DATA";
    }else{
        cout << LOC << " is the location of " <<ITEM;
    }
}