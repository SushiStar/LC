/*
 * There are n items each belonging to zero or one of m groups where group[i] is
 * the group that the i-th item belongs to and it's equal to -1 if the i-the
 * item belongs to no group. The items and the groups are zero indexed. A group
 * can have no item belonging to it.
 *
 * Return a sorted list of the items such that:
 * 		The items that belong to the same group are next to each other
 * in the sorted list. There are some relations between these items where
 * beforeItems[i] is a list containing all the items that should come before the
 * i-th item in the sorted array (to the left of the i-th item)
 *
 * Return any solution if there is more than one solution and return an empty
 * list if there is no solution.
 *
 * Date: 06/26/2020
 * Author: Wei Du
 */
#include <deque>
#include <numeric>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
    int numGroup;

public:
    vector<int> sortItems(int n, int m, vector<int> &group,
                          vector<vector<int>> &beforeItems) {
        numGroup = m;
        vector<vector<int>> groups(m);
        for (int i = 0; i < n; ++i) {
            if (group[i] == -1) {
                groups.push_back({i});
                group[i] = numGroup++;
            } else
                groups[group[i]].push_back(i);
        }
        vector<unordered_set<int>> nxtGroups(numGroup);
        vector<vector<int>> inGroupNextItems(n);
        vector<int> groupDOF(numGroup, 0);
        vector<int> inGroupItemDOF(n, 0);
        for (int i = 0; i < beforeItems.size(); ++i) {
            for (int pred : beforeItems[i]) {
                if (group[pred] == group[i]) {
                    inGroupNextItems[pred].push_back(i);
                    ++inGroupItemDOF[i];
                } else if (!nxtGroups[group[pred]].count(group[i])) {
					// not in the same group, consider it group-wise
                    nxtGroups[group[pred]].insert(group[i]);
                    ++groupDOF[group[i]];
                }
            }
        }

        vector<int> groupOrder;
        deque<int> q;
        for (int i = 0; i < numGroup; ++i)
            if (groupDOF[i] == 0) q.push_back(i);
        while (!q.empty()) {
            int tmp = q.front();
            q.pop_front();
            groupOrder.push_back(tmp);
            for (int nxtG : nxtGroups[tmp])
                if (--groupDOF[nxtG] == 0) q.push_back(nxtG);
        }
        if (groupOrder.size() != numGroup) return {};
        vector<vector<int>> orderedGroup(numGroup);
        for (int i = 0; i < groupOrder.size(); ++i)
            orderedGroup[i] = std::move(groups[groupOrder[i]]);

        // in group sort
        vector<int> ret{};
        for (int i = 0; i < numGroup; ++i) {
            if (groups[i].size() == 1) {
                ret.push_back(groups[i][0]);
                continue;
            }
            q.clear();
            for (int j = 0; j < groups[i].size(); ++j)
                if (inGroupItemDOF[groups[i][j]] == 0)
                    q.push_back(groups[i][j]);
            int cnt{0};
            while (!q.empty()) {
                int tmp = q.front();
                q.pop_front();
                ret.push_back(tmp);
                ++cnt;
                for (int nxtItm : inGroupNextItems[tmp])
                    if (--inGroupItemDOF[nxtItm] == 0) q.push_back(nxtItm);
            }
            if (cnt != groups[i].size()) return {};
        }
        return ret;
    }
};
