class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
      std::vector<int> prod(nums.size(),1);
      int p = 1;
      for(int i=0;i<nums.size();i++){
        prod[i] *= p;
        p *= nums[i]; 
      }

      p = 1;
      for(int i=nums.size()-1;i>=0;i--){
        prod[i] *= p;
        p *= nums[i];
      }
      return prod;
    }
};
