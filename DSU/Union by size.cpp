#include<bits/stdc++.h>
#define ll long long int
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;

ll parent[100000], size[100000];

void MakeSet(){
    for(ll i=1;i<=10;i++){
        parent[i]=i;
        size[i]=1;
    }
}

ll Find(ll i){
    while(i!=parent[i])
        i=parent[i];
    return i;
}

void Union(ll i, ll j){
    ll i_id=Find(i);
    ll j_id=Find(j);
    if(i_id==j_id)
        return;
    if(size[i_id]>size[j_id]){
        parent[j_id]=i_id;
        size[i_id]+=size[j_id];
    }
    else{
        parent[i_id]=j_id;
        size[j_id]+=size[i_id];
    }
}

int main()
{
    fio;
    MakeSet();
    Union(1,2);
    Union(3,4);
    Union(1,9);
    Union(5,6);
    Union(3,7);
    Union(4,6);
    Union(2,4);
    for(ll i=1;i<=10;i++)
    {
        cout<<"Node:"<<i<<" "<<"Parent:"<<parent[i]<<" "<<"Size:"<<size[i]<<endl;
    }
    return 0;
}

/*
OUTPUT                                                  4             8        10
Node:1 Parent:2 Size:1                                / /\ \
Node:2 Parent:4 Size:3                               / /  \ \
Node:3 Parent:4 Size:1                              /  |  |  \
Node:4 Parent:4 Size:8                             2   3  7   6
Node:5 Parent:6 Size:1                            / \         |
Node:6 Parent:4 Size:2                           1   9        5
Node:7 Parent:4 Size:1
Node:8 Parent:8 Size:1
Node:9 Parent:2 Size:1
Node:10 Parent:10 Size:1
*/
