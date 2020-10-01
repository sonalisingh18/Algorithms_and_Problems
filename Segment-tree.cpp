                        >> Segment tree
            
            >>> Resources:
            
                Tutorial no. 1: https://cp-algorithms.com/data_structures/segment_tree.html
                Tutorial no. 2: https://www.geeksforgeeks.org/segment-tree-set-1-sum-of-given-range/
                Visualization : https://visualgo.net/bn/segmenttree?slide=1

            >>> Implementation:
            
                int tr[1000000];
                int lazy[1000000];
                
                /*push function.*/
                void push(int v)
                {
                	/*write your custom function.*/
                	if(!lazy[v])
                	{
                		
                	}
                }
                
                /*preparing lazy and tree.*/
                void init(int l,int r,int v)
                {
                	/*write down your custum code.*/
                	if(l==r)
                	{
                		tr[v]=arr[l];
                	}
                	else
                	{
                		int mid=(l+r)/2;
                		init(l,mid-1,2*v+1);
                		init(mid+1,r,2*v+2);
                		
                	}
                }
                
                /*for update.*/
                void update(int l,int r,int v,int l1,int r1,int val)
                {
                	/*write down your custom code.*/
                	if(l1>r1)
                	{
                		return ;
                	}
                    if(l==l1 and r==r1)
                	{
                		
                	}
                	else
                	{
                	   push(v);
                	   int mid=(l+r)/2;
                	   update(l,mid-1,2*v+1,l1,min(mid-1,r1),val);
                	   update(r,mid+1,2*v+2,max(mid+1,l1),r1,val);
                	}
                	
                }
                
                /*for query*/
                int query(int l,int r,int v,int l1,int r1)
                {
                	/*write down your custom code.*/
                	if(l1>r1)
                	{
                		
                	}
                	if(l==l1 and r==r1)
                	{
                        return tr[v];
                	}
                	else
                	{
                		int mid=(l+r)/2;
                		ll val=query(l,mid-1,2*v+1,l1,min(r1,mid-1));
                		ll val1=query(mid+1,r,2*v+2,max(l1,mid+1),r1);
                	}
                	
                }

