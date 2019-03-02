/*
 * ZigZag Conversion
 *
 * Date: 01.31.2019
 */

class Solution {
public:
    string convert(string s, int numRows) {
        std::vector<string> contain;
        for (auto i = 0; i < numRows; ++i) contain.push_back("");

        if (numRows == 1) return s;
        int bound = numRows * 2 - 2;
        for (int i = 0; i < s.size(); ++i) {
            int k = i % bound;
            k = std::min(k, bound - k);
            contain.at(k) += s.at(i);
        }
        std::string res{""};
        for (auto &m : contain) res += m;
        return res;
    }
};
