/*
  Sonali Singh
  Question link: https://www.codechef.com/problems/ANUMLA
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
    ll t,n,m,i,j,sz;
    cin>>t;
    while(t--){
        cin>>n;
        m=1<<n;
        ll a[m];
        for(i=0;i<m;i++)
        cin>>a[i];
        sort(a,a+m);
        vector<ll>v,ans;
        priority_queue<ll,vector<ll>,greater<ll>>q;
        v.pb(0);
        for(i=1;i<m;i++){
            if(q.empty() || q.top()>a[i]){
                ans.pb(a[i]);
                sz=v.size();
                v.pb(a[i]);
                for(j=1;j<sz;j++){
                    v.pb(v[j]+a[i]);
                    q.push(v[j]+a[i]);
                }
            }
            else
            q.pop();
            if(ans.size()==n)
            break;
        }
        for(i=0;i<n;i++)
        cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}
