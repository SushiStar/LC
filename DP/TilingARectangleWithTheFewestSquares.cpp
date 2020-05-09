/*
 * Given a rectangle of size n x m, find the minimum number of integer-sided
 * squares that tile the rectangle.
 * 1 <= n <= 13;
 * 1 <= m <= 13;
 *
 * Date: 05/08/2020
 * Author: Wei Du
 */
#include <vector>
using namespace std;

class Solution {
public:
    int tilingRectangle(int n, int m) {
        if (m == n) return 1;
        int minSide(std::min(m, n));
        int maxSide(m+n-minSide);
        dp.resize(maxSide+1, std::vector<int>(maxSide+1,-1));
        for (int i = 1; i <= minSide; ++i)
            dp[i][i] = 1;
        return getMin(n, m);
    }
private:
    std::vector<std::vector<int>> dp;
    int getMin(int n, int m) {
        if (!m || !n) return 0;
        else if (dp[n][m] != -1) return dp[n][m]; 
        int ret{INT_MAX};
        int width = std::max(n, m);
        int height = std::min(n, m);
        int diff(width-height);
        if (width >= height * 2) {
            ret = getMin(diff, height) + 1;
        } else { // width < height * 2;
            // i = diff
            ret = std::min(ret, getMin(diff, height));
            for (int i = diff; i < width/2; ++i) {
                int r1, r2;
                if (height >= i*2) {
                    r1 = 2 + getMin(i, height-i) + getMin(i-diff, width-i);
                    r2 = 2 + getMin(width-i*2,i) + getMin(i-diff, width);
                } else  { // height < i*2
                    r1 = 3+getMin(2*i-height,height-i) + getMin(i-diff, width-i);
                    r2 = 3+getMin(width-i*2, 2*i -height) + getMin(i-diff, width-height+i);
                }
                ret = std::min(ret, std::min(r1,r2));
            }
        }
        dp[n][m] = ret;
        dp[m][n] = ret;
        return ret;
    }
};
