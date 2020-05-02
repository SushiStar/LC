/*
 * Therej are a total of n courses you have to take, labeled from
 * 0 to n-1. Some courses may have prerequesites, for example to take
 * course 0 you have to first take course 1, which is expressed as a 
 * pair: [0, 1]. Given the total number of courses and a list of 
 * prerequesite pairs, return the ordering of courses you should take 
 * to finish all courses. There may be multiple correct orders, you 
 * just need to return one of them. If it is impossible to finish all
 * courses, return an empty array.
 *
 * Date: 05/02/2020
 * Author: Wei Du
 */
#include <vector>
#include <numeric>
#include <queue>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        std::vector<int> ret{};
        if (numCourses == 0) return ret;
        if (prerequisites.empty() || prerequisites[0].empty()) {
            ret.resize(numCourses);
            std::iota(ret.begin(), ret.end(), 0);
            return ret;
        }
        std::vector<std::unordered_set<int>> order(numCourses, std::unordered_set<int>{});
        std::vector<int> degree(numCourses, 0);
        for (auto pir : prerequisites) {
            ++degree[pir[0]];
            order[pir[1]].insert(pir[0]);
        }

        // Kahan's algorithm in topology sort
        std::queue<int> q;
        for (int i = 0; i < order.size(); ++i)
            if (order[i].empty()) q.push(i);
        while (!q.empty()) {
            int parent = q.front();
            q.pop();
            ret.push_back(parent);
            for (auto child : order[parent]) {
                --degree[child];
                if (!degree[child])
                    q.push(child);
            }
        }
        if (ret.size() != numCourses) ret.clear();
        return ret;
    }
};
