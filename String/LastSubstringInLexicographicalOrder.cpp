/*
 * Given a string s, return the last substring of s in lexicographical order.
 *  
 * 1 <= s.length <= 4*10^5
 * s contains only lowercase English letters.
 *
 * Date: 05/22/2020
 * Author: Wei Du
 */

#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution_TLE {
public:
    string lastSubstring(string s) {
        std::vector<std::vector<int>> char_location(128);
        for (int i = 0; i < s.size(); ++i) {
            char_location[s[i]].push_back(i);
        }
        char last(127);
        for (; last > 0; --last) {
            if (!char_location[last].empty())
                break;
        }
        std::vector<std::string> candidates{};
        for (int idx : char_location[last]) {
            candidates.push_back(s.substr(idx));
        }
        std::sort(candidates.begin(), candidates.end());
        return candidates[0];
    }
};

class Solution {
public:
    string lastSubstring(string s) {
        int n=s.length(),i=0,j=1,k=0;
        while(j+k<n)
        {
            if(s[i+k]==s[j+k]) k++; 
            else if(s[i+k]<s[j+k]) i=j++,k=0;
            else j+=k+1,k=0;
        }
        return s.substr(i);
    };
};


