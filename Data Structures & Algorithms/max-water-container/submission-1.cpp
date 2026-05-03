class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l = 0, r = heights.size()-1;
        int maxarea = 0;
        while(l<r){
            maxarea = max(maxarea, (min(heights[l], heights[r]) * (r-l)));
            if(heights[l]<heights[r]){
                l++;
            }
            else{
                r--;
            }
        }
        return maxarea;
    }
};
