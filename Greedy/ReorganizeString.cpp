/*
 * Given a string S, check if the letters can be rearranged so that two
 * characters that are adjacent to each other are not the same. If possible,
 * output any possible result. If not possible, return empty string.
 *
 * Date: 04/08/2020
 * Author: Wei Du
 */
class Solution {
public:
    string reorganizeString(string S) {
        if (S.empty()) return S;
        std::string result(S.size(), '.');
        std::unordered_map<char, int> count;
        for (auto ch : S)
            ++count[ch];
        std::priority_queue<numChar, std::vector<numChar>, cmpCh> pq;
        for (auto &ele : count)
            pq.push(ele);

        int pst{0};
        int len(S.size());
        while (!pq.empty()) {
            char curr = pq.top().first;
            int num = pq.top().second;
            pq.pop();
            while (num > 0) {
                --num;
                while (result[pst] != '.') {
                    ++pst;
                    pst %= len;
                }
                if ((pst > 0 && result[pst - 1] == curr) ||
                    (pst < len - 1 && result[pst + 1] == curr)) {
                    return std::string("");
                }
                result[pst] = curr;
                pst += 2;
                pst %= len;
            }
        }
        return result;
    }

private:
    typedef std::pair<char, int> numChar;
    struct cmpCh {
        bool operator()(const numChar &a, const numChar &b) const {
            return a.second < b.second;
        }
    };
};
