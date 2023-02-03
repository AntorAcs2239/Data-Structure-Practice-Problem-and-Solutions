#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
void solve()
{
    int n;
    cin>>n;
    int ar[n],br[n];
    for(int i=0;i<n;i++)cin>>ar[i],br[i]=ar[i];
    stack<int>st;
     st.push(ar[n-1]);
    ar[n-1]=-1;
    for(int i=n-2;i>=0;i--)
    {
        while(!st.empty()&&st.top()<ar[i])
        {
            st.pop();
        }
        if(st.empty())
        {
             st.push(ar[i]);
             ar[i]=-1;
        }
        else 
        {
            int t=st.top();
            st.push(ar[i]);
            ar[i]=t;
        }
    }
    for(int i=0;i<n;i++)cout<<"Next Greater element of "<<br[i]<<" is "<<ar[i]<<endl;
    cout<<endl;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}