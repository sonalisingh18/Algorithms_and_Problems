#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL)
int main()
{
    fio;
    vector<ll>v={3,2,15,5,4,25};
    make_heap(v.begin(),v.end());
    for(auto it=v.begin();it!=v.end();it++)
    cout<<*it<<" ";                                       // 25 5 15 2 4 3
    cout<<endl;
    cout<<v.front()<<endl;                                // 25    
    v.push_back(31);
    push_heap(v.begin(),v.end());
    for(auto it=v.begin();it!=v.end();it++)
    cout<<*it<<" ";                                       // 31 5 25 2 4 3 15
    cout<<endl;
    cout<<v.front()<<endl;                                // 31
    pop_heap(v.begin(),v.end());
    v.pop_back();
    for(auto it=v.begin();it!=v.end();it++)
    cout<<*it<<" ";                                       // 25 5 15 2 4 3
    cout<<endl;
    sort_heap(v.begin(),v.end());
    for(auto it=v.begin();it!=v.end();it++)
    cout<<*it<<" ";                                       // 2 3 4 5 15 25
    cout<<endl;
    is_heap(v.begin(),v.end())?cout<<"YES":cout<<"NO";    // NO
    cout<<endl;
    return 0;
}
