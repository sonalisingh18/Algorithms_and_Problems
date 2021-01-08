/*
 Sonali Singh
 Question link: https://www.spoj.com/problems/EZDIJKST/
*/

#include<bits/stdc++.h>
#define mod 1000000007
#define ll long long int
#define pb push_back
#define pf push_front
#define mp make_pair
#define pll pair<ll,ll>
#define f first
#define s second
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define inf 0x3f3f3f3f
using namespace std;
ll V;
 
void addEdge(vector<pair<ll,ll>>adj[], ll u, ll v, ll wt){ 
	adj[u].pb({v, wt}); 
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
	cout<<"NO"<<endl;
	else
	cout<<dist[d]<<"\n";
} 
 
int main(){ 
    fio;
    ll t,v,k,a,b,c,A,B;
    cin>>t;
    while(t--){
        cin>>V>>k;
	    vector<pair<ll,ll>>adj[V+1]; 
        for(ll i=0;i<k;i++){
            cin>>a>>b>>c;
            addEdge(adj,a,b,c);
        }
        cin>>A>>B;
	    dijkstra(adj,A,B); 
    }
    return 0;
}