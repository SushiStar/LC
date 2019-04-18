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
#include <string>
#include <set>
#include <vector>

class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        std::vector<string> res;
        if(s.empty()) return res;
        auto seg = unbalanced(s);
        if (seg.empty()) {
            res.push_back(s);
            return res;
        }
        // BFS
        std::vector<std::set<std::string>> segStrings;
        for (int i = 0; i < seg.size(); ++i) {
            std::set<std::string> thisSeg;
            auto target = s[seg[i]];
            int front, back;
            if (target == '(') {
                front = seg[i];
                back = i==seg.size()-1 ? s.size() : seg[i+1];
            }else if (target == ')'){
                front = i==0? 0 : seg[i-1];
                back = seg[i]+1;
            }
            auto segment = s.substr(front, back-front);
            for (int j = 0; j < segment.size(); ++j) {
                if (segment[j] == target) {
                    auto temp = segment;
                    temp.erase(j,1);
                    thisSeg.insert(temp);
                }
            }
            segStrings.push_back(thisSeg);
        }
        std::vector<std::string>* q1 = new std::vector<std::string>();
        std::vector<std::string>* q2 = new std::vector<std::string>();
        q1->push_back("");
        for (int k = 0; k < segStrings.size(); ++k) {
            for (auto it = segStrings[k].begin(); it!=segStrings[k].end(); ++it) {
                for (int j=0; j<q1->size(); ++j) {
                    q2->push_back(q1->at(j)+*it);
                }
            }
            auto temp = q1;
            q1=q2;
            q2=temp;
            q2->clear();
        }
        if (s[seg[0]] == '(') {
            auto bf = s.substr(0,seg[0]);
            for (int i = 0; i < q1->size(); ++i) {
                q1->at(i) = bf +q1->at(i);
            }
        }
        if (s[seg.back()] == ')') {
            auto bk = s.substr(seg.back()+1, s.size()-seg.back()-1 );
            for (int i =0; i < q1->size(); ++i) {
                q1->at(i)+=bk;
            }
        }
        return *q1;
    }

    std::vector<int> unbalanced(const string& s) {
        std::vector<int> sk;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                sk.push_back(i);
            } else if (s[i] == ')') {
                if (sk.empty() || s[sk.back()] == ')')
                    sk.push_back(i);
                else // s[sk.top()] = '('
                    sk.pop_back();
            }
        }
        return sk;
    }
};

