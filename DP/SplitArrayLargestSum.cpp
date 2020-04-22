/*
 * Given an array which consists of non-negative integers and an integer
 * m, you can split the array into m non-empty continuous subarrays. Write
 * an algorithm to minimize the largest sum among these m subarrays.
 *
 * Date: 04/22/2020
 * Author: Wei Du
 */
class Solution {
public:
    int splitArray(vector<int> &nums, int m) {
        if (nums.empty()) return 0;
        if (m >= nums.size())
            return *(std::max_element(nums.begin(), nums.end()));

        std::vector<std::vector<int>> sum(nums.size() + 1,
                                          std::vector<int>(nums.size(), 0));
        nums.insert(nums.begin(), 0);
        for (int i = 1; i < nums.size(); ++i)
            nums[i] += nums[i - 1];
        if (m < 2) return nums.back();

        std::vector<std::vector<int>> buffer(nums.size(),
                                             std::vector<int>(m, INT_MAX));
        for (int i = 0; i < nums.size(); ++i)
            buffer[i][0] = nums[i];

        // break m times
        for (int i = 1; i < m; ++i) {
            for (int j = i; j < nums.size(); ++j) {
                for (int k = j - 1; k > 0; --k) {
                    buffer[j][i] =
                        std::min(buffer[j][i],
                                 std::max(nums[j] - nums[k], buffer[k][i - 1]));
                }
            }
        }
        return buffer[nums.size() - 1][m - 1];
    }
};

// better and awesome idea
class Solution {
private:
    bool doable(const vector<int> &nums, int cuts, long long max) {
        long acc = 0;
        for (auto num : nums) {
            if (num > max) return false;
            else if (acc + num <= max) acc += num;
            else {
                --cuts;
                acc = num;
                if (cuts < 0) return false;
            }
        }
        return true;
    }
public:
    int splitArray(vector<int> &nums, int m) {
        long long left = 0, right = 0;
        for (auto num : nums) {
            left = max(left, (long long)num);
            right += num;
        }

        while (left < right) {
            long long mid = left + (right - left) / 2;
            if (doable(nums, m - 1, mid))
                right = mid;
            else left = mid + 1;
        }
        return left;
    }
};

