/*
 * Given n pairs of aprentheses, write a function to generate all
 * combinations of well-formed partheses.
 *
 * Date: 04/30/2020
 * Author: Wei Du
 */
#include <string>
#include <vector>

class Solution {
public:
    std::vector<std::string> generateParenthesis(int n) {
        std::vector<std::string> ret;
        addBrackets(std::string(""), n, n, ret);
        return ret;
    }

private:
    void addBrackets(std::string str, int left, int right,
            std::vector<std::string> &ret) {
        if (left) addBrackets(str+'(', left-1, right, ret);
        if (right > left) addBrackets(str+')', left, right-1, ret);
        if (!right) ret.push_back(str);
    }
};
