#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
void next_smallest_element_to_Right(int ar[],int n,int nSER[])
{
    stack<int>st;
    st.push(0);
    for(int i=1;i<n;i++)
    {
        while(!st.empty()&&ar[i]<=ar[st.top()])
        {
            int p=st.top();
            nSER[p]=i;
            st.pop();
        }
        st.push(i);
    }
    while(!st.empty())
    {
        int p=st.top();
        nSER[p]=n;
        st.pop();
    }
}
void next_smallest_element_to_Left(int ar[],int n,int nSEL[])
{
    stack<int>st;
    st.push(n-1);
    for(int i=n-2;i>=0;i--)
    {
        while(!st.empty()&&ar[i]<=ar[st.top()])
        {
            int p=st.top();
            nSEL[p]=i;
            st.pop();
        }
        st.push(i);
    }
    while(!st.empty())
    {
        int p=st.top();
        nSEL[p]=-1;
        st.pop();
    }
}
void solve()
{
    int n;
    cin>>n;
    int ar[n],br[n],nSEL[n],nSER[n];
    for(int i=0;i<n;i++)cin>>ar[i],br[i]=ar[i];
    next_smallest_element_to_Right(ar,n,nSER);
    next_smallest_element_to_Left(ar,n,nSEL);
    int LAH[n];
    int Largest_Area_Histogram=INT_MIN;
    for(int i=0;i<n;i++)
    {
        LAH[i]=nSER[i]-(nSEL[i]);
        Largest_Area_Histogram=max(Largest_Area_Histogram,(LAH[i]-1)*ar[i]);
    }
    cout<<Largest_Area_Histogram<<endl;
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