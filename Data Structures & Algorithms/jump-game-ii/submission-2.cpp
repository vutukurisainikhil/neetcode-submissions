class Solution {
public:
    int jump(vector<int>& nums) {
        int res = 0 , curr_reach = 0 , reach = 0;
        for(int index = 0 ; index < nums.size() - 1 ; index++)
        {
            // finding the max reach possible.
            curr_reach = max(curr_reach, nums[index] + index);
            
            // if found, then its a single jump, but inital jump is counted as one jump.
            if(index == reach)
            {
                res++;
                reach = curr_reach;
            }
        }
        return res;
    }
};