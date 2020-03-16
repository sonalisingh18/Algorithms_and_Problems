/*
  Sonali Singh
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

ll vis[100];

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
    ll n=7, ConnectedComp=0;
    memset(vis,0,sizeof(vis));
    vector<ll> adj[n+1];                                     
    addEdge(adj,1,2);                                    
    addEdge(adj,2,5);                                   
    addEdge(adj,1,6);                                  
    addEdge(adj,2,7);                                     
    for(ll i=1;i<=n;i++){
        if(vis[i]==0){
            DFS(i,adj);
            ConnectedComp++;
        }
    }
    cout<<"Number of connected components: "<<ConnectedComp;
    return 0;
}

/*                                                                                    1
                                                                                     / \
                                                                                    /   \
OUTPUT                                                                             2     6
Number of connected components: 3                                                 / \   / 
                                                                                 7    5    3
                                                                                      
                                                                                      4 
*/
