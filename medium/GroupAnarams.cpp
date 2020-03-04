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
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        if (strs.empty()) return res;

        std::unordered_map<size_t, int> cmb2res;
        for(auto tpstr:strs){ 
            auto key = hash_fn(tpstr);
            if (cmb2res.find(key)==cmb2res.end()) {
                int val = res.size();
                cmb2res[key] = val;
                std::vector<string> tmp{tpstr};
                res.push_back(tmp);
            } else {
                int val = cmb2res[key];
                res[val].push_back(tpstr);
            }
        }
        return res;
    }

    size_t hash_fn(string key) {
        std::sort(key.begin(), key.end());
        std::hash<std::string> hs;
        return hs(key);
    }
};
