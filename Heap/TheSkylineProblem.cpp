/*
 * Date: 04/14/2020
 * Author: Wei Du
 */
class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>> &buildings) {
        std::vector<std::vector<int>> rlt{};
        if (buildings.empty() || buildings[0].empty()) return rlt;
        std::priority_queue<std::vector<int>, std::vector<std::vector<int>>,
                            cmpBuild>
            pq;
        int lstEd{-1};
        rlt.push_back({buildings[0][0], buildings[0][2]});
        pq.push(buildings[0]);
        for (int i = 1; i < buildings.size(); ++i) {
            lstEd = pq.top()[1];
            while (!pq.empty() && buildings[i][0] >= pq.top()[1]) {
                lstEd = std::max(lstEd, pq.top()[1]);
                pq.pop();
                if (!pq.empty() && pq.top()[1] > lstEd &&
                    pq.top()[2] != rlt.back()[1]) {
                    rlt.push_back({lstEd, pq.top()[2]});
                }
            }
            if (pq.empty()) {
                if (rlt.empty()) {
                    rlt.push_back({buildings[i][0], buildings[i][2]});
                } else if (rlt.back()[1] != buildings[i][2]) {
                    if (lstEd != buildings[i][0]) {
                        rlt.push_back({lstEd, 0});
                    }
                    rlt.push_back({buildings[i][0], buildings[i][2]});
                }
            } else if (buildings[i][2] > pq.top()[2]) {
                if (buildings[i][0] == rlt.back()[0]) { // connected
                    rlt.back()[1] = buildings[i][2];
                } else {
                    rlt.push_back({buildings[i][0], buildings[i][2]});
                }
            }
            // buildings[i] equals the tallest now, nothing changed now
            // buildings[i] shorter than the tallest now, nothing changed now
            pq.push(buildings[i]);
        }
        lstEd = pq.top()[1];
        while (!pq.empty()) {
            lstEd = std::max(lstEd, pq.top()[1]);
            pq.pop();
            if (!pq.empty() && pq.top()[1] > lstEd &&
                pq.top()[2] != rlt.back()[1]) {
                rlt.push_back({lstEd, pq.top()[2]});
            }
        }
        rlt.push_back({lstEd, 0});
        return rlt;
    }

private:
    struct cmpBuild {
        bool operator()(const std::vector<int> &v1,
                        const std::vector<int> &v2) const {
            return v1[2] < v2[2];
        }
    };
};
