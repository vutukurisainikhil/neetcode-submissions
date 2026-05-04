class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> LIS(nums.size(), 1);

        for (int i = 1; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j] && (LIS[i] < LIS[j]+1)) {
                    LIS[i] = 1 + LIS[j];
                }
            }
        }
        return *max_element(LIS.begin(), LIS.end());
    }
};
/**
class Solution {
public:
    // TimeComplexity - O(nlogn) as we use loop + binary search O(logn) where as DP LIS takes O(n^2).
    //  Space Complexity - O(n)    

    // 1. create a new array(res), and try to fill elements in sorted way to get max increasing subsequence
    // 2. we use binary search, to find element nums[i] in res
    //     1. if nums[i] value is greater than res, then insert at the end.
    //     2. if found, it fine
    //     3. else, nums[i] is not found, then insert at appropriate place.
    // 3. return size of res array.

    int lengthOfLIS(vector<int>& nums) {
        vector<int> res;
        res.push_back(nums[0]);
        for(int i=1;i<nums.size();++i){
            int num = nums[i];
            if(num > res[res.size()-1]){
                res.push_back(num);
            }
            else{
                int j = binarysearch(res, num);
                res[j] = num;
            }
        }
        return res.size();
    }
    
    int binarysearch(vector<int> res,int num){
        int left = 0;
        int right = res.size()-1;
        int mid=0;
        while(left < right){
            mid = (right+left)/2;
            if(num == res[mid]){
                return mid; // if found returning
            }
            if(num>res[mid]){
                left = mid+1; 
            }
            else{
                right = mid;
            }
        }
        // returning index in res array, to update the recent greater value in res array.
        return left;
    }
};
**/