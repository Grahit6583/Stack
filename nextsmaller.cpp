#include<iostream>
#include<bits/stdc++.h>

using namespace std;

vector<int> smaller_element(vector<int> &arr,int n)
{
    stack<int> s;
    s.push(-1);
    vector<int> ans(n);
    for(int i = n-1; i >= 0 ; i--)
    {
        int curr = arr[i];
        while(s.top() >= curr)
        {
            s.pop();
        }
        ans[i]=s.top();
        s.push(curr);
    }
    return ans;
}

int main()
{
    int size = 4;
    vector<int> arr(size);
    arr =  {4,2,3,1};
    for(int i =0 ; i < arr.size();i++)
    {
        cout<<arr[i]<<"    ";
    }
    cout<<endl;
    vector <int> ans = smaller_element(arr,size);
    for(int i =0 ; i < ans.size();i++)
    {
        cout<<ans[i]<<"    ";
    }
    return 0;

}