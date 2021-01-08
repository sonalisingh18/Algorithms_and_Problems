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
ll vis[1000000];
void addEdge(vector<ll>adj[], ll a, ll b){
    adj[a].pb(b);
    adj[b].pb(a);
}
void DFS(ll p, vector<ll>adj[]){
    vis[p]=1;
    for(ll i=0;i<adj[p].size();i++){
        if(vis[adj[p][i]]==0){
            DFS(adj[p][i],adj);
        }
    }
}
int main(){
    fio;
    ll t,n,m,a,b;
    cin>>t;
    while(t--){
        ll ConnectedComp=0;
        cin>>n>>m;
        memset(vis,0,sizeof(vis));
        vector<ll> adj[n+1]; 
        for(ll i=0;i<m;i++){
            cin>>a>>b;
            addEdge(adj,a,b); 
        }
        for(ll i=0;i<n;i++){
            if(vis[i]==0){
                DFS(i,adj);
                ConnectedComp++;
            }
        }
        cout<<ConnectedComp<<endl;
    }
    return 0;
}