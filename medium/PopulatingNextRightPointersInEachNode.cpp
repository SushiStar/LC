/*
 * You are given a perfect binary tree where all leaves are on the same
 * level, and every parent has two children. The binary tree has the
 * following definition:
 * struct Node {
 *      int val;
 *      Node *left;
 *      Node *right;
 *      Node *next;
 * };
 * Populate each next pointer to point to its next right node. If there
 * is no next right node, the next pointer should be set to NULL. Initially,
 * all next pointers are set to NULL.
 *
 * Date: Apr/23/2019
 * Author: Wei Du
 */
#include <vector>

// probably BFS
class Solution {
public:
    Node* connect(Node* root) {
        if (!root) return root;
        std::vector<Node*> one{root};
        std::vector<Node*> two;
        while (!one.empty()) {
            int sz = one.size();
            one.push_back(nullptr);
            for (int i = 0; i < sz; ++i) {
                one[i]->next = one[i + 1];
                if (one[i]->left) {     // evey parent is complete
                    two.push_back(one[i]->left);
                    two.push_back(one[i]->right);
                }
            }
            one.clear();
            one = std::move(two);
            two.clear();
        }
        return root;
    }
};
