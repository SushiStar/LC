/*
 * Design a hit counter which counts the number of hits received in the past
 * 5 minutes.
 * Each function accepts a timestamp parameter (in seconds granularity) and you
 * may assume that calls are being made to the system in chronological order (ie,
 * the timestamp is monotonically increasing). You may assume that the earliest 
 * timestamp starts at 1.
 * It is possible that several hits arrive roughly at the same time.
 * 
 * Date: 05/19/2020
 * Author: Wei Du
 */
#include <vector>

class HitCounter {
public:
    /** Initialize your data structure here. */
    HitCounter() : totalHits(0), threshold(300){
        tilCurr.push_back({0,0});
    }
    
    /** Record a hit.
        @param timestamp - The current timestamp (in seconds granularity). */
    void hit(int timestamp) {
        if (timestamp == tilCurr.back().first) {
            tilCurr.back().second +=1;
        } else {
            int hisCount(tilCurr.back().second);
            tilCurr.push_back({timestamp, hisCount+1});
        }
    }
    
    /** Return the number of hits in the past 5 minutes.
        @param timestamp - The current timestamp (in seconds granularity). */
    int getHits(int timestamp) {
        // bainry search;
        int target = timestamp-threshold;
        if (target <= 0) 
            return tilCurr.back().second;
        else if (target > tilCurr.back().first)
            return 0;

        int left(0), right(tilCurr.size()-1);
        int mid = left + (right-left)/2;
        while (left < right) {
            if (tilCurr[mid].first == target) {
                break;
            } else if (tilCurr[mid].first < target) {
                left = mid+1;
            } else {
                right = mid;
            }
            mid = left + (right-left)/2;
        }
        mid = tilCurr[mid].first > target ? mid-1 : mid;
        return tilCurr.back().second - tilCurr[mid].second;
    }
private:
    int totalHits;
    int threshold;
    std::vector<std::pair<int,int>> tilCurr;
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter* obj = new HitCounter();
 * obj->hit(timestamp);
 * int param_2 = obj->getHits(timestamp);
 */
