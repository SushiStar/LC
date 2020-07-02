/*
 * Date: 03/25/2020
 *
 * Author: Wei Du
 */
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        std::vector<std::vector<int>> result;
        if (!root) return result;
        std::vector<TreeNode*> buffer[2];
        int idx0{0};
        int idx1{1};
        buffer[idx0].push_back(root);
        while (!buffer[idx0].empty()) {
            std::vector<int> level{};
            for (auto node : buffer[idx0]) {
                level.push_back(node->val);
                if (node->left) buffer[idx1].push_back(node->left);
                if (node->right) buffer[idx1].push_back(node->right);
            }
            result.push_back(level);
            buffer[idx0].clear();
            std::swap(idx0, idx1);
        }
        std::reverse(result.begin(), result.end());
        return result;
    }
};

class Solution1 {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
      if (!root) return {};
      vector<vector<int>> ret{};
      vector<TreeNode*> bfs{root};
      int idx{0}, mark{1};
      ret.push_back({});
      while (idx < bfs.size()) {
        auto tmp = bfs[idx++];
        ret.back().push_back(tmp->val);
        if (tmp->left) bfs.push_back(tmp->left);
        if (tmp->right) bfs.push_back(tmp->right);
        if (idx == mark) {
          ret.push_back({});
          mark = bfs.size();
        }
      }
      ret.pop_back();
      std::reverse(ret.begin(), ret.end());
      return ret;
    }
};
