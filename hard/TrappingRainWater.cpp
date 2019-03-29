/*
 * Given n non-negative integers representing an elevation
 * map where the width of each bar is 1, compute how much water
 * it is able to trap after raining.
 *
 * Date: Mar/28/2019
 * Author: Wei Du
 */
class Solution {
public:
    int trap(vector<int>& height) {
        int res(0);

        int sz = height.size();
        if (sz == 0|| sz ==1) return res;

        int max_pos = findMax(height, 0, sz-1);
        int max_left(max_pos);
        int max_right(max_pos);
        // overflow to the left;
        while (max_left > 0 && height[max_left] > 0) {
            // find the second maximum;
            int max_left_left = findMax(height, 0, max_left-1);
            if (height[max_left_left] == 0) break;

            auto mark = height[max_left_left];
            for (int i = max_left_left +1; i < max_left; ++i) {
                res += mark - height[i];
            }

            max_left = max_left_left;
        }
        
        // overflow to the right;
        while (max_right < sz-1 && height[max_right] > 0) {
            // find the second maximum;
            int max_right_right = findMax(height, max_right+1, sz-1);
            if (height[max_right_right] == 0) break;

            auto mark = height[max_right_right];
            for (int i = max_right +1; i < max_right_right; ++i) {
                res += mark - height[i];
            }

            max_right = max_right_right;
        }
        return res;
    }

    // binsection search the max value within a range
    int findMax(vector<int>&height, int left, int right) {
        if (left == right) {
            return left;
        } else {
            int mid = (left+right) /2;
            int res1 = findMax(left, mid);
            int res2 = findMax(mid+1, right);
            return height[res1] > height[res2] ? res1 : res2;
        }
    }

};
