/*
 * Given a list of unique words, find all pairs of distinct
 * indices (i, j) in the given list, so that the concatenation
 * of the two words, i.e. words[i]+words[j] is a palindrome.
 *
 * Date: 04/17/2020
 * Author: Wei Du
 */

// O(n^2);
class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string> &words) {
        std::vector<std::vector<int>> rlt{};
        for (int i = 0; i < words.size(); ++i) {
            for (int j = i + 1; j < words.size(); ++j) {
                std::string s1 = words[i] + words[j];
                std::string s2 = words[j] + words[i];
                if (isPalindrome(s1)) rlt.push_back(std::vector<int>{i, j});
                if (isPalindrome(s2)) rlt.push_back(std::vector<int>{j, i});
            }
        }
        return rlt;
    }

private:
    // 0 undecided, 1 true, -1 false;
    std::unordered_map<std::string, int> strState;
    bool isPalindrome(const std::string &s) {
        if (strState[s] == 0) {
            int whole(s.size());
            int half(whole / 2);
            --whole;
            strState[s] = 1;
            for (int i = 0; i < half; ++i) {
                if (s[i] == s[whole - i])
                    continue;
                else {
                    strState[s] = -1;
                    break;
                }
            }
        }
        return strState[s] == 1;
    }
};

class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>> result;
        unordered_map<string, int> dict;
        for(int i = 0; i < words.size(); i++) {
            dict[words[i]] = i;
        }
        for(int i = 0; i < words.size(); i++) {
            for(int j = 0; j <= words[i].length(); j++) {
                //check the suffix word
                if(is_palindrome(words[i], j, words[i].size() - 1)) {
                    /** the suffix word can be null to all the word **/
                    string suffix = words[i].substr(0, j);
                    reverse(suffix.begin(), suffix.end());
                    if(dict.find(suffix) != dict.end() && i != dict[suffix]) {
                        result.push_back({i, dict[suffix]});
                    }
                }
                //check the prefix word 
                if(j > 0 && is_palindrome(words[i], 0, j - 1)) {
                    string prefix = words[i].substr(j);
                    reverse(prefix.begin(), prefix.end());
                    if(dict.find(prefix) != dict.end() && dict[prefix] != i) {
                        result.push_back({dict[prefix], i});
                    }
                }
            }
        }
        return result;
    }
    
    bool is_palindrome(string& s, int start, int end) {
        while(start < end) {
            if(s[start++] != s[end--]) {
                return false;
            }
        }
        return true;
        
    }
};
