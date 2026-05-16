class Solution {
public:
    // Greedy BFS-by-levels: each "jump" expands to the max reachable index
    // among all positions in the current jump's range.
    // Time: O(n), Space: O(1).
    int jump(vector<int>& nums) {
        int res = 0 , currmax = 0 , reach = 0;
        for(int index = 0 ; index < nums.size() - 1 ; index++)
        {
            // finding the max reach possible.
            currmax = max(currmax, nums[index] + index);
            
            // if found, then its a single jump, but inital jump is counted as one jump.
            if(index == reach)
            {
                res++;
                reach = currmax;
            }
        }
        return res;
    }
};