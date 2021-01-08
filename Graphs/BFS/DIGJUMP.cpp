/*
 Sonali Singh
 Question link: https://www.codechef.com/problems/DIGJUMP
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

int main(){
    fio;
    string s;
    cin>>s;
    ll n=s.size();
    vector<ll> adj[11];
    vector<ll> dis(n+1,-1);
    for(ll i=0;i<n;i++)
    adj[s[i]-'0'].pb(i);
    queue<ll>q;
    q.push(0);
    dis[0]=0;
    while(!q.empty()){
        ll x=q.front();
        if(x==n-1)
            break;
        q.pop();
        if(x-1>=0){
            if(dis[x-1]==-1){
                dis[x-1]=dis[x]+1;
                q.push(x-1);
            }
        }
        if(x+1<=n-1){
            if(dis[x+1]==-1){
                dis[x+1]=dis[x]+1;
                q.push(x+1);
            }
        }
        ll y=s[x]-'0';
        for(auto it: adj[y]){
            if(dis[it]==-1){
                dis[it]=dis[x]+1;
                q.push(it);
            }
        }
        adj[y].clear();
    }
    cout<<dis[n-1];
    return 0;
}