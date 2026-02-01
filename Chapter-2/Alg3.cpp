#include<iostream>
using namespace std;
int main(){
    int N;
    cout << "Enter Size: ";
    cin >> N;
    int DATA[N];
    int K = 1;          
    int LOC = 1;        
    cout << "Values: ";
    for(int i=0;i<N;i++){
        cin >> DATA[i];     
    }
    int MAX = DATA[0];      
    while(K<N){            
        if(MAX<DATA[K]){    
            LOC = K+1;
            MAX = DATA[K];
        }
        K++;
    }
    cout << LOC << " : " << MAX << endl;    
}