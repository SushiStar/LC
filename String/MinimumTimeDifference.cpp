/*
 * Given a list of 24-hour clock time points in "Hour:Minutes" format, find 
 * the minimum minutes difference between any two time points in the list.
 *
 * The number of time points in the given list is at least 2 and won't exceed 20000.
 * The input time is legal and ranges from 00:00 to 23:59.
 *
 * Date: 05/20/2020
 * Author: Wei Du
 */

#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        if (timePoints.size() > 720) return 0;
        int minDiff(720);
        std::vector<bool> timelist(1440,false);
        for (int i = 0; i < timePoints.size(); ++i) {
            int timeidx = std::stoi(timePoints[i].substr(0,2))*60 + std::stoi(timePoints[i].substr(3));
            if (timelist[timeidx]) return 0;
            else 
                timelist[timeidx] = true;
        }
        int lastIdx{0}, currIdx{0};
        while (!timelist[lastIdx])
            ++lastIdx;
        currIdx = lastIdx+1;
        while (!timelist[currIdx]) 
            ++currIdx;
        while (currIdx < 1440) {
            if (timelist[currIdx]) {
                int diff = std::min(1440 - (currIdx - lastIdx), currIdx-lastIdx);
                minDiff = std::min(minDiff, diff);
                lastIdx = currIdx;
            }
            ++currIdx;
        }
        lastIdx = 0;
        while (!timelist[lastIdx])
            ++lastIdx;
        currIdx = 1439;
        while (!timelist[currIdx])
            --currIdx;
        minDiff = std::min(minDiff, std::min(1440-(currIdx-lastIdx), currIdx-lastIdx));
        return minDiff;
    }
};
