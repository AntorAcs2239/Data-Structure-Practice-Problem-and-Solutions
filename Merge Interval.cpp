#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
vector<vector<int>> merge(vector<vector<int>>vec)
{
    sort(vec.begin(), vec.end());
    vector<vector<int>> ans;
    int i, j;
    int mi = vec[0][0], mx = vec[0][1];
    for (i = 0, j = 1; j < vec.size();)
    {
        int c = vec[j][0], d = vec[j][1];
        if (!(c >= mi && c <= mx))
        {
            vector<int> t;
            t.push_back(mi);
            t.push_back(mx);
            ans.push_back(t);
            mi = c;
            mx = d;
            i = j;
            j++;
        }
        else
        {
            mx = max(mx, d);
            j++;
        }
    }
    if (j == vec.size())
    {
        vector<int> t;
        t.push_back(mi);
        t.push_back(mx);
        ans.push_back(t);
        i = j;
        j++;
    }
    return ans;
}
void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> vec;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        vector<int>t;
        t.push_back(a);
        t.push_back(b);
        vec.push_back(t);
    }
    vec=merge(vec);
    for(int i=0;i<vec.size();i++)
    {
        cout<<vec[i][0]<<" "<<vec[i][1]<<endl;
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