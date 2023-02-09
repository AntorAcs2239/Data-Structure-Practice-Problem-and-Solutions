#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
void solve()
{
    int n;
    cin>>n;
    int ar[n][n];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)cin>>ar[i][j];
    }
    stack<int>st;
    for(int i=0;i<n;i++)st.push(i);
    while(st.size()>=2)
    {
        int i=st.top();
        st.pop();
        int j=st.top();
        st.pop();
        if(ar[i][j])
        {
            st.push(j);
        }
        else 
        {
            st.push(i);
        }
    }
    int p=st.top();
    for(int i=0;i<n;i++)
    {
        if(ar[p][i]==1)
        {
            cout<<"No Celebrity"<<endl;
            return;
        }
    }
    for(int i=0;i<n;i++)
    {
        if(i!=p&&ar[i][p]==0)
        {
            cout<<"No Celebrity"<<endl;
            return;
        }
    }
    cout<<"The person "<<p+1<<" is Celebrity"<<endl;
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