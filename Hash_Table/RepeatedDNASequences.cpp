/*
 * All DNA is composed of a series of nucleotides abbreviated as
 * A, C, G, and T, for example"ACGAATTCCG". When studying DNA, it
 * is sometimes useful to identify repeated sequences within the
 * DNA.
 *
 * Write a function to find all the 10-letter-long sequences (substring)
 * that occur more than once in a DNA molecule.
 *
 * Date: 04/17/20202
 * Author: Wei Du
 */
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        std::vector<string> rlt{};
        if (s.size() < 11) return rlt;
        std::unordered_map<std::string, int> exist;
        std::string buffer(s.substr(0, 10));
        exist[buffer] = 1;
        for (int i = 10; i < s.size(); ++i) {
            buffer.erase(buffer.begin());
            buffer += s[i];
            if (exist[buffer] == 1) {
                rlt.push_back(buffer);
            }
            ++exist[buffer];
        }
        return rlt;
    }
};

