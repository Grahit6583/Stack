#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class node
{
    public:

        int data;
        node *next;

        node(int data) : data(data),next(nullptr){}
};

class Stack
{
    private:
        node *top;
    public:
        Stack() : top(nullptr) {}
        bool isempty()
        {
            return top == nullptr;
        }

        void push(int data)
        {
            node *newnode = new node(data);
            newnode->data = data;
            newnode->next = top;
            top = newnode;
        }

        void pop()
        {
            if(isempty())
            {
                cout<<"Stack Underflow"<<endl;
                return;
            }
            node *temp = top;
            int poppedData = temp->data;
            top = top->next;
            delete temp;
            cout<<"Popped Data is : "<<poppedData<<endl;
        }

        int peek()
        {
            if(isempty())
            {
                cout<<"Stack is empty"<<endl;
                return -1;
            }
            return top->data;
        }

        void display()
        {
            if(isempty())
            {
                cout<<"Stack is empty "<<endl;
                return;
            }
            node *temp = top;
            while(temp != NULL)
            {
                cout<<temp->data<<" -> ";
                temp=temp->next;
            }
            cout<<"NULL"<<endl;
        }
};

int main()
{
    Stack s1;
    s1.push(12);
    s1.push(13);
    s1.push(14);
    s1.push(15);
    s1.push(16);
    s1.push(17);
    s1.display();
    s1.pop();
    s1.pop();
    s1.pop();
    cout<<s1.peek()<<endl;
    s1.display();
    s1.pop();
    s1.pop();
    s1.pop();
    s1.pop();
    cout<<s1.peek()<<endl;
    s1.display();
}