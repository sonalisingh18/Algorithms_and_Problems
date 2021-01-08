/*
 Sonali Singh
 Question link: https://www.spoj.com/problems/CAM5/
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
ll parent[1000000], size[1000000];
void MakeSet(ll n){
    for(ll i=0;i<n;i++){
        parent[i]=i;
        size[i]=1;
    }
}
ll Find(ll i){
    while(i!=parent[i])
        i=parent[i];
    return i;
}
void Union(ll i, ll j){
    ll i_id=Find(i);
    ll j_id=Find(j);
    if(i_id==j_id)
        return;
    if(size[i_id]>size[j_id]){
        parent[j_id]=i_id;
        size[i_id]+=size[j_id];
    }
    else{
        parent[i_id]=j_id;
        size[j_id]+=size[i_id];
    }
}
int main()
{
    fio;
    ll t,n,m,a,b;
    cin>>t;
    while(t--){
        ll c=0;
        cin>>n>>m;
        MakeSet(n);
        for(ll i=0;i<m;i++){
            cin>>a>>b;
            Union(a,b);
        }
        for(ll i=0;i<n;i++){
            if(parent[i]==i)
                c++;
        }
        cout<<c<<endl;
    }
    return 0;
}