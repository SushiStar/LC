/*
 * Given a positive integer n, find the least number of perfect
 * square numbers which sum to n;
 *
 * Date: Apr/12/2019
 * Author: Wei Du
 */
#include <cmath>
#include <unordered_map>

class Solution {
public:
    int numSquares(int n) {
        std::unordered_map<int, int> mp;
        return numSquares(n, mp);
    }

private:
    int numSquares(int n, std::unordered_map<int, int>& mp) {
        if (!n) return 0;
        int ceil = (int)floor(sqrt(n));
        int minn(INT_MAX);
        int lower;
        for (int i = 1; i <= ceil; ++i) {
            if (mp[n - i * i] != 0) {
                lower = mp[n - i * i];
            } else {
                lower = numSquares(n - i * i, mp);
                mp[n - i * i] = lower;
            }
            minn = minn < lower ? minn : lower;
        }
        return minn + 1;
    }
};

class Solution {
public:
    int numSquares(int n) {
        if (!n) return 0;
        std::vector<int> mp(n+1);
        mp[0] = 0;
        mp[1] = 1;
        for (int i = 2; i <= n; ++i) {
            mp[i] = INT_MAX;
            int j = 1;
            while (j*j < i) {
                mp[i] = min(mp[i], mp[i-j*j]);
                ++j;
            }
            ++mp[i];
        }
        return mp[n];
    }
};
