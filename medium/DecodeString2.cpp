/*
 * Given an encoded string, return it's decoded string
 * 
 * Date: Apr/18/2019
 * Author: Wei Du
 */
#include<string>
#include<cstdlib>
#include<vector>

class Solution {
public:
    string decodeString(string s) {
        std::string res("");
        int l(0),r(0),nump(0);
        while (l < s.size()) {
            if (s[l] == '[') {  // found a subcode
                nump++;
                r = l;
                while (nump) {
                    ++r;
                    if (s[r] == ']') --nump;
                    if (s[r] == '[') ++nump;
                }
                auto subs = getSubstr(s, l, r);
                int k = (int)s[l-1]-48;
                for (int i = 0; i < k; ++i) res+=subs;
                l = r;
            }
            ++l;
        }
        return res;
    }
private:
    // s[left] = '['
    // s[right] = ']'
    std::string getSubstr(const string& s,int left,int right) {
        std::string res="";
        int l = left+1;
        while(s[l] != '[' && l < right) ++l;
        if (l < right) {        // there's sub-code
            int r = right-1;
            while(s[r]!=']') --r;
            int times = (int)s[l-1]-48;
            auto sub = getSubstr(s, l, r);
            for (int i = 0; i < times; ++i) {
                res+=sub;
            }
        } else {
            res+=s.substr(left+1, right-left-1);
        }
        return res;
    }
};
