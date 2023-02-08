#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int pre(char ch)
{
    if (ch == '+' || ch == '-')
        return 1;
    if (ch == '/' || ch == '*')
        return 2;
    if (ch == '(' || ch == ')')
        return 10;
    return 0;
}
vector<string> infixtopostfix(string s)
{
    stack<char> st;
    vector<string> ans;
    for (int i = 0; i < s.size(); i++)
    {
        if(s[i]==' ')continue;
        if (s[i] == '(')
        {
            st.push('(');
            i++;
            while(s[i]==' ')i++;
            if(pre(s[i]))
            {
                ans.push_back("0");
            }
            i--;
        }
        else if (s[i] == ')')
        {
            while (!st.empty() && st.top() != '(')
            {
                string t;
                t += st.top();
                ans.push_back(t);
                st.pop();
            }
            st.pop();
        }
        else if (!pre(s[i]))
        {
            string tem;
            while (!pre(s[i]) && i < s.size())
            {

                tem += s[i];
                if (s[i] == ' ')
                    tem.pop_back();
                i++;
            }
            i--;
            ans.push_back(tem);
        }
        else
        {
            while (!st.empty() && pre(s[i]) >= pre(st.top()))
            {
                string t;
                t += st.top();
                ans.push_back(t);
                st.pop();
            }
            st.push(s[i]);
        }
    }
    while (!st.empty())
    {
        string t;
        t += st.top();
        if (st.top() != '(')
            ans.push_back(t);
        st.pop();
    }
    return ans;
}
void solve()
{
    string s;
    cin >> s;
    string tem;
    tem+='0';
    tem+=s;
    s=tem;
    vector<string> vec = infixtopostfix(s);
    for(int i=0;i<vec.size();i++)cout<<vec[i]<<" ";
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