#include<bits/stdc++.h>

using namespace std;

class Stack
{
    private:
        int *arr;
        int top;
        int size;
    public:
        Stack(int size)
        {
            this->size = size;
            arr = new int[size];
            top = -1;
        }
        bool isempty()
        {
            return top == -1;
        }

        void push(int data)
        {
            if((size-top)>1)
            {
                top++;
                arr[top]=data;
            }
            else
            {
                cout<<"Stack Overflow"<<endl;
            }
        }

        int pop()
        {
            if(top>=0)
            {
                top--;
                return arr[top];
                cout<<"Stack Underflow"<<endl;
                return -1;
            }
            else
            {
                cout<<"Stack Underflow"<<endl;
            }
        }
        int peek()
        {
            return arr[top];
        }
        void display()
        {
            for(int i = 0; i <= top; ++i)
            {
                cout<<arr[i]<<"  ";
            }
            cout<<endl;
        }
};

void sorting(Stack &s1,int num)
{
    if(s1.isempty() || (!s1.isempty() && s1.peek() < num))
    {
        s1.push(num);
        return;
    }

    int x = s1.peek();
    s1.pop();
    sorting(s1,num);
    s1.push(x);
}

void sortstack(Stack &s1)
{
    if(s1.isempty())
    {
        return;
    }
    int num = s1.peek();
    s1.pop();
    sortstack(s1);
    sorting(s1,num);
}

int main()
{
    int size =5;
    Stack s1(size);
    s1.push(2);
    s1.push(5);
    s1.push(1);
    s1.push(4);
    s1.push(3);
    s1.display();
    sortstack(s1);
    s1.display();
}