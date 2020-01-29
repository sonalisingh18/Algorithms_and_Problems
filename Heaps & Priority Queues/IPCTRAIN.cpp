/* 
 Sonali Singh
 Question link: https://www.codechef.com/problems/IPCTRAIN
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

struct trainer{
    ll D,T,S;
};

trainer tr[1000000];
bool comp(trainer a,trainer b){
    return a.D < b.D;
}

int main(){
    fio;
    ll t,n,d,i;
    cin>>t;
    while(t--)
    {
        cin>>n>>d;
        for(i=1;i<=n;i++)
        cin>>tr[i].D>>tr[i].T>>tr[i].S;
        sort(tr+1,tr+n+1,comp);
        priority_queue< pair<ll,ll>, vector<pair<ll,ll>> > pq;
        ll k=1;
        for(i=1;i<=d;i++){
            while(k<=n && tr[k].D==i){
                pq.push({tr[k].S, k});
                k++;
            }
            while(!pq.empty() && !tr[(pq.top()).second].T){
                pq.pop();
            }
            if(!pq.empty()){
                tr[(pq.top()).second].T--;
            }
        }
        ll sadness=0;
        for(i=1;i<=n;i++)
        sadness+= (tr[i].T * tr[i].S);
        cout<<sadness<<endl;
    }
    return 0;
}
