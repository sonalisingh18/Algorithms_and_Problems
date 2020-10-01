                    >> BIT aka Fenwick tree.
                    
        >>> Resources: 
        
            Tutorial no.1: https://cp-algorithms.com/data_structures/fenwick.html
            Tutorial no.2: https://www.youtube.com/watch?v=CWDQJGaN1gY
            Visualization: https://visualgo.net/bn/fenwicktree?slide=1
        
        >>> Implementation:
        
            const int N=200000;
            int bit[N];
            
            int pres(int idx)
            {
            	int ans=0;
            	while(idx>0)
            	{
            		ans+=bit[idx];
            		idx-=idx&-idx;
            	}
            	return ans;
            }
            
            void update(int idx,int  val,int n)
            {
            	while(idx<=n)
            	{
            		bit[idx]+=val;
            		idx+=idx&-idx;
            	}
            }
            
            int rsm(int l, int r)
            {
            	return pres(r) - pres(l-1);
            }
            
            
        >>> Problems:
        
            Problem-1: https://www.spoj.com/problems/INVCNT/
            Solution : https://pastebin.com/embed_iframe/ZGheLfLF
           
            Problem-2 : https://codeforces.com/contest/1042/problem/D
            Solution: https://codeforces.com/contest/1042/submission/90062975
           
            Problem-3: https://codeforces.com/contest/459/problem/D
            Solution: https://codeforces.com/contest/459/submission/90060302
           
            Problem-4: https://codeforces.com/contest/1401/problem/E
            Solution: https://codeforces.com/contest/1401/submission/90651339
