#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
int main()
{
    fio;
    ll m;
    ll c[]={1,2,3,5};
    ll l=sizeof(c)/sizeof(c[0]);
    cin>>m;
    ll deno[m+1];
    deno[0]=0;
    for(ll i=1;i<m+1;i++)
    deno[i]=INT_MAX;
    for(ll i=1;i<=m;i++)
        for(ll j=0;j<l;j++)
            if(c[j]<=i)
            {
                ll numcoin=deno[i-c[j]]+1;
                if(numcoin!=INT_MAX && numcoin<=deno[i])
                deno[i]=numcoin;
            }
    cout<<deno[m];
    return 0;
}
