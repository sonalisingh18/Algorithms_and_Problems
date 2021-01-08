/*
 Sonali Singh
 Question link: https://www.spoj.com/problems/MAKETREE/
*/

#include <iostream>
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
    ll n,k,i,j,w,a;
    cin>>n>>k;
    vector<ll> outdeg(n+5,0), adj[n+1],topp(n+5,0),pos(n+5,0);
    for(i=1;i<=k;i++){
        cin>>w;
        outdeg[i]=w;
        for(j=0;j<w;j++){
            cin>>a;
            adj[a].pb(i);
        }
    }
    queue<ll> q;
    for(i=1;i<=n;i++){
        if(outdeg[i]==0)
            q.push(i);
    }
    //for(i=1;i<=n;i++)
    //cout<<outdeg[i]<<" ";
    //cout<<endl;
    ll c=0;
    while(!q.empty()){
        ll u=q.front();
        q.pop();
        topp[++c]=u;
        pos[u]=c;
        for(auto x: adj[u]){
            if(--outdeg[x]==0)
                q.push(x);
        }
    }
    //for(i=1;i<=n;i++)
    //cout<<topp[i]<<" ";
    //cout<<endl;
    //for(i=1;i<=n;i++)
    //cout<<pos[i]<<" ";
    //cout<<endl;
    for(i=1;i<=n;i++)
        cout<<topp[pos[i]+1]<<endl;
    return 0;
}