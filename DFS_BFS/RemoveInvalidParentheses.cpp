/*
 * Remove the minimum number of parentheses in order to make the
 * input string valid. Return all possible results.
 * Note: the input may contain letters other than the parentheses.
 *
 * The logic is: 1) The unbalanced bracket is '(', delete '(' from now on
 *                  till the next unbalanced mark.
 *               2) The balanced bracket is ')', delete ')' from now on
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
    void removeR(string s, std::vector<string> &res) {
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
        } else { // s[t] == '('
            // t2 = (t2 == -1) ? s.size() : t2;
            t2 = s.size();
            while (t < t2) {
                if (s[t] == '(' && (s[t + 1] != '(' || t + 1 == t2)) {
                    auto tmp = s;
                    tmp.erase(t, 1);
                    removeR(tmp, res);
                }
                ++t;
            }
        }
    }
    std::array<int, 2> getInvalid(const string &s) {
        std::vector<int> sk;
        std::array<int, 3> res = {-1, -1};
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
        switch (sz) {
        case 0:
            break;
        case 1:
            res[0] = sk[0];
            break;
        default:
            if (s[res[0]] == '(') res[0] = sk[0];
            res[1] = sk[1];
            break;
        }
        return res;
    }
};


// better idea
class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        std::vector<std::string> result{};
        std::vector<std::string> result1{};
        if (s.empty()) {
            result.push_back(std::string(""));
            return result;
        }
        removeR(s, result1, 0);
        for (auto &s : result1) {
            removeL(s, result, s.size()-1);
        }
        return result;
    }
private:
    void removeR(std::string s, std::vector<std::string> & result, int start) {
        int left{0}, right{0};
        int curr{0};
        while (curr < (int)s.size() && left >= right) {
            if (s[curr] == ')') {
                ++right;
            } else if (s[curr] == '(') {
                ++left;
            }
            ++curr;
        }
        curr = std::min(curr, (int)s.size()-1);
        if (right > left && curr < (int)s.size()) {  // still ')' to be removed
            for (int i = start; i <= curr; ++i){ 
                if (s[i] == ')' && (i==start || s[i-1] != ')')) {
                    std::string duplicate{s};
                    duplicate.erase(i, 1);
                    removeR(duplicate, result, i);
                }
            }
        } else {
            result.push_back(s);
        }
    }
    
    void removeL(std::string s, std::vector<std::string>& result, int start) {
        int left{0}, right{0};
        int curr((int)s.size()-1);
        while (curr > -1 && left <= right) {
            if (s[curr] == ')') {
                ++right;
            } else if (s[curr] == '('){
                ++left;
            }
            --curr;
        }
        if (curr < 0) curr = 0;
        if (left > right){
            for (int i = start; i >= curr; --i){ 
                if (s[i] == '(' && (i==start || s[i+1] != '(')) {
                    std::string duplicate{s};
                    duplicate.erase(i,1);
                    removeL(duplicate, result, i-1);
                }
            }
        } else {
            result.push_back(s);
        }
    }
    
};

// even better
class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        std::vector<std::string> result{};
        std::vector<std::string> result1{};
        removeR(s, result1, 0,0);
        for (auto &s : result1) {
            removeL(s, result, s.size()-1,s.size()-1);
        }
        if (result.empty()){ 
            result.push_back(std::string(""));
        }
        return result;
    }
private:
  void removeR(std::string& s, std::vector<std::string> & result, int last_i, int last_j) {
        for (int stk{0}, i = last_i; i < (int)s.size(); ++i ) {
            if (s[i] == '(') ++stk;
            else if (s[i] == ')') --stk;
            if (stk > -1)  continue;
            // ')' more than '('
            for (int j = last_j; j <= i; ++j) {
                // always delete the first occurrence of ')' to avoid reapeating
                if (s[j] == ')' && (j == last_j|| s[j-1] != ')')) {
                    // i, j position is where get wrong, now fix it,
                    // then the new string fron 0 to i should be fine
                    // the last delete place is j, you cannot delete anything before j
                    // in case of repeating
                    auto duplicate(s);
                    duplicate.erase(j,1);
                    removeR(duplicate, result,i,j);
                }
            }
            return;
        }
        result.push_back(s);
    }

    void removeL(std::string& s, std::vector<std::string>& result, int last_i, int last_j) {
        for (int stk{0}, i = last_i; i > -1; --i){
            if (s[i] == '(') ++stk;
            else if (s[i] == ')') --stk;
            if (stk < 1) continue;

            // '(' more than ')'
            for (int j =  last_j; j >= i; --j) {
                // always delete the first occurrence of '(' to avoid repeating
                if (s[j] == '(' && (j == last_j || s[j+1] != '(')) {
                    // i, j position is where get wrong, now fix it,
                    // then the new string from the end to current i-1 should be fine
                    // the last delete place is j, you cannot delete anything after j
                    // in case of repeating
                    auto duplicate(s);
                    duplicate.erase(j,1);
                    removeL(duplicate, result, i-1,j);
                }
            }
            return;
        }
        result.push_back(s);
    }
};
