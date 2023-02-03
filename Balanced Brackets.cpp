#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
void solve()
{
    string  s;
    cin>>s;
    stack<char>st;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]==')'||s[i]==']'||s[i]=='}')
        {
            if(st.empty())
            {
                cout<<"False"<<endl;
                return;
            }
            while(st.top()!='('&&st.top()!='['&&st.top()!='{')
            {
                st.pop();
            }
            
            if((s[i]==')'&&st.top()!='(')||
                (s[i]=='}'&&st.top()!='{')||
                 (s[i]==']'&&st.top()!='['))
                 {
                    cout<<"False"<<endl;
                    return;
                 }
                 st.pop();
        }
        else 
        {
            st.push(s[i]);
        }
    }
    if(st.empty())cout<<"True"<<endl;
    else cout<<"False"<<endl;
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