/*
 * There are total of numCourses courses you have to take, labeled
 * from 0 to numCourses-1. Some courses may have prerequisits, for
 * example to take course 0 you have to first take course 1, which
 * is expressed as a pair: [0, 1].
 * Given the total number of courses and a list of prerequisite
 * paris, is it possible for you to finish all courses?
 *
 * Date: 05/01/2020
 * Author: Wei Du
 */

#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
        if (numCourses < 3 || prerequisites.empty() || prerequisites[0].empty())
            return true;
        std::unordered_map<int, std::vector<int>> order;
        for (auto p : prerequisites) order[p[0]].push_back(p[1]);
        for (int i = 0; i < numCourses; ++i) {
            if (order.find(i) == order.end() ||
                checked.find(i) != checked.end()) continue;
            else if (isCycle(order, i)) return false;
        }
        return true;
    }
private:
    std::unordered_set<int> visited;
    std::unordered_set<int> checked;
    bool isCycle(std::unordered_map<int, std::vector<int>> &order, int start) {
        // DFS
        if (visited.find(start) != visited.end()) return true;
        visited.insert(start);
        for (auto child : order[start])
            if (isCycle(order, child)) return true;
        visited.erase(start);
        return false;
    }
};
