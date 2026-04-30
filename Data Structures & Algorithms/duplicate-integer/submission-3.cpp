class Solution {
public:
    // Timecomplexity: 0(1), as unordered_set - insert,find is O(1)
    bool hasDuplicate(vector<int>& nums) {
        std::unordered_set<int> m;
        if(nums.empty()){
            return false;
        }
        m.insert(nums[0]);
        for(int i=1;i<nums.size();i++){
            if(m.find(nums[i]) == m.end()){
                m.insert(nums[i]);
            }
            else{
                return true;
            }
        }
        return false;
    }
};