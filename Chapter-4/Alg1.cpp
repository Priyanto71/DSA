#include<iostream>
using namespace std;
int main(){
    int LA[] = {1,2,3,4,5,6,7,8,9,10};
    int LB = 0;
    int UB = 9;
    int K = LB;
    while(K<=UB){
        cout << LA[K] << " ";
        K = K + 1;
    }

}