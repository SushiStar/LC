/*
 * You're given strings J representing the types of stones that are jewels, and
 * S representing the stones you have.
 * Each character in S is a type of stone you have.
 * You want to know how many of the stones you have are also jewels.
 */

class Solution {
public:
    int numJewelsInStones(string J, string S)
    {
        unordered_map<char, int> mapp;
        for (auto s : S) map[s]++;
        int res = 0;
        for (auto j : J) res += map[j];
        return res;
    }
};
