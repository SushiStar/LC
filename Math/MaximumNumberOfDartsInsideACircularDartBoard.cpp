/*
 * You have a very large square wall and a circular dartboard placed on the
 * wall. You have been challenged to throw darts into the board blindfolded.
 * Darts thrown at the wall are represented as an array of points on a 2D plane.
 * Return the maximum number of points that are within or lie on any circular
 * dartboard of radius r.
 *
 * Date: 05/16/2020
 * Author: Wei Du
 */
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    int numPoints(vector<vector<int>> &points, int r) {
        distance.resize(points.size(), std::vector<double>(points.size(), -1));
        for (int i = 0; i < points.size() - 1; ++i) {
            for (int j = i + 1; j < points.size(); ++j) {
                int diffx(points[i][0] - points[j][0]);
                int diffy(points[i][1] - points[j][1]);
                distance[i][j] = std::sqrt(diffx*diffx + diffy*diffy);
                distance[i][j] = distance[j][i];
            }
        }
        int ret{0};
        for (int i = 0; i < points.size(); ++i)
            ret = max(ret, calPoints(i, r, points));
        return ret;
    }

private:
    // distance squared
    std::vector<std::vector<double>> distance;

    int calPoints(int i, double r, std::vector<std::vector<int>> &points) {
        vector<pair<double, bool>> angles;
        int count(1);
        int res(1);

        for (int j = 0; j < distance.size(); j++) {
            if (i != j && distance[i][j] <= 2 * r) {
                double diffy = points[j][1]-points[i][1];
                double diffx = points[j][0]-points[i][0];
                double angleA = std::atan(diffy/diffx);
                double angleB = std::acos(0.5*distance[i][j]/r);
                double alpha = angleA-angleB;
                double beta = angleA+angleB;
                angles.push_back(make_pair(alpha, true));
                angles.push_back(make_pair(beta, false));
            }
        }
        std::sort(angles.begin(), angles.end());
        for (auto it = angles.begin(); it != angles.end(); ++it) {
            if (it->second) count++;
            else count--;
            if (count > res) res = count;
        }
        return res;
    }
};
