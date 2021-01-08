/*
 Sonali Singh
 Question link: https://www.spoj.com/problems/TRAFFICN/
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
ll n;
void dijkstra(vector<pair<ll,ll>>adj[], vector<ll>&dist, ll s, ll d){ 
    priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>>pq; 
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
} 
int main(){ 
    fio;
    ll T,n,m,k,s,t,a,b,w,u,v,wt,i,ans;
    cin>>T;
    while(T--){
        cin>>n>>m>>k>>s>>t;
        vector<pair<ll,ll>>adj1[n+1]; 
        vector<pair<ll,ll>>adj2[n+1]; 
        vector<ll>dist1(n+1,inf); 
        vector<ll>dist2(n+1,inf); 
        for(i=0;i<m;i++){
            cin>>a>>b>>wt;
            adj1[a].pb({b,wt});
            adj2[b].pb({a,wt});
        }
        dijkstra(adj1,dist1,s,t);
        dijkstra(adj2,dist2,t,s);
        ans=dist1[t];
        //cout<<dist1[t]<<" "<<dist2[s]<<endl;
        for(i=0;i<k;i++){
            cin>>u>>v>>w;
            ans=min(ans,min((dist1[u]+w+dist2[v]),(dist1[v]+w+dist2[u])));
            //cout<<ans<<" ";
        }
        if(ans==inf)
	        cout<<"-1"<<endl;
	    else
	        cout<<ans<<endl;
    }
  return 0; 
}