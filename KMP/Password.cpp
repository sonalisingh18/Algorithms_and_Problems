/*Sonali Singh
question link: https://codeforces.com/contest/126/problem/B
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
int main()
{
    fio;
    string s;
    cin>>s;
    ll l=s.length();
    ll lps[l+1];
    ll maxx=0;
    ll j=0;
    lps[0]=0;
    for(int i=1;i<l;i++)
    {
        while(j>0&&s[i]!=s[j])
            j=lps[j-1];
        if(s[i]==s[j])
            j++;
        lps[i] = j;
        if(i!=l-1)
            maxx = max(maxx, lps[i]);
    }
    //for(int i=0;i<l;i++)
    //cout<<lps[i]<<" ";
    //cout<<endl;
    int ans = lps[l-1];
    if(ans>maxx)
        ans = lps[ans-1];
    if(ans)
        cout<<s.substr(0, ans)<<endl;
    else
        cout<<"Just a legend"<<endl;
    return 0;
}
