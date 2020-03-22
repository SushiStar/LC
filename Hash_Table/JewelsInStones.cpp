/*
 * You're given strings J representing the types of stones that are jewels, and
 * S representing the stones you have.
 * Each character in S is a type of stone you have.
 * You want to know how many of the stones you have are also jewels.
 * 
 * Date: 03/22/2020
 * Author: Wei Du
 */

class Solution {
public:
    int numJewelsInStones(string J, string S) {
        int result{0};
        std::vector<int> mp(128, 0);
        for (auto ch : J) mp[ch] =  1;
        for (auto ch : S) {
            if (mp[ch] == 1){ 
                ++result;
            }
        }
        return result;
    }
};
