/*
 Sonali Singh
 Question link: https://www.codechef.com/problems/FIRESC
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
ll vis[1000000];
void addEdge(vector<ll>adj[], ll a, ll b){
    adj[a].pb(b);
    adj[b].pb(a);
}
void DFS(ll p, vector<ll>adj[],ll *c){
    (*c)++;
    vis[p]=1;
    for(ll i=0;i<adj[p].size();i++){
        if(vis[adj[p][i]]==0){
            DFS(adj[p][i],adj,c);
        }
    }
}
int main(){
    fio;
    ll t,n,m,i,a,b;
    cin>>t;
    while(t--){
        cin>>n>>m;
        ll ConnectedComp=0,ans=1;
        memset(vis,0,sizeof(vis));
        vector<ll> adj[n+1];                                     
        for(i=1;i<=m;i++){
            cin>>a>>b;
            addEdge(adj,a,b);
        }
        for(ll i=1;i<=n;i++){
            if(vis[i]==0){
                ll c=0;
                DFS(i,adj,&c);
                ConnectedComp++;
                ans=((ans%mod)*(c%mod))%mod;
            }
        }
        cout<<ConnectedComp<<" "<<ans<<endl;
    }
    return 0;
}
