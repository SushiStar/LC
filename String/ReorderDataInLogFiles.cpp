/*
 * You have an array of logs. Each log is a space delimited string of words.
 * For each log, the identifier will consist only of lowercase letters, or;
 * Each word after the identifier will consist only of digits.
 *
 * We will call these two varieties of logs letter-logs and digit-logs. It
 * is guaranteed that each log has at least one word after its identifier.
 *
 * Reorder the logs so that all of the letter-logs come before any digit-log.
 * The letter-logs are ordered lexicographically ignoring identifier, with
 * the identifier used in case of ties. The digit-logs should be put in
 * their original order.
 * Return the final order of the logs.
 *
 * Date: 05/15/2020
 * Author: Wei Du
 */

#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        std::vector<std::string> retLetter{};
        std::vector<std::string> retNumber{};
        for (int i = 0; i < logs.size(); ++i) {
            char ch = logs[i][logs[i].find_first_of(' ')+1];
            if (ch <= '9') {
                retNumber.push_back(logs[i]);
            } else {
                retLetter.push_back(logs[i]);
            }
        }
        std::sort(retLetter.begin(), retLetter.end(), cmpString());
        retLetter.insert(retLetter.end(), retNumber.begin(), retNumber.end());
        return retLetter;
    }
private:
    struct cmpString {
        bool operator() (std::string &str1, std::string &str2) const {
            std::string s1 = str1.substr(str1.find_first_of(' ')+1);
            std::string s2 = str2.substr(str2.find_first_of(' ')+1);
            if (s1 < s2) {
                return true;
            } else if (s1 == s2) {
                return str1 < str2;
            } 
            return false;
        }
    };
};
