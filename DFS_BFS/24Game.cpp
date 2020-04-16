/*
 * You have 4 cards each containing a number from 1 to 9. You need to judge
 * whether they could operated through *, /, +, -, () to get the value of 24.
 *
 * The divisino operator / represents real division, not integer division.
 * Every operation done is between two numbers. In particular, we cannot use
 * - as a unary operator.
 * You cannot cancatenate numbers together.
 *
 * Date: 04/16/2020
 * Author: Wei Du
 */

class Solution {
public:
    bool judgePoint24(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        do {
            if (valid(nums)) return true;
        } while (next_permutation(nums.begin(), nums.end()));
        return false;
    }

private:
    bool valid(vector<int> &nums) {
        double a = nums[0], b = nums[1], c = nums[2], d = nums[3];
        if (valid(a + b, c, d) || valid(a - b, c, d) || valid(a * b, c, d) ||
            valid(a / b, c, d))
            return true;
        if (valid(a, b + c, d) || valid(a, b - c, d) || valid(a, b * c, d) ||
            valid(a, b / c, d))
            return true;
        if (valid(a, b, c + d) || valid(a, b, c - d) || valid(a, b, c * d) ||
            valid(a, b, c / d))
            return true;
        return false;
    }
    bool valid(double a, double b, double c) {
        if (valid(a + b, c) || valid(a - b, c) || valid(a * b, c) ||
            b && valid(a / b, c))
            return true;
        if (valid(a, b + c) || valid(a, b - c) || valid(a, b * c) ||
            c && valid(a, b / c))
            return true;
        return false;
    }
    bool valid(double a, double b) {
        if (abs(a + b - 24.0) < 0.0001 || abs(a - b - 24.0) < 0.0001 ||
            abs(a * b - 24.0) < 0.0001 || b && abs(a / b - 24.0) < 0.0001)
            return true;
        return false;
    }
};
