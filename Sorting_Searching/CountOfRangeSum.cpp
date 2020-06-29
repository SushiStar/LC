/*
 * Given an integer array nums, return the number of range sums that lie in
 * [lower, upper] inclusive. Range sum S(i,j) is defined as the sum of the
 * elements in nums between indices i and j (i <= j), inclusive.
 *
 * Note: A naive algorithm of O(n^2) is trivial. You MUST do better than that.
 *
 * Date: 06/28/2020
 * Author: Wei du
 */

#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int countRangeSum(vector<int> &numss, int lower, int upper) {
        if (numss.empty()) return 0;
        std::vector<long> nums(numss.begin(), numss.end());
        unordered_map<long, int> cnt{};
        int ret{0};
        for (int i = 0; i < nums.size(); ++i) {
            nums[i] += (i == 0 ? 0 : nums[i - 1]);
            long left{nums[i] - (long)upper}, right{nums[i] - (long)lower};
            while (left <= right) {
                if (cnt.find(left) != cnt.end()) {
                    ret += cnt[left];
                }
                ++left;
            }
            if (nums[i] >= lower && nums[i] <= upper) {
                ++ret;
            }
            ++cnt[nums[i]];
        }
        return ret;
    }
};

// mergesort
class Solution1 {
public:
	int countRangeSum(vector<int> &nums, int lower, int upper) {
		if (nums.empty()) return 0;
		sum.resize(nums.size());
		sum[0] = nums[0]; lo = lower; hi = upper;
		for (int i = 1; i < nums.size(); ++i) sum[i] = sum[i-1]+nums[i];
		return mergeSort(0, nums.size()-1);
	}
private:
	vector<int64_t> sum;
	int hi, lo;
	int mergeSort(int left, int right) {
		if (left == right) return lo <= sum[left] && sum[left] <= hi;
		int mid = left + (right-left)/2;
		int cnt = mergeSort(left, mid) + mergeSort(mid+1, right);

		// count for each sum[k] on the right, find matches on the left;
		for (int l_ = left, r_ = left, k = mid+1; k <= right; ++k) {	// find all i j pairs;
			while (r_ <= mid && sum[k] - sum[r_] >= lo) ++r_;
			while (l_ <= mid && sum[k] - sum[l_] > hi) ++l_;
			cnt += r_-l_;
		}

		inplace_merge(sum.begin() + left, sum.begin()+mid+1, sum.begin() + right+1);
		return cnt;
	}
};
