#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
void solve()
{
    string s;
    cin>>s;
    stack<char>st;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='('||(s[i]!='('&&s[i]!=')'))
        {
            st.push(s[i]);
        }
        else 
        {
            if(st.top()=='(')
            {
                cout<<"Needless Brackets Exist"<<endl;
                return;
            }
            while(st.top()!='(')
            {
                st.pop();
            }
            st.pop();
        }
    }
      cout<<"No Needless Brackets"<<endl;
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