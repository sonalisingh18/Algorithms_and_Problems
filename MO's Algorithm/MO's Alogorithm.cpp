// Written by Dheeraj Maurya
// Btech CSE IET LUCKNOW (2018 - 2022)
// MO's Algorithm
// problem name:Powerful array
// problem Link: https://codeforces.com/contest/86/problem/D

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 200005 ,block=500;
ll arr[N] ,ans[N],cnt=0,vis[N*5];

bool cmp(pair<ll,pair<ll,ll>> &a,pair<ll,pair<ll,ll>> &b){
   if(a.second.first/block==b.second.first/block) return (a.second.second<b.second.second);
   return (a.second.first < b.second.first);
}

void add(ll v){
   cnt  -= v*vis[v]*vis[v];
   ++vis[v];
   cnt  += v*vis[v]*vis[v];
}

void subtract(ll v){
   cnt  -= v*vis[v]*vis[v];
   --vis[v];
   cnt  += v*vis[v]*vis[v];
}

int main(){
   ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
   ll t,n,i,j,q;
   cin>>n>>q;
   memset(vis,0,sizeof(vis));

//    INPUT : 3 2
//           1 2 1
//           1 2
//           1 3

   for(i=1;i<=n;i++) cin>>arr[i];


   vector<pair<ll,pair<ll,ll>>> v(q);
   for(i=0;i<q;i++){
      cin>>v[i].second.first>>v[i].second.second;  v[i].first =i+1;
   }   
   sort(v.begin(),v.end(),cmp);
   ll l = 1 , r = 0;
   for(auto k:v){
      ll left = k.second.first ,right =k.second.second ,id = k.first;
      while(l<left) { subtract(arr[l]); ++l; }
      while(l>left) { --l; add(arr[l]); }
      while(r<right){ ++r; add(arr[r]); }
      while(r>right){ subtract(arr[r]); --r; }
      ans[id] = cnt;
   }
   for(i=1;i<=q;i++) cout<<ans[i]<<"\n";

//    OUTPUT : 3
//             6
}