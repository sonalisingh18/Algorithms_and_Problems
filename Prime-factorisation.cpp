                        >> Prime Factorisation
                          
            >>> Resources:
            
                T-1: https://cp-algorithms.com/algebra/factorization.html
                T-2: https://www.geeksforgeeks.org/prime-factorization-using-sieve-olog-n-multiple-queries/
                
            >>> Implementation:O(N sqrt(N))
    
                int n;
                vector<int> primefactor;
                if(n%2==0)
                {
                    primefactor.push_back(2);
                    while(n%2==0)
                    {
                        n/=2;
                    }
                }
                for(int j=3;j<=sqrt(n);j++)
                {
                    if(n%j==0)
                    {
                        primefactor.push_back(j);
                        while(n%j==0)
                        {
                            n/=j;
                        }
                    }
                }
                if(n>2)
                {
                    primefactor.push_back(n);
                }
                
                
                
                IMPLEMENTATION-2 : O(N log(N)) Useful in case of Integer Factorisation of N numbers.
            
                const int N=10000000;
                int prime[N];
                vector<int> primefact;
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
                void getprimefact(int n)
                {
                    while(n!=1)
                    {
                        primefact.push_back(prime[n]);
                        n/=prime[n];
                    }
                }
                
            >>> Problems:    
            
                Problem-1: https://codeforces.com/problemset/problem/385/C
                Solution : https://codeforces.com/contest/385/submission/87036620
                
                Problem-2: https://codeforces.com/gym/287655/problem/A
                Solution : https://codeforces.com/gym/287655/submission/86968972
                
                Problem-3: https://codeforces.com/contest/1228/problem/C
                Solution : https://codeforces.com/contest/1228/submission/86955216
    
