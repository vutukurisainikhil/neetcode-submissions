class Solution {
public:
    // TimeComplexity - O(nlogn)
    // Space Complexity - O(n)
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n=intervals.size();
        vector<vector<int>> ans;
        sort(intervals.begin(),intervals.end());
        for(int i=0;i<n;i++){
            // if the list of merged intervals is empty or if the current
            // interval does not overlap with the previous, simply append it.
            if(ans.empty() || ans.back()[1] < intervals[i][0]){
                ans.push_back(intervals[i]);
            }
            else
            {
            // otherwise, there is overlap, so we merge the current and previous
            // intervals.
                ans.back()[1]=max(ans.back()[1],intervals[i][1]);
            }
        }

        return ans;
    }
};