/* addition at a particular postion in the array using segment trees.
   finding the sum of the given range*/
   
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
void build(ll a[],ll v,ll low,ll high,ll t[])
{
    if(low==high)
    {
        t[v]=a[low];
    }
    else
    {
        ll mid=(low+high)/2;
        build(a,2*v+1,low,mid,t);
        build(a,2*v+2,mid+1,high,t);
        t[v]=t[2*v+1]+t[v*2+2];
    }
}
void update(ll v,ll low,ll high,ll pos,ll value,ll t[])
{
    if(low==high)
    {
        t[v]=value;
    }
    else
    {
        ll mid=(low+high)/2;
        if(pos<=mid)
        update(2*v+1,low,mid,pos,value,t);
        else
        update(2*v+2,mid+1,high,pos,value,t);
        t[v]=t[v*2+1]+t[v*2+2];
    }
}
ll sum(ll v,ll low,ll high,ll l,ll r,ll t[])
{
    if(l>r)
    return 0;
    else
    if(l==low && r==high)
    {
        return t[v];
    }
    else
    {
        ll mid=(low+high)/2;
        return sum(2*v+1,low,mid,l,min(mid,r),t)+sum(2*v+2,mid+1,high,max(l,mid+1),r,t);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n,i,j,q,m,pos,value,l,r;
    cin>>n;
    ll a[n];
    ll size=pow(2,ceil(log2(n))+1);
    ll t[size];
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    build(a,0,0,n-1,t);
    cin>>q;
    for(i=0;i<q;i++)
    {
        /*cin>>m;
        if(m==1)
        {
            cin>>pos>>value;
            update(0,0,n-1,pos-1,value,t);
        }
        else
        if(m==2)
        {*/
            cin>>l>>r;
            cout<<sum(0,0,n-1,l-1,r-1,t)<<endl;
        //}
    }
}
