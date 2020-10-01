                                >> Z's Algorithm 
    >>> Resources :
    
    1.  https://www.youtube.com/watch?v=CpZh4eF8QBw
    2.  https://cp-algorithms.com/string/z-function.html
                                
                                
    >>> Implementation :
    
    void pre(string s,ll *z)
    {
        ll n=s.size();
        z[0]=0;
        ll l=0;
        ll r=0;
        for(ll i=1;i<n;i++)
        {
            if(i>r)
            {
                l=i;
                r=i;
                
                while(r<n and s[r]==s[r-l])
                {
                    r++;
                }
                
                z[i]=r-l;
                r--;
            }
            else
            {
                ll k=i-l;
                if(z[k]+i<=r)
                {
                    z[i]=z[k];
                }
                else
                {
                    l=i;
                    
                    while(r<n and s[r]==s[r-l])
                    {
                        r++;
                    }
                    
                    z[i]=r-l;
                    r--;
                    
                }
            }
        }
    }
    ll Z(string s1,string s2)
    {
        string s3=s1+"!"+s2;
        ll l=s3.size();
        ll z[l];
        pre(s3,z);
        ll c=0;
        for(ll i=0;i<l;i++)
        {
            if(z[i]==s1.size())
            {
                c++;
            }
        }
        return c;
    }
    
    
    >>> Problems:
        
        Problem-1: http://codeforces.com/problemset/problem/127/D
        Problem-2: http://codeforces.com/contest/432/problem/D
    