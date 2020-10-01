                        >> Rolling hash.
            
            >>> Resources:
                Tutorial: https://codeforces.com/blog/entry/60445
                Tips : Look at the code do some paper work you will get the idea behind the Algorithm.
            
            >>> Implementation:
            
                const ll mod=1000000009;
                
                const ll P1=53;
                
                ll powk[2000000];
                ll has[2000000];
                
                void power()
                {
                   powk[0]=1;
                   for(ll i=199994;i>=0;i--)
                   {
                       powk[199995-i]=(powk[199995-i-1]*P1)%mod;
                   }
                }
                
                void hashing(string s)
                {
                   ll n=s.length();
                   for(ll i=n-1;i>=0;i--)
                   {
                       has[i]=((has[i+1]*P1)%mod+(s[i]-'a'+1))%mod;
                   }
                }
                
                ll subs(ll l,ll r)
                {
                   return (mod-(has[r+1]*powk[r-l+1])%mod+has[l])%mod; 
                }

            >>> Problems :
            
                Problem-1: https://www.spoj.com/problems/ADACLEAN/
                Solution : https://pastebin.com/embed_iframe/ZKQ7fZ4j
