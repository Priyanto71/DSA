#include<iostream>
#include<cmath>
using namespace std;
int main(){
    double A,B,C;
    cout << "A: ";
    cin >> A;
    cout << "B: ";
    cin >> B;
    cout << "C: ";
    cin >> C;
    double D = (B*B) - (4*A*C);
    if(D>0){
        double X1 = (-B+sqrt(D))/(2*A);
        double X2 = (-B-sqrt(D))/(2*A);
        cout << "Two Real Solutions: X1 = " << X1 << " and X2 = " << X2;
    }else if(D==0){
        double X = (-B)/(2*A);
        cout << "Unique Solution: X = " << X;
    }else{
        cout << "No Real Solution";
    }
}