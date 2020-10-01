                           >> Sieve 
                           
        >>> Resources:
            
            T-1: https://www.geeksforgeeks.org/sieve-of-eratosthenes/
            
            
        >>> Implementation:
        
            const ll N=1000000;
            ll prime[N];
            void pre()
            {
                for(ll i=0;i<N;i++)
                {
                    prime[i]=true;
                }
            	for(ll i=2;i<=sqrt(N);i++)
            	{
            		if(prime[i])
            		{
        				for(ll j=i*i;j<N;j+=i)
        				{
        					prime[j]=false;
        				}
            		}
            	}
            }