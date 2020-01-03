#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL)

ll LeftChild(ll i)
{
    return (2*i+1);
}
ll RightChild(ll i)
{
    return (2*i+2);
}

void ShiftDown(ll a[], ll k,ll i)
{
    ll MaxIndex=i;
    ll l=LeftChild(i);
    ll r=RightChild(i);
    if(l<k && a[l]>a[i])
    MaxIndex=l;
    if(r<k && a[r]>a[MaxIndex])
    MaxIndex=r;
    if(i!=MaxIndex)
    {
        swap(a[i],a[MaxIndex]);
        ShiftDown(a,k,MaxIndex);
    }
}

void BuildHeap(ll a[],ll n)
{
    for(ll i=n/2-1;i>=0;i--)
    ShiftDown(a,n,i);
}

void HeapSort(ll a[], ll n)
{
    BuildHeap(a,n);
    for(ll i=n-1;i>=0;i--)
    {
        swap(a[0],a[i]);
        ShiftDown(a,i,0);
    }
}

int main()
{
    fio;
    ll a[]={24,2,31,12,16,6,13,11};
    ll n=sizeof(a)/sizeof(a[0]);
    HeapSort(a,n);
    for(ll i=0;i<n;i++)
        cout<<a[i]<<" ";
    return 0;
}

// Output: 2 6 11 12 13 16 24 31 
