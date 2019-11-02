/*
Sonali Singh
*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
ll editdistance(string s1, string s2){
    ll m=s1.size();
    ll n=s2.size();
    vector<vector<ll>>DP(m+1,vector<ll>(n+1));
    for(ll i=0;i<=m;i++){
        for(ll j=0;j<=n;j++){
            if(i==0)
                DP[i][j]=j;
            else if(j==0)
                DP[i][j]=i;
            else if(s1[i-1]==s2[j-1])
                DP[i][j]=DP[i-1][j-1];
            else{
                DP[i][j]=1+min(min(DP[i-1][j],DP[i][j-1]),DP[i-1][j-1]);
            }
        }
    }
    return DP[m][n];
}
int main()
{
    fio;
    string s1,s2;
    cin>>s1>>s2;
    cout<<editdistance(s1,s2);
    return 0;
}
