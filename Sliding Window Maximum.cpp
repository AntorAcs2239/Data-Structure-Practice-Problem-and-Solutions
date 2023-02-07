#include <bits/stdc++.h>
using namespace std;
#define ll long long int
void solve()
{
    int n,k;
    cin >> n>>k;
    int ar[n], br[n];
    for (int i = 0; i < n; i++)
        cin >> ar[i], br[i] = ar[i];
    stack<int> st;
    st.push(0);
    for (int i = 1; i < n; i++)
    {
        while (!st.empty() && ar[i] >= ar[st.top()])
        {
            int t = st.top();
            ar[t] = i;
            st.pop();
        }
        st.push(i);
    }
    while (!st.empty())
    {
        int t = st.top();
        ar[t] =n+100;
        st.pop();
    }
    for(int i=0;i<n;i++)cout<<ar[i]<<" ";
    cout<<endl;
    for(int i=0;i<=n-k;i++)
    {
        int a=i+k-1;
        int b=ar[i];
        if(b>a)
        {
            cout<<br[b]<<" ";
            continue;
        }
        while(b<=a)
        {
            if(b+ar[b]>a)break;
            b=ar[b];
        }
        cout<<br[b]<<" ";
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