/*
 * Given a binary treey, imagine yourself standing on the right side of it,
 * return the values of the nodes that you can see ordered from top to bottom.
 *
 * Date: 06/07/2020
 * Author: Wei Du
 */
#include <deque>
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
    vector<int> rightSideView(TreeNode *root) {
        std::vector<int> ret{};
        if (!root) return ret;
        std::deque<TreeNode *> bfsOrder{root};
        int levelCount(1);
        int nextLevelCount(0);
        while (!bfsOrder.empty()) {
            nextLevelCount = 0;
            while (levelCount > 0) {
                if (--levelCount == 0) {
					ret.push_back(bfsOrder[0]->val);
                }
                if (bfsOrder[0]->left) {
                    bfsOrder.push_back(bfsOrder[0]->left);
					++nextLevelCount;
                }
				if (bfsOrder[0]->right) {
					bfsOrder.push_back(bfsOrder[0]->right);
					++nextLevelCount;
				}
				bfsOrder.pop_front();
            }
			levelCount = nextLevelCount;
        }
        return ret;
    }
};
