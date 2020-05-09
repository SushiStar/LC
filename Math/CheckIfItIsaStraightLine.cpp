/* 
 * You are given an array coordinates, coordinates[i] = [x, y], where [x, y]
 * represents the coordinate of a point. Check if these points make a straight
 * line in the XY plane.
 *
 * 2 <= coordinates.length <= 1000
 * coordinates[i].length == 2
 * -10^4 <= coordinates[i][0], coordinates[i][1] <= 10^4
 *  coordinates contains no duplicate point.
 *  
 * Date: 05/08/2020
 * Author: Wei Du
 */
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        if (coordinates.size() < 3) return true;
        verticalLine = coordinates[0][0] == coordinates[1][0];
        if (verticalLine) anchorX = coordinates[0][0];
        else {
            slope = ((double)coordinates[0][1] -coordinates[1][1])/((double)coordinates[0][0]-coordinates[1][0]);
            intercept = coordinates[0][1] - slope * coordinates[0][0];
        }
        for (int i = 2; i < coordinates.size(); ++i) 
            if (!sameLine(coordinates[i][0], coordinates[i][1]))
                return false;
        return true;
    }
private:
    double slope;
    double intercept;
    bool verticalLine;
    int anchorX;
    bool sameLine(int x, int y) {
        if (verticalLine)
            return anchorX == x;
        double ret_y = slope*x + intercept;
        return std::abs(ret_y - y) < 1e-5;
    }
};
