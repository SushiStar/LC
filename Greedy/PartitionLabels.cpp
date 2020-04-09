/*
 * A string s of lowercase letters is given. We want to partition this string
 * into as many parts as possible so that each letter appears in at most one
 * part, and return a list of integers representing the size of these parts.
 *
 * Date: 04/08/2020
 * Author: Wei Du
 */
class Solution {
public:
    vector<int> partitionLabels(string S) {
        std::vector<int> rlt{};
        if (S.empty()) return rlt;
        std::vector<std::vector<int>> positions(26, std::vector<int>{});
        for (int i = 0; i < S.size(); ++i)
            positions[S[i] - 'a'].push_back(i);
        std::sort(positions.begin(), positions.end());
        int lastEnd{0};
        int start{0};
        for (auto &v : positions) {
            if (v.empty()) continue;
            if (v[0] <= lastEnd) {
                lastEnd = std::max(lastEnd, v.back());
            } else {
                rlt.push_back(lastEnd - start + 1);
                start = v[0];
                lastEnd = v.back();
            }
        }
        rlt.push_back(lastEnd - start + 1);
        return rlt;
    }
};

class Solution {
public:
    vector<int> partitionLabels(string S) {
        std::vector<int> rlt{};
        if (S.empty()) return rlt;
        std::vector<int> lstP(26, 0);
        for (int i = 0; i < S.size(); ++i)
            lstP[S[i] - 'a'] = i;

        int counter{0};
        int lastEnd{0};
        for (int i = 0; i < S.size(); ++i) {
            if (lastEnd < i) {
                rlt.push_back(counter);
                counter = 0;
                lastEnd = lstP[S[i] - 'a'];
            }
            lastEnd = std::max(lastEnd, lstP[S[i] - 'a']);
            ++counter;
        }
        rlt.push_back(counter);
        return rlt;
    }
};
