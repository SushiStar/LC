/*
 * Given an binary tree where each path going from the root to any leaf
 * form a valid sequence, check if a given string is a valid sequence
 * in such binary tree.
 * We get the given string from the concatenate of an array of integers
 * arr and the concatenation of all values of the nodes along a path
 * results in a sequence in the given binary tree.
 *
 * Date: 04/30/2020
 * Author: Wei Du
 */
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool isValidSequence(TreeNode *root, vector<int> &arr) {
        return isValidSequence(root, arr, 0);
    }

private:
    bool isValidSequence(TreeNode *root, const vector<int> &arr, int start) {
        if (!root) return false;
        if (start == arr.size()-1)  {
            if (root->val == arr[start] && !root->left && !root->right) 
                return true;
            else 
                return false;
        }  else if (root->val == arr[start]) {
            return (isValidSequence(root, arr, start+1) ||
                    isValidSequence(root, arr, start+1));
        }
        return false;
    }
};
