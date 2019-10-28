/*Sonali Singh
#kmp
question link: https://www.spoj.com/problems/NHAY/
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL)
void kmp(string needle,int m,string haystack,int n,int* lps)
{
    int i=0,j=0;
    while(i<n)
    {
        if(needle[j]==haystack[i])
        {
            j++;
            i++;
        }
        if(j==m)
        {
            if((i-j)!=0)
            cout<<i-j<<endl;
            j=lps[j-1];
        }
        else if(i<n && needle[j]!=haystack[i])
        {
            if(j!=0)
            j=lps[j-1];
            else
            i++;
        }
    }
}
void lps_array(string niddle,int m,int* lps)
{
    int l=0,i=1;
    lps[0]=0;
    while(i<m)
    {
        if(niddle[i]==niddle[l])
        {
            l++;
            lps[i]=l;
            i++; 
        }
        else
        {
            if(l!=0)
            {
                l=lps[l-1];
            }
            else
            {
                lps[i]=0;
                i++;
            }
        }
    }
}
int main()
{
    fio;
    int n;
    string needle,haystack;
    while(cin>>n)
    {
        cin>>needle>>haystack;
        int m=needle.size();
        int n=haystack.size();
        int lps[m];
        lps_array(needle,m,lps);
        kmp(needle,m,haystack,n,lps);
        cout<<endl;
    }
    return 0;
}
