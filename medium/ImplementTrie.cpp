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
    Trie() { root = new Node(); }

    /** Inserts a word into the trie. */
    void insert(string word) { int res = insert(word, root); }

    /** Returns if the word is in the trie. */
    bool search(string word) { return search(word, root); }

    /** Returns if there is any word in the trie that starts with the given
     * prefix. */
    bool startsWith(string prefix) { return startsWith(prefix, root); }

private:
    struct Node;
    bool startsWith(string prefix, Node* root) {
        if (root->wd.find(prefix) != 0 && root->real) {
            return true;
        }

        if (prefix.find(root->wd) != std::string::npos) {  
            // possibly in children
            int sz = root->children.size();
            for (int i = 0; i < sz; ++i) {
                if (startsWith(prefix, root->children[i])) return true;
            }
        }
        // current word not contain prefix, return false;
        return false;
    }

    bool search(string word, Node* root) const {
        if (root->wd == word) return root->real;
        if (std::string::npos != word.find(root->wd)) {
            int sz = root->children.size();
            for (int i = 0; i < sz; ++i) {
                if (search(word, root->children[i])) return true;
            }
        }
        return false;
    }

    bool insert(string word, Node* root) {
        if (word == root->wd) {
            root->real = true;
            return true;
        }
        if (word.find(root->wd) == 0 ) {
            for (int i = 0; i < root->children.size(); ++i) {
                if (insert(word, root->children[i])) return true;
            }
        } else {
            create_insert(word, root);
        }
        return true;
    }
    void create_insert(string word, Node* root) {
        if (root->wd == word) {
            root->real = true;
            return;
        }
        int sz = root->wd.size();
        char tmp = word[sz];
        Node* newNode = new Node(root->wd+tmp);
        create_insert(word, root);
    }

    struct Node {
        std::string wd;
        bool real;
        std::vector<Node*> children;
        Node() : wd(""), real(false) {}
        Node(std::string in) : wd(in), real(false) {}
    };
    Node* root;
};
