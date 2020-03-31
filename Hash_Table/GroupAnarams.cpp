/*
 * Given an array of strings, group anagrams together.
 * All inputs will be in lowercase.
 *
 * Date: 03/04/2020
 *
 * Author: Wei Du
 */

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs) {
        std::vector<std::vector<std::string>> rlt;
        if (strs.empty()) return rlt;
        std::unordered_map<std::string, int> strIdx;
        for (auto &str : strs) {
            std::string temp{str};
            std::sort(temp.begin(), temp.end());
            if (strIdx.find(temp) == strIdx.end()) {
                strIdx[temp] = rlt.size();
                rlt.push_back(std::vector<std::string>{str});
            } else {
                rlt[strIdx[temp]].push_back(str);
            }
        }
        return rlt;
    }
};
