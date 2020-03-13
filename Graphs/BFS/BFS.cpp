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

void addEdge(vector<ll>adj[], ll a, ll b){
    adj[a].pb(b);
    adj[b].pb(a);
}

void BFS(ll s, ll n, vector<ll>adj[]){
    queue<ll> q;
    q.push(s);
    ll vis[n+1];
    memset(vis,0,sizeof(vis));
    ll level[n+1];
    level[s]=0;
    vis[s]=1;
    while(!q.empty()){
        ll x=q.front();
        cout<<x<<"(Level:"<<level[x]<<")"<<" ";
        for(ll i=0;i<adj[x].size();i++){
            if(vis[adj[x][i]]==0){
                level[adj[x][i]]=level[x]+1;
                q.push(adj[x][i]);
                vis[adj[x][i]]=1;
                //cout<<adj[x][i]<<" ";
            }
        }
        q.pop();
    }    
}

//To print adjacency list
/*void printlist(vector<ll> adj[], ll n) 
{ 
    for(ll i=1;i<=n;i++) { 
        cout<<"\nAdjacency list of vertex "<<i<<"\n"<<i; 
        for (auto x:adj[i]) 
           cout <<"-> "<<x; 
        printf("\n"); 
    }
    cout<<endl;
} 
*/

int main(){
    fio;
    ll n=7;
    vector<ll> adj[n+1];                                     
    addEdge(adj,1,2);                                    
    addEdge(adj,2,5);                                   
    addEdge(adj,1,6);                                  
    addEdge(adj,2,7);                                    
    addEdge(adj,5,4);                                
    addEdge(adj,5,6);                               
    addEdge(adj,6,3);                                   
    //printlist(adj, n);                                 
    cout<<"BFS starting from node 3:\n";
    BFS(3,n,adj);
    return 0;
}

/*                                                                                                    1
                                                                                                     / \
                                                                                                    /   \
OUTPUT                                                                                             2     6
BFS starting from node 3:                                                                         / \   / \
3(Level:0) 6(Level:1) 1(Level:2) 5(Level:2) 2(Level:3) 4(Level:3) 7(Level:4)                     7    5    3
                                                                                                      |
                                                                                                      4 
*/
