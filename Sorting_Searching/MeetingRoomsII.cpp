/*
 * Given an array of meeting time intervals consisting of start and end
 * times [[s1,e1], [s2,e2], ...], find the minimum number of conference
 * rooms required.
 *
 * Date: 04/07/2020
 * Author: Wei Du
 */

class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        if (intervals.empty()) return 0;
        std::sort(intervals.begin(), intervals.end(), cmpTime());
        std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
        pq.push(0);
        for (const auto &mt : intervals) {
            if (pq.top() <= mt[0]) {
                pq.pop();
            }
            pq.push(mt[1]);
        }
        return pq.size();
    }
private:
    struct cmpTime {
        bool operator()(const vector<int>& v1, const vector<int>& v2) const {
            return v1[0] < v2[0];
        }
    };
};
