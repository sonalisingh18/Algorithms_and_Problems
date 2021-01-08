/*
 Sonali Singh
 Question link: https://www.spoj.com/problems/GCPC11J/
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
ll n,maxx,node=0,vis[1000000],level[1000000];
vector<ll> adj[1000000];
void addEdge(vector<ll>adj[], ll a, ll b){
    adj[a].pb(b);
    adj[b].pb(a);
}
void BFS(ll s){
    memset(vis,0,sizeof(vis));
    memset(level,0,sizeof(level));
    queue<ll> q;
    q.push(s);
    vis[s]=1;
    while(!q.empty()){
        ll x=q.front();
        for(ll i=0;i<adj[x].size();i++){
            if(vis[adj[x][i]]==0){
                level[adj[x][i]]=level[x]+1;
                q.push(adj[x][i]);
                vis[adj[x][i]]=1;
            }
        }
        q.pop();
    }
    maxx=1;
    for(ll i=0;i<n;i++){
        maxx=max(maxx,level[i]);
        if(maxx==level[i]) 
        node=i;
    }
}
int main(){
    fio;
    ll t,a,b;
    cin>>t;
    while(t--){
        cin>>n;
        for(ll i=0;i<n-1;i++){
            cin>>a>>b;
            addEdge(adj,a,b);
        }
        BFS(0);
        BFS(node);
        cout<<(maxx+1)/2<<endl;
        for(ll i=0;i<n;i++)
            adj[i].clear();
    }
  return 0;
} 