/*
 Sonali Singh
 Question link: https://www.spoj.com/problems/PPATH/
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
ll a[10000]={0};
ll vis[10000];
ll level[10000];
vector<ll> v;
void sieve(){
    for(int i=2;i<=100;i++){
        if(a[i]==0){
            for(int j=i*i;j<=10000;j+=i)
            a[j]=1;
        }
    }
    for(int i=1000;i<10000;i++){
        if(a[i]==0)
        v.pb(i);
    }
}
void addEdge(vector<ll>adj[], ll a, ll b){
    adj[a].pb(b);
    adj[b].pb(a);
}
void BFS(ll s, vector<ll>adj[]){
    queue<ll> q;
    q.push(s);
    memset(vis,0,sizeof(vis));
    memset(level,-1,sizeof(level));
    vis[s]=1;
    level[s]=0;
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
}
int main(){
    fio;
    ll n,i,j,k,a,b;
    sieve();
    vector<ll> adj[10000];
    for(i=0;i<v.size();i++){
        for(j=0;j<v.size();j++){
            ll c=0;
            for(k=3;k>=0;k--){
                if(((v[i]/((ll)pow(10,k)))%10)==((v[j]/(ll)(pow(10,k)))%10))
                    c++;
            }
            if(c==3)
                addEdge(adj,v[i],v[j]);
        }
    }
        cin>>n;
        while(n--){
            cin>>a>>b;
            BFS(a,adj);
            if(level[b]==-1)
               cout<<"Impossible"<<endl;
            else
                cout<<level[b]<<endl;
        }
    return 0;
}