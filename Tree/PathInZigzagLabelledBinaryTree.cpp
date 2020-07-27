/*
 * In an infinite binary tree where every node has two children, the nodes are
 * labelled in row order.
 *
 * In the odd numbered rows (ie., the first, third, fifth,...), the labelling is
 * left to right, while in the even numbered rows (second, fourth, sixth,...),
 * the labelling is right to left.
 *
 * Given the label of a node in this tree, return the labels in the path from
 * the root of the tree to the node with that label.
 *
 * Date: 07/26/2020
 * Author: Wei Du
 */
#include "../common.h"

class Solution {
 public:
  vector<int> pathInZigZagTree(int label) {
    int curlevel = (int)(log2(label) + 1e-4);
    int left = (int)(pow(2, curlevel) + 1e-4);
    int right = left * 2 - 1;
    int actualIdx = curlevel&1 ? right+left-label : label;

    vector<int> ret{};
    while (curlevel > -1) {
      if (curlevel & 1) {  // reversed
        ret.push_back(left+right-actualIdx);
      } else {
        ret.push_back(actualIdx);
      }
      right = left - 1;
      left /= 2;
      actualIdx/=2;
      --curlevel;
    }
    std::reverse(ret.begin(), ret.end());
    return ret;
  }
};
