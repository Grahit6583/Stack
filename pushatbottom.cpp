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

void solve(Stack &s , int x)
{
    if(s.isempty())
    {
        s.push(x);
        return;
    }
    int num = s.peek();
    s.pop();
    solve(s,x);
    s.push(num);
}

Stack pushbottom(Stack &s,int x)
{
    solve(s,x);
    return s;
}

int main()
{
    int size = 10;
    Stack s(size),s1(size);
    s.push(5);
    s.push(4);
    s.push(3);
    s.push(2);
    s.push(1);
    s.display();
    s1 = pushbottom(s,0);
    s1.display();
}