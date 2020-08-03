/*
 * Serialization is the process of converting a data structure or object into a
 * sequence of bits so that it can be stored in a file or memory buffer, or
 * transmitted across a network connection link to be reconstructed later in the
 * same or another computer environment. Design an algorithm to serialize and
 * deserialize an N-ary tree. An N-ary tree is a rooted tree in which each node
 * has no more than N children. There is no restriction on how your
 * serialization/deserialization algorithm should work. You just need to ensure
 * that an N-ary tree can be serialized to a string and this string can be
 * deserialized to the original tree structure.
 *
 * Date: 08/02/2020
 * Author: Wei Du
 */

#include "../common.h"

// Definition for a Node.
class Node {
 public:
  int val;
  vector<Node*> children;

  Node() {}

  Node(int _val) { val = _val; }

  Node(int _val, vector<Node*> _children) {
    val = _val;
    children = _children;
  }
};

class Codec {
 public:
  // Encodes a tree to a single string.
  string serialize(Node* root) {
    if (!root) return "";
    string thisnode{'[' + std::to_string(root->val) + ','};
    for (int i = 0; i < root->children.size(); ++i) {
      thisnode += serialize(root->children[i]);
      thisnode += ',';
    }
    thisnode.pop_back();
    thisnode += ']';
    return thisnode;
  }

  // Decodes your encoded data to tree.
  Node* deserialize(string data) {
    if (data.empty()) return nullptr;
    int comma = data.find_first_of(',', 0);
    if (comma == std::string::npos) comma = data.find_first_of(']', 0);
    Node* root = new Node(std::stoi(data.substr(1, comma - 1)));

    int start = comma + 1;
    while (start < data.size() - 1) {
      int cnt{1}, end{start + 1};
      while (cnt != 0) {
        if (data[end] == ']')
          --cnt;
        else if (data[end] == '[')
          ++cnt;
        ++end;
      }
      root->children.push_back(deserialize(data.substr(start, end - start)));
      start = end + 1;
    }
    return root;
  }
};
