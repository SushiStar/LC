/**
 *
 */
class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words)
    {
        vector<string> ms{".-",   "-...", "-.-.", "-..",  ".",    "..-.", "--.",
                          "....", "..",   ".---", "-.-",  ".-..", "--",   "-.",
                          "---",  ".--.", "--.-", ".-.",  "...",  "-",    "..-",
                          "...-", ".--",  "-..-", "-.--", "--.."};

        unordered_set<string> sett{};
        for (auto x : words) {
            string tmp{};
            for (auto m : x) {
                tmp += ms.at(m - 97);
            }
            sett.insert(tmp);
        }
        return sett.size();
    }
};
