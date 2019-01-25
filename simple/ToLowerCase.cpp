/*
 *
 */

class Solution {
public:
    string toLowerCase(string str) {
        for (auto &s:str) s = tolower(s);
        return str;
    }
};
