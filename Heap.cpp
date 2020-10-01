               >> Heap/Priority_Queue using stl    
        
        >>> Resources:
        
            Tutorial-1:https://www.programiz.com/dsa/priority-queue
        
        
        >>> Implementation:
        
            1.Max heap 
            
            
            priority_queue<int> pq;
            
            
            
            ---
            2.Min heap 
            
            priority_queue<int,vector<int>,greater<int>> pq;
            
            
            ---
            3.Custum Priority Queue 
            
            struct Rectangle 
            {
                //Declare variables u need in your structure.
                
                int width;
                int height;
                
                Rectangle(int width,int height):width(width),height(height)
                {
                    
                }
            };
            
            struct comparator
            {
                bool operator()(Rectangle R1 , Rectangle R2)
                {
                    //write custom comparator function here
                    
                    return R1.width < R2.width;
                }
            };
            
            int main()
            {
                priority_queue<Rectangle, vector<Rectangle>, comparator> pq;
            }
        
        >>> Problems:

            Problem-1(simple):https://www.codechef.com/problems/TSECJ05
            Solution:https://www.codechef.com/viewsolution/33333104
              
            Problem-2(simple):https://www.codechef.com/problems/KSUBSUM
            Solution:https://www.codechef.com/viewsolution/33332409
              
            Problem-3(simple):https://www.codechef.com/problems/RRATING
            Solution:https://www.codechef.com/viewsolution/33332546
  
