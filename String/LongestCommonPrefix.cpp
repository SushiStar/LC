/*
 * Write a function to find the longest common prefix string amongest
 * an array of strings.
 *
 * If there is no common prefix, return an empty string "".
 *
 * Date: 04/28/2020
 * Author: Wei Du
 */

class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        if (strs.empty()) return "";
        auto ret(strs[0]);
        for (int i = 1; i < strs.size(); ++i) {
            if (ret.size() > strs[i].size()) std::swap(ret, strs[i]);
            int counter(0);
            while (counter < ret.size() && ret[counter] == strs[i][counter])
                ++counter;
            ret.erase(counter);
            if (ret.empty()) return ret;
        }
        return ret;
    }
};
