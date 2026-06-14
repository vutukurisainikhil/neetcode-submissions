/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        // sort happens when first is equal then sorts based on second values
        vector<pair<int,int>> rooms;
        for(auto& interval: intervals){
            rooms.push_back({interval.start, 1});
            rooms.push_back({interval.end, -1});
        }
        sort(rooms.begin(), rooms.end());
        int count = 0, ans =0;
        for(auto& room: rooms){
            count += room.second;
            ans = max(ans, count);
        }
        return ans;
    }
};