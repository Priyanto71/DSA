#include<iostream>
using namespace std;
int main(){
    int N;
    cout << "Enter Size: ";
    cin >> N;
    int DATA[N];
    int K = 0;          
    int LOC = 0;        
    cout << "Values: ";
    for(int i=0;i<N;i++){
        cin >> DATA[i];     
    }
    int MAX = DATA[0];      
    for(K=1;K<N;K++){       
        if(MAX<DATA[K]){    
            LOC = K+1;
            MAX = DATA[K];
        }
    }
    cout << LOC << " : " << MAX << endl;    
}