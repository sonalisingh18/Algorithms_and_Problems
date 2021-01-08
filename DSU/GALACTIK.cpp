/*
 Sonali Singh
 Question link: https://www.codechef.com/problems/GALACTIK
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
ll parent[100000], size[1000000],tax[1000000];

void MakeSet(ll n){
    for(ll i=1;i<=n;i++){
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
        tax[i_id]=tax[j_id]=min(tax[i_id],tax[j_id]);
    }
    else{
        parent[i_id]=j_id;
        size[j_id]+=size[i_id];
        tax[i_id]=tax[j_id]=min(tax[i_id],tax[j_id]);
    }
}

int main(){
    fio;
    ll n,m;
    cin>>n>>m;
    MakeSet(n);
    ll a[m],b[m];
    for(ll i=1;i<=m;i++)
    cin>>a[i]>>b[i];
    for(ll i=1;i<=n;i++){
        cin>>tax[i];
        if(tax[i]<0)
        tax[i]=INT_MAX;
    }
    for(ll i=1;i<=m;i++)
       Union(a[i],b[i]);
    //for(ll i=1;i<=n;i++)
        //cout<<parent[i]<<" ";
    //cout<<endl;
    vector<ll>v;
    for(ll i=1;i<=n;i++){
        if(parent[i]==i)
            v.pb(tax[i]);
    }
    //for(ll i=0;i<v.size();i++)
        //cout<<v[i]<<" ";
    //cout<<endl;
    if(v.size()==1)
        cout<<"0"<<endl;
    else{
        sort(v.begin(),v.end());
        if(v[v.size()-1]==INT_MAX)
            cout<<"-1"<<endl;
        else{
            ll sum=v[0]*(v.size()-1);
            for(ll i=1;i<v.size();i++)
                sum+=v[i];
            cout<<sum<<endl;
        }
    }
    return 0;
}