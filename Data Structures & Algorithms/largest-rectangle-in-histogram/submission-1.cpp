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
        const int size_h = heights.size();
        stack<int> stk;
        int i = 0, max_area = 0;
        while (i < size_h) {
            if (stk.empty() || heights[i] >= heights[stk.top()])
                stk.push(i++);
            else {
                int h = stk.top();
                stk.pop();
                max_area = max(max_area,
                            heights[h] * (stk.empty() ? i : i - stk.top() - 1));
            }
        }
        return max_area;
    }
};