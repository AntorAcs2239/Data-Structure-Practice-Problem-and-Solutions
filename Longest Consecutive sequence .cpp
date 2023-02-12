#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
void solve()
{
    int n;
    cin >> n;
    int ar[n];
    map<int,int>mp,mp2;
    for(int i=0;i<n;i++)
    {
        cin>>ar[i];
        mp[ar[i]]=1;
        mp2[ar[i]]=1;
    }
    for(int i=0;i<n;i++)
    {
        if(mp[ar[i]-1])
        {
            mp[ar[i]]=0;
        }
    }
    int si=0;
    vector<int>ans;
    for(int i=0;i<n;i++)
    {
        if(mp[ar[i]])
        {
            vector<int>tem;
            int j=ar[i];
            while(mp2[j])
            {
                tem.push_back(j);
                j++;
            }
            if(tem.size()>ans.size())
            {
                ans=tem;
            }
        }
    }
    cout<<ans.size()<<endl;
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
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