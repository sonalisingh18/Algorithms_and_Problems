/*
Sonali Singh
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL)
void simple_sieve(vector<int> &prime,int limit)
{
    bool isprime[limit+1];
    memset(isprime,false,sizeof(isprime));
    for(int i=2;i<=sqrt(limit);i++)
    {
        if(isprime[i]==0)
        {
            for(int j=i*i;j<limit;j+=i)
                isprime[j]=true;
        }
    }
    for(int i=2;i<limit;i++)
    {
        if(!isprime[i])
        {
            prime.push_back(i);
            cout<<i<<" ";
        }
       // cout<<endl;
    }
}
void segmented_sieve(int n)
{
    int limit=floor(sqrt(n))+1;
    vector<int>prime;
    simple_sieve(prime,limit);
    int low =limit;
    int high= 2*limit;
    while(low<n)
    {
        if(high>n)
        high=n;
        bool isprime[limit+1];
        memset(isprime,false,sizeof(isprime));
        for(int i=0;i<prime.size();i++)
        {
            int base=floor(low/prime[i])*prime[i];
            if(base<low)
            base=base+prime[i];
            for(int j=base;j<high;j+=prime[i])
            isprime[j-low]=true;
        }
        for(int i=low;i<high;i++)
        {
            if(!isprime[i-low])
            cout<<i<<" ";
        }
        low=low+limit;
        high=high+limit;
    }
}
int main()
{
    fio;
    int n;
    cin>>n;
    segmented_sieve(n);
    return 0;
}
