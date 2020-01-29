/*
 Sonali Singh
 Question link:https://www.codechef.com/problems/DIVSET
*/

#include<bits/stdc++.h>
#define mod 1000000007
#define ll long long int
#define pb push_back
#define mp make_pair
#define pll pair<ll,ll>
#define f first
#define s second
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;

bool bin_srch(vector<ll> a,ll n,ll mid, ll k, ll c){
    vector<ll>v(mid);
    ll i=0,x;
    while(k--){
        x=0;
        while(i<n && x<mid){
            if(v[x]*c<=a[i]){
                v[x]=a[i];
                x++;
            }
            i++;
        }
        if(x<mid)
        return false;
    }
    return true;
}

int main()
{
    fio;
    ll t,n,k,c,i;
    cin>>t;
    while(t--)
    {
        cin>>n>>k>>c;
        vector<ll>a(n);
        for(i=0;i<n;i++)
        cin>>a[i];
        sort(a.begin(), a.end());
        ll l=0,mid;
        ll r=n/k;
        ll count=0;
        while(r>=l){
            mid=((r+l)/2);
            if(bin_srch(a,n,mid,k,c)){
                l=mid+1;
                count=max(count,mid);
            }
            else
            r=mid-1;
        }
        cout<<count<<endl;
    }
    return 0;
}
