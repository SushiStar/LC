/*
 * Serialization is the process of converting a data structure or object into a
 * sequence of bits so that it can be stored in a file or memory buffer, or
 * transmitted across a network connection link to be reconstructed later in
 * the same or another computer environment.
 *
 * Design an algorithm to serialize and deserialize a binary search tree. There
 * is no restriction on how your serializetion/deserialization algorithm should
 * work. You just need to ensure that a binary search tree can be serialized to
 * a string and this string can be deserialized to the original tree structure;
 *
 * The encoded string should be as compact as possible.
 *
 * Date: 04/16/2020
 * Author: Wei Du
 */
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 };

class Codec {
public:
    TreeNode *k;
    // Encodes a tree to a single string.
    string serialize(TreeNode *root) {
        if (!root) return "";
        std::unordered_map<TreeNode*, int> nodeIdMap;
        int nodeID(1);
        // do bfs
        std::string ret(std::to_string(root->val)+'_'+std::to_string(nodeID)+'_'+std::to_string(0)+' ');
        nodeIdMap[root] = nodeID;
        ++nodeID;
        std::vector<TreeNode*> bfsCurr{root};
        std::vector<TreeNode*> bfsNext{};
        while (!bfsCurr.empty()) {
            for (TreeNode* node: bfsCurr) {
                if (node->left) {
                    ret += (std::to_string(node->left->val) + '_' + std::to_string(nodeID)+'_'+std::to_string(nodeIdMap[node]) + ' ');
                    nodeIdMap[node->left] = nodeID;
                    ++nodeID;
                    bfsNext.push_back(node->left);
                }
                if (node->right) {
                    ret += (std::to_string(node->right->val) + '_' + std::to_string(nodeID)+'_'+std::to_string(-nodeIdMap[node])  + ' ');
                    nodeIdMap[node->right] = nodeID;
                    ++nodeID;
                    bfsNext.push_back(node->right);
                }
            }
            bfsCurr.clear();
            std::swap(bfsCurr, bfsNext);
        }
        return ret;
    }
        // Decodes your encoded data to tree.
    TreeNode *deserialize(string data) {
        if (data.empty()) return nullptr;
        std::unordered_map<int, TreeNode*> nodeIDMap;
        int start(0);
        int end(0);
        while (start != data.size()) {
            end = data.find(' ', start);
            std::string nodeStr = data.substr(start, end-start);
            start = end+1;

            size_t position1 = nodeStr.find('_');
            size_t position2 = nodeStr.find('_',position1+1);
            TreeNode *currNode = new TreeNode(std::stoi(nodeStr.substr(0, position1)));
            nodeIDMap[std::stoi(nodeStr.substr(position1+1, position2-position1))] = currNode;
            int parentID = std::stoi(nodeStr.substr(position2+1));
            if (parentID == 0) continue;
            if (parentID > 0) {
                nodeIDMap[parentID]->left = currNode;
            } else {
                nodeIDMap[-parentID]->right = currNode;
            }
        }
        return nodeIDMap[1];
    }
};
