/*
 * Given two arrays of length m and n with digits 0-9 representing two numbers.
 * Create the maximum number of length k <= m + n from digits of the two. The
 * relative order of the digits from the same array must be preserved. Return an
 * array of the k digits.
 * Note: You should try to optimize your time and space complexity.
 *
 * Date: 06/28/2020
 * Author: Wei Du
 */
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> maxNumber(vector<int> &nums1, vector<int> &nums2, int k) {
        vector<int> ret(k, 0);
        for (int i = max(0, k - (int)nums2.size());
             i <= min(k, (int)nums1.size()); ++i) {
			// i numbers from nums1 and k-i numbers from nums2
            auto v1 = largestSub(nums1, i);
            auto v2 = largestSub(nums2, k - i);
			vector<int> ans(k,0);
			int pos1{0}, pos2{0}, tpos{0};
			while (pos1 < v1.size() || pos2 < v2.size())
				ans[tpos++] = greater(v1, pos1, v2, pos2) ? v1[pos1++] : v2[pos2++];
			if (!greater(ret, 0, ans, 0))
				ret = ans;
        }
		return ret;
    }

private:
	// stack find the largest k numbers combination
    vector<int> largestSub(vector<int> &nums, const int k) {
        vector<int> ret(k, 0);
        int len = 0, n = nums.size();
        for (int i = 0; i < n; ++i) {
            while (len && len + n - i > k && nums[i] > ret[len - 1])
                --len;
            if (len < k) ret[len++] = nums[i];
        }
        return ret;
    }

    bool greater(vector<int> a, int start1, vector<int> b, int start2) {
        for (; start1 < a.size() && start2 < b.size(); ++start1, ++start2) {
            if (a[start1] > b[start2]) return true;
            if (a[start1] < b[start2]) return false;
        }
        return start1 != a.size();
    }
};
