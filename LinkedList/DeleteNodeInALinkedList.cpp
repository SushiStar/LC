/*
 * Write a function to delete a node (except the tail) in a singly linked
 * list, given only access to that node.
 *
 * The linkedlist will have at least two elements.
 * All of the node's values will be unique.
 * The given node will not be the tail and it will always be a valid node
 * of the linked list.
 * Do not return anything from your function.
 *
 * Date: 04/28/2020
 * Author: Wei Du
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode *node) {
        auto nxt = node->next;
        while (nxt) {
            node->val = nxt->val;
            if (nxt->next) node = nxt;
            nxt = nxt->next;
        }
        delete node->next;
        node->next = nullptr;
    }
};
