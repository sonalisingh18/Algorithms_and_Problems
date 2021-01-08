/*
 Sonali Singh
 Question link: https://www.spoj.com/problems/TRVCOST/
*/

#include<bits/stdc++.h>
#define mod 1000000007
typedef long long ll;
#define pb push_back
#define pf push_front
#define mp make_pair
#define pll pair<ll,ll>
#define f first
#define s second
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define inf 0x3f3f3f3f
using namespace std;
ll V=505;
 
void addEdge(vector<pair<ll,ll>>adj[], ll u, ll v, ll wt){ 
	adj[u].pb({v,wt}); 
	adj[v].pb({u,wt});
}
 
void dijkstra(vector<pair<ll,ll>>adj[], ll s, ll d){ 
	priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>>pq; 
	vector<ll>dist(V+1,inf); 
	pq.push({0,s}); 
	dist[s]=0; 
	while(!pq.empty()){ 
		ll u=pq.top().second; 
		for(auto x: adj[u]){
			ll v=x.f; 
			ll wt=x.s; 
			if(dist[v]>dist[u]+wt){ 
				dist[v]=dist[u]+wt; 
				pq.push({dist[v],v}); 
			} 
		}
		if(u==d)
		    break;
		pq.pop();  
	} 
	if(dist[d]==inf)
	cout<<"NO PATH"<<endl;
	else
	cout<<dist[d]<<"\n";
} 
 
int main(){ 
    fio;
    ll n,a,b,w,u,v,q,i;
    cin>>n;
    vector<pair<ll,ll>>adj[V];
    for(i=0;i<n;i++){
        cin>>a>>b>>w;
        addEdge(adj,a,b,w);
    }
    cin>>u>>q;
    for(i=0;i<q;i++){
        cin>>v;
        dijkstra(adj,u,v);
    }
    return 0;
}