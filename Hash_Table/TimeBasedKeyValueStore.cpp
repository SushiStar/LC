/*
 * Create a timebased key-value store class TimeMap, that supports two
 * operations.
 * 1. set(string key, string value, int timestamp)
 *      stores kay and value, along with the givem timestamp
 * 2. get(string key, int timestamp)
 *      returns a value such that set(key, value, timestamp_prev)was called
 *      previously, with timestamp_prev <= timestamp.
 *      if there are multiple such values, it returns the one with the largest
 *      timestamp_prev.
 *      if there are no values, it returns the empty string ("");
 *
 * Date: 05/18/2020
 * Author: Wei Du
 */
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class TimeMap {
public:
    /** Initialize your data structure here. */
    TimeMap() {}

    void set(string key, string value, int timestamp) {
        std::vector<int> &vct = mapp[key];
        vct.push_back(timestamp);
        mapp2[timestamp] = value;
    }

    string get(string key, int timestamp) {
        const std::vector<int> &vct = mapp[key];
        // binary search
        if (timestamp < vct[0])
            return "";
        else if (timestamp >= vct.back())
            return mapp2[vct.back()];
        int left(0), right(vct.size() - 1);
        int mid = left + (right - left) / 2;
        while (left < right) {
            if (vct[mid] == timestamp) {
                return mapp2[vct[mid]];
            } else if (vct[mid] > timestamp) {
                right = mid;
            } else {
                left = mid + 1;
            }
            mid = left + (right - left) / 2;
        }
        if (vct[mid] <= timestamp) {
            return mapp2[vct[mid]];
        }
        if (mid > 0 && vct[mid - 1] <= timestamp) {
            return mapp2[vct[mid - 1]];
        }
        return "";
    }

private:
    std::unordered_map<std::string, std::vector<int>> mapp;
    std::unordered_map<int, std::string> mapp2;
};
