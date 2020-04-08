/*
 * Given an integer array with no duplicates. A maximum tree building on
 * this array is defined as follow:
 *      1. The root is the maximum number in the array.
 *      2. The left subtree is the maxmium tree constructed from left part
 *      subarray divided by the maximum number.
 *      3. The right subtree is the maximum tree constructed from right part
 *      subarray divided by the maximum number.
 *
 * Construct the maximum tree by given an array and output the root node of
 * this tree.
 *
 * Date: 04/07/2020
 * Author: Wei Du
 */
// recursive way
class Solution {
public:
    TreeNode *constructMaximumBinaryTree(vector<int> &nums) {
        if (nums.empty()) return nullptr;
        maxInterval.resize(nums.size(), std::vector<int>(nums.size(), -1));
        for (int i = 0; i < nums.size(); ++i) {
            int tmpMax{nums[i]};
            int tmpMaxIdx{i};
            for (int j = i; j < nums.size(); ++j) {
                if (tmpMax < nums[j]) {
                    tmpMax = nums[j];
                    tmpMaxIdx = j;
                }
                maxInterval[i][j] = tmpMaxIdx;
            }
        }
        return constructSubTree(nums, 0, nums.size() - 1);
    }

private:
    std::vector<std::vector<int>> maxInterval;
    TreeNode *constructSubTree(const std::vector<int> &nums, int start,
                               int end) {
        if (start > end) return nullptr;
        if (start == end) {
            TreeNode *root = new TreeNode(nums[start]);
            return root;
        }
        int maxIdx = maxInterval[start][end];
        TreeNode *root = new TreeNode(nums[maxIdx]);
        root->left = constructSubTree(nums, start, maxIdx - 1);
        root->right = constructSubTree(nums, maxIdx + 1, end);
        return root;
    }
};

// iteratively
class Solution {
public:
    TreeNode *constructMaximumBinaryTree(vector<int> &nums) {
        if (nums.empty()) return nullptr;
        TreeNode *root = new TreeNode(nums[0]);
        for (int i = 1; i < nums.size(); ++i) {
            TreeNode *curr = new TreeNode(nums[i]);
            root = siftDown(root, curr);
        }
        return root;
    }

private:
    TreeNode *siftDown(TreeNode *root, TreeNode *curr) {
        // curr->val < root;
        TreeNode *tmp{root};
        if (curr->val > root->val) {
            curr->left = root;
            return curr;
        }
        while (tmp->right && curr->val <= tmp->right->val) {
            tmp = tmp->right;
        }
        curr->left = tmp->right;
        tmp->right = curr;
        return root;
    }
};

// stack
class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if (nums.empty()) return nullptr;
        std::stack<TreeNode*> stk; 
        for (int i = 0; i < nums.size(); ++i ){
            TreeNode* curr = new TreeNode(nums[i]);
            while (!stk.empty() && nums[i] > stk.top()->val) {
                curr->left = stk.top();
                stk.pop();
            }
            if (!stk.empty()) {
                stk.top()->right = curr;
            }
            stk.push(curr);
        }
        while (stk.size() > 1){ 
            stk.pop();
        }
        return stk.top();
    }
};
