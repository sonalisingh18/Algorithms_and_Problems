/*
Sonali Singh
Time complexity: O(V+E)
Auxiliary space: O(V)
Topological Sort: Topological sorting for Directed Acyclic Graph (DAG) is a linear ordering of vertices 
such that for every directed edge uv, vertex u comes before v in the ordering. Topological Sorting for a 
graph is not possible if the graph is not a DAG.
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
using namespace std;
 
void addEdge(vector<ll> adj[], ll u, ll v,  vector<ll> &inDegree){
	adj[u].pb(v);
	inDegree[v]++;
}
int main(){
	fio;
	ll n=6,i,j;
	vector<ll> adj[n+1];
	vector<ll> topsort,inDegree(n+1,0),vis(n+1,0);
    addEdge(adj,5,2,inDegree);
    addEdge(adj,5,0,inDegree);
    addEdge(adj,4,0,inDegree);
    addEdge(adj,4,1,inDegree);
    addEdge(adj,2,3,inDegree);
    addEdge(adj,3,1,inDegree);
	queue<ll> q;
	for(ll i=0;i<n;i++){
        if(inDegree[i]==0){
        	q.push(i);
        	vis[i]=1;
    	}
	}
	ll c=0;
	while(!q.empty()){
    	ll u=q.front();
    	topsort.pb(u);
    	q.pop();
    	for(auto x: adj[u]){
            if(vis[x]==0){
                inDegree[x]--;
                if(inDegree[x]==0){
                    q.push(x);
           	     vis[x]=1;
            	}
        	}
    	}
    	c++;
	}
	if(c!=n)
        cout<<"There exists a cycle in graph"<<endl;
	else{
        cout<<"Topological Sort:\n";
        for(i=0;i<topsort.size();i++)
            cout<<topsort[i]<<" ";
        cout<<endl;
	}
	return 0;
}
 
/*
OUTPUT
Topological Sort:
4 5 2 0 3 1
*/
