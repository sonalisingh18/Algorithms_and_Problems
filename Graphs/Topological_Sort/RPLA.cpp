/*
 Sonali Singh
 Question link: https://www.spoj.com/problems/RPLA/
*/

#include<bits/stdc++.h>
#define mod 1000000007
#define ll long long int
#define ln "\n"
#define pb push_back
#define pf push_front
#define mp make_pair
#define pll pair<ll,ll>
#define f first
#define s second
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;
int main(){
    fio;
    ll t,n,m,a,b,i,j,k;
    cin>>t;
    for(k=1;k<=t;k++){
        cin>>n>>m;
        vector<ll> adj[n+1],inDegree(n+1,0);
        vector<pll> topsort;
        for(i=0;i<m;i++){
           cin>>a>>b;
           adj[b].pb(a);
           inDegree[a]++;
        }
        queue<pll> q;
        for(ll i=0;i<n;i++){
            if(inDegree[i]==0){
                q.push({1,i});
            }
        }
        while(!q.empty()){
            pll u=q.front();
            topsort.pb({u.f,u.s});
            for(auto x: adj[u.s]){
                inDegree[x]--;
                if(inDegree[x]==0){
                    q.push({u.f+1,x});
                }
            }
            q.pop();
        }
        sort(topsort.begin(),topsort.end());
        cout<<"Scenario #"<<k<<":"<<ln;
        for(i=0;i<topsort.size();i++)
            cout<<topsort[i].f<<" "<<topsort[i].s<<ln;
    }
    return 0;
}