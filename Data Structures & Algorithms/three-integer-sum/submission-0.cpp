class Solution {
public:
    /*
    unique triplets occurs, if we sort array first anf then to find triplets.
    */
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        int target=0;
        
        sort(nums.begin(), nums.end());
        
        vector<vector<int>> res;
        for(int i = 0; i < n; i++)
        {   // while first occurance alone, we will find triplets, so we need to skip next occurance if nums[i]==nums[i-1];
            if(i > 0 and nums[i] == nums[i - 1]) continue;
            
            int target2sum = target - nums[i];
            // with 2 pointers algorithm, we are going to find the sorted triplets.
            int start = i + 1;
            int end = n - 1;
            while(start < end)
            {
                int sum2 = nums[start] + nums[end];
                if(sum2 < target2sum or (start > i + 1 and nums[start] == nums[start - 1]))
                    start++;
                else if(sum2 > target2sum or (end < n - 1 and nums[end] == nums[end + 1]))
                    end--;
                else
                {
                    res.push_back({nums[i], nums[start], nums[end]});
                    start++;
                    end--;
                }
            }
        }
        
        return res;
    }
};