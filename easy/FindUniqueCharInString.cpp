/*
 * Given a string find the first non-repeating character in it and return
 * its index.
 * If it doesn't return -1.
 *
 * Author: Wei Du
 *
 * Date: Mar/12/2019
 *
 */

class Solution {
public:
    int firstUniqChar(string s) {
        int size = s.size();
        int res = -1;
        if (size == 0) return res;

        std::unordered_map<char, int> container;
        for(int i = 0; i < size; ++i) {
            container[s[i]]++;
        }

        for(int i = 0; i < size; ++i) {
            if(container[s[i]] == 1) return i;
        }
        return res;
    }
};
