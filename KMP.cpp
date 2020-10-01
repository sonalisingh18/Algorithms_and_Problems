                            >> KMP (String pattern searching) 
                                
        >>> Resources:
        
            1 : https://www.topcoder.com/community/competitive-programming/tutorials/introduction-to-string-searching-algorithms/
            2 : https://www.geeksforgeeks.org/kmp-algorithm-for-pattern-searching/

        >>> Implementation:

            void prearr(string s1,ll *lps)
            {
                lps[0]=0;
                ll m=s1.length();
                ll j=1,l=0;
                while(j<m)
                {
                    if(s1[j]==s1[l])
                    {
                        l++;
                        lps[j]=l;
                        j++;
                    }
                    else
                    {
                        if(l>0)
                        {
                            l=lps[l-1];
                        }
                        else
                        {
                            lps[j]=0;
                            j++;
                        }
                    }
                }
            }
            
            
            ll patt(string s1,string s2)
            {
                ll m=s1.length();
                ll n=s2.length();
                ll lps[m];
                prearr(s1,lps);
                ll freq=0;
                ll i=0,j=0;
                while(i<n)
                {
                    if(s1[j]==s2[i])
                    {
                        i++;
                        j++;
                    }
                    else
                    {
                        if(j>0)
                        {
                            j=lps[j-1];
                        }
                        else
                        {
                            i++;
                        }
                    }
                    if(j==m)
                    {
                        freq++;
                        j=lps[j-1];
                    }
                }
                return freq;
            }

        >>> Problems:
        
            Problem-1: https://codeforces.com/contest/1379/problem/A
            Solution : https://codeforces.com/contest/1379/submission/87306803
           
            Problem-2:  https://www.codechef.com/CENS2020/problems/CENS20C
            Solution : https://www.codechef.com/viewsolution/37013566
