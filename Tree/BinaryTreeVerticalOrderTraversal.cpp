/*
 * Given a binary tree, return the vertical order traversal of its nodes'
 * values. (ie, from top to bottom, column by column).
 * If two nodes are in the same row and column, the order should be from 
 * left to right. 
 * 
 * Date: 05/17/2020
 * Author: Wei Du
 */
#include <vector>
#include <unordered_map>
using namespace std;

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

class Solution {
public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        std::vector<std::vector<int>> ret{};
        if (!root) return ret;
        std::unordered_map<TreeNode*, int> colIdx;
        std::unordered_map<int, std::vector<int>> colLine;
        colIdx[root] = 0;
        std::vector<TreeNode*> bfsCurr{root};
        std::vector<TreeNode*> bfsNext{};
        while (!bfsCurr.empty()) {
            for (TreeNode* parent : bfsCurr) {
                colLine[colIdx[parent]].push_back(parent->val);
                if (parent->left) {
                    bfsNext.push_back(parent->left);
                    colIdx[parent->left] = colIdx[parent]-1;
                }
                if (parent->right) {
                    bfsNext.push_back(parent->right);
                    colIdx[parent->right] = colIdx[parent]+1;
                }
            }
            bfsCurr.clear();
            std::swap(bfsCurr, bfsNext);
        }
        int minIdx(INT_MAX), maxIdx(INT_MIN);
        for (auto &pr : colLine) {
            maxIdx = std::max(maxIdx, pr.first);
            minIdx = std::min(minIdx, pr.first);
        }
        ret.resize(maxIdx-minIdx+1);
        for (auto &pr : colLine) {
            ret[pr.first-minIdx] = pr.second;
        }
        return ret;
    }
};
