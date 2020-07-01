/*
 * Given a binary tree, Populate each next pointer to point to its next right
 * node. If there is no next right node, the next pointer should be set to NULL.
 * Initially, all next pointers are set to NULL.  Follow up: You may only use
 * constant extra space.  Recursive approach is fine, you may assume implicit
 * stack space does not count as extra space for this problem.
 *
 * Date: 07/01/2020
 * Author: Wei Du
 */
#include <vector>
using namespace std;

// Definition for a Node.
class Node {
 public:
  int val;
  Node* left;
  Node* right;
  Node* next;

  Node() : val(0), left(nullptr), right(nullptr), next(nullptr) {}

  Node(int _val) : val(_val), left(nullptr), right(nullptr), next(nullptr) {}

  Node(int _val, Node* _left, Node* _right, Node* _next)
      : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
  vector<Node*> buffer;
  int depth{-1};
 public:
   Node* connect(Node* root) {
     if (!root) return root;
     ++depth;
     if (depth == buffer.size())
       buffer.push_back(root);
     else {
       buffer[depth]->next = root;
       buffer[depth] = root;
     }
     connect(root->left);
     connect(root->right);
     --depth;
     return root;
   }
};
