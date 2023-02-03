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
    for(int i=1;i<n;i++)
    {
        while(!st.empty()&&ar[i]>=ar[st.top()])
        {
            int p=st.top();
            ar[p]=ar[i];
            st.pop();
        }
        st.push(i);
    }
    while(!st.empty())
    {
        int p=st.top();
        ar[p]=-1;
        st.pop();
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