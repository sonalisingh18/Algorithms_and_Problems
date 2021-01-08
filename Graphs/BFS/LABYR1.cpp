/*
 Sonali Singh
 Question link: https://www.spoj.com/problems/LABYR1/
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
char str[1001][1001];
ll vis[1001][1001],level[1001][1001],r,c,maxlen;
pair<ll,ll>node;
ll mr[]={0,1,0,-1};
ll mc[]={-1,0,1,0};
void BFS(pair<ll,ll>s){
    queue<pair<ll,ll>>q;
    q.push(s);
    memset(vis,0,sizeof(vis));
    level[s.f][s.s]=0;
    maxlen=0;
    while(!q.empty()){
        pair<ll,ll> x=q.front(),next;
        q.pop();
        for(ll i=0;i<4;i++){
            next.f=x.f+mr[i];
            next.s=x.s+mc[i];
            if(next.f>=0 && next.f<r && next.s>=0 && next.s<c){
                if(str[next.f][next.s]=='.' && vis[next.f][next.s]==0){
                    level[next.f][next.s]=level[x.f][x.s]+1;
                    vis[next.f][next.s]=1;
                    q.push(next);
                    if(level[next.f][next.s]>maxlen){
                        maxlen=level[next.f][next.s];
                        node=next;
                    }
                }
            }
        }
    }    
}
int main(){
    fio;
    ll t,n,i,j;
    cin>>t;
    while(t--){
        pair<ll,ll>pr;
        cin>>c>>r;
        for(i=0;i<r;i++)
        cin>>str[i];
        for(i=0;i<r;i++){
            for(j=0;j<c;j++){
                if(str[i][j]=='.'){
                    pr=mp(i,j);
                    goto sona;
                }
            }
        }
        sona:;
        BFS(pr);
        //cout<<node.f<<node.s<<" "<<maxlen<<endl;
        BFS(node);
        cout<<"Maximum rope length is "<<maxlen<<"."<<endl;
    }
    return 0;
}