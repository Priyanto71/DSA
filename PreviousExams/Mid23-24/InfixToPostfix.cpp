#include<iostream>
using namespace std;
char stackArr[100];
int top = -1;
void push(char x){
    stackArr[++top] = x;
}
char pop(){
    char x = stackArr[top];
    top--;
    return x;
}
char peek(){
    return stackArr[top];
}
int precedence(char op){
    if(op == '+' || op == '-'){
        return 1;
    }else if(op == '*' || op == '/'){
        return 2;
    }else if(op == '^'){
        return 3;
    }else {
        return 0;
    }
}
int main(){
    char infix[100];
    char postfix[100];
    cout<<"Enter the infix expression: ";
    cin>>infix;
    int k = 0;
    for(int i = 0; infix[i] != '\0'; i++){
        char ch = infix[i];
        if((ch >='a' && ch <= 'z') ||
           (ch >='A' && ch <= 'Z') ||
           (ch >='0' && ch <= '9')){
            postfix[k++] = ch;
        }
        else if(ch == '('){
            push(ch);
        }
        else if(ch == ')'){
            while(top!=-1 && peek() != '('){
                postfix[k++] = pop();
            }
            pop();
        }
        else{
            while(top!=-1 && precedence(peek()) >= precedence(ch)){
                postfix[k++] = pop();
            }
            push(ch);
        }
        
    }
    while(top!=-1){
        postfix[k++] = pop();
    }
    postfix[k] = '\0';
    cout<<"The postfix expression is: "<<postfix<<endl;
    return 0;
}