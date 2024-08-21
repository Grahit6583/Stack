#include<bits/stdc++.h>
#include<limits.h>
using namespace std;

class special_stack
{
    private:
        stack<int> s;
        int mini = INT_MAX;
    public:
        void push(int data)
        {
            if(s.empty())
            {
                s.push(data);
                mini = data;
            }
            else
            {
                if(data < mini)
                {
                    s.push(2*data - mini);
                    mini = data;
                }
                else
                {
                    s.push(data);
                }
            }
        }

        int pop()
        {
            if(s.empty())
            {
                return -1;
            }
            int curr = s.top();
            s.pop();
            if(curr > mini)
            {
                return curr;
            }
            else
            {
                int prevmin = mini;
                int val  = 2*mini - curr;
                mini = val;
                return prevmin;
            }
        }

        int top()
        {
            if(s.empty())
            {
                return -1;
            }

            int curr = s.top();
            if(curr < mini)
            {
                return mini;
            }
            else
            {
                return curr;
            }
        }

        bool isempty()
        {
            return s.empty();
        }

        int getmin()
        {
            if(s.empty())
            {
                return -1;
            }

            return mini;
          }
};

int main()
{
    special_stack s;
    s.push(13);
    s.push(47);
    // s.push(8);
    // s.push(2);

    cout<<s.top()<<endl;
    s.push(8);
    cout<<s.pop()<<endl;
    cout<<s.getmin()<<endl;

    return 0;
}