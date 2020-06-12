/*
 * Given a collection of intervals, merge all overlapping intervals.
 *
 * Date: 06/11/2020
 *
 * Author: Wei Du
 */
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals) {
        if (intervals.empty() || intervals[0].empty()) return {};
        std::sort(intervals.begin(), intervals.end());
        vector<vector<int>> ret;
        int begin(intervals[0][0]), end(intervals[0][1]);
        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i][0] > end) {
                ret.push_back({begin, end});
                begin = intervals[i][0];
                end = intervals[i][1];
            } else { // extend current interval;
                end = end < intervals[i][1] ? intervals[i][1] : end;
            }
        }
        ret.push_back({begin, end});
        return ret;
    }
};
