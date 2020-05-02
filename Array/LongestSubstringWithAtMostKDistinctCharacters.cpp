/*
 * Given a string, find the length of the longest substring T
 * that contains at most K distinct characters.
 *
 * Date: 05/01/2020
 * Author: Wei Du
 */
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        int ret{0};
        if (s.empty() || k == 0) return ret;
        if (s.size() <= k) return s.size();
        std::vector<int> position(128, -1);
        int left(0), right(0);
        int counter{1};
        position[s[0]] = 0;
        while (right < s.size()) {
            if (position[s[right]] < left) ++counter;
            position[s[right]] = right;
            ret = std::max(ret, right - left + 1);
            if (counter == k && right + 1 < s.size() &&
                position[s[right + 1]] < left) {
                while (position[s[left]] != left)
                    ++left;
                ++left;
                --counter;
            }
            ++right;
        }
        ret = std::max(ret, right - left);
        return ret;
    }
};
