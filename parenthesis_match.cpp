#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Stack
{
    private:
        char *arr;
        int size;
        int top;
    
    public:
        Stack(int size)
        {
            this->size = size;
            arr = new char[size];
            top = -1;
        }
        void push(int data)
        {
            if((size-top)>1)
            {
                top++;
                arr[top] = data;
            }
            else
            {
                cout<<"Stack overflow"<<endl;
            }
        }

        int pop()
        {
            if(top >= 0)
            {
                return arr[top--];
            }
            else
            {
                cout<<"Stack underflow"<<endl;
                return -1;
            }
        }

        bool isempty()
        {
            return top == -1;
        }
};
bool parenthesis_match(string str)
{
    Stack s1(str.length());
    for(char c : str)
    {
        if(c=='(' || c=='{' || c=='[')
        {
            cout<<"hello"<<endl;
            s1.push(c);
        }
        else if(c==')' || c=='}' || c==']')
        {
            if(s1.isempty())
            {
                cout<<"12354"<<endl;
                return false;
            }
            int top = s1.pop();
            if ((c == ')' && top != '(') ||
                (c == ']' && top != '[') ||
                (c == '}' && top != '{'))
            {
                cout<<"world"<<endl;
                return false;
            }
        }
    }
    cout<<"my name is grahit"<<endl;
    return s1.isempty();
}
int main()
{
    string str;
    cout<<"Enter the expression : "<<endl;
    getline(cin,str);

    if (parenthesis_match(str)) {
        std::cout << "Expression  is balanced." << std::endl;
    } else {
        std::cout << "Expression  is not balanced." << std::endl;
    }
}