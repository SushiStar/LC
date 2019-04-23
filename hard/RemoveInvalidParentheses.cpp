/*
 * Remove the minimum number of parentheses in order to make the
 * input string valid. Return all possible results.
 * Note: the input may contain letters other than the parentheses.
 *
 * The logic is: 1) The unbalanced bracket is '(', delete '(' from now on
 *                  till the next unbalanced mark.
 *               2) The balanced bracket is ')', delte ')' from now on
 *                  to the forward unbalanced mark.
 *
 * Date: Apr/17/2019
 * Author: Wei Du
 */
#include <array>
#include <string>
#include <vector>

class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        std::vector<string> res;
        if (!s.empty()) removeR(s, res);
        if (res.empty()) res.push_back("");
        return res;
    }

private:
    void removeR(string s, std::vector<string>& res) {
        auto tt = getInvalid(s);
        int t(tt[0]), t2(tt[1]);
        if (t[0] == -1) {
            res.push_back(s);
            return;
        }
        if (s[t] == ')') {
            if (t == 0) {
                auto tmp = s;
                tmp.erase(0, 1);
                removeR(tmp, res);
            } else {
                while (t > 0) {
                    if (s[t] == ')' && s[t] != s[t - 1]) {
                        auto tmp = s;
                        tmp.erase(t, 1);
                        removeR(tmp, res);
                    }
                    --t;
                }
            }
        } else {  // s[t] == '('
            //t2 = (t2 == -1) ? s.size() : t2;
            t2 = s.size();
            while (t < t2) {
                if (s[t] == '(' && (s[t + 1] != '('|| t+1 == t2)) {
                    auto tmp = s;
                    tmp.erase(t, 1);
                    removeR(tmp, res);
                }
                ++t;
            }
        }
    }
    std::array<int,2> getInvalid(const string& s) {
        std::vector<int> sk;
        std::array<int,3> res = {-1,-1};
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') sk.push_back(i);
            if (s[i] == ')') {
                if (!sk.empty() && s[sk.back()] == '(')
                    sk.pop_back();
                else
                    sk.push_back(i);
            }
        }
        int sz = sk.size();
        switch(sz) {
            case 0 : 
                break;
            case 1 :
                res[0] = sk[0];
                break;
            default:
                if (s[res[0]] == '(')
                res[0] = sk[0];
                res[1] = sk[1];
                break;
        }
        return res;
    }
};

class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        std::unordered_set<string> ret;
        if (!s.empty()) removeR(s, ret);
        if (ret.empty()) ret.insert("");
        std::vector<string> res;
        for (auto i : ret) { res.push_back(i); }
        return res;
    }

private:
    void removeR(string s, std::unordered_set<string>& res) {
        auto tt = getInvalid(s);
        int t(tt[0]), t2(tt[1]);
        if (t == -1) {
            res.insert(s);
            return;
        }
        if (s[t] == ')') {
            if (t == 0) {
                auto tmp = s;
                tmp.erase(0, 1);
                removeR(tmp, res);
            } else {
                while (t > 0) {
                    if (s[t] == ')' && s[t] != s[t - 1]) {
                        auto tmp = s;
                        tmp.erase(t, 1);
                        removeR(tmp, res);
                    }
                    --t;
                }
            }
        } else {  // s[t] == '('
//            t2 = (t2 == -1) ? s.size() : t2;
            t2 = s.size();
            while (t < t2) {
                if (s[t] == '(' && (s[t + 1] != '(' || t+1 ==t2)) {
                    auto tmp = s;
                    tmp.erase(t, 1);
                    removeR(tmp, res);
                }
                ++t;
            }
        }
    }
    std::array<int,2> getInvalid(const string& s) {
        std::vector<int> sk;
        std::array<int,2> res = {-1,-1};
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') sk.push_back(i);
            if (s[i] == ')') {
                if (!sk.empty() && s[sk.back()] == '(')
                    sk.pop_back();
                else
                    sk.push_back(i);
            }
        }
        int sz = sk.size();
        switch(sz) {
            case 0 : 
                break;
            case 1 :
                res[0] = sk[0];
                break;
            default:
                if (sk[0] == '(') {
                    res[0] == sk.back();
                    res[1] == -1;
                } else {
                    res[0] = sk[0];
                    res[1] = sk[1];                   
                }
                break;
        }
        return res;
    }
};

