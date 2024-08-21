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
            this->size = size;
            arr = new char[size];
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
        char pop()
        {
            if(top >= 0)
            {
                return arr[top--];
            }
            else{
                cout<<"Stack Underflow"<<endl;
            }
        }
        char peek()
        {
            if(top>=0 && top<size)
            {
                return arr[top];
            }
            else
            {
                cout<<"Stack is empty"<<endl;
            }
        }
};
unordered_map<char,int> precedence =
{
    {'-',1},{'+',1},{'*',2},{'/',2}
};
bool parenthesis_match(string str)
{
    Stack s1(str.length());
    for(char c : str)
    {
        if(c=='(' || c=='{' || c=='[')
        {
            s1.push(c);
        }
        else if(c==')' || c=='}' || c==']')
        {
            if(s1.isempty())
            {
                return false;
            }
            int top = s1.pop();
            if ((c == ')' && top != '(') ||
                (c == ']' && top != '[') ||
                (c == '}' && top != '{'))
            {
                return false;
            }
        }
    }
    return s1.isempty();
}
string InfixToPostfix(string &str)
{
    Stack s1(str.length());
    string postfix;
    if(parenthesis_match(str))
    {
    for(char c : str)
    {
        if(isalnum(c))
        {
            postfix += c;
        }
        else if(c == '(')
        {
            s1.push(c);
        }
        else if(c == ')')
        {
            while(!s1.isempty() && s1.peek() != '(')
            {
                postfix += s1.pop();
            }
            s1.pop(); //for )
        }
        else
        {
            while(!s1.isempty() && s1.peek() != '(' && precedence[c] <= precedence[s1.peek()])
            {
                postfix += s1.pop();
            }
            s1.push(c);
        }
    }
    while(!s1.isempty())
    {
        postfix += s1.pop();
    }
    return postfix;
    }
    else
    {
       return "Expression is not balanced";
    }
}

int main()
{
    string infixExpression = "a+b*(c-d/e";
    string postfixExpression = InfixToPostfix(infixExpression);

    cout << "Infix Expression: " << infixExpression << endl;
    cout << "Postfix Expression: " << postfixExpression << endl;

    return 0;
}