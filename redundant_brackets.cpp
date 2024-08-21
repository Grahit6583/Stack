#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Stack
{
    private:
        char *arr;
        int top;
        int size;

    public:
        Stack(int size)
        {
            arr = new char[size];
            top = -1;
            this->size = size;
        }

        void push(char ch)
        {
            if((size-top) > 1)
            {
                top++;
                arr[top] = ch;
            }
            else
            {
                cout<<"Stack  overflow"<<endl;
            }
        }

        void pop()
        {
            if(top >= 0)
            {
                top--;
                return ;
            }
            else
            {
                cout<<"Stack underflow"<<endl;
            }
        }

        char peek()
        {
            if(top >= 0)
            {
                return arr[top];
            }
            else
            {
                cout<<"Stack is empty"<<endl;
            }
        }
};

bool isredundant(string &s1)
{
    Stack s(s1.length());
    for(int i =0 ; i<=s1.length();i++)
    {
        char ch = s1[i];
        if(ch == '(' || ch == '+' || ch == '-' || ch == '/' || ch == '*')
        {
            s.push(ch);
        }
        else
        {
            if(ch == ')')
            {
                bool isredundant = true;
                while(s.peek() != '(')
                {
                    char ch1 = s.peek();
                    if(ch1 == '+' || ch1 == '-' || ch1 == '/' || ch1 == '*')
                    {
                        isredundant = false;
                    }
                    s.pop();
                }
                if(isredundant == true)
                {
                    return true;
                }
                s.pop();
            }
        }
    }
    return false;
}

int main()
{

    string s1 = "()";

    if(isredundant(s1))
    {
        cout<<"STRING IS REDUNDANT"<<endl;
    }
    else
    {
        cout<<"STRING IS NOT REDUNDANT"<<endl;
    }
}