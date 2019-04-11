/*
 * There are a total of n courses that you have to take, labeled from 0 to n-1.
 * Some courses may have some prerequisite, for example to take course 0 you
 * have to first take course 1, which is expressed as a pair {0,1}.
 * Given the total number of courses and a list of prerequisite pairs, is it
 * possible for you to finish all courses?
 *
 * Date: Apr/10/2019
 * Author: Wei Du
 */
#include <queue>
#include <unordered_map>
#include <utility>
#include <vector>
class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        if (prerequisites.empty()) return true;
        std::vector<int> tempvector;
        std::vector<std::vector<int>> tb(numCourses, tempvector);
        std::queue<int> bfs{p.first};
        for (auto p : prerequisites) {
            tb[p.first].push_back(p.second);
            while (!bfs.empty()) {
                auto f = bfs.front();
                for (int i = 0; i < tb[f].size(); ++i) {
                    if (tb[f][i] == p.first) {
                        return false;
                    }
                    bfs.push(tb[f][i]);
                }
                bfs.pop();
            }
        }
        return true;
    }
};
