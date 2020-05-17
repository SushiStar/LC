/*
 * Given two integer arrays startTime and endTime and given an integer
 * queryTime. The ith student started doing their homework at the time
 * startTime[i] and finished it at time endTime[i]. Return the number of
 * students doing their homework at time querytime. More formally, return the
 * number of students where queryTime lays in the interval [startTime[i],
 * endTime[i]] inclusive.
 *
 * Date: 05/16/2020
 * Author: Wei Du
 */
#include <vector>
using namespace std;

class Solution {
public:
    int busyStudent(vector<int> &startTime, vector<int> &endTime,
            int queryTime) {
        int ret{0};
        for (int i = 0; i < startTime.size(); ++i) {
            if (startTime[i] <= queryTime && endTime[i] >= queryTime)
                ++ret;
        }
        return ret;
    }
};
