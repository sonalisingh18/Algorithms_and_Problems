                            >> String hashing.    
            
            >>> Resources:
            
                Tutorial no. 1: https://cp-algorithms.com/string/string-hashing.html
                Tutorial n0. 2:https://www.quora.com/q/threadsiiithyderabad/String-Hashing-for-competitive-programming
                
            >>> Implementation:
            
                const ll mod=1000000009;
                
                const ll P1=53;
                
                ll powk1[1000000];
                
                ll hash1=0;
                
                void power()
                {
                    ll flag=1;
                
                    for(ll i=0;i<1000000;i++)
                    {
                        powk1[i]=flag;
                        flag=flag*P1;
                        flag=flag%mod;
                    }
                }
                
                /*hash calculation.*/
                void hashing(string s)
                {
                   ll hash1=0;
                
                   ll j=0;
                   for(auto c:s)
                   {
                       hash1=(hash1+((c-'a'+1)*powk1[j]))%mod;
                       j++;
                   }
                }

            >>> Problems: 
 
                Problem-1 : https://www.codechef.com/problems/CHEFSHIP/
                Solution  : https://www.codechef.com/viewsolution/33331757
                 
                Problem-2 : https://www.codechef.com/problems/CONVSTR/
                Solution  : https://www.codechef.com/viewsolution/33539615
