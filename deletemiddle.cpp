#include<iostream>

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
            top = -1;
            arr = new int[size];
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
                cout<<"Stack Overflow"<<endl;
            }
        }

        int pop()
        {
            if(top <= 0)
            {
                cout<<"Stack Underflow"<<endl;
                return -1;
            }
            else
            {
                return arr[top--];
            }
        }

        int peek()
        {
            if(top >=0)
            {
                return arr[top];
            }
            else
            {
                cout<<"Stack is empty"<<endl;
            }
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

void solve(Stack &s1,int count,int size)
{
    //base case
    if(count == size/2)
    {
        s1.pop();
        return;
    }
    int num = s1.peek();
    s1.pop();
    solve(s1,count+1,size);
    s1.push(num);
    return;
}

void deletemiddle(Stack &s1 ,int size)
{
    int count =0 ;
    solve(s1,count,size);
    return;
}

int main()
{
    int size =5;
    Stack s1(size);
    s1.push(5);
    s1.push(4);
    s1.push(3);
    s1.push(2);
    s1.push(1);
    s1.display();
    deletemiddle(s1,size);
    s1.display();
}