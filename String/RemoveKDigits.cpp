/*
 * Given a non-negative integer num represented as a string, remove k
 * digits from the number so that the new number is the smallest possible.
 *
 * The length of num is less than 10002 and will be >= k.
 * The given num does not contain and leading zero.
 *
 * Date: 05/13/2020
 * Author: Wei Du
 */
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

// TLE
class Solution {
public:
    string removeKdigits(string num, int k) {
        std::string ret = removeAction(num, k);
        if (ret.empty()) ret += '0';
        while (ret.size() > 1 && ret[0] == '0')
            ret.erase(0, 1);
        return ret;
    }

private:
    std::unordered_map<std::string, std::unordered_map<int, std::string>> dp;
    string removeAction(std::string num, int k) {
        if (k == 0)
            return num;
        else if (k == num.size())
            return "";
        if (dp[num].find(k) != dp[num].end()) return dp[num][k];
        std::string ret{num};
        for (int i = 0; i <= num.size() - k; ++i) {
            std::string strLeft = num.substr(0, i);
            std::string strRight = num.substr(i + 1);
            std::string tmpRet = strLeft + removeAction(strRight, k - 1);
            if (tmpRet.size() < ret.size() || tmpRet < ret) {
                ret = tmpRet;
            }
        }
        dp[num][k] = ret;
        return ret;
    }
};

class Solution1 {
public:
    string removeKdigits(string num, int k) {
        std::string ret = removeAction(num, k);
        if (ret.empty()) ret += '0';
        while (ret.size() > 1 && ret[0] == '0')
            ret.erase(0, 1);
        return ret;
    }

private:
    std::string removeAction(std::string num, int k) {
        if (k == num.size())
            return "";
        else if (k <= 0)
            return num;
        size_t i = 0;
        while (i < num.size() - k && num[i] <= num[i + 1]) {
            ++i;
        }
        num = num.erase(std::min(i, num.size() - 1), 1);
        return removeAction(num, k - 1);
    }
};

class Solution2 {
public:
    string removeKdigits(string num, int k) {
        if (k == num.size()) return "0";

        std::string ret{num[0]};
        for (int i = 1; i < num.size(); ++i) {
            while (k > 0 && !ret.empty() && num[i] < ret.back()) {
                ret.pop_back();
                --k;
            }
            ret += num[i];
        }
        while (k > 0 && !ret.empty()) {
            ret.pop_back();
            --k;
        }
        while (!ret.empty() && ret[0] == '0')
            ret.erase(0, 1);
        if (ret.empty()) ret += '0';
        return ret;
    }
};
