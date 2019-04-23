/*
 * Given a char array representing tasks CPU need to do. It contains capital 
 * letters A to Z where different letters represent different tasks. Tasks 
 * could be done without original order. Each task could be done in one 
 * interval. For each interval, CPU could finish one task or just be idle.
 * However, there is a non-negative cooling interval n that means between two
 * same tasks, there must be at least n intervals that CPU are doing different
 * tasks or just be idle.  You need to return the least number of intervals 
 * the CPU will take to finish all the given tasks.
 *
 * Date: Apr/22/2019
 * Author: Wei Du
 */
#include <cmath>
#include <vector>
#include <unordered_map>

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        if (tasks.empty()) return 0;
        std::vector<int> mp(26,0);
        int maxx(0);
        for (auto& c:tasks) {
            ++mp[c-65];
            maxx=std::max(maxx,mp[c-65]);
        }
        int ans = (maxx-1)*(n+1);
        for (auto& p:mp) {  // the rest;
            ans+=(p==maxx);
        }
        return std::max(ans,(int)tasks.size());
    }
};
