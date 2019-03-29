/*
 * Given a collection of intervals, merge all overlapping intervals.
 *
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval():start(0), end(0){}
 *     Interval(int s, int e) : start(s), start(e) {}
 * };
 *
 * Date: Mar/29/2019
 *
 * Author: Wei Du
 */

class Solution {
public:
    struct cmpItv {
        bool operator()(const Interval& t1, const Interval& t2) {
            return t1.start <= t2.start;
        }
    } cmp;

    vector<Interval> merge(vector<Interval>& intervals) {
        if (intervals.empty()) return intervals;

        std::sort(intervals.begin(), intervals.end(), cmp);

        while(!intervals.empty()){
            auto tmp = intervals[0];
            if (tmp.start <= tmp.end) {
                break;
            } else {
                intervals.erase(intervals.begin(), intervals.begin()+1);
            }
        }

        for (int i = 1; i < intervals.size(); ) {
           
            if (intervals[i].start > intervals[i].end){   // take care of illegal ones.
                intervals.erase(intervals.begin()+i,intervals.begin()+i+1);
                continue;
            }

            if (intervals[i].start <= intervals[i-1].end) {  // which means overlap
                // since intervals is ordered,
                // not possible m.start < resEnd.start
                intervals[i-1].end = intervals[i].end;
                intervals.erase(intervals.begin()+i, intervals.begin()+i+1);
            } else {  // which means no overlap
                ++i;
            }
        }
        return intervals;
    }
};
