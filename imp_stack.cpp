#include<iostream>
#include<stack>

using namespace std;

int main()
{
    stack<int> stk;
    stk.push(5);
    stk.push(4);
    stk.push(3);
    stk.push(2);
    stk.pop();
    stk.pop();
    cout<<"top of the stack "<<stk.top()<<endl;
    cout<<"check list is empty "<<stk.empty()<<endl;
    cout<<"Size of the stack : "<<stk.size()<<endl;
    return 0;
}