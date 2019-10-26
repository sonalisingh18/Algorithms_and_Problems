/*Sonali Singh
#Codechef
#recursion
question link: https://www.codechef.com/problems/NOKIA
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);
int find_min(ll n)
{
  ll ans;
  if(n<1)
  return 0;
  else
  {
      ans=n+1+find_min(n/2)+find_min(n-1-n/2);
      return ans;
  }
}
int main()
{
    fio;
    ll t,n,m,max,min,ans;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        max=(n*(n+3))/2;
        min=find_min(n);
        if(m<min)
        cout<<"-1"<<endl;
        else if(m>max)
        cout<<m-max<<endl;
        else
        cout<<"0"<<endl;
    }
    return 0;
}