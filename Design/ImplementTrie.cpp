/*
 * Implement a trie with insert, search, and startwith methods.
 *
 * You may assume that all inputs are consist of lowercase letters.
 * All inputs are guaranteed to be non-empty strings.
 *
 * Date: 05/06/2020
 * Author: Wei Du
 */
#include <string>
#include <vector>
using namespace std;

class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
        head = new node('!');
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        node* upper(head);
        for (int i = 0; i < word.size(); ++i) {
            if (!upper->children[word[i]]) 
                upper->children[word[i]] = new node(word[i]);
            upper = upper->children[word[i]];
        }
        upper->isEnd = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        node* curr(head);
        for (int i = 0; i < word.size() && curr; ++i)
            curr = curr->children[word[i]];
        if (!curr) return false;
        return (curr->val == word.back() &&  curr->isEnd);
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        node* curr(head);
        for (int i = 0; i < prefix.size() && curr; ++i)
            curr = curr->children[prefix[i]];
        return curr;
    }
private:
    struct node {
        node(char val_) :val(val_), isEnd(false), children(128) {}
        char val;
        bool isEnd;
        std::vector<node*> children;
    };
    node* head;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
