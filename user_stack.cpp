#include<iostream>

using namespace std;

class Stack
{
    public:
        int *arr;
        int size;
        int top;

        Stack(int size)
        {
            this->size = size;
            arr = new int[size];
            top = -1;
        }
        void push(int element)
        {
            if((size-top)>1)
            {
                top++;
                arr[top] = element;
            }
            else
            {
                cout<<"Stack Overflow";
            }
        }

        void pop()
        {
            if(top >=0 )
            {
                top--;
            }
            else
            {
                cout<<"STACK OVERFLOW";
            }
        }

        int peek()
        {
            if(top >=0 && top < size)
            {
                return arr[top];
            }
            else
            {
                cout<<"STACK IS EMPTY"<<endl;
                return -1;
            }
        }

        bool isempty()
        {
            if(top == -1)
            {
                cout<<"STACK IS EMPTY"<<endl;
                return true;
            }
            else
            {
                cout<<"STACK IS NOT EMPTY"<<endl;
                return false;
            }
        }
};

int main()
{
    Stack s1(5);
    s1.push(5);
    s1.push(4);
    s1.push(3);
    s1.push(2);
    s1.push(1);
    cout<<"top of the stack "<<s1.peek()<<endl;
    s1.pop();
    cout<<"top of the stack "<<s1.peek()<<endl;
    s1.isempty();
}