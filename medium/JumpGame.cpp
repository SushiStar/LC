/*
 * Given an array of non-negative integers, you are initially
 * positioned at the first index of an array.
 * Each element in the array represents your maximum jump length
 * at that position.
 * Determine if you are able to reach the last index.
 *
 * Date: Mar/29/2019
 *
 * Author: Wei Du
 */

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int end = nums.size() - 1;
        if (end < 1) return true;
        if (nums[0] == 0) return false;

        int pos(0);
        // try the maximum step every time,
        // if not feasible(land at 0), go back steps
        while (true) {
            pos = pos + nums[pos];

            if (pos >= end) return true;
            // else  not reachable

            if (nums[pos] == 0) {  // try to get across the gap
                int flag(pos);
                while (pos > 0 && pos + nums[pos] <= flag) {
                    --pos;
                }
                if (pos == 0) {
                    return false;
                }
            }
        }
        return false;
    }
};
