#include<iostream>
using namespace std;
int main(){
    int DATA[] = {1,2,3,4,5,6,7,8,9,10};
    int LB = 0;
    int UB = 10;
    int ITEM = 5;
    int BEG = LB;
    int END = UB;
    int MID = int ((BEG + END) / 2);
    cout << "Array:" << endl;
    for(int i = 0; i < UB; i++){
        cout << DATA[i] << " ";
    }
    cout << endl << "ITEM: " << ITEM << endl;
    while(BEG <= END && DATA[MID] != ITEM){
        if(ITEM < DATA[MID]){
            END = MID - 1;
        }else{
            BEG = MID + 1;
        }
        MID = int ((BEG + END) / 2);
    }
    int LOC;
    if(DATA[MID] == ITEM){
        LOC = MID;
    }else{
        LOC = -1;
    }
    if(LOC == -1){
        cout << "ITEM Not Found" << endl;
    }else{
        cout << "ITEM Found at Index " << LOC + 1 << endl;
    }
}