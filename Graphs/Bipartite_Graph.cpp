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
 
int main()
{
	fio;
	ll n,m,a,b,i,j;
    cin>>n>>m;
	vector<ll> adj[n+1];
	ll color[n+1];
    memset(color,-1,sizeof(color));
    for(i=0;i<m;i++)
	{
        cin>>a>>b;
	    adj[a].pb(b);
    	adj[b].pb(a);
	}
	queue<ll> q;
	ll flag=1,k=1;
    for(i=1;i<=n;i++)
	{
        if(color[i]==-1)
    	{
            color[i]=0;
        	q.push(i);
            while(!q.empty())
        	{
            	ll x=q.front();
                for(j=0;j<adj[x].size();j++)
            	{
                    if(color[adj[x][j]]==-1)
                	{
                        color[adj[x][j]]=color[x]^1;
                        q.push(adj[x][j]);
                	}
                    else
                	{
                        if(color[x]!=color[adj[x][j]])
                        k=1;
                        else
                        k=0;
                        flag=flag&k;
 	               }
            	}
                q.pop();
        	}
    	}
	}
	if(flag==1)
        cout<<"Bipartite Graph"<<endl;
	else
        cout<<"Not a Bipartitie Graph"<<endl;
	return 0;
}
 
/*
                                                                 __                     __
INPUT:                                                          |                         |
5 4                                         1--2  5             |   1--2         1--2     |
1 2                                         |  |                |   |  |   =>     \/      |
2 3                                         |  |                |   |  |          /\      |
3 4                                         4--3                |   4--3         3--4     |
4 1                                                             |__                     __|
 
OUTPUT:
Bipartite Graph
 
*/
