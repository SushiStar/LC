/*
 * Given n non-negative integers representing the histogram's bar
 * height where the width of each bar is 1, find the area of largest
 * rectangle in the histogram.
 *
 * Date: 05/06/2020
 * Author: Wei Du
 */
#include <vector>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        if (heights.empty()) return 0;
        if (heights.size() == 1) return heights[0];
        heights.insert(heights.begin(), -1);
        heights.push_back(-1);
        int ret{0};
        std::vector<int> stk;
        stk.push_back(0);
        for (int i = 1; i < heights.size(); ++i) {
            while (heights[i] < heights[stk.back()]) {
                auto h = heights[stk.back()];
                stk.pop_back();
                ret = std::max(ret, (i-stk.back()-1)*h);
            }
            stk.push_back(i);
        }
        return ret;
    }
};
