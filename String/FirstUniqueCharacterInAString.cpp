/*
 * Given a string, find the first non-repeating character in it and return
 * it's index. If it doesn't exist, return -1;
 *
 * Date: 04/27/2020
 * Author: Wei Du
 */

class Solution {
public:
    int firstUniqChar(string s) {
        std::vector<int> counter(26, 0);
        for (auto ch : s)
            ++counter[ch - 'a'];
        for (int i = 0; i < s.size(); ++i)
            if (counter[s[i] - 'a'] == 1) return i;
        return -1;
    }
};
