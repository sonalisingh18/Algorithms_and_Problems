#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL)
ll h[1000000],size;

ll Parent(ll i)
{
    return ((i-1)/2);
}
ll LeftChild(ll i)
{
    return (2*i+1);
}
ll RightChild(ll i)
{
    return (2*i+2);
}

void ShiftUp(ll i)
{
    while(i!=0 && h[Parent(i)]<h[i])
    {
        swap(h[i],h[Parent(i)]);
        i=Parent(i);
    }
}
void ShiftDown(ll i)
{
    ll maxIndex=i;
    ll l=LeftChild(i);
    if(l<size && h[l]>h[maxIndex])
    maxIndex=l;
    ll r=RightChild(i);
    if(r<size && h[r]>h[maxIndex])
    maxIndex=r;
    if(i!=maxIndex)
    {
        swap(h[i],h[maxIndex]);
        ShiftDown(maxIndex);
    }
}
ll ExtractMax()
{
    ll result=h[0];
    h[0]=h[size-1];
    size-=1;
    ShiftDown(0);
    return result;
}
ll GetMax()
{
    return h[0];
}

void InsertKey(ll x)
{
    h[size]=x;
    size+=1;
    ShiftUp(size-1);
}
void ChangePriority(ll i, ll p)
{
   ll oldp= h[i];
   h[i]=p;
   if(p>oldp)
   ShiftUp(i);
   else
   ShiftDown(i);
}
void DeleteKey(ll i)
{
    h[i]=INT_MAX;
    ShiftUp(i);
    ExtractMax();
}

int main()
{
    ll size=0;
    InsertKey(8);
    //          8
    
    InsertKey(5);
    //          8                
    //         /        
    //        5         
    
    InsertKey(24);
    //          8                  24
    //         / \       -->      /  \
    //        5   24             5    8
    
    DeleteKey(1);
    //          24                 ∞                 8             24
    //         /  \      -->      / \      -->      /      -->     /
    //        ∞    8             24  8             24             8
    
    InsertKey(15); 
    //          24                
    //         /  \        
    //        8    15 
    
    InsertKey(4);
    //          24                
    //         /  \        
    //        8    15
    //       /
    //      4
    
    InsertKey(10); 
    //          24                   24
    //         /  \                 /  \
    //        8    15    -->       10   15  
    //       / \                  /  \
    //      4   10               4    8
    
    ChangePriority(3,50);
    //          24                   24                   50
    //         /  \                 /  \                 /  \
    //        10   15    -->       50   15      -->     24   15
    //       /  \                 /  \                 /  \
    //      50   8               10   8               10   8
    
    cout << GetMax() << " "; 
    
    cout << ExtractMax() << " "; 
    //          8                    24                   24
    //         / \                  /  \                 /  \
    //        24  15     -->       8    15      -->     10   15
    //       /                    /                    /
    //      10                   10                   8
    
    cout << ExtractMax() << " ";
    //          8                  15
    //         / \       -->      /  \
    //        10  15             10   8
    
    cout << ExtractMax() << " ";
    //          8                  10
    //         /         -->      /          
    //        10                 8
    
    cout << ExtractMax() << " ";
    //          8
    
    cout << GetMax(); 
    
    //  output:  50 50 24 15 10 8
   return 0;
}
