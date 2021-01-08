/*
 Sonali Singh
 Question link: https://www.codechef.com/problems/BIGOF01
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
void Union(ll i,ll j){
    ll i_id=Find(i);
    ll j_id=Find(j);
    if(i_id==j_id)
        return;
    if(size[i_id]>size[j_id]){
        parent[j]=i_id;
        size[i_id]+=size[j_id];
    }
    else{
        parent[i]=j_id;
        size[j_id]+=size[i_id];
    }
}
void Sona(ll x,ll y){
    ll x_id=Find(x);
    ll y_id=Find(y);
    if(x_id==y_id)
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;  
}
int main(){
    fio;
    ll t,i,n,c,q,s,d,a,b;
    cin>>t;
    while(t--){
        cin>>n>>c;
        MakeSet(n);
        for(i=1;i<=c;i++){
            cin>>a>>b;
            Union(a,b);
        }
        cin>>q;
        for(i=0;i<q;i++){
            cin>>s>>d;
            Sona(s,d);
        }
    }
    return 0;
}