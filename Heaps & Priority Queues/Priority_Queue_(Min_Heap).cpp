#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL)

void show_q(priority_queue <ll, vector<ll>, greater<ll>> q)
{
    priority_queue <ll, vector<ll>, greater<ll>> a=q;
    while(!a.empty())
    {
        cout<<a.top()<<" ";
        a.pop();
    }
    cout<<endl;
}

int main()
{
    fio;
    priority_queue <ll, vector<ll>, greater<ll>> q;
    q.push(3);
    q.push(2);
    q.push(15);
    q.push(5);
    q.push(4);
    q.push(25);
    show_q(q);                                    // 2 3 4 5 15 25  
    cout<<q.top()<<endl;                          // 2
    cout<<q.size()<<endl;                         // 6
    q.pop(); 
    show_q(q);                                    // 3 4 5 15 25 
    return 0;
}
