/*
 * Design a data structure that supports the following two operations:
 * void addWord(word)
 * void search(word)
 * search(word) can search a literal word or a regular expression string
 * containing only letters a-z or ..
 * A . means it can represent any one letter.
 *
 * You may assume that all words are consist of lowercase letters a-z.
 *
 * Date: 05/23/2020
 * Author: Wei Du
 */
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class WordDictionary {
public:
    /** Initialize your data structure here. */
    WordDictionary() { root = new TrieNode('!'); }

    /** Adds a word into the data structure. */
    void addWord(string word) {
        TrieNode *curr = root;
        for (int i = 0; i < word.size(); ++i) {
            if (!curr->descendants[word[i]]) {
                curr->descendants[word[i]] = new TrieNode(word[i]);
            }
            curr = curr->descendants[word[i]];
        }
        curr->wordEnd = true;
    }

    /** Returns if the word is in the data structure. A word could contain the
     * dot character '.' to represent any one letter. */
    bool search(string word) {
        std::vector<TrieNode *> possibleNodesCurr{root};
        std::vector<TrieNode *> possibleNodesNext{};
        for (int i = 0; i < word.size(); ++i) {
            for (auto curr : possibleNodesCurr) {
                if (word[i] == '.') {
                    for (char ch = 'a'; ch <= 'z'; ++ch) {
                        if (curr->descendants[ch]) {
                            possibleNodesNext.push_back(curr->descendants[ch]);
                        }
                    }
                } else {
                    if (curr->descendants[word[i]]) {
                        possibleNodesNext.push_back(curr->descendants[word[i]]);
                    }
                }
            }
            if (possibleNodesNext.empty()) return false;
            possibleNodesCurr.clear();
            std::swap(possibleNodesNext, possibleNodesCurr);
        }
        if (possibleNodesCurr.empty()) return false;
        for (auto last_node : possibleNodesCurr) {
            if (last_node->wordEnd) return true;
        }
        return false;
    }

private:
    struct TrieNode {
        TrieNode(char val_) : val(val_), wordEnd(false), descendants(128) {}
        char val;
        bool wordEnd;
        std::vector<TrieNode *> descendants;
    };
    TrieNode *root;
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
