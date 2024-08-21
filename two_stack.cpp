#include<iostream>

using namespace std;

class stack
{
    public:
        int size;
        int *arr;
        int top1;
        int top2;
        stack(int size)
        {
            this -> size = size;
            arr = new int[size];
            top1 = -1;
            top2 = size;
        }

        void push1(int element)
        {
            if((top2-top1)>1)
            {
                top1++;
                arr[top1] = element;
                return;
            }
            cout<<"STACK OVERFLOW"<<endl;
        }

        void push2(int element)
        {
            if((top2-top1)>1)
            {
            top2--;
            arr[top2] = element;
            return;
            }
            cout<<"STACK OVERFLOW"<<endl;
        }

        void pop1()
        {
            if(top1 >= 0)
            {
                top1--;
                return;
            }
            cout<<"STACK UNDERFLOW"<<endl;
        }

        void pop2()
        {
            if(top2 < size)
            {
                top2++;
                return;
            }
            cout<<"STACK UNDERFLOW"<<endl;
        }

        int peek1()
        {
            if(top1 >= 0 && top1 < top2)
            {
                return arr[top1];
            }
            cout<<"STACK IS EMPTY"<<endl;
            return -1;
        }

        int peek2()
        {
            if(top2 >= top1 && top2 < size)
            {
                return arr[top2];
            }
            cout<<"STACK IS EMPTY"<<endl;
            return -1;
        }

        bool isempty1()
        {
            if(top1 == -1)
            {
                cout<<"STACK 1 IS EMPTY"<<endl;
                return true;
            }
            cout<<"STACK 1 IS NOT EMPTY"<<endl;
            return false;
        }

        bool isempty2()
        {
            if(top2 == size)
            {
                cout<<"STACK 2 IS EMPTY"<<endl;
                return true;
            }
            cout<<"STACK 2 IS NOT EMPTY"<<endl;
            return false;
        }
};

int main()
{
    stack s1(8);
    s1.push1(1);
    s1.push1(2);
    s1.push1(3);
    s1.push1(4);

    s1.push2(5);
    s1.push2(6);
    s1.push2(7);
    s1.push2(8);

    cout<<"TOP OF THE STACK1 IS : "<<s1.peek1()<<endl;
    cout<<"TOP OF THE STACK1 IS : "<<s1.peek2()<<endl;

    s1.pop1();
    s1.pop2();

    cout<<"TOP OF THE STACK1 IS : "<<s1.peek1()<<endl;
    cout<<"TOP OF THE STACK1 IS : "<<s1.peek2()<<endl;

    s1.pop1();
    s1.pop2();
    s1.pop1();
    s1.pop2();


    s1.isempty1();
    s1.isempty2();

    return 0;
}