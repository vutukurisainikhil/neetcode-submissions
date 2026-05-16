class Solution {
   /* Example: heights = [2,1,5,6,2,3]   (sentinel 0 appended → [2,1,5,6,2,3,0])
   Stack stores INDICES.

   i=0 push        stk=[0]
   i=1 pop idx 0   stk=[]      h=2, width=1,         area=2,  max=2
   i=1 push        stk=[1]
   i=2 push        stk=[1,2]
   i=3 push        stk=[1,2,3]
   i=4 pop idx 3   stk=[1,2]   h=6, width=4-2-1=1,   area=6,  max=6
   i=4 pop idx 2   stk=[1]     h=5, width=4-1-1=2,   area=10, max=10
   i=4 push        stk=[1,4]
   i=5 push        stk=[1,4,5]
   i=6 pop idx 5   stk=[1,4]   h=3, width=6-4-1=1,   area=3,  max=10
   i=6 pop idx 4   stk=[1]     h=2, width=6-1-1=4,   area=8,  max=10
   i=6 pop idx 1   stk=[]      h=1, width=6,         area=6,  max=10
   i=6 push        stk=[6]
   Done. Return 10.
*/
public:
    int largestRectangleArea(vector<int>& heights) {
        // Append sentinel 0 to force the stack to flush all remaining bars at the end.
        heights.push_back(0);
        
        stack<int> stk;                // stack of indices with monotonically increasing heights
        int i = 0, n = heights.size(), max_area = 0;
        
        while (i < n) {
            // If current bar is taller than stack top, extend the increasing sequence.
            if (stk.empty() || heights[i] >= heights[stk.top()]) {
                stk.push(i++);
            }
            else {
                // Current bar is shorter — pop the top and compute its max rectangle.
                int popped = stk.top();
                stk.pop();
                
                // Width spans from the new stack top (exclusive) to i (exclusive).
                // If stack is empty, the popped bar extends all the way to the left.
                int width = stk.empty() ? i : i - stk.top() - 1;
                
                max_area = max(max_area, heights[popped] * width);
            }
        }
        return max_area;
    }
};