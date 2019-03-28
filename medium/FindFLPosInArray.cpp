/*
 * Given an array of integers nums sorted in ascending order,
 * find the start and ending position of a given target value.
 *
 * Your algorithms runtime complexity must be in the order of Olog(n);
 *
 * Date: Mar/28/2019
 *
 * Author: Wei Du
 */

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        std::vector<int> res{-1,-1};
        if (nums.empty()) return res;

        int end = nums.size() -1;
        if (nums[0] > target || nums[end] < target) return res;

        int left(0),right(end);
        std::pair<int,int> ress = findFL(nums,left, right, target);

        if (ress.first == INT_MAX && ress.second == INT_MIN) return res;
        if (ress.first == INT_MAX) ress.first = ress.second;
        if (ress.second == INT_MIN) ress.second = ress.first;
        res[0] = ress.first;
        res[1] = ress.second;
        return res;
    }

    std::pair<int,int> findFL(vector<int>& nums,int left, int right, int target){
        if (left == right){
            if (nums[left] == target) return std::make_pair(left, right);
            else  return std::make_pair(INT_MAX,INT_MIN);
        }

        int lp(INT_MAX);
        int rp(INT_MIN);
        if (left+1 == right) {
            if(nums[left] == target) lp = left;
            if(nums[right] == target) rp = right;
            return std::make_pair(lp,rp);
        }

        int mid = (left+right) /2;
        auto l = findFL(nums,left,mid,target);
        lp = min(lp, l.first);
        rp = max(rp, l.second);
        auto r = findFL(nums, mid, right, target);
        lp = min(lp, r.first);
        rp = max(rp, r.second);
        return std::make_pair(lp, rp);
    }
};
