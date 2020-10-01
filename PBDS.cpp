                           >> PBDS (Policy based Data Structure)
    
    >>> Resources :
    
        1. https://codeforces.com/blog/entry/11080 (Sufficient)
        2. https://www.geeksforgeeks.org/ordered-set-gnu-c-pbds/
    
    >>> Implementation 
    
    
        #include <ext/pb_ds/assoc_container.hpp> 
        #include <ext/pb_ds/tree_policy.hpp> 
        using namespace __gnu_pbds; 
        #define o_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update>
    
    
    >>> Operations 
    
        st.order_of_key(x);   // number of elements strictly less than x;
        *st.find_by_order(k); // kth largest element count from 0.
    
    
    >>> Problems:
    
        Problem-1 : https://codeforces.com/contest/1042/problem/D
        
        Problem-2 : https://csacademy.com/contest/round-75/task/race-cars/