/*
Sonali Singh
#spoj_problem
#stack
question link: https://www.spoj.com/problems/STPAR/
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
int main()
{
    fio;
    ll n;
    cin>>n;
    while(n)
    {
        ll i,c=1,k=1;
        long long a[n+1];
        for(i=1;i<=n;i++)
            cin>>a[i];
        stack<ll>s;
        for(i=1;i<=n;i++)
        {
            if(a[i]==k)
                k++;
            else
            {
                if(s.empty())
                {
                      s.push(a[i]);
 
                }
 
                else if(!s.empty() && s.top()<a[i])
                {
 
                    c=0;
                    break;
                }
                else
                    s.push(a[i]);
            }
 
            while(!s.empty() && s.top()==k)
            {
                s.pop();
                k++;
            }
        }
        if(c==0)
            cout<<"no"<<endl;
        else if(k-1==n && s.empty())
            cout<<"yes"<<endl;
            cin>>n;
    }
    return 0;
}
