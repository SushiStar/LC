/*
 * There is a box protected by a password is a sequence of n digits where
 * each digit can be one of the first k digits 0, 1, ..., k-1.
 *
 * While entering password, the last n digits entered will automatically be
 * matched against the correct password.
 *
 * For example, assuming the correct password is "345", if you type "012345",
 * the box will open because the correct password matches the suffix of the
 * entered password.
 *
 * Return any password minimum length that is guaranteed to open the box at
 * some point of entering it.
 *
 * Date: 05/26/2020
 * Author: Wei Du
 */
#include <queue>
#include <string>
#include <unordered_set>
using namespace std;

class Solution {
public:
    string crackSafe(int n, int k) {
        // n numbers in range [0, k-1]
        if (n == 1) {
            std::string ret{""};
            for (int i = 0; i < k; ++i) {
                ret += ('0' + i);
            }
            return ret;
        }

        char endNum('0' + k);
        std::unordered_set<std::string> sett;
        std::vector<std::string> copysett;

        sett.insert(std::string(n, '0'));
        copysett.push_back(std::string(n, '0'));
        // find all the numbers
        for (int i = 0; i < copysett.size(); ++i) {
            auto tmpStr = copysett[i].substr(1);
            for (char i = '0'; i < endNum; ++i) {
                tmpStr.push_back(i);
                if (sett.find(tmpStr) == sett.end()) {
                    sett.insert(tmpStr);
                    copysett.push_back(tmpStr);
                }
                tmpStr.pop_back();
            }
        }

        // combine all the numbers
        std::string ret;
        bool restart(true);
        while (!sett.empty()) {
            if (restart) 
                ret+=*(sett.begin());
            std::string nxt{ret.substr(ret.size() - n + 1)};
            char i = '0';
            for (; i < endNum; ++i) {
                nxt.push_back(i);
                if (sett.find(nxt) != sett.end()) {
                    ret += i;
                    sett.erase(nxt);
                    restart = false;
                    break;
                }
                nxt.pop_back();
            }
            if (i == endNum) {
                restart = true;
            }
        }
        return ret;
    }
};
