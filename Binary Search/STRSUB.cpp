/*Sonali Singh
#Codechef
#binary_search
question link: https://www.codechef.com/problems/STRSUB
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);
ll calculate(ll l,ll r,ll sum[],ll max[],ll n)
{
    ll k1=l-1;
    ll k2=r+1;
    while((k2-k1)>1)
    {
        ll km=(k1+k2)/2;
        if (max[km]<=r)
            k1=km;
        else
            k2=km;
    }
    ll k=k1;
    ll answer=sum[k]-sum[l-1]+(r-k)*(r+1)-(r*(r+1)/2-l*(l-1)/2);
    return answer;
}   

int main()
{
    fio;
    ll t,i,j,k,m,n,q,s,p,r,l,zero,one,ans;
    char a[1000000];
    a[0]='0';
    cin>>t;
    while(t--)
    {
        cin>>n>>k>>q;
        
        for(i=1;i<=n;i++)
        cin>>a[i];
        ll sum[n+1],max[n+1];
        max[0]=0;
        zero=0;
        one=0;
        j=1;
        if(a[1]=='1')
        one++;
        else
        zero++;
        for(i=1;i<=n;i++)
        {
            while(j<=n && one<=k && zero<=k)
            {
            j += 1;
            if (j > n)
                break;
            if (a[j] == '1')
                one=one+1;
            else
                zero=zero+1;
            }
            max[i]=j;
            if (a[i] == '1')
                one=one-1;
            else
                zero=zero-1;
        }
        for(i=1;i<=n;i++)
        sum[0]=0;
        for(i=1;i<=n;i++)
            sum[i]=sum[i-1]+max[i];
        for(i=0;i<q;i++)
        {
            cin>>l>>r;
            ll answer=calculate(l,r,sum,max,n);
            cout<<answer<<endl;
        }
    }
    return 0;
}
