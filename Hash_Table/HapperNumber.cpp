/*
 * Write an algorithm to determine if a number is "happy".
 * A happy number is a number defined by the following process:
 * Starting with an positive integer, replace the number by the
 * sum of squares of its digits, and repeat the process until
 * the number equals 1 (where it will stay), or it loops endlessly
 * in a cycle which does not include 1. Those numbers for which
 * this process ends in 1 are happy numbers.
 *
 * Date:  03/31/2020
 * Author: Wei Du
 */
#include <vector>
#include <unordered_map>

class Solution {
private:
    std::vector<int> partition(int num) {
        std::vector<int> res;
        while(num/10) {
            res.push_back(num%10);
            num /= 10;
        }
        res.push_back(num);
        return res;
    }

    int sumsquare(const std::vector<int>& v) {
        int res(0);
        for (auto& num:v) {
            res+=num*num;
        }
        return res;
    }

public:
    bool isHappy(int n) {
        std::unordered_map<int,int> mp;
        while (n > 1 && !mp[n]) {
            mp[n] = 1;
            auto k = partition(n);
            n = sumsquare(k);
        }
        return n == 1;
    }
};
