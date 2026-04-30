class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::set<int> m;
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