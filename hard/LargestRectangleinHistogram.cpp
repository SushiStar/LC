/*
 * Given n non-negative integers representing the histogram's bar
 * height where the width of each bar is 1, find the area of largest
 * rectangle in the histogram.
 *
 * Date: Apr/02/2019
 *
 * Author: Wei Du
 */
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        if (heights.empty()) return 0;
        int sz = heights.size();
        int maxx(heights[0]);
        int stack<int> sk;
        int i(0);

        while (i < sz) {
            if (sk.empty() || heights[i] >= heights[sk.top()]) {
                sk.push_back(i);
                ++i;
            } else {
                int tp = sk.top();
                sk.pop();
                int multi = sk.empty()? i : i-sk.top()-1;
                maxx = max(maxx, multi*heights[tp]);
            }
        }
        while (sk.size() > 1) {
            int tp = sk.top();
            sk.pop();
            maxx = max(maxx, (sz-sk.pop()-1) * heights[tp]);
        }
        if (sk.size() == 1) {
            maxx = max(maxx, sz*heights[sk.top()]);
        }
        return maxx;
    }
};
