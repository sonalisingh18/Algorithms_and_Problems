                    >> SCC (strongly connected component)
        
        >>> Resources:             
                     
            Tutorial no.1: https://cp-algorithms.com/graph/strongly-connected-components.html
            Tutorial no.2: https://www.youtube.com/watch?v=RpgcYiky7uw
    
    
        >>> Implementation:
    
            const ll N=200000;
            vector<ll> adj[N],revadj[N],scc[N];
            stack<ll> st;
            bool vis[N];
            
            void dfs(ll v)
            {
                vis[v]=true;
                for(auto i:adj[v])
                {
                    if(!vis[i])
                    {
                        dfs(i);
                        st.push(i);
                    }
                }
                
            }
            
           
            void dfs1(ll v,ll s)
            {
                vis[v]=true;
                for(auto i:revadj[v])
                {
                    if(!vis[i])
                    {
                        dfs1(i,s);
                        scc[s].pb(i);
                    }
                }
                
            }
            
           
            for(ll i=0;i<m;i++)
            {
                ll x,y;
                cin>>x>>y;
                adj[x].pb(y);
                revadj[y].pb(x);
            }
            
            
            for(ll i=1;i<=n;i++)
            {
                if(!vis[i])
                {
                    dfs(i);
                    st.push(i);
                }
            }
            
            
            while(st.size())
            {
                if(!vis[st.top()])
                {
                    dfs1(st.top(),st.top());
                }
                else
                {
                    st.pop();
                }
            }
    
    
        >>> Problems:
    
            Problem-1: https://codeforces.com/problemset/problem/427/C
            Solution : https://codeforces.com/contest/427/submission/86796090
    
