#include<iostream>
using namespace std;
int main(){
    int DATA[10] = {1,3,2,7,4,10,6,8,9};
    int N = 9;
    int ITEM = 5;
    DATA[N + 1] = ITEM;
    int LOC = 0;
    cout << "Array:" << endl;
    for(int i = 0; i < N; i++){
        cout << DATA[i] << " ";
    }
    cout << endl << "ITEM: " << ITEM << endl;
    while(DATA[LOC] != ITEM){
        LOC = LOC + 1;
    }
    if(LOC == N + 1){
        LOC = -1;
    }
    if(LOC == -1){
        cout << "ITEM Not Found" << endl;
    }else{
        cout << "ITEM Found at Index " << LOC + 1 << endl;
    }
}