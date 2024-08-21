#include<bits/stdc++.h>

using namespace std;

class Nstack
{
    private:
        int *arr;
        int *top;
        int *next;

        int n,s;
        int freespot;
    public:
        Nstack(int N , int S)
        {
            n = N;
            s = S;
            arr = new int[s];
            top = new int[n];
            next = new int[s];

            for(int i =0 ;i<n ;i++)
            {
                top[i] = -1;
            }

            for(int i = 0 ;i<s ;i++)
            {
                next[i] = i+1;
            }
            next[s-1] = -1;

            freespot = 0;
        }

        bool push(int x , int m)
        {
            if(freespot == -1)
            {
                cout<<"STACK OVERFLOW"<<endl;
                return false;
            }

            //find index
            int index = freespot;

            //freespot update
            freespot = next[index];

            //push element
            arr[index] = x;

            //update next
            next[index] = top[m-1];

            //update top
            top[m-1] = index;

            return true;
        }

        int pop(int m)
        {
            if(top[m-1] == -1)
            {
                return -1;
            }

            int index = top[m-1];

            top[m-1] = next[index];

            next[index] = freespot;

            freespot = index;

            return arr[index];
        }
};

int main()
{
    Nstack s(3,6);
    cout<<s.pop(1)<<endl;
    cout<<s.pop(2)<<endl;
    cout<<s.pop(2)<<endl;

}