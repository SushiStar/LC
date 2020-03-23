/*
 * Given an array arr of positive integers, consider all binary trees such that:
 *      Each node has either 0 or 2 children.
 *      The values of arr correspond to values of each leaf, in an
 * in-order-traversal of a tree. The value of each non-leaf node is equal to the
 * product of the largest leaf value in its left and right sub-tree
 * respectively. Among all possible binary trees considered, return the smallest
 * possible sum of the values of each non-leaf node.
 *
 * Date: 03/23/2020
 * Author: Wei Du.
 */

// Do a DP
class Solution {
public:
    int mctFromLeafValues(vector<int> &arr) {
        if (arr.empty()) return 0;
        std::vector<std::vector<int>> dp(arr.size(),
                                         std::vector<int>(arr.size(), INT_MAX));
        std::vector<std::vector<int>> maxi(arr.size(),
                                           std::vector<int>(arr.size(), 0));

        for (int i = 0; i < arr.size(); ++i) {
            maxi[i][i] = arr[i];
            dp[i][i] = 0;
            for (int j = i + 1; j < arr.size(); ++j) {
                maxi[i][j] = std::max(maxi[i][j - 1], arr[j]);
            }
        }
        for (int step = 1; step < arr.size(); ++step) {
            for (int left = 0; left < arr.size() - step; ++left) {
                int right = left + step;
                for (int k = left; k < right; ++k) {
                    dp[left][right] =
                        std::min(dp[left][right],
                                 dp[left][k] + dp[k + 1][right] +
                                     maxi[left][k] * maxi[k + 1][right]);
                }
            }
        }
        return dp[0].back();
    }
};

/*
 * When we build a node in the tree, we compared the two numbers a and b.
 * In this process, the smaller one is removed and we won't use it anymore,
 * and the bigger one actually stays.
 * 
 * The problem can translated as following:
 * Given an array A, choose two neighbors in the array a and b,
 * we can remove the smaller one min(a,b) and the cost is a * b.
 * What is the minimum cost to remove the whole array until only one left?
 * 
 * To remove a number a, it needs a cost a * b, where b >= a.
 * So a has to be removed by a bigger number.
 * We want minimize this cost, so we need to minimize b.
 * 
 * b has two candidates, the first bigger number on the left,
 * the first bigger number on the right. (a number could only be removed with 
 * its nearest larger number.)
 * Deeper look:
 *              The current tree structure should be [6 X 2 X 4 X 7 X 5],
 *              so the non-leaf nodes are represented by X. where X should
 *              be the multiplication of its neighbors.
 *              To summarize, this is equal to group to neighbors and leave 
 *              the larger one for later group.
 * 
 * The cost to remove a is a * min(left, right).
 *
 * we decompose a hard problem into reasonable easy one:
 * Just find the next greater element in the array, on the left and one right.
 * Refer to the problem 503.
 */

class Solution {
public:
    int mctFromLeafValues(vector<int> &arr) {
        int res = 0;
        vector<int> stack = {INT_MAX};
        for (int a : arr) {
            while (stack.back() <= a) {
                int mid = stack.back();
                stack.pop_back();
                res += mid * min(stack.back(), a);  // ????????
            }
            stack.push_back(a);
        }
        // now stack is in order from large to small
        for (int i = 2; i < stack.size(); ++i) {
            res += stack[i] * stack[i - 1];
        }
        return res;
    }
};
