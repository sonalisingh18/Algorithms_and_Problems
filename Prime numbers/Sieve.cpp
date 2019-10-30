/*
Sonali Singh
Time complexity: O(n*log(log(n)))
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL)
void sieve_of_eratosthenes(int n)
{
    int a[n+1];
    memset(a,0,sizeof(a));
    for(int i=2;i<=sqrt(n);i++)
    {
        if(a[i]==0)
        {
            for(int j=i*i;j<=n;j+=i)
            a[j]=1;
        }
    }
    for(int i=2;i<=n;i++)
    {
        if(a[i]==0)
        cout<<i<<" ";
    }
}
int main()
{
    fio;
    int n;
    cin>>n;
    sieve_of_eratosthenes(n);
    return 0;
}
