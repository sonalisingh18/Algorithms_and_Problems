/*
Sonali Singh
Time complexity: O(V+E)
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
 
struct node
{
	ll to, weight;
};
vector<node> edges[100000];	
 
void addEdge(ll a, ll b, ll w)
{
    edges[a].pb({b,w});
    edges[b].pb({a,w});
}
 
void ZeroOneBFS(ll s,ll n)
{
	ll dist[n+1];
	for(ll i=0;i<n;i++)
	dist[i] = INT_MAX;
	deque<ll> q;
	dist[s]=0;
	q.pb(s);
	while(!q.empty())
	{
    	ll x=q.front();
    	q.pop_front();
    	for(ll i=0;i<edges[x].size();i++)
    	{
            if(dist[edges[x][i].to]>dist[x]+edges[x][i].weight)
        	{
                dist[edges[x][i].to]=dist[x]+edges[x][i].weight;
                if(edges[x][i].weight==0)
               	 q.pf(edges[x][i].to);
            	else
                    q.pb(edges[x][i].to);
        	}
    	}
	}
	for(ll i=0;i<n;i++)
	{
        cout<<dist[i]<<" ";
	}
}
 
int main()
{
	fio;
	ll n=9;
	addEdge(0, 1, 0);
	addEdge(0, 7, 1);
	addEdge(1, 7, 1);
	addEdge(1, 2, 1);
	addEdge(2, 3, 0);
	addEdge(2, 5, 0);
	addEdge(2, 8, 1);
	addEdge(3, 4, 1);
	addEdge(3, 5, 1);
	addEdge(4, 5, 1);
	addEdge(5, 6, 1);
    addEdge(6, 7, 1);
	addEdge(7, 8, 1);                           	
    cout<<"Shortest distance between node 0 and other nodes\n";
	ZeroOneBFS(0,n);
	return 0;
}

/*
                                                                     1 	   0
                                                                  1-----2-----3
                                                               0 /| 	|\	  |\ 1
OUTPUT:                                                         / |1   1| \  1| \
Shortest distance between node 0 and other nodes               0  |     8  \  |  4
0 0 1 1 2 1 2 1 2                                               \ |  1/ |  0\ | /
                                                               1 \|  / 1|	 \|/ 1
                	                                              7-----6-----5
                                                                     1 	   1
*/
