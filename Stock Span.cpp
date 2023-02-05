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
    st.push(0);
    br[0]=1;
    for(int i=1;i<n;i++)
    {
        while(!st.empty()&&ar[i]>=ar[st.top()])
        {
            st.pop();
        }
        if(!st.empty())
        {
            int t=st.top();
            br[i]=i-t;
        }
        else 
        {
            br[i]=i+1;
        }
        st.push(i);
    }
    for(int i=0;i<n;i++)cout<<"Span of "<<ar[i]<<" is "<<br[i]<<endl;
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