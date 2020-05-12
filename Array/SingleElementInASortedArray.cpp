/*
 * You are given a sorted array consisting of only integers where every
 * element appears exactly twice, except for one element which appears
 * exactly once. Find this single element that appears only once.
 *
 * Your Solution should run in O(log n) time and O(1) space.
 *
 * Date: 05/12/2020
 * Author: Wei Du
 */
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        if (nums.empty()) return 0;
        if (nums.size() == 1) return nums[0];
        auto sett = findSingle(nums, 0, nums.size()-1);
        return *(sett.begin());
    }
private:
    std::unordered_set<int> findSingle(const std::vector<int>& nums, int left, int right) {
        if (left == right) return std::unordered_set<int>{nums[left]};
        int mid = left + (right-left)/2;
        std::unordered_set<int> left_single = findSingle(nums, left, mid);
        std::unordered_set<int> right_single = findSingle(nums, mid+1, right);
        std::unordered_set<int> ret{};
        for (int single : right_single) {
            if (left_single.find(single) != left_single.end()) {
                ret.insert(single);
            }
        }
        for (int single : right_single) {
            left_single.erase(single);
            right_single.erase(single);
        } 
        for (int single : right_single) {
            left_single.insert(single);
        }
        return left_single;
    }
};
