/*
Sonali Singh
question link: https://www.spoj.com/problems/HISTOGRA/
*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL)
int main(){
    fio;
    ll n,x,i;
    stack<ll>st;
    while(1)
    {
        ll c=0;
        cin>>n;
        if(n==0)
        break;
        ll a[n];
        for(ll i=0;i<n;i++)
            cin>>a[i];
        ll maxarea=0;
        ll area=0;
        ll t;
        i=0;
        while(i<n){
            if(st.empty() || a[st.top()]<=a[i]){
                st.push(i);
                i++;
            }
            else{
                t=st.top();
                st.pop();
                if(st.empty())
                    area=a[t]*i;
                else
                    area=a[t]*(i-st.top()-1);
                if(area>maxarea)
                maxarea=area;
            }
        }
        while(!st.empty()){
            t=st.top();
            st.pop();
            if(st.empty())
                area=a[t]*i;
            else
                area=a[t]*(i-st.top()-1);
            if(area>maxarea)
                maxarea=area;
        }
        cout<<maxarea<<" "<<endl;
    }
    return 0;
} 
