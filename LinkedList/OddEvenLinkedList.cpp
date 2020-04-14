/*
 * Given a singly linked list, group all odd nodes together followed by even
 * nodes. Please note here we are talking about the node number and not the
 * value in the nodes.
 *
 * You should try to do it inplace. The program should run in O(1) space
 * complexity and O(n) time complexity.
 *
 * Date: 04/13/2020
 * Auhtor: Wei Du
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
    ListNode *oddEvenList(ListNode *head) {
        if (!head || !head->next) return head;
        ListNode *head1{head}, *head2{head->next}, *tail1{head},
            *tail2{head->next};
        ListNode *buffer{head->next};
        buffer = buffer ? buffer->next : buffer;
        while (buffer) {
            tail1->next = buffer;
            tail1 = tail1->next;
            buffer = buffer->next;
            if (buffer) {
                tail2->next = buffer;
                tail2 = tail2->next;
                buffer = buffer->next;
            }
        }
        tail1->next = head2;
        tail2->next = nullptr;
        return head1;
    }
};
