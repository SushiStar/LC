/*
 * Given a non-empty array of non-negative integers nums, the degree
 * of this array is defined as the maximum frequency of any one of
 * its elements.
 *
 * Your task is ot find the smallest possible length of a (continguous)
 * subarray of nums, that has the same degree as nums.
 *
 * Date: 04/23/2020
 * Author: Wei Du
 */
class Solution {
public:
  int findShortestSubArray(vector<int> &nums) {
    if (nums.size() < 2)
      return nums.size();
    std::vector<int> buffer{};
    std::unordered_map<int, std::vector<int>> position;
    int maxNum{0};
    for (int i = 0; i < nums.size(); ++i) {
      position[nums[i]].push_back(i);
      if (position[nums[i]].size() > maxNum) {
        maxNum = position[nums[i]].size();
        buffer.clear();
        buffer.push_back(nums[i]);
      } else if (position[nums[i]].size() == maxNum) {
        buffer.push_back(nums[i]);
      }
    }
    int ret(INT_MAX);
    for (int i = 0; i < buffer.size(); ++i) {
      int start = position[buffer[i]].front();
      int end = position[buffer[i]].back();
      if (ret > (end - start)) {
        ret = end - start;
      }
    }
    return ret + 1;
  }
};
