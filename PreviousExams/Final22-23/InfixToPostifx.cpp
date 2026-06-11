#include<iostream>
using namespace std;

char stackArr[100];
int top=-1;

void push(char x)
{
    stackArr[++top]=x;
}

char pop()
{
    return stackArr[top--];
}

char peek()
{
    return stackArr[top];
}

int priority(char op)
{
    if(op=='^') return 3;
    if(op=='*' || op=='/') return 2;
    if(op=='+' || op=='-') return 1;
    return 0;
}

int main()
{
    char infix[100];

    cin>>infix;

    char postfix[100];

    int k=0;

    for(int i=0;infix[i]!='\0';i++)
    {
        char ch=infix[i];

        if((ch>='A'&&ch<='Z')||(ch>='a'&&ch<='z'))
            postfix[k++]=ch;

        else if(ch=='(')
            push(ch);

        else if(ch==')')
        {
            while(peek()!='(')
                postfix[k++]=pop();

            pop();
        }

        else
        {
            while(top!=-1 &&
                  priority(peek())>=priority(ch))
                postfix[k++]=pop();

            push(ch);
        }
    }

    while(top!=-1)
        postfix[k++]=pop();

    postfix[k]='\0';

    cout<<postfix;

    return 0;
}