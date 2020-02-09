/*
  Sonali Singh
  Question link: https://www.codechef.com/problems/TSECJ05
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
    ll t,k,n,i,x;
    cin>>t;
    while(t--){
        cin>>k>>n;
        priority_queue<ll, vector<ll>, greater<ll>>q;
        ll j=1;
        for(i=1;i<=n;i++){
            cin>>x;
            if(i<k)
            {
                q.push(x);
                cout<<"-1"<<" ";
            }
            else{
                if(i==k)
                q.push(x);
                else if(x>q.top()){
                    q.push(x);
                    q.pop();
                }
                cout<<q.top()<<" ";
            }
            
        }
        cout<<endl;
    }
    return 0;
}
