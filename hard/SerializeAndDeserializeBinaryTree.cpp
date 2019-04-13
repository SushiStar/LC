/*
 * Serialization is the process of converting a data structure or object into
 * a sequence of bits so that it can be stored in a file or memory buffer, or
 * transmitted across a network connection link to be reconstructed later in
 * the same or another computer environment.  Design an algorithm to serialize
 * and deserialize a binary tree. There is no restriction on how your
 * serialization/deserialization algorithm should work. You just need to ensure
 * that a binary tree can be serialized to a string and this string can be
 * deserialized to the original tree structure.
 *
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 *
 * Date: Apr/12/2019
 * Author: Wei Du
 */
#include <iostream>
#include <queue>
#include <string>
#include <vector>

class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        std::string res("");
        std::queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            auto tmp = q.front();
            q.pop();
            if (tmp) {
                q.push(tmp->left);
                q.push(tmp->right);
                res += std::to_string(tmp->val);
                res += ",";
            } else {
                res += "null,";
            }
        }

        while (res[res.size() - 2] == 'l') {
            res.erase(res.size() - 5);
        }

        // remove the comma
        if (!res.empty()) res.erase(res.size() - 1);
        res.insert(0, 1, '[');
        res += "]";
        std::cout << res << std::endl;
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data == "[]") return nullptr;
        std::vector<TreeNode*> res;
        arrayParser(data, res);
        int l(0), r(0);
        while (r < res.size()) {
            if (!res[l]) {
                ++l;
                continue;
            }
            res[l]->left = res[r];
            ++r;
            if (r >= res.size()) break;
            res[l]->right = res[r];
            ++r;
            ++l;
        }
        return res[0];
    }

private:
    void arrayParser(string data, vector<TreeNode*>& res) {
        // remove brackets
        data.insert(data.size() - 1, 1, ',');
        int sz = data.size() - 1;
        int i(1);
        std::string num("");
        while (i < sz) {
            if (data[i] != ',') {
                num += data[i];
            } else {
                if (num.back() == 'l') {
                    res.push_back(nullptr);
                } else {
                    TreeNode* temp = new TreeNode(std::stoi(num));
                    res.push_back(temp);
                }
                num.clear();
            }
            ++i;
        }
    }
};
