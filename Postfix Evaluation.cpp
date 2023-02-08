#include <bits/stdc++.h>
using namespace std;
#define ll long long int
bool isoperator(string op)
{
    if (op == "+" || op == "-" || op == "*" || op == "/")
        return true;
    return false;
}
int evalute(vector<string> tokens)
{
    stack<int> st;
    for (int i = 0; i < tokens.size(); i++)
    {
        if (isoperator(tokens[i]))
        {
            int v1 = st.top();
            st.pop();
            int v2 = st.top();
            st.pop();
            string op = tokens[i];
            int ans;
            if (op == "+")
                ans = v1 + v2;
            if (op == "-")
                ans = v2 - v1;
            if (op == "*")
                ans = v1 * v2;
            if (op == "/")
                ans = v2 / v1;
            st.push(ans);
        }
        else
        {
            int v = stoi(tokens[i]);
            st.push(v);
        }
    }
    return st.top();
}
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
    cout << evalute(vec) << endl;
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