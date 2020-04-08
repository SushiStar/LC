/*
 * Given an array of non-negative integers, you are initially positioned at the
 * first index of the array.
 *
 * Each element in the array represents your maximum jump length at that
 * position.
 *
 * Your goal is to reach the last index in the minimum number of jumps.
 * You can assume that you can always reach the last index.
 *
 * Date: 04/07/2020
 * Author: Wei Du
 */

class Solution {
public:
    int jump(vector<int> &nums) {
        if (nums.empty()) return 0;
        std::vector<int> minJp(nums.size(), INT_MAX);

        minJp[0] = 0;
        for (int i = 0; i < minJp.size(); ++i) {
            for (int j = 0; j <= nums[i]; ++j) {
                if (i + j < minJp.size()) {
                    minJp[i + j] = std::min(minJp[i + j], minJp[i] + 1);
                }
            }
        }
        return minJp.back();
    }
};

// greedy --> implicit bfs
class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size() < 2) return 0; 
        int left{1};
        int goal(nums.size()-1);
        int right{0+nums[0]};
        int step{1};
        while (right < goal) {
            int furthest{right};
            ++step;
            for (int i = left; i <= right; ++i){
                furthest = std::max(nums[i]+i,furthest);
                if (furthest >= goal)
                    return step;
            }
            left = right;
            right = furthest;
        }
        return step;
    }
}; 
