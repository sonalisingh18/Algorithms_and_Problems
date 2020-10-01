                            >> Trie
                            
            >>> Resources:
            
                T-0: https://leetcode.com/discuss/general-discussion/680706/article-on-trie-general-template-and-list-of-problems(best)
                T-1: https://www.quora.com/q/threadsiiithyderabad/Tutorial-on-Trie-and-example-problems
                T-2: https://www.techiedelight.com/cpp-implementation-trie-data-structure/
                T-3: https://www.youtube.com/watch?v=-urNrIAQnNo&t=55s
                
            >>> Implementation:    

                typedef struct box
                {
                    int cnt = 0;
                	box* bit[2];
                	
                }trie;
                
                trie* root;
                
                void erase(int x)
                {
                	trie* cur = root;
                	
                	for(int i=30;i>=0;i--)
                	{
                		int b = x/(ll)pow(2,i) & 1;
                		
                		cur = cur->bit[b];
                		
                		cur->cnt--;
                	}
                }
                
                void insert(int x)
                {
                	trie* cur = root;
                	
                	for(int i=30;i>=0;i--)
                	{
                		int b = x/(ll)pow(2,i) & 1;
                	
                		if(!cur->bit[b])
                		{
                			cur->bit[b] = new trie();
                		}
                		
                		cur = cur->bit[b];
                		cur->cnt++;
                	}
                }
                
                int minxor(int x)
                {
                        int ans = 0;
                	trie* cur = root;
                	for(int i=30;i>=0;i--)
                	{
                		int b = x/(ll)pow(2,i) & 1;
                
                		if(cur->bit[b] && cur->bit[b]->cnt>0)
                		{
                			cur = cur->bit[b];
                		}
                		else
                		{
                		    ans+=(ll)pow(2,i);
                		    cur = cur->bit[!b];
                		}
                	}
                	return ans;
                }
                
                int maxxor(int x)
                {
                    int ans = 0;
                    
                	trie* cur = root;
                	
                	for(int i=30;i>=0;i--)
                	{
                		int b = x/(ll)pow(2,i) & 1;
                		
                		if(cur->bit[!b] && cur->bit[!b]->cnt)
                		{
                			ans += (ll)pow(2,i);
                			
                			cur = cur->bit[!b];
                		}
                		else
                		{
                			cur = cur->bit[b];
                		}
                	}
                	return ans;
                }

            >>> Problems:
 
                Problem-1: https://codeforces.com/contest/948/problem/D
                Solution : https://codeforces.com/contest/948/submission/87281347
               
                Problem-2: https://codeforces.com/contest/706/problem/D
                Solution : https://codeforces.com/contest/706/submission/87276298
