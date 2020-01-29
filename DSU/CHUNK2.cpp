/*
 Sonali Singh
 Question link: https://www.spoj.com/problems/CHUNK2/
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
vector<ll> prime;
ll parent[100005], size[100005];
bool IsPrime[2000006];
void sieve_of_eratosthenes(ll num){
    memset(IsPrime, true, sizeof(IsPrime));
    for(ll i=2;i*i<=num;i++){
        if(IsPrime[i]==true){
            for(ll j=i*i;j<=num;j+=i)
            IsPrime[j]=false;
        }
    }
    for(ll i=2;i<=num;i++){
        if(IsPrime[i]==true)
        prime.pb(i);
    }
}
 
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
    }
    else{
        parent[i_id]=j_id;
        size[j_id]+=size[i_id];
    }
}
 
int main()
{
    fio;
    ll t,n,m,i,a,b;
    cin>>t;
    while(t--){
        cin>>n>>m;
        MakeSet(n);
        for(i=0;i<m;i++){
            cin>>a>>b;
            Union(a,b);
        }
        ll max=0;
        for(i=0;i<n;i++){
            if(max<size[i])
            max=size[i];
        }
        //cout<<max<<endl;
        if(m==0)
        cout<<"-1"<<endl;
        else{
        sieve_of_eratosthenes(2000005);
        cout<<prime[max-1]<<endl;
        }
    }
    return 0;
} 
