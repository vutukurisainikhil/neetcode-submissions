class Solution {
public:
    // Time Complexity: O(n)
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> result;
        for(int i=0;i<intervals.size();i++){
            int start = intervals[i][0];
            int end = intervals[i][1];
            if(end < newInterval[0]){ // less than NewInterval
                result.push_back(intervals[i]);
            }
            else if(start > newInterval[1]){ // greater than NewInterval
                result.push_back(newInterval); // so, swap the current and NewInterval.
                newInterval = {start, end};
            }
            else if(end >= newInterval[0]){ // overlapping interval.
                newInterval[0] = min(start, newInterval[0]);
                newInterval[1] = max(end, newInterval[1]);
            }
        }
        result.push_back(newInterval); // add the interval.
        return result;
    }
};