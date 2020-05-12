/*
 * We are given a list schedule of employees, which represents the 
 * working time for each employee.
 * Each employee has a list of non-overlapping Intervals, and these
 * intervals are in sorted order.
 * Return the list of finite intervals representing common, positive
 * length free time for all employees, also in sorted order.
 *
 * Even though we are representing Intervals in the form [x, y], the
 * objects insides are Intervals, not lists or arrays. 
 *
 * Date: 05/12/2020
 */
#include <vector>
#include <queue>
using namespace std;

class Interval {
public:
    int start;
    int end;

    Interval() {}

    Interval(int _start, int _end) {
        start = _start;
        end = _end;
    }
};

class Solution {
public:
    vector<Interval> employeeFreeTime(vector<vector<Interval>> schedule) {
        std::vector<Interval> ret{};
        std::priority_queue<Interval, std::vector<Interval>, cmpInterval> pq{};
        for (int i = 0; i < schedule.size(); ++i) {
            for (int j = 0; j < schedule[i].size(); ++j) {
                pq.push(schedule[i][j]);
            }
        }
        int freeStart(0);
        freeStart = pq.top().start;
        while (!pq.empty()) {
            Interval currInterval = pq.top();
            pq.pop();
            if (currInterval.start <= freeStart) {
                freeStart = std::max(freeStart, currInterval.end);
            } else {
                ret.push_back(Interval(freeStart, currInterval.start));
                freeStart = currInterval.end;
            }
        }
        return ret;
    }
private:
    struct cmpInterval {
        bool operator()(Interval& i1, Interval& i2) const {
            if (i1.start < i2.start) return true;
            else if (i1.start == i2.start) return i1.end < i2.end;
            return false;
        }
    };
};
