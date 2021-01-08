/*
 Sonali Singh
 Question link: https://www.spoj.com/problems/SHPATH/
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
    ll t,k,a,b,c,r;
    cin>>t;
    while(t--){
        cin>>V;
        vector<pair<ll,ll>>adj[V+1]; 
        map<string,ll>mp;
        string str,str1,str2;
        for(ll j=1;j<=V;j++){
            cin>>str;
            mp[str]=j;
            cin>>k;
            for(ll i=0;i<k;i++){
                cin>>b>>c;
                addEdge(adj,j,b,c);
            }
        }
        cin>>r;
        for(ll i=1;i<=r;i++){
            cin>>str1>>str2;
	        dijkstra(adj,mp.at(str1),mp.at(str2));
        }
    }
    return 0;
}