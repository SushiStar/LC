/*
 * Write a function to delete a node (except the tail) in a singly linked list,
 * given access only to that node.
 *
 * The linked list will have at least 2 nodes.
 * All of the node's values will be unique.
 * The given node will not be the tail and it will always be a valid node of a
 * linked list. Do not return anything from your function.
 *
 * Date: Jun/14/2019
 * Author: Wei Du
 */

class Solution {
public:
    void deleteNode(ListNode* node) {
        node->val = node->next->val;
        auto temp = node->next;
        node->next = node->next->next;
        delete temp;
    }
};
