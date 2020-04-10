/*
 * Given an integer array nums, find the sum of the elements between indices
 * i and j (i <= j), inclusive.
 *
 * Date: 04/10/20202
 * Author: Wei Du
 */
class NumArray {
public:
    NumArray(vector<int> &nums) {
        sum.resize(nums.size(), std::vector<int>(nums.size(), INT_MIN));
        for (int i = 0; i < nums.size(); ++i)
            sum[i][i] = nums[i];
    }

    int sumRange(int i, int j) {
        if (sum[i][j] == INT_MIN) {
            if (sum[i][j - 1] != INT_MIN) {
                sum[i][j] = sum[i][j - 1] + sum[j][j];
            } else if (sum[i + 1][j] != INT_MIN) {
                sum[i][j] = sum[i + 1][j] + sum[i][i];
            } else {
                sum[i][j] = sumRange(i + 1, j - 1) + sum[j][j] + sum[i][i];
            }
        }
        return sum[i][j];
    }

private:
    std::vector<std::vector<int>> sum;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */
class NumArray {
public:
    NumArray(vector<int> &nums) {
        acc = std::move(nums);
        for (int i = 1; i < acc.size(); ++i)
            acc[i] += acc[i - 1];
    }

    int sumRange(int i, int j) {
        if (acc.empty()) return INT_MIN;
        if (i == 0) return acc[j];
        return acc[j] - acc[i - 1];
    }

private:
    std::vector<int> acc;
};
