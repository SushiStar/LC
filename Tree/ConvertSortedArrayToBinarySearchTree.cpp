/*
 * Given an array where elements are sorted in ascending order,
 * convert it to height balanced BST.
 * For this problem, a height-balanced binary tree is defined as
 * a binary tree in which the depth of the two subtrees of every
 * node never differe by more than 1.
 *
 * Date: 03/23/2020
 * Author: Wei Du
 */

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.empty()) return nullptr;
        return getRoot(nums,0,nums.size()-1);
    }
    TreeNode* getRoot(const std::vector<int>& nums, int l, int r) {
        if (l>r) return nullptr;
        if (l == r) {
            TreeNode* res = new TreeNode(nums[l]);
            return res;
        }
        int mid = (l+r)/2;
        TreeNode* res = new TreeNode(nums[mid]);
        res->left = getRoot(nums, l, mid-1);
        res->right = getRoot(nums, mid+1, r);
        return res;
    }
};
