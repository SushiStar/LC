/*
 * There is a new alien language which uses the latin alphabet. However, the
 * order among letters are unknown to you. You receive a list of non-empty words
 * from the dictionary, where words are sorted lexicographically by the rules of
 * this new language. Derive the order of letters in this language.
 *
 * Date: 03/27/2020
 * Author: Wei Du
 */
class Solution {
public:
    string alienOrder(vector<string> &words) {
        std::vector<CH *> characters(26);
        int counter{0};
        for (auto &w : words) {
            for (auto ch : w) {
                characters[ch - 'a'] = new CH(ch);
            }
        }
        for (int i = 1; i < words.size(); ++i) {
            int row{0};
            int smaller = std::min(words[i - 1].size(), words[i].size());
            while (row < smaller && words[i - 1][row] == words[i][row]) {
                ++row;
            }
            if (row < smaller) { // then words[i-1][row] > words[i][row]
                auto higher = characters[words[i - 1][row] - 'a'];
                auto lower = characters[words[i][row] - 'a'];
                // auto phigher =
                higher->next = lower;
                lower->prev = higher;
                lower->rank = std::min(higher->rank - 1, lower->rank);
                while (lower->next) {
                    lower->next->rank = lower->rank - 1;
                    lower = lower->next;
                    if (lower == higher) {
                        return std::string("");
                    }
                }
            } else if (words[i - 1].size() > words[i].size()) {
                return std::string("");
            }
        }
        std::string result("");
        std::sort(characters.begin(), characters.end(), cmp());
        for (auto ptr : characters) {
            if (ptr) {
                result.append(1, ptr->ch);
            }
        }
        return result;
    }

private:
    struct CH {
        CH(char ch_) : ch(ch_), prev(nullptr), next(nullptr) {}
        char ch;
        CH *prev, *next;
        int rank{0};
    };
    struct cmp {
        bool operator()(CH *a, CH *b) {
            if (a == nullptr) return false;
            if (b == nullptr) return true;
            return a->rank > b->rank;
        }
    };
};
