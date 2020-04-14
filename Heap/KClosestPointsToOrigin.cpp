/*
 * We ahve a list of points on the plane. Find the K closest points
 * to the origin (0,0). (Here, the distance between two points on a
 * plane is the Euclidean distance.)
 * You may return the answer in any order. The answer is guaranteed
 * to be unique (except fo the order that it is in.)
 *
 * Date: 04/14/2020
 * Author: Wei Du
 */
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>> &points, int K) {
        if (points.size() <= K) return points;
        for (int i = 0; i < points.size(); ++i) {
            points[i].push_back(points[i][0] * points[i][0] +
                                points[i][1] * points[i][1]);
        }
        std::nth_element(points.begin(), points.begin() + (size_t)K,
                         points.end(), cmpDist());
        for (int i = 0; i < K; ++i) {
            points[i].pop_back();
        }
        points.erase(points.begin() + (size_t)K, points.end());
        return points;
    }

private:
    struct cmpDist {
        bool operator()(const std::vector<int> &pt1,
                        const std::vector<int> &pt2) const {
            return pt1[2] < pt2[2];
        }
    };
};
