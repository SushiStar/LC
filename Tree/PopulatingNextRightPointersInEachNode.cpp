/*
 * You are given a perfect binary tree where all leaves are on the
 * same level, and every parent has two children. The binary tree has
 * the following definition:
 * struct Node {
 *      int val;
 *      Node* left;
 *      Node* right;
 *      Node* next;
 * }
 *
 * Populate each next pointer to point its next right node. If there is
 * not next right node, the next pointer should be sett to NULL.
 * Initially, all next pointers are set to NULL.
 *
 * Date: 04/29/2002
 * Author: Wei Du
 */

class Solution {
public:
    Node *connect(Node *root) {
        if (!root) return root;
        std::vector<Node *> bfs[2];
        bfs[0].push_back(root);
        while (!bfs[0].empty()) {
            bfs[0].push_back(nullptr);
            for (int i = 0; i < bfs[0].size() - 1; ++i) {
                bfs[0][i]->next = bfs[0][i + 1];
                if (bfs[0][i]->left) bfs[1].push_back(bfs[0][i]->left);
                if (bfs[0][i]->right) bfs[1].push_back(bfs[0][i]->right);
            }
            bfs[0].clear();
            std::swap(bfs[0], bfs[1]);
        }
        return root;
    }
};
