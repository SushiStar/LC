/*
 * Implement a trie with insert, search, and startsWith methods.
 * You may assume that all inputs are consist of lowercase letters
 * a-z. All inputs are guaranteed to be non-empty strings.
 *
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 *
 * Date:Apr/11/2019
 * Author: Wei Du
 */
#include <string>
#include <vector>
class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {}

    /** Inserts a word into the trie. */
    void insert(string word) {}

    /** Returns if the word is in the trie. */
    bool search(string word) {}

    /** Returns if there is any word in the trie that starts with the given
     * prefix. */
    bool startsWith(string prefix) {}

private:
    struct Node {
        std::string wd;
        Node* parent;
        std::vector<Node*> children;
        Node() : wd(""), parent(nullptr) {}
        Node(std::string in) : wd(in), parent(nullptr) {}
    };
    std::vector<Node*> root;
};
