/*
 * Given a set of non-overlapping intervals, insert a new interval (merge
 * if necessary).
 * You may assume that the intervals were initially stored according to their
 * start times.
 *
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 *
 * Date: Apr/13/2019
 * Author: Wei Du
 */
#include <vector>
using namespace std;

class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        if (intervals.empty()) {
            intervals.push_back(newInterval);
            return intervals;
        }
        // find [l,r]  where l < newInterval.start;
        int l = findIn(intervals, newInterval.start, 0, intervals.size()-1);
        int r = findIn(intervals, newInterval.end,   0, intervals.size()-1);
        // taking care of left
        int ll = intervals[l].start;
        int lr = intervals[l].end;
        if (newInterval.start >= ll && newInterval.start <= lr) {
            newInterval.start = ll;     // erase l
        } else if (newInterval.start > lr ) {
            ++l;        // erase l+1
        }
        // taking care of right
        int rl = intervals[r].start;
        int rr = intervals[r].end;
        if (newInterval.end >= rl && newInterval.end <=rr) {
            newInterval.end = rr;   // erase r
        } else if (newInterval.end < rl) {
            --r;    // erase r-1
        }
        intervals.erase(intervals.begin()+l, intervals.begin()+l+(r-l+1));
        intervals.insert(l+intervals.begin(), newInterval);
        return intervals;
    }
private:
    int findIn(vector<Interval>& intervals, int A, int left, int right) {
        if (left == right) return right;
        int mid = (left+right)/2;
        if (intervals[mid].start <=A && intervals[mid].end>=A) {
            return mid;
        } else if (intervals[mid].start > A) {
            return findIn(intervals, A, left, mid);
        } else {    // intervals[mid].end < a
            return findIn(intervals, A, mid+1, right);
        }
        return -1;
    }
};
