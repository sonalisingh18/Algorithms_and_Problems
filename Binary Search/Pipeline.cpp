/* 
Sonali Singh
Question link: https://codeforces.com/contest/287/problem/B
*/
 
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL)
int main()
{  
    fio;
    ll n,k,sum=1,c=0,s,i,l,r,upper,lower,mid;
    cin>>n>>k;
    s=(k*(k-1))/2;
    if(n>s+1)
    cout<<"-1"<<endl;
    else{
        l=0,r=k;
        while(1){
            mid=(l+r)/2;
            upper=((mid*(2*k-mid-1))/2 )+ 1;
            lower=upper-(k-mid);
            if(n==upper || (n<upper && n>lower))
            break;
            else if(n>upper)
            l=mid;
            else
            r=mid;
        }
        cout<<mid<<endl;
    }
    return 0;
}
