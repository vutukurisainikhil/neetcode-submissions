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
        vector<pair<int, int>> time;
        for (const auto& i : intervals) {
            time.push_back({i.start, 1});
            time.push_back({i.end, -1});
        }

        sort(time.begin(), time.end(), [](auto& a, auto& b) {
            return a.first == b.first ? a.second < b.second : a.first < b.first;
        });

        int res = 0, count = 0;
        for (const auto& t : time) {
            count += t.second;
            res = max(res, count);
        }
        return res;
    }
};