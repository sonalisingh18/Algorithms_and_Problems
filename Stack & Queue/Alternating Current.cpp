/*
  Sonali Singh
  Question link: https://codeforces.com/contest/343/problem/B
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
    string s;
    stack<char>st;
    cin>>s;
    ll l=s.length();
    for(ll i=0;i<l;i++){
        if(st.empty())
        st.push(s[i]);
        else{
            if(st.top()==s[i])
                st.pop();
            else
                st.push(s[i]);
        }
    }
    if(st.empty())
    cout<<"Yes"<<endl;
    else
    cout<<"No"<<endl;
    return 0;
}
