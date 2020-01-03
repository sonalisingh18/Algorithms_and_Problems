// By default C++ creates a max-heap 
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL)

void show_q(priority_queue <ll> q)
{
    priority_queue <ll> a=q;
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
    priority_queue <ll> q;
    q.push(3);
    q.push(2);
    q.push(15);
    q.push(5);
    q.push(4);
    q.push(25);
    show_q(q);                                    // 25 15 5 4 3 2 
    cout<<q.top()<<endl;                          // 25
    cout<<q.size()<<endl;                         // 6
    q.pop(); 
    show_q(q);                                    // 15 5 4 3 2
    priority_queue <ll> p;
    p.push(24);
    p.push(12);
    p.push(31);
    p.push(16);
    p.push(13);
    show_q(p);                                    // 31 24 16 13 12 
    q.swap(p);
    show_q(q);                                    // 31 24 16 13 12 
    show_q(p);                                    // 15 5 4 3 2
    return 0;
}
