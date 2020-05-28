/*
 * Given a set of N people (numbered 1, 2, ..., N), we would like to
 * split everyone into two groups of any size.
 * Each person may dislike some other people, and they should not go
 * into the same group. Fromally, if dislikes[i] = [a, b], it means it
 * is not allowed to put the people numbered a and b into the same
 * group. Return true if and only if it is possible to split everyone
 * into two groups in this way.
 *
 * 1 <= N <= 2000
 * 0 <= dislikes.length <= 10000
 * 1 <= dislikes[i][j] <= N
 * dislikes[i][0] < dislikes[i][1]
 * There does not exsit i!=j for which dislikes[i] == dislikes[j]
 *
 * Date: 05/27/2020
 * Author: Wei Du
 */
#include <deque>
#include <vector>
using namespace std;

class Solution {
public:
    bool possibleBipartition(int N, vector<vector<int>> &dislikes) {
        if (dislikes.empty()) return true;
        std::vector<std::vector<int>> opposite(N + 1, std::vector<int>{});
        std::vector<int> team(N + 1, -1);
        for (auto &pr : dislikes) {
            opposite[pr[0]].push_back(pr[1]);
            opposite[pr[1]].push_back(pr[0]);
        }

        for (int i = 1; i <= N; ++i) {
            if (team[i] == -1) {
                // do a bfs here to assign team
                team[i] = 0;
                std::deque<int> dq{i};
                while (!dq.empty()) {
                    int currNode = dq.front();
                    dq.pop_front();
                    for (int neighbor : opposite[currNode]) {
                        if (team[neighbor] == team[currNode]) {
                            return false;
                        } else if (team[neighbor] == -1) {
                            team[neighbor] = 1 - team[currNode];
                            dq.push_back(neighbor);
                        }
                    }
                }
            } // else i'th node has already been assigned a team
        }
        return true;
    }
};
