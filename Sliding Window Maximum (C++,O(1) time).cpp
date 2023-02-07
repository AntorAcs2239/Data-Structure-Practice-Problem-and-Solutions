#include <bits/stdc++.h>
using namespace std;
#define ll long long int
void solve()
{
    int n,k;
    cin >> n>>k;
    int ar[n];
    for(int i=0;i<n;i++)cin>>ar[i];
    int left_max[n],right_max[n];
    int t=n%k;
    int mx=INT_MIN;
    for(int i=0;i<n;i++)
    {
        mx=max(mx,ar[i]);
        left_max[i]=mx;
        if(i%k==k-1)
        {
            mx=INT_MIN;
        }
    }
    mx=INT_MIN;
    for(int i=n-1;i>=n-t;i--)
    {
        mx=max(mx,ar[i]);
        right_max[i]=mx;
    }
    mx=INT_MIN;
    int p=1;
    for(int i=n-t-1;i>=0;i--)
    {
        mx=max(mx,ar[i]);
        right_max[i]=mx;
        if(p%k==0)
        {
            mx=INT_MIN;
        }
        p++;
    }
    for(int i=0;i<n;i++)
    {
        cout<<left_max[i]<<" ";
    }
    cout<<endl;
       for(int i=0;i<n;i++)
    {
        cout<<right_max[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<=n-k;i++)
    {
        cout<<max(left_max[i+k-1],right_max[i])<<" ";
    }
    cout<<endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}