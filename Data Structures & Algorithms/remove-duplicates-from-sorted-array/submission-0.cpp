class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int real_index = 0;
        for(int i =1 ;i<nums.size();i++){
            if(nums[real_index] !=nums[i]){
                nums[++real_index] = nums[i];
            }
        }
        return real_index+1;
    }
};