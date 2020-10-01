                    >> ETF
                    
        >>> Resources:            
        
            T-1: https://cp-algorithms.com/algebra/phi-function.html
            T-2: https://www.geeksforgeeks.org/eulers-totient-function/
        
        
        
        >>> Implementation:
        
            int eulerphi(int n) 
            {
                int ans=n;
                for(int i=2;i*i<=n;i++) 
                {
                    if(n%i==0) 
                    {
                        while(n%i==0)
                        {
                            n/=i;
                        }
                        ans-=ans/i;
                    }
                }
                if(n>1)
                {
                    ans-=ans/n;
                }
                return ans;
            }
            
            
            IMPLEMENTATION-2 : Complexity: n log(log(n)) for n numbers with precomputation.
            
            
            const int N=2000000;
            int prime[N+1];
            void precompute()
            {
                for(int i=0;i<N;i++)
                {
                    prime[i]=i;
                }
                for(int i=2;i<N;i+=2)
                {
                    prime[i]=2;
                }
                for(int i=3;i<=sqrt(N);i++)
                {
                    for(int j=i*i;j<N;j+=i)
                    {
                        if(prime[j]==j)
                        {
                            prime[j]=i;
                        }
                    }
                }
            }
            
            int  eulerphi(int n)
            {
                int ans=n;
                while(n!=1)
                {
                    int val=prime[n];
                    while(n%val==0)
                    {
                        n/=val;
                    }
                    ans-=ans/val;
                }
                return ans;
            }
        
        
        >>> Problems :
        
            Problem-1: https://www.spoj.com/problems/ETF/
            Solution : https://pastebin.com/embed_iframe/tZBJpzL6
        
